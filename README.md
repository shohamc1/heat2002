# NASCAR Heat 2002 (GBA) — Matching Decompilation

A work-in-progress matching decompilation of **NASCAR Heat 2002** for Game Boy
Advance (Crawfish Interactive / Infogrames, May 2002).

"Matching" means the build reproduces the original ROM **byte for byte**. Every
commit is verified against the retail cartridge's SHA-1. If the hash doesn't
match, the change is wrong — no exceptions.

## Progress

| Metric | Value |
| --- | ---: |
| Functions decompiled | **587 / 592** |
| Code matched | **103,190 / 104,960 bytes** |
| Percent complete | **98.31%** |

Progress is measured in **bytes of code**, not function count — a 1,500-instruction
function is not worth the same as a 1-instruction stub. The denominator is the
592 game-code functions: 743 blocks minus 151 that are runtime library, SDK
or luvdis false positives (see `docs/learnings/parked.md`). 74 library objects
are built from source: 34 newlib from `tools/agbcc/libc`, 18 libgcc from
`tools/agbcc/libgcc` (two copies), and from `lib/` 18 libagbsyscall members,
two copies of the sound driver's `m4a_1.s` and the MultiBoot library, all
adapted from pret/pokeemerald, and Nintendo's EEPROM save library, from
Dream-Atelier/kl-eod-decomp. Counting them, 98.6856% of the whole ROM's code
comes from source. Regenerate with `python3 scripts/progress.py`;
`--json` emits an [objdiff](https://github.com/encounter/objdiff) `report.json`
v2 compatible with [decomp.dev](https://decomp.dev).

The disassembly already reassembles to a perfect match, so the ROM is fully
reproducible today. Decompilation is the work of replacing that assembly with C
that compiles to the same bytes.

## ROM

| | |
| --- | --- |
| File | `NASCAR Heat 2002 (USA).gba` |
| Size | 4,194,304 bytes (4 MB) |
| SHA-1 | `0eb1fa43d8b0f8a6fb1e3ac04f7bba92c7cbac96` |
| MD5 | `2fb73b874bbf4119e5cbf17b8ceae9c1` |
| Game code | `ANHE` (title `NASCAR HEAT`, maker `70`) |

**The ROM is not in this repository** and never will be — it's copyrighted. Supply
your own dump and place it at `baserom.gba`. Verify with:

```sh
shasum -c nascar-heat.sha1.baserom
```

## Setup

Requires `arm-none-eabi-binutils`, Python 3, and a C compiler to bootstrap agbcc.

```sh
git clone --recursive https://github.com/shohamc1/heat2002-gba
cd heat2002-gba

# macOS; use apt-get install binutils-arm-none-eabi on Debian/Ubuntu
brew install arm-none-eabi-binutils

# Build the 2002-era compiler (a few minutes)
cd tools/agbcc && ./build.sh && cd ../..

# Function discovery tool
python3 -m venv .venv && .venv/bin/pip install -e tools/luvdis

# Permuter dependencies (scripts/permute.py); pycparser 3 breaks it
.venv/bin/pip install "pycparser<3" toml

cp /path/to/your/dump.gba baserom.gba
make check      # must print MATCH
```

## Verification

`make check` proves the output is **bit-identical** to the retail ROM. That is
the strongest signal available and every commit must pass it — but it does not
prove our C *means* the same thing as the original C, and names like
`sub_08006734` are addresses, not recovered symbols.

[`docs/verification.md`](docs/verification.md) documents exactly what MATCH does
and does not establish, including why `scripts/match.py` compares assembled
**bytes** rather than instruction text (text comparison produced both false
matches and false mismatches).

## Build

```sh
make            # build nascar-heat.gba
make check      # build + verify SHA-1 — the only test that counts
make disasm     # full-ROM reference disasm -> build/rom_reference.s (never touches asm/)
```

## How it works

The ROM was compiled with **GCC 2.95**, which is unmistakable in the
disassembly: `pop {r0}; bx r0` epilogues instead of `pop {pc}`, and
`add rX, rY, #0` used as a register move. Reproducing those bytes requires the
same compiler, so the project vendors [agbcc](https://github.com/Dream-Atelier/agbcc)
— the GBA decomp community's build of that era's toolchain.

Function discovery cross-references two signals: addresses that something `bl`s
to, **and** that begin with a `push {..., lr}` prologue. Either alone is mostly
noise (a bare `0xB5` byte scan hits roughly 1-in-256 by chance, and Luvdis'
own call-graph reachability stalls at `0x801A56C`). Requiring both cut ~1,300
candidates to 593 solid seeds, which Luvdis expanded to 743.

## Layout

```
asm/*.s          ROM disassembly, one fragment per gap between decompiled
                 functions; reassembles exactly
ram/             Alias stubs for RAM-module builds (never in the main link)
src/             Decompiled C — one function per file, named for it
include/         Headers
include/gba/     GBA hardware headers vendored from fireemblem8u (pret)
scripts/
  seed_functions.py  Function discovery (BL targets ∩ push prologues)
  match.py           Diff one compiled function against the target asm
  extract.py         Cut a matched function out of its asm fragment
  batch_extract.py   Extract every matched function, regenerate ldscript
  progress.py        Progress report + decomp.dev report.json
  permute.py         Run decomp-permuter on a near-miss draft
tools/agbcc      Vendored GCC 2.95 — do not modify
tools/luvdis     Vendored disassembler — do not modify
tools/m2c        Vendored asm-to-C decompiler for first drafts; do not modify
tools/decomp-permuter  Vendored C permuter (agbcc fork); do not modify
docs/recon.md    Binary recon: inventory, call graph, entry point
docs/decomp-queue.md  Pending functions with remaining diff, largest first
docs/verification.md  What MATCH proves, and what it doesn't
docs/learnings/  Parked functions and known dead ends — read before picking
                 (2026-09-23-twin-sweep.md: the matching-lever catalog)
CLAUDE.md        Agent instructions (AGENTS.md symlinks here)
```

## Contributing

Pick an open function from [`docs/decomp-queue.md`](docs/decomp-queue.md)
(pending functions with their remaining diff, largest first) or the
"no useful twin" list in
[`docs/learnings/parked.md`](docs/learnings/parked.md). The loop:

1. Write C in `src/` implementing the target function.
2. `make && python3 scripts/match.py <function>`
3. `MISMATCH` prints an instruction-level diff — adjust and repeat.
4. On `MATCH`, cut the function out of its `asm/*.s` fragment
   (`python3 scripts/extract.py <function>`) and place the C object at the
   same address in `ldscript.ld`.
5. `make check` must still print `MATCH`.
6. Commit. One function per commit, or a batch that was verified one
   function at a time (`scripts/batch_extract.py` re-runs every `src/*.c`
   through `match.py` before it cuts anything).

Read [`CLAUDE.md`](CLAUDE.md) first — it documents the agbcc-specific tells that
make a function match (loop shape from branch placement, stray `lsl`/`asr` pairs
meaning a width mismatch, locals assigned in declaration order).

### Matching levers that closed recent functions

The last dozen functions each came down to one or two small source
shapes; the catalog with mechanisms and failures is in
[`docs/learnings/2026-09-23-twin-sweep.md`](docs/learnings/2026-09-23-twin-sweep.md).
The short list:

- **Write the plainest source first**: no pointer locals, no pins, plain
  field expressions. GCSE builds the spanning address pseudos (the
  `mov r9, r5`-style copies in the ROM) and the allocator finds the
  ROM's homes on its own more often than not. Pointer locals and
  `register ... asm("rN")` pins are last-resort crutches — and test pin
  removals as *combinations*, not one at a time (a missed combination
  cost sub_08009C4C a full session).
- **A stack parameter read as both `ldrh` and `ldr` is a u32 in the
  source.** GCC 2.95 integrates narrower parms into entry pseudos; only
  word-sized parms keep the slot equivalence that reload turns into
  per-use reads under pressure (the narrow loads still come out
  narrow).
- **Statement order is the lever, declaration order is not** — pseudos
  are created at first reference. Split `k = x >> N; k += C;`,
  `a |= CONST;` before a call, and `row = table[i]; row += f(...)` so
  the non-call side evaluates first.
- **Operand order tunes live ranges**: writing `element * pointer` vs
  `pointer * element` changed which pseudo global allocation ranks
  first (sub_0800A084's final fix).
- **Registers that "skip" a free register are reload scratches**, not
  global-alloc homes: the `movs #imm; lsls` constant splits (>255
  offsets) and fused load+shift input reloads are created by reload
  after global allocation, round-robin from its spill set. If the ROM
  rotates r2→r3→r2 where yours first-fits from r0, look for what adds a
  register to that spill set.


**Never modify anything under `tools/`.** Those are vendored submodules; the
compiler's exact behavior is what makes matching possible. They're fenced off
from linting and autofix via per-submodule `.pi-lens.json`.

## What's known about the binary

From [`docs/recon.md`](docs/recon.md):

- Entry point `0x080000C0` (header branch `0xEA00002E`), a standard AGB crt0:
  IRQ/System stack setup, vector install at `0x03007FFC`, ARM→Thumb interwork.
- Code clusters in two dense regions: `0x08000260`–`0x0801CCD4` (529 functions)
  and `0x08339920`–`0x08344DA8` (202 functions). The ~1.15 MB gap in the middle
  is assets.
- The late region contains **opcode-for-opcode duplicates** of the libgcc
  helpers and BIOS wrappers from the first region, plus a second Nintendo logo
  and ARM startup sequence at `0x08363EE8`.
- Identified by shape: `__divsi3`, `__modsi3`, `__umodsi3`, `__clzsi2`,
  `__div0`, a soft-float family, `memcpy`/`memmove`/`memset`, and 8 BIOS SWI
  wrappers.

## Credits

The headers in [`include/gba/`](include/gba/) come from
[fireemblem8u](https://github.com/laqieer/fireemblem8u), which carries the
shared GBA hardware layer originated by [pret](https://github.com/pret).
`io_reg.h` is identical to pokeemerald's. The same four files are used across
pret-lineage decompilations: `io_reg.h`, `defines.h`, `syscall.h` and
`macro.h`. Neither project ships a licence file, so they are reused here by
community convention, with attribution.

One change was made to them. `defines.h` dropped its `#include <stddef.h>`,
because this project builds with `-nostdinc` and used nothing from that header.

fireemblem8u also identified this ROM's sound engine. It is MP2K (m4a), with
ident `0x68736D53`, one revision older than pret's `0x68736D54`.

## Legal

This project contains **no copyrighted game data** — only original source code
and analysis. You must supply your own legally-obtained ROM. NASCAR Heat 2002 is
the property of its respective rights holders; this project is unaffiliated
reverse-engineering for interoperability and preservation research.
