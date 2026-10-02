#!/usr/bin/env python3
"""Move local extern declarations into shared headers.

Removes extern declarations from src/**/*.c and adds the #include lines that
replace them. Which declarations to remove is decided by the current phase
and spelled out in a plan file, one entry per line:

    <header> <symbol>

`header` is the include path as it appears in the #include line (functions.h,
m4a.h, data.h, ...). `symbol` is the declared name. Blank lines and lines
starting with # are ignored.

A declaration line is removed when every declarator on it is in the plan
(extern u8 gA[], gB[]; loses both names). If only some declarators are
covered the line is rewritten to keep the rest, and the rewrite is printed
so it can be checked by hand. The trailing comment of a removed line goes
too; the header that replaces it keeps the address comment.

The #include lines are added after the file's last existing #include line
(the include block is at the top of every file in src/), or at the top of
the file when it has none, once per header per file.

Default is a dry run. --apply rewrites the files.

Assumes the corpus shapes verified on 2026-09-27: every extern in src/ is a
single line starting at column 0, none has a comment line attached above it,
and none spans several lines.
"""
import argparse
import glob
import os
import re
import sys

EXTERN_LINE = re.compile(r"^extern\b([^;]*);(.*)$")

# A declarator is a name optionally followed by array suffixes. Parenthesised
# declarators (function prototypes, function pointers) are handled before it.
VAR_DECL = re.compile(r"(\w+)\s*(?:\[[^\]]*\])*\s*$")
FUNC_PTR = re.compile(r"\(\s*\*\s*(\w+)")


def split_top_level(text):
    """Split on commas at paren/bracket depth 0, stripped."""
    parts, depth, cur = [], 0, []
    for ch in text:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    parts.append("".join(cur).strip())
    return [p for p in parts if p]


def declarator_name(chunk):
    """The name a declarator chunk declares, and the span it occupies."""
    m = FUNC_PTR.search(chunk)
    if m:
        return m.group(1), m.span()
    if chunk.endswith(")") and "(" in chunk:
        # Function prototype: the identifier before the first paren.
        m = re.search(r"(\w+)\s*\(", chunk)
        if m:
            # The span covers the whole prototype from the name on.
            return m.group(1), (m.start(1), len(chunk))
    m = VAR_DECL.search(chunk)
    if m:
        return m.group(1), m.span()
    return None, None


def process_line(line, plan):
    """Return (new_line_or_None, removed_names).

    new_line is None when the whole declaration is removed. When only some
    declarators are covered (extern u8 a[], b[]; keeping only b) the line is
    rewritten; chunk 0 carries the base type, later chunks are bare
    declarators sharing it.
    """
    m = EXTERN_LINE.match(line)
    if not m:
        return line, []
    chunks = split_top_level(m.group(1))
    parsed = [declarator_name(c) for c in chunks]
    if any(name is None for name, _ in parsed):
        return line, []
    covered = [n for _, (n, _) in zip(chunks, parsed) if n in plan]
    kept = [(c, span) for c, (n, span) in zip(chunks, parsed)
            if n not in plan]
    if not covered:
        return line, []
    if not kept:
        return None, covered
    if chunks[0] not in [c for c, _ in kept]:
        base = chunks[0][:parsed[0][1][0]].strip()
        texts = [base + " " + c for c, _ in kept]
    else:
        texts = [c for c, _ in kept]
    return "extern " + ", ".join(texts) + ";", covered


def insert_includes(lines, headers):
    """Insert #include lines after the last include, or at the top."""
    idx = [i for i, l in enumerate(lines) if l.startswith("#include")]
    at = idx[-1] + 1 if idx else 0
    for h in reversed(headers):
        lines.insert(at, f'#include "{h}"')


# A local (non-extern) prototype of a plan symbol: type tokens, the name,
# a parameter list, and a semicolon. Keyword-led statements (return Foo();)
# and static declarations are excluded by what may precede the name.
LOCAL_PROTO = re.compile(
    r"^[ \t]*(?:const[ \t]+|volatile[ \t]+|unsigned[ \t]+"
    r"|struct[ \t]+\w+[ \t]+|[A-Za-z_]\w*[ \t\*]+)+\*?\s*"
    r"(\w+)[ \t]*\([^;]*\)[ \t]*;[ \t]*$")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("plan_file")
    ap.add_argument("--apply", action="store_true",
                    help="rewrite files (default: dry run)")
    ap.add_argument("--root", default=".",
                    help="repository root (for tests on a copy)")
    args = ap.parse_args()

    plan = {}
    order = []
    with open(args.plan_file) as f:
        for ln in f:
            ln = ln.strip()
            if not ln or ln.startswith("#"):
                continue
            header, symbol = ln.split(None, 1)
            symbol = symbol.strip()
            plan[symbol] = header
            order.append(header)

    seen = set()
    n_files = n_removed = n_rewrites = 0
    for path in sorted(glob.glob(os.path.join(args.root, "src", "**", "*.c"),
                                 recursive=True)):
        with open(path, errors="replace") as f:
            lines = f.read().split("\n")
        out, removed, touched, rewrites = [], [], set(), []
        for line in lines:
            new, gone = process_line(line, plan)
            # also drop local (non-extern) prototypes of plan symbols
            if new == line and not re.match(r"^\s*(extern|static)\b", line) \
                    and not line.lstrip().startswith(
                        ("return ", "else ", "case ", "goto ", "do ",
                         "sizeof ")):
                m = LOCAL_PROTO.match(line)
                if m and m.group(1) in plan:
                    seen.add(m.group(1))
                    touched.add(plan[m.group(1)])
                    removed.append(m.group(1))
                    continue
            removed += gone
            seen.update(gone)
            touched.update(plan[n] for n in gone)
            if new is None:
                continue
            if new != line:
                rewrites.append((line, new))
                n_rewrites += 1
            out.append(new)
        if not removed:
            continue
        n_files += 1
        n_removed += len(removed)
        have = {l.split('"')[1] for l in lines
                if l.startswith("#include ") and '"' in l}
        # Plan-file order, so the author controls where each include lands.
        to_add = [h for h in dict.fromkeys(order)
                  if h in touched and h not in have]
        if to_add:
            insert_includes(out, to_add)
        print(f"{'APPLY ' if args.apply else 'DRY   '}{path}: "
              f"-{len(removed)} decl, +{to_add or 'no'} include")
        for old, new in rewrites:
            print(f"  rewrite: {old.strip()}\n        -> {new.strip()}")
        if args.apply:
            with open(path, "w") as f:
                f.write("\n".join(out))

    missing = sorted(set(plan) - seen)
    print(f"\n{n_files} files, {n_removed} declarations "
          f"{'removed' if args.apply else 'would be removed'}, "
          f"{n_rewrites} partial rewrites")
    if missing:
        print("symbols in the plan that matched no extern declaration:")
        for s in missing:
            print(f"  {s}")
        sys.exit(1)


if __name__ == "__main__":
    main()
