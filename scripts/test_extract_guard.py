#!/usr/bin/env python3
"""Regression test: the cross-object guard flags every hazard mnemonic.

`referenced_labels` decides which `_XXXXXXXX` operands stop an extraction.
A PC-relative `ldr` pool load and every conditional branch are computed by
the assembler inside one object, so they are hazards; only `bl`/`blx` emit
link-time relocations and may cross an object boundary.

An earlier `not mn.startswith("bl")` exemption silently swallowed `ble`,
`bls` and `blt` -- 486 branches in asm/ -- because they share bl's prefix.
This pins the full mnemonic set that actually appears in the disassembly.

    python3 scripts/test_extract_guard.py
"""

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import extract

# Every mnemonic in asm/*.s that takes a _XXXXXXXX operand, plus the
# ldr byte/halfword forms, which are never PC-relative in Thumb.
HAZARD = ["ldr", "b", "beq", "bne", "ble", "bge", "bhi", "bls", "bgt", "blt",
          "bcc", "bcs", "bpl"]
EXEMPT = ["bl", "blx"]


def flagged(mnemonic):
    line = f"\t{mnemonic} _08001234\n"
    return extract.referenced_labels([line], 0, 1) == {"_08001234"}


def main():
    bad = [m for m in HAZARD if not flagged(m)]
    bad += [f"{m} (should be exempt)" for m in EXEMPT if flagged(m)]
    if bad:
        print("FAIL: " + ", ".join(bad))
        return 1
    print(f"OK: {len(HAZARD)} hazard mnemonics flagged, {len(EXEMPT)} exempt")
    return 0


if __name__ == "__main__":
    sys.exit(main())
