# NASCAR Heat 2002 (GBA) — Matching Decompilation

Goal: reproduce `baserom.gba` **byte for byte** from source. The build is
correct only when `make check` prints `MATCH`.

## The rule that governs everything

`make check` must print `MATCH` at every commit. A change that breaks the
SHA1 is wrong, no matter how clean the C looks. Never edit `baserom.gba`,
`nascar-heat.sha1`, or weaken `check` to make a build pass.

## Current state

- `asm/*.s` — ROM disassembly, **1150 functions** originally, split into one
  fragment per gap between decompiled functions; reassembles to an exact match.
  luvdis found 743 of them. The other 407 are reached only through a pointer
  or never called (callbacks, leaf functions, empty `bx lr` stubs), so the
  `bl`-and-`push` seed rule missed them and luvdis left them as `.byte` rows.
  `scripts/seed_functions.py` now seeds them explicitly (`POINTER_ONLY`).
- `src/` — **257 functions decompiled**. One function per file, named for
  it. Run `scripts/progress.py` for the live figure; do not hand-copy it
  here, it goes stale within a day.
- `docs/recon.md` — function inventory, call graph, entry-point trace, candidate ranking.
- `docs/learnings/solved-walls.md`: **read when a function stalls.** It maps
  `match.py` diff symptoms to the source fixes that matched earlier walls,
  and you must update it when you match or abandon a stalled function.
- `docs/learnings/parked.md` — **read before picking a target.** What was
  already tried and does not match, why the compiler patch was reverted, and the 151
  blocks that are not decompilation targets: runtime-library and SDK code
  (libgcc, newlib, libagbsyscall, the sound driver's `m4a_1.s`, the MultiBoot
  and EEPROM libraries) and 7 luvdis
  false positives that are not functions at all.
- `build/lib/libgcc/` — every libgcc block, built from `tools/agbcc/libgcc`
  with its own Makefile's flags, plus the high 0x0834 module's renamed
  copy (see the Makefile).
- `build/lib/newlib/` — all 34 newlib code objects (plus `impure.o`'s data)
  built from `tools/agbcc/libc` with the library's own flags (see the
  Makefile), placed whole by `ldscript.ld` with their `.rodata`, `.data` and
  `.bss`. They replaced 73 luvdis blocks.
