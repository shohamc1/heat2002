# Plan: move extern declarations into headers

Measured on 27 September 2026 at commit `e0e8953`.

The goal is pret/pokeemerald's layout. Code is grouped into module files,
and each module has one header that declares its functions and variables.
Each RAM variable is defined in the C file that owns it. A local `extern`
is rare. `make check` must print `MATCH` at every commit, as for any other
change in this repository.

The plan gets there in two stages:

1. **Stage 1, phases 0 to 5 (about 1 week):** every symbol that more than
   one file uses is declared once, in a header. Symbols that have no
   subsystem yet go in catch-all headers. A variable that only one file
   uses can stay a local `extern` in that file. This is where zeldaret/tmc
   is today.
2. **Stage 2, phase 6 (weeks, one module at a time):** functions merge into
   module files, each module gets its own header, and RAM variables move
   from `symbols.ld` into C. The catch-all headers empty out and go away.

Stage 1 is done when all of the following hold:

- `python3 scripts/externs.py --check` prints nothing and exits 0.
- `make check-code` runs that check, so local builds and CI both enforce
  it.
- `make check` and `make check-code` print `MATCH`.
- `CLAUDE.md` and `docs/decomp-guide.md` tell contributors where to
  declare symbols.

Stage 2 is done when `include/functions.h` and `include/variables.h` no
longer exist and `symbols.ld` holds no RAM variables.

Don't start with a naming pass. Most symbols are placeholders
(`sub_XXXXXXXX`, `gUnk_XXXXXXXX`), and naming them before you understand the
code produces guesses. Once each symbol has one declaration, a rename is one
scripted edit. Naming happens in phases 3, 4, and 6, where giving a symbol
its real type or its module and naming it are the same job.

## Why this matters

Each C file declares what it uses with its own `extern` lines. The compiler
checks each file on its own, so it can't detect when two files disagree
about a symbol's type. The following table shows the current state:

| Measure | Count | Notes |
|---|---|---|
| `extern` lines in `src/` | 4,492 | In 1,058 C files |
| Unique functions declared | 285 | 89 declared in more than one file; 29 with conflicting types |
| Unique variables declared | 2,166 | 423 declared in more than one file; 170 with conflicting types |
| Struct definitions in `src/` | 163 | 84 distinct tags; `struct Car` alone is defined 25 times |
| Unprototyped declarations (`f()`) | 0 | Every function extern has a prototype |

The counts ignore parameter names and whitespace. `scripts/externs.py`
reproduces them; see "Appendix: audit script".

### How the reference projects compare

Neither reference project has zero local `extern` lines. Both declare a
symbol in a header once several files use it. The following table shows
the same audit run on each project:

| Project | `extern` lines in `src/` | Symbols declared in more than one file | Symbols with conflicting types |
|---|---|---|---|
| This repository (`e0e8953`) | 4,492 | 512 | 199 |
| zeldaret/tmc (`d92d4581`) | 2,135 | 78 | 27 |
| pret/pokeemerald (`c925b84`) | 142 | 7 | 2 |

tmc places every RAM global by address in `linker.ld`, as `symbols.ld`
does here. It declares a shared variable in the header of the subsystem
that uses it, even with a placeholder name, such as
`extern struct_02018EB0 gUnk_02018EB0;` in `beanstalkSubtask.h`. A
variable that one file uses stays local: `gIntroState` is declared in
`title.c`. Its `functions.h` holds two prototypes.

pokeemerald defines each variable in its owning C file with `EWRAM_DATA`
and declares it in that module's header. `sym_ewram.txt` lists the objects
in link order, so the linker lays out their variables in the original
order.

### Variable conflicts by class

The 170 variable conflicts fall into the following classes. The phase
column shows where each class gets fixed.

