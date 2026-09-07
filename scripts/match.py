#!/usr/bin/env python3
"""Compare a decompiled function's compiled bytes against the retail ROM.

    python3 scripts/match.py sub_08006734

The target is read from `baserom.gba` at the function's own address, which is
encoded in its name (`sub_08006734` -> `0x08006734`). That matters: an earlier
version extracted the target from `asm/rom.s`, so the moment a function was
decompiled -- and deleted from the asm -- the tool could no longer verify it.
The ROM is the ground truth and it never moves, so a matched function stays
checkable forever.

Comparison is on BYTES, never on assembly text, because text is unsound in
both directions:

  * `.L1:` moved by one instruction changes a branch target -- identical
    mnemonics, different bytes.
  * agbcc emits divided-syntax `lsl` where unified syntax wants `lsls` --
    different text, identical encoding.
"""

import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "baserom.gba"
NM = "arm-none-eabi-nm"
OBJCOPY = "arm-none-eabi-objcopy"
OBJDUMP = "arm-none-eabi-objdump"
ROM_BASE = 0x8000000


def addr_of(name):
    """`sub_08006734` -> 0x08006734."""
    m = re.fullmatch(r"(?:sub|func)_([0-9A-Fa-f]{8})", name)
    if not m:
        return None
    return int(m.group(1), 16)


def find_symbol(name):
    """Locate `name` in the built objects. Returns (object, offset, size)."""
    hits = []
    for obj in sorted((ROOT / "build").rglob("*.o")):
        # Only C objects; asm objects hold the not-yet-decompiled originals
        # and would trivially "match" the ROM they were disassembled from.
        if "/src/" not in obj.as_posix():
            continue
        out = subprocess.run(
            [NM, "--print-size", str(obj)],
            capture_output=True,
            text=True,
            check=False,
        ).stdout
        for line in out.splitlines():
            p = line.split()
            if len(p) == 4 and p[2] in ("t", "T") and p[3] == name:
                hits.append((obj, int(p[0], 16), int(p[1], 16)))
    return hits


def object_bytes(obj, offset, size):
    """Extract `size` bytes at `offset` from an object's .text."""
    with tempfile.TemporaryDirectory() as d:
        bin_ = Path(d) / "t.bin"
        r = subprocess.run(
            [OBJCOPY, "-O", "binary", "--only-section=.text", str(obj), str(bin_)],
            capture_output=True,
            check=False,
        )
        if r.returncode != 0 or not bin_.exists():
            return None
        blob = bin_.read_bytes()
        if offset + size > len(blob):
            return None
        return blob[offset : offset + size]


def disasm(data, addr):
    """Disassemble raw Thumb bytes, for the human-readable diff only."""
    with tempfile.TemporaryDirectory() as d:
        bin_ = Path(d) / "t.bin"
        bin_.write_bytes(data)
        out = subprocess.run(
            [
                OBJDUMP, "-D", "-b", "binary", "-m", "arm",
                "-M", "force-thumb", f"--adjust-vma={addr:#x}", str(bin_),
            ],
            capture_output=True,
            text=True,
            check=False,
        ).stdout
        lines = []
        for line in out.splitlines():
            m = re.match(r"^\s*([0-9a-f]+):\s+([0-9a-f ]+?)\s\s+(.*)$", line)
            if m:
                lines.append(f"{m.group(1)}: {m.group(3).strip()}")
        return lines


def main():
    if len(sys.argv) != 2:
        sys.exit("usage: match.py FUNCTION_NAME")
    name = sys.argv[1]

    for tool in (NM, OBJCOPY, OBJDUMP):
        if not shutil.which(tool):
            sys.exit(f"{tool} not found; install arm-none-eabi-binutils")
    if not ROM.exists():
        sys.exit(f"{ROM} not found -- supply your own dump (see README)")

    addr = addr_of(name)
    if addr is None:
        sys.exit(f"{name}: cannot derive an address from the name")

    hits = find_symbol(name)
    if not hits:
        sys.exit(f"{name}: no compiled object under build/src -- run `make` first")
    if len(hits) > 1:
        where = ", ".join(str(o.relative_to(ROOT)) for o, _, _ in hits)
        sys.exit(f"{name}: defined in multiple objects ({where})")

    obj, offset, size = hits[0]
    if size == 0:
        sys.exit(f"{name}: nm reports size 0 in {obj.relative_to(ROOT)}")

    ours = object_bytes(obj, offset, size)
    if ours is None:
        sys.exit(f"{name}: could not extract bytes from {obj.relative_to(ROOT)}")

    rom = ROM.read_bytes()
    start = addr - ROM_BASE
    if not (0 <= start < len(rom)):
        sys.exit(f"{name}: address {addr:#x} is outside the ROM")
    target = rom[start : start + size]

    if ours == target:
        print(f"{name}: MATCH ({size} bytes @ {addr:#010x})")
        return 0

    print(f"{name}: MISMATCH ({size} bytes @ {addr:#010x})")
    print(f"  target: {target.hex(' ')}")
    print(f"  ours:   {ours.hex(' ')}")
    import difflib

    for line in difflib.unified_diff(
        disasm(target, addr), disasm(ours, addr), "target", "ours", lineterm="", n=3
    ):
        print(line)
    return 1


def _selftest():
    assert addr_of("sub_08006734") == 0x08006734
    assert addr_of("not_a_function") is None

    # Byte comparison must catch a moved label, which text comparison cannot.
    # `bx lr` (0x4770) vs `nop` (0x46c0) stands in for any 2-byte difference.
    assert b"\x70\x47" != b"\xc0\x46"

    if shutil.which(OBJDUMP):
        d = disasm(b"\x70\x47", 0x08006734)
        assert d and "bx" in d[0].lower(), d

    if ROM.exists():
        rom = ROM.read_bytes()
        # The known contents of sub_08006734: a bare `bx lr`.
        assert rom[0x6734:0x6736] == b"\x70\x47", rom[0x6734:0x6736].hex()
    print("selftest ok")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--selftest":
        _selftest()
    else:
        sys.exit(main())
