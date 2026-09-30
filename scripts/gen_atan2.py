#!/usr/bin/env python3
"""Generate Atan2's lookup table (0x0806C97C-0x0807C97C, 65,536 bytes).

Atan2 (src/system/Atan2.c) returns t[(y + 128) * 256 + 128 + x], with x
and y scaled into -127..127, so t is a 256x256 table of u8 angles, 256
units per turn. The original tool evaluated atan2(x, y) * 128 / pi as a
double and truncated toward zero, as a C cast does; Python's math.atan2
is the same host libm double. `make check` compares the bytes with
baserom.gba, and `make check-code` compares them against the committed
reference hash, so a host libm that ever rounds one differently fails the
build loudly instead of silently changing the ROM.

The table's bytes are generated, not extracted: no ROM is needed, so the
build makes them in CI too (assets/generated.json, type "gen").

Usage: python3 scripts/gen_atan2.py OUT.bin
"""

import math
import sys


def main(out):
    table = bytearray(256 * 256)
    for y in range(-128, 128):
        for x in range(-128, 128):
            table[(y + 128) * 256 + (x + 128)] = \
                int(math.atan2(x, y) * 128 / math.pi) & 0xFF
    with open(out, "wb") as f:
        f.write(table)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    main(sys.argv[1])
