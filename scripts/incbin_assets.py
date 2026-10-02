#!/usr/bin/env python3
"""Replace extracted data assets' `.byte` rows in an asm fragment with
`.incbin` lines.

The rewrite uses these checks:

1. Map every line of the fragment to its ROM address, starting from the
   address in the fragment's name. `.byte` rows are one byte per value,
   `.2byte`/`.4byte` are 2 and 4, `bl`/`blx` are 4 and every other
   instruction is 2, `thumb_func_start` aligns to 4, and labels, `.global`,
   `.thumb` and `non_word_aligned_thumb_func_start` take no space. An
   `.incbin` line already present takes the byte size its asset lists.
2. Check every `_XXXXXXXX:` and `sub_XXXXXXXX:` label against its computed
   address. Any disagreement means the map is wrong, so stop.
3. Split a `.byte` row when an asset boundary falls inside it.
4. A label inside a removed range must be referenced nowhere else (the
   other asm fragments, src/*.c, ldscript.ld, symbols.ld) before it may
   leave; a referenced one stops the rewrite.
5. Write `.incbin "build/assets/..."` lines, adding `.align 2, 0` where the
   ROM zero-fills the stream's tail to the next 4-byte boundary. `.align`
   is relative to the fragment's start, so this is only exact while the
   fragment starts 4-byte aligned (rom_0801CD08.s and rom_08364810.s do).

Every byte removed is checked against baserom.gba, so a wrong line map can
never silently eat the wrong range.

Usage:
    python3 scripts/incbin_assets.py data/rom_0801CD08.s [data/rom_....s ...]
"""

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM_BASE = 0x08000000

LABEL_RE = re.compile(r"^([A-Za-z_.$][A-Za-z0-9_.$]*):(.*)$")
LABEL_ADDR_RE = re.compile(r"^(_|sub_)([0-9A-F]{8})$")
NOP_SIZE = {"global", "thumb", "thumb_func", "syntax", "text", "size", "type",
            "pool", "section", "equ", "endm", "macro", "code16", "code32",
            "non_word_aligned_thumb_func_start", "thumb_func_end", "arm_func_end"}
DATA_SIZE = {"byte": 1, "2byte": 2, "halfword": 2, "4byte": 4, "word": 4}
# exact tokens, not prefixes: `bl`/`blx` are 4 bytes, `ble`/`bls`/`blt` are 2
LONG_INSN = {"bl", "blx"}


def asset_sizes():
    sizes = {}
    for config in sorted((ROOT / "assets").glob("*.json")):
        for asset in json.loads(config.read_text()):
            sizes[f"build/assets/{asset['path']}"] = asset["size"]
    return sizes


def line_size(text, sizes, state):
    """(bytes, state) for one line, ("align", n) to align to 2**n, or None."""
    s = text.strip()
    if not s or s.startswith("@"):
        return 0, state
    m = LABEL_RE.match(s)
    if m and m.group(2).strip():
        return line_size(m.group(2).strip(), sizes, state)[0], state
    if m:
        return 0, state
    if s.startswith("non_word_aligned_thumb_func_start"):
        return 0, state  # no .align: the name may sit at a 2-mod-4 address
    if s.startswith("thumb_func_start") or s.startswith("arm_func_start"):
        return ("align", 2), state
    if s.startswith("thumb_func_end") or s.startswith("arm_func_end"):
        return 0, state
    if s.startswith("."):
        parts = s.split(None, 1)
        op, arg = parts[0][1:], (parts[1] if len(parts) > 1 else "")
        if op == "align":
            return ("align", int(arg.split(",")[0])), state
        if op == "incbin":
            path = re.match(r'^"([^"]+)"', arg).group(1)
            if path not in sizes:
                raise SystemExit(f"incbin of an asset no *.json lists: {path}")
            return sizes[path], state
        if op == "arm":
            return 0, "arm"
        if op in ("thumb", "code16"):
            return 0, "thumb"
        if op in DATA_SIZE:
            values = [v for v in arg.split(",") if v.strip()]
            return DATA_SIZE[op] * len(values), state
        if op in NOP_SIZE:
            return 0, state
        return None, state
    if state == "arm":
        return 4, state
    token = s.split(None, 1)[0]
    return (4 if token in LONG_INSN else 2), state


def parse_byte_row(text):
    """Values of a `.byte` row, or None if the line is not one."""
    s = text.strip()
    if not s.startswith(".byte "):
        return None
    return [int(v.strip().split("@")[0], 16) for v in s[6:].split(",")]


def row_text(values):
    return "\t.byte " + ", ".join(f"0x{v:02X}" for v in values)


def map_lines(path, sizes):
    """The fragment's lines with ROM addresses, plus the end address."""
    text = path.read_text().splitlines()
    m = re.match(r"^rom_([0-9A-F]{8})\.s$", path.name)
    if not m:
        raise SystemExit(f"{path.name}: name is not rom_<address>.s")
    lines, addr, state = [], int(m.group(1), 16), "thumb"
    in_preamble = True
    for n, raw in enumerate(text, 1):
        if in_preamble:
            lines.append((raw, addr))
            if raw.strip() == "@ End embedded Luvdis macros":
                in_preamble = False
            continue
        try:
            size, state = line_size(raw, sizes, state)
        except (AttributeError, ValueError):
            size = None
        if size is None:
            raise SystemExit(f"{path.name}:{n}: cannot size line: {raw!r}")
        lines.append((raw, addr))
        if isinstance(size, tuple):
            addr = (addr + (1 << size[1]) - 1) & ~((1 << size[1]) - 1)
        else:
            addr += size
    return lines, addr


