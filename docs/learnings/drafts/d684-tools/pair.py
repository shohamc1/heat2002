#!/usr/bin/env python3
"""Pair-wise scaffold ablation search for sub_0800D684.

The sixth-pass win (hunks 6 -> 4, sdiff 1059 -> 959) came from reverting *two*
fifth-pass scaffolds together; neither revert won alone.  This script scores
every single edit and every pair from a curated revert list and prints the
ranking.

    python3 pair.py [--out DIR] [-j 8]
"""
import argparse
import itertools
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()

# (name, old, new) -- every `old` must occur exactly once in BASE.
E = [
    ("preloop_selfstore", "    a1->unk175 = a1->unk175;\n    k2 = (s32)pa;", "    k2 = (s32)pa;"),
    ("loopend_selfstore", "a1->unk175 = a1->unk175;\nloop_continue:", "loop_continue:"),
    ("edge3_selfstore", "            gUnk_083FDA2C[(*cc).d].f1 = gUnk_083FDA2C[(*cc).d].f1;\n", ""),
    ("dowhile", """        if (gUnk_0202EEB0 != 0)
            do
                hit2->unk88 -= d0 >> 14;
            while (0);""", """        if (gUnk_0202EEB0 != 0)
            hit2->unk88 -= d0 >> 14;"""),
    ("pa_direct", "    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);", "    sub_0800D5D4(a1, pa);"),
    ("ccd_gone", "    ccd = (*cc).d;\n", ""),
    ("k1_dot", "    k1 = (&gUnk_083FDA2C[ccd])->f0;", "    k1 = gUnk_083FDA2C[ccd].f0;"),
    ("k0_ccd", "    k0 = gUnk_083FDA2C[(*cc).d].f1;", "    k0 = gUnk_083FDA2C[ccd].f1;"),
    ("dz_direct", "            d0 = self->unk08;\n            dz = d0;\n            edgeq = other->unk08;\n            dz -= edgeq;", "            dz = self->unk08;\n            dz -= other->unk08;"),
    ("v1hold_direct1", "        v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);", "        v1hold = (v1 = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);"),
    ("e_route2", "        e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;", "        v1hold = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);"),
    ("k2_21e0", "        k2 = gUnk_020021E0;\n        if (k2 == 0 &&", "        if (gUnk_020021E0 == 0 &&"),
    ("w_direct", "    d0 = (s32)(*cc).c;\n    w = d0;", "    w = (s32)(*cc).c;"),
    ("e1_carrier2", "        if (0 < u && v4 >= -0x1C00 && (d1 = (e = -0x1C00 - v2)) >= 0) {", "        if (0 < u && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {"),
    ("lim3800_decl", "    s32 lim3800;\n", ""),
    ("fraction_decl", "    s32 fraction;\n", ""),
    ("k2_split_h1e1", "            k2 = edgeq + v1;\n            if ((u32)(k2 + 0xF00) <= 0x1E00)", "            edgeq += v1;\n            if ((u32)(edgeq + 0xF00) <= 0x1E00)"),
    ("k2_split_h1e2", "            k2 = edgeq + v2;\n            k1 = e;\n            d1 = k1;\n            if ((u32)(k2 + 0x1C00) <= 0x3800)", "            edgeq += v2;\n            k1 = e;\n            d1 = k1;\n            if ((u32)(edgeq + 0x1C00) <= 0x3800)"),
    ("k2_split_h1e3", "            k2 = edgeq + v2;\n            d1 = k2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)", "            edgeq += v2;\n            d1 = edgeq + 0x1C00;\n            if ((u32)d1 <= 0x3800)"),
    ("k2_split_h2e1", "            k2 = edgeq + v1;\n            if ((u32)(k2 + 0xF00) <= 0x1E00)", "            edgeq += v1;\n            if ((u32)(edgeq + 0xF00) <= 0x1E00)"),
    ("k2_split_h2e2", "            k2 = edgeq + v2;\n            if ((u32)(k2 + 0x1C00) <= 0x3800)\n                sub_0800D64C(cursor", "            edgeq += v2;\n            if ((u32)(edgeq + 0x1C00) <= 0x3800)\n                sub_0800D64C(cursor"),
    ("k2_split_h2e3", "            k2 = edgeq + v2;\n            if ((u32)(k2 + 0x1C00) <= 0x3800)\n                sub_0800D64C(cursor, a2, a1, 3", "            edgeq += v2;\n            if ((u32)(edgeq + 0x1C00) <= 0x3800)\n                sub_0800D64C(cursor, a2, a1, 3"),
    ("unk55_direct", "    k2 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)k2;\n    d1 = k2;", "    d1 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)d1;"),
    ("hit2_split", "    hit2 = (struct Ent *)w;\n    ((struct Ent *)u)->unk48 = ((struct Ent *)u)->unk2C;", "    ((struct Ent *)u)->unk48 = ((struct Ent *)u)->unk2C;\n    hit2 = (struct Ent *)w;"),
    ("u0_direct", "    u0 = (*cc).a;\n    u = (s32)u0;", "    u = (s32)(*cc).a;"),
    ("coswap1", "        am = ", "        am = "),  # placeholder, dropped if not found
]


def build(edits):
    src = BASE
    for name, old, new in edits:
        if src.count(old) != 1:
            return None, f"{name}: pattern count {src.count(old)}"
        src = src.replace(old, new)
    return src, "+".join(n for n, _, _ in edits)


def work(item):
    idx, edits, outdir = item
    src, label = build(edits)
    if src is None:
        return {"idx": idx, "label": label, "note": label, "sdiff": 99999, "hunks": 99, "size": 0}
    d = pathlib.Path(outdir) / f"c{idx}"
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(src)
    rep = filediff.report(str(f), str(d))
    rep["label"] = label
    rep["file"] = str(f)
    return rep


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="/tmp/mylane_v0/pair")
    ap.add_argument("-j", type=int, default=8)
    a = ap.parse_args()
    valid = [e for e in E if BASE.count(e[1]) == 1]
    dropped = [e[0] for e in E if BASE.count(e[1]) != 1]
    if dropped:
        print("dropped (pattern not unique):", dropped)
    combos = [()] + [(e,) for e in valid] + list(itertools.combinations(valid, 2))
    todo = [(i, c, a.out) for i, c in enumerate(combos)]
    print(f"{len(todo)} combos ({len(valid)} singles + {len(combos)-1-len(valid)} pairs)")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["sdiff"], r["hunks"], r["size"]))
    print(f"{'size':>5s} {'hunks':>5s} {'sdiff':>6s}  label")
    for r in rows[:25]:
        print(f"{r['size']:>5} {r['hunks']:>5} {r['sdiff']:>6}  {r['label']}")


if __name__ == "__main__":
    main()