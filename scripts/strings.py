#!/usr/bin/env python3
"""Extract readable strings and compressed-asset candidates from the ROM.

None of this needs a decompiled function -- it only reads baserom.gba. The
point is that the ROM's 96% data payload is researchable in parallel with
matching work, and that knowing what a data table holds is what lets a
function be named something better than its address.

    python3 scripts/strings.py                 # game text
    python3 scripts/strings.py --compressed    # LZ77/RLE block candidates
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "baserom.gba"
BASE = 0x8000000

# Executable ROM regions. Strings inside code are almost always
# instruction bytes that happen to be printable, so they are excluded.
CODE = ((0x08000260, 0x0801CCD4), (0x08339920, 0x08344DA8), (0x0836419C, 0x083647FC))


def in_code(addr):
    return any(lo <= addr < hi for lo, hi in CODE)


def load():
    if not ROM.exists():
        sys.exit(f"{ROM} not found -- supply your own dump (see README)")
    return ROM.read_bytes()


def strings(data, min_len=6, alpha_ratio=0.6):
    """Printable runs that look like real text rather than stray bytes.

    The ratio filter is what separates 'PIT STOP NEEDED!' from compressed
    graphics data that happens to be printable ASCII.
    """
    out = []
    for m in re.finditer(rb"[ -~]{%d,}" % min_len, data):
        addr = BASE + m.start()
        if in_code(addr):
            continue
        s = m.group().decode("ascii")
        letters = sum(c.isalpha() or c.isspace() for c in s)
        if letters >= len(s) * alpha_ratio:
            out.append((addr, s))
    return out


def compressed(data):
    """GBA BIOS decompression header candidates.

    Byte 0 is the type (0x10 LZ77, 0x30 RLE), the next three are the
    decompressed size, little-endian. HEURISTIC: any 4 bytes can look like a
    header, so these are candidates to validate by decompressing, not facts.
    """
    found = []
    for off in range(0, len(data) - 3, 4):
        t = data[off]
        if t not in (0x10, 0x30):
            continue
        size = data[off + 1] | (data[off + 2] << 8) | (data[off + 3] << 16)
        if not (0x40 <= size <= 0x40000):
            continue
        addr = BASE + off
        if in_code(addr):
            continue
        found.append((addr, "LZ77" if t == 0x10 else "RLE", size))
    return found


def main():
    data = load()
    if "--compressed" in sys.argv:
        blocks = compressed(data)
        lz = sum(1 for b in blocks if b[1] == "LZ77")
        print(f"{len(blocks)} candidate blocks ({lz} LZ77, {len(blocks) - lz} RLE)")
        print("HEURISTIC -- validate by decompressing before trusting.\n")
        for addr, kind, size in sorted(blocks, key=lambda b: -b[2])[:25]:
            print(f"  {addr:#010x}  {kind:4s}  {size:>8,} bytes decompressed")
    else:
        found = strings(data)
        print(f"{len(found)} strings outside code regions\n")
        for addr, s in found:
            print(f"  {addr:#010x}  {s[:72]}")


def _selftest():
    # A printable run inside a code region must be rejected; the same run
    # outside must be kept.
    assert in_code(0x08000260) and not in_code(0x0829EA00)
    blob = b"\x00" * 16 + b"PIT STOP NEEDED!" + b"\x00" * 16
    got = strings(blob)
    assert any("PIT STOP NEEDED!" in s for _, s in got), got
    # Dense punctuation is compressed data, not text.
    assert not strings(b"\x00" + b";87+/;<77+++<77++7<<<;//;<87" + b"\x00")
    # A well-formed LZ77 header is found; a bogus type is not.
    assert compressed(b"\x10\x00\x01\x00")[0][1] == "LZ77"
    assert not compressed(b"\x99\x00\x01\x00")
    print("selftest ok")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        _selftest()
    else:
        main()
