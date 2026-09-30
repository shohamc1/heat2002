# NASCAR Heat 2002 (GBA) — Matching Decompilation

Goal: reproduce `baserom.gba` **byte for byte** from source. The build is
correct only when `make check` prints `MATCH`.

## The rule that governs everything

`make check` must print `MATCH` at every commit. A change that breaks the
SHA1 is wrong, no matter how clean the C looks. Never edit `baserom.gba`,
`nascar-heat.sha1`, or weaken `check` to make a build pass.

## Current state

- `data/*.s` — the fragments left of the ROM disassembly, which held
  **1159 functions** originally, split into one fragment per gap between
  decompiled functions. The folder was `asm/` until 2026-09-25. No code is
  left in it: every fragment holds only `.incbin` lines for data assets.
  `data/sound/` holds the MP2K sound data's fragments (see the sound
  paragraph below); the Makefile picks both levels up, but the scripts
  that scan for code glob `data/*.s` at the top level only -- the sound
  files hold none.
  luvdis found 743 of the functions. The other 409 Thumb functions are reached only
  through a pointer or never called (callbacks, leaf functions, empty `bx lr`
  stubs), so the `bl`-and-`push` seed rule missed them and luvdis left them as
  `.byte` rows. `scripts/seed_functions.py` now seeds them explicitly
  (`POINTER_ONLY`). The last 7 are hand-written ARM (the SDK start routine and
  interrupt dispatcher, in the main program, the high module and the
  multiboot island), which luvdis can't decode, since it reads only Thumb.
  They build from `lib/crt0.s` and `lib/crt0_island.s` (`ARM_BLOCKS` in
  `progress.py`).
- The cartridge header and the ROM's zero tail aren't in any source file.
  `lib/rom_header.s` leaves the header's fields empty, and the Makefile's
  `.gba` rule pads the ROM to 4 MB with `objcopy --pad-to`, then runs
  `gbafix` (built from `tools/tmc`) to write the logo, title, codes and
  checksum, as pokeemerald does.
- `src/` — decompiled C, in folders at any depth. A file can hold several
  functions that sit next to each other in the ROM, including `ASM_FUNC`
  functions still in asm (see "Files, folders, and names"). Run
  `scripts/progress.py` for the live figure; do not hand-copy it here, it
  goes stale within a day.
