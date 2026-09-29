#!/usr/bin/env python3
"""Compare a decompiled function's compiled bytes against the retail ROM.

    python3 scripts/match.py LoadTrack

The target is read from `baserom.gba` at the function's own address, taken
from `nascar-heat.elf`'s symbol table, so a function keeps its address when
it's renamed. A `sub_XXXXXXXX`-style name that the ELF doesn't hold falls
back to the address in the name. That matters: an earlier
version extracted the target from `asm/rom.s`, so the moment a function was
decompiled -- and deleted from the asm -- the tool could no longer verify it.
The ROM is the ground truth and it never moves, so a matched function stays
checkable forever.

The object is first linked alone at its run address with `-R nascar-heat.elf`
(symbol values only, no code) so `bl`/`.word sub_XXX` references resolve to
their real targets; an unrelocated object cannot match anything that calls
out. Before extraction the ELF still contains the asm copy of the function,
which is fine -- only its symbols are read. During the pre-extraction
iteration loop, build just the object (`make build/src/NAME.o`), since the
full link fails on the duplicate symbol until the asm block is deleted.

Comparison is on BYTES, never on assembly text, because text is unsound in
both directions:

  * `.L1:` moved by one instruction changes a branch target -- identical
    mnemonics, different bytes.
  * agbcc emits divided-syntax `lsl` where unified syntax wants `lsls` --
    different text, identical encoding.
"""

import functools
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "baserom.gba"
NM = "arm-none-eabi-nm"
OBJCOPY = "arm-none-eabi-objcopy"
OBJDUMP = "arm-none-eabi-objdump"
LD = "arm-none-eabi-ld"
ELF = ROOT / "nascar-heat.elf"
SYMBOLS = ROOT / "symbols.ld"
ROM_BASE = 0x8000000

def addr_of(name):
    """The ROM address of function `name`.

    Read from nascar-heat.elf, so any name works once the function is in
    the build. `sub_XXXXXXXX`-style -> 0x08XXXXXXX is the fallback for a name the
    ELF doesn't hold: a fresh clone before `make`, or a luvdis block that
    left the build with the data it sat in.
    """
    addr = _elf_addresses().get(name)
    if addr is not None:
        return addr
    m = re.fullmatch(r"(?:sub|func)_([0-9A-Fa-f]{8})", name)
    if not m:
        return None
    return int(m.group(1), 16)


def source_of(name):
    """The src/**/*.c file that defines function `name`, or None."""
    path = ROOT / "src" / f"{name}.c"
    if path.exists():
        return path
    pat = re.compile(
        rf"^\S[^(\n;]*\b{re.escape(name)}\s*\([^;{{]*\)\s*\{{|\bASM_FUNC\([^,]*,[^(]*\b{re.escape(name)}\s*\(",
        re.MULTILINE,
    )
    for c in sorted((ROOT / "src").rglob("*.c")):
        if pat.search(c.read_text(errors="replace")):
            return c
    return None


@functools.lru_cache(maxsize=1)
def _symbol_index():
    """Map every built C symbol to [(object, offset, size)], in one nm pass.

    Cached because progress.py checks every decompiled function and each
    check used to re-run nm over all of build/src -- quadratic in the number
    of decompiled functions, minutes of subprocesses by the 250-function
    mark. Call _symbol_index.cache_clear() after rebuilding an object.
    """
    index = {}
    for obj in sorted((ROOT / "build").rglob("*.o")):
        # Only C objects; asm objects hold the not-yet-decompiled originals
        # and would trivially "match" the ROM they were disassembled from.
        if "/src/" not in obj.as_posix():
            continue
        # A renamed or moved source leaves its old object behind.
        if not (ROOT / obj.relative_to(ROOT / "build")).with_suffix(".c").exists():
            continue
        out = subprocess.run(
            [NM, "--print-size", str(obj)],
            capture_output=True,
            text=True,
            check=False,
        ).stdout
        for line in out.splitlines():
            p = line.split()
            if len(p) == 4 and p[2] in ("t", "T"):
                index.setdefault(p[3], []).append((obj, int(p[0], 16), int(p[1], 16)))
    return index


