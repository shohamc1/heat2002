#!/usr/bin/env python3
"""Force reload scratch sets in the instrumented cc1 and score the result.

Usage: RT_ADDSET=4 python3 forcecheck.py SRC [--cc PATH] [--workdir DIR]
       python3 forcecheck.py SRC --set 012346      (equivalent to RT_SET=012346)

The env override only takes effect inside cc1, so it must be set for the compile
subprocess; this drives the same cpp -> cc1 -> as -> link pipeline as
d684tool.py but keeps the environment (d684tool's caller env is not inherited by
its subprocesses when we mutate os.environ after import).
"""
import argparse
import os
import pathlib
import subprocess
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import d684tool as D  # noqa: E402
import filediff as F  # noqa: E402


def build(src, workdir, extra_env, cc1):
    d = pathlib.Path(workdir)
    d.mkdir(parents=True, exist_ok=True)
    i = d / "c.i"
    s = d / "c.s"
    o = d / "c.o"
    env = dict(os.environ)
    env.update(extra_env)
    r = subprocess.run([D.CPP, "-E", "-x", "c"] + D.CPPFLAGS + [str(src), "-o", str(i)],
                       capture_output=True, text=True, env=env)
    assert r.returncode == 0, r.stderr[-2000:]
    r = subprocess.run([str(cc1)] + D.CFLAGS + [str(i), "-o", str(s)],
                       capture_output=True, text=True, env=env)
    assert r.returncode == 0, (r.stdout + r.stderr)[-2000:]
    with open(s, "a") as f:
        f.write("\t.align 2, 0\n")
    r = subprocess.run([D.AS] + D.ASFLAGS + ["-o", str(o), str(s)],
                       capture_output=True, text=True, env=env)
    assert r.returncode == 0, r.stderr[-2000:]
    return o


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("--cc", default=str(D.CC1))
    ap.add_argument("--workdir", default="/tmp/forcecheck")
    ap.add_argument("--set", default=None)
    ap.add_argument("--addset", default=None)
    ap.add_argument("--delset", default=None)
    a = ap.parse_args()
    env = {}
    if a.set is not None:
        env["RT_SET"] = a.set
    if a.addset is not None:
        env["RT_ADDSET"] = a.addset
    if a.delset is not None:
        env["RT_DELSET"] = a.delset
    wd = pathlib.Path(a.workdir)
    o = build(a.src, wd, env, a.cc)
    target = D.M.ROM.read_bytes()[D.ADDR - D.M.ROM_BASE: D.ADDR - D.M.ROM_BASE + D.SIZE]
    out = subprocess.run([D.NM, "--print-size", str(o)], capture_output=True, text=True).stdout
    offset = size = None
    for line in out.splitlines():
        p = line.split()
        if len(p) == 4 and p[3] == D.NAME:
            offset, size = int(p[0], 16), int(p[1], 16)
    assert size is not None, "symbol not found"
    ours = D.M.object_bytes(o, offset, size, D.ADDR)
    res = D.Result(str(a.src), o, None, ours, target)
    print(f"size={res.size} hunks={len(res.hunks())} sdiff={F.score_of(res)} env={env}")
    for tag, i1, i2, j1, j2 in res.hunks():
        print(f"  {tag:8s} T[{i1}:{i2}] O[{j1}:{j2}]  ~0x{D.ADDR + 2*i1:x}")


if __name__ == "__main__":
    main()