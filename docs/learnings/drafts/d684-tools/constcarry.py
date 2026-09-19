#!/usr/bin/env python3
"""Constant-valued local carriers (the `parked.md` lever).

`parked.md` records that declaring a local initialised to a constant and using it
where the C says the literal makes the quantity claim a register during
local-alloc; constant propagation then folds it and deletes the loads, but the
*allocation* it produced survives.  This sweep respells one constant occurrence
at a time as such a local, for every constant-bearing site in the function,
trying several declaration positions and types.

    python3 constcarry.py --site all|NAME [-j 8] [--pos end|head|beforeloop]
"""
import argparse
import pathlib
import re
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/constcarry")

# (name, literal text as it appears, local type, declaration position)
SITES = [
    # (name, constant token to replace, carrier type, declaration position)
    ("c1C00", "0x1C00", "u16", "end"),
    ("cF00", "0xF00", "u16", "end"),
    ("c3800", "0x3800", "u16", "end"),
    ("c1E00", "0x1E00", "u16", "end"),
    ("c6400", "0x6400", "u16", "end"),
    ("c190", "0x190", "u16", "end"),
    ("c200000", "0x200000", "s32", "head"),
    ("c1000", "1000", "u16", "end"),
    ("c40000", "40000", "u16", "end"),
    ("c32", "0x32", "u8", "end"),
    ("c10", "0x10", "u8", "end"),
    ("c400", "0x400", "u16", "end"),
    ("cmagic", "0xC28F5C29", "s32", "end"),
    ("c40", "0x40", "u8", "end"),
    ("c18F", "0x18F", "u16", "end"),
    ("c175", "0x175", "u8", "end"),
    ("c7D", "0x7D", "u8", "end"),
    ("cE8", "0xE8", "u8", "end"),
    ("c34", "0x34", "u8", "end"),
    ("cmod3", "3", "u8", "end"),
    ("cs3", "3", "u8", "end"),
    ("cshift8", "8", "u8", "end"),
    ("cshift12", "12", "u8", "end"),
    ("cshift14", "14", "u8", "end"),
    ("cshift4", "4", "u8", "end"),
    ("cshift16", "16", "u8", "end"),
    ("cneg6", "6", "u8", "end"),
]


def decl_snippet(name, lit, ty, pos):
    if pos == "head":
        anchor = "    u8 flag;\n"
        return anchor + f"    {ty} {name} = {lit};\n", anchor
    if pos == "beforeloop":
        anchor = "    count = gUnk_02002090;\n"
        return anchor + f"    {ty} {name} = {lit};\n", anchor
    anchor = "    u8 ccd;\n"
    return anchor + f"    {ty} {name} = {lit};\n", anchor


def make(name, lit, ty, pos, occ):
    # declaration
    dec, anchor = decl_snippet(name, lit, ty, pos)
    if BASE.count(anchor) != 1:
        return None, f"anchor {anchor!r} count {BASE.count(anchor)}"
    text = BASE.replace(anchor, dec)
    # replace the occ-th occurrence of the literal
    idx = -1
    start = 0
    for k in range(occ + 1):
        idx = BASE.find(lit, start)
        if idx < 0:
            return None, f"literal {lit!r} occurrence {occ} missing"
        start = idx + 1
    # positions shift by the declaration length only if the decl is before the site
    off = len(dec) - len(anchor)
    if BASE.index(anchor) > idx:
        off = 0
    tgt = idx + off
    text = text[:tgt] + name + text[tgt + len(lit):]
    return text, None


def work(args):
    tag, params = args
    name, lit, ty, pos, occ = params
    text, err = make(name, lit, ty, pos, occ)
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    if text is None:
        return {"tag": tag, "note": err, "sdiff": 99999, "hunks": 99, "size": 0}
    f = d / "v.c"
    f.write_text(text)
    try:
        r = filediff.report(str(f), str(d))
    except Exception as ex:
        return {"tag": tag, "note": str(ex)[:40], "sdiff": 99999, "hunks": 99, "size": 0}
    if "hunks" not in r:
        return {"tag": tag, "note": "compile error", "sdiff": 99999, "hunks": 99, "size": 0}
    r["tag"] = tag
    return r


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--occ", type=int, default=-1, help="-1: all occurrences of each literal")
    a = ap.parse_args()
    todo = []
    for name, lit, ty, pos in SITES:
        n = BASE.count(lit)
        occs = range(n) if a.occ < 0 else [a.occ]
        for occ in occs:
            todo.append((f"{name}_{occ}", (f"c_{name}_{occ}", lit, ty, pos, occ)))
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:30]:
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>5}  {r['tag']} {r.get('note','')}")


if __name__ == "__main__":
    main()