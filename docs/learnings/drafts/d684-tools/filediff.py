#!/usr/bin/env python3
"""Field-level diff score for sub_0800D684 (decomp-permuter's weighting).

The structural metric (`d684tool.py check`) ignores register operands; the
keepreg metric (`ndiff.py`) masks immediates.  A byte match needs both to be
right, so this scorer prices every difference the way decomp-permuter does:

    mnemonic/shape difference (insert, delete, replace across shapes)  100
    differing register operand                                          5
    differing immediate/offset                                          1

Alignment runs on the *structural* normalisation (registers, immediates, pool
offsets, branch targets masked), so a pure recolour is a `replace` of two equal
lines and is priced 5 per differing register.  PC-relative pool offsets and
branch targets are excluded from the cost: they move legitimately when the
function's size shifts.

    python3 filediff.py FILE [--workdir DIR] [--cc BINARY] [--list]
"""
import argparse
import difflib
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402

COST_SHAPE = 100
COST_REG = 5
COST_IMM = 1

REG_RE = re.compile(r"\b(r\d+|sl|fp|ip|sp|lr|pc)\b")


def clean(line):
    line = re.sub(r"^[0-9a-f]+:\s*", "", line)
    line = re.sub(r"@.*$", "", line)
    return line.strip()


def tokens(line):
    parts = clean(line).split(None, 1)
    if not parts:
        return "", []
    mnem = parts[0]
    ops = parts[1] if len(parts) > 1 else ""
    ops = ops.replace("[", " ").replace("]", " ").replace(",", " ").replace("{", "").replace("}", "")
    return mnem, ops.split()


def line_cost(a, b):
    ma, ta = tokens(a)
    mb, tb = tokens(b)
    if ma != mb or len(ta) != len(tb):
        return COST_SHAPE
    cost = 0
    for x, y in zip(ta, tb):
        x, y = x.strip(), y.strip()
        if x == y:
            continue
        xr, yr = REG_RE.fullmatch(x), REG_RE.fullmatch(y)
        if xr and yr:
            cost += COST_REG          # register recolour
        else:
            cost += COST_IMM          # immediate / offset / branch target
    return cost


def score_of(r, listing=False):
    tn = [D.norm(x) for x in r.td]
    on = [D.norm(x) for x in r.od]
    total = 0
    detail = []
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(
            None, tn, on, autojunk=False).get_opcodes():
        if tag == "equal":
            # structurally identical: price any recolour or immediate that the
            # structural normalisation masked
            for k in range(i2 - i1):
                c = line_cost(r.td[i1 + k], r.od[j1 + k])
                total += c
                if listing and c:
                    detail.append((c, r.td[i1 + k], r.od[j1 + k]))
            continue
        if tag == "replace" and (i2 - i1) == (j2 - j1):
            for k in range(i2 - i1):
                c = line_cost(r.td[i1 + k], r.od[j1 + k])
                total += c
                if listing and c:
                    detail.append((c, r.td[i1 + k], r.od[j1 + k]))
        else:
            n = max(i2 - i1, j2 - j1)
            for k in range(n):
                t = r.td[i1 + k] if i1 + k < i2 else ""
                o = r.od[j1 + k] if j1 + k < j2 else ""
                total += COST_SHAPE
                if listing:
                    detail.append((COST_SHAPE, t, o))
    if listing:
        return total, detail
    return total


def report(src, workdir, cc=None, listing=False):
    r = D.run(src, workdir) if cc is None else D.run(src, workdir, cc1=cc)
    if r.err or r.ours is None:
        return {"src": str(src), "error": (r.err or "no output")[:300]}
    if listing:
        s, detail = score_of(r, True)
    else:
        s = score_of(r)
        detail = None
    tn = [D.norm(x) for x in r.td]
    on = [D.norm(x) for x in r.od]
    hunks = sum(1 for tag, *_ in difflib.SequenceMatcher(None, tn, on, autojunk=False).get_opcodes() if tag != "equal")
    out = {"src": str(src), "size": r.size, "match": r.match, "hunks": hunks, "sdiff": s}
    if detail is not None:
        out["detail"] = detail
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("--workdir", default="/tmp/d684v5/wd")
    ap.add_argument("--cc")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()
    res = report(a.src, a.workdir, Path(a.cc) if a.cc else None, a.list)
    if a.list and "detail" in res:
        for c, t, o in sorted(res["detail"], key=lambda x: -x[0]):
            print(f"{c:5d}  - {t if t else '(none)':<52s} + {o}")
        print()
        del res["detail"]
    print(json.dumps(res))


if __name__ == "__main__":
    sys.exit(main())
