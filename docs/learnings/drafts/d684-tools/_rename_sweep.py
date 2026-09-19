#!/usr/bin/env python3
"""Consistent global renamings of the scratch locals (a pure bijection of names).

Renaming swaps which pseudo holds which values without changing any instruction.
Allocnos are ordered by number (creation order) with ties broken by number, so a
swap can change the assignment even when the code is identical.
"""
import pathlib
import re
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/rename")


def rename(text, a, b):
    # token-exact swap of identifiers a and b
    def sub(m):
        return b if m.group(0) == a else a
    pat = re.compile(rf"\b(?:{re.escape(a)}|{re.escape(b)})\b")
    return pat.sub(sub, text)


PAIRS = [("d0", "d1"), ("k0", "k1"), ("k2", "k3"), ("d0", "k0"), ("d1", "k1"),
         ("k0", "k2"), ("k1", "k3"), ("edgeq", "v1hold"), ("k2", "d1"), ("d0", "k2")]


def work(pair):
    a, b = pair
    name = f"{a}_{b}"
    d = OUT / name
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(rename(BASE, a, b))
    r = filediff.report(str(f), str(d))
    r["name"] = name
    return r


if __name__ == "__main__":
    with ProcessPoolExecutor(max_workers=6) as ex:
        rows = list(ex.map(work, PAIRS))
    for r in sorted(rows, key=lambda r: (r.get("hunks", 99), r.get("sdiff", 99999))):
        print(f"{r['name']:14s} size={str(r.get('size','-')):>5} hunks={str(r.get('hunks','-')):>2} sdiff={str(r.get('sdiff','-')):>5} {r.get('note','')}")