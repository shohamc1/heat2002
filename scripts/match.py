#!/usr/bin/env python3
"""Compare a compiled C function against the target asm from the ROM.

The inner loop of a matching decomp: write C, build it, diff its asm against
what the ROM actually contains. Exit 0 means the function matches and can be
moved from asm/ into src/.

    python3 scripts/match.py sub_8000260
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Normalize away everything that can't affect emitted bytes: directives,
# comments, label numbering, and whitespace.
DROP = re.compile(r"^\s*(@|\.(?!word|byte|short|hword|4byte|align|balign)|$)")


def normalize(asm):
    out = []
    for line in asm.splitlines():
        line = line.split("@")[0].rstrip()
        if not line or DROP.match(line):
            continue
        out.append(re.sub(r"\s+", " ", line.strip()))
    return out


def extract(path, name):
    """Pull one function's body out of an asm file."""
    text = Path(path).read_text(errors="replace")
    pat = re.compile(
        rf"^\s*(?:thumb_func_start|arm_func_start)\s+{re.escape(name)}\s*$"
        rf"(.*?)"
        rf"^\s*(?:thumb_func_end|arm_func_end|thumb_func_start|arm_func_start)\b",
        re.S | re.M,
    )
    m = pat.search(text)
    if m:
        return m.group(1)
    # agbcc output uses plain labels rather than the Luvdis macros.
    pat2 = re.compile(rf"^{re.escape(name)}:\s*$(.*?)^\.Lfe\d+:", re.S | re.M)
    m = pat2.search(text)
    return m.group(1) if m else None


def main():
    if len(sys.argv) != 2:
        sys.exit("usage: match.py FUNCTION_NAME")
    name = sys.argv[1]

    target = extract(ROOT / "asm" / "rom.s", name)
    if target is None:
        sys.exit(f"{name}: not found in asm/rom.s")

    # Find whichever built .s contains our version of the function.
    ours = None
    for s in (ROOT / "build" / "src").rglob("*.s"):
        ours = extract(s, name)
        if ours is not None:
            break
    if ours is None:
        sys.exit(f"{name}: not found in any build/src/*.s -- run `make` first")

    a, b = normalize(target), normalize(ours)
    if a == b:
        print(f"{name}: MATCH ({len(a)} insns)")
        return 0

    import difflib

    print(f"{name}: MISMATCH (target {len(a)} insns, ours {len(b)})")
    for line in difflib.unified_diff(a, b, "target", "ours", lineterm="", n=3):
        print(line)
    return 1


def _selftest():
    import tempfile

    src = "thumb_func_start foo\n\tadd r0, r1\n\t@ note\nthumb_func_end foo\n"
    with tempfile.TemporaryDirectory() as d:
        p = Path(d) / "selftest.s"
        p.write_text(src)
        assert normalize(extract(p, "foo")) == ["add r0, r1"]
        assert extract(p, "bar") is None
    print("selftest ok")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--selftest":
        _selftest()
    else:
        sys.exit(main())
