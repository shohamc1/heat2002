#!/usr/bin/env python3
"""Register-aware diff counter for sub_0800D684.

`d684tool.py check` counts *structural* hunks: differences in instruction
count/shape after blanking register names and operands.  A byte-identical
match needs more than that: the register operands must line up too.

This tool reports, in one line of JSON:

  size   object size in bytes (2006 = match size)
  hunks  structural hunks (d684tool metric; 0 needed)
  ndiff  number of instruction lines that differ with registers visible,
         branch targets/offsets/immediates masked (0 needed)
  match  byte equality (the only true success)

and with `--list`, every differing line as `- target / + ours`.

  python3 ndiff.py FILE [--workdir DIR] [--cc BINARY] [--list]
"""
import argparse
import difflib
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402


def keepreg(s):
    s = re.sub(r"^[0-9a-f]+:\s*", "", s)
    s = re.sub(r"@ \(0x[0-9a-f]+\)", "", s)
    s = re.sub(r"0x[0-9a-fA-F]+|\$[0-9a-fA-F]+|\b\d+\b", "H", s)
    return re.sub(r"\s+", " ", s).strip()


def report(src, workdir, cc=None, listing=False):
    r = D.run(src, workdir) if cc is None else D.run(src, workdir, cc1=cc)
    if r.err or r.ours is None:
        return {"src": str(src), "error": (r.err or "no output")[:300]}
    tn = [D.norm(x) for x in r.td]
    on = [D.norm(x) for x in r.od]
    hunks = [
        (tag, i1, i2, j1, j2)
        for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(
            None, tn, on, autojunk=False).get_opcodes()
        if tag != "equal"
    ]
    tn = [keepreg(x) for x in r.td]
    on = [keepreg(x) for x in r.od]
    diff = []
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(
            None, tn, on, autojunk=False).get_opcodes():
        if tag == "equal":
            continue
        n = max(i2 - i1, j2 - j1)
        for k in range(n):
            t = r.td[i1 + k] if i1 + k < i2 else ""
            o = r.od[j1 + k] if j1 + k < j2 else ""
            diff.append((tag, t, o))
    out = {
        "src": str(src),
        "size": r.size,
        "match": r.match,
        "hunks": len(hunks),
        "ndiff": len(diff),
    }
    if listing:
        out["diff"] = diff
        out["hunk_list"] = hunks
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("--workdir", default="/tmp/d684v5/wd")
    ap.add_argument("--cc")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()
    res = report(a.src, a.workdir, Path(a.cc) if a.cc else None, a.list)
    if a.list and "diff" in res:
        for tag, t, o in res["diff"]:
            print(f"{tag:8s} - {t if t else '(none)':<52s} + {o}")
        print()
        del res["diff"]
        print("hunks:", [(tag, i1, i2, j1, j2) for tag, i1, i2, j1, j2 in res.pop("hunk_list")])
    print(json.dumps(res))


if __name__ == "__main__":
    sys.exit(main())
