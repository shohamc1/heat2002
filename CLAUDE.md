# NASCAR Heat 2002 (GBA) — Matching Decompilation

Goal: reproduce `baserom.gba` **byte for byte** from source. The build is
correct only when `make check` prints `MATCH`.

## The rule that governs everything

`make check` must print `MATCH` at every commit. A change that breaks the
SHA1 is wrong, no matter how clean the C looks. Never edit `baserom.gba`,
`nascar-heat.sha1`, or weaken `check` to make a build pass.

## Current state

- `asm/rom.s` — full ROM disassembly, **743 functions**, reassembles to an exact match.
- `src/` — empty. Decompilation moves functions from asm into C, one at a time.
- `docs/recon.md` — function inventory, call graph, entry-point trace, candidate ranking.
- `docs/tickets/` — one markdown ticket per function. Start with `DECOMP-001`.
- `scripts/progress.py` — progress in bytes of code; `--json` emits decomp.dev `report.json`.

Counting functions: match **both** `thumb_func_start` and
`non_word_aligned_thumb_func_start` (735 + 8 = 743), and skip the macro
preamble (through `@ End embedded Luvdis macros`) or you get a phantom
function named `name` from the `.macro` definition. `scripts/progress.py
--selftest` asserts all three.

## The loop

1. Take the lowest-numbered open ticket in `docs/tickets/`.
2. Write C in `src/` implementing that function.
3. `make && python3 scripts/match.py <name>`.
4. `MISMATCH` prints an instruction diff — adjust the C and repeat.
5. On `MATCH`, delete the function from `asm/rom.s` and place the C object at
   the same address in `ldscript.ld`.
6. `make check` must still print `MATCH`.
7. `python3 scripts/progress.py`, then commit. One function per commit.

## Toolchain

`tools/agbcc/agbcc` is GCC 2.95, the compiler this ROM was built with. Its
codegen fingerprints are visible throughout `asm/rom.s`:

- `pop {r0}; bx r0` function epilogues (not `pop {pc}`)
- `add rX, rY, #0` used as a register move
- arguments evaluated right-to-left

If your C produces `pop {pc}` you are not using agbcc.

## Writing C that matches

The compiler is old and literal. It does almost no reordering, so the asm
maps closely onto the source:

- Match the exact number and order of locals; agbcc assigns registers in
  declaration order.
- A `for` that compiles to `bge` at the top ran zero-trip-checked; a `do/while`
  shape puts the branch at the bottom. The asm tells you which loop was written.
- Prefer `s32`/`u8` etc. from `include/global.h` — width mismatches show up as
  stray `lsl`/`asr` sign-extension pairs.
- Stack shuffling that won't go away usually means a local is missing or one
  too many exists.

## Never do these

- Do not modify anything under `tools/agbcc/` or `tools/luvdis/`. They are
  vendored. The compiler's exact behavior is what makes matching possible;
  reformatting its source can silently change codegen. Both are fenced off
  from linting via a per-submodule `.pi-lens.json` — leave it in place.
- Do not "fix" warnings in `asm/rom.s`. It reproduces the ROM as-is.
- Do not add compiler flags to make something match. The flags in the
  Makefile are the ones the original build used.

## Commands

    make            # build
    make check      # build + verify SHA1 (the only test that counts)
    make disasm     # regenerate asm/rom.s from the base ROM
    python3 scripts/match.py NAME       # diff one function against the target
    python3 scripts/progress.py         # progress summary
    python3 scripts/progress.py --json  # report.json for decomp.dev
