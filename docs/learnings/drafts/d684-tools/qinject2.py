#!/usr/bin/env python3
"""Quantity injection at the eight edge-bound blocks (see qinject.py docstring).

Each edit rewrites a whole `if (bound) call;` statement into
`{ s32 tq = <expr>; if ((u32)tq <= K) call; }`, which adds a local-alloc quantity
to the block (turning the buggy 3-quantity sort into the correct 4-quantity path)
while the copy should be tied away.
"""
import itertools
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/qinj3")

SITES = [
    ("e0h1",
     """            if ((u32)(edgeq + 0xF00) <= 0x1E00)
                sub_0800D64C(a1, a2, cursor, 0, &gUnk_0202CC90, &flag, -u, (e << 16) / -u);""",
     """            {
                s32 tq = edgeq + 0xF00;
                if ((u32)tq <= 0x1E00)
                    sub_0800D64C(a1, a2, cursor, 0, &gUnk_0202CC90, &flag, -u, (e << 16) / -u);
            }"""),
    ("e1h1",
     """            if ((u32)(k3 + 0xF00) <= 0x1E00)
                sub_0800D64C(a1, a2, cursor, 1, cc, &flag, u, (e << 16) / u);""",
     """            {
                s32 tq = k3 + 0xF00;
                if ((u32)tq <= 0x1E00)
                    sub_0800D64C(a1, a2, cursor, 1, cc, &flag, u, (e << 16) / u);
            }"""),
    ("e2h1",
     """            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);""",
     """            {
                s32 tq = k2 + 0x1C00;
                if ((u32)tq <= 0x3800)
                    sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);
            }"""),
    ("e3h1",
     """            if ((u32)d1 <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 3, cc, &flag, -w, (e << 16) / -w);""",
     """            {
                s32 tq = d1;
                if ((u32)tq <= 0x3800)
                    sub_0800D64C(a1, a2, cursor, 3, cc, &flag, -w, (e << 16) / -w);
            }"""),
    ("e0h2",
     """            if ((u32)(edgeq + 0xF00) <= 0x1E00)
                sub_0800D64C(cursor, a2, a1, 0, cc, &flag, -u, (e << 16) / -u);""",
     """            {
                s32 tq = edgeq + 0xF00;
                if ((u32)tq <= 0x1E00)
                    sub_0800D64C(cursor, a2, a1, 0, cc, &flag, -u, (e << 16) / -u);
            }"""),
    ("e1h2",
     """            if ((u32)(edgeq + 0xF00) <= 0x1E00)
                sub_0800D64C(cursor, a2, a1, 1, cc, &flag, u, (e << 16) / u);""",
     """            {
                s32 tq = edgeq + 0xF00;
                if ((u32)tq <= 0x1E00)
                    sub_0800D64C(cursor, a2, a1, 1, cc, &flag, u, (e << 16) / u);
            }"""),
    ("e2h2",
     """            if ((u32)(k0 + 0x1C00) <= 0x3800)
                sub_0800D64C(cursor, a2, a1, 2, cc, &flag, w, (e << 16) / w);""",
     """            {
                s32 tq = k0 + 0x1C00;
                if ((u32)tq <= 0x3800)
                    sub_0800D64C(cursor, a2, a1, 2, cc, &flag, w, (e << 16) / w);
            }"""),
    ("e3h2",
     """            if ((u32)(d1 + 0x1C00) <= 0x3800)
                sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90, &flag, -w, (e << 16) / -w);""",
     """            {
                s32 tq = d1 + 0x1C00;
                if ((u32)tq <= 0x3800)
                    sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90, &flag, -w, (e << 16) / -w);
            }"""),
]


def build(keep):
    text = BASE
    for name, old, new in SITES:
        if name not in keep:
            continue
        if text.count(old) != 1:
            return None, f"{name}: pattern {text.count(old)}"
        text = text.replace(old, new)
    return text, None


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
    print(f"{len(names)}/{len(SITES)} applicable sites:", names)
    combos = [(n,) for n in names] + list(itertools.combinations(names, 2)) + list(itertools.combinations(names, 3))
    todo = [(f"k{'_'.join(c)}", set(c)) for c in combos]
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:20]:
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>5}  {r['tag']} {r.get('note','')}")