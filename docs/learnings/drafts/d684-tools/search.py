#!/usr/bin/env python3
"""Cartesian search over curated source levers for sub_0800D684.

Each lever is a list of (label, edits) where edits is a list of (old, new)
text substitutions applied to the baseline. Every `old` must occur exactly
once. Scores every combination with the isolated harness and logs progress.

  python3 search.py --out /tmp/d684v5/search.jsonl -j 6
  python3 search.py --only L1a,L2a --out ... # filter
"""
import argparse, itertools, json, os, subprocess, sys, time
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

WD = Path("/tmp/d684v5")  # scratch; override with --out/--outdir
import os
BASE = Path(os.environ.get("SEARCH_BASE", str(WD / "base.c"))).read_text()
TOOL = str(Path(__file__).resolve().parent / "d684tool.py")
if not Path(TOOL).exists():  # fall back to the scratch copy
    TOOL = str(WD / "d684tool.py")

# ---------------------------------------------------------------- levers
L1_BASE = "    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);"
L1 = [
    ("baseline", []),
    ("pa", [("    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);", "    sub_0800D5D4(a1, pa);")]),
    ("global", [("    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);", "    sub_0800D5D4(a1, gUnk_0202CCB0);")]),
    ("u32k2", [("    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);", "    k3 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k3);")]),
    ("d0carrier", [("    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);", "    d0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)d0);")]),
]

L2_BASE = """            edgeq = e * u / w;
            k2 = edgeq + v2;
            k1 = e;
            d1 = k1;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);"""
L2 = [
    ("baseline", []),
    ("inline", [("""            k1 = e;
            d1 = k1;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);""",
                 """            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (e << 16) / w);""")]),
    ("d1only", [("""            k1 = e;
            d1 = k1;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);""",
                 """            d1 = e;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);""")]),
    ("k1only", [("""            k1 = e;
            d1 = k1;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);""",
                 """            k1 = e;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (k1 << 16) / w);""")]),
]

L3_BASE = """            if ((u32)(k2 + 0x1C00) <= 0x3800) {
                fraction = e << 16;
                sub_0800D64C(cursor, a2, a1, 2, cc, &flag, w, fraction / w);
            }"""
L3 = [
    ("baseline", []),
    ("inline", [(L3_BASE, """            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(cursor, a2, a1, 2, cc, &flag, w, (e << 16) / w);""")]),
    ("unshifted", [(L3_BASE, """            if ((u32)(k2 + 0x1C00) <= 0x3800) {
                fraction = e;
                sub_0800D64C(cursor, a2, a1, 2, cc, &flag, w, (fraction << 16) / w);
            }""")]),
    ("fraceq", [(L3_BASE, """            if ((u32)(k2 + 0x1C00) <= 0x3800) {
                fraction = e << 16;
                sub_0800D64C(cursor, a2, a1, 2, cc, &flag, w, (fraction) / w);
            }""")]),
]

L4_BASE = """    u0 = (*cc).a;
    u = (s32)u0;
    d0 = (s32)(*cc).c;
    w = d0;
    ang = ((struct Ent *)w)->unk34 >> 8;
    ccd = (*cc).d;
    d1 = gUnk_0801CD08[ang];
    d0 = gUnk_0801CD08[ang + 0x40];
    k1 = (&gUnk_083FDA2C[ccd])->f0;
    k0 = gUnk_083FDA2C[(*cc).d].f1;"""
L4 = [
    ("baseline", []),
    ("allcc_first", [("""    u0 = (*cc).a;
    u = (s32)u0;
    d0 = (s32)(*cc).c;
    w = d0;
    ang = ((struct Ent *)w)->unk34 >> 8;
    ccd = (*cc).d;
    d1 = gUnk_0801CD08[ang];""",
                      """    u0 = (*cc).a;
    u = (s32)u0;
    d0 = (s32)(*cc).c;
    w = d0;
    ccd = (*cc).d;
    d1 = (s32)(*cc).b;
    ang = ((struct Ent *)w)->unk34 >> 8;
    d1 = gUnk_0801CD08[ang];""")]),
    ("seq_fields", [("""    u0 = (*cc).a;
    u = (s32)u0;
    d0 = (s32)(*cc).c;
    w = d0;
    ang = ((struct Ent *)w)->unk34 >> 8;
    ccd = (*cc).d;
    d1 = gUnk_0801CD08[ang];
    d0 = gUnk_0801CD08[ang + 0x40];
    k1 = (&gUnk_083FDA2C[ccd])->f0;
    k0 = gUnk_083FDA2C[(*cc).d].f1;""",
                    """    u0 = (*cc).a;
    u = (s32)u0;
    d0 = (s32)(*cc).c;
    w = d0;
    ccd = (*cc).d;
    k1 = (&gUnk_083FDA2C[ccd])->f0;
    k0 = gUnk_083FDA2C[ccd].f1;
    d1 = (s32)(*cc).b;
    ang = ((struct Ent *)w)->unk34 >> 8;
    d1 = gUnk_0801CD08[ang];
    d0 = gUnk_0801CD08[ang + 0x40];""")]),
    ("g_late", [("""    k1 = (&gUnk_083FDA2C[ccd])->f0;
    k0 = gUnk_083FDA2C[(*cc).d].f1;""",
                 """    k1 = (&gUnk_083FDA2C[ccd])->f0;
    k0 = gUnk_083FDA2C[ccd].f1;""")]),
]

