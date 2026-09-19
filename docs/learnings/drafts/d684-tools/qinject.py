#!/usr/bin/env python3
"""Quantity injection at the three-quantity bound blocks.

`block_alloc`'s hand-rolled 1-3 quantity sort is buggy; four or more take the
correct qsort path.  Wrapping the comparison operand in a block-scoped copy adds
a quantity (and the copy itself should be tied away by local-alloc), so this
sweep tries that at every edge-bound site, singly and in combinations.
"""
import itertools
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/qinj2")

# (name, old, new) - each old must occur exactly once
SITES = [
    ("e0h1", "            if ((u32)(edgeq + 0xF00) <= 0x1E00)\n                sub_0800D64C(a1, a2, cursor, 0,",
     "            { s32 tq = edgeq + 0xF00; if ((u32)tq <= 0x1E00)\n                sub_0800D64C(a1, a2, cursor, 0,"),
    ("e1h1", "            if ((u32)(k3 + 0xF00) <= 0x1E00)",
     "            { s32 tq = k3 + 0xF00; if ((u32)tq <= 0x1E00)"),
    ("e0h2", "            if ((u32)(edgeq + 0xF00) <= 0x1E00)\n                sub_0800D64C(cursor, a2, a1, 0,",
     "            { s32 tq = edgeq + 0xF00; if ((u32)tq <= 0x1E00)\n                sub_0800D64C(cursor, a2, a1, 0,"),
    ("e1h2", "            if ((u32)(edgeq + 0xF00) <= 0x1E00)\n                sub_0800D64C(cursor, a2, a1, 1,",
     "            { s32 tq = edgeq + 0xF00; if ((u32)tq <= 0x1E00)\n                sub_0800D64C(cursor, a2, a1, 1,"),
    ("e2h1", "            if ((u32)(k2 + 0x1C00) <= 0x3800)\n                sub_0800D64C(a1, a2, cursor, 2,",
     "            { s32 tq = k2 + 0x1C00; if ((u32)tq <= 0x3800)\n                sub_0800D64C(a1, a2, cursor, 2,"),
    ("e2h2", "            if ((u32)(k0 + 0x1C00) <= 0x3800)\n                sub_0800D64C(cursor, a2, a1, 2,",
     "            { s32 tq = k0 + 0x1C00; if ((u32)tq <= 0x3800)\n                sub_0800D64C(cursor, a2, a1, 2,"),
    ("e3h1", "            if ((u32)(k2 + 0x1C00) <= 0x3800)\n                sub_0800D64C(a1, a2, cursor, 3,",
     "            { s32 tq = k2 + 0x1C00; if ((u32)tq <= 0x3800)\n                sub_0800D64C(a1, a2, cursor, 3,"),
    ("e3h2", "            if ((u32)(d1 + 0x1C00) <= 0x3800)\n                sub_0800D64C(cursor, a2, a1, 3,",
     "            { s32 tq = d1 + 0x1C00; if ((u32)tq <= 0x3800)\n                sub_0800D64C(cursor, a2, a1, 3,"),
]


def build(keep):
    text = BASE
    used = []
    for name, old, new in SITES:
        if name not in keep:
            continue
        if text.count(old) != 1:
            return None, f"{name}: pattern {text.count(old)}"
        text = text.replace(old, new)
        used.append(name)
    return text, "+".join(used)


def work(args):
    tag, keep = args
    text, err = build(keep)
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    if text is None or text == BASE:
        return {"tag": tag, "note": err or "no-op", "sdiff": 99999, "hunks": 99, "size": 0}
    f = d / "v.c"
    f.write_text(text)
    try:
        r = filediff.report(str(f), str(d))
    except Exception as e:
        return {"tag": tag, "note": str(e)[:40], "sdiff": 99999, "hunks": 99, "size": 0}
    if "hunks" not in r:
        return {"tag": tag, "note": "compile error", "sdiff": 99999, "hunks": 99, "size": 0}
    r["tag"] = tag
    return r


if __name__ == "__main__":
    names = [n for n, o, _ in SITES if BASE.count(o) == 1]
    print("applicable sites:", names)
    combos = [(n,) for n in names]
    combos += list(itertools.combinations(names, 2))
    combos += list(itertools.combinations(names, 3))
    todo = [(f"k{'_'.join(c)}", set(c)) for c in combos]
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:20]:
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>5}  {r['tag']} {r.get('note','')}")