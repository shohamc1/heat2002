#!/usr/bin/env python3
"""Generate an objdiff-format progress report for decomp.dev, plus a local summary.

decomp.dev ingests objdiff's `report.json` schema. We synthesize it directly
rather than running `objdiff-cli report generate`, which wants a carved target
object per unit and a full objdiff.json unit map -- overkill while every
function still lives in one asm file.

Progress is measured in BYTES OF CODE, not function count: a function is
"matched" once it is implemented in C under src/ and `scripts/match.py` agrees
with the target asm. Everything still in asm/rom.s counts as unmatched.

    python3 scripts/progress.py            # human summary
    python3 scripts/progress.py --json     # write report.json
"""

import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ASM_DIR = ROOT / "asm"
OBJ_DIR = ROOT / "build" / "asm"
PREAMBLE_END = "@ End embedded Luvdis macros"

# Both macro forms start a real function. Missing the non-word-aligned variant
# undercounts by 8 on this ROM.
START = re.compile(r"^\s+(?:non_word_aligned_)?(?:thumb|arm)_func_start\s+(\S+)\s*$")


def parse_asm():
    """Return {name: instruction_count} for functions still in asm.

    Once a function is decompiled, its `thumb_func_start`..`thumb_func_end`
    block moves out of the monolithic asm/rom.s and the file gets split at
    that boundary (see CLAUDE.md's placement notes), so functions still in
    asm are spread across every asm/*.s fragment, not just rom.s.
    """
    funcs = {}
    for path in sorted(ASM_DIR.glob("*.s")):
        lines = path.read_text(errors="replace").splitlines()
        for i, line in enumerate(lines):
            if PREAMBLE_END in line:
                lines = lines[i + 1 :]
                break

        cur = None
        for line in lines:
            m = START.match(line)
            if m:
                cur = m.group(1)
                funcs[cur] = 0
                continue
            if re.match(r"\s+(?:thumb|arm)_func_end\b", line):
                cur = None
                continue
            if cur is None:
                continue
            s = line.split("@")[0].strip()
            if s and not s.startswith(".") and not s.endswith(":"):
                funcs[cur] += 1
    return funcs


def func_sizes():
    """Real byte sizes from the linked objects, via nm.

    nm reports a bogus size for the handful of stray markers sitting inside
    data regions (it measures to the next symbol, spanning megabytes of
    assets), so anything absurd is clamped by the instruction count instead.
    """
    sizes = {}
    for obj in sorted(OBJ_DIR.glob("*.o")):
        out = subprocess.run(
            ["arm-none-eabi-nm", "--print-size", str(obj)],
            capture_output=True,
            text=True,
            check=False,
        ).stdout
        for line in out.splitlines():
            parts = line.split()
            if len(parts) == 4 and parts[2] in ("t", "T"):
                sizes[parts[3]] = int(parts[1], 16)
    return sizes


def decompiled():
    """Function names *defined* in C under src/, not merely referenced.

    Anchored to line start (no leading whitespace) and a `name(` that starts
    a definition, so a call to a still-asm function from inside a decompiled
    one -- always indented, inside braces -- doesn't get counted as done.
    """
    done = set()
    pat = re.compile(r"^\S[^(\n]*\b(sub_[0-9A-Fa-f]{8})\s*\(", re.MULTILINE)
    for c in (ROOT / "src").rglob("*.c"):
        for m in pat.finditer(c.read_text(errors="replace")):
            done.add(m.group(1))
    return done


def c_func_sizes():
    """Real byte sizes for decompiled functions, via nm on build/src/*.o."""
    sizes = {}
    for obj in sorted((ROOT / "build" / "src").glob("*.o")):
        out = subprocess.run(
            ["arm-none-eabi-nm", "--print-size", str(obj)],
            capture_output=True,
            text=True,
            check=False,
        ).stdout
        for line in out.splitlines():
            parts = line.split()
            if len(parts) == 4 and parts[2] in ("t", "T"):
                sizes[parts[3]] = int(parts[1], 16)
    return sizes


def main():
    insns = parse_asm()
    sizes = func_sizes()
    done = decompiled()
    csizes = c_func_sizes()

    # A matched function is deleted from asm/*.s entirely (see CLAUDE.md's
    # loop, step 5), so `insns` alone would lose it from the report. Track it
    # separately, sized from its compiled object instead of asm bytes.
    names = sorted(set(insns) | done)

    units, total, matched = [], 0, 0
    for name in names:
        is_done = name in done
        if name in insns:
            n = insns[name]
            # 2 bytes per Thumb instruction; trust nm only when it's plausible.
            est = n * 2
            size = sizes.get(name, est)
            if size > max(est * 4, 512):
                size = est
        else:
            size = csizes.get(name, 0)
        total += size
        matched += size if is_done else 0
        units.append(
            {
                "name": name,
                "measures": {
                    "total_code": size,
                    "matched_code": size if is_done else 0,
                    "matched_code_percent": 100.0 if is_done else 0.0,
                    "total_functions": 1,
                    "matched_functions": 1 if is_done else 0,
                    "complete_code": size if is_done else 0,
                },
                "metadata": {"complete": is_done},
            }
        )

    pct = (matched / total * 100) if total else 0.0
    measures = {
        "fuzzy_match_percent": pct,
        "total_code": total,
        "matched_code": matched,
        "matched_code_percent": pct,
        "total_data": 0,
        "matched_data": 0,
        "matched_data_percent": 0.0,
        "total_functions": len(units),
        "matched_functions": len(done),
        "matched_functions_percent": (len(done) / len(units) * 100 if units else 0.0),
        "complete_code": matched,
        "complete_code_percent": pct,
        "total_units": len(units),
        "complete_units": len(done),
    }

    if "--json" in sys.argv:
        report = {"version": 2, "measures": measures, "units": units, "categories": []}
        out = ROOT / "report.json"
        out.write_text(json.dumps(report, indent=2) + "\n")
        print(f"wrote {out}")
    else:
        print("NASCAR Heat 2002 — decompilation progress")
        print(f"  functions: {measures['matched_functions']} / {len(units)} matched")
        print(f"  code:      {matched} / {total} bytes ({pct:.4f}%)")
        if not done:
            print("\n  nothing decompiled yet — see docs/tickets/")


def _selftest():
    insns = parse_asm()
    # The macro preamble defines `thumb_func_start name`; a bad parse yields a
    # phantom function literally called "name" -- once per split asm file.
    assert "name" not in insns, "preamble leaked into the parse"
    # 743 total, minus however many have been decompiled out of asm/*.s and
    # into src/*.c so far -- computed, not hardcoded, so this doesn't need
    # editing as tickets land.
    remaining = 743 - len(decompiled())
    assert len(insns) == remaining, f"expected {remaining} functions, got {len(insns)}"
    assert "sub_08006734" not in insns, "sub_08006734 should be decompiled, not in asm"
    print(f"selftest ok ({len(insns)} functions remaining in asm)")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        _selftest()
    else:
        main()
