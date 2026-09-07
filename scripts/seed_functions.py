#!/usr/bin/env python3
"""Discover Thumb function entry points in a GBA ROM, emit a Luvdis config.

Two independent signals must agree before an address is called a function:
  1. something BL's to it (decoded from Thumb BL instruction pairs), and
  2. it starts with a `push {..., lr}` prologue.

Either signal alone is mostly noise on this ROM -- a bare 0xB5 byte scan hits
~1-in-256 by chance, and Luvdis' own call-graph reachability stalls at
0x801A56C. Requiring both cuts ~1300 candidates to ~600 real ones.
"""

import sys
from collections import Counter

ROM_BASE = 0x8000000


def bl_targets(data):
    """Decode every Thumb BL instruction pair, return target -> call count."""
    targets = Counter()
    for off in range(0, len(data) - 3, 2):
        hi = data[off] | (data[off + 1] << 8)
        lo = data[off + 2] | (data[off + 3] << 8)
        if 0xF000 <= hi <= 0xF7FF and 0xF800 <= lo <= 0xFFFF:
            disp = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
            if disp & 0x400000:  # sign-extend the 23-bit displacement
                disp -= 0x800000
            target = ROM_BASE + off + 4 + disp
            if ROM_BASE <= target < ROM_BASE + len(data):
                targets[target] += 1
    return targets


def has_push_lr(data, addr):
    off = addr - ROM_BASE
    # Thumb PUSH {..., lr} encodes as 0xB5xx (little-endian: high byte 0xB5).
    return off + 1 < len(data) and data[off + 1] == 0xB5


def main():
    if len(sys.argv) < 3:
        sys.exit("usage: seed_functions.py ROM OUT.cfg [START] [STOP]")
    rom, out = sys.argv[1], sys.argv[2]
    start = int(sys.argv[3], 0) if len(sys.argv) > 3 else ROM_BASE
    stop = int(sys.argv[4], 0) if len(sys.argv) > 4 else 0x8400000

    with open(rom, "rb") as f:
        data = f.read()

    targets = bl_targets(data)
    funcs = sorted(t for t in targets if start <= t < stop and has_push_lr(data, t))

    with open(out, "w") as f:
        f.write(f"# {len(funcs)} functions, 0 named, {len(funcs)} unnamed\n")
        f.write("# [arm_func|thumb_func] <address> [module] [name]\n")
        for addr in funcs:
            f.write(f"thumb_func 0x{addr:08X}\n")

    print(f"{len(funcs)} functions -> {out}")
    if funcs:
        print(f"range: {funcs[0]:#x} - {funcs[-1]:#x}")


def _selftest():
    # A BL at 0x8000000 targeting 0x8000100, which holds `push {r4, lr}`.
    data = bytearray(0x200)
    disp = 0x100 - 4
    hi = 0xF000 | ((disp >> 12) & 0x7FF)
    lo = 0xF800 | ((disp >> 1) & 0x7FF)
    data[0:4] = bytes([hi & 0xFF, hi >> 8, lo & 0xFF, lo >> 8])
    data[0x100:0x102] = bytes([0x10, 0xB5])  # push {r4, lr}
    assert bl_targets(bytes(data))[0x8000100] == 1
    assert has_push_lr(bytes(data), 0x8000100)
    assert not has_push_lr(bytes(data), 0x8000000)
    print("selftest ok")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--selftest":
        _selftest()
    else:
        main()