L5_BASE = """    d1 = (s32)&((struct Ent *)u)->unk55;
    v55 = *(u8 *)d1;"""
L5 = [
    ("baseline", []),
    ("readfirst", [(L5_BASE, """    v55 = ((struct Ent *)u)->unk55;
    d1 = (s32)&((struct Ent *)u)->unk55;""")]),
    ("read2nd", [(L5_BASE, """    d1 = (s32)&((struct Ent *)u)->unk55;
    v55 = ((struct Ent *)u)->unk55;""")]),
    ("directread", [(L5_BASE, """    v55 = *(u8 *)&((struct Ent *)u)->unk55;
    d1 = (s32)&((struct Ent *)u)->unk55;""")]),
    ("k2carrier", [(L5_BASE, """    k2 = (s32)&((struct Ent *)u)->unk55;
    v55 = *(u8 *)k2;
    d1 = k2;""")]),
    ("k2carrier2", [(L5_BASE, """    k2 = (s32)&((struct Ent *)u)->unk55;
    d1 = k2;
    v55 = *(u8 *)k2;""")]),
    ("k1carrier", [(L5_BASE, """    k1 = (s32)&((struct Ent *)u)->unk55;
    v55 = *(u8 *)k1;
    d1 = k1;""")]),
    ("k3carrier", [(L5_BASE, """    k3 = (s32)&((struct Ent *)u)->unk55;
    v55 = *(u8 *)k3;
    d1 = k3;""")]),
]

L6_BASE = "        sub_0800BA34(v55, v55, -6, 0, v55, v55, 0x400);"
L6 = [
    ("baseline", []),
    ("d1arg2", [(L6_BASE, "        sub_0800BA34(v55, *(u8 *)d1, -6, 0, v55, v55, 0x400);")]),
    ("d1arg1", [(L6_BASE, "        sub_0800BA34(*(u8 *)d1, v55, -6, 0, v55, v55, 0x400);")]),
    ("d1arg5", [(L6_BASE, "        sub_0800BA34(v55, v55, -6, 0, *(u8 *)d1, v55, 0x400);")]),
]

LEVERS = [("L1", L1), ("L2", L2), ("L3", L3), ("L4", L4), ("L5", L5), ("L6", L6)]


def build(combo):
    src = BASE
    labels = []
    for (name, opts), pick in zip(LEVERS, combo):
        label, edits = opts[pick]
        labels.append(f"{name}{pick}:{label}")
        for old, new in edits:
            n = src.count(old)
            if n != 1:
                return None, f"{name}{pick} pattern count {n} for {old[:40]!r}"
            src = src.replace(old, new)
    return src, "+".join(labels)


def work(args):
    idx, combo, outdir = args
    src, label = build(combo)
    if src is None:
        return {"idx": idx, "label": label, "error": "pattern"}
    d = Path(outdir) / f"c{idx}"
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(src)
    r = subprocess.run(["python3", TOOL, "check", str(f), "--workdir", str(d), "--json"],
                       capture_output=True, text=True)
    try:
        res = json.loads(r.stdout.strip().splitlines()[0])
    except Exception:
        return {"idx": idx, "label": label, "error": (r.stdout + r.stderr)[-200:]}
    res["label"] = label
    res["file"] = str(f)
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(WD / "search.jsonl"))
    ap.add_argument("-j", type=int, default=6)
    ap.add_argument("--outdir", default="/tmp/d684v5/search")
    ap.add_argument("--only", default=None, help="comma list of LxN filters, e.g. L1a,L3b")
    a = ap.parse_args()

    filters = a.only.split(",") if a.only else None
    combos = []
    for combo in itertools.product(*[range(len(o)) for _, o in LEVERS]):
        if filters:
            picks = [f"{n}{chr(ord('a') + i)}" for (n, _), i in zip(LEVERS, combo)]
            if not all(p in filters for p in picks):
                continue
        combos.append(combo)
    print(f"{len(combos)} combinations", flush=True)

    t0 = time.time()
    best = []
    with open(a.out, "a") as log, ProcessPoolExecutor(max_workers=a.j) as ex:
        for res in ex.map(work, [(i, c, a.outdir) for i, c in enumerate(combos)], chunksize=4):
            log.write(json.dumps(res) + "\n")
            log.flush()
            if res.get("match"):
                print(f"*** MATCH: {res['label']} {res['file']}", flush=True)
            h = res.get("hunks")
            if h is not None and h < 8:
                best.append(res)
                print(f"{h} hunks  size={res.get('size')}  {res['label']}  {res['file']}", flush=True)
    print(f"done in {time.time()-t0:.1f}s; improved combos: {len(best)}")
    for r in sorted(best, key=lambda r: r["hunks"])[:15]:
        print(f"  {r['hunks']} hunks (t+{r['t_extra']} o+{r['o_extra']}) size={r['size']} {r['label']}")


if __name__ == "__main__":
    sys.exit(main())
