#!/usr/bin/env python3
"""Batch-extract all currently-matched functions.

For every src/*.c whose function MATCHes (verified via match.py's compare),
run the extract.py cut, then regenerate ldscript.ld's explicit object list
from scratch in address order. Idempotent-ish: refuses on size mismatch,
skips functions already extracted (not in any asm fragment).

Usage: python3 scripts/batch_extract.py [--dry-run]
"""

import re
import sys
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "scripts"))
import extract as ex  # noqa: E402
import match as m  # noqa: E402


def matched_functions():
    """(name, size, addr) for every src/*.c that byte-matches the ROM."""
    out = []
    for f in sorted((ROOT / "src").glob("sub_*.c")):
        name = f.stem
        try:
            ours, target, size, addr = m.compare(name)
        except SystemExit:
            continue
        if ours == target:
            out.append((name, size, addr))
    return out


def still_in_asm(name):
    for f in ex.fragments():
        if re.search(r"\tthumb_func_start " + name + r"$", f.read_text(), re.M):
            return True
    return False


def objects_in_order():
    """All placement lines (src objects + asm fragments) sorted by the ROM
    address each lands at. asm fragment rom_XXXX.s lands at 0x0XXXX; src
    object sub_XXXX.c lands at its function address."""
    lines = []
    for f in sorted((ROOT / "asm").glob("*.s")):
        mm = re.match(r"rom_([0-9A-F]{8})\.s", f.name)
        if mm:
            lines.append((int(mm.group(1), 16), f"build/asm/{f.stem}.o(.text*);"))
    for f in sorted((ROOT / "src").glob("sub_*.c")):
        addr = int(f.stem[4:], 16)
        lines.append((addr, f"build/src/{f.stem}.o(.text*);"))
    # rom.o (the head fragment) has no address in its name; it goes first
    return [(0x08000000, "build/asm/rom.o(.text*);")] + sorted(lines)


def rewrite_ldscript():
    p = ROOT / "ldscript.ld"
    text = p.read_text()
    body = "\n".join(f"        {l}" for _, l in objects_in_order())
    new = re.sub(
        r"(\.text : ALIGN\(4\)\n    \{\n)(.*?)(\n        /\* Catch-all)",
        lambda mo: mo.group(1) + body + mo.group(3),
        text,
        flags=re.S,
    )
    if new == text:
        raise SystemExit("ldscript rewrite failed (pattern not found)")
    p.write_text(new)


def main():
    dry = "--dry-run" in sys.argv
    matched = matched_functions()
    todo = [(n, s, a) for n, s, a in matched if still_in_asm(n)]
    print(f"{len(matched)} matched, {len(todo)} still to extract")
    for name, size, addr in sorted(todo, key=lambda t: t[2]):
        if dry:
            print(f"  would extract {name} ({size}B @ {addr:#x})")
            continue
        r = subprocess.run(
            [sys.executable, str(ROOT / "scripts" / "extract.py"), name],
            capture_output=True, text=True,
        )
        print(f"  {r.stdout.strip() or r.stderr.strip()}")
        if r.returncode != 0:
            raise SystemExit(f"extraction of {name} failed -- stopping")
    if not dry:
        rewrite_ldscript()
        print("ldscript.ld rewritten")


if __name__ == "__main__":
    main()