| Class | Count | Example | Phase |
|---|---|---|---|
| Differ only by `volatile` or `const` | 22 | `gIsLinkRace`: `u8` in 23 files, `volatile u8` in 4 | 2 |
| Scalar in some files, array in others | 31 | `gUnk_083FDE18`: `u32` and `u32 []` | 2 |
| Array size differs | 2 | `gUnk_0202CBC0` | 2 |
| Different struct types | 20 | `gCars`: about 20 struct types across 52 files | 3 |
| Element width or sign differs | 62 | `gCamera`, `gUnk_03007FF8` | 4 |
| Pointer in some files, array in others | 5 | `gUnk_0203ACD8` | 4 |
| Other mixed shapes | 28 | `gUnk_020251B8`: `u32`, `u32 []`, `u8 *`, `u16 *` | 4 |

### `volatile` isn't needed

`CLAUDE.md` says some globals need `extern volatile` to match. That's no
longer true for the current corpus. The test was to remove `volatile` from
every `extern` line in all 39 files that use it, rebuild each object, and
run `match.py` on every function in it. Every function printed `MATCH`.

This matters because `volatile` was the main reason one shared declaration
might not work for every file. If a future function needs the volatile
access order, cast at that one access site: `*(vu8 *)&gIsLinkRace`. A
volatile cast produced the same bytes as a volatile extern in
`UpdateLapProgress`. Phase 2 repeats this test and records it, so the
claim is reproducible.

### Declaration order matters for struct arrays

Under `old_agbcc`, declaring an array of a struct before the struct is
defined changes the generated code. `LoadTrackTiles` and `LoadTrack` both
mismatch when `extern struct Track gUnk_08364B0C[];` moves above
`struct Track`'s definition, as a header included at the top of the file
would put it. Declaring a single struct variable, or a prototype with a
pointer to a struct, before the struct's definition produced identical
code in a test.

No file in `src/` declares a struct array before its struct today. So a
header must never declare an array of a struct that the header doesn't
define before that line.

## Rules

These rules come from `CLAUDE.md` and apply to every commit:

- `make check` prints `MATCH`. Never edit `baserom.gba` or
  `nascar-heat.sha1`, and never weaken the `check` target.
- The header follows the definition. A matched C function's parameter
  types drive the callee's code, so never change a definition's signature
  to suit a caller. Change the caller.
- Don't add compiler flags, and don't modify anything under `tools/`.
- Other sessions commit to `main` while you work, and they add C files
  with their own `extern` lines. Rebase often, and rerun your codemod on
  the files that arrive.
- Commit in small steps. Each commit builds and matches on its own.

## Target layout

The following headers hold the declarations. Each C file includes
`global.h` first, then the `gba/` headers it needs, then these:

| Header | Holds | Stage | Model |
|---|---|---|---|
| `include/functions.h` | Prototypes for functions that have no module header yet | 1 only | tmc's `include/functions.h`, which tmc has almost emptied |
| `include/variables.h` | Shared RAM globals (`0x02xxxxxx`, `0x03xxxxxx`) that have no module header yet | 1 only | tmc's placement: addresses stay in `symbols.ld`, as in tmc's `linker.ld` |
| `include/data.h` (exists) | Shared ROM data (`0x08xxxxxx`), whether defined in `src/data/` or labelled in `data/*.s` | 1 and 2 | pokeemerald's `include/graphics.h` |
| `include/m4a.h` | The sound engine's public API: `m4aSongNumStart` and its siblings | 1 and 2 | pokeemerald's `include/m4a.h` |
| `include/<module>.h` | One module's structs, variables, and prototypes: `car.h`, `menu.h`, `text.h`, `link.h` | 1 and 2 | pokeemerald's one header per module |

Keep these conventions:

- Sort each catch-all header by address. Split `functions.h` and
  `variables.h` into three commented sections: main program, high module,
  and multiboot island. The high module's and island's symbols link at
  EWRAM run addresses, so a plain sort by ELF value mixes them with RAM.
- Keep any address comment that a declaration already carries, such as
  `/* 0x020020DC */`.
