#!/usr/bin/env python3
"""Exhaustive pair sweep over a large text-anchored lever library.

Every lever is a (name, old, new) with a unique `old` in the base.  Pairs whose
`old` strings overlap textually are skipped.  Workers apply the two edits to the
base text (transported as small strings) and score with filediff.

    python3 bigpairs.py [-j 8] [--base FILE] [--out DIR] [--max-levers 200]
"""
import argparse
import itertools
import json
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

import os

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = pathlib.Path(os.environ.get("BIGPAIRS_BASE", str(REPO / "src/sub_0800D684.c"))).read_text()


def lever_library(base):
    L = []

    def add(name, old, new):
        if base.count(old) == 1 and old != new:
            L.append((name, old, new))

    # --- per-occurrence alias respellings (the class that produced the last win)
    alias_pairs = [
        ("d0 = pa[4];\n        d1 = pa[5];", "d0 = gUnk_0202CCB0[4];\n        d1 = pa[5];"),
        ("d0 = pb[4];\n        d1 = pb[5];", "d0 = gUnk_0202CD30[4];\n        d1 = pb[5];"),
        ("d0 = pa[6];\n        d1 = pa[7];", "d0 = gUnk_0202CCB0[6];\n        d1 = pa[7];"),
        ("d0 = pb[6];\n        d1 = pb[7];", "d0 = gUnk_0202CD30[6];\n        d1 = pb[7];"),
        ("v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);", "v1 = (v1hold = ((k1 = gUnk_0202CD30[1]) * d0 - (k0 = pb[0]) * d1) >> 8);"),
        ("v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);", "v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = gUnk_0202CD30[0]) * d1) >> 8);"),
        ("v3 = ((k3 = pb[3]) * d0 - (k2 = pb[2]) * d1) >> 8;", "v3 = ((k3 = gUnk_0202CD30[3]) * d0 - (k2 = pb[2]) * d1) >> 8;"),
        ("v3 = ((k3 = pb[3]) * d0 - (k2 = pb[2]) * d1) >> 8;", "v3 = ((k3 = pb[3]) * d0 - (k2 = gUnk_0202CD30[2]) * d1) >> 8;"),
        ("v1 = (v1hold = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);", "v1 = (v1hold = ((k1 = gUnk_0202CCB0[1]) * d0 - (k0 = pa[0]) * d1) >> 8);"),
        ("v1 = (v1hold = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);", "v1 = (v1hold = ((k1 = pa[1]) * d0 - (k0 = gUnk_0202CCB0[0]) * d1) >> 8);"),
        ("v3 = ((k3 = pa[3]) * d0 - (k2 = gUnk_0202CCB0[2]) * d1) >> 8;", "v3 = ((k3 = gUnk_0202CCB0[3]) * d0 - (k2 = gUnk_0202CCB0[2]) * d1) >> 8;"),
    ]
    for i, (o, n) in enumerate(alias_pairs):
        add(f"alias{i}", o, n)
    L.append(("aliasH1e1", "e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;",
              "e = (v1 = ((k1 = gUnk_0202CCB0[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;"))
    # --- call-argument mixes
    for i, (o, n) in enumerate([
        ("sub_0800D64C(a1, a2, cursor, 0, &gUnk_0202CC90,", "sub_0800D64C(a1, a2, cursor, 0, cc,"),
        ("sub_0800D64C(a1, a2, cursor, 1, cc,", "sub_0800D64C(a1, a2, cursor, 1, &gUnk_0202CC90,"),
        ("sub_0800D64C(a1, a2, cursor, 2, cc,", "sub_0800D64C(a1, a2, cursor, 2, &gUnk_0202CC90,"),
        ("sub_0800D64C(a1, a2, cursor, 3, cc,", "sub_0800D64C(a1, a2, cursor, 3, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 0, cc,", "sub_0800D64C(cursor, a2, a1, 0, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 1, cc,", "sub_0800D64C(cursor, a2, a1, 1, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 2, cc,", "sub_0800D64C(cursor, a2, a1, 2, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90,", "sub_0800D64C(cursor, a2, a1, 3, cc,"),
    ]):
        add(f"arg{i}", o, n)
    # --- guard carriers / removals
    guards = [
        ("h1e0", "        if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {", "e = v2 - 0x1C00"),
        ("h1e1", "        if (u > 0 && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {", "e = -0x1C00 - v2"),
        ("h1e3", "        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {", "e = v1 - 0xF00"),
        ("h2e0", "        if (u < 0 && v4 <= 0x1C00 && (d1 = (e = v2 - 0x1C00)) >= 0) {", "e = v2 - 0x1C00"),
        ("h2e1", "        if (0 < u && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {", "e = -0x1C00 - v2"),
        ("h2e2", "        if (w > 0 && v3 >= -0xF00 && (e = -0xF00 - v1) >= 0) {", "e = -0xF00 - v1"),
        ("h2e3", "        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {", "e = v1 - 0xF00"),
    ]
    for site, line, expr in guards:
        for x in ("k0", "k1", "k2", "k3", "d0", "d1", "edgeq", "v1hold", "lim3800"):
            add(f"{site}_{x}", line, line.replace(f"(e = {expr})", f"({x} = (e = {expr}))"))
        add(f"{site}_none", line, line.replace(f"(e = {expr})", f"({expr.replace(chr(61), chr(61))})"))
    # --- bound carriers
    for site, old, tmpl in [
        ("h1e1b", "            k2 = edgeq + v1;\n            if ((u32)(k2 + 0xF00) <= 0x1E00)", "            {K} = edgeq + v1;\n            if ((u32)({{K}} + 0xF00) <= 0x1E00)"),
        ("h1e3b", "            d1 = k2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)", "            {K} = edgeq + v2;\n            if ((u32)({{K}} + 0x1C00) <= 0x3800)"),
        ("h2e1b", "            k2 = edgeq + v1;\n            if ((u32)(k2 + 0xF00) <= 0x1E00)", "            {K} = edgeq + v1;\n            if ((u32)({{K}} + 0xF00) <= 0x1E00)"),
        ("h2e2b", "            k0 = edgeq + v2;\n            if ((u32)(k0 + 0x1C00) <= 0x3800)", "            {K} = edgeq + v2;\n            if ((u32)({{K}} + 0x1C00) <= 0x3800)"),
        ("h2e3b", "            d1 = edgeq + v2;\n            if ((u32)(d1 + 0x1C00) <= 0x3800)", "            {K} = edgeq + v2;\n            if ((u32)({{K}} + 0x1C00) <= 0x3800)"),
    ]:
        for k in ("k0", "k1", "k2", "k3", "d0", "d1", "edgeq"):
            add(f"{site}_{k}", old, tmpl.replace("{K}", k).replace("{K}", k))
    # --- post-loop spellings
    for name, o, n in [
        ("globg", "    d0 = -gUnk_0202CC90.g;", "    d0 = -(*cc).g;"),
        ("dotk1", "    k1 = gUnk_083FDA2C[ccd].f0;", "    k1 = (&gUnk_083FDA2C[ccd])->f0;"),
        ("wcar_d0", "    d1 = (s32)(*cc).c;\n    w = d1;", "    d0 = (s32)(*cc).c;\n    w = d0;"),
        ("wcar_dir", "    d1 = (s32)(*cc).c;\n    w = d1;", "    w = (s32)(*cc).c;"),
        ("k3_4", "            k3 = 4;\n", "            dz = 4;\n"),
        ("unk55_d1", "    k2 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)k2;\n    d1 = k2;",
                     "    d1 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)d1;"),
        ("pre_self", "    a1->unk175 = a1->unk175;\n", ""),
        ("loop_self", "a1->unk175 = a1->unk175;\nloop_continue:", "loop_continue:"),
        ("dowhile", "            do\n                hit2->unk88 -= d0 >> 14;\n            while (0);", "            hit2->unk88 -= d0 >> 14;"),
        ("pa_dir", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    sub_0800D5D4(a1, pa);"),
        ("pa_k2", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);"),
        ("dz_dir", "            d0 = self->unk08;\n            dz = d0;\n            edgeq = other->unk08;\n            dz -= edgeq;",
                   "            dz = self->unk08;\n            dz -= other->unk08;"),
        ("v1e_off", "        e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;",
                    "        v1hold = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);"),
        ("cc_glob_d", "    ccd = (*cc).d;", "    ccd = gUnk_0202CC90.d;"),
        ("k0_ccd", "    k0 = gUnk_083FDA2C[(*cc).d].f1;", "    k0 = gUnk_083FDA2C[ccd].f1;"),
        ("h1e3_b", "            d1 = k2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)", "            d1 = edgeq + v2;\n            if ((u32)(d1 + 0x1C00) <= 0x3800)"),
    ]:
        add(name, o, n)
    return L


def work(args):
    i, j, edits, outdir = args
    text = BASE
    for _n, o, n in edits:
        if text.count(o) != 1:
            return {"i": i, "j": j, "sdiff": 99999, "hunks": 99, "size": 0}
        text = text.replace(o, n)
    d = pathlib.Path(outdir) / f"p{i}_{j}"
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(text)
    try:
        r = filediff.report(str(f), str(d))
    except Exception:
        return {"i": i, "j": j, "sdiff": 99999, "hunks": 99, "size": 0}
    if "hunks" not in r:
        return {"i": i, "j": j, "sdiff": 99999, "hunks": 99, "size": 0}
    return {"i": i, "j": j, "sdiff": r["sdiff"], "hunks": r["hunks"], "size": r["size"], "match": r["match"]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", default=str(REPO / "src/sub_0800D684.c"))
    ap.add_argument("--out", default="/tmp/mylane_v0/bigpairs")
    ap.add_argument("-j", type=int, default=8)
    a = ap.parse_args()
    L = lever_library(BASE)
    print(f"{len(L)} levers")
    base_rep = filediff.report(a.base, str(pathlib.Path(a.out) / "base"))
    print("base:", base_rep["hunks"], base_rep["sdiff"], base_rep["size"])
    pairs = []
    for i, j in itertools.combinations(range(len(L)), 2):
        if L[i][1] in L[j][1] or L[j][1] in L[i][1]:
            continue
        pairs.append((i, j))
    print(f"{len(pairs)} pairs")
    todo = [(i, j, (L[i], L[j]), a.out) for i, j in pairs]
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    best = (base_rep["hunks"], base_rep["sdiff"], base_rep["size"])
    print(f"baseline {best}")
    for r in rows[:25]:
        if (r["hunks"], r["sdiff"], r["size"]) < best:
            print(f"  IMPROVE {r['size']} {r['hunks']} {r['sdiff']}  {L[r['i']][0]} + {L[r['j']][0]}")
        else:
            print(f"  {r['size']} {r['hunks']} {r['sdiff']}  {L[r['i']][0]} + {L[r['j']][0]}")
    with open(pathlib.Path(a.out) / "pairs.jsonl", "w") as fh:
        for r in rows:
            fh.write(json.dumps({"i": r["i"], "j": r["j"], "name": f"{L[r['i']][0]}+{L[r['j']][0]}",
                                 "size": r["size"], "hunks": r["hunks"], "sdiff": r["sdiff"]}) + "\n")


if __name__ == "__main__":
    main()