#!/usr/bin/env python3
"""Regression test: no NOP filler (46c0) at the end of any built object.

gas rounds a .text section's end up to its alignment with NOPs; the ROM has
only zeros between functions. The Makefile appends `.align 2, 0` to every
generated .s so the rounding uses explicit zero fill instead. This pins that
for both a C function (mid-body literal pool, 2-mod-4 tail) and an asm
fragment ending 2 mod 4.

    python3 scripts/test_alignment.py
"""

import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
AS = ["arm-none-eabi-as", "-mcpu=arm7tdmi", "-mthumb-interwork"]

C_SRC = "extern unsigned int g;\nunsigned int f(unsigned int x) { if (x) g = 0x12345678; return x * 3; }\n"
ASM_SRC = "\t.code 16\n.text\n\t.align 2, 0\n\t.thumb_func\nf:\n\tmovs r0, #0\n\tpop {r0}\n\tbx r0\n"


def text_bytes(d, asm):
    (d / "t.s").write_text(asm + "\t.align 2, 0\n")  # same append as the Makefile
    subprocess.run(AS + ["-o", d / "t.o", d / "t.s"], check=True)
    subprocess.run(["arm-none-eabi-objcopy", "-O", "binary", "-j", ".text", d / "t.o", d / "t.bin"], check=True)
    return (d / "t.bin").read_bytes()


def main():
    with tempfile.TemporaryDirectory() as tmp:
        d = Path(tmp)
        (d / "t.i").write_text(C_SRC)
        subprocess.run([ROOT / "tools/agbcc/old_agbcc", "-O2", "-mthumb-interwork", d / "t.i", "-o", d / "c.s"], check=True)
        for name, asm in (("c", (d / "c.s").read_text()), ("asm", ASM_SRC)):
            b = text_bytes(d, asm)
            assert len(b) % 4 == 0, f"{name}: section not rounded ({len(b)} bytes)"
            assert b[-2:] != b"\xc0\x46", f"{name}: NOP filler at section end"
    print("alignment ok (zero fill, no 46c0)")


if __name__ == "__main__":
    sys.exit(main())
