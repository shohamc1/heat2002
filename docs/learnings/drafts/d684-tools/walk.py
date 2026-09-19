#!/usr/bin/env python3
"""Plateau-walking search for sub_0800D684.

The metric landscape is flat in many directions (most single edits are exactly
neutral), and every accepted win so far was a *set* of edits that are neutral
or worse alone.  A plain single-edit sweep from a fixed base therefore stalls.
This walks: from the current variant, score every lever; take the best move
(ties broken at random, with a tabu list to avoid cycling), accept it even if
it is neutral, and record the best (hunks, sdiff, size) ever seen.

    python3 walk.py [--steps N] [-j 8] [--out DIR] [--base FILE]
"""
import argparse
import itertools
import json
import pathlib
import random
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

# ---------------------------------------------------------------- lever library
DEAD = ["k0", "k1", "k2", "k3", "d0", "d1", "edgeq", "dx", "v1hold", "lim3800",
        "i", "count", "a2", "base", "self", "other", "a1_175", "u0"]
BOUNDS = ["k0", "k1", "k2", "k3", "d0", "d1", "edgeq"]


def levers(base):
    """Yield (name, old, new) edits; only those present in `base` survive."""
    out = []
    # guard carriers: (e = <expr>) -> (X = (e = <expr>)) for each guard
    guards = [
        ("h1e0", "        if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {", "e = v2 - 0x1C00"),
        ("h1e1", "        if (u > 0 && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {", "e = -0x1C00 - v2"),
        ("h1e2", "        if (w > 0 && v3 >= -0xF00 && (d1 = (e = -0xF00 - v1)) >= 0) {", "e = -0xF00 - v1"),
        ("h1e3", "        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {", "e = v1 - 0xF00"),
        ("h2e0", "        if (u < 0 && v4 <= 0x1C00 && (d1 = (e = v2 - 0x1C00)) >= 0) {", "e = v2 - 0x1C00"),
        ("h2e1", "        if (0 < u && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {", "e = -0x1C00 - v2"),
        ("h2e2", "        if (w > 0 && v3 >= -0xF00 && (e = -0xF00 - v1) >= 0) {", "e = -0xF00 - v1"),
        ("h2e3", "        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {", "e = v1 - 0xF00"),
    ]
    for site, line, expr in guards:
        if base.count(line) != 1:
            continue
        for x in DEAD:
            out.append((f"{site}_carrier_{x}", line, line.replace(f"(e = {expr})", f"({x} = (e = {expr}))")))
        if "(d1 = (e =" in line:  # also allow removing the existing carrier
            out.append((f"{site}_carrier_none", line, line.replace(f"(d1 = (e = {expr}))", f"(e = {expr})")))
    # bound carriers
    for site, old, tmpl in [
        ("h1e1b", "            k2 = edgeq + v1;\n            if ((u32)(k2 + 0xF00) <= 0x1E00)", "            {K} = edgeq + v1;\n            if ((u32)({{K}} + 0xF00) <= 0x1E00)"),
        ("h1e2b", "            k2 = edgeq + v2;\n            k1 = e;", "            {K} = edgeq + v2;\n            k1 = e;"),
        ("h1e3b", "            d1 = k2 + 0x1C00;\n            if ((u32)d1 <= 0x3800)", "            {K} = edgeq + v2;\n            if ((u32)({{K}} + 0x1C00) <= 0x3800)"),
        ("h2e1b", "            k2 = edgeq + v1;\n            if ((u32)(k2 + 0xF00) <= 0x1E00)", "            {K} = edgeq + v1;\n            if ((u32)({{K}} + 0xF00) <= 0x1E00)"),
        ("h2e2b", "            k0 = edgeq + v2;\n            if ((u32)(k0 + 0x1C00) <= 0x3800)", "            {K} = edgeq + v2;\n            if ((u32)({{K}} + 0x1C00) <= 0x3800)"),
        ("h2e3b", "            edgeq = edgeq + v2;\n            if ((u32)(edgeq + 0x1C00) <= 0x3800)", "            {K} = edgeq + v2;\n            if ((u32)({{K}} + 0x1C00) <= 0x3800)"),
    ]:
        if base.count(old) != 1:
            continue
        for k in BOUNDS:
            new = tmpl.replace("{K}", k).replace("{K}", k)
            out.append((f"{site}_bound_{k}", old, new))
    # call-argument mixes
    for i, (old, new) in enumerate([
        ("sub_0800D64C(a1, a2, cursor, 0, &gUnk_0202CC90,", "sub_0800D64C(a1, a2, cursor, 0, cc,"),
        ("sub_0800D64C(a1, a2, cursor, 1, cc,", "sub_0800D64C(a1, a2, cursor, 1, &gUnk_0202CC90,"),
        ("sub_0800D64C(a1, a2, cursor, 2, cc,", "sub_0800D64C(a1, a2, cursor, 2, &gUnk_0202CC90,"),
        ("sub_0800D64C(a1, a2, cursor, 3, cc,", "sub_0800D64C(a1, a2, cursor, 3, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 0, cc,", "sub_0800D64C(cursor, a2, a1, 0, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 1, cc,", "sub_0800D64C(cursor, a2, a1, 1, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 2, cc,", "sub_0800D64C(cursor, a2, a1, 2, &gUnk_0202CC90,"),
        ("sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90,", "sub_0800D64C(cursor, a2, a1, 3, cc,"),
    ]):
        if base.count(old) >= 1:
            out.append((f"argmix{i}", old, new))
    # numerator spellings
    for site, old, new in [
        ("h1e2num", "                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);",
                    "                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (e << 16) / w);"),
        ("h1e2num2", "            k1 = e;\n            d1 = k1;", "            d1 = e;"),
        ("h2e0num", "            edgeq = w * e / u;\n            edgeq += v1hold;", "            edgeq = w * e / u;\n            edgeq += v1hold;"),
    ]:
        if base.count(old) >= 1:
            out.append((site, old, new))
    # post-loop carriers and spellings
    for site, old, new in [
        ("glob_g", "    d0 = -gUnk_0202CC90.g;", "    d0 = -(*cc).g;"),
        ("glob_g2", "    d0 = -(*cc).g;", "    d0 = -gUnk_0202CC90.g;"),
        ("dotk1", "    k1 = gUnk_083FDA2C[ccd].f0;", "    k1 = (&gUnk_083FDA2C[ccd])->f0;"),
        ("dotk1b", "    k1 = (&gUnk_083FDA2C[ccd])->f0;", "    k1 = gUnk_083FDA2C[ccd].f0;"),
        ("wcar", "    d1 = (s32)(*cc).c;\n    w = d1;", "    d0 = (s32)(*cc).c;\n    w = d0;"),
        ("wcar2", "    d0 = (s32)(*cc).c;\n    w = d0;", "    d1 = (s32)(*cc).c;\n    w = d1;"),
        ("wcar3", "    d1 = (s32)(*cc).c;\n    w = d1;", "    w = (s32)(*cc).c;"),
        ("k3_4", "            k3 = 4;\n", "            dz = 4;\n"),
        ("dz_4", "            dz = 4;\n", "            k3 = 4;\n"),
        ("unk55a", "    k2 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)k2;\n    d1 = k2;",
                   "    d1 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)d1;"),
        ("unk55b", "    k2 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)k2;\n    d1 = k2;",
                   "    k3 = (s32)&((struct Ent *)u)->unk55;\n    v55 = *(u8 *)k3;\n    d1 = k3;"),
        ("selfstore_pre", "    a1->unk175 = a1->unk175;\n", ""),
        ("selfstore_loop", "a1->unk175 = a1->unk175;\nloop_continue:", "loop_continue:"),
        ("dowhile", "            do\n                hit2->unk88 -= d0 >> 14;\n            while (0);", "            hit2->unk88 -= d0 >> 14;"),
        ("nodowhile", "            hit2->unk88 -= d0 >> 14;", "            do\n                hit2->unk88 -= d0 >> 14;\n            while (0);"),
        ("pa_k0", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    k2 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k2);"),
        ("pa_k2", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    k1 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k1);"),
        ("pa_k3", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    k3 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k3);"),
        ("pa_dir", "    k0 = (s32)pa;\n    sub_0800D5D4(a1, (s32 *)k0);", "    sub_0800D5D4(a1, pa);"),
        ("dz_d0", "            d0 = self->unk08;\n            dz = d0;\n            edgeq = other->unk08;\n            dz -= edgeq;",
                  "            dz = self->unk08;\n            dz -= other->unk08;"),
        ("v1_e", "        e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);\n        v1hold = e;",
                 "        v1hold = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);"),
        ("v1h1", "        v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);",
                 "        v1hold = (v1 = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);"),
    ]:
        if base.count(old) >= 1:
            out.append((site, old, new))
    return out


