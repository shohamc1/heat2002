#!/usr/bin/env python3
"""Isolated compile+score tool for sub_0800D684.

Compiles a candidate .c anywhere (private workdir, no shared build/ races),
links it at 0x0800D684 with the real ROM's symbols, and reports structural
diff vs the retail bytes.

  python3 d684tool.py check FILE [--workdir DIR] [--label L] [--json] [--cc CC1] [--flag F]...
  python3 d684tool.py show  FILE START END
  python3 d684tool.py base64-diff ...

Never writes into the repo. Read-only w.r.t. src/, build/, asm/.
"""
import argparse, difflib, json, os, re, shutil, struct, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path("/Users/shohamc1/heat2002-gba")
sys.path.insert(0, str(ROOT / "scripts"))
import match as M  # noqa: E402

NAME = "sub_0800D684"
ADDR = 0x0800D684
SIZE = 2006
CFLAGS = ["-O2", "-mthumb-interwork", "-fhex-asm", "-Wimplicit", "-Wparentheses"]
CC1 = ROOT / "tools/agbcc/old_agbcc"
CPP = "cc"
CPPFLAGS = ["-I", str(ROOT / "include"), "-I", str(ROOT / "tools/agbcc/include"),
            "-iquote", str(ROOT / "include"), "-nostdinc", "-undef"]
AS = "arm-none-eabi-as"
ASFLAGS = ["-mcpu=arm7tdmi", "-mthumb-interwork", "-I", str(ROOT / "include")]
NM = "arm-none-eabi-nm"


def compile_candidate(src, workdir, cc1=CC1, cflags=None):
    workdir = Path(workdir)
    workdir.mkdir(parents=True, exist_ok=True)
    tag = re.sub(r"[^A-Za-z0-9_.-]", "_", str(src))[-60:]
    i = workdir / (tag + ".i")
    s = workdir / (tag + ".s")
    o = workdir / (tag + ".o")
    r = subprocess.run([CPP, "-E", "-x", "c"] + CPPFLAGS + [str(src), "-o", str(i)],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return None, "cpp failed:\n" + r.stderr[-3000:]
    r = subprocess.run([str(cc1)] + (cflags or CFLAGS) + [str(i), "-o", str(s)],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return None, "cc1 failed:\n" + r.stdout[-3000:] + r.stderr[-3000:]
    with open(s, "a") as f:
        f.write("\t.align 2, 0\n")
    r = subprocess.run([AS] + ASFLAGS + ["-o", str(o), str(s)],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return None, "as failed:\n" + r.stderr[-3000:]
    return o, None


def norm(s):
    s = re.sub(r"^[0-9a-f]+:\s*", "", s)
    s = re.sub(r"\[pc, #\d+\]", "[pc, #H]", s)
    s = re.sub(r"\$[0-9a-fA-F]+|0x[0-9a-fA-F]+|\b[0-9a-f]{4,}\b", "H", s)
    s = re.sub(r"\b(r\d+|sl|fp|ip|sp|lr|pc)\b", "R", s)
    return re.sub(r"\s+", " ", s).strip()


class Result:
    def __init__(self, src, obj, err, ours, target, cc1=None, cflags=None):
        self.src, self.obj, self.err = src, obj, err
        self.ours, self.target = ours, target
        self.cc1, self.cflags = cc1, cflags
        if ours is None:
            return
        self.size = len(ours)
        self.addr = ADDR
        self.td = M.disasm(target, ADDR)
        self.od = M.disasm(ours, ADDR)
        self.match = ours == target

    def hunks(self):
        tn = [norm(x) for x in self.td]
        on = [norm(x) for x in self.od]
        sm = difflib.SequenceMatcher(None, tn, on, autojunk=False)
        out = []
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag == "equal":
                continue
            if tag == "replace" and all(a == b for a, b in zip(tn[i1:i2], on[j1:j2])) \
               and (i2 - i1) == (j2 - j1):
                continue  # pure register recolour
            out.append((tag, i1, i2, j1, j2))
        return out

    def summary(self):
        if self.err:
            return {"src": str(self.src), "error": self.err[:500]}
        h = self.hunks()
        return {
            "src": str(self.src),
            "size": self.size,
            "match": self.match,
            "hunks": len(h),
            "t_extra": sum(i2 - i1 for _, i1, i2, _, _ in h),
            "o_extra": sum(j2 - j1 for _, _, _, j1, j2 in h),
            "cc1": str(self.cc1) if self.cc1 else "default",
            "cflags": self.cflags or CFLAGS,
        }

    def show(self, lo, hi, ctx=0):
        lines = []
        for k in range(max(0, lo - ctx), min(hi + ctx, len(self.td))):
            t = self.td[k]
            o = self.od[k] if k < len(self.od) else ""
            mark = " " if t.split("@")[0].strip() == o.split("@")[0].strip() else "*"
            lines.append(f"{mark}{k:4d} T {t:52s} | O {o}")
        return "\n".join(lines)


def run(src, workdir, cc1=CC1, cflags=None):
    obj, err = compile_candidate(src, workdir, cc1=cc1, cflags=cflags)
    target = M.ROM.read_bytes()[ADDR - M.ROM_BASE: ADDR - M.ROM_BASE + SIZE]
    if obj is None:
        return Result(src, None, err, None, target, cc1, cflags)
    out = subprocess.run([NM, "--print-size", str(obj)], capture_output=True, text=True).stdout
    offset = size = None
    for line in out.splitlines():
        p = line.split()
        if len(p) == 4 and p[3] == NAME:
            offset, size = int(p[0], 16), int(p[1], 16)
    if size is None:
        return Result(src, obj, "symbol not found", None, target, cc1, cflags)
    ours = M.object_bytes(obj, offset, size, ADDR)
    return Result(src, obj, None, ours, target, cc1, cflags)


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("check")
    c.add_argument("src")
    c.add_argument("--workdir", default="/tmp/d684v5/wd")
    c.add_argument("--label", default=None)
    c.add_argument("--json", action="store_true")
    c.add_argument("--cc")
    c.add_argument("--flag", action="append", default=[])
    s = sub.add_parser("show")
    s.add_argument("src")
    s.add_argument("start", type=int)
    s.add_argument("end", type=int)
    s.add_argument("--ctx", type=int, default=0)
    s.add_argument("--workdir", default="/tmp/d684v5/wd")
    a = ap.parse_args()

    if a.cmd == "check":
        r = run(a.src, a.workdir, cc1=Path(a.cc) if a.cc else CC1,
                cflags=(CFLAGS + a.flag) if a.flag else None)
        if a.label:
            r.label = a.label
        if a.json:
            print(json.dumps(r.summary()))
        else:
            print(json.dumps(r.summary(), indent=1))
            for tag, i1, i2, j1, j2 in r.hunks():
                print(f"  {tag} target[{i1}:{i2}] ours[{j1}:{j2}]")
        return 0
    if a.cmd == "show":
        r = run(a.src, a.workdir)
        if r.err or r.ours is None:
            print(r.err)
            return 1
        print(r.show(a.start, a.end, a.ctx))
        return 0


if __name__ == "__main__":
    sys.exit(main())
