#!/usr/bin/env python3
"""Generate an objdiff-format progress report for decomp.dev, plus a local summary.

decomp.dev ingests objdiff's `report.json` schema. We synthesize it directly
rather than running `objdiff-cli report generate`, which wants a carved target
object per unit and a full objdiff.json unit map -- overkill while every
function still lives in one asm file.

Progress is measured in BYTES OF CODE, not function count: a function is
"matched" once it is implemented in C under src/ and `scripts/match.py` agrees
with the target asm. Everything still in data/*.s, and every ASM_FUNC in a C
file, counts as unmatched. One function per luvdis block (scripts/blocks.txt),
keyed by ROM address, so names, files and folders don't matter.

    python3 scripts/progress.py            # human summary
    python3 scripts/progress.py --json     # write report.json
"""

import bisect
import json
import re
import subprocess
import sys
from pathlib import Path

import match

ROOT = Path(__file__).resolve().parent.parent
ASM_DIR = ROOT / "data"
OBJ_DIR = ROOT / "build" / "data"
PREAMBLE_END = "@ End embedded Luvdis macros"

# Both macro forms start a real function. Missing the non-word-aligned variant
# undercounts by 8 on this ROM.
START = re.compile(r"^\s+(?:non_word_aligned_)?(?:thumb|arm)_func_start\s+(\S+)\s*$")

# Runtime library still in asm. All of it -- libgcc and newlib -- now builds
# from source, so this finds nothing; it stays as a guard. The runtime was
# built without -mthumb-interwork, so it ends in `pop {rN, pc}` or
# `mov pc, lr`, which agbcc cannot emit under the project's flags. That
# epilogue is what identifies it -- an address range would be wrong, because
# ten already-matched functions sat inside the same spans (a linker
# interleaves objects; a matched leaf whose epilogue is a bare `bx lr` is
# flag-insensitive and matches either way).
NON_INTERWORK_EPILOGUE = re.compile(r"\bpop \{[^}]*pc\}|\bmov pc, lr\b")

# luvdis misread these seven data runs as functions; see parked.md.
LUVDIS_FALSE_POSITIVES = frozenset((
    0x08026DB6, 0x0824C6F0, 0x0827B7CA, 0x080462B2, 0x08121316,
    0x08120E3A, 0x08248272,
))

# Hand-written ARM that luvdis (a Thumb decoder) left as .byte rows: the SDK
# crt0 start routine and interrupt dispatcher, once for the main program, once
# for the high 0x0834 module and once for the multiboot island (which adds a
# link-port wait routine). They build from lib/crt0.s and lib/crt0_island.s;
# like m4a_1.s, they aren't decompilation targets.
ARM_BLOCKS = frozenset((
    0x080000C0, 0x08000104, 0x08339780, 0x083397C4,
    0x08363FC8, 0x08363FF4, 0x083640B0,
))

# luvdis blocks whose bytes now come from newlib objects built from source
# (build/lib/newlib, placed by ldscript.ld). They left asm/ and src/ without
# being game code; listing them keeps the 1159-block accounting closed.
NEWLIB_BLOCKS = frozenset((
    0x08017594, 0x080175D4, 0x080175F4, 0x08017668, 0x0801767C,
    0x080185DC, 0x080186D0, 0x08018740, 0x080187EC, 0x08018948,
    0x08019640, 0x080196D4, 0x0801970C, 0x080197B0, 0x080197D0,
    0x08019830, 0x080199F0, 0x08019AB0, 0x08019CDC, 0x08019D1C,
    0x08019D58, 0x08019D78, 0x08019D88, 0x08019E64, 0x08019FC0,
    0x0801A380, 0x0801A3AC, 0x0801A42C, 0x0801A48C, 0x0801A514,
    0x0801A568, 0x0801A56C, 0x0801A570, 0x0801A5C8, 0x0801A5E0,
    0x0801A6FC, 0x0801A754, 0x0801A7D8, 0x0801A7EC, 0x0801A958,
    0x0801A9F0, 0x0801AA90, 0x0801AAD0, 0x0801AC0C, 0x0801ACC8,
    0x0801AE84, 0x0801AF74, 0x0801AFD0, 0x0801B014, 0x0801B034,
    0x0801B0F0, 0x0801B104, 0x0801B118, 0x0801B130, 0x0801B154,
    0x0801B19C, 0x0801B220, 0x0801B22C, 0x0801B250, 0x0801B29C,
    0x0801B350, 0x0801B384, 0x0801B3D4, 0x0801B410, 0x0801B478,
    0x0801B4A8, 0x0801B500, 0x0801B52C, 0x0801B538, 0x0801B564,
    0x0801B584, 0x0801B58C, 0x0801B5BC,
))

