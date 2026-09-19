#!/usr/bin/env python3
"""Sweep post-loop spellings of the `cc` reads (the `(*cc).{a,b,d,h,i,j}` group
after the loop) against the tail hunks.

The ROM materialises `&gUnk_0202CC90` into r4 at 0x800db42 and keeps it live;
our draft materialises it pre-loop into r6, which the sin-table `ldrsh r6` kills,
so the later reads rematerialise the address (the two insert hunks).

    python3 ccsweep.py [-j 8]
"""
import argparse
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402
import filediff as F  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/ccsweep")

# post-loop reads, in source order
POST = [
    "    u0 = (*cc).a;\n",
    "    d1 = (s32)(*cc).c;\n",
    "    ccd = (*cc).d;\n",
    "    k0 = gUnk_083FDA2C[(*cc).d].f1;\n",
]
REPL = {
    "arrow": lambda f: f.replace("(*cc).", "cc->"),
    "global": lambda f: f.replace("(*cc).", "gUnk_0202CC90."),
    "globptr": lambda f: f.replace("(*cc).", "(&gUnk_0202CC90)->"),
}


def make(kind, which):
    t = BASE
    for i, snip in enumerate(POST):
        if i not in which:
            continue
        if t.count(snip) != 1:
            return None
        t = t.replace(snip, REPL[kind](snip))
    return t


def evaluate(args):
    tag, text = args
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    if text is None:
        return {"tag": tag, "hunks": 99, "sdiff": 99999, "size": 0}
    f.write_text(text)
    try:
        res = D.run(str(f), str(d))
        if res.err or res.ours is None:
            return {"tag": tag, "hunks": 99, "sdiff": 99999, "size": 0}
        hunks = len([o for o in __import__("difflib").SequenceMatcher(
            None, [D.norm(x) for x in res.td], [D.norm(x) for x in res.od], autojunk=False
        ).get_opcodes() if o[0] != "equal"])
        return {"tag": tag, "hunks": hunks, "sdiff": F.score_of(res), "size": res.size}
    except Exception:
        return {"tag": tag, "hunks": 99, "sdiff": 99999, "size": 0}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    a = ap.parse_args()
    import itertools
    todo = []
    for kind in REPL:
        for n in range(1, len(POST) + 1):
            for which in itertools.combinations(range(len(POST)), n):
                tag = f"{kind}_" + "".join(str(i) for i in which)
                todo.append((tag, make(kind, set(which))))
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(evaluate, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:20]:
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>6}  {r['tag']}")


if __name__ == "__main__":
    main()