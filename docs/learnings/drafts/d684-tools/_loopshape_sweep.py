#!/usr/bin/env python3
"""Loop-shape variants: `goto loop_continue` vs `continue` vs restructured loop."""
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/loopshape")


def variants():
    v = {}
    # (a) continue instead of goto
    t = BASE.replace("goto loop_continue;", "continue;")
    t = t.replace("a1->unk175 = a1->unk175;\nloop_continue:;", "a1->unk175 = a1->unk175;")
    t = t.replace("a1->unk175 = a1->unk175;\nloop_continue:", "a1->unk175 = a1->unk175;")
    v["continue"] = t
    # (b) goto but label at the top of the body
    t = BASE.replace("loop_continue:;", "loop_continue:;")
    v["nolabel_selfstore"] = BASE.replace("a1->unk175 = a1->unk175;\nloop_continue:;", "loop_continue:;")
    # (c) explicit increment inside a while loop is out of scope; try removing the comma-increment
    t = BASE.replace(
        "for (i = 0; i != count; i++, cursor = (struct Ent *)((u8 *)cursor + 0x190)) {",
        "for (i = 0; i != count; i++) {\n        cursor = (struct Ent *)((u8 *)cursor + 0x190);")
    v["incr_in_body"] = t
    # (d) the loop bounds check as `< count`
    t = BASE.replace("for (i = 0; i != count;", "for (i = 0; i < count;")
    v["lt_count"] = t
    return v


def work(item):
    name, text = item
    d = OUT / name
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(text)
    r = filediff.report(str(f), str(d))
    r["name"] = name
    return r


if __name__ == "__main__":
    with ProcessPoolExecutor(max_workers=4) as ex:
        rows = list(ex.map(work, variants().items()))
    for r in sorted(rows, key=lambda r: (r.get("hunks", 99), r.get("sdiff", 99999))):
        print(f"{r['name']:20s} size={str(r.get('size','-')):>5} hunks={str(r.get('hunks','-')):>2} sdiff={str(r.get('sdiff','-')):>5}")