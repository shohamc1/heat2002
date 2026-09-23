#!/usr/bin/env python3
"""Find copies and near-copies of already-decompiled functions among the rest.

The 0x0834 module duplicates parts of the low region with renamed globals
(sub_08343EA8 is sub_0800D684), so a large share of the remaining functions
should be near-free once their twin is matched. This script finds them by
comparing normalized instruction streams from build/rom_reference.s
(`make disasm`; the ROM itself, so decompiled and non-decompiled functions
appear in one uniform format).

Normalization per instruction, designed so a relocated copy of a function
normalizes identically to its original:
  - branch targets (_XXXXXXXX labels) -> signed offset from function start
  - pool references (ldr rN, _XXXXXXXX) -> the token P; the loaded value is
    recorded separately so we can still tell "same constants" from
    "constants moved with the module"
  - call targets (bl sub_XXXXXXXX) -> the token S
  - registers and small immediates are kept verbatim
  - .byte/.4byte rows (jump tables, stray data luvdis never decoded) -> DATA

Exact copies are grouped by this normalized stream; near matches are ranked
with difflib over the same tokens, pruned by length ratio and 3-gram overlap.

    make disasm                       # needs build/rom_reference.s
    python3 scripts/find_twins.py     # prints a markdown report
"""

import hashlib
import re
import subprocess
import sys
from difflib import SequenceMatcher
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "scripts"))
import progress  # LIBRARY_BLOCKS, LUVDIS_FALSE_POSITIVES, ARM_BLOCKS

REF = ROOT / "build" / "rom_reference.s"
PREAMBLE_END = "@ End embedded Luvdis macros"

FUNC_START = re.compile(
    r"^\s*(?:non_word_aligned_)?(thumb|arm)_func_start\s+(\S+)\s*$"
)
FUNC_END = re.compile(r"^\s*(?:non_word_aligned_)?(?:thumb|arm)_func_end\b")
BRANCH = {
    "b", "bl", "beq", "bne", "bcs", "bcc", "bmi", "bpl", "bvs", "bvc",
    "bhi", "bls", "bge", "blt", "bgt", "ble", "blx", "bx",
}
LABEL_RE = re.compile(r"\b(_[0-9A-Fa-f]{8})\b")
SYM_RE = re.compile(r"\b(sub_[0-9A-Fa-f]{8})\b")
POOL_VAL_RE = re.compile(r"@\s*=(0x[0-9A-Fa-f]+)")
DEF_RE = re.compile(
    r"^(?:__attribute__\s*\(\([^)]*\)\)\s*)?\S[^(\n;]*\b(sub_[0-9A-Fa-f]{8})\s*\([^;{]*\)\s*\{",
    re.MULTILINE,
)


def parse_reference():
    """{name: {"kind", "tokens", "pools"}} from build/rom_reference.s."""
    funcs = {}
    cur = None
    addr = 0
    with REF.open() as f:
        for line in f:
            if PREAMBLE_END in line:
                continue
            m = FUNC_START.match(line)
            if m:
                name = m.group(2)
                cur = name
                addr = int(name.split("_")[1], 16) if name.startswith("sub_") else 0
                funcs[cur] = {"kind": m.group(1), "tokens": [], "pools": [], "insns": 0}
                continue
            if FUNC_END.match(line):
                cur = None
                continue
            if cur is None:
                continue
            pool = POOL_VAL_RE.search(line)
            s = line.split("@")[0].strip()
            if not s:
                continue
            # luvdis data rows inside a function: "_08000254: .4byte 0x..." on
            # one line, or a bare "_08000254:" label. Both carry no code; the
            # label must vanish or relocated copies stop matching exactly.
            m = re.match(r"^(_[0-9A-Fa-f]{8}|[A-Za-z_]\w*):\s*(.*)$", s)
            if m:
                s = m.group(2).strip()
                if not s:
                    continue
            if s.startswith("."):
                if s.split()[0] in (".byte", ".2byte", ".short", ".4byte", ".word"):
                    funcs[cur]["tokens"].append("DATA")
                continue
            if s.endswith(":"):
                continue  # bare label (no data attached)
            mn, _, ops = s.partition(" ")
            mn = re.sub(r"\.[nw]$", "", mn)  # b.n / blx.w unified suffixes
            is_branch = mn in BRANCH and mn != "bx"

            def sub_label(m, _addr=addr, _br=is_branch):
                if _br:
                    return "%+d" % (int(m.group(1)[1:], 16) - _addr)
                return "P"

            ops = LABEL_RE.sub(sub_label, ops)
            ops = SYM_RE.sub("S", ops)
            toks = [mn] + [o for o in re.split(r",\s*(?![^\]}]*[}\]])", ops) if o]
            funcs[cur]["tokens"] += toks
            funcs[cur]["insns"] += 1
            if pool and "P" in toks:
                funcs[cur]["pools"].append(pool.group(1))
    return funcs


