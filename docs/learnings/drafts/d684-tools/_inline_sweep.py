#!/usr/bin/env python3
"""Local-removal / expression-inlining sweep: drop a named local and inline its value."""
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/inline")
E = [
    ("drop_a1_175", """    a1_175 = a1->unk175;
    base = (struct Ent *)gUnk_0202A550;
    if (a1_175 != 0) {""", """    base = (struct Ent *)gUnk_0202A550;
    if (a1->unk175 != 0) {"""),
    ("drop_base1", """    base = (struct Ent *)gUnk_0202A550;
    if (a1_175 != 0) {""", """    if (a1_175 != 0) {"""),
    ("drop_base2", """    cursor = base;""", """    cursor = (struct Ent *)gUnk_0202A550;"""),
    ("drop_base3", """        if (a1 == base)""", """        if (a1 == (struct Ent *)gUnk_0202A550)"""),
    ("drop_u0", """    u0 = (*cc).a;
    u = (s32)u0;""", """    u = (s32)(*cc).a;"""),
    ("drop_u0b", """    u0 = (*cc).a;
    u = (s32)u0;""", """    u0 = (*cc).a;
    u = (s32)u0;"""),
    ("drop_ccd", """    ccd = (*cc).d;""", """    ccd = (*cc).d;"""),
    ("drop_self_other", """            self = a1;
            dx = self->unk00;
            other = cursor;
            dx -= other->unk00;""", """            self = a1;
            dx = a1->unk00;
            other = cursor;
            dx -= cursor->unk00;"""),
    ("drop_a2_use", """                sub_0800D64C(a1, a2, cursor, 0, &gUnk_0202CC90, &flag, -u, (e << 16) / -u);""",
                   """                sub_0800D64C(a1, a2, cursor, 0, cc, &flag, -u, (e << 16) / -u);"""),
    ("merge_d0d1", """        d0 = pa[4];
        d1 = pa[5];
        d0 -= pb[4];
        d1 -= pb[5];""", """        d0 = gUnk_0202CCB0[4];
        d1 = pa[5];
        d0 -= pb[4];
        d1 -= pb[5];"""),
    ("merge_v1hold", """        v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);""",
                      """        v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8;
        v1 = v1hold;"""),
    ("merge_edgeq", """            edgeq = w * e / u;
            edgeq += v1hold;""", """            edgeq = w * e / u + v1hold;"""),
    ("drop_i", """    for (i = 0; i != count; i++, cursor = (struct Ent *)((u8 *)cursor + 0x190)) {""",
               """    for (i = 0; i != count; i++, cursor = (struct Ent *)((u8 *)cursor + 0x190)) {"""),
    ("flag_direct", """    flag = 0;
    cursor = base;""", """    flag = 0;
    cursor = base;"""),
    ("count_direct", """    count = gUnk_02002090;
    if (gUnk_020020DC != 0)
        count = gUnk_020020AC;""", """    count = gUnk_02002090;
    if (gUnk_020020DC != 0)
        count = gUnk_020020AC;"""),
]


def work(item):
    name, old, new = item
    if old == new:
        return {"name": name, "note": "no-op"}
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
        print(f"{r['name']:16s} size={str(r.get('size','-')):>5} hunks={str(r.get('hunks','-')):>2} sdiff={str(r.get('sdiff','-')):>5} {r.get('note','')}")