# luvdis blocks now built from Nintendo's libagbsyscall (lib/libagbsyscall.s,
# pokeemerald's): the main program's copy, the high 0x0834 module's, and the
# multiboot island's.
AGBSYSCALL_BLOCKS = frozenset((
    0x08016E0C, 0x08016E10, 0x08016E14, 0x08016E1C, 0x08016E20,
    0x08016E28, 0x08016E2C, 0x08016E30, 0x08344B60, 0x08344B64,
    0x08344B68, 0x08344B70, 0x08344B74, 0x083647FC,
))

# luvdis blocks now built from the MP2K driver's hand-written assembly
# (lib/m4a_1.s, from pokeemerald's), in the main program and the high module.
M4A_BLOCKS = frozenset((
    0x08000958, 0x08000972, 0x08000DC8,
    0x0833A018, 0x0833A032, 0x0833A488,
))

# luvdis blocks now built from Nintendo's EEPROM_V120 save library
# (lib/eeprom.c). Its timer interrupt handler was never a luvdis block.
EEPROM_BLOCKS = frozenset((
    0x08016E38, 0x08016EA0, 0x08016ED8, 0x08016F3C, 0x08016F80,
    0x08017000, 0x080170B8, 0x0801719C,
))

# luvdis blocks now built from Nintendo's MultiBoot library (lib/multiboot.c,
# pokeemerald's).
MULTIBOOT_BLOCKS = frozenset((
    0x0800EA64, 0x0800EAA0, 0x0800EE8C, 0x0800EED8, 0x0800EEFC,
    0x0800EFC0, 0x0800EFD0, 0x0800F0BC, 0x0800F0D4,
))

# luvdis blocks now built from tools/agbcc/libgcc: the main program's copy
# (lib1thumb.asm helpers, __muldi3, __negdi2, dp-bit, fp-bit, __lshrdi3) and
# the high 0x0834 module's.
LIBGCC_BLOCKS = frozenset((
    0x08017230, 0x080172C4, 0x080172C8, 0x08017398, 0x08017408,
    0x08017498, 0x0801B5EC, 0x0801B734, 0x0801B80C, 0x0801BA78,
    0x0801BAA8, 0x0801BAE0, 0x0801BD88, 0x0801BF10, 0x0801C03C,
    0x0801C088, 0x0801C0D4, 0x0801C16C, 0x0801C1B8, 0x0801C204,
    0x0801C280, 0x0801C2F4, 0x0801C388, 0x0801C440, 0x0801C4BC,
    0x0801C8E8, 0x0801CC90, 0x0801CCD4, 0x08344BB8, 0x08344C4C,
    0x08344C50, 0x08344D20, 0x08344D90, 0x08344DA8,
))

# Every luvdis block whose bytes now come from a source-built library object.
LIBRARY_BLOCKS = (
    NEWLIB_BLOCKS | AGBSYSCALL_BLOCKS | M4A_BLOCKS | EEPROM_BLOCKS | MULTIBOOT_BLOCKS
    | LIBGCC_BLOCKS | ARM_BLOCKS
)

# Every luvdis block's address, sorted; see the header of blocks.txt.
BLOCKS = tuple(sorted(
    int(line, 16)
    for line in (ROOT / "scripts" / "blocks.txt").read_text().splitlines()
    if line and not line.startswith("#")
))

# The function name in `ASM_FUNC("path", void name(...))`.
ASM_FUNC_DECL = re.compile(r'\bASM_FUNC\(\s*"[^"]*"\s*,[^(]*?\b(\w+)\s*\(')


