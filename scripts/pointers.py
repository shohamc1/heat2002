#!/usr/bin/env python3
"""Count the raw pointers left in the built ROM.

A raw pointer is an aligned word that holds an address inside the ROM (or
inside an EWRAM image's run range, for a word in that image) and that no
relocation produced. The linker writes a relocated word from a symbol, so
it follows its target when the layout shifts; a raw one doesn't. A
relocation against a symbol that a linker script sets to a number (a
`symbols.ld` line such as `gUnk_08334E0A = 0x08334E0A;`) counts as raw too,
since it can't move either.

`make pointers` links build/nascar-heat.relocs.elf with --emit-relocs and
runs this script. It prints the total, the words whose target is a known
start (a symbol or an asset), and the biggest sources: the asset or the
symbol that holds each raw word. Graphics and tilemaps hold words that fall
in the ROM range by chance, so the known-start count is the better guide
to real pointers.

Usage:
    python3 scripts/pointers.py [--all]
    python3 scripts/pointers.py --selftest
"""

import bisect
import collections
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "nascar-heat.gba"
ELF = ROOT / "build" / "nascar-heat.relocs.elf"
ROM_BASE = 0x08000000


def tool(*cmd):
    return subprocess.run(cmd, capture_output=True, text=True, check=True).stdout


def sections(elf):
    """{name: (vma, lma, size)} for every section that loads into the ROM."""
    out = {}
    lines = tool("arm-none-eabi-objdump", "-h", elf).splitlines()
    for line, flags in zip(lines, lines[1:]):
        f = line.split()
        if len(f) == 7 and f[0].isdigit() and "LOAD" in flags:
            out[f[1]] = (int(f[3], 16), int(f[4], 16), int(f[2], 16))
    return out


def symbols(elf):
    """(value, type, section index, name) for every named symbol."""
    out = []
    for line in tool("arm-none-eabi-readelf", "-sW", elf).splitlines():
        f = line.split()
        if len(f) == 8 and f[0][:-1].isdigit():
            out.append((int(f[1], 16), f[3], f[6], f[7]))
    return out


def fixed_names():
    """Symbols that a linker script sets to a plain number."""
    return {m.group(1) for f in ("symbols.ld", "ldscript.ld")
            for m in re.finditer(r"^\s*(\w+) = 0x[0-9A-Fa-f]+;",
                                 (ROOT / f).read_text(), re.M)}


def relocated(elf, secs, absolute):
    """ROM addresses of the words the linker computed from a movable
    symbol, and of those it computed from a fixed number."""
    return parse_relocs(tool("arm-none-eabi-readelf", "-rW", elf), secs, absolute)


def parse_relocs(text, secs, absolute):
    """relocated() for readelf -rW output. An EWRAM image's relocation
    offsets are run addresses, so each maps back through its section."""
    moved, fixed, sec = set(), set(), None
    for line in text.splitlines():
        m = re.match(r"Relocation section '\.rel(\S+)'", line)
        if m:
            sec = secs.get(m.group(1))
            continue
        f = line.split()
        if sec is None or len(f) < 3 or f[2] != "R_ARM_ABS32":
            continue
        vma, lma, _ = sec
        rom = int(f[0], 16) - vma + lma
        (fixed if len(f) > 4 and f[4] in absolute else moved).add(rom)
    return moved, fixed


def scan(rom, ranges, moved):
    """Yield (address, value) for each aligned word that falls in a pointer
    range and that `moved` doesn't cover. `ranges` maps each ROM span
    (start, end) to the value spans a word there may point into."""
    for (start, end), targets in ranges.items():
        for a in range(start, end, 4):
            w = int.from_bytes(rom[a - ROM_BASE:a - ROM_BASE + 4], "little")
            if a not in moved and any(lo <= w < hi for lo, hi in targets):
                yield a, w


def assets():
    out = []
    for config in sorted((ROOT / "assets").glob("*.json")):
        data = json.loads(config.read_text())
        # assets/tracks.json also carries per-track metadata under "tracks"
        for a in (data["assets"] if isinstance(data, dict) else data):
            out.append((int(a["start"], 16), a["size"], a["path"]))
    return sorted(out)


