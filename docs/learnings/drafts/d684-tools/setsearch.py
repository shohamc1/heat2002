#!/usr/bin/env python3
"""Carrier-subset search screened by the reload scratch set.

The pre-carrier draft has the target's spill set {0,1,2,3,4,6} and 26 shape
hunks; the current draft has 0 hunks and the wrong set {0,1,2,3,6}.  This walks
subsets of the documented carriers, keeps those whose compile reports
`USEDSPILL` containing r4, and scores them.

    python3 setsearch.py [-j 8] [--random N] [--max-remove K]
"""
import argparse
import itertools
import os
import pathlib
import random
import subprocess
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402
import filediff as F  # noqa: E402
from carriersub import CARRIERS  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/setsearch")
DIAG = REPO / "tools/agbcc/gcc/old_agbcc"


def build(remove):
    t = BASE
    for name, old, new in CARRIERS:
        if name in remove:
            if t.count(old) != 1:
                return None
            t = t.replace(old, new)
    return t


def check(args):
    tag, remove = args
    text = build(set(remove))
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    if text is None:
        return {"tag": tag, "set": None, "score": None}
    f = d / "v.c"
    f.write_text(text)
    i = d / "v.i"
    r = subprocess.run([D.CPP, "-E", "-x", "c"] + D.CPPFLAGS + [str(f), "-o", str(i)],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return {"tag": tag, "set": None, "score": None}
    env = dict(os.environ)
    env["RT_ALL"] = "1"
    r = subprocess.run([str(DIAG)] + D.CFLAGS + [str(i), "-o", str(d / "v.s")],
                       capture_output=True, text=True, env=env)
    if r.returncode != 0:
        return {"tag": tag, "set": None, "score": None}
    us = [l for l in r.stderr.splitlines() if l.startswith("USEDSPILL:")]
    s = us[-1].split(":", 1)[1].split() if us else []
    res = D.run(str(f), str(d))
    sc = None if (res.err or res.ours is None) else (res.size, len(res.hunks()), F.score_of(res))
    return {"tag": tag, "set": s, "score": sc}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--random", type=int, default=200)
    ap.add_argument("--max-remove", type=int, default=3)
    ap.add_argument("--seed", type=int, default=7)
    a = ap.parse_args()
    names = [n for n, o, _ in CARRIERS if BASE.count(o) == 1]
    todo = []
    for k in range(0, a.max_remove + 1):
        for c in itertools.combinations(names, k):
            todo.append(("r" + "_".join(c) if c else "base", c))
    rnd = random.Random(a.seed)
    for n in range(a.random):
        k = rnd.randint(4, max(5, len(names) - 1))
        c = tuple(rnd.sample(names, k))
        todo.append(("x" + "_".join(c), c))
    print(f"{len(names)} carriers, {len(todo)} variants")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(check, todo))
    with4 = [r for r in rows if r["set"] and "4" in r["set"]]
    print(f"{len(with4)} variants keep r4 in the set")
    with4.sort(key=lambda r: (r["score"] is None, r["score"] or (9999, 999, 999999)))
    for r in with4[:20]:
        print(f"  set={' '.join(r['set']):22s} score={r['score']} {r['tag'][:90]}")
    good = [r for r in with4 if r["score"] and r["score"][0] == 2006 and r["score"][1] == 0 and r["score"][2] < 335]
    print(f"{len(good)} of them beat 335")


if __name__ == "__main__":
    main()