- `lib/` — SDK source pulled from pret/pokeemerald: `libagbsyscall.s` (one
  object per syscall; all three copies in the ROM build from it) and
  `m4a_1.s` (the sound driver's hand-written asm, edited to this ROM's older
  revision; both engine copies build from it). Copies outside the main
  program keep their luvdis names. Also `multiboot.c` (pokeemerald's), and
  `eeprom.c`, Nintendo's `EEPROM_V120` save library from
  Dream-Atelier/kl-eod-decomp, built at `-O1` as the SDK built it. A library object keeps its own flags; the
  rule against adding flags is about game code in `src/`.
- `docs/decomp-guide.md` — **read this before your first function.** Step-by-step
  with the failure modes; the loop below is the summary.
- `scripts/progress.py` — progress in bytes of code; `--json` emits decomp.dev `report.json`.

Counting functions: match **both** `thumb_func_start` and
`non_word_aligned_thumb_func_start` (1142 + 8 = 1150), and skip the macro
preamble (through `@ End embedded Luvdis macros`) or you get a phantom
function named `name` from the `.macro` definition. `scripts/progress.py
--selftest` asserts all three.

Of those 1150 blocks, **151 are not decompilation targets** — see
`parked.md` — so the game-code denominator is **999**. The 144 blocks now
built from library source are listed in `progress.py` (`LIBRARY_BLOCKS`) so
the 1150 still adds up. `progress.py` reports against 999 and prints the
whole-ROM figure underneath.

## The loop

1. Pick an unmatched function and read `parked.md` first: it records what
   was already tried.
2. Write C in `src/` implementing that function. For a first draft, read
   m2c's output (see "Helper tools").
3. `python3 scripts/match.py <name>`. It builds only `build/src/<name>.o`
   (a full `make` fails with a duplicate symbol while the asm copy still
   exists -- expected) and links it alone at its address with symbols from
   `nascar-heat.elf`, so `bl`/pointer references resolve before comparing.
4. `MISMATCH` prints an instruction diff — adjust the C and repeat. If the
   structure matches and only registers or a few instructions differ, run
   the permuter and trace the compiler passes before you park the function
   (see "Helper tools" and `docs/learnings/solved-walls.md`).
5. On `MATCH`, delete the function from its `asm/*.s` fragment and place the
   C object at the same address in `ldscript.ld`.
6. `make check` must still print `MATCH`.
7. `python3 scripts/progress.py`, then commit. One function per commit.

## Toolchain

`tools/agbcc/old_agbcc` is GCC 2.95, the compiler this ROM was built with,
built from **stock** upstream
[Dream-Atelier/agbcc](https://github.com/Dream-Atelier/agbcc) at `a0f70c9`,
which the `tools/agbcc` submodule points at. A fork carrying one `calls.c`
patch was used until 2026-09-23 (see "Reverted 2026-09-23" in
`docs/learnings/parked.md`). The binary is gitignored, so a fresh clone needs
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
- An address (or any argument costing more than one cheap move) is loaded
  before the other argument registers. When the ROM loads it after them,
  pin the other arguments: `register u32 a0 asm("r0") = 0;
  register u32 a1 asm("r1") = 4; f(a0, a1, &g);` (see `sub_08003738`).
- A `for` that compiles to `bge` at the top ran zero-trip-checked; a `do/while`
  shape puts the branch at the bottom. The asm tells you which loop was written.
- Prefer `s32`/`u8` etc. from `include/global.h` — width mismatches show up as
  stray `lsl`/`asr` sign-extension pairs.
- Stack shuffling that won't go away usually means a local is missing or one
  too many exists.
- In `src/sub_083[3-9]*.c`, write `/` and `%` as operators, never as calls
  to `sub_08344BB8` and friends. That module linked its own libgcc copy, and
  the Makefile renames the libcall symbols for those objects. A named call
  loses the libcall's hard-r0 return and changes register allocation.
- Before drafting from scratch, check whether an instruction-identical twin
  is already matched: the 0x0834 module duplicates parts of the low region
  (`sub_08343EA8` is `sub_0800D684` with renamed globals).
- Never write a ROM address (`0x08xxxxxx`) as a number in C. A shiftable
  build is a project goal, and each raw address means another edit and
  re-match later. For a function, declare it and use its name:
  `(u32)sub_0800042C` links to `0x0800042D`, Thumb bit included, with
  identical bytes (tested on `sub_08000380`). For ROM data, declare an
  `extern` and add one line to `symbols.ld`. When the shiftability pass
  replaces that line with a real label, the C doesn't change. Older files
  still hold raw literals; leave them for that pass.

## Helper tools

Two vendored submodules help at opposite ends of a function. Neither decides a
match: only `match.py` and `make check` do.

**m2c** (`tools/m2c`) turns asm into draft C. Use it when you start a
function, especially a large one with no draft. To find the fragment, run
`grep -l 'func_start sub_080112E0$' asm/*.s`, then:

    python3 tools/m2c/m2c.py -t gba -f sub_080112E0 asm/rom_080112DE.s

Treat the output as notes, not source. It casts addresses instead of using
`extern` symbols, guesses types, and ignores declaration order. Rewrite it
with the rules in "Writing C that matches".

**decomp-permuter** (`tools/decomp-permuter`, the agbcc fork) rewrites a
draft at random and scores each compile against the target. Use it when the
structure matches and the diff is register names or a few reordered
instructions:

    python3 scripts/permute.py sub_080112E0 DRAFT.c -j8

- It writes `nonmatchings/NAME/` (gitignored) and runs until you press
  Ctrl+C. Each better candidate lands in
  `nonmatchings/NAME/output-SCORE-N/source.c`.
- Edit your draft, not `base.c`. Every run regenerates the inputs.
- A score of 0 means the disassembly text matches. Copy the candidate to
  `src/NAME.c` and run `match.py`: only its `MATCH` counts.
- A lower non-zero score is a lead. Find the change that helped and apply
  it to your draft by hand, then run the permuter again from there.
- Its C parser rejects `register ... asm("rN")` pins. Remove them first.
- It runs from `.venv`, because it needs `pycparser<3`. See the setup
  section of `README.md`.

Don't stop at the permuter. Its first trial, on `sub_08016ED8`, ran about
30 minutes from a score of 25 without improving, and the fix needed an
`asm("rN")` pin that the permuter can't parse. Tracing the compiler passes
found that fix:

1. Find a variant, even one with wrong bytes, that gets the right register
   choices. For `sub_08016ED8`, that was a `volatile u32` read in place of
   `u16`.
2. Compile it and the draft with `old_agbcc` plus `-dc -dN -dl` to dump
   RTL after combine, regmove, and local-alloc.
3. Find the first pass where the two dumps diverge, and write C that
   changes what that pass sees.

The `sub_08016ED8` entry in `parked.md` walks through a full example.

`scripts/permute.py` replaces the permuter's own `import.py`. It links the
target and every candidate at the function's ROM address, like `match.py`.
Unlinked objects never score 0 here: asm pools hold literal addresses, and C
pools hold relocations. `import.py` can't link, because it builds every
`compile.sh` from one project-wide command, and the address differs per
function. On an already-matched function this setup scores 0.

## Extracting a function: linker placement

Solved once for `sub_08006734`; repeat this shape for every function. The
mechanical steps:

1. Find the function's `thumb_func_start`/`arm_func_start` block in whichever
   `asm/*.s` fragment currently holds it.
2. Truncate that fragment right before the block. Delete ONLY the
   function's own bytes: its instructions and its literal pool (the
   `_XXXXXXXX: .4byte` lines that `ldr rN, _XXXXXXXX` refers to). Some
   blocks end in trailing `.byte` rows that luvdis never decoded: zero fill,
   small tables, the high module's ARM startup code. A `.byte` row can also
   be code: luvdis leaves every switch jump table and its case bodies as
   `.byte` inside the function that owns them. Bytes after the function's
   own pool are not the function; `match.py`'s size comes from the
   compiled object, so they would silently vanish from the ROM. Keep them.
   (Before `POINTER_ONLY`, most such rows were missed functions: the 52
   bytes after `sub_08016558`'s pool are `sub_08016568`.)
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
still hardcoded through `sub_08006734`'s first review pass -- fixed since).
`progress.py` also learned that a fully-decompiled function disappears from
`asm/*.s` entirely (sized instead from its compiled object in
`build/src/*.o`), and that "is this function decompiled" must check for a
`name(` at column 0 in a `src/*.c` file, not merely the name appearing
anywhere in one -- otherwise a decompiled function calling a still-asm one
counts that callee as done too. Already fixed; new fragments and new
functions need no further tooling changes for either of these.

## Never do these

- Do not modify `tools/luvdis/`, `tools/m2c/`, or `tools/decomp-permuter/`,
  and do not casually modify the compiler.
  Both are fenced off from linting via a per-submodule `.pi-lens.json` —
  leave it in place.

  The compiler is stock upstream agbcc. A `calls.c` patch was carried
  until 2026-09-23 and reverted once register pins matched the one function
  that needed it; the source-level avenue it had missed is the lesson. Any
  compiler change must clear this bar: every source-level avenue exhausted
  first (register pins included), rival explanations built and
  regression-tested, the whole corpus still matching, and the reasoning
  written down. A change that merely makes one function match is not
  acceptable.
- Do not "fix" warnings in `asm/rom.s`. It reproduces the ROM as-is.
- Do not add compiler flags to make something match. The flags in the
  Makefile are the ones the original build used, and `-O2`, interwork and
  every other flag have each been swept and eliminated as explanations —
  see `parked.md` before reaching for one.

## Commands

    make            # build
    make check      # build + verify SHA1 (the only test that counts)
    make disasm     # full-ROM reference disasm -> build/rom_reference.s (never touches asm/)
    python3 scripts/match.py NAME       # diff one function against the target
    python3 tools/m2c/m2c.py -t gba -f NAME FRAGMENT.s   # draft C from asm
    python3 scripts/permute.py NAME DRAFT.c -j8          # permute a near-miss
    python3 scripts/progress.py         # progress summary
    python3 scripts/progress.py --json  # report.json for decomp.dev