- Declare a struct in the module header that owns it. Add a catch-all
  `include/structs.h`, as tmc's `structures.h`, only for a struct that
  belongs to no module.
- Move a symbol from a catch-all header into its module header when you
  name its module.
- The high module and the island use their own names (`gModule_...`) for
  their variables, even at an address the main program also uses. They are
  different variables on different GBAs, so keep them as separate
  declarations. tmc does the same for one GBA: `gMenu`, `gIntroState`, and
  `gChooseFileState` all sit at `0x02000080`, each with its own name and
  type.

## Phase 0: set up

Time: about 30 minutes.

1. Create a branch from `main`.
2. Run `make check` and confirm it prints `MATCH`.
3. Run `python3 scripts/externs.py` from the repository root and keep its
   output: it's your list of conflicts for phases 1 to 4. Run it again at
   the end of each phase to measure the change.
4. Write a codemod script that does the following. Don't commit it: it's a
   one-off tool.
    1. Find every `extern` declaration in `src/**/*.c`, including ones with
       a trailing comment.
    2. Remove the declarations that the current phase covers.
    3. Add the matching `#include` lines after `#include "global.h"`, once
       per file.

## Phase 1: functions

Time: about 3 to 4 hours.

Every game function is defined in a C file, as C or as an `ASM_FUNC`, and
the sound engine's functions are defined in `lib/`. So every function
`extern` crosses a file boundary. This phase moves all 285 into headers,
not only the 89 that several files declare.

Do this phase in two commits. The first makes every caller agree while the
externs are still local, so it builds and matches on its own. The second
moves the agreed declarations into headers.

### Commit 1: make every caller agree

1. For each of the 29 conflicting functions, pick the canonical signature:
    - If the function is defined in C, use its definition's signature.
      Twenty-eight of the 29 are.
    - If it's still in asm (`sub_08017230`), use its most common
      declaration: `s32 sub_08017230(s32, s32)`.
2. Rewrite every local `extern` for that function to the canonical
   signature.
3. Fix each call site the change touches, in this order:
    1. Pointer type mismatch, such as `FadeToBrightenedPalette(u32, u32)`
       against the canonical `(void *, u32)`: cast the argument. A pointer
       cast doesn't change the generated code.
    2. Return type mismatch, such as `ExchangeLinkInput` declared `s8`,
       `s32`, and `u32`: cast the result at the call site to the type the
       file used, for example `(s8)ExchangeLinkInput()`.
    3. Integer width or sign mismatch, such as `MenuMoveVertical` with `s8`
       against `u8`: build and run `match.py`. If the function mismatches,
       cast the argument to the type the old declaration used.
    4. If a cast doesn't restore the match, call through a function
       pointer with the old signature, and add a comment that says why:
       `((u8 (*)(u16, u8, u32, u32))MenuMoveVertical)(keys, v, lo, hi)`.
       Record the case in `docs/learnings/solved-walls.md`.
4. Run `python3 scripts/match.py NAME` on every function in each file you
   changed.
5. Run `make check`, then commit.

### Commit 2: move the prototypes into headers

1. Generate `include/functions.h` with one prototype per game function
   that any file declares. Keep the definition's parameter names: they
   document the function better than the callers' names.
2. Move the sound engine's functions (`m4a...`) into `include/m4a.h`
   instead.
3. If a prototype takes a pointer to a struct that no header defines yet,
   forward-declare the tag at the top of the header: `struct Car;`. Each
   file that defines the struct still completes it. A forward-declared
   pointer parameter doesn't change the generated code; see "Declaration
   order matters for struct arrays".
4. Leave out any function that a file defines `static`. A header
   declaration followed by a `static` definition fails to build.
5. Run the codemod: remove the function externs from `src/`, and include
   `functions.h` or `m4a.h` where a file used them.
6. Run `make check`, then commit.

