#!/usr/bin/env python3
"""Guard-structure variants: flat `a && b && (x = expr) >= 0` vs nested ifs."""
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/guardshape")

GUARDS = [
    ("h1e0", "        if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {", "e = v2 - 0x1C00"),
    ("h1e1", "        if (u > 0 && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {", "e = -0x1C00 - v2"),
    ("h2e0", "        if (u < 0 && v4 <= 0x1C00 && (d1 = (e = v2 - 0x1C00)) >= 0) {", "d1 = (e = v2 - 0x1C00)"),
    ("h2e1", "        if (0 < u && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {", "e = -0x1C00 - v2"),
]


def make_flat_nested(site, line, expr):
    head, tail = line.split("&& ", 1)
    inner = "" if expr.startswith("d1") else expr
    ind = "        "
    body_open = line
    return None


def variants():
    v = {}
    for site, line, expr in GUARDS:
        cond1, cond2, cond3 = "u < 0 && v4 <= 0x1C00", None, None
        # parse the three conditions crudely
        parts = line.strip()[3:-2].split(" && ")
        if len(parts) != 3:
            continue
        a, b, c = parts
        # (a) two-level: if (a && b) { c; if (<c value> >= 0) {
        v[f"{site}_nested2"] = BASE.replace(line, f"        if ({a} && {b}) {{\n            {c};\n            if (({c.split(' = ')[1].rstrip(')')}) >= 0) {{")
        # (b) three-level
        v[f"{site}_nested3"] = BASE.replace(line, f"        if ({a}) {{\n            if ({b}) {{\n                {c};\n                if (({c.split(' = ')[1].rstrip(')')}) >= 0) {{")
    return v


def work(item):
    name, text = item
    if text == BASE:
        return {"name": name, "note": "no-op", "hunks": 99, "sdiff": 99999, "size": 0}
    d = OUT / name
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(text)
    r = filediff.report(str(f), str(d))
    r["name"] = name
    return r


if __name__ == "__main__":
    with ProcessPoolExecutor(max_workers=6) as ex:
        rows = list(ex.map(work, variants().items()))
    for r in sorted(rows, key=lambda r: (r.get("hunks", 99), r.get("sdiff", 99999))):
        print(f"{r['name']:18s} size={str(r.get('size','-')):>5} hunks={str(r.get('hunks','-')):>2} sdiff={str(r.get('sdiff','-')):>5} {r.get('note','')}")