def evaluate(args):
    idx, text, outdir = args
    d = pathlib.Path(outdir) / f"c{idx}"
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(text)
    try:
        r = filediff.report(str(f), str(d))
    except Exception as e:
        return {"idx": idx, "sdiff": 99999, "hunks": 99, "size": 0, "note": str(e)[:60]}
    if "error" in r or "hunks" not in r:
        return {"idx": idx, "sdiff": 99999, "hunks": 99, "size": 0, "note": str(r.get("error", ""))[:60]}
    r["idx"] = idx
    return r


def apply_edit(text, old, new):
    if text.count(old) != 1:
        return None
    return text.replace(old, new)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", default="src/sub_0800D684.c")
    ap.add_argument("--out", default="/tmp/mylane_v0/walk")
    ap.add_argument("--steps", type=int, default=200)
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--seed", type=int, default=1)
    a = ap.parse_args()
    rng = random.Random(a.seed)
    out = pathlib.Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    cur = pathlib.Path(a.base).read_text()
    cur_rep = filediff.report(a.base, str(out / "base"))
    best = (cur_rep["hunks"], cur_rep["sdiff"], cur_rep["size"], cur)
    print(f"base: hunks={cur_rep['hunks']} sdiff={cur_rep['sdiff']} size={cur_rep['size']}", flush=True)
    log = open(out / "log.jsonl", "a")
    tabu = set()
    for step in range(a.steps):
        cands = []
        for name, old, new in levers(cur):
            t = apply_edit(cur, old, new)
            if t is None or t in tabu:
                continue
            cands.append((name, t))
        if not cands:
            print("no applicable levers; stopping", flush=True)
            break
        todo = [(i, t, str(out)) for i, (_n, t) in enumerate(cands)]
        with ProcessPoolExecutor(max_workers=a.j) as ex:
            rows = list(ex.map(evaluate, todo))
        for i, r in enumerate(rows):
            r["name"] = cands[i][0]
            log.write(json.dumps({k: v for k, v in r.items() if k != "idx"}) + "\n")
        log.flush()
        rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
        cur_key = (cur_rep["hunks"], cur_rep["sdiff"], cur_rep["size"])
        ok = [r for r in rows if (r["hunks"], r["sdiff"], r["size"]) <= cur_key]
        if not ok:
            # kick: random worse move to escape a strict local minimum
            pick = rng.choice(rows[: max(1, len(rows) // 4)])
            print("  kick", flush=True)
        else:
            top = [r for r in ok if (r["hunks"], r["sdiff"], r["size"]) == (ok[0]["hunks"], ok[0]["sdiff"], ok[0]["size"])]
            pick = rng.choice(top)
        cur_rep = {"hunks": pick["hunks"], "sdiff": pick["sdiff"], "size": pick["size"]}
        print(f"step {step}: best move {pick['name']} -> hunks={pick['hunks']} sdiff={pick['sdiff']} size={pick['size']}"
              f" (base hunks={best[0]} sdiff={best[1]})", flush=True)
        if (pick["hunks"], pick["sdiff"], pick["size"]) < best[:3]:
            best = (pick["hunks"], pick["sdiff"], pick["size"], cands[pick["idx"]][1])
            (out / "best.c").write_text(best[3])
            print(f"  new best written to {out}/best.c", flush=True)
        cur = cands[pick["idx"]][1]
        tabu.add(cur)
        if len(tabu) > 400:
            tabu = set(itertools.islice(tabu, 200))
    (out / "final.c").write_text(cur)
    print("final best:", best[:3], flush=True)


if __name__ == "__main__":
    main()