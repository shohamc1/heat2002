#!/usr/bin/env python3
"""Occurrence-specific alias respellings: pa[k]/pb[k] -> gUnk_0202CCB0[k]/gUnk_0202CD30[k].

LaneBig's win was `d0 = pa[4]` -> `d0 = gUnk_0202CCB0[4]`: because `pa` is a spilled
pseudo, every read rematerialises the *global's address*; writing the global directly
reshapes that chain's live set and can hand the remat the target's register.  The effect
is per-occurrence, so this sweep enumerates every occurrence, then pairs/triples.
"""
import itertools
import pathlib
import re
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/alias")
PAT = re.compile(r"\b(pa|pb)\[(\d+)\]")


def occurrences():
    out = []
    for m in PAT.finditer(BASE):
        var, idx = m.group(1), m.group(2)
        glob = "gUnk_0202CCB0" if var == "pa" else "gUnk_0202CD30"
        out.append((m.start(), m.end(), BASE[m.start():m.end()], f"{glob}[{idx}]"))
    return out


def variant(occ_idx):
    occ = occurrences()
    keep = set(occ_idx)
    parts = []
    last = 0
    for i, (s, e, old, new) in enumerate(occ):
        parts.append(BASE[last:s])
        parts.append(new if i in keep else old)
        last = e
    parts.append(BASE[last:])
    return "".join(parts)


def work(args):
    tag, keep = args
    d = OUT / tag
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(variant(keep))
    try:
        r = filediff.report(str(f), str(d))
    except Exception as ex:
        return {"tag": tag, "keep": sorted(keep), "sdiff": 99999, "hunks": 99, "size": 0, "note": str(ex)[:40]}
    if "hunks" not in r:
        return {"tag": tag, "keep": sorted(keep), "sdiff": 99999, "hunks": 99, "size": 0}
    r["tag"] = tag
    r["keep"] = sorted(keep)
    return r


def main():
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--mode", default="singles", choices=["singles", "pairs", "triples", "quads"])
    a = ap.parse_args()
    occ = occurrences()
    print(f"{len(occ)} occurrences:", [(i, o[2]) for i, o in enumerate(occ)])
    n = len(occ)
    combos = []
    if a.mode == "singles":
        combos = [(i,) for i in range(n)]
    elif a.mode == "pairs":
        combos = list(itertools.combinations(range(n), 2))
    elif a.mode == "triples":
        combos = list(itertools.combinations(range(n), 3))
    else:
        combos = list(itertools.combinations(range(n), 4))
    todo = [(f"{a.mode}_{'_'.join(map(str, c))}", set(c)) for c in combos]
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:25]:
        labels = "+".join(occ[i][2] for i in r["keep"])
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>5}  {labels}")


if __name__ == "__main__":
    main()