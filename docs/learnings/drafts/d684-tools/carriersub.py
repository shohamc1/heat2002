#!/usr/bin/env python3
"""Carrier-subset removal search.

The pre-carrier draft has two chains (`k3 * d1` in both mirrors) that pick r4 and
so put r4 into the reload scratch set; the current draft's carriers removed that
need.  If any subset of the carriers restores it while keeping the instruction
stream, the two post-loop hunks collapse (size 2006).  This enumerates subsets
of a curated carrier list (all sizes) and reports the best (hunks, sdiff, size).
"""
import itertools
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/carriersub")

# (name, old, new) - "new" removes/reverts the carrier
CARRIERS = [
    ("pa_k0", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    sub_0800D5D4(a1, pa);"),
    ("dz_d0", "            d0 = self->unk08;\n            dz = d0;\n            edgeq = other->unk08;\n            dz -= edgeq;",
              "            dz = self->unk08;\n            dz -= other->unk08;"),
    ("v1h_h1", "        v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);",
               "        v1hold = (v1 = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);"),
    ("v1e_h2", "        e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;",
               "        v1hold = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);"),
    ("h1e2_carrier", "        if (w > 0 && v3 >= -0xF00 && (d1 = (e = -0xF00 - v1)) >= 0) {",
                     "        if (w > 0 && v3 >= -0xF00 && (e = -0xF00 - v1) >= 0) {"),
    ("h1e2_k1d1", """            k1 = e;
            d1 = k1;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);""",
                   """            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (e << 16) / w);"""),
    ("h1e3_d1", "            d1 = k2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)",
                "            if ((u32)(k2 + 0x1C00) <= 0x3800)"),
    ("h1e3_self", "            d0 = gUnk_083FDA2C[(*cc).d].f1; gUnk_083FDA2C[(*cc).d].f1 = d0;\n", ""),
    ("h2e0_carrier", "        if (u < 0 && v4 <= 0x1C00 && (d1 = (e = v2 - 0x1C00)) >= 0) {",
                     "        if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {"),
    ("h2e2_k0", "            k0 = edgeq + v2;\n            if ((u32)(k0 + 0x1C00) <= 0x3800)",
                "            k2 = edgeq + v2;\n            if ((u32)(k2 + 0x1C00) <= 0x3800)"),
    ("h2e3_d1", "            d1 = edgeq + v2;\n            if ((u32)(d1 + 0x1C00) <= 0x3800)",
                "            k2 = edgeq + v2;\n            if ((u32)(k2 + 0x1C00) <= 0x3800)"),
    ("h2e3_arg", "sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90, &flag, -w, (e << 16) / -w);",
                 "sub_0800D64C(cursor, a2, a1, 3, cc, &flag, -w, (e << 16) / -w);"),
    ("h1e1_k3", "            k3 = edgeq + v1;\n            if ((u32)(k3 + 0xF00) <= 0x1E00)",
                "            k2 = edgeq + v1;\n            if ((u32)(k2 + 0xF00) <= 0x1E00)"),
    ("preloop_self", "    a1->unk175 = a1->unk175;\n    k0 = (s32)pa;", "    k0 = (s32)pa;"),
    ("loopend_self", "a1->unk175 = a1->unk175;\nloop_continue:", "loop_continue:"),
    ("w_carrier", "    d1 = (s32)(*cc).c;\n    w = d1;", "    w = (s32)(*cc).c;"),
    ("k3_4", "            k3 = 4;\n", "            dz = 4;\n"),
    ("k2_21e0", "        k2 = gUnk_020021E0;\n        if (k2 == 0 &&", "        if (gUnk_020021E0 == 0 &&"),
    ("dowhile", "            do\n                hit2->unk88 -= d0 >> 14;\n            while (0);",
                "            hit2->unk88 -= d0 >> 14;"),
    ("ccd_k1", "    k1 = gUnk_083FDA2C[ccd].f0;", "    k1 = (&gUnk_083FDA2C[ccd])->f0;"),
    ("glob_g", "    d0 = -gUnk_0202CC90.g;", "    d0 = -(*cc).g;"),
    ("pa4_alias", "        d0 = gUnk_0202CCB0[4];", "        d0 = pa[4];"),
]


def build(keep):
    t = BASE
    for name, old, new in CARRIERS:
        if name in keep:
            continue
        if t.count(old) != 1:
            return None, f"{name}: pattern {t.count(old)}"
        t = t.replace(old, new)
    return t, None


def work(args):
    tag, removed = args
    text, err = build(set(removed))
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    if text is None:
        return {"tag": tag, "note": err, "hunks": 99, "sdiff": 99999, "size": 0}
    f = d / "v.c"
    f.write_text(text)
    try:
        r = filediff.report(str(f), str(d))
    except Exception as e:
        return {"tag": tag, "note": str(e)[:40], "hunks": 99, "sdiff": 99999, "size": 0}
    if "hunks" not in r:
        return {"tag": tag, "note": "compile error", "hunks": 99, "sdiff": 99999, "size": 0}
    r["tag"] = tag
    return r


def main():
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--max-remove", type=int, default=4)
    ap.add_argument("--all-sizes", action="store_true")
    a = ap.parse_args()
    names = [n for n, o, _ in CARRIERS if BASE.count(o) == 1]
    print(f"{len(names)} applicable carriers")
    combos = []
    sizes = range(1, len(names) + 1) if a.all_sizes else range(1, a.max_remove + 1)
    for k in sizes:
        combos += list(itertools.combinations(names, k))
    print(f"{len(combos)} subsets")
    todo = [(f"r{'_'.join(c)}", c) for c in combos]
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:25]:
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>5}  {r['tag']} {r.get('note','')}")


if __name__ == "__main__":
    main()