# NASCAR Heat 2002 (GBA) — Matching Decompilation

Goal: reproduce `baserom.gba` **byte for byte** from source. The build is
correct only when `make check` prints `MATCH`.

## The rule that governs everything

`make check` must print `MATCH` at every commit. A change that breaks the
SHA1 is wrong, no matter how clean the C looks. Never edit `baserom.gba`,
`nascar-heat.sha1`, or weaken `check` to make a build pass.

## Current state

- `asm/*.s` — ROM disassembly, **743 functions** originally, split into one
  fragment per gap between decompiled functions; reassembles to an exact match.
- `src/` — **204 functions decompiled** (7,306/110,078 bytes). One function
  per file, named for it.
- `docs/recon.md` — function inventory, call graph, entry-point trace, candidate ranking.
- `docs/learnings/parked.md` — **read before picking a target.** What was
  already tried and does not match, plus the five luvdis false positives
  that are not functions at all.
- `docs/tickets/` — one markdown ticket per function. Lowest open number first.
- `docs/decomp-guide.md` — **read this before your first ticket.** Step-by-step
  with the failure modes; the loop below is the summary.
- `scripts/progress.py` — progress in bytes of code; `--json` emits decomp.dev `report.json`.

Counting functions: match **both** `thumb_func_start` and
`non_word_aligned_thumb_func_start` (735 + 8 = 743), and skip the macro
preamble (through `@ End embedded Luvdis macros`) or you get a phantom
function named `name` from the `.macro` definition. `scripts/progress.py
--selftest` asserts all three.

## The loop

1. Take the lowest-numbered open ticket in `docs/tickets/`.
2. Write C in `src/` implementing that function.
3. `python3 scripts/match.py <name>`. It builds only `build/src/<name>.o`
   (a full `make` fails with a duplicate symbol while the asm copy still
   exists -- expected) and links it alone at its address with symbols from
   `nascar-heat.elf`, so `bl`/pointer references resolve before comparing.
4. `MISMATCH` prints an instruction diff — adjust the C and repeat.
5. On `MATCH`, delete the function from its `asm/*.s` fragment and place the
   C object at the same address in `ldscript.ld`.
6. `make check` must still print `MATCH`.
7. `python3 scripts/progress.py`, then commit. One function per commit.

## Toolchain

`tools/agbcc/old_agbcc` is GCC 2.95, the compiler this ROM was built with,
built from the **fork** at
[shohamc1/agbcc-heat2002](https://github.com/shohamc1/agbcc-heat2002),
which the `tools/agbcc` submodule points at. It carries one commit on top
of upstream: address constants are not precomputed into a pseudo before
the parameter registers are loaded. See the "compiler is patched" section
of `docs/learnings/parked.md` for why, and for the idiom it creates. The
binary is gitignored, so a fresh clone needs
`git submodule update --init` then `tools/agbcc/build.sh`. Its
codegen fingerprints are visible throughout `asm/rom.s`:

- `pop {r0}; bx r0` function epilogues (not `pop {pc}`)
- `add rX, rY, #0` used as a register move
- arguments evaluated right-to-left

If your C produces `pop {pc}` you are not using agbcc.

### Use `old_agbcc`, not `agbcc`

The two vendored binaries differ at the `#ifndef OLD_COMPILER` gate in
`tools/agbcc/gcc/thumb.c` (`s_register_operand`, line 1588). The visible
effect is where a constant is materialised relative to the memory load it
is combined with:

    ldr  r1, _020005CC      ldr  r0, _020005CC
    movs r0, #8             ldrh r1, [r0, #0]
    ldrh r1, [r1, #0]       movs r0, #8
    ands r0, r1             ands r0, r1
    old_agbcc               agbcc

`old_agbcc` hoists the constant; `agbcc` never does. The ROM contains both
orders, and **`volatile` is the lever**: under `old_agbcc` a `volatile`
global suppresses the hoist and gives the second form. `agbcc` can only
ever produce the second form, so ~27 functions are unreachable from any C
under it.

Verified 2026-09-10: `make check` prints MATCH for the whole ROM under
`old_agbcc`, with four globals needing `extern volatile` (`gKeysHeld`,
`gKeysPressed`, `gUnk_02000DD0`, `gUnk_02037E20`, `gUnk_02037618`,
`gUnk_0203761C`). `-fprologue-bugfix` does not exist in `old_agbcc` and is
not needed: all 211 functions matched without it.

So when the asm loads a constant *before* the memory it operates on, write
the global non-`volatile`; when it loads the memory first, write it
`volatile`.

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
2. Truncate that fragment right before the block. Delete ONLY the
   function's own bytes: its instructions and its literal pool (the
   `_XXXXXXXX: .4byte` lines that `ldr rN, _XXXXXXXX` refers to). 312 of the
   742 blocks end in trailing `.byte` rows -- data that luvdis lumped in
   before the next `thumb_func_start` (e.g. 52 bytes after `sub_08016558`'s
   pool). Those bytes are not the function; `match.py`'s size comes from the
   compiled object, so they would silently vanish from the ROM. Keep them.
   Also check that no `ldr rN, _XXXXXXXX` in the block refers to a pool
   label defined in a *different* function's block, or vice versa. A
   PC-relative load cannot cross an object boundary (assembly fails with
   "invalid offset"; `.global` does not help). Exactly two such pairs
   exist: `sub_08000958`/`sub_08000972` (share `_08000988`) and
   `sub_0833A018`/`sub_0833A032` (share `_0833A048`) -- each is really one
   routine that `bl`s into its own tail. Decompile each pair together in
   one `src/*.c` file or leave both in asm; never split between them.
3. Create a new fragment `asm/rom_ADDR.s` (named for the ROM address where
   the fragment's first byte lands: the end of the removed function, i.e.
   where the kept `.byte` rows or the next function begin) containing: the
   macro preamble (everything through `@ End embedded Luvdis macros`, copied
   verbatim -- each `.s` file is assembled standalone) followed by the rest
   of the original content, starting with any kept trailing data.
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
to its recorded alignment (4, from any `.align 2, 0` in the file -- agbcc
emits one before every function and every literal pool) using NOP filler
(`46c0`). `-no-pad-sections` does not stop it. The ROM contains no NOPs: the
gap before the next function is always zero bytes. So a C function or an asm
fragment whose size is 2 mod 4 would put `46c0` where the ROM has `0000`.
This is not rare -- 55 functions have a literal pool followed by a 2-mod-4
code tail, and 207 function boundaries sit 2 mod 4, so any fragment cut there
hits it too. The Makefile fixes it by appending an explicit `.align 2, 0` to
every generated `.s` (C and asm fragments alike) before assembling: an
explicit align pads with its fill byte (zero) instead of NOPs, and that zero
is exactly the linker fill the ROM has. Verified on a 2-mod-4 fragment cut at
`sub_08000274` and on a C function with a mid-body pool and odd tail.

Keep one function per `src/*.c` file anyway: `ldscript.ld` places whole
objects at addresses, so a file with two functions can only be placed if they
are adjacent in the ROM, and `progress.py` sizes decompiled functions per
object.

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
    make disasm     # full-ROM reference disasm -> build/rom_reference.s (never touches asm/)
    python3 scripts/match.py NAME       # diff one function against the target
    python3 scripts/progress.py         # progress summary
    python3 scripts/progress.py --json  # report.json for decomp.dev