def main(show_all):
    if not ELF.exists():
        sys.exit(f"{ELF.relative_to(ROOT)} is missing: run `make pointers`")
    secs = sections(ELF)
    rom = ROM.read_bytes()
    rom_end = max(lma + size for _, lma, size in secs.values())
    ranges = {}
    for vma, lma, size in secs.values():
        targets = [(ROM_BASE, rom_end)]
        if vma != lma:          # an EWRAM image also points at its run range
            targets.append((vma, vma + size))
        ranges[(lma, lma + size)] = targets
    syms = symbols(ELF)
    moved, fixed = relocated(ELF, secs, fixed_names())
    raw = sorted(scan(rom, ranges, moved))

    # A known start: a 4-byte-aligned asset or data label, or a function's
    # entry point (odd for Thumb, as readelf shows it). Tilemaps are full of
    # halfword pairs that land on odd or 2-mod-4 addresses by chance.
    syms = [s for s in syms if s[2] not in ("ABS", "UND")
            and s[1] != "SECTION" and not s[3].startswith("$")]
    blobs = assets()
    starts = ({v for v, t, _, _ in syms if t == "FUNC" or v % 4 == 0}
              | {s for s, _, _ in blobs if s % 4 == 0})
    named = sorted({v & ~1: n for v, _, _, n in reversed(syms)
                    if v >= ROM_BASE and n[0] != "."}.items())
    keys = [s for s, _ in named]
    blob_keys = [s for s, _, _ in blobs]

    def source(a):
        i = bisect.bisect_right(blob_keys, a) - 1
        if i >= 0 and a < blobs[i][0] + blobs[i][1]:
            return blobs[i][2]
        i = bisect.bisect_right(keys, a) - 1
        return named[i][1] if i >= 0 else "?"

    known = [(a, w) for a, w in raw if w in starts]
    print(f"raw ROM pointers: {len(raw)} aligned words "
          f"({len(known)} on a known start)")
    print(f"  of which from a linker-script number: "
          f"{sum(a in fixed for a, _ in raw)}")
    print(f"relocated words (not counted): {len(moved)}")
    by = collections.Counter(source(a) for a, _ in raw)
    good = collections.Counter(source(a) for a, _ in known)
    print("\nbiggest sources (all / on a known start):")
    for src, n in by.most_common(None if show_all else 25):
        print(f"  {n:6} {good[src]:6}  {src}")


def selftest():
    words = [0x08000010, 0x08000011, 0x12345678, 0x02000004, 0x08000008]
    rom = b"".join(w.to_bytes(4, "little") for w in words)
    ranges = {(ROM_BASE, ROM_BASE + 12): [(ROM_BASE, ROM_BASE + 20)],
              (ROM_BASE + 12, ROM_BASE + 20): [(ROM_BASE, ROM_BASE + 20),
                                               (0x02000000, 0x02000008)]}
    got = list(scan(rom, ranges, {ROM_BASE + 4}))
    # word 1 is relocated, word 2 is out of range, and the EWRAM value
    # counts only in the image's span
    assert got == [(ROM_BASE, 0x08000010), (ROM_BASE + 12, 0x02000004),
                   (ROM_BASE + 16, 0x08000008)], got
    assert not list(scan(rom, {(ROM_BASE, ROM_BASE + 16):
                               [(ROM_BASE, ROM_BASE + 20)]},
                         {ROM_BASE, ROM_BASE + 4}))
    secs = {".high_module": (0x02000D00, 0x08339780, 0x100)}
    text = """Relocation section '.rel.high_module' at offset 0x0 contains 3 entries:
 Offset     Info    Type                Sym. Value  Symbol's Name
02000d2c  00000402 R_ARM_ABS32            02000d00   sub_08339780
02000d30  00000402 R_ARM_ABS32            02000d00   gUnk_0200C668
02000d34  0026561d R_ARM_THM_CALL         02000d00   sub_08339780
Relocation section '.rel.text' at offset 0x0 contains 1 entry:
08000218  00000402 R_ARM_ABS32            0800020c   .text
"""
    # the unknown section's relocation is ignored, a call isn't a word,
    # and the fixed name lands in `fixed`
    moved, fixed = parse_relocs(text, secs, {"gUnk_0200C668"})
    assert moved == {0x083397AC} and fixed == {0x083397B0}, (moved, fixed)
    print("selftest ok")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        selftest()
    else:
        main("--all" in sys.argv)