Phase 1 is done when no function `extern` is left in `src/` and
`make check` prints `MATCH`.

## Phase 2: shared variables and the mechanical conflicts

Time: about 3 to 4 hours.

### Commit 1: drop `volatile`

1. Repeat the `volatile` test from "`volatile` isn't needed":
    1. In every file under `src/` that has an `extern volatile` line,
       remove `volatile` from each `extern` line.
    2. Rebuild each file's object, and run `match.py` on every function
       it defines. List them with
       `arm-none-eabi-nm build/src/FILE.o | awk '$2 == "T" {print $3}'`.
2. If every function prints `MATCH`, keep the change. If one mismatches,
   put its `volatile` back as a cast at the access site that needs it,
   such as `*(vu8 *)&gX`.
3. Record the procedure and the result in
   `docs/learnings/solved-walls.md`: the files tested, the command, and
   the outcome.
4. In `CLAUDE.md`, rewrite the `volatile` guidance in "Use `old_agbcc`,
   not `agbcc`": declare the global without `volatile`, and cast the one
   access that needs the volatile order. This keeps the docs in step with
   the tree from this commit on.
5. Run `make check`, then commit all of the above together.

### Commit 2: fix the other mechanical conflicts

1. Fix these conflicts in place, keeping the externs local:
    - `const` only: keep `const` on ROM data (`0x08xxxxxx`), and drop it
      from RAM variables.
    - Array size (2): use the largest size any file declares, or `[]` if
      no file needs the size.
    - Scalar against array (31): declare the variable as an array, then
      rewrite the scalar users. `gX` becomes `gX[0]`, and `&gX` becomes
      `gX`.
2. Run `match.py` on every function in each file you changed, then
   `make check`, then commit.

### Commit 3: move the shared variables into headers

1. Generate declarations for every variable that more than one file
   declares, that now has one type, and whose type isn't a struct:
    - RAM variables go in `include/variables.h`.
    - ROM data goes in `include/data.h`, with `const`.
2. Leave every struct-typed variable local, even when every file spells
   its type the same way. Phase 3 moves it together with its struct. A
   header that declares a struct array before the file defines the struct
   changes the generated code; see "Declaration order matters for struct
   arrays". One shared variable falls under this rule today:
   `gUnk_08364B0C`, a `struct Track` array.
3. Run the codemod to remove the moved externs and add the includes.
   Leave the externs of variables that only one file declares where they
   are.
4. Run `make check`, then commit.

Phase 2 is done when `scripts/externs.py --check` lists only the 115
variables in the struct, width, pointer, and other classes, plus
`gUnk_08364B0C`, which phase 3 moves.

## Phase 3: shared structs, starting with `struct Car`

Time: about 1 to 2 days.

`gCars` has about 20 different types across 52 files, and its users index
it with a stride of `0x190`. Merge one struct at a time:

1. Collect every definition of the struct and every type that its users
   give it. For `struct Car`, that includes `struct Car08005FA8`,
   `struct Car137C`, `struct UnkCar`, `struct Drv`, `struct Ent`, and the
   `u8 [][0x190]` views.
2. Build one definition in `include/car.h`, above every `extern` that uses
   it:
    - Include every field that any file uses, at its offset, with an offset
      comment as the existing definitions do.
    - Fill unknown gaps with `u8 padXX[...]` arrays.
    - Where files disagree on a field's width or sign, pick the one most
      files use. Fix the other users with a cast at the access site.
    - Name each field from what the code does with it. This is the naming
      work.
3. Add a compile-time size check after the struct, so a wrong pad shows up
   as a build error:
   `typedef char CarSizeCheck[sizeof(struct Car) == 0x190 ? 1 : -1];`
4. Replace each file's local struct and its `gCars` extern with
   `#include "car.h"`, and rename field accesses to the shared names.
5. Run `match.py` on every function in each file you changed, then
   `make check`, then commit.

Handle `gUnk_0203D520` in the same pass. It's the high module's array of
cars:

