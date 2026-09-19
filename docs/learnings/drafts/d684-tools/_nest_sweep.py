#!/usr/bin/env python3
"""Nesting/carrier variants for the second mirror's edge-0 guard."""
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/nest")
Q = "        if (u < 0 && v4 <= 0x1C00 && (d1 = (e = v2 - 0x1C00)) >= 0) {"
E = [
    ("h2e0_swap_nest", Q, "        if (u < 0 && v4 <= 0x1C00 && (e = (d1 = v2 - 0x1C00)) >= 0) {"),
    ("h2e0_k1_nest", Q, "        if (u < 0 && v4 <= 0x1C00 && (k1 = (e = v2 - 0x1C00)) >= 0) {"),
    ("h2e0_d0_nest", Q, "        if (u < 0 && v4 <= 0x1C00 && (d0 = (e = v2 - 0x1C00)) >= 0) {"),
    ("h2e0_k3_nest", Q, "        if (u < 0 && v4 <= 0x1C00 && (k3 = (e = v2 - 0x1C00)) >= 0) {"),
    ("h2e0_edgeq", Q, "        if (u < 0 && v4 <= 0x1C00 && (edgeq = (e = v2 - 0x1C00)) >= 0) {"),
    ("h2e0_v4", Q, "        if (u < 0 && v4 <= 0x1C00 && (v4 = (e = v2 - 0x1C00)) >= 0) {"),
    ("h2e0_u", Q, "        if (u < 0 && v4 <= 0x1C00 && (u = (e = v2 - 0x1C00)) >= 0) {"),
    ("h2e0_v1hold", Q, "        if (u < 0 && v4 <= 0x1C00 && (v1hold = (e = v2 - 0x1C00)) >= 0) {"),
    ("h1e2_swap_nest", "        if (w > 0 && v3 >= -0xF00 && (d1 = (e = -0xF00 - v1)) >= 0) {",
     "        if (w > 0 && v3 >= -0xF00 && (e = (d1 = -0xF00 - v1)) >= 0) {"),
]


def work(item):
    name, old, new = item
    if BASE.count(old) != 1:
        return {"name": name, "note": f"pattern={BASE.count(old)}"}
    d = OUT / name
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(BASE.replace(old, new))
    r = filediff.report(str(f), str(d))
    r["name"] = name
    return r


if __name__ == "__main__":
    with ProcessPoolExecutor(max_workers=6) as ex:
        rows = list(ex.map(work, E))
    for r in sorted(rows, key=lambda r: (r.get("hunks", 99), r.get("sdiff", 99999))):
        print(f"{r['name']:18s} size={str(r.get('size','-')):>5} hunks={str(r.get('hunks','-')):>2} sdiff={str(r.get('sdiff','-')):>5} {r.get('note','')}")