#!/usr/bin/env python3
"""Search for variants that fix the *tail* (the two post-loop `cc` remats),
regardless of head damage, by ranking on a tail-local signal instead of the total.

If a variant stops emitting the two extra instructions at 0x800db68 / 0x800db90,
r4 has entered the reload scratch union and the tail is fixed.  Ranking on total
hunks would hide such a variant behind new head hunks, so this ranks on
tail-local opcodes first, then total hunks, then sdiff.

    python3 tailrank.py [-j 8] [--max-remove 3]
"""
import argparse
import itertools
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import difflib
import d684tool as D  # noqa: E402
import filediff as F  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/tailrank")
TAIL_LO, TAIL_HI = 0x800DB00, 0x800DBC0


def analyse(res):
    tn = [D.norm(x) for x in res.td]
    on = [D.norm(x) for x in res.od]
    ops = [o for o in difflib.SequenceMatcher(None, tn, on, autojunk=False).get_opcodes() if o[0] != "equal"]
    # robust tail signal: length of the run of trailing instructions that are
    # byte-identical (raw text, registers included) at the end of both listings
    def body(line):  # drop the address prefix, keep register names
        return line.split(":", 1)[1].split("@")[0].strip() if ":" in line else line.strip()

    tail = 0
    k = 1
    while k <= len(res.td) and k <= len(res.od):
        if body(res.td[-k]) == body(res.od[-k]):
            tail += 1
            k += 1
        else:
            break
    return len(ops), tail, F.score_of(res)


def evaluate(args):
    tag, text, d = args
    p = pathlib.Path(d)
    p.mkdir(parents=True, exist_ok=True)
    f = p / "v.c"
    f.write_text(text)
    try:
        res = D.run(str(f), str(p))
        if res.err or res.ours is None:
            return {"tag": tag, "tail": 999, "hunks": 999, "sdiff": 999999, "size": 0}
        hunks, tail, sdiff = analyse(res)
    except Exception:
        return {"tag": tag, "tail": 999, "hunks": 999, "sdiff": 999999, "size": 0}
    return {"tag": tag, "hunks": hunks, "tail": tail, "sdiff": sdiff, "size": res.size}


def carrier_variants(max_remove):
    from carriersub import CARRIERS
    names = [n for n, o, _ in CARRIERS if BASE.count(o) == 1]
    for k in range(0, min(max_remove, len(names)) + 1):
        for c in itertools.combinations(names, k):
            t = BASE
            ok = True
            for name, old, new in CARRIERS:
                if name in c:
                    if t.count(old) != 1:
                        ok = False
                        break
                    t = t.replace(old, new)
            if ok:
                yield ("r" + "_".join(c) if c else "base"), t


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--max-remove", type=int, default=3)
    ap.add_argument("--top", type=int, default=30)
    a = ap.parse_args()
    todo = [(tag, text, str(OUT / tag)) for tag, text in carrier_variants(a.max_remove)]
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(evaluate, todo))
    rows.sort(key=lambda r: (-r["tail"], r["hunks"], r["sdiff"], r["size"]))
    print(f"{'tail':>4} {'hunks':>5} {'sdiff':>7} {'size':>5}  tag")
    for r in rows[: a.top]:
        print(f"{r['tail']:>4} {r['hunks']:>5} {r['sdiff']:>7} {r['size']:>5}  {r['tag']}")


if __name__ == "__main__":
    main()