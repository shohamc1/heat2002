#!/usr/bin/env python3
"""Count the extern declarations in src/ and list symbols declared with more
than one type. Parameter names and whitespace don't count as a difference.

With --check, print only the symbols that more than one file declares
locally, and exit 1 if there are any.

Run from the repository root."""
import collections
import glob
import re
import sys

EXTERN = re.compile(r"^[ \t]*extern\s+(.*?);", re.S | re.M)


def parse(decl):
    decl = re.sub(r"/\*.*?\*/|//[^\n]*", "", decl)
    decl = re.sub(r"\s+", " ", decl).strip()
    func = re.match(r"(.*?)\b(\w+)\s*\((.*)\)$", decl)
    if func and not re.search(r"\(\s*\*", decl):
        ret, name, args = func.groups()
        params = []
        for p in args.split(","):
            p = p.strip()
            if len(p.split()) > 1 or "*" in p:
                p = re.sub(r"\b\w+$", "", p) if re.search(r"[\w*]\s*\w+$", p) \
                    and not re.fullmatch(r"(const |volatile )*\w+", p) else p
            params.append(p.replace(" ", ""))
        return "function", name, f"{ret.strip()}({','.join(params)})"
    ptr = re.search(r"\(\s*\*\s*(\w+)", decl)
    name = ptr.group(1) if ptr else re.findall(r"(\w+)\s*(?:\[[^\]]*\]\s*)*$", decl)[-1]
    return "variable", name, re.sub(rf"\b{name}\b", "X", decl)


lines = 0
types = collections.defaultdict(collections.Counter)
files = collections.defaultdict(set)
for path in glob.glob("src/**/*.c", recursive=True):
    text = open(path, errors="replace").read()
    for m in EXTERN.finditer(text):
        lines += 1
        kind, name, sig = parse(m.group(1))
        types[kind, name][sig] += 1
        files[kind, name].add(path)

shared = sorted(k[1] for k in files if len(files[k]) > 1)
if "--check" in sys.argv:
    for name in shared:
        print(f"{name} is declared in more than one file; move it to a header")
    sys.exit(1 if shared else 0)

print(f"extern lines: {lines}")
for kind in ("function", "variable"):
    syms = [k for k in types if k[0] == kind]
    clash = sorted((k for k in syms if len(types[k]) > 1),
                   key=lambda k: -len(files[k]))
    many = sum(1 for k in syms if len(files[k]) > 1)
    print(f"\n{kind}s: {len(syms)} unique, {many} in more than one file, "
          f"{len(clash)} with conflicting types")
    for k in clash:
        print(f"  {k[1]} ({len(files[k])} files): "
              + "; ".join(f"{s} x{n}" for s, n in types[k].most_common()))