@functools.lru_cache(maxsize=1)
def _sections():
    """{name: (lma, vma, size)} of every section in nascar-heat.elf."""
    if not ELF.exists():
        return {}
    out = subprocess.run([OBJDUMP, "-h", str(ELF)], capture_output=True, text=True, check=False).stdout
    return {
        name: (int(lma, 16), int(vma, 16), int(size, 16))
        for name, size, vma, lma in re.findall(
            r"^\s*\d+ (\S+)\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)", out, re.M
        )
    }


@functools.lru_cache(maxsize=1)
def _elf_addresses():
    """{function name: ROM address} from nascar-heat.elf's symbol table.

    A symbol in an EWRAM image holds its run address; its section's load
    address maps it back to where it sits in the ROM.
    """
    if not ELF.exists():
        return {}
    sections = _sections()
    out = subprocess.run([OBJDUMP, "-t", str(ELF)], capture_output=True, text=True, check=False).stdout
    addrs = {}
    for value, section, name in re.findall(r"^([0-9a-f]+) .* F (\S+)\s+[0-9a-f]+ (\S+)$", out, re.M):
        if section in sections:
            lma, vma, _ = sections[section]
            addrs[name] = (int(value, 16) & ~1) - vma + lma
    return addrs


def link_address(addr):
    """The address the code stored at ROM `addr` runs at.

    The high module and the multiboot island are stored in the ROM but
    linked to run from EWRAM, and their jump tables and pointers hold EWRAM
    addresses. ldscript.ld places each in its own section, so a section
    whose load address (LMA) differs from its run address (VMA) gives the
    mapping.
    """
    for lma, vma, size in _sections().values():
        if lma <= addr < lma + size:
            return addr - lma + vma
    return addr


def find_symbol(name):
    """Locate `name` in the built objects. Returns (object, offset, size)."""
    return list(_symbol_index().get(name, ()))


def object_bytes(obj, offset, size, addr):
    """Link `obj` alone at the address ROM `addr` runs at (symbols from the
    full ELF) and return the function's .text bytes."""
    link_addr = link_address(addr)
    with tempfile.TemporaryDirectory() as d:
        elf = Path(d) / "t.elf"
        bin_ = Path(d) / "t.bin"
        cmd = [LD, f"-Ttext={link_addr - offset:#x}", "-e", f"{link_addr:#x}", "-o", str(elf), str(obj)]
        if ELF.exists():
            cmd[1:1] = ["-R", str(ELF)]
        if SYMBOLS.exists():
            cmd[1:1] = ["-T", str(SYMBOLS)]
        r = subprocess.run(cmd, capture_output=True, text=True, check=False)
        if r.returncode != 0:
            sys.stderr.write(r.stderr)
            return None
        r = subprocess.run(
            [OBJCOPY, "-O", "binary", "--only-section=.text", str(elf), str(bin_)],
            capture_output=True,
            check=False,
        )
        if r.returncode != 0 or not bin_.exists():
            return None
        blob = bin_.read_bytes()
        if offset + size > len(blob):
            return None
        return blob[offset : offset + size]


def disasm(data, addr):
    """Disassemble raw Thumb bytes, for the human-readable diff only."""
    with tempfile.TemporaryDirectory() as d:
        bin_ = Path(d) / "t.bin"
        bin_.write_bytes(data)
        out = subprocess.run(
            [
                OBJDUMP, "-D", "-b", "binary", "-m", "arm",
                "-M", "force-thumb", f"--adjust-vma={addr:#x}", str(bin_),
            ],
            capture_output=True,
            text=True,
            check=False,
        ).stdout
        lines = []
        for line in out.splitlines():
            m = re.match(r"^\s*([0-9a-f]+):\s+([0-9a-f ]+?)\s\s+(.*)$", line)
            if m:
                lines.append(f"{m.group(1)}: {m.group(3).strip()}")
        return lines


def compare(name):
    """Return (ours, target, size, addr); sys.exit with a reason on failure."""
    addr = addr_of(name)
    if addr is None:
        sys.exit(f"{name}: not in {ELF.name} and no address in the name -- run `make`")

    hits = find_symbol(name)
    if not hits:
        sys.exit(f"{name}: no compiled object under build/src -- run `make build/src/{name}.o` first")
    if len(hits) > 1:
        where = ", ".join(str(o.relative_to(ROOT)) for o, _, _ in hits)
        sys.exit(f"{name}: defined in multiple objects ({where})")

    obj, offset, size = hits[0]
    if size == 0:
        sys.exit(f"{name}: nm reports size 0 in {obj.relative_to(ROOT)}")

    ours = object_bytes(obj, offset, size, addr)
    if ours is None:
        sys.exit(f"{name}: could not link/extract bytes from {obj.relative_to(ROOT)}")

    rom = ROM.read_bytes()
    start = addr - ROM_BASE
    if not (0 <= start < len(rom)):
        sys.exit(f"{name}: address {addr:#x} is outside the ROM")
    return ours, rom[start : start + size], size, addr


