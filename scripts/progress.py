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

# Vendored runtime library: 33 libgcc + 59 newlib functions, identified
# byte-for-byte (docs/learnings/parked.md, runtime-newlib-map.json). They were
# built without -mthumb-interwork, so they end in `pop {rN, pc}` or
# `mov pc, lr`, which agbcc cannot emit under the project's flags. They are
# not decompilation targets: they stay as asm, or are replaced by verified
# library objects. That epilogue is what identifies them -- an address range
# would be wrong, because ten already-matched functions sit inside the same
# spans (a linker interleaves objects; a matched leaf whose epilogue is a bare
# `bx lr` is flag-insensitive and matches either way).
NON_INTERWORK_EPILOGUE = re.compile(r"\bpop \{[^}]*pc\}|\bmov pc, lr\b")

# luvdis misread these five data runs as functions; see parked.md.
LUVDIS_FALSE_POSITIVES = frozenset(
    ("sub_08026DB6", "sub_0824C6F0", "sub_0827B7CA", "sub_080462B2", "sub_08121316")
)


def runtime_library():
    """Names of the vendored runtime-library functions still in asm."""
    found = set()
    for path in sorted(ASM_DIR.glob("*.s")):
        txt = path.read_text(errors="replace")
        starts = [
            (m.start(), m.group(1))
            for m in re.finditer(
                r"\t(?:non_word_aligned_)?(?:thumb|arm)_func_start (\S+)\n", txt
            )
        ]
        for i, (pos, name) in enumerate(starts):
            end = starts[i + 1][0] if i + 1 < len(starts) else len(txt)
            if NON_INTERWORK_EPILOGUE.search(txt[pos:end]):
                found.add(name)
    return found


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
    """Functions defined in src/*.c whose compiled bytes match the ROM.

    A definition is `name(` at column 0 followed by `{` -- a prototype
    (`void name(...);`) is not one. Each candidate is then verified against
    the ROM by match.py, so a C body that compiles but is wrong is not
    counted as done.
    """
    sys.path.insert(0, str(ROOT / "scripts"))
    import match

    pat = re.compile(r"^(?:__attribute__\s*\(\([^)]*\)\)\s*)?\S[^(\n;]*\b(sub_[0-9A-Fa-f]{8})\s*\([^;{]*\)\s*\{", re.MULTILINE)
    done = set()
    for c in (ROOT / "src").rglob("*.c"):
        for m in pat.finditer(c.read_text(errors="replace")):
            name = m.group(1)
            if not match.find_symbol(name):
                continue  # not built; reported via `missing` below
            if match.matches(name):
                done.add(name)
            else:
                print(f"  WARNING: {name} is in src/ but does not match the ROM", file=sys.stderr)
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

    # Sizes come from build/**/*.o via nm. With no build (or a stale one), a
    # decompiled function contributes 0 bytes and the totals silently shrink
    # -- which reads as "no progress" rather than "unknown". Say so instead.
    defined = set(re.findall(r"^\S[^(\n;]*\b(sub_[0-9A-Fa-f]{8})\s*\([^;{]*\)\s*\{",
                             "\n".join(c.read_text(errors="replace") for c in (ROOT / "src").rglob("*.c")),
                             re.MULTILINE))
    missing = sorted(n for n in defined if n not in csizes)

    # A matched function is deleted from asm/*.s entirely (see CLAUDE.md's
    # loop, step 5), so `insns` alone would lose it from the report. Track it
    # separately, sized from its compiled object instead of asm bytes.
    names = sorted(set(insns) | done)
    non_targets = runtime_library() | LUVDIS_FALSE_POSITIVES

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
                "metadata": {"complete": is_done, "target": name not in non_targets},
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
        if missing:
            sys.exit(
                f"refusing to write report.json: no compiled object for "
                f"{', '.join(missing)} -- run `make` first"
            )
        report = {"version": 2, "measures": measures, "units": units, "categories": []}
        out = ROOT / "report.json"
        out.write_text(json.dumps(report, indent=2) + "\n")
        print(f"wrote {out}")
    else:
        game = [u for u in units if u["metadata"]["target"]]
        g_total = sum(u["measures"]["total_code"] for u in game)
        g_matched = sum(u["measures"]["matched_code"] for u in game)
        g_done = sum(u["measures"]["matched_functions"] for u in game)
        g_pct = (g_matched / g_total * 100) if g_total else 0.0
        print("NASCAR Heat 2002 — decompilation progress")
        print(f"  functions: {g_done} / {len(game)} matched")
        print(f"  code:      {g_matched} / {g_total} bytes ({g_pct:.4f}%)")
        print(
            f"  excluded:  {len(units) - len(game)} non-targets"
            " (vendored runtime library, luvdis false positives)"
        )
        print(f"  whole ROM: {matched} / {total} bytes ({pct:.4f}%) over {len(units)} blocks")
        if missing:
            print(
                f"\n  WARNING: no compiled object for {', '.join(missing)};"
                "\n  counted as 0 bytes. Run `make` for accurate totals."
            )
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
    total = len(set(insns) | decompiled())
    assert total == 743, f"expected 743 functions across asm + matched C, got {total}"
    assert "sub_08006734" not in insns, "sub_08006734 should be decompiled, not in asm"
    # 92 runtime-library functions, all still in asm, plus 5 luvdis false
    # positives, are not decompilation targets -- so the game-code
    # denominator is 646, not 743.
    rt = runtime_library()
    assert len(rt) == 92, f"expected 92 runtime-library functions, got {len(rt)}"
    non_targets = rt | LUVDIS_FALSE_POSITIVES
    assert total - len(non_targets) == 646, (
        f"game-code denominator should be 646, got {total - len(non_targets)}"
    )
    # Every address in the verified newlib map must be one of them.
    import json as _json

    mapped = {
        int(row[0], 16)
        for row in _json.loads((ROOT / "docs/learnings/runtime-newlib-map.json").read_text())
    }
    rt_addrs = {int(n.split("_")[1], 16) for n in rt if re.fullmatch(r"sub_[0-9A-Fa-f]{8}", n)}
    assert mapped <= rt_addrs, f"newlib map has {len(mapped - rt_addrs)} unflagged addresses"
    print(f"selftest ok ({len(insns)} functions remaining in asm)")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        _selftest()
    else:
        main()
