#!/usr/bin/env python3
"""Single-edit ablation sweep: revert one documented scaffold at a time and score.

Used from the repo root:
    python3 /tmp/ablate.py
"""
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/abl")

E = [
    ("preloop_selfstore", "    a1->unk175 = a1->unk175;\n    k2 = (s32)pa;", "    k2 = (s32)pa;"),
    ("loopend_selfstore", "a1->unk175 = a1->unk175;\nloop_continue:", "loop_continue:"),
    ("dowhile", """        if (gUnk_0202EEB0 != 0)
            do
                hit2->unk88 -= d0 >> 14;
            while (0);""", """        if (gUnk_0202EEB0 != 0)
            hit2->unk88 -= d0 >> 14;"""),
    ("pa_direct", "    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);", "    sub_0800D5D4(a1, pa);"),
    ("ccd_gone", "    ccd = (*cc).d;\n", ""),
    ("k1_dot", "    k1 = (&gUnk_083FDA2C[ccd])->f0;", "    k1 = gUnk_083FDA2C[ccd].f0;"),
    ("dz_direct", "            d0 = self->unk08;\n            dz = d0;\n            edgeq = other->unk08;\n            dz -= edgeq;", "            dz = self->unk08;\n            dz -= other->unk08;"),
    ("v1hold_direct1", "        v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);", "        v1hold = (v1 = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);"),
    ("e_route2", "        e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;", "        v1hold = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);"),
    ("k2_21e0", "        k2 = gUnk_020021E0;\n        if (k2 == 0 &&", "        if (gUnk_020021E0 == 0 &&"),
    ("w_direct", "    d0 = (s32)(*cc).c;\n    w = d0;", "    w = (s32)(*cc).c;"),
    ("e1_carrier2", "        if (0 < u && v4 >= -0x1C00 && (d1 = (e = -0x1C00 - v2)) >= 0) {", "        if (0 < u && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {"),
    ("lim3800_decl", "    s32 lim3800;\n", ""),
    ("fraction_decl", "    s32 fraction;\n", ""),
    ("edgeq_split_1", "            k2 = edgeq + v2;\n            if ((u32)(k2 + 0x1C00) <= 0x3800)\n                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);", "            edgeq += v2;\n            if ((u32)(edgeq + 0x1C00) <= 0x3800)\n                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);"),
]


def work(item):
    name, old, new = item
    n = BASE.count(old)
    if n != 1:
        return {"name": name, "note": f"pattern count {n}"}
    d = OUT / name
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(BASE.replace(old, new))
    rep = filediff.report(str(f), str(d))
    rep["name"] = name
    return rep


if __name__ == "__main__":
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(work, E))
    rows.sort(key=lambda r: (r.get("sdiff", 99999), r.get("hunks", 99)))
    print(f"{'variant':22s} {'size':>5s} {'hunks':>5s} {'sdiff':>6s}  note")
    for r in rows:
        print(f"{r['name']:22s} {str(r.get('size','-')):>5} {str(r.get('hunks','-')):>5} {str(r.get('sdiff','-')):>6}  {r.get('note','')}")
