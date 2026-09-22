#!/usr/bin/env python3
"""Extract one or more matched functions from the asm fragments.

For each function, delete its block (instructions + its own literal pool +
any `.byte 0x00, 0x00` alignment pad directly before the pool) from the asm
fragment, keep all trailing data, and create the new fragment so the removed
bytes are exactly replaced by the compiled C object.

Usage:
    python3 scripts/extract.py NAME...          # extract listed functions
    python3 scripts/extract.py --plan           # show what would be cut

luvdis block layout, in order:
    thumb_func_start NAME        <- START
    NAME:                        (label)
    <instructions>               (bl = 4 bytes, everything else 2)
    [.byte 0x00, 0x00]           (2-byte pad, only when a pool follows)
    [.global _X / _X: .4byte]*   (literal pool entries, single-line form)
    <trailing data>              (.byte rows, labels -- NOT the function's)
    next thumb_func_start

The function's own bytes are instructions + pad + pool. Trailing data
survives and starts the new fragment. A pad row with NO pool after it stays
at the head of the new fragment: the linker/assembler zero-fill reproduces
those 2 bytes either way, and keeping the cut at instruction granularity
makes the size check exact (nm size = code + pool, no pad).

Safety: refuses a function whose instructions reference labels defined
outside its block, or whose defined labels are referenced from outside
(shared pools: the two known pairs must be decompiled together or not at
all). Refuses any cut whose byte count disagrees with the compiled object's
symbol size.

ldscript.ld is NOT touched -- the caller wires placement.
"""

import re
import sys
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PREAMBLE_END = "@ End embedded Luvdis macros"

PAD_RE = re.compile(r"\t\.byte 0x00, 0x00\s*$")
SHORT_RE = re.compile(r"\t\.short( 0x[0-9a-f]{4})(, 0x[0-9a-f]{4})*\s*$")
GLOBAL_RE = re.compile(r"\t\.global\s+(_[0-9A-F]{8})\s*$")
POOL_ENTRY_RE = re.compile(r"(_[0-9A-F]{8}):\s*\.4byte\s")
FUNC_START_RE = re.compile(r"\t(non_word_aligned_)?(thumb|arm)_func_start\s")
LABEL_DEF_RE = re.compile(r"(_[0-9A-F]{8}):")


def is_ins(l):
    """A rendered instruction line (mnemonic, not a directive)."""
    return bool(re.match(r"\t[a-z][a-z0-9]*\s", l)) and not re.match(r"\t\.", l)

def refd_labels_in_line(l):
    """_XXXXXXXX labels used as operands, `_`-prefixed. Left boundary
    excludes `sub_080...` (the `_` inside `sub_` follows a word char), so
    `bl` targets stay out of the pool-sharing analysis."""
    return {m.group(0) for m in re.finditer(r"(?<![A-Za-z0-9_])_[0-9A-F]{8}(?![0-9A-F])", l)}


def ins_bytes(l):
    """Thumb instruction size: bl (and blx imm) are 32-bit, the rest 16-bit."""
    if re.match(r"\t(bl|blx)\s", l):
        return 4
    return 2


def fragments():
    return sorted(ROOT.glob("asm/*.s"))


def read_preamble():
    """The macro preamble, verbatim, from any fragment."""
    for f in fragments():
        lines = f.read_text().splitlines()
        for i, l in enumerate(lines):
            if l.strip() == PREAMBLE_END:
                return lines[: i + 1]
    raise SystemExit("no preamble found in any fragment")


def referenced_labels(lines, lo, hi):
    """Labels used as POOL/branch operands within [lo,hi) that would break
    if this block is extracted.

    `bl _XXX` to a moved .global label emits R_ARM_THM_CALL and resolves
    at link time -- exempt. PC-relative `ldr rN, _XXX` pool loads and
    b-family branches to _XXXXXXXX labels are real hazards: the
    assembler computes their offsets inside one object, and `b` also has
    a +/-2KB range that cannot cross object boundaries. Verified
    2026-09-09: cross-block b-style label branches exist only inside
    sub_08026DB6 (misclassified PCM data, never extracted), but the
    b-family is kept in the flagged set so a future extraction near
    misclassified data fails loudly instead of silently.
    """
    refs = set()
    for l in lines[lo:hi]:
        if not is_ins(l):
            continue
        m = re.match(r"\t(\w+)", l)
        if not m:
            continue
        mn = m.group(1)
        # bl/blx emit link-time relocations and are exempt (ble/bls/blt
        # are conditional BRANCHES, not bl forms).
        if not (mn == "ldr" or (mn.startswith("b") and mn not in ("bl", "blx"))):
            continue
        refs.update(refd_labels_in_line(l))
    return refs