def check_labels(lines, path):
    for n, (raw, addr) in enumerate(lines, 1):
        m = LABEL_RE.match(raw.strip())
        if m:
            ma = LABEL_ADDR_RE.match(m.group(1))
            if ma and int(ma.group(2), 16) != addr:
                raise SystemExit(
                    f"{path.name}:{n}: label {m.group(1)} sits at computed "
                    f"0x{addr:08X}, not 0x{int(ma.group(2), 16):08X}"
                    " -- the line map is wrong")


def referenced(name, fragment, new_text):
    """Is `name` used outside the removed ranges? (protocol step 4)"""
    files = [p for p in (ROOT / "data").rglob("*.s") if p != fragment]
    files += (ROOT / "src").rglob("*.c") + (ROOT / "include").rglob("*.h")
    files += [ROOT / "ldscript.ld", ROOT / "symbols.ld"]
    pat = re.compile(rf"\b{re.escape(name)}\b")
    if pat.search(new_text):
        return True
    return any(pat.search(p.read_text()) for p in files)


def rewrite(path, lines, end, assets, rom):
    """Single pass: walk the lines, splitting rows at each asset range."""
    # ranges to remove: [start, stop) with the zero tail absorbed
    ranges = []
    for a in assets:
        start, size = int(a["start"], 16), a["size"]
        stop = start + size
        pad = 0
        # Only a typed (compressed-stream) asset's zero tail is its own
        # padding to the next 4-byte boundary. An untyped raw blob sits
        # back to back with whatever follows, so its tail -- zero or not
        # -- belongs to the next asset; absorbing it here would overlap.
        if a.get("type"):
            tail = rom[stop - ROM_BASE:(stop + 3 & ~3) - ROM_BASE]
            if not any(tail):
                pad = (stop + 3 & ~3) - stop
        ranges.append((start, stop, stop + pad, a))
    for (s1, _, e1, _), (s2, _, _, _) in zip(ranges, ranges[1:]):
        if e1 > s2:
            raise SystemExit(f"{path.name}: assets overlap at 0x{s2:08X}")
    if ranges and (ranges[0][0] < lines[0][1] or ranges[-1][2] > end):
        raise SystemExit(f"{path.name}: asset outside fragment span")

    out, ri, dropped, removed_bytes = [], 0, 0, 0
    emitted = set()
    for raw, addr in lines:
        # a blob whose whole range ended before this line's first byte
        while ri < len(ranges) and ranges[ri][2] <= addr:
            ri += 1
        vals = parse_byte_row(raw)
        if vals is not None and ri < len(ranges) and addr < ranges[ri][2]:
            # a data row that reaches into the range: split it, flushing
            # each kept stretch before the .incbin that follows it
            i = 0
            while i < len(vals) and ri < len(ranges):
                s, e, ep, asset = ranges[ri]
                byte_addr = addr + i
                if byte_addr >= ep:
                    ri += 1
                    continue
                if byte_addr < s:
                    take = s - byte_addr
                    out.append(row_text(vals[i:i + take]))
                    i += take
                    continue
                # values [i:...] now lie inside [s, ep)
                take = min(len(vals) - i, ep - byte_addr)
                chunk = vals[i:i + take]
                expect = rom[byte_addr - ROM_BASE:byte_addr - ROM_BASE + take]
                if chunk != list(expect):
                    raise SystemExit(
                        f"{path.name}: bytes at 0x{byte_addr:08X} disagree with "
                        "baserom.gba -- the line map is wrong")
                if s not in emitted:
                    out.append(f'\t.incbin "build/assets/{asset["path"]}"')
                    if ep > e:
                        out.append("\t.align 2, 0")
                    emitted.add(s)
                removed_bytes += take
                i += take
            if i < len(vals):
                out.append(row_text(vals[i:]))
        elif vals is None and ri < len(ranges) \
                and ranges[ri][0] < addr < ranges[ri][2] and raw.strip() \
                and not raw.strip().startswith("@"):
            # a non-data line strictly inside a removed range
            m = LABEL_RE.match(raw.strip())
            name = m.group(1) if m and not m.group(2).strip() else None
            if not name:
                raise SystemExit(
                    f"{path.name}: non-data line inside an asset range: {raw!r}")
            if referenced(name, path, "\n".join(out) + "\n" + raw):
                raise SystemExit(
                    f"{path.name}: label {name} inside an asset range is "
                    "referenced elsewhere")
            dropped += 1
        else:
            out.append(raw)
    path.write_text("\n".join(out) + "\n")
    print(f"{path.name}: removed {removed_bytes} bytes in {len(emitted)} "
          f"assets, dropped {dropped} labels, "
          f"{len(lines)} -> {len(out)} lines")


def main():
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    rom = (ROOT / "baserom.gba").read_bytes()
    sizes = asset_sizes()
    assets = []
    for config in sorted((ROOT / "assets").glob("*.json")):
        assets += json.loads(config.read_text())
    for arg in sys.argv[1:]:
        path = ROOT / arg
        text = path.read_text()
        lines, end = map_lines(path, sizes)
        check_labels(lines, path)
        # skip assets the fragment already .incbins (sound, or a re-run)
        inside = [a for a in assets
                  if lines[0][1] <= int(a["start"], 16) < end
                  and f'.incbin "build/assets/{a["path"]}"' not in text]
        rewrite(path, lines, end, inside, rom)


if __name__ == "__main__":
    main()
