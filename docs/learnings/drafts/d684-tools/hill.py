#!/usr/bin/env python3
"""Hill-climb search over declaration-list permutations and other global levers.

Why: sub_0800D684 is at 6 structural hunks / ndiff 78.  The remaining lines are
register-allocation differences, and agbcc's allocators take pseudo numbers and
priorities straight from *declaration order*.  A permutation of the declaration
list changes allocation globally while leaving the instruction stream (and thus
the structural hunks) intact -- exactly the lever the per-site spellings cannot
reach.

Usage:
    python3 hill.py --base FILE [--out DIR] [-j 8] [--rounds N] [--seed-file FILE]

Writes: OUT/best.c (best source found), OUT/log.jsonl (every evaluated variant),
OUT/round-N-rank.txt (ranked mutations of round N).

Score: field-level diff (filediff.py): 100 per shape difference, 5 per recolour, 1 per immediate  (mirrors decomp-permuter's weights: an inserted or
deleted instruction costs more than a register recolour).
"""
import argparse
import json
import os
import re
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402
import filediff  # noqa: E402

DECL_RE = re.compile(r"^(    )(u8|s32|u32|f32|struct [A-Za-z0-9_]+ \*?|s16|u16)(.+);$")


def decl_lines(text):
    """Return (line indices of declaration statements in the function header)."""
    lines = text.split("\n")
    fn = next(i for i, l in enumerate(lines) if l.startswith("u8 sub_0800D684"))
    out = []
    for i in range(fn + 1, len(lines)):
        l = lines[i]
        if l.startswith("{"):
            continue
        m = DECL_RE.match(l)
        if m and not l.strip().startswith("//"):
            out.append(i)
    # only the contiguous run right after the function header line + '{'
    return out


def swap_mutations(text):
    idx = decl_lines(text)
    lines = text.split("\n")
    for a, b in zip(idx, idx[1:]):
        v = list(lines)
        v[a], v[b] = v[b], v[a]
        yield f"swap {a}:{b} ({lines[a].strip()[:24]} <-> {lines[b].strip()[:24]})", "\n".join(v)


def move_mutations(text):
    idx = decl_lines(text)
    lines = text.split("\n")
    first, last = idx[0], idx[-1]
    for a in idx:
        for target, name in ((first, "first"), (last, "last")):
            if a == target:
                continue
            v = list(lines)
            item = v.pop(a)
            t = target if a > target else target
            v.insert(t, item)
            yield f"move {a}->{name} ({lines[a].strip()[:24]})", "\n".join(v)


def delete_mutations(text):
    idx = decl_lines(text)
    lines = text.split("\n")
    for a in idx:
        v = list(lines)
        if v[a].strip().startswith("s32 lim3800"):
            v[a] = "    // removed: " + v[a].strip()
        else:
            continue
        yield f"drop {lines[a].strip()[:24]}", "\n".join(v)


def inner_decl_mutations(text):
    """Move the post-loop block's inner declarations to the function header."""
    m = re.search(r"    if \(flag != 0\) \{\n((?:    [a-zA-Z].*\n|\n)+?)\n", text)
    if not m:
        return
    block = [l for l in m.group(1).split("\n") if l.strip() and not l.strip().startswith("u0")]
    head = decl_lines(text)[-1]
    lines = text.split("\n")
    for l in block:
        v = list(lines)
        v = [x for x in v if x != l]
        v.insert(head + 1, l)
        yield f"hoist inner decl {l.strip()[:30]}", "\n".join(v)


def variants(text):
    for name, t in swap_mutations(text):
        yield ("swap", name, t)
    for name, t in move_mutations(text):
        yield ("move", name, t)
    for name, t in delete_mutations(text):
        yield ("drop", name, t)
    for name, t in inner_decl_mutations(text):
        yield ("hoist", name, t)


def evaluate(args):
    tag, name, text, outdir = args
    d = Path(outdir) / "wd" / tag
    f = d / "v.c"
    d.mkdir(parents=True, exist_ok=True)
    f.write_text(text)
    try:
        rep = filediff.report(str(f), str(d))
    except Exception as e:  # compile/link blowups are just bad scores
        return {"name": name, "error": str(e)[:120]}
    rep["name"] = name
    return rep


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", required=True)
    ap.add_argument("--out", default="/tmp/d684v5/hill")
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--rounds", type=int, default=4)
    a = ap.parse_args()

    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    base_text = Path(a.base).read_text()
    log = open(out / "log.jsonl", "a")
    cur = base_text
    base_rep = evaluate(("base", "base", cur, str(out)))
    print("base:", {k: base_rep.get(k) for k in ("size", "hunks", "sdiff", "match")}, flush=True)

    for rnd in range(a.rounds):
        todo = [(f"r{rnd}m{i}", name, t, str(out)) for i, (_k, name, t) in enumerate(variants(cur))]
        print(f"round {rnd}: {len(todo)} variants", flush=True)
        with ProcessPoolExecutor(max_workers=a.j) as ex:
            rows = [r for r in ex.map(evaluate, todo) if "error" not in r]
        rows.sort(key=lambda r: (r["sdiff"], r["hunks"], r["size"]))
        for r in rows:
            log.write(json.dumps(r) + "\n")
        log.flush()
        with open(out / f"round-{rnd}-rank.txt", "w") as fh:
            for r in rows[:35]:
                fh.write(f"{r['sdiff']:6d} hunks={r['hunks']:2d} size={r['size']} {r['name']}\n")
        best = rows[0]
        cur_score = (base_rep["sdiff"], base_rep["hunks"])
        best_score = (best["sdiff"], best["hunks"])
        print(f"  best: {best['name']} score={best_score} (base {cur_score})", flush=True)
        if best_score < cur_score:
            # rebuild the best text and re-measure with the base path for stability
            for tag, name, t in variants(cur):
                if name == best["name"]:
                    cur = t
                    break
            (out / "best.c").write_text(cur)
            base_rep = best
        else:
            print("  no improvement; stopping", flush=True)
            break
    (out / "best.c").write_text(cur)
    print("best written to", out / "best.c")


if __name__ == "__main__":
    main()