def defined_labels(lines, lo, hi):
    """_XXXXXXXX labels defined in [lo,hi), any line form (label-only or
    single-line `label: .4byte` pool entries)."""
    d = set()
    for l in lines[lo:hi]:
        m = LABEL_DEF_RE.match(l)
        if m:
            d.add(m.group(1))
    return d


def find_block(lines, name):
    """Return (start, cut_end, nxt) or None if not in this fragment."""
    start = None
    for i, l in enumerate(lines):
        if re.match(r"\t(non_word_aligned_)?thumb_func_start " + re.escape(name) + r"$", l):
            start = i
            break
    if start is None:
        return None

    nxt = len(lines)
    for i in range(start + 1, len(lines)):
        if FUNC_START_RE.match(lines[i]):
            nxt = i
            break

    last_ins = None
    for i in range(start, nxt):
        if is_ins(lines[i]):
            last_ins = i
    if last_ins is None:
        raise SystemExit(f"{name}: no instructions found")

    # Compute the function's maximal extent: instructions + [pad] +
    # own literal-pool entries (labels referenced by the instructions,
    # in `.global X / X: .4byte` single-line form). Mid-body pools are
    # already inside the instruction span, so the tail scan only ever
    # appends. The caller then trims/extends this against the compiled
    # object's symbol size (ground truth for what the C occupies).
    refs = referenced_labels(lines, start, last_ins + 1)
    j = last_ins + 1
    if j < nxt and PAD_RE.match(lines[j]):
        j += 1
    while j < nxt:
        l = lines[j]
        m = GLOBAL_RE.match(l)
        if m and j + 1 < nxt:
            nxt_lbl = POOL_ENTRY_RE.match(lines[j + 1])
            if nxt_lbl and nxt_lbl.group(1) in refs:
                j += 2
                continue
        pm = POOL_ENTRY_RE.match(l)
        if pm and pm.group(1) in refs:
            j += 1
            continue
        break
    return start, j, nxt


def block_bytes(lines, start, cut_end, name):
    """Byte size of the cut, and its pad-row count. Aborts on surprises."""
    n = 0
    pads = 0
    for l in lines[start:cut_end]:
        if FUNC_START_RE.match(l) or GLOBAL_RE.match(l):
            continue
        if re.match(r"^[A-Za-z_][A-Za-z0-9_]*:\s*$", l) or POOL_ENTRY_RE.match(l):
            if POOL_ENTRY_RE.match(l):
                n += 4
            continue
        if PAD_RE.match(l):
            n += 2
            pads += 1
            continue
        if SHORT_RE.match(l):
            # raw halfword data inside a repaired block (a luvdis .byte run
            # redisassembled by the RAM-module repair tooling)
            n += 2 * l.count("0x")
            continue
        if is_ins(l):
            n += ins_bytes(l)
            continue
        if re.match(r"\t\.byte", l):
            raise SystemExit(f"{name}: trailing .byte data inside cut: {l!r}")
        raise SystemExit(f"{name}: unrecognized line in cut: {l!r}")
    return n, pads


def object_size(name):
    """Symbol size of the compiled function from build/src/NAME.o."""
    out = subprocess.run(
        ["arm-none-eabi-nm", "--print-size", str(ROOT / "build" / "src" / f"{name}.o")],
        capture_output=True, text=True, check=False,
    ).stdout
    for line in out.splitlines():
        p = line.split()
        if len(p) == 4 and p[3] == name:
            return int(p[1], 16)
    raise SystemExit(f"{name}: not found in build/src/{name}.o -- match it first")


