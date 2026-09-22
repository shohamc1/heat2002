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

# Vendored runtime library still in asm: libgcc, and the newlib objects not
# yet built from source (docs/learnings/parked.md, runtime-newlib-map.json).
# They were
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

# luvdis blocks whose bytes now come from newlib objects built from source
# (build/lib/newlib, placed by ldscript.ld). They left asm/ and src/ without
# being game code; listing them keeps the 743-block accounting closed.
NEWLIB_BLOCKS = frozenset((
    "sub_08017594", "sub_080175D4", "sub_080175F4", "sub_08017668", "sub_0801767C",
    "sub_080185DC", "sub_080186D0", "sub_08018740", "sub_080187EC", "sub_08018948",
    "sub_08019640", "sub_080196D4", "sub_0801970C", "sub_080197B0", "sub_080197D0",
    "sub_08019830", "sub_080199F0", "sub_08019AB0", "sub_08019CDC", "sub_08019D1C",
    "sub_08019D58", "sub_08019D78", "sub_08019D88", "sub_08019E64", "sub_08019FC0",
    "sub_0801A380", "sub_0801A3AC", "sub_0801A42C", "sub_0801A48C", "sub_0801A514",
    "sub_0801A568", "sub_0801A56C", "sub_0801A570", "sub_0801A5C8", "sub_0801A5E0",
    "sub_0801A6FC", "sub_0801A754", "sub_0801A7D8", "sub_0801A7EC", "sub_0801A958",
    "sub_0801A9F0", "sub_0801AA90", "sub_0801AAD0", "sub_0801AC0C", "sub_0801ACC8",
    "sub_0801AE84", "sub_0801AF74", "sub_0801AFD0", "sub_0801B014", "sub_0801B034",
    "sub_0801B0F0", "sub_0801B104", "sub_0801B118", "sub_0801B130", "sub_0801B154",
    "sub_0801B19C", "sub_0801B220", "sub_0801B22C", "sub_0801B250", "sub_0801B29C",
    "sub_0801B350", "sub_0801B384", "sub_0801B3D4", "sub_0801B410", "sub_0801B478",
    "sub_0801B4A8", "sub_0801B500", "sub_0801B52C", "sub_0801B538", "sub_0801B564",
    "sub_0801B584", "sub_0801B58C", "sub_0801B5BC",
))

# luvdis blocks now built from Nintendo's libagbsyscall (lib/libagbsyscall.s,
# pokeemerald's): the main program's copy, the high 0x0834 module's, and the
# multiboot island's.
AGBSYSCALL_BLOCKS = frozenset((
    "sub_08016E0C", "sub_08016E10", "sub_08016E14", "sub_08016E1C", "sub_08016E20",
    "sub_08016E28", "sub_08016E2C", "sub_08016E30", "sub_08344B60", "sub_08344B64",
    "sub_08344B68", "sub_08344B70", "sub_08344B74", "sub_083647FC",
))

# luvdis blocks now built from the MP2K driver's hand-written assembly
# (lib/m4a_1.s, from pokeemerald's), in the main program and the high module.
M4A_BLOCKS = frozenset((
    "sub_08000958", "sub_08000972", "sub_08000DC8",
    "sub_0833A018", "sub_0833A032", "sub_0833A488",
))

# Every luvdis block whose bytes now come from a source-built library object.
LIBRARY_BLOCKS = NEWLIB_BLOCKS | AGBSYSCALL_BLOCKS | M4A_BLOCKS

# Runtime-library functions the epilogue check cannot see, because they are
# in src/ rather than asm/: libgcc's __div0.
RUNTIME_LEAVES = frozenset(("sub_080172C4",))


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


def library_objects():
    """{object: .text bytes} for the runtime library built from source."""
    sizes = {}
    lib = ROOT / "build" / "lib"
    for obj in sorted(lib.rglob("*.o")):
        out = subprocess.run(
            ["arm-none-eabi-size", "-A", str(obj)], capture_output=True, text=True, check=False
        ).stdout
        m = re.search(r"^\.text\s+(\d+)", out, re.MULTILINE)
        if m and int(m.group(1)):
            sizes[str(obj.relative_to(lib))] = int(m.group(1))
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
    non_targets = runtime_library() | LUVDIS_FALSE_POSITIVES | RUNTIME_LEAVES

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

    # Source-built runtime library: complete by construction (make check
    # verifies it), never a decompilation target.
    lib = library_objects()
    for name, size in lib.items():
        total += size
        matched += size
        units.append(
            {
                "name": name,
                "measures": {
                    "total_code": size,
                    "matched_code": size,
                    "matched_code_percent": 100.0,
                    "total_functions": 1,
                    "matched_functions": 1,
                    "complete_code": size,
                },
                "metadata": {"complete": True, "target": False},
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
        "matched_functions": len(done) + len(lib),
        "matched_functions_percent": ((len(done) + len(lib)) / len(units) * 100 if units else 0.0),
        "complete_code": matched,
        "complete_code_percent": pct,
        "total_units": len(units),
        "complete_units": len(done) + len(lib),
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
        print(
            f"  whole ROM: {matched} / {total} bytes ({pct:.4f}%) over {len(units)} units"
            f" ({len(lib)} library objects built from source)"
        )
        if not lib:
            print("\n  WARNING: no build/lib objects; run `make` for accurate totals.")
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
    done = decompiled()
    assert not LIBRARY_BLOCKS & (set(insns) | done), "a library block is back in asm/ or src/"
    total = len(set(insns) | done | LIBRARY_BLOCKS)
    assert total == 743, f"expected 743 functions across asm + matched C + libraries, got {total}"
    assert "sub_08006734" not in insns, "sub_08006734 should be decompiled, not in asm"
    # 92 runtime-library functions were flagged in asm; the 59 newlib ones
    # are now built from source, so the 33 libgcc ones remain. With the 5
    # luvdis false positives, the 93 library blocks (73 newlib, 14
    # libagbsyscall, 6 m4a_1) and libgcc's __div0 leaf in src/, 132 blocks
    # are not decompilation targets: the game-code denominator is 611.
    rt = runtime_library()
    assert len(rt) == 33, f"expected 33 runtime-library functions in asm, got {len(rt)}"
    non_targets = rt | LUVDIS_FALSE_POSITIVES | LIBRARY_BLOCKS | RUNTIME_LEAVES
    assert total - len(non_targets) == 611, (
        f"game-code denominator should be 611, got {total - len(non_targets)}"
    )
    # Every address in the verified newlib map must be one of them.
    import json as _json

    mapped = {
        int(row[0], 16)
        for row in _json.loads((ROOT / "docs/learnings/runtime-newlib-map.json").read_text())
    }
    rt_addrs = {
        int(n.split("_")[1], 16)
        for n in rt | LIBRARY_BLOCKS
        if re.fullmatch(r"sub_[0-9A-Fa-f]{8}", n)
    }
    assert mapped <= rt_addrs, f"newlib map has {len(mapped - rt_addrs)} unflagged addresses"
    print(f"selftest ok ({len(insns)} functions remaining in asm)")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        _selftest()
    else:
        main()
