#!/usr/bin/env python3
"""Address-aligned listing diff for sub_0800D684.

The listings' index pairing is meaningless once sizes differ (extra instructions
shift everything after them).  This walks both listings and aligns on the branch
targets / instruction text so the reported differences are real.

    python3 aligndiff.py FILE [--workdir DIR] [--lo 0x800db40] [--hi 0x800dba0]
"""
import argparse
import pathlib
import re
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402


def key(line):
    """Alignment key: mnemonic + operand *shape* (registers kept)."""
    b = line.split(":", 1)[-1].split("@")[0].strip()
    return re.sub(r"0x[0-9a-f]+|\b\d+\b", "#", b)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("--workdir", default="/tmp/aligndiff")
    ap.add_argument("--lo", default="800d684")
    ap.add_argument("--hi", default="800de60")
    a = ap.parse_args()
    res = D.run(a.src, a.workdir)
    if res.err or res.ours is None:
        print("compile error:", (res.err or "")[:400])
        return 1
    lo, hi = int(a.lo, 16), int(a.hi, 16)
    T = [x for x in res.td if lo <= int(x.split(":")[0], 16) <= hi]
    O = [x for x in res.od if lo <= int(x.split(":")[0], 16) <= hi]
    i = j = 0
    while i < len(T) or j < len(O):
        if i < len(T) and j < len(O) and key(T[i]) == key(O[j]):
            if T[i].split(":", 1)[1].strip() != O[j].split(":", 1)[1].strip():
                print(f"~ T {T[i]:46s} | O {O[j]}")
            i += 1
            j += 1
            continue
        # look ahead: an extra instruction on one side
        if i < len(T) and (j >= len(O) or key(T[i]) not in [key(x) for x in O[j:j + 4]]):
            print(f"- T {T[i]:46s} | (nothing)")
            i += 1
            continue
        if j < len(O) and (i >= len(T) or key(O[j]) not in [key(x) for x in T[i:i + 4]]):
            print(f"+ T {'':46s} | O {O[j]}")
            j += 1
            continue
        print(f"~ T {T[i]:46s} | O {O[j]}")
        i += 1
        j += 1
    return 0


if __name__ == "__main__":
    sys.exit(main())