- All 29 files that use it are in the high module, and no main-program
  file uses it.
- Its users give it the same car struct types as `gCars` and the same
  `0x190` stride.
- `gCars` is at `0x0202A550` on the host GBA. The high module runs on the
  other GBA, which keeps its cars at `0x0203D520`, in module workspace past
  the end of the loaded image (`0x0202B468`).

Rename it to `gModule_Cars`. The rename touches only the high module's C
files and the `symbols.ld` line. Then declare it with the rest of the car
data: `extern struct Car gModule_Cars[];` in `include/car.h`, below the
struct. Keep it separate from `gCars`: the two arrays live on different
GBAs.

Then repeat for the other struct tags that several files define: `Track`
(eight files), `Ent` (eight), `Box` (seven), and `UnkCar` (five).

## Phase 4: the remaining conflicts, one subsystem at a time

Time: about 30 minutes per variable, alongside decompilation.

The 95 variables left in the width, pointer, and other classes are usually
structs or unions that nobody has typed yet. A variable read as `u8` at one
site and `u32` at another is usually a struct with fields at different
offsets. For each variable:

1. Read every access site in the asm (`make disasm`, then search
   `build/rom_reference.s`) and note each load's width and offset.
2. Decide the real type:
    - Accesses at several offsets with fixed widths mean a struct.
    - The same offset read at several widths means a union, or a field
      that some caller reads with a cast.
    - `ldr rX, =gX` followed by `ldr rX, [rX]` before the access means
      `gX` is a pointer variable. An access through the address directly
      means an array. One variable can't be both, so one group of files is
      wrong.
    - Two unrelated uses of one address can be two variables. As tmc does,
      give each use its own name and type, with a line for each in
      `symbols.ld`.
3. Name the variable and its fields, and declare it in its module header,
   or in `variables.h` if it has no module yet.
4. Update every user, run `match.py` on each changed function, then
   `make check`, then commit.

## Phase 5: lock in stage 1

Time: about 1 hour.

1. In the `Makefile`, make `check-code` run the check before it compares
   the SHA1, so it fails when more than one file declares the same symbol
   locally. `check` depends on `check-code`, and CI runs `check-code`, so
   local builds and CI both enforce it:

   ```make
   check-code: $(TARGET).gba $(TARGET).code.sha1
   	python3 scripts/externs.py --check
   	python3 scripts/assets.py mask $< $(BUILD)/$(TARGET).code.gba
   	@shasum -c $(TARGET).code.sha1 && echo "CODE MATCH" || (echo "CODE MISMATCH"; exit 1)
   ```

   Add the check only now: before phase 4 ends, it fails.
2. Update `CLAUDE.md`:
    - Add these rules to "Writing C that matches": declare every function
      in a header; declare a variable in a header once a second file uses
      it; never declare a symbol in a C file that a header already
      declares.
    - Describe the header layout from this plan in "Current state".
3. Update `docs/decomp-guide.md`: when a new function needs a prototype or
   a shared global, add it to the module header, or to the catch-all
   header if there's no module header yet.

## Phase 6: reach the pokeemerald layout

Time: weeks, one module at a time. Start a module only after you can name
it.

This phase repeats per module. Each module needs a name and a boundary,
so it moves at the pace of decompilation and naming, not in one pass.

### Find a module's boundary

The original linker placed each object's code together and each object's
variables together. Use both to find where an original source file
started and ended:

- A run of neighbouring functions that call each other and share
  variables is probably one file.
- A run of neighbouring RAM variables that only that run of functions
  reads or writes is that file's data. The variables' address order is
  the file's definition order.
- A module whose RAM isn't one contiguous run has the wrong boundary, or
  holds variables of more than one kind (initialised data, zero-filled
  data, IWRAM). Check the boundary before you move anything.

### Merge the module's functions

