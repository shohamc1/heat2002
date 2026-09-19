#!/usr/bin/env python3
"""Occurrence-specific respellings of aliasable lvalues.

Families (all semantics-preserving):
  A. `(*cc).X`      -> `gUnk_0202CC90.X`   (cc is assigned once, never rebound)
  B. `((struct Ent *)u)->X` -> `u0->X`     (u0 = (*cc).a, u = (s32)u0, both write-once)
  C. `((struct Ent *)w)->X` -> `hit2->X`   only for occurrences after hit2's assignment
     (B and C are offered with the winner; verify the construction yourself)

    python3 alias2.py --mode singles|pairs [-j 8]
"""
import argparse
import itertools
import pathlib
import re
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import filediff  # noqa: E402

REPO = pathlib.Path("/Users/shohamc1/heat2002-gba")
BASE = (REPO / "src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/alias2")

RULES = [
    (re.compile(r"\(\*cc\)\.(\w+)"), lambda m: f"gUnk_0202CC90.{m.group(1)}"),
    (re.compile(r"\(\(struct Ent \*\)u\)->(\w+)"), lambda m: f"u0->{m.group(1)}"),
]
HIT2_START = BASE.find("    hit2 = (struct Ent *)w;")
SELF_START = BASE.find("            self = a1;")
OTHER_START = BASE.find("            other = cursor;")


def occurrences():
    out = []
    for rx, fn in RULES:
        for m in rx.finditer(BASE):
            out.append((m.start(), m.end(), m.group(0), fn(m)))
    # family C: only occurrences after hit2's assignment
    rx = re.compile(r"\(\(struct Ent \*\)w\)->(\w+)")
    for m in rx.finditer(BASE):
        if m.start() > HIT2_START:
            out.append((m.start(), m.end(), m.group(0), f"hit2->{m.group(1)}"))
    # family D: self->X -> a1->X, other->X -> cursor->X (after their assignments)
    for rx, fn, start in [
        (re.compile(r"\bself->(\w+)"), lambda m: f"a1->{m.group(1)}", SELF_START),
        (re.compile(r"\bother->(\w+)"), lambda m: f"cursor->{m.group(1)}", OTHER_START),
    ]:
        if start < 0:
            continue
        for m in rx.finditer(BASE):
            if m.start() > start:
                out.append((m.start(), m.end(), m.group(0), fn(m)))
    out.sort()
    return out


def variant(keep):
    occ = occurrences()
    parts, last = [], 0
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
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--mode", default="singles", choices=["singles", "pairs"])
    a = ap.parse_args()
    occ = occurrences()
    print(f"{len(occ)} occurrences")
    for i, o in enumerate(occ):
        print(f"  [{i}] {o[2]} -> {o[3]}")
    n = len(occ)
    combos = [(i,) for i in range(n)] if a.mode == "singles" else list(itertools.combinations(range(n), 2))
    todo = [(f"{a.mode}_{'_'.join(map(str, c))}", set(c)) for c in combos]
    print(f"{len(todo)} variants")
    with ProcessPoolExecutor(max_workers=a.j) as ex:
        rows = list(ex.map(work, todo))
    rows.sort(key=lambda r: (r["hunks"], r["sdiff"], r["size"]))
    for r in rows[:20]:
        labels = " + ".join(occ[i][2] + "->" + occ[i][3] for i in r["keep"])
        print(f"{r['size']:>5} {r['hunks']:>2} {r['sdiff']:>5}  {labels}")


if __name__ == "__main__":
    main()