def extract_one(name, plan=False):
    for f in fragments():
        lines = f.read_text().splitlines()
        blk = find_block(lines, name)
        if blk is None:
            continue
        start, cut_end, nxt = blk

        # Shared-pool guard, dangerous direction only: another block's
        # instructions reaching into this cut (or this cut's labels being
        # loaded from elsewhere) would leave a dangling PC-relative
        # reference. A function that merely *references* an outside label
        # is fine: its C replaces that load with a symbols.ld symbol.
        block_defs = defined_labels(lines, start, nxt)
        outside_refs = referenced_labels(lines, 0, start) | referenced_labels(lines, nxt, len(lines))
        shared = block_defs & outside_refs
        if shared:
            raise SystemExit(f"{name}: SHARED POOL {sorted(shared)} -- cannot extract alone")

        size = object_size(name)
        addr = int(name[4:], 16)
        # Trim trailing pad rows off the maximal extent until the cut
        # matches the object's symbol size exactly. The object's size is
        # ground truth for the bytes the C occupies; a trailing pad that
        # the object doesn't cover is inter-function gap and stays in the
        # next fragment (linker zero-fill reproduces it).
        while True:
            n_bytes, pads = block_bytes(lines, start, cut_end, name)
            if n_bytes == size:
                break
            if n_bytes == size + 2 and cut_end > start and PAD_RE.match(lines[cut_end - 1]):
                cut_end -= 1  # trailing pad is gap, leave it to fragment B
                continue
            if plan:
                print(
                    f"{name}: {f.name} lines {start+1}..{cut_end}, "
                    f"{n_bytes} bytes vs object {size} bytes -> SIZE MISMATCH"
                )
                return
            raise SystemExit(
                f"{name}: size mismatch: cut {n_bytes} bytes "
                f"vs object {size} bytes -- ABORT"
            )
        if plan:
            print(f"{name}: {f.name} lines {start+1}..{cut_end}, {n_bytes} bytes (object {size}) OK")
            return

        new_addr = addr + n_bytes
        b_name = f"rom_{new_addr:08X}.s"
        b_path = ROOT / "asm" / b_name
        if b_path.exists() and f.name != b_name:
            raise SystemExit(f"asm/{b_name} already exists -- refusing to overwrite")

        preamble = read_preamble()
        # The 2 gap bytes after a function ending 2-mod-4 must not start
        # fragment B: B's section aligns to 4, which would shift every
        # later address by +2. Drop a leading pad row, or strip the leading
        # `0x00, 0x00` from a merged data row (luvdis folds the pad into
        # the next .byte run). The object's own trailing align-fill covers
        # the gap bytes.
        tail = lines[cut_end:]
        rom = (ROOT / "baserom.gba").read_bytes()
        if new_addr % 4 == 2:
            gap = rom[new_addr - 0x8000000 : new_addr - 0x8000000 + 2]
            if gap != b"\x00\x00":
                raise SystemExit(
                    f"{name}: gap bytes at {new_addr:#x} are {gap.hex()} "
                    f"(not zero) -- unextractable alone"
                )
            if tail and PAD_RE.match(tail[0]):
                tail = tail[1:]
            elif tail:
                m0 = re.match(r"\t\.byte 0x00, 0x00, (.*)$", tail[0])
                if m0:
                    tail[0] = f"\t.byte {m0.group(1)}"
                else:
                    raise SystemExit(
                        f"{name}: fragment would start at {new_addr:#x} (2-mod-4) "
                        f"with non-fillable content {tail[0]!r} -- unextractable alone"
                    )
        head = lines[:start]
        pre_n = len(read_preamble())
        if any(l.strip() for l in head[pre_n:]):
            (ROOT / f).write_text("\n".join(head) + "\n")
        else:
            (ROOT / f).unlink()
            print(f"{f.name}: emptied by the cut, removed")
        if not any(l.strip() for l in tail):
            # Nothing follows the function in this fragment: writing B would
            # emit a preamble-only .s assembling to zero bytes -- dead weight
            # in the build and in ldscript.ld.
            print(f"{name}: extracted from {f.name} (no tail, no new fragment)")
            return
        b_path.write_text("\n".join(preamble + tail) + "\n")
        print(f"{name}: extracted from {f.name} -> asm/{b_name}")
        return
    raise SystemExit(f"{name}: not found in any fragment")


def main():
    args = sys.argv[1:]
    if not args:
        raise SystemExit(__doc__)
    plan = "--plan" in args
    for name in [a for a in args if not a.startswith("--")]:
        extract_one(name, plan=plan)


if __name__ == "__main__":
    main()