def matches(name):
    """True iff the compiled `name` reproduces the ROM bytes. For progress.py."""
    ours, target, _, _ = compare(name)
    return ours == target


def main():
    if len(sys.argv) != 2:
        sys.exit("usage: match.py FUNCTION_NAME")
    name = sys.argv[1]

    for tool in (NM, OBJCOPY, OBJDUMP, LD):
        if not shutil.which(tool):
            sys.exit(f"{tool} not found; install arm-none-eabi-binutils")
    if not ROM.exists():
        sys.exit(f"{ROM} not found -- supply your own dump (see README)")

    # Build only this object: a full `make` fails on the duplicate symbol
    # until the asm block is deleted, and the point is to match *before* that.
    # -B forces the recompile: make compares mtimes at 1-second granularity,
    # so an edit landing in the same second as the previous build is skipped
    # and the verdict below would describe the *previous* source.
    src = source_of(name)
    if src:
        obj = Path("build") / src.relative_to(ROOT).with_suffix(".o")
        r = subprocess.run(["make", "-B", str(obj)], cwd=ROOT, capture_output=True, text=True)
        if r.returncode != 0:
            sys.exit(r.stdout + r.stderr)
        _symbol_index.cache_clear()

    ours, target, size, addr = compare(name)

    if ours == target:
        print(f"{name}: MATCH ({size} bytes @ {addr:#010x})")
        return 0

    print(f"{name}: MISMATCH ({size} bytes @ {addr:#010x})")
    print(f"  target: {target.hex(' ')}")
    print(f"  ours:   {ours.hex(' ')}")
    import difflib

    for line in difflib.unified_diff(
        disasm(target, addr), disasm(ours, addr), "target", "ours", lineterm="", n=3
    ):
        print(line)
    return 1


def _selftest():
    assert addr_of("DummyUiFontLoad") == 0x08006734
    assert addr_of("not_a_function") is None

    # Byte comparison must catch a moved label, which text comparison cannot.
    # `bx lr` (0x4770) vs `nop` (0x46c0) stands in for any 2-byte difference.
    assert b"\x70\x47" != b"\xc0\x46"

    if shutil.which(OBJDUMP):
        d = disasm(b"\x70\x47", 0x08006734)
        assert d and "bx" in d[0].lower(), d

    if ROM.exists():
        rom = ROM.read_bytes()
        # The known contents of DummyUiFontLoad: a bare `bx lr`.
        assert rom[0x6734:0x6736] == b"\x70\x47", rom[0x6734:0x6736].hex()

    # Module code links at its EWRAM run address, read from the ELF's
    # sections; main-program code links where it sits in the ROM.
    if ELF.exists():
        # The ELF, not the name, gives the address: a helper without a sub_
        # name, and an EWRAM symbol mapped back to its ROM address.
        assert addr_of("Min") == 0x0800D5BC, addr_of("Min")
        assert addr_of("sub_08339AEC") == 0x08339AEC, addr_of("sub_08339AEC")
        assert link_address(0x08340EFC) == 0x0200847C, hex(link_address(0x08340EFC))
        assert link_address(0x08364550) == 0x02000668, hex(link_address(0x08364550))
        assert link_address(0x08006734) == 0x08006734

    # The symbol index is built once and reused; a second lookup must not
    # re-run nm, or progress.py goes quadratic again.
    if (ROOT / "build" / "src").is_dir():
        _symbol_index.cache_clear()
        first = _symbol_index.cache_info()
        find_symbol("DummyUiFontLoad")
        find_symbol("DummyUiFontLoad")
        info = _symbol_index.cache_info()
        assert first.currsize == 0 and info.hits >= 1 and info.misses == 1, info
    print("selftest ok")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--selftest":
        _selftest()
    else:
        sys.exit(main())