def by_address(names):
    """{ROM address: name}. Every set in this file is keyed by address, so a
    function can be renamed without touching it."""
    out = {}
    for name in names:
        addr = match.addr_of(name)
        if addr is None:
            sys.exit(f"{name}: not in {match.ELF.name} and no address in the name -- run `make`")
        out[addr] = name
    return out


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
    asm are spread across every data/*.s fragment, not just rom.s.
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


def asm_funcs():
    """Names declared with ASM_FUNC in src/: still asm, so unmatched."""
    names = set()
    for c in (ROOT / "src").rglob("*.c"):
        names.update(ASM_FUNC_DECL.findall(c.read_text(errors="replace")))
    return names


def c_blocks():
    """{block address: [name, bytes, is_c]} for the blocks built from src/.

    Every function in build/src/**/*.o counts, whatever it's called and
    however many share a file. A function that isn't a block start (the
    out-of-line copy of an inline helper such as min_0800D5BC) adds its
    bytes to the block before it. `is_c` is False for an ASM_FUNC.
    """
    funcs = {}
    for name, hits in match._symbol_index().items():
        addr = match.addr_of(name)
        if addr is None:
            print(f"  WARNING: {name} has no ROM address; place it and run `make`", file=sys.stderr)
            continue
        funcs[addr] = (name, hits[0][2])

    asm = asm_funcs()
    blocks = {}
    for addr in sorted(funcs):
        name, size = funcs[addr]
        start = BLOCKS[bisect.bisect_right(BLOCKS, addr) - 1]
        if start == addr:
            blocks[addr] = [name, size, name not in asm]
        elif start in blocks:
            blocks[start][1] += size
    return blocks


def decompiled(blocks):
    """Addresses of the C blocks whose compiled bytes match the ROM.

    Each candidate is verified against the ROM by match.py, so a C body
    that compiles but is wrong is not counted as done.
    """
    done = set()
    for addr, (name, _, is_c) in blocks.items():
        if not is_c:
            continue
        if match.matches(name):
            done.add(addr)
        else:
            print(f"  WARNING: {name} is in src/ but does not match the ROM", file=sys.stderr)
    return done


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
    in_c = c_blocks()
    done = decompiled(in_c)

    # Sizes come from build/**/*.o via nm. With no build (or a stale one), a
    # decompiled function contributes 0 bytes and the totals silently shrink
    # -- which reads as "no progress" rather than "unknown". Say so instead.
    src = ROOT / "src"
    missing = sorted(
        str(c.relative_to(src))
        for c in src.rglob("*.c")
        if not (ROOT / "build" / "src" / c.relative_to(src).with_suffix(".o")).exists()
    )

    # A matched function is deleted from data/*.s entirely (see CLAUDE.md's
    # loop, step 5), so `insns` alone would lose it from the report. Track it
    # separately, sized from its compiled object instead of asm bytes. Before
    # its asm block is deleted, both copies share one address and one unit.
    in_asm = by_address(insns)
    non_targets = set(by_address(runtime_library())) | LUVDIS_FALSE_POSITIVES | ARM_BLOCKS

    units, total, matched = [], 0, 0
    for addr in sorted(set(in_asm) | set(in_c)):
        is_done = addr in done
        if addr in in_asm:
            name = in_asm[addr]
            n = insns[name]
            # 2 bytes per Thumb instruction; trust nm only when it's plausible.
            est = n * 2
            size = sizes.get(name, est)
            if size > max(est * 4, 512):
                size = est
        else:
            name, size, _ = in_c[addr]
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
                "metadata": {"complete": is_done, "target": addr not in non_targets},
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
            " (vendored runtime library, luvdis false positives, hand-written ARM)"
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
            print("\n  nothing decompiled yet — see docs/decomp-guide.md")


def _selftest():
    insns = parse_asm()
    # The macro preamble defines `thumb_func_start name`; a bad parse yields a
    # phantom function literally called "name" -- once per split asm file.
    assert "name" not in insns, "preamble leaked into the parse"
    # 1159 total: luvdis's original 743 blocks, the 409 pointer-only or
    # uncalled Thumb functions it missed (seed_functions.py's POINTER_ONLY),
    # and the 7 ARM_BLOCKS, whether still in data/*.s or already matched in
    # src/*.c. blocks.txt holds them all, and asm/ plus src/ must account
    # for every one outside the libraries.
    assert len(BLOCKS) == len(set(BLOCKS)) == 1159, f"blocks.txt holds {len(set(BLOCKS))} blocks"
    in_asm = set(by_address(insns))
    assert in_asm <= set(BLOCKS), f"asm blocks missing from blocks.txt: {sorted(map(hex, in_asm - set(BLOCKS)))}"
    blocks = in_asm | set(c_blocks())
    assert not LIBRARY_BLOCKS & blocks, "a library block is back in asm/ or src/"
    # False positives count whether or not they're still in asm: the ones
    # inside extracted data (assets/*.json) left with it.
    lost = set(BLOCKS) - blocks - LIBRARY_BLOCKS - LUVDIS_FALSE_POSITIVES
    assert not lost, f"blocks in neither asm/ nor src/: {sorted(map(hex, lost))}"
    total = len(set(BLOCKS))
    assert 0x08006734 not in in_asm, "DummyUiFontLoad should be decompiled, not in asm"
    # All 92 runtime-library functions once flagged in asm now build from
    # source. The 7 luvdis false positives, the 7 ARM blocks and the 144
    # library blocks (73 newlib, 14 libagbsyscall, 6 m4a_1, 8 EEPROM, 9
    # MultiBoot, 34 libgcc) make 158 blocks that are not decompilation
    # targets: the game-code denominator is 1001.
    rt = runtime_library()
    assert not rt, f"runtime-library code is back in asm: {sorted(rt)}"
    rt_addrs = set(by_address(rt)) | LIBRARY_BLOCKS
    non_targets = rt_addrs | LUVDIS_FALSE_POSITIVES | ARM_BLOCKS
    assert total - len(non_targets) == 1001, (
        f"game-code denominator should be 1001, got {total - len(non_targets)}"
    )
    # Every address in the verified newlib map must be one of them.
    import json as _json

    mapped = {
        int(row[0], 16)
        for row in _json.loads((ROOT / "docs/learnings/runtime-newlib-map.json").read_text())
    }
    assert mapped <= rt_addrs, f"newlib map has {len(mapped - rt_addrs)} unflagged addresses"
    print(f"selftest ok ({len(insns)} functions remaining in asm)")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        _selftest()
    else:
        main()