- `assets/*.json` — data assets in zeldaret/tmc's format. `make` runs
  `scripts/assets.py extract` to copy each one out of `baserom.gba` into
  `build/assets/`, and a `data/*.s` fragment `.incbin`s it, so the data
  stays out of git.
  CI has no ROM, so it runs `make check-code`: the build with zero-filled
  assets, compared against `nascar-heat.code.sha1`. `make` regenerates that
  file from `baserom.gba` when `assets/*.json` changes; commit the two
  together.
  Sound builds from editable files, as in zeldaret/tmc: each song from
  `assets/sound/songs/*.mid` (mid2agb, then assembled in place by
  `data/sound/sounds.s`) and each sample from `assets/sound/samples/*.aif`
  (aif2pcm, into `data/sound/direct_sound_samples.s`). The rest of the
  sound range is split as tmc's `data/sound/` is: the voice groups in
  `voicegroups.s`, the eight CGB waves one `.bin` each in
  `programmable_wave_samples.s` (the high module's copy, in
  `data/sound/module_sound.s`, `.incbin`s the same files), and the song
  and music player tables in C (`src/sound/tables.c`; the module's twins
  in `src/sound/module_tables.c`, its engine tables in
  `src/sound/module_engine_tables.c` sharing their initialisers with the
  main program's through `src/data/m4a_engine_tables.h`).
  `make` builds those tools from `tools/tmc` and runs
  `scripts/assets.py unpack` to write each editable file from `baserom.gba`
  only when it's missing, so edits survive `make` and `make clean`. Delete a
  file to get the ROM's version back. `assets/*/` is gitignored: never
  commit the editable files. Without a ROM, none of this runs.
  Graphics build from editable files the same way (`scripts/assets.py`'s
  docstring is the reference): full-screen backgrounds as indexed PNGs
  under `assets/graphics/screens/` (`"screen"` metatile pictures and
  `"bitmap"` mode-4 ones), tile sheets under `assets/graphics/tiles/`
  (`"tiles"`), and palettes as JASC `.pal` text files under
  `assets/graphics/palettes/` (`"pal"`). An edited picture can grow up
  to what its loader copies, and everything after it in the ROM moves
  (the edited build then no longer matches, as with any edit); a palette
  keeps its colour count, which the hardware fixes. `assets.py`'s
  docstring gives each type's limit. A palette whose ROM colours set the
  GBA's unused bit 15 lists them in its `bit15` option, and the build
  sets the bit again. A high-module
  blob the ROM also holds in the main program is a `"copy"`: its
  fragment incbins the original's build output, so one edit changes
  both GBAs.
  The 12 tracks and their AI and collision geometry are a `"track"`
  asset type: `scripts/assets.py unpack` writes each track's editable
  folder `assets/tracks/NAME/` (a Tiled `.tmx` holding the three RLE
  map layers, two 4bpp tile-sheet `.png`s that carry the palette, the
  two metatile tables as Tiled maps, and the surface codes as text,
  with the ROM-only side files under `retail/`), and the
  build re-encodes them into the part files `data/rom_0807CE30.s`
  incbins, with the stream lengths reaching `gTrackData` through the
  `.len` files it `INCBIN_U16`s. The high module's track-7 copy builds
  from the same files. The folders also hold the track GEOMETRY (issue
  #4 part 2): lanes, waypoints and walls as object layers of the `.tmx`,
  whose derived records (`scripts/track_geometry.py` holds the
  byte-exact formulas and a `verify` mode) rebuild three more regions
  (`data/rom_08365348.s`, `data/rom_083682BC.s`, `data/rom_083CA0C4.s`)
  beside the spatial indexes, which are rebuilt when the geometry
  moves. `assets.py`'s docstring is the reference.
  Compressed graphics are typed and convert to `.png` with `make convert`;
  the rest of the data is untyped raw blobs (`assets/unknown.json`).
  See "Extracted data assets" in `docs/learnings/parked.md`.
- `scripts/gen_atan2.py` generates `gAtan2Table` (0x0806C97C-0x0807C97C,
  65,536 bytes) from one formula, as a `"gen"` asset type: no ROM is
  needed, CI builds the real bytes, and `assets.py mask` leaves the range
  unmasked so `make check-code` holds the generator to the committed
  hash.
- `src/data/*.c`: the ROM data tables that C code reads, defined in C with
  `INCBIN_U8`/`INCBIN_U16`/`INCBIN_U32`, as pokeemerald's `src/graphics.c`
  does. `tools/bin/preproc` (built from `tools/tmc`) expands each call
  between cpp and agbcc. `include/data.h` declares the tables that several
  files read. See "Define ROM data in C" below.
- `include/` — one declaration per shared symbol, enforced by
  `make check-code` (`scripts/externs.py --check` fails if two files
  declare the same symbol locally). `functions.h` holds every game
  function's prototype, `m4a.h` the sound API and its tables,
  `variables.h` the shared RAM globals (address-sorted, main program and
  high-module sections; the addresses stay in `symbols.ld`),
  `data.h` the shared ROM data, `car.h` the 0x190-byte `struct Car`
  with `gCars`/`gModule_Cars`, and `structs.h` the other shared structs
  (the 0x64 `struct Track`, the m4a table structs). A variable only one
  file uses stays a local `extern` in that file. When a view-cast must
  keep a file's old access width, follow the rules in solved-walls
  entry 31 and its variants.
- `docs/recon.md` — function inventory, call graph, entry-point trace, candidate ranking.
- `docs/learnings/solved-walls.md`: **read when a function stalls.** It maps
  `match.py` diff symptoms to the source fixes that matched earlier walls,
  and you must update it when you match or abandon a stalled function.
- `docs/learnings/parked.md` — **read before picking a target.** What was
  already tried and does not match, why the compiler patch was reverted, and the 158
  blocks that are not decompilation targets: runtime-library and SDK code
  (libgcc, newlib, libagbsyscall, the sound driver's `m4a_1.s`, the MultiBoot
  and EEPROM libraries, the 7 hand-written ARM blocks) and 7 luvdis
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
  program keep their luvdis names. Also `crt0.s` (the SDK start routine and
  interrupt dispatcher, from pokeemerald's, for the main program and the
  high module), `crt0_island.s` (the island's variant, with a link-cable
  handshake), `rom_header.s`, `multiboot.c` (pokeemerald's), and
  `eeprom.c`, Nintendo's `EEPROM_V120` save library from
  Dream-Atelier/kl-eod-decomp, built at `-O1` as the SDK built it. A library object keeps its own flags; the
  rule against adding flags is about game code in `src/`.
- `docs/decomp-guide.md` — **read this before your first function.** Step-by-step
  with the failure modes; the loop below is the summary.
- `scripts/progress.py` — progress in bytes of code; `--json` emits decomp.dev `report.json`.

Counting functions: match `thumb_func_start`,
`non_word_aligned_thumb_func_start` and `arm_func_start` (1144 + 8 + 7 =
1159), and skip the macro
preamble (through `@ End embedded Luvdis macros`) or you get a phantom
function named `name` from the `.macro` definition. `scripts/progress.py
--selftest` asserts all three.

Of those 1159 blocks, **158 are not decompilation targets** — see
`parked.md` — so the game-code denominator is **1001**. The 144 blocks now
built from library source are listed in `progress.py` (`LIBRARY_BLOCKS`) so
the 1159 still adds up. `progress.py` reports against 1001 and prints the
whole-ROM figure underneath. `scripts/blocks.txt` lists all 1159 block
addresses. `progress.py` counts one function per block, so the count
doesn't change when you rename functions, merge them into one file, or move
files. An extra C function that isn't a block start, such as the
out-of-line copy of the inline helper `Min`, adds its bytes to the
block before it.

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
5. On `MATCH`, delete the function from its `data/*.s` fragment and place the
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
codegen fingerprints are visible throughout `build/rom_reference.s` (`make disasm`):

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
access suppresses the hoist and gives the second form. `agbcc` can only
ever produce the second form, so ~27 functions are unreachable from any C
under it.

Never declare a global `extern volatile`: a declaration shared through a
header must work for every file, and most files want the hoisted order.
Declare the global plain, and where the ROM loads the memory *before* the
constant it combines with, cast that one access to a volatile pointer:

    gUnk_02000DD0 &= 0xFFFE;           *(vu16 *)&gUnk_02000DD0 &= 0xFFFE;
    constant hoisted first             memory loaded first

Verified 2026-09-27: `volatile` was removed from every `extern` line in
`src/` (43 files, keyword and `vu16` spellings alike) and every function
in each file re-matched. Twelve functions lost the memory-first order and
got it back with a `*(vuX *)&g` cast at those accesses; the other 31
matched without any cast. `make check` prints `MATCH` with no `extern
volatile` left in the tree. (`-fprologue-bugfix` does not exist in
`old_agbcc` and was never needed.)

So when the asm loads a constant *before* the memory it operates on, no
cast is needed; when it loads the memory first, cast that access.

## Writing C that matches

The compiler is old and literal. It does almost no reordering, so the asm
maps closely onto the source:

- Declare every function you call in `include/functions.h` (or `m4a.h`
  for the sound API), never a local prototype. Declare a variable in
  `include/variables.h` (RAM) or `include/data.h` (ROM data) as soon as
  a second file uses it; before that a local `extern` in its only user
  is fine. `make check-code` rejects a symbol declared locally in more
  than one file. A shared array of structs needs its struct completed in
  a header above the extern (`car.h`, `structs.h`): a header that
  declares a struct array before the file defines the struct changes
  the generated code. When a header's type differs from what a matched
  file's code assumed, cast at the access site — solved-walls entry 31
  and its variants list the cast shapes that keep the bytes.
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
- In high-module C, write `/` and `%` as operators, never as calls to
  `sub_08344BB8` and friends. That module linked its own libgcc copy, and
  the Makefile renames the libcall symbols for every object that
  `ldscript.ld` places in `.high_module` or `.island`, plus any
  `src/sub_083[3-9]*.c` not placed yet. A named call
  loses the libcall's hard-r0 return and changes register allocation.
- Before drafting from scratch, check whether an instruction-identical twin
  is already matched: the 0x0834 module duplicates parts of the low region
  (`ModuleCollideCars [sub_08343EA8]` is `sub_0800D684` with renamed globals).
- Never write a ROM address (`0x08xxxxxx`) as a number in C. A shiftable
  build is a project goal, and each raw address means another edit and
  re-match later. For a function, declare it and use its name:
  `(u32)sub_0800042C` links to `0x0800042D`, Thumb bit included, with
  identical bytes (tested on `sub_08000380`). For ROM data that starts an
  `assets/unknown.json` blob, define it in `src/data/` (see "Define ROM
  data in C"). For any other ROM address, give the data a label where its
  bytes are: a `NAME:` line before its `.incbin` in `data/*.s`, splitting
  the blob in `assets/unknown.json` if the address falls inside one. For an
  offset inside a C-defined blob, add an alias to `symbols.ld`, such as
  `gUnk_083FDE2D = gChampionshipTrackOrder + 0x11;`. `symbols.ld` holds no ROM
  address: never add one. No C writes a ROM address as a number, so keep
  it that way.
- A table of pointers names its targets: `(u32)gUnk_X` or `(u32)sub_X` in
  C, `.4byte NAME` in `data/*.s`. See "Pointers" in
  `docs/learnings/parked.md`, and run `make pointers` to count the raw
  pointers left in the ROM. `make shift-test` boots the ROM and a copy
  moved by `0x104` bytes in mGBA and checks they behave the same; CI runs
  it without the ROM.

## Helper tools

Two vendored submodules help at opposite ends of a function. Neither decides a
match: only `match.py` and `make check` do.

**m2c** (`tools/m2c`) turns asm into draft C. Use it when you start a
function, especially a large one with no draft. To find the fragment, run
`grep -l 'func_start sub_080112E0$' data/*.s`, then:

    python3 tools/m2c/m2c.py -t gba -f sub_080112E0 data/rom_080112DE.s

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

**`scripts/find_twins.py`** finds functions that are copies or near-copies of
already-decompiled ones (`make disasm && python3 scripts/find_twins.py >
docs/function-twins.md`). It normalizes each function's instructions so a
relocated copy matches its original (branch targets become offsets from
function start; pool and `bl` targets are masked), so most of the high
0x0834 module shows up as exact copies of low-region functions whose C only
needs the globals and callees renamed (the positional pool/call
correspondence between twin and copy in `rom_reference.s` gives the address
map mechanically — that is how the 2026-09-24 batch of 188 functions was
ported). Read `docs/function-twins.md` before picking a target; regenerate
it after any batch of matches — it also lists remaining-vs-remaining
families where decompiling one member makes its relatives ports.

## Extracting a function: linker placement

Solved once for `sub_08006734`; repeat this shape for every function. The
mechanical steps:

1. Find the function's `thumb_func_start`/`arm_func_start` block in whichever
   `data/*.s` fragment currently holds it.
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
3. Create a new fragment `data/rom_ADDR.s` (named for the ROM address where
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
5. List the new object explicitly in the `ldscript.ld` section that holds
   its address (`.text` for most functions; see "Functions that run from
   EWRAM"), in address order: `build/data/<fragment-before>.o(.text*);` then
   `build/src/<path>.o(.text*);` then `build/data/<fragment-after>.o(.text*);`,
   where `<path>` is the C file's path under `src/` without `.c`. To add a
   function to an existing file instead, put it in the file in ROM order;
   the file's line stays where it is. A trailing `*(.text*);`
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
`sub_08000274` and on a C function with a mid-body pool and odd tail. For C,
the align goes in `.text`, so a `src/data/` file's `.rodata` gets no end
padding.

`scripts/match.py` and `scripts/progress.py` both scan every `data/*.s`
fragment now, never a hardcoded `asm/rom.s` (match.py's *target* lookup was
still hardcoded through `sub_08006734`'s first review pass -- fixed since).
`progress.py` also learned that a fully-decompiled function disappears from
`data/*.s` entirely (sized instead from its compiled object in
`build/src/**/*.o`). New fragments and new functions need no further
tooling changes.

## Define ROM data in C

Asset data must come from `baserom.gba`, never from literals in git. That
covers graphics (tiles, palettes, tilemaps, metatile maps and tables),
music and samples. List a graphics blob in `assets/graphics.json` (as
`graphics/metatiles_ADDR.bin` for a metatile map or table), not in
`assets/unknown.json`, and read it with `INCBIN_*`. Write literal
initialisers only for data the program logic reads: constants, lookup
tables, VRAM slot lists, text and pointer tables.

The Makefile runs every C file through `tools/bin/preproc`, which replaces
each `INCBIN_U8`, `INCBIN_U16`, or `INCBIN_U32` call with an initialiser
list read from the named file. To move a data blob from a `data/*.s`
fragment into C, follow the steps in "Extracting a function: linker
placement", with these differences:

1. In a `src/data/rom_ADDR.c` file, define the blob with the element type
   its users declare, reading the file that `scripts/assets.py` extracts:

       const u32 gUnk_0807C9CC[] =
           INCBIN_U32("build/assets/unknown/data_0807C9CC.bin");

   If users declare a pointer, a struct, or types that disagree, define an
   integer array of the matching width and add a comment that names the
   users' declarations.
2. If several files read the blob, move their `extern` into
   `include/data.h` as `extern const`, and include `data.h` in each file.
3. Delete the blob's `symbols.ld` line.
4. In `ldscript.ld`, place the object's `.rodata`, not its `.text`:
   `build/src/data/rom_ADDR.o(.rodata);`.

The sound tables are the one exception to `src/data/`: tmc keeps them in
`src/sound.c`, next to the m4a code that reads them, so they live in
`src/sound/tables.c` and `src/sound/module_tables.c`, and the high
module's engine tables beside them in `src/sound/module_engine_tables.c`
(their initialisers shared with `src/data/rom_0801D018.c` through
`src/data/m4a_engine_tables.h`; none of the three uses `INCBIN_*`, so
none needs the `$(ASSET_STAMP)` dependency). A ROM-data C file elsewhere
than `src/data/` needs a line here saying why.

Check alignment before you cut. agbcc aligns each array to its element size,
and a file's `.rodata` takes the alignment of its widest array. The blobs sit
back to back, so each blob must start at a multiple of its element size, and
the file's first blob at a multiple of the widest. Every cut between a C file
and a `data/*.s` fragment must fall on a 4-byte boundary, because the
Makefile pads each fragment to 4 bytes. If a blob can't meet these rules,
leave it as `.incbin`. "ROM data defined in C" in `docs/learnings/parked.md`
lists the blobs still in `data/*.s` and why.

## Files, folders, and names

The layout follows zeldaret/tmc and pret/pokeemerald: a C file is a
translation unit, not a function. The scripts key every function by its ROM
address, which `match.py` reads from `nascar-heat.elf`, so neither the
function's name nor its file's name or folder matters to them.

Named functions are filed by domain under `src/`: `system`, `sound`, `task`,
`track`, `car`, `race`, `hud`, `menu`, `link`, `save`, `camera`, `sprite`,
`palette`. A lone named function keeps a file named after it. ROM-neighbouring
functions of one domain share a module file (`src/task/task.c`,
`src/save/save.c`, `src/car/engine.c`): `ldscript.ld` places the whole
object, so only contiguous blocks can share one. Two things stop a merge:
a per-object CFLAGS override (`src/link/SioTransferIntr.c` builds at `-O1`)
and struct-layout views — two definitions of one tag cannot share a TU.
Prototype disagreements do not block: compile each caller under both views
and drop the stale declaration when the assembly comes out identical
(`car/update.c` merged after its `u16`/`u32` parameter proved
instruction-neutral). Functions still called
`sub_XXXXXXXX` stay at the `src/` root until they are named; file one under
its domain when it is.

`src/dead/` holds every file whose functions nothing in the ROM reaches: no
`bl`, no tail-call `b`, and no function pointer from a live function or from
data. Most are the high module's copies of main-program code that the second
GBA never calls, empty `bx lr` stubs, and cut features such as the cheat
password screen (`sub_080132F8`). `scripts/dead_code.py` lists the dead
functions, and `scripts/dead_code.py --check` exits 1 when a file sits on
the wrong side of `src/dead/`. A file that mixes dead and live functions
stays in its domain folder.

Ignore everything in `src/dead/`. Don't read, name, refactor, or document
its functions, and leave it out of searches and reviews. Its only upkeep is
keeping `scripts/dead_code.py --check` passing.

- A file can hold any number of functions, but `ldscript.ld` places the
  whole object, so they must be contiguous in the ROM and in ROM order.
- Order a C file's top level as the SDK-era code did: `#include` lines,
  `#define`s, type definitions (`struct`, `typedef`, `enum`), `extern`
  declarations and function prototypes, file-scope globals, prototypes of
  `static` functions, then function definitions in ROM order. A header comment
  sits directly above the first function it describes. Hoisting a struct above
  an `extern` is byte-neutral (`make check` verifies it).
- A lone-function file (named for its function) merges into the module file
  beside it in ROM order. Two things stop that, on top of the CFLAGS and
  struct-view blockers above: a non-static `inline` helper (agbcc emits its
  out-of-line copy at the end of the translation unit, so
  `CollideCarWithWalls` must stay apart from `CollideCars`), and a local
  struct whose layout differs from the module's (`FadeOutBody`, `TrkVolPitSet`).
- Folders can nest to any depth under `src/`. The object lands at the same
  path under `build/src/`.
- `match.py NAME` finds the file that defines `NAME` and builds only that
  object.

### Keep an unmatched function in a C file

To keep a function that isn't matched yet in its translation unit, use
`ASM_FUNC` from `include/global.h`, as tmc does:

    ASM_FUNC("asm/non_matching/race/sub_0800BAFC.inc",
             void sub_0800BAFC(s32 a, s32 b))

The `.inc` file holds the luvdis block's body: every line after its name
label, without the `thumb_func_start` and `thumb_func_end` lines. The
compiler emits the name label and alignment itself. `progress.py` counts an
`ASM_FUNC` as unmatched. To decompile it, replace the macro with C and
delete the `.inc` file. An `ASM_FUNC` must start on a 4-byte boundary, so a
`non_word_aligned_thumb_func_start` block can't become one.

### Rename a function

To rename a matched function:

1. Rename the function in its C file, and the file itself if you like.
2. If the file's path changed, update its `build/src/...` line in
   `ldscript.ld`.
3. Update any callers and `symbols.ld` references.
4. Run `make check` and `python3 scripts/match.py NEW_NAME`.

Rename after the function matches and is placed. Before placement, the ELF
holds only the asm's `sub_XXXXXXXX` name, and a high-module file gets its
libcall renaming only from a `sub_083[3-9]*` file name.

## Functions that run from EWRAM

Two images in the ROM run from EWRAM on a second GBA, not from the
cartridge. The main program sends the multiboot island with the BIOS
MultiBoot call. The island then receives the high module over the link
cable in 32 KB chunks. The following table lists both images:

| Image | ROM range | Runs at | `ldscript.ld` section |
|---|---|---|---|
| High module | `0x08339780`-`0x08363EE8` | `0x02000D00` | `.high_module` |
| Multiboot island | `0x08363EE8`-`0x08364AC8` | `0x02000000` | `.island` |

`ldscript.ld` links each section at its run address and stores it at its
ROM address. Every symbol inside takes its EWRAM value: `sub_08339AEC`
links to `0x0200106C`, so `(u32)sub_08339AEC` gives `0x0200106D`.
`match.py` and `progress.py` map that value back to the ROM address
through the section's load address.

The main link uses `--no-check-sections`, because the island's run
addresses overlap the main program's EWRAM `.bss`. The overlap is real:
the two run on different GBAs. Don't remove the flag.

### Decompile a function in an EWRAM image

Follow the same loop as for any other function. Only these points differ:

- Place the `build/src/<name>.o(.text*);` line inside the image's section
  block in `ldscript.ld`, in address order. There's no link base, alias, or
  `match.py` entry to add.
- `match.py` and `permute.py` link the function at its run address, which
  they read from the section table in `nascar-heat.elf`. They still report
  the ROM address.
- To reference a function or label in the same image, use its name. The
  linker resolves it to the EWRAM address. For image data with no label
  yet, add a label in the image's data fragment, as for ROM data; the
  label takes the run address. `gHighModule`, `gHighModuleRom` and
  `gUnk_08363EE8` (`ldscript.ld`) give an image's run and ROM addresses.
  Don't write a raw `0x0200xxxx` literal in C for anything inside an
  image. Module C still writes some variables outside the image, which
  have no bytes in the ROM, as numbers; see "EWRAM variables outside the
  image" in `docs/decomp-queue.md`.
- The same EWRAM address can mean a different variable on each GBA. When
  main-program code already uses a `gUnk_<address>` name, give the
  module's data its own label, such as `gModule_02025220`.
- Keep each asm fragment inside one image. The fragments
  `rom_08363EE8.s` and `rom_08364AC8.s` start exactly at a section
  boundary, so never merge one into the fragment before it.

### Troubleshoot an EWRAM function

- If `match.py` shows jump-table or pointer words that differ from the ROM
  by exactly `0x6338A80` (high module) or `0x6363EE8` (island), the
  function linked at its ROM address. Run `make` to refresh
  `nascar-heat.elf`: `match.py` reads the run address from it, and falls
  back to the ROM address when the ELF is missing.
- If `make check` fails with the same offsets, the object's `ldscript.ld`
  line is outside its image's section block. Move the line inside it.

## Never do these

- Do not modify `tools/luvdis/`, `tools/m2c/`, `tools/decomp-permuter/`, or
  `tools/tmc/`, and do not casually modify the compiler.

  The compiler is stock upstream agbcc. A `calls.c` patch was carried
  until 2026-09-23 and reverted once register pins matched the one function
  that needed it; the source-level avenue it had missed is the lesson. Any
  compiler change must clear this bar: every source-level avenue exhausted
  first (register pins included), rival explanations built and
  regression-tested, the whole corpus still matching, and the reasoning
  written down. A change that merely makes one function match is not
  acceptable.
- Do not "fix" warnings in `data/*.s`. It reproduces the ROM as-is.
- Do not add compiler flags to make something match. The flags in the
  Makefile are the ones the original build used, and `-O2`, interwork and
  every other flag have each been swept and eliminated as explanations —
  see `parked.md` before reaching for one.

## Commands

    make            # build
    make check      # build + verify SHA1 (the only test that counts)
    make check-code # every byte outside assets/*.json; what CI runs, no ROM
    make disasm     # full-ROM reference disasm -> build/rom_reference.s (never touches data/)
    python3 scripts/match.py NAME       # diff one function against the target
    python3 tools/m2c/m2c.py -t gba -f NAME FRAGMENT.s   # draft C from asm
    python3 scripts/permute.py NAME DRAFT.c -j8          # permute a near-miss
    python3 scripts/progress.py         # progress summary
    python3 scripts/progress.py --json  # report.json for decomp.dev
    python3 scripts/dead_code.py --check # src/dead/ matches the call graph
    make tools      # build agb2mid, mid2agb, aif2pcm, gbagfx from tools/tmc
    make convert    # extracted graphics -> .png, round-trip checked (needs libpng)
    make pointers   # count the ROM's raw pointers (scripts/pointers.py)
    make shift-test # boot the ROM and a shifted copy in mGBA and compare
