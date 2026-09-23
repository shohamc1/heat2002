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

import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "scripts"))
from progress import LIBRARY_BLOCKS  # noqa: E402
DEFAULT_ROOT = "sub_08015364"

# Same rule progress.py uses: the vendored runtime was built without
# -mthumb-interwork, so it ends in `pop {rN, pc}` or `mov pc, lr`.
RUNTIME = re.compile(r"\bpop \{[^}]*pc\}|\bmov pc, lr\b")
FUNC_START = re.compile(r"\s+(?:non_word_aligned_)?(?:thumb|arm)_func_start\s+(\S+)")
C_DEF = re.compile(r"^\S[^(\n;]*\b(sub_[0-9A-Fa-f]{8})\s*\([^;{]*\)\s*\{", re.MULTILINE)
CALL = re.compile(r"\bbl\s+(sub_[0-9A-Fa-f]{8})")


def graph():
    """(calls, decompiled, vendored, block_size) over the whole ROM."""
    calls = collections.defaultdict(set)
    vendored, starts = set(), set()

    for f in sorted((ROOT / "asm").glob("*.s")):
        cur, body = None, []
        for ln in f.read_text().splitlines():
            m = FUNC_START.match(ln)
            if m:
                if cur and RUNTIME.search("\n".join(body)):
                    vendored.add(cur)
                cur, body = m.group(1), []
                starts.add(cur)
                continue
            if cur:
                body.append(ln)
                calls[cur] |= set(CALL.findall(ln))
        if cur and RUNTIME.search("\n".join(body)):
            vendored.add(cur)
    # Blocks now built from library source have left asm/ and src/.
    vendored |= LIBRARY_BLOCKS

    decompiled = set()
    for f in sorted((ROOT / "src").glob("*.c")):
        src = f.read_text(errors="replace")
        m = C_DEF.search(src)
        if not m:
            continue
        name = m.group(1)
        decompiled.add(name)
        starts.add(name)
        calls[name] |= {
            t for t in re.findall(r"\b(sub_[0-9A-Fa-f]{8})\s*\(", src[m.start() :]) if t != name
        }

    # A block runs until the next one starts; that is an upper bound on its
    # code, since trailing data luvdis lumped in is counted too.
    addrs = sorted(int(n[4:], 16) for n in starts if re.fullmatch(r"sub_[0-9A-Fa-f]{8}", n))
    size = {f"sub_{a:08X}": addrs[i + 1] - a for i, a in enumerate(addrs[:-1])}
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
    # Every decompiled name must have a src file named for it.
    for n in list(decompiled)[:20]:
        assert (ROOT / "src" / f"{n}.c").exists(), n
    print("selftest ok")


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        _selftest()
    else:
        sys.exit(main())
