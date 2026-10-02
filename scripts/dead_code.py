#!/usr/bin/env python3
"""List the functions in nascar-heat.elf that nothing in the ROM can reach.

A function is live when a root reaches it through the call graph. Edges are
`bl` and `b` instructions from inside one function to another function's
start, and any word in a function's extent (a literal pool) that holds
another function's address with its Thumb bit. Roots are the ARM functions
(the start routines and interrupt dispatchers), the first function of each
image, and every function pointer stored outside a function, such as a
task table.

With --check, compare the result with src/dead/ instead: exit 1 if a file
there defines a live function, or a file outside it defines only dead ones.
"""
import bisect
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ELF = ROOT / "nascar-heat.elf"
CODE = (".text", ".high_module", ".island")
SECTIONS = CODE + (".text_tail",)
BRANCH = re.compile(r"^\s*([0-9a-f]+):\s.*?\t(?:bl|blx|b(?:eq|ne|cs|cc|mi|pl|"
                    r"vs|vc|hi|ls|ge|lt|gt|le)?(?:\.n|\.w)?)\t([0-9a-f]+)")


def run(*args):
    return subprocess.run(args, capture_output=True, text=True,
                          check=True).stdout


def sections():
    """{name: (vma, file offset, size)} for the sections that hold the ROM."""
    out = {}
    for line in run("arm-none-eabi-readelf", "-SW", str(ELF)).splitlines():
        m = re.match(r"\s*\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+"
                     r"([0-9a-f]+)\s+([0-9a-f]+)", line)
        if m and m.group(1) in SECTIONS:
            out[m.group(1)] = tuple(int(g, 16) for g in m.groups()[1:])
    return out


def functions():
    """{address: (name, size, thumb bit)} for every FUNC symbol."""
    funcs = {}
    for line in run("arm-none-eabi-readelf", "-sW", str(ELF)).splitlines():
        f = line.split()
        if len(f) >= 8 and f[3] == "FUNC":
            addr = int(f[1], 16)
            funcs[addr & ~1] = (f[7], int(f[2], 0), addr & 1)
    return funcs


def dead_functions():
    """Names of the functions no root reaches."""
    secs = sections()
    funcs = functions()
    starts = sorted(funcs)

    def owner(addr):
        i = bisect.bisect_right(starts, addr) - 1
        if i < 0:
            return None
        s = starts[i]
        size = funcs[s][1]
        end = s + size if size else (starts[i + 1] if i + 1 < len(starts)
                                     else s)
        return s if addr < end else None

    edges = {s: set() for s in starts}
    roots = {s for s in starts if not funcs[s][2]}
    pointers = {s | funcs[s][2]: s for s in starts}

    blob = ELF.read_bytes()
    for name, (vma, off, size) in secs.items():
        if name in CODE:
            roots.add(min(s for s in starts if vma <= s < vma + size))
        for i in range(0, size - 3, 4):
            target = pointers.get(struct.unpack_from("<I", blob, off + i)[0])
            if target is not None:
                o = owner(vma + i)
                (edges[o].add if o is not None else roots.add)(target)

    jobs = [a for s in CODE for a in ("-j", s)]
    for line in run("arm-none-eabi-objdump", "-d", *jobs,
                    str(ELF)).splitlines():
        m = BRANCH.match(line)
        if m:
            o, dst = owner(int(m.group(1), 16)), int(m.group(2), 16)
            if o is not None and dst in funcs and dst != o:
                edges[o].add(dst)

    live, todo = set(), list(roots)
    while todo:
        s = todo.pop()
        if s not in live:
            live.add(s)
            todo.extend(edges[s])
    return {funcs[s][0] for s in starts if s not in live}


def check(dead):
    """Paths whose place (in src/dead/ or not) disagrees with `dead`."""
    wrong = []
    for c in sorted((ROOT / "src").rglob("*.c")):
        rel = c.relative_to(ROOT / "src")
        if rel.parts[0] in ("data", "platform"):
            # platform/ is the hosted port's layer: no GBA objects exist.
            continue
        obj = ROOT / "build" / "src" / rel.with_suffix(".o")
        names = [line.split()[2] for line in
                 run("arm-none-eabi-nm", "--defined-only", str(obj))
                 .splitlines() if line.split()[1] in "Tt"
                 and not line.split()[2].startswith(("$", ".", "gcc2"))]
        all_dead = bool(names) and all(n in dead for n in names)
        if all_dead != (rel.parts[0] == "dead"):
            wrong.append(f"src/{rel}")
    return wrong


def main():
    dead = dead_functions()
    if sys.argv[1:] == ["--check"]:
        wrong = check(dead)
        for path in wrong:
            print(f"misplaced: {path}")
        return 1 if wrong else 0
    for name in sorted(dead):
        print(name)
    return 0


if __name__ == "__main__":
    sys.exit(main())
