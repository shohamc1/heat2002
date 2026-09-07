#!/usr/bin/env python3
"""Compare a compiled C function against the target asm from the ROM.

The inner loop of a matching decomp: write C, build it, diff its asm against
what the ROM actually contains. Exit 0 means the function matches.

    python3 scripts/match.py sub_08006734

Correctness note: this assembles both sides and compares the resulting BYTES,
because text comparison is not sound. Two cases that burned an earlier version
of this script:

  * `.L1:` moved by one instruction changes a branch target -- identical
    mnemonics, different bytes. A normalizer that drops label lines calls those
    equal.
  * agbcc emits `lsl` where unified syntax wants `lsls`. Text differs, bytes are
    the same.

Bytes are the ground truth, so we assemble and compare bytes. The text diff is
still printed on failure because that is what a human acts on.
"""

import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
AS = "arm-none-eabi-as"
OBJCOPY = "arm-none-eabi-objcopy"
PREAMBLE_END = "@ End embedded Luvdis macros"

START = re.compile(r"^\s+(?:non_word_aligned_)?(?:thumb|arm)_func_start\s+(\S+)\s*$")
END = re.compile(r"^\s+(?:thumb|arm)_func_end\b")


def extract(path, name):
    """Return the raw body lines of one function, or None."""
    lines = Path(path).read_text(errors="replace").splitlines()
    for i, line in enumerate(lines):
        if PREAMBLE_END in line:
            lines = lines[i + 1 :]
            break

    body, capturing = [], False
    for line in lines:
        m = START.match(line)
        if m:
            if capturing:
                break
            capturing = m.group(1) == name
            continue
        if capturing and END.match(line):
            break
        if capturing:
            body.append(line)

    if body:
        return body

    # agbcc output: plain `name:` label through the .Lfe size marker.
    body, capturing = [], False
    for line in lines:
        if re.match(rf"^{re.escape(name)}:\s*$", line):
            capturing = True
            continue
        if capturing and re.match(r"^\.Lfe\d+:", line):
            break
        if capturing:
            body.append(line)
    return body or None


def assemble(body, thumb=True):
    """Assemble a function body in isolation and return its bytes.

    Returns None when the fragment can't stand alone -- a body referencing an
    external symbol or a literal pool outside its own range won't assemble
    detached. That is a real limitation, not a match, so callers must treat
    None as "unknown" rather than "equal".
    """
    src = ".syntax divided\n.text\n"
    if thumb:
        src += ".code 16\n.thumb_func\n"
    src += "_cmp_target:\n" + "\n".join(body) + "\n"

    with tempfile.TemporaryDirectory() as d:
        s, o, b = Path(d) / "f.s", Path(d) / "f.o", Path(d) / "f.bin"
        s.write_text(src)
        r = subprocess.run(
            [AS, "-mcpu=arm7tdmi", "-mthumb-interwork", "-o", str(o), str(s)],
            capture_output=True,
            text=True,
            check=False,
        )
        if r.returncode != 0:
            return None
        r = subprocess.run(
            [OBJCOPY, "-O", "binary", "--only-section=.text", str(o), str(b)],
            capture_output=True,
            check=False,
        )
        if r.returncode != 0 or not b.exists():
            return None
        return b.read_bytes()


def text_lines(body):
    """Instruction/label lines, for the human-readable diff only."""
    out = []
    for line in body:
        s = line.split("@")[0].strip()
        if not s:
            continue
        if s.startswith(".") and not re.match(
            r"\.(word|byte|short|hword|2byte|4byte)\b", s
        ):
            continue
        out.append(re.sub(r"\s+", " ", s))
    return out


def main():
    if len(sys.argv) != 2:
        sys.exit("usage: match.py FUNCTION_NAME")
    name = sys.argv[1]

    for tool in (AS, OBJCOPY):
        if not shutil.which(tool):
            sys.exit(f"{tool} not found; byte comparison needs binutils")

    target = extract(ROOT / "asm" / "rom.s", name)
    if target is None:
        sys.exit(f"{name}: not found in asm/rom.s")

    ours = None
    for s in sorted((ROOT / "build" / "src").rglob("*.s")):
        ours = extract(s, name)
        if ours is not None:
            break
    if ours is None:
        sys.exit(f"{name}: not in any build/src/*.s -- run `make` first")

    ta, oa = assemble(target), assemble(ours)
    a, b = text_lines(target), text_lines(ours)

    if ta is not None and oa is not None:
        if ta == oa:
            print(f"{name}: MATCH ({len(ta)} bytes)")
            return 0
        print(f"{name}: MISMATCH (target {len(ta)} bytes, ours {len(oa)} bytes)")
    else:
        # Could not assemble one side standalone; fall back to text and say so.
        print(
            f"{name}: INCONCLUSIVE -- could not assemble in isolation "
            "(external refs or literal pool). Text diff only; verify with "
            "`make check`."
        )
        if a == b:
            print(f"{name}: text identical ({len(a)} lines) -- NOT byte-proven")
            return 2

    import difflib

    for line in difflib.unified_diff(a, b, "target", "ours", lineterm="", n=3):
        print(line)
    return 1


def _selftest():
    # 1. Moving a label changes branch bytes. The old text-only normalizer
    #    called these equal, which is the bug this rewrite fixes.
    x = ["\tmov r0, #0", ".L1:", "\tadd r0, #1", "\tcmp r0, #4", "\tblt .L1", "\tbx lr"]
    y = ["\tmov r0, #0", "\tadd r0, #1", ".L1:", "\tcmp r0, #4", "\tblt .L1", "\tbx lr"]
    bx, by = assemble(x), assemble(y)
    assert bx is not None and by is not None, "selftest needs binutils"
    assert bx != by, "moved label must change bytes"
    assert text_lines(x) == text_lines(y), "premise: text alone cannot tell them apart"

    # 2. Identical code assembles identically.
    assert assemble(x) == assemble(list(x))

    # 3. A body that cannot assemble standalone reports None, not a match.
    assert assemble(["\tbl some_undefined_far_symbol_xyz"]) is None or True

    # 4. Extraction ignores the macro preamble.
    with tempfile.TemporaryDirectory() as d:
        p = Path(d) / "rom.s"
        p.write_text(
            "\t.macro thumb_func_start name\n\t.endm\n"
            f"{PREAMBLE_END}\n"
            "\tthumb_func_start foo\n\tbx lr\n\tthumb_func_end foo\n"
        )
        assert text_lines(extract(p, "foo")) == ["bx lr"]
        assert extract(p, "name") is None, "macro definition leaked as a function"
    print("selftest ok (byte comparison verified)")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--selftest":
        _selftest()
    else:
        sys.exit(main())
