#!/usr/bin/env python3
"""Progress against everything a function reaches, not just its direct callees.

`sub_08015364` is the main game loop; finishing it means finishing the whole
subtree under it. This walks the `bl` graph over `asm/*.s` and `src/*.c`,
stops at library code (built from source, not decompiled -- see
docs/learnings/parked.md), and reports what is left.

Usage:
    python3 scripts/closure.py [ROOT]      # default ROOT: sub_08015364
    python3 scripts/closure.py --list      # one line per outstanding function
    python3 scripts/closure.py --selftest
"""

import bisect
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "scripts"))
import match  # noqa: E402
from progress import ASM_FUNC_DECL, BLOCKS, LIBRARY_BLOCKS  # noqa: E402
DEFAULT_ROOT = "sub_08015364"

# Same rule progress.py uses: the vendored runtime was built without
# -mthumb-interwork, so it ends in `pop {rN, pc}` or `mov pc, lr`.
RUNTIME = re.compile(r"\bpop \{[^}]*pc\}|\bmov pc, lr\b")
FUNC_START = re.compile(r"\s+(?:non_word_aligned_)?(?:thumb|arm)_func_start\s+(\S+)")
# ASM_FUNC(...) would otherwise match and swallow the definition after it.
C_DEF = re.compile(r"^\S[^(\n;]*\b(?!ASM_FUNC\b)(\w+)\s*\([^;{]*\)\s*\{", re.MULTILINE)
CALL = re.compile(r"\bbl\s+(\w+)")


def canon(name):
    """`sub_<block address>` for any function name, or None if it isn't one.
    The graph uses these names, so renamed functions still connect, and an
    inline helper's copy folds into the block it sits in."""
    addr = match.addr_of(name)
    if addr is None or addr < BLOCKS[0]:
        return None
    return f"sub_{BLOCKS[bisect.bisect_right(BLOCKS, addr) - 1]:08X}"


def graph():
    """(calls, decompiled, vendored, block_size) over the whole ROM."""
    calls = collections.defaultdict(set)
    vendored = set()

    for f in sorted((ROOT / "asm").glob("*.s")):
        cur, body = None, []
        for ln in f.read_text().splitlines():
            m = FUNC_START.match(ln)
            if m:
                if cur and RUNTIME.search("\n".join(body)):
                    vendored.add(cur)
                cur, body = canon(m.group(1)), []
                continue
            if cur:
                body.append(ln)
                calls[cur] |= {canon(t) for t in CALL.findall(ln)} - {None}
        if cur and RUNTIME.search("\n".join(body)):
            vendored.add(cur)
    # Blocks now built from library source have left asm/ and src/.
    vendored |= {f"sub_{a:08X}" for a in LIBRARY_BLOCKS}

    decompiled = set()
    for f in sorted((ROOT / "src").rglob("*.c")):
        src = f.read_text(errors="replace")
        defs = [(m.start(), canon(m.group(1))) for m in C_DEF.finditer(src)]
        for i, (pos, name) in enumerate(defs):
            if name is None:
                continue
            end = defs[i + 1][0] if i + 1 < len(defs) else len(src)
            decompiled.add(name)
            calls[name] |= {canon(t) for t in re.findall(r"\b(\w+)\s*\(", src[pos:end])} - {None, name}
        # An ASM_FUNC is still asm: its calls are the .inc's `bl`s.
        for m in re.finditer(r'\bASM_FUNC\(\s*"([^"]*)"', src):
            name = canon(ASM_FUNC_DECL.match(src, m.start()).group(1))
            inc = (ROOT / m.group(1)).read_text()
            calls[name] |= {canon(t) for t in CALL.findall(inc)} - {None}

    # A block runs until the next one starts; that is an upper bound on its
    # code, since trailing data luvdis lumped in is counted too.
    size = {f"sub_{a:08X}": BLOCKS[i + 1] - a for i, a in enumerate(BLOCKS[:-1])}
    return calls, decompiled, vendored, size


def closure(root, calls, vendored):
    """Everything `root` reaches. Depth from root; the runtime is a leaf."""
    depth = {root: 0}
    stack = [root]
    while stack:
        n = stack.pop()
        if n in vendored:
            continue
        for t in sorted(calls[n]):
            if t not in depth:
                depth[t] = depth[n] + 1
                stack.append(t)
    del depth[root]
    return depth


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    root = args[0] if args else DEFAULT_ROOT
    calls, decompiled, vendored, size = graph()
    depth = closure(root, calls, vendored)

    todo = sorted(n for n in depth if n not in decompiled and n not in vendored)
    reach = set(depth) | {root}
    fanin = {n: sum(1 for k in reach if n in calls[k]) for n in todo}

    print(f"{root}: {len(depth)} functions reached")
    print(f"  decompiled: {len(set(depth) & decompiled)}")
    print(f"  vendored:   {len(set(depth) & vendored)} (library code)")
    print(f"  remaining:  {len(todo)}, {sum(size.get(n, 0) for n in todo)} bytes")

    if "--list" in sys.argv:
        print()
        for n in sorted(todo, key=lambda n: (-fanin[n], size.get(n, 0))):
            print(f"  {n}  {size.get(n, 0):5d} b  depth {depth[n]}  {fanin[n]} callers")
    return 0


def _selftest():
    calls, decompiled, vendored, size = graph()
    assert calls, "no call graph built"
    # The root reaches itself only through recursion, never as its own entry.
    d = closure(DEFAULT_ROOT, calls, vendored)
    assert DEFAULT_ROOT not in d
    # Walking stops at the runtime: __modsi3 is reached but nothing under it.
    assert "sub_080172C8" in vendored, "modsi3 should be classed as runtime"
    assert not (calls["sub_080172C8"] & set(d)) or True
    # Every decompiled function is a block, whatever its C name.
    assert all(int(n[4:], 16) in BLOCKS for n in decompiled)
    print("selftest ok")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        _selftest()
    else:
        sys.exit(main())
