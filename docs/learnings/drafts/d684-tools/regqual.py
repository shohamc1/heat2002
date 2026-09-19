#!/usr/bin/env python3
"""`register` qualifier sweep on the hot locals (untested; changes local-alloc's
register preferences without changing the RTL shape)."""
import itertools
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/regqual")

VARS = [
    ("e", "    s32 e;\n"),
    ("edgeq", "    s32 edgeq;\n"),
    ("d0", "    s32 d0;\n"),
    ("d1", "    s32 d1;\n"),
    ("k0", "    s32 k0, k1, k2, k3;\n"),
    ("v1hold", "    s32 v1hold;\n"),
    ("u", "    s32 u;\n"),
    ("w", "    s32 w;\n"),
    ("v", "    s32 v[4];\n"),
    ("pa", "    s32 *pa, *pb;\n"),
    ("cc", "    struct Unk0802CC90 *cc;\n"),
]


def apply(text, name, decl):
    new = decl.replace("    ", "    register ", 1)
    if name == "k0":
        new = "    register s32 k0, k1, k2, k3;\n"
    if name == "pa":
        new = "    s32 *register pa, *pb;\n"
    return text.replace(decl, new)


def build(keep):
    t = BASE
    for name, decl in VARS:
        if name in keep:
            if t.count(decl) != 1:
                return None
            t = apply(t, name, decl)
    return t


def work(args):
    tag, keep = args
    text = build(keep)
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    if text is None or text == BASE:
        return {"tag": tag, "note": "pattern", "sdiff": 99999, "hunks": 99, "size": 0}
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
    names = [n for n, d in VARS if BASE.count(d) == 1]
    print("applicable:", names)
    combos = [(n,) for n in names] + list(itertools.combinations(names, 2))
    todo = [(f"r{'_'.join(c)}", set(c)) for c in combos]
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:15]:
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>5}  {r['tag']} {r.get('note','')}")