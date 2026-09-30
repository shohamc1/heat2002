#!/usr/bin/env python3
"""Count the extern declarations in src/ and list symbols declared with more
than one type. Parameter names and whitespace don't count as a difference.

Plain file-scope prototypes (not spelled with `extern`) are recognized too,
and so is what every header in include/ declares. A local declaration whose
normalized signature matches a header's is redundant -- the header can be
made visible with an include, and the local line deleted. A local
declaration whose signature differs from the header's is a deliberate
struct-view prototype (AGENTS.md, "Files, folders, and names") and is left
alone.

With --check, print only the violations -- extern symbols that more than
one file declares locally, and local declarations that a header already
declares -- and exit 1 if there are any.

Known gaps: only single-line prototypes are recognized, and parse()'s
normalization predates the header rule, so an exotic duplicate (a
multi-line prototype, say) can slip by.

Run from the repository root."""
import collections
import glob
import re
import sys

EXTERN = re.compile(r"^[ \t]*extern\s+(.*?);", re.S | re.M)

# A plain file-scope prototype: `void foo(u32 x);`, `struct Bar *baz(void);`.
# The return type may hold only words, spaces and `*`, and must hold a word:
# that keeps macro calls like ASM_FUNC(...) out, and indented call statements
# `    foo(x);` too, because the callee leaves no word for the name group.
# Keyword statements are excluded up front: `return f(x, y);` and a
# `register ... asm("r1");` pin would otherwise parse as prototypes. The
# lookaheads lead the line, so they cannot be sidestepped by indentation.
PROTO = re.compile(
    r"^(?![ \t]*(?:static|typedef|return|register)\b)(?![ \t]*#)(?![^\n]*[={])"
    r"[ \t]*([\w \t*]*\w[\w \t*]*?)\b(\w+)[ \t]*\((.*)\)[ \t]*;[ \t]*$",
    re.M)


def parse(decl):
    decl = re.sub(r"/\*.*?\*/|//[^\n]*", "", decl)
    decl = re.sub(r"\s+", " ", decl).strip()
    # A pointer to be declared names itself right after the first `(`;
    # a function whose parameter happens to be a pointer does not.
    func = re.match(r"(.*?)\b(\w+)\s*\((.*)\)$", decl)
    if func and not re.match(r"^[^(]*\(\s*\*", decl):
        ret, name, args = func.groups()
        params = []
        for p in args.split(","):
            p = p.strip()
            p = re.sub(r"\b\w+(\s*\[[^\]]*\])$", r"\1", p)
            if len(p.split()) > 1 or "*" in p:
                p = re.sub(r"\b\w+$", "", p) if re.search(r"[\w*]\s*\w+$", p) \
                    and not re.fullmatch(r"(const |volatile )*\w+", p) else p
            params.append(p.replace(" ", ""))
        return "function", name, f"{ret.strip()}({','.join(params)})"
    ptr = re.search(r"\(\s*\*\s*(\w+)", decl)
    name = ptr.group(1) if ptr else re.findall(r"(\w+)\s*(?:\[[^\]]*\]\s*)*$", decl)[-1]
    return "variable", name, re.sub(rf"\b{name}\b", "X", decl)


def declarations(path):
    """The file's extern declarations and plain prototypes, as two lists of
    (kind, name, signature) tuples with the signature parse() normalizes."""
    text = re.sub(r"/\*.*?\*/|//[^\n]*", "",
                  open(path, errors="replace").read(), flags=re.S)
    externs = [parse(m.group(1)) for m in EXTERN.finditer(text)]
    protos = [parse(f"{m.group(1)}{m.group(2)}({m.group(3)})")
              for m in PROTO.finditer(text)]
    return externs, protos


# What the headers declare: name -> (signature, header) pairs.
headers = collections.defaultdict(set)
for path in glob.glob("include/**/*.h", recursive=True):
    for kind, name, sig in sum(declarations(path), []):
        headers[name].add((sig, path))

lines = 0
prototypes = 0
types = collections.defaultdict(collections.Counter)
files = collections.defaultdict(set)
shadowed = set()
for path in glob.glob("src/**/*.c", recursive=True):
    externs, protos = declarations(path)
    lines += len(externs)
    prototypes += len(protos)
    for kind, name, sig in externs:
        types[kind, name][sig] += 1
        files[kind, name].add(path)
    # Dead files are frozen (AGENTS.md, "Ignore everything in src/dead/"):
    # they cannot be edited to satisfy the header rule, so it skips them.
    if path.startswith("src/dead/"):
        continue
    for kind, name, sig in externs + protos:
        for header_sig, header in sorted(headers.get(name, ())):
            if header_sig == sig:
                shadowed.add((path, name, header))
                break

shared = sorted(k[1] for k in files if len(files[k]) > 1)
if "--check" in sys.argv:
    for name in shared:
        print(f"{name} is declared in more than one file; move it to a header")
    for path, name, header in sorted(shadowed):
        print(f"{name} is declared locally in {path} but {header} already "
              f"declares it; include {header}, then delete the local "
              f"declaration")
    sys.exit(1 if shared or shadowed else 0)

print(f"extern lines: {lines}, plain prototypes: {prototypes}")
print(f"declarations a header already declares: {len(shadowed)}")
for path, name, header in sorted(shadowed):
    print(f"  {path}: {name} ({header})")
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