1. Move the module's functions into one file, `src/<area>/<module>.c`,
   in ROM order. Keep unmatched functions as `ASM_FUNC`. See "Files,
   folders, and names" in `CLAUDE.md`.
2. Replace the functions' lines in `ldscript.ld` with the one object's
   line.
3. Create `include/<module>.h`. Move the module's prototypes, structs, and
   shared variables into it from `functions.h`, `variables.h`, and any
   other header.
4. Run `match.py` on every function in the file, then `make check`, then
   commit.

### Define the module's RAM variables in C

Prove the mechanism on one variable before you move a whole module:

1. In the module's C file, define the variable with `EWRAM_DATA` (or
   `IWRAM_DATA` for `0x03xxxxxx`) from `include/gba/defines.h`, in address
   order, as pokeemerald does: `EWRAM_DATA u8 gIsLinkRace = 0;`.
2. In `ldscript.ld`, add a `NOLOAD` output section at the first
   variable's address that places the object's `ewram_data`. The script
   already does this for `multiboot.o`'s `.bss` at `0x0200048C`.
3. Delete the variables' lines from `symbols.ld`.
4. Run `make check`. The ROM's literal pools hold every variable's
   address, so a variable in the wrong place breaks the SHA1.
5. Commit.

Once one module works, repeat for the rest. When every RAM section is
placed by object, consider pokeemerald's `sym_ewram.txt` pattern: one
section per memory region that lists the objects in order, with `.space`
fill for variables that no C file defines yet.

### Finish

1. Delete `include/functions.h` and `include/variables.h` once they're
   empty.
2. Tighten the `--check` rule in `scripts/externs.py`: a local `extern` is
   allowed only for a data label in `data/*.s` that one file reads.
3. Update `CLAUDE.md` and `docs/decomp-guide.md` to describe the module
   layout.

## Troubleshooting

The following table maps build and match failures to their usual cause:

| Symptom | Cause | Fix |
|---|---|---|
| `conflicting types for 'X'` | The header and the definition disagree | Make the header match the definition, never the reverse |
| `static declaration of 'X' follows non-static declaration` | The function is `static` in its file | Remove it from the header |
| `invalid use of undefined type 'struct X'` | The header only forward-declares the struct | Include the module header that defines it |
| `match.py` shows an extra `lsl`/`lsr` or `lsl`/`asr` pair before a `bl` | The prototype changed how the caller narrows an argument | Cast the argument; see phase 1, commit 1, step 3 |
| `match.py` shows `ldrb` where the ROM has `ldrh`, or the reverse | A variable's declared width changed | Cast at the access site, or fix the struct field's type |
| `match.py` shows an extra `ldr` before an access | A pointer became an array, or the reverse | See phase 4, step 2 |
| `match.py` shows a constant loaded after the memory it combines with | The access lost the volatile order | Cast that access to a volatile pointer: `*(vu8 *)&gX` |
| `undefined reference to 'X'` at link time | The symbol's name changed in a header but not in `symbols.ld` | Rename it in `symbols.ld` too |
| `match.py` shows a field read as `ldr rX, [rY, #OFFSET]`, where the ROM adds the offset first (`adds rX, rY, #OFFSET`, then `ldr rX, [rX, #0]`) | A header declares a struct array before the struct is defined | Define the struct in the header above the `extern`, or leave the `extern` local until phase 3 |
| `make check` fails after a variable moves into C | The variable's address, order, or alignment changed | Compare `nm nascar-heat.elf` against the old `symbols.ld` address |

## Out of scope

The following work is related but isn't part of this plan:

- A wholesale rename of placeholder names.
- The EWRAM variables that the high module's C still writes as numbers.
  See "EWRAM variables outside the image" in `docs/decomp-queue.md`.
- Library code in `lib/` and anything under `tools/`.

## Appendix: audit script