def nm_sizes():
    """{symbol: bytes} for every function object under build/."""
    objs = list((ROOT / "build" / "asm").glob("*.o")) + list(
        (ROOT / "build" / "src").glob("*.o")
    )
    sizes = {}
    for i in range(0, len(objs), 200):  # arg-length safety chunk
        out = subprocess.run(
            ["arm-none-eabi-nm", "--print-size", *map(str, objs[i : i + 200])],
            capture_output=True, text=True, check=False,
        ).stdout
        for line in out.splitlines():
            parts = line.split()
            if len(parts) == 4 and parts[2] in ("t", "T"):
                sizes[parts[3]] = int(parts[1], 16)
    return sizes


def trigrams(toks):
    return {tuple(toks[i : i + 3]) for i in range(len(toks) - 2)}


def main():
    funcs = parse_reference()

    decompiled = set()
    for c in (ROOT / "src").rglob("*.c"):
        decompiled.update(DEF_RE.findall(c.read_text(errors="replace")))

    non_targets = progress.LIBRARY_BLOCKS | progress.LUVDIS_FALSE_POSITIVES | progress.ARM_BLOCKS
    arm = {n for n, f in funcs.items() if f["kind"] == "arm"}
    # Only functions the project tracks as blocks in asm/*.s are work items;
    # luvdis also finds a few strays inside library-object spans.
    tracked = set(progress.parse_asm())
    strays = sorted(n for n in funcs if n not in tracked
                    and n not in decompiled and n not in non_targets and n not in arm)
    remaining = sorted(
        n for n in tracked
        if n not in decompiled and n not in non_targets and n not in arm
    )

    print(f"<!-- parsed {len(funcs)} functions; {len(decompiled)} decompiled, "
          f"{len(remaining)} remaining targets, {len(non_targets | arm)} non-targets -->")
    if strays:
        print(f"<!-- luvdis blocks not tracked by the project (skipped): "
              f"{', '.join(strays)} -->")
    for n in sorted(decompiled | non_targets):
        if n not in funcs:
            print(f"<!-- NOTE: {n} not in rom_reference.s -->")

    sizes = nm_sizes()
    def size(n):
        return sizes.get(n, funcs[n]["insns"] * 2 + len(funcs[n]["pools"]) * 2)

    tok = {n: tuple(funcs[n]["tokens"]) for n in funcs}
    hsh = {n: hashlib.md5("\n".join(tok[n]).encode()).hexdigest() for n in funcs}
    tri = {n: trigrams(tok[n]) for n in funcs}
    ln = {n: len(tok[n]) for n in funcs}

    # ---- exact structural copies ------------------------------------
    by_hash = {}
    for n in list(remaining) + sorted(decompiled):
        by_hash.setdefault(hsh[n], []).append(n)
    exact = []  # (remaining fn, [decompiled twins])
    for names in by_hash.values():
        twins = [n for n in names if n in decompiled]
        news = [n for n in names if n not in decompiled]
        for n in news:
            if twins:
                exact.append((n, twins))

    def pools_same(a, b):
        return funcs[a]["pools"] == funcs[b]["pools"]

    # ---- near matches ------------------------------------------------
    # difflib opcodes also give the number of tokens that actually differ,
    # which says more about the remaining work than the ratio does.
    near = []  # (remaining fn, best twin, ratio, differing tokens)
    done_sorted = sorted(decompiled)
    for n in remaining:
        if ln[n] < 6:  # `bx lr` stubs and the like: noise, counted separately
            continue
        best, best_r, best_d = None, 0.0, 0
        for d in done_sorted:
            if d in by_hash.get(hsh[n], []):
                continue  # already an exact copy
            la, lb = ln[n], ln[d]
            if la * 2 < lb or lb * 2 < la:
                continue
            ta, tb = tri[n], tri[d]
            if not ta or not tb:
                continue
            j = len(ta & tb) / len(ta | tb)
            if j < 0.34:
                continue
            sm = SequenceMatcher(None, tok[n], tok[d], autojunk=False)
            if sm.ratio() > best_r:
                best = d
                best_r = sm.ratio()
                best_d = sum((i2 - i1) + (j2 - j1)
                             for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != "equal")
        if best and best_r >= 0.80:
            near.append((n, best, best_r, best_d))

    # ---- remaining-vs-remaining families ------------------------------
    fam = {}
    for names in by_hash.values():
        news = [n for n in names if n not in decompiled]
        if len(news) >= 2:
            for n in news[1:]:
                fam[n] = news[0]

    tiny = [n for n in remaining if ln[n] < 6]

    # ---- report -------------------------------------------------------
    out = []
    real = [x for x in exact if ln[x[0]] >= 6]
    tiny_exact = [x for x in exact if ln[x[0]] < 6]
    out.append("# Function twins — remaining functions vs. already-decompiled ones")
    out.append("")
    out.append("Method: every function's instruction stream from `build/rom_reference.s`"
               " (the ROM itself, so decompiled and remaining functions share one"
               " format), normalized so a relocated copy matches its original:"
               " branch targets become offsets from function start, pool loads and"
               " `bl` targets are masked (pool values recorded separately),"
               " registers and small immediates kept. Validated on the known pair"
               " `sub_08343EA8`/`sub_0800D684`, which normalizes identical.")
    out.append("")
    out.append("Caveats: 'exact' means identical modulo call targets and pool"
               " constants — port the twin's C, then rename the called functions"
               " and globals it references (the high 0x0834 module keeps its own"
               " copies of both). 'moved' pool constants are the copy's own data"
               " addresses; 'same' plus exact tokens is a literal duplicate.")
    out.append("")
    out.append(f"Regenerate after any batch of matches:"
               f" `make disasm && python3 scripts/find_twins.py > docs/function-twins.md`.")
    out.append("")
    out.append(f"## Summary — {len(exact)} exact copies, {len(near)} near matches")
    out.append("")
    out.append(f"Of {len(remaining)} remaining game-code functions, "
               f"{len(exact)} are instruction-identical (modulo relocated pool/"
               f"call targets) to an already-decompiled function, and {len(near)} "
               f"are ≥80% similar. {len(tiny)} are trivial (<6 tokens).")
    if tiny_exact:
        out.append("")
        out.append(f"({len(tiny_exact)} of the exact copies are trivial stubs "
                   f"(<6 tokens), folded out of the table: "
                   + ", ".join("`%s`" % n for n, _ in tiny_exact[:8])
                   + ("…" if len(tiny_exact) > 8 else "") + ")")
    out.append("")
    out.append("## Exact copies (start here — the twin's C is nearly the whole answer)")
    out.append("")
    out.append(f"{len(real)} real exact copies ({sum(size(n) for n, _ in real)} bytes). "
               f"'moved' pool constants = the copy points at its own module's data/"
               f"globals — port the twin's C and rename the globals; 'same' = a "
               f"literal duplicate, port verbatim (check the call targets).")
    out.append("")
    out.append("| remaining | decompiled twin(s) | bytes | pool constants |")
    out.append("|---|---|---|---|")
    for n, twins in sorted(real, key=lambda x: -size(x[0])):
        same = "same" if pools_same(n, twins[0]) else "moved"
        out.append(f"| `{n}` | {', '.join('`%s`' % t for t in twins)} | {size(n)} | {same} |")
    out.append("")
    out.append("## Near matches (≥0.80 similarity, not exact)")
    out.append("")
    out.append(f"{len(near)} functions at ≥0.80 similarity, "
               f"{sum(size(n) for n, _, _, _ in near)} bytes — differing tokens is the "
               f"number of instruction/operand tokens that must change in the twin's C.")
    out.append("")
    out.append("| remaining | best twin | similarity | differing tokens | bytes |")
    out.append("|---|---|---|---|---|")
    for n, d, r, diff in sorted(near, key=lambda x: (x[3], -size(x[0]))):
        out.append(f"| `{n}` | `{d}` | {r:.2f} | {diff} | {size(n)} |")
    out.append("")
    out.append("## Families among the remaining (identical to each other)")
    out.append("")
    fam_real = {k: v for k, v in fam.items() if ln[k] >= 6}
    if fam_real:
        inv = {}
        for k, v in fam_real.items():
            inv.setdefault(v, []).append(k)
        fam_bytes = sum(size(v) for v in inv)
        out.append(f"{len(inv)} families: decompile the first column once and its "
                   f"relatives are {fam_bytes} bytes of porting, not reverse engineering.")
        out.append("")
        out.append("| decompile first | then get for near-free | bytes |")
        out.append("|---|---|---|")
        for v, ks in sorted(inv.items(), key=lambda x: -size(x[0])):
            out.append(f"| `{v}` | {', '.join('`%s`' % k for k in ks)} | {size(v)} |")
    else:
        out.append("None.")
    if tiny_exact:
        out.append("")
        out.append(f"Trivial exact-copy stubs (<6 tokens, {sum(size(n) for n, _ in tiny_exact)} bytes total): "
                   + ", ".join("`%s`" % n for n, _ in tiny_exact))
    print("\n".join(out))


if __name__ == "__main__":
    main()
