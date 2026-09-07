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

## Extracting a function: linker placement

Solved once in DECOMP-001 (`sub_08006734`); repeat this shape for every
ticket. The mechanical steps:

1. Find the function's `thumb_func_start`/`arm_func_start` block in whichever
   `asm/*.s` fragment currently holds it.
2. Truncate that fragment right before the block (delete the block through
   the next function's `thumb_func_start` line, exclusive).
3. Create a new fragment `asm/rom_ADDR.s` (named for the address of the
   function immediately after the one removed) containing: the macro
   preamble (everything through `@ End embedded Luvdis macros`, copied
   verbatim -- each `.s` file is assembled standalone) followed by the rest
   of the original content, starting at that next function.
4. Every bare `_XXXXXXXX:` address label (branch/data targets luvdis
   generates, as opposed to `sub_XXXXXXXX` function symbols, which the
   macros already `.global`) must be `.global` in whichever fragment defines
   it, or cross-fragment references fail to link with "undefined reference".
   One-time fix, not needed again once a symbol has been globalized.
5. List the new object explicitly in `ldscript.ld`'s `.text` block, in
   address order: `build/asm/<fragment-before>.o(.text*);` then
   `build/src/<name>.o(.text*);` then `build/asm/<fragment-after>.o(.text*);`.
   name the C file after the function (`src/sub_08006734.c`, not
   `src/stub.c`) so this line is mechanical to write. A trailing `*(.text*);`
   stays in the script as a safety net, not the placement mechanism: it
   exists so a forgotten explicit line still links -- landing past the real
   ROM's end and breaking the SHA1 loudly -- instead of silently vanishing
   into `/DISCARD/` with `make check` still printing MATCH.

Do not hand-add filler bytes for the gap between a short C function and
whatever follows. `ld` automatically zero-pads the location counter up to
satisfy the next input section's recorded alignment (from its own internal
`.align 2, 0` directives), and that zero-fill is what the original ROM's
inter-function padding actually is. Adding your own padding on top double-counts.

The one real trap: `arm-none-eabi-as` rounds every `.text` section's end up
to its recorded alignment using NOP filler (`46c0`), independent of section
content. A monolithic asm/rom.s never showed this (one section, aligned by
luck at EOF), but a lone C function assembled to its own object will, if its
size isn't a multiple of 4 -- the extra NOP bytes land in the ROM where the
real byte (usually zero, from the linker's own alignment fill) belongs.
`-no-pad-sections` claims to disable this and does not, empirically, in this
toolchain. The fix lives in the Makefile's `$(BUILD)/src/%.o` rule: an `awk`
step downgrades agbcc's leading `.align 2, 0` (the function's own entry
alignment, a content no-op since a function is always first in its own
object) to `.align 1, 0` before assembling, which stops gas from recording
alignment 4 for the section at all. (Not `sed -i` -- its in-place flag takes
a mandatory suffix argument on BSD and an optional one on GNU, so the same
invocation cannot work on both a Mac dev machine and Linux CI; awk's
redirect-to-a-temp-file-then-rename has no such split.)

Only the *first* `.align 2, 0` is touched -- this is why **one function per
`src/*.c` file is a hard build requirement, not a style convention**. A
second function's own leading alignment, or a real literal pool's alignment
inside a bigger function, is a second `.align 2, 0` that reintroduces the
same section-alignment-4 problem the fix exists to avoid, and the fix
silently stops applying to it. No literal-pool case has been hit yet; when
one is, this awk step will not be enough on its own and needs revisiting.

`scripts/match.py` and `scripts/progress.py` both scan every `asm/*.s`
fragment now, never a hardcoded `asm/rom.s` (match.py's *target* lookup was
still hardcoded through DECOMP-001's first review pass -- fixed since).
`progress.py` also learned that a fully-decompiled function disappears from
`asm/*.s` entirely (sized instead from its compiled object in
`build/src/*.o`), and that "is this function decompiled" must check for a
`name(` at column 0 in a `src/*.c` file, not merely the name appearing
anywhere in one -- otherwise a decompiled function calling a still-asm one
counts that callee as done too. Already fixed; new fragments and new
tickets need no further tooling changes for either of these.

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
