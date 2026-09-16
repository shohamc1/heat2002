#!/usr/bin/env python3
"""Run decomp-permuter on a near-miss draft.

    python3 scripts/permute.py NAME C_FILE [PERMUTER_ARGS...]
    python3 scripts/permute.py --selftest

For example:

    python3 scripts/permute.py sub_080112E0 docs/learnings/drafts/sub_080112E0.c -j8

This writes nonmatchings/NAME/ (base.c, target.o, compile.sh, settings.toml)
and starts tools/decomp-permuter/permuter.py on it. Each better candidate
lands in nonmatchings/NAME/output-SCORE-N/. Edit C_FILE, not base.c: every
run regenerates the directory's inputs.

The permuter's own import.py is not used, because its objects are unlinked.
The target asm writes pool entries as literal addresses while the C writes
`extern` symbols, so an unlinked candidate carries relocations the target
lacks and never reaches 0. Both sides are linked at the function's address
against nascar-heat.elf and symbols.ld instead, the same way match.py links.
import.py can't do that: it builds compile.sh from one project-wide command,
and the link address differs per function. (It also needs Homebrew's
`cpp-NN` on macOS, but installing that doesn't fix the linking.)

A score of 0 is a lead, not a match. The scorer compares objdump text and
ignores branch targets. Copy the candidate into src/NAME.c and confirm with
scripts/match.py.
"""

import os
import re
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path

from extract import PAD_RE, find_block, fragments, read_preamble
from match import ELF, LD, OBJCOPY, ROM, ROM_BASE, ROOT, SYMBOLS, addr_of

PERMUTER = ROOT / "tools" / "decomp-permuter" / "permuter.py"
# The permuter needs pycparser < 3 (3.0 removed pycparser.plyparser), so it
# runs from the project venv: .venv/bin/pip install "pycparser<3" toml
VENV_PYTHON = ROOT / ".venv" / "bin" / "python"

# The Makefile appends `.align 2, 0` to every .s it assembles (see its
# comment); both sides here do the same so their tails compare equal.
COMPILE_SH = """#!/bin/sh
# The permuter runs: compile.sh INPUT.c -o OUTPUT.o
set -e
cd {root}
{cc1} {cflags} "$1" -o "$3.s"
printf '\\t.align 2, 0\\n' >> "$3.s"
{as_} {asflags} -I include -o "$3.u.o" "$3.s"
{link} -o "$3" "$3.u.o"
rm -f "$3.s" "$3.u.o"
"""


def make_var(name):
    """A `NAME := value` from the Makefile, so flags can't drift from the build."""
    m = re.search(rf"^{name}\s*:=\s*(.*)$", (ROOT / "Makefile").read_text(), re.M)
    return m.group(1).strip()


def function_asm(name, texts=None):
    """The macro preamble plus NAME's instructions and literal pool."""
    for lines in texts or (f.read_text().splitlines() for f in fragments()):
        blk = find_block(lines, name)
        if blk is None:
            continue
        start, end, _ = blk
        # A pad with no pool after it is inter-function gap, not function.
        while PAD_RE.match(lines[end - 1]):
            end -= 1
        return "\n".join(read_preamble() + lines[start:end]) + "\n\t.align 2, 0\n"
    return None


def link_cmd(addr):
    return [LD, "-T", str(SYMBOLS), "-R", str(ELF), f"-Ttext={addr:#x}", "-e", f"{addr:#x}"]


def build_target(name, out, texts=None):
    """Assemble NAME's asm block and link it at its ROM address into `out`."""
    asm = function_asm(name, texts)
    if asm is None:
        sys.exit(f"{name}: not found in asm/*.s")
    src = out.with_suffix(".s")
    src.write_text(asm)
    unlinked = out.with_suffix(".u.o")
    run = lambda cmd: subprocess.run(cmd, cwd=ROOT, check=True)
    run([make_var("AS"), *make_var("ASFLAGS").split(), "-I", "include", "-o", str(unlinked), str(src)])
    run([*link_cmd(addr_of(name)), "-o", str(out), str(unlinked)])
    unlinked.unlink()


def setup(name, c_file):
    """Write nonmatchings/NAME/ and return its path."""
    if addr_of(name) is None:
        sys.exit(f"{name}: cannot derive an address from the name")
    if not ELF.exists():
        sys.exit(f"{ELF.name} not found -- run make first")
    d = ROOT / "nonmatchings" / name
    d.mkdir(parents=True, exist_ok=True)
    build_target(name, d / "target.o")

    # -P drops line markers, which the permuter's C parser rejects.
    cpp = [*make_var("CPP").split(), "-P", *make_var("CPPFLAGS").split(), str(c_file)]
    base = subprocess.run(cpp, cwd=ROOT, check=True, stdout=subprocess.PIPE, text=True)
    (d / "base.c").write_text(base.stdout)

    sh = d / "compile.sh"
    sh.write_text(COMPILE_SH.format(
        root=shlex.quote(str(ROOT)),
        cc1=make_var("CC1"),
        cflags=make_var("CFLAGS"),
        as_=make_var("AS"),
        asflags=make_var("ASFLAGS"),
        link=shlex.join(link_cmd(addr_of(name))),
    ))
    sh.chmod(0o755)
    (d / "settings.toml").write_text(f'func_name = "{name}"\ncompiler_type = "gcc"\n')
    return d


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    name, c_file, *args = sys.argv[1:]
    if not VENV_PYTHON.exists():
        sys.exit(f"{VENV_PYTHON} not found -- see the setup section of README.md")
    d = setup(name, Path(c_file).resolve())
    os.execv(VENV_PYTHON, [str(VENV_PYTHON), str(PERMUTER), str(d), *args])


def _selftest():
    assert make_var("CC1") == "tools/agbcc/old_agbcc", make_var("CC1")
    if not (ELF.exists() and ROM.exists()):
        print("selftest ok (target check skipped: needs nascar-heat.elf and baserom.gba)")
        return

    # The target must be the ROM's own bytes, or the permuter chases the
    # wrong thing. Runtime-library functions never leave asm, so this check
    # has a subject for as long as the repo exists.
    from progress import runtime_library

    texts = [f.read_text().splitlines() for f in fragments()]
    name = next(n for n in sorted(runtime_library()) if function_asm(n, texts))
    with tempfile.TemporaryDirectory() as tmp:
        out = Path(tmp) / "target.o"
        build_target(name, out, texts)
        blob = Path(tmp) / "target.bin"
        subprocess.run(
            [OBJCOPY, "-O", "binary", "--only-section=.text", str(out), str(blob)],
            check=True,
        )
        got = blob.read_bytes()
    start = addr_of(name) - ROM_BASE
    assert got and got == ROM.read_bytes()[start : start + len(got)], name
    print(f"selftest ok ({name}: {len(got)} bytes)")


if __name__ == "__main__":
    if sys.argv[1:] == ["--selftest"]:
        _selftest()
    else:
        main()
