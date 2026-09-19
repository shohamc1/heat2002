#!/usr/bin/env python3
"""Pair sweep over the union of every lever that has been tried in isolation.

Each entry is (name, old_text, new_text) applied to the current baseline.  Only
variants with size 2006, hunks 0 and sdiff < 335 count.

    python3 unionpairs.py [-j 8] [--triples TOPN]
"""
import argparse
import itertools
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402
import filediff as F  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/unionpairs")

LEVERS = [
    ("dz_d0", "            d0 = self->unk08;\n            dz = d0;\n            edgeq = other->unk08;\n            dz -= edgeq;",
              "            dz = self->unk08;\n            edgeq = other->unk08;\n            dz -= edgeq;"),
    ("v55k2", "    v55 = *(u8 *)k2;\n    d1 = k2;\n", "    v55 = *(u8 *)k2;\n"),
    ("k3_dz", "            k3 = 4;\n", "            dz = 4;\n"),
    ("k1e", "            k1 = e;\n            d1 = k1;\n", "            d1 = e;\n"),
    ("k2e3_inplace", "            k2 = edgeq + v2;\n            d1 = k2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)",
                     "            d1 = edgeq + v2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)"),
    ("k3inplace", "            k3 = edgeq + v1;\n            if ((u32)(k3 + 0xF00) <= 0x1E00)",
                  "            edgeq += v1;\n            if ((u32)(edgeq + 0xF00) <= 0x1E00)"),
    ("k0e2", "            k0 = edgeq + v2;\n            if ((u32)(k0 + 0x1C00) <= 0x3800)",
             "            edgeq += v2;\n            if ((u32)(edgeq + 0x1C00) <= 0x3800)"),
    ("d1e3", "            d1 = edgeq + v2;\n            if ((u32)(d1 + 0x1C00) <= 0x3800)",
             "            edgeq += v2;\n            if ((u32)(edgeq + 0x1C00) <= 0x3800)"),
    ("v1h2", "        e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;",
             "        v1hold = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);"),
    ("k0pa", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    sub_0800D5D4(a1, pa);"),
    ("preloop_self", "    a1->unk175 = a1->unk175;\n    k0 = (s32)pa;", "    k0 = (s32)pa;"),
    ("loopend_self", "a1->unk175 = a1->unk175;\nloop_continue:", "loop_continue:"),
    ("dowhile", "            do\n                hit2->unk88 -= d0 >> 14;\n            while (0);",
                "            hit2->unk88 -= d0 >> 14;"),
    ("k2_21e0", "        k2 = gUnk_020021E0;\n        if (k2 == 0 &&", "        if (gUnk_020021E0 == 0 &&"),
    ("pa4_alias", "        d0 = gUnk_0202CCB0[4];", "        d0 = pa[4];"),
    ("ccd_k0", "    k0 = gUnk_083FDA2C[(*cc).d].f1;", "    k0 = gUnk_083FDA2C[ccd].f1;"),
    ("cc2_a", "    u0 = (*cc).a;", "    u0 = (*cc2).a;"),
    ("d1_direct", "    v55 = *(u8 *)k2;\n    d1 = k2;\n",
                  "    v55 = *(u8 *)k2;\n    d1 = (s32)&((struct Ent *)u)->unk55;\n"),
    ("v55_const", "    v55 = 0x10;\n    *(u8 *)d1 = v55;\n    hit2->unk55 = v55;\n",
                  "    *(u8 *)d1 = 0x10;\n    hit2->unk55 = 0x10;\n"),
    ("m2e2_arg_cc", "sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90, &flag, -w, (e << 16) / -w);",
                    "sub_0800D64C(cursor, a2, a1, 3, cc, &flag, -w, (e << 16) / -w);"),
    ("m1e2_arg_k1", "                sub_0800D64C(a1, a2, cursor, 3, cc, &flag, -w, (e << 16) / -w);",
                    "                sub_0800D64C(a1, a2, cursor, 3, cc, &flag, -w, (d1 << 16) / -w);"),
    ("self_carrier", "            self = a1;\n            dx = self->unk00;", "            dx = a1->unk00;"),
    ("other_carrier", "            other = cursor;\n            dx -= other->unk00;", "            dx -= cursor->unk00;"),
    ("count_carrier", "    count = gUnk_02002090;\n    if (gUnk_020020DC != 0)\n        count = gUnk_020020AC;",
                      "    count = gUnk_02002090;\n    if (gUnk_020020DC != 0)\n        count = gUnk_020020AC;"),
]
# edge substitutions, generated
for site, pat in (("m1", "(e = v1 - 0xF00) >= 0) {\n            edgeq = e * u / w;\n            k2 = edgeq + v2;\n            d1 = k2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)\n                sub_0800D64C(a1, a2, cursor, 3, cc, &flag, -w, (e << 16) / -w);"),
                  ("m2", "(e = v1 - 0xF00) >= 0) {\n            edgeq = e * u / w;\n            d1 = edgeq + v2;\n            if ((u32)(d1 + 0x1C00) <= 0x3800)\n                sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90, &flag, -w, (e << 16) / -w);")):
    if BASE.count(pat) != 1:
        continue
    for var in ("dz", "d0", "i"):
        new = pat.replace("(e = v1 - 0xF00)", f"({var} = v1 - 0xF00)").replace("e * u / w", f"{var} * u / w").replace("(e << 16)", f"({var} << 16)")
        LEVERS.append((f"{site}_e_{var}", pat, new))

AVAIL = [(n, o, w) for n, o, w in LEVERS if BASE.count(o) == 1]


def evaluate(args):
    tag, text = args
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(text)
    try:
        r = D.run(str(f), str(d))
        if r.err or r.ours is None:
            return {"tag": tag, "hunks": 99, "sdiff": 99999, "size": 0}
        return {"tag": tag, "hunks": len(r.hunks()), "sdiff": F.score_of(r), "size": r.size}
    except Exception:
        return {"tag": tag, "hunks": 99, "sdiff": 99999, "size": 0}


def apply(t, combo):
    for _, o, w in combo:
        t = t.replace(o, w)
    return t


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--triples", type=int, default=0)
    a = ap.parse_args()
    print(f"{len(AVAIL)} applicable levers")
    pairs = [(("+".join(n for n, _, _ in c)).replace("+", "_"), apply(BASE, c))
             for c in itertools.combinations(AVAIL, 2)]
    print(f"{len(pairs)} pairs")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(evaluate, pairs))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    good = [r for r in rows if r["size"] == 2006 and r["hunks"] == 0 and r["sdiff"] < 335]
    for r in rows[:12]:
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>6}  {r['tag']}")
    print(f"{len(good)} pairs below 335")
    return


if __name__ == "__main__":
    main()