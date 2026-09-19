#!/usr/bin/env python3
"""Sweep single self-store/re-read 'dials' across every statement boundary.

Each dial is a semantically neutral perturbation (X = X; / a redundant re-read)
inserted before one statement. The point is not the inserted code itself: it
perturbs liveness, register allocation and reload's rotating spill-register
counter, which is what couples the remaining hunks.

  python3 dials.py --base FILE --out JSONL [-j 8] [--region LO HI]
  python3 dials.py --base FILE --pairs JSONL_OF_BEST [-j 8]
"""
import argparse, json, os, subprocess, sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

TOOL = str(Path(__file__).resolve().parent / "d684tool.py")

DIALS = [
    ("a1_175", "    a1->unk175 = a1->unk175;\n"),
    ("curs_175", "    cursor->unk175 = cursor->unk175;\n"),
    ("cc_b", "    (*cc).b = (*cc).b;\n"),
    ("cc_d", "    (*cc).d = (*cc).d;\n"),
    ("k2_k2", "    k2 = k2;\n"),
    ("k1_k1", "    k1 = k1;\n"),
    ("k3_k3", "    k3 = k3;\n"),
    ("d1_d1", "    d1 = d1;\n"),
    ("d0_d0", "    d0 = d0;\n"),
    ("edgeq_eq", "    edgeq = edgeq;\n"),
    ("e_e", "    e = e;\n"),
    ("w_w", "    w = w;\n"),
    ("u_u", "    u = u;\n"),
    ("flag_flag", "    flag = flag;\n"),
    ("i_i", "    i = i;\n"),
    ("a2_a2", "    a2 = a2;\n"),
    ("ccd_ccd", "    ccd = ccd;\n"),
    ("v1hold_hold", "    v1hold = v1hold;\n"),
    ("pa_pa", "    pa = pa;\n"),
    ("pb_pb", "    pb = pb;\n"),
    ("cc_cc", "    cc = cc;\n"),
]


def statements(src):
    """(line_index, indent) for every line that starts a statement in the body."""
    out = []
    for i, line in enumerate(src.splitlines()):
        s = line.strip()
        if not s or s.startswith(("/*", "*", "//", "#", "}")):
            continue
        if i < 600:          # keep to the function body (header comment is above)
            continue
        if s.endswith(";") or s.endswith("{") or s.endswith(")"):
            out.append(i)
    return out


def build(base_lines, insert_at, dial_text):
    return "\n".join(base_lines[:insert_at] + [dial_text.rstrip("\n")] + base_lines[insert_at:]) + "\n"


def work(job):
    idx, src, label, outdir = job
    d = Path(outdir) / f"d{idx}"
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(src)
    r = subprocess.run(["python3", TOOL, "check", str(f), "--workdir", str(d), "--json"],
                       capture_output=True, text=True)
    try:
        res = json.loads(r.stdout.strip().splitlines()[0])
    except Exception:
        return {"idx": idx, "label": label, "error": (r.stdout + r.stderr)[-160:]}
    res["label"] = label
    res["file"] = str(f)
    return res


def best_from(path):
    out = []
    for line in open(path):
        try:
            r = json.loads(line)
        except Exception:
            continue
        if r.get("hunks") is not None:
            out.append(r)
    out.sort(key=lambda r: (r["hunks"], abs(r["size"] - 2006)))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--outdir", default="/tmp/d684v5/dials")
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--region", default=None, help="LO:HI line range")
    ap.add_argument("--pairs", default=None, help="jsonl of singles to pair up")
    ap.add_argument("--top", type=int, default=12)
    a = ap.parse_args()

    src = Path(a.base).read_text()
    lines = src.splitlines()
    jobs = []
    if a.pairs:
        tops = best_from(a.pairs)[: a.top]
        print("pairing", len(tops), "singles", flush=True)
        for i, r1 in enumerate(tops):
            for j, r2 in enumerate(tops):
                if j <= i:
                    continue
                s1 = Path(r1["file"]).read_text().splitlines()
                s2 = Path(r2["file"]).read_text().splitlines()
                # both are the base with one dial appended; combine by diffing line counts
                if len(s1) > len(s2):
                    s1, s2 = s2, s1
                # merge: take s1 (shorter = base+1 dial) then append the dial line from s2
                extra = [l for l in s2 if l not in s1] or [l for l in s1 if l not in s2]
                merged = s1 + extra[:1]
                jobs.append((len(jobs), "\n".join(merged) + "\n", f"{r1['label']}+{r2['label']}", a.outdir))
    else:
        lo, hi = 0, 10 ** 9
        if a.region:
            lo, hi = (int(x) for x in a.region.split(":"))
        for ln in statements(src):
            if not (lo <= ln <= hi):
                continue
            for name, dial in DIALS:
                jobs.append((len(jobs), build(lines, ln, dial), f"L{ln + 1}:{name}", a.outdir))
    print(f"{len(jobs)} dial variants", flush=True)
    best = []
    with open(a.out, "a") as log, ProcessPoolExecutor(max_workers=a.j) as ex:
        for res in ex.map(work, jobs, chunksize=4):
            log.write(json.dumps(res) + "\n")
            log.flush()
            h = res.get("hunks")
            if h is not None and h <= 6:
                best.append(res)
                if h < 6:
                    print(f"*** {h} hunks size={res['size']} {res['label']} {res['file']}", flush=True)
    best.sort(key=lambda r: (r["hunks"], abs(r["size"] - 2006)))
    print(f"improved (<=6): {len(best)}")
    for r in best[:a.top]:
        print(f"  {r['hunks']} hunks size={r['size']} t+{r['t_extra']} o+{r['o_extra']} {r['label']}")


if __name__ == "__main__":
    sys.exit(main())