`scripts/externs.py` is the audit script, and the source of truth for
every count in this plan. Run it from the repository root. It prints the
`extern` line count and every symbol with conflicting types, most-used
first. With `--check`, it lists only the symbols that more than one file
declares locally, and exits 1 if there are any.

### The 29 function conflicts

The following table lists each conflicting function, where it's defined,
and the declarations callers use, most common first:

| Function | Defined in | Declarations (count) |
|---|---|---|
| `BeginFadeToColor` | C | `void (s32, u32)` (3); `void (u32, u32)` (1) |
| `DrawSmallDigit` | C | `void (u8 *, u8)` (2); `void (u16 *, u8)` (1) |
| `DrawSpriteText` | C | `void (void *, u32, u32)` (1); `void (u8 *, u32, u32)` (1) |
| `DrawText` | C | `void (u8 *, u32, u32, u8)` (10); `void (u32, u32, u32, u8)` (1) |
| `DrawTextCentered` | C | `void (u32, u32, u32)` (5); `void (u8 *, u32, u32)` (1) |
| `DrawTextCenteredHighlight` | C | `void (u32, u32, u32)` (13); `void (u8 *, u32, u8)` (6) |
| `DrawTrackSelect` | C | `void (s8, u8)` (1); `void (u8, u8)` (1) |
| `ExchangeLinkInput` | C | `u32 (void)` (3); `s32 (void)` (3); `s8 (void)` (1) |
| `FadeToBrightenedPalette` | C | `void (void *, u32)` (50); `void (u32, u32)` (1) |
| `FreeTask` | C | `void (u32)` (2); `void (structEntityAF44 *)` (1) |
| `GetString` | C | `u32 (u16)` (24); `u32 (u32)` (11); `void (u16)` (1) |
| `MenuMoveHorizontal` | C | `u8 (u16, s8, u32, u32)` (3); `u8 (u16, u8, u8, u8)` (1) |
| `MenuMoveVertical` | C | `u8 (u16, s8, u32, u32)` (23); `u8 (u16, u8, u32, u32)` (1); `u8 (u16, s8, s16, s16)` (1); `u32 (u16, u8, u32, u32)` (1) |
| `RemoveTask` | C | `void (u32)` (2); `void (structEntityAF44 *)` (1) |
| `RequestObjPalette` | C | `u8 (u32)` (3); `u8 (u8 *)` (1) |
| `RunRace` | C | `u8 (u8, u8, void *)` (1); `u8 (u32, u32, void *)` (1) |
| `sub_08001134` | C | `void (u32)` (2); `void (void)` (1) |
| `m4aMPlayStop [sub_080019B4]` | C | `void (u32)` (2); `void (void *)` (1) |
| `ReadLinkMenuKeys [sub_08004DB4]` | C | `void (void)` (1); `u32 (void)` (1) |
| `sub_0800649C` | C | `void (u32, u32, u32)` (3); `void (u8 *, u32, u32)` (1); `void (u8 *, u32, u32, u32)` (1) |
| `sub_0800F328` | C | `void (u32, void *)` (11); `void (void *, void *)` (2) |
| `sub_08010680` | C | `void (u32)` (3); `void (u16 *)` (1) |
| `sub_08011C9C` | C | `void (u32, void *)` (33); `void (u8, void *)` (3); `void (u8, u16 *)` (1) |
| `sub_08016D28` | C | `void (u8)` (2); `void (void)` (1) |
| `sub_08017230` | asm | `s32 (s32, s32)` (5); `u32 (u32, s32)` (1); `u32 (u32, u32)` (1) |
| `sub_0833A7F4` | C | `void (u32)` (2); `void (void)` (1) |
| `sub_0833E36C` | C | `void (u16 *, u32)` (1); `void (u8 *, u8)` (1) |
| `sub_0833E3C8` | C | `void (u16 *, s32)` (1); `void (u8 *, u8)` (1) |
| `sub_0833EF0C` | C | `void (u32, u32, u32)` (2); `void (u8 *, u32, u32)` (1) |
