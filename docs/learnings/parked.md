# Parked functions and known dead ends

Things that were attempted and did *not* match, with the reason. Read this
before picking a ticket: several of these look like easy leaves and are not.
A park is not a permanent verdict — it is a record of what was already tried,
so the next attempt starts from the failure instead of rediscovering it.

## Not functions at all (luvdis false positives)

Seven entries in the 743 count are data runs that the seed heuristic
(`BL` target ∩ `push {..., lr}` prologue) misclassified. A `0xB5` byte
appears in data roughly 1-in-256 of the time, and these landed on one
that a `bl` also happens to point near.

| "Function" | Tell |
|---|---|
| `sub_08026DB6` | `push` immediately followed by `bhi`/`bcs` on no comparison; `.2byte 0xF9BF @ bl lr+894` |
| `sub_0824C6F0` | two `push` in a row, then a solid `.byte` run |
| `sub_0827B7CA` | `strb r5, [r2, r1]` before any register is set up |
| `sub_080462B2` | `.2byte 0xFA4A @ bl lr+1172` — a `bl` into the middle of nowhere |
| `sub_08121316` | `add sp, #0x000`, then a second `push` |
| `sub_08120E3A` | one `push`, then `0xB1xx`/`0xB5xx` table halfwords; no references |
| `sub_08248272` | one `push`, then `0xB1xx`/`0xB5xx` table halfwords; no references |

They are left in `asm/` and must stay there. Do not write C for them. The
743 denominator is therefore ~738 real functions; the count is left at 743
so it agrees with the disassembly and with `progress.py --selftest`.

## Non-interwork epilogues

Two functions end in `pop {r4, pc}` (and `sub_080172C4`'s sibling shape
`mov pc, lr`). Under `-mthumb-interwork` agbcc always emits the
`pop {r4}; pop {r0}; bx r0` form, so the retail bytes are unreachable from
C with the flags the original build used.

`sub_080172C4` itself is solved: it is the `__div0` hook, a bare
`mov pc, lr`, and `__attribute__((naked))` reproduces it exactly
(`src/sub_080172C4.c`). That trick does **not** generalize — a naked
function with a real body means hand-writing the whole body in asm, which
is not decompilation.

27 `pop {r4, pc}` / `mov pc, lr` sites exist across `asm/`. Any ticket
whose target ends that way is blocked on the same wall. Do not add a
compiler flag to work around it (see `CLAUDE.md`, "Never do these").

## The `lsls rB, rA` cross-register-scale family

26 sites, in `rom_0800C98A.s` (5), `rom_0800E732.s` (4), `rom_08016E36.s`
(2), `rom_080172C6.s` (5), `rom_08019D60.s` (3), `rom_0801A56E.s` (6),
`rom_0801B588.s` (1).

The retail code shifts one register by another register's value
(`lsls r4, r5`) while `r5` stays live across the shift and is reused
afterwards. agbcc's `local-alloc.c` allocates the shift-amount register
such that it is treated as dead after the shift, so the natural C
(`x << n` with `n` a live local) produces a copy and a different register
assignment. Root cause is understood; the missing piece is a C construct
that keeps the index live across the shift in a way agbcc's allocator
agrees with. Nobody has found it yet.

Do not attempt to fix this in `tools/agbcc/`. It is vendored and its exact
behavior is what makes every other function match.

## The flag-check scheduling pattern

14 occurrences in the ROM, 0 reachable from current agbcc: the original
compiler scheduled a flag test ahead of an intervening instruction in a way
this build of agbcc will not reproduce from any C arrangement tried so far.
Likely a different point release of the same compiler, or different
optimization ordering. Parked with no known path.

## Style notes that are *not* blockers

- Four decompiled files use raw address casts (`*(u16 *)0x02022E18`)
  instead of `extern` symbols from `symbols.ld`. They byte-match. Worth
  tidying when the surrounding data is named, not before.
- `symbols.ld` has 9 identical duplicate lines. Harmless to `ld`; a
  `sort -u` fixes it whenever someone is editing the file anyway.

- Callee declarations intentionally disagree across files because each
  caller matched with a different shape: `sub_080065A8` is `void(u32)`
  in two files and `void(void)` in four (those callers pass nothing and
  only match that way — r0 carries garbage the callee tolerates);
  `sub_08017230` (__divsi3) returns s16/s32/u16 depending on the caller;
  `sub_0833FF44` is uniformly `void*(void)` after 7340584; `gUnk_03007FF0`
  is u32/u32[]/struct-ptr per file. Don't "fix" these to a single
  canonical signature without re-verifying every caller — the per-file
  shape IS the match. A shared declarations header remains future work.

## Solved: the constant-materialisation order (was 27 functions)

`agbcc` and `old_agbcc` disagree on where a constant is materialised
relative to the memory load it is combined with. The ROM contains both
orders; only `old_agbcc` can produce both. The build switched to it on
2026-09-10 -- see the "Use `old_agbcc`, not `agbcc`" section of
`CLAUDE.md`. `volatile` on the global is the lever:

- target loads the **constant first** -> plain `extern u16 gFoo;`
- target loads the **memory first** -> `extern volatile u16 gFoo;`

`volatile` also stops CSE, so a target that re-reads the same global
twice (once into a local for two tests, once as a call argument) needs
the `volatile` form plus a local. `sub_080144F4` is the worked example.

## Register-allocation ties: one left, and the mechanism is not an excuse

This section used to list seven functions as "ties no C shape has flipped".
**Six of them now match** (`sub_0801238C`, `sub_0800F3C0`, `sub_0800F818`,
`sub_08003F4C`, `sub_080144F4` / `sub_08014A84`, `sub_08003738`), all at the
source level, with no compiler change. Re-check with
`python3 scripts/match.py <name>` before believing any claim below.

The lever that cleared most of them is in commit `bcfef4c`: **where the ROM
shows an extra live register, or an ordering you cannot reproduce, look for a
variable the C writes as a literal.** Declaring `s8 v = 0;` live across the
setup calls and writing `sel = v` where the obvious C says `sel = 0` makes
the local claim a register; constant propagation then folds `v` to 0 and
deletes the loads, but the *allocation survives the value*. That commit also
records the methodological error to avoid here: tracing the mechanism in
`local-alloc.c` explains the output you are getting and says nothing about
which source produces the ROM's, so **do not treat a mechanism trace as an
impossibility proof.**

Before a manual variant campaign on a register-only diff, run
`python3 scripts/permute.py NAME DRAFT.c -j8` (see "Helper tools" in
`CLAUDE.md`). It automates the search that cleared `sub_08001150`. Its
agbcc passes include duplicate and self assignments, the family the
dead write-back store belongs to, but at low weight. Treat a run with no
0 as a lead, not a verdict: its best candidate shows which rewrites move
the allocation.

| Function | Difference | Attempts |
|---|---|---|
| `sub_08015364` | ONE 2-byte run at `0x8015d8f-0x8015d90`: the `gUnk_0202EEB0 = 1;` constant in the state2 track-select arm wants `r2`, ours takes `r0` | ~300 |

Two shapes reach the ROM from opposite sides and neither closes: the current
draft (4042) gets the index group at `0x8015d7e` right and the constant wrong,
while a `volatile`-cast index plus a function-scope `one` (4039) gets the
constant byte-exact and rotates the index group. The blockers are symmetric and
both come from the ROM's own instruction stream, not from the C -- see
`docs/learnings/drafts/sub_08015364-HANDOFF.md` for the allocation data and the
priority arithmetic before spending time here.

`sub_08015364` is 4042 / 4044 bytes, size exact, and its instruction stream
is identical to the ROM's -- same count (1757), mnemonics, immediates, shift
counts, branch targets and pool offsets. A diff normalising only register
names has zero hunks. `docs/learnings/drafts/sub_08015364.c` holds the C and
a long comment with the mechanism and the full list of what has been swept:
48 `volatile` variants, the `u32 addr = (u32)&g;` idiom on 22 globals, all 11
adjacent swaps of the local declaration list, constant-valued locals in three
types at four declaration positions, and the store written as an array, a
`u8 *`, a literal address and a macro.

What the RTL says (`old_agbcc -dl -dg`): the constant is pseudo 861, created
by `movqi`'s expander, block-local in block 160 with `REG_N_DEATHS == 1`, so
`local_alloc` owns it. `find_free_reg` takes the first register outside
`fixed_reg_set | regs_live_at[birth..death) | ~reg_class_contents[class]`,
and `regs_live_at` holds only hard registers plus quantities already
allocated *in this block* (`REG_SET_TO_HARD_REG_SET` masks the pseudos out),
so ours takes `r0`. Between the `bl` at `0x8015d88` and the store there is
exactly one instruction, so at most one local can be born in the window, and
nothing else in the block outlives the call. The two other allocators were
measured rather than argued: making the constant a spilled pseudo puts it in
`r3` via `allocate_reload_reg`'s round-robin (4036/4044), and making it a
short-range global allocno puts it in `r7` for every live range tried,
because `find_reg`'s pass 0 excludes `r0`-`r6`. `src/sub_0833FF44.c`'s own
`u32 one = 1;` also lands in `r7`, hoisted ahead of its loop.

That narrows what to look for, and `u8 f8d0 = sub_0800F8D0(...)` with a use
in the first `if` does move the constant to `r1`, which shows the shape is
reachable -- something has to be live in `r0` across the store while
`&gUnk_0202EEB0` stays in `r1`. No arrangement found yet keeps the rest of
the block intact. Do not reach for the compiler: the same `old_agbcc`
reproduces 257 functions and 1757 of 1757 instructions of this one, this
tree's `local-alloc.c` and `global.c` hard-code an `r0`..`r15` scan with no
`REG_ALLOC_ORDER` hook, and any change to that order moves registers
everywhere.


### Rival rule tested and refuted: QTY_CMP_PRI with `size` in bytes

`QTY_CMP_PRI` multiplies by `qty_size`, which is `PSEUDO_REGNO_SIZE` -- WORDS,
so SImode and QImode both score 1. The obvious rival rule is that the retail
compiler used byte sizes, which would let a pointer quantity outrank a QImode
constant. Built (`make CC1=<patched> check`) and measured:

- **114 of 261 decompiled functions match, 147 break.** Whole-ROM SHA1 fails.
- `sub_08015364` drops from 4042/4044 to 578/4044, and the register it was
  meant to fix does not move: still `movs r0, #1` at 0x8015d8e.

Refuted on both counts. The site is insensitive to allocation *priority*
because the constant is the only local quantity live at that point; only a
quantity or hard register occupying r0 across the store can move it.

### `block_alloc`'s three-quantity sort is not a sort

`local-alloc.c:block_alloc` orders quantities with `qsort` only when a block
has four or more of them. For one, two or three it uses a hand-rolled
sequence, and the three-quantity case is wrong:

```c
    case 3:
      if (qty_compare (0, 1) > 0) EXCHANGE (0, 1);
      if (qty_compare (1, 2) > 0) EXCHANGE (2, 1);
      /* fall through */
    case 2:
      if (qty_compare (0, 1) > 0) EXCHANGE (0, 1);
```

`EXCHANGE` swaps `qty_order[]` slots, but `qty_compare` takes quantity
*numbers*. After the `case 3` exchange, slot 1 no longer holds quantity 1, so
the `case 2` comparison compares the wrong pair. **In a three-quantity block
the allocation order can therefore be non-monotonic in priority.**

`sub_0801238C` is the worked example, and it is why that function matches.
Instrumented `find_free_reg` output for its first block:

```
qty=0 reg=23 born=2  dead=18 nref=7 pri=8750   -> r0   (&gUnk_0202EF00)
qty=2 reg=36 born=8  dead=16 nref=5 pri=12500  -> r1   (the constant 1)
qty=1 reg=27 born=4  dead=18 nref=3 pri=2142   -> r2   (the constant 0)
```

The address is allocated first despite the lowest-but-one priority, which is
how the ROM's `ldr r0,[pc]; movs r2,#0; strb r2,[r0,#0]` -- constant in a
*higher* register than the address -- is reachable at all. Under a correct
sort the constant would have gone first and taken r0.

This is worth checking before declaring any register tie unreachable: count
the local quantities in the block first (`old_agbcc -dl` lists them as
"in block N"). Three is the interesting number.

## The menu-loop family (mostly solved)

`sub_080144F4`, `sub_08014A84`, `sub_0800F22C`, `sub_08014F5C` and
`sub_08012BBC` all match now. Three rules got them there:

1. **The cursor variables are `s8`, not `u8`.** The `lsls #24` / `lsrs #24`
   pair the ROM emits before each use is the u8 conversion of a value
   stored as `s8`; declare them `u8` and agbcc proves the conversion
   redundant and drops it. An `s8` *parameter* additionally produces the
   `adds r4, r0, #0` copy before the narrowing (`sub_08012BBC`).
2. **`gKeysPressed` stays non-`volatile`, with no local copy.** Write
   `gKeysPressed & 1` and `gKeysPressed & 2` and pass `gKeysPressed`
   to the call: old_agbcc reuses one load for the two tests and emits a
   second for the call, which is what the ROM does. A local copy adds an
   `adds r1, r0, #0`; `volatile` adds a third load.
3. The return type is `u8` while the cursor is `s8`, which is what forces
   the `lsls`/`lsrs` pair in the loop tail and the `lsrs r0, rN, #24`
   after `sub_0800420C`.

Start any remaining member of the family from `src/sub_080144F4.c`.

## The eleven open sub_08015364 callees

65 of the 76 callees match. The near-miss C for each of the ten below is
kept in `docs/learnings/drafts/`; start from those files, not from
scratch. Every one of them builds and differs from the ROM only where
noted.

### Resolved: the 92 non-interwork epilogues are all runtime library

**All 92 are runtime-library code: 33 libgcc and 59 newlib. None is game
code.** They are not decompilation targets and should stay as assembly, or
later be replaced by verified library objects. Two independent reviews and
a byte-level identification of every one of the 59 newlib functions agree.

`docs/learnings/runtime-newlib-map.json` maps each newlib address to its
symbol and source file.

The libgcc side is identified by shape in `docs/recon.md`. Four of those
helpers are reachable from plain C, because agbcc emits a bare
`bl __divsi3`, `bl __modsi3`, `bl __udivsi3` or `bl __umodsi3` for `/` and
`%`. `symbols.ld` aliases each name onto the vendored block, so decompiled
C writes the operator instead of calling the `sub_` name:

    __divsi3 = sub_08017230;
    __modsi3 = sub_080172C8;
    __udivsi3 = _08017420;
    __umodsi3 = sub_08017498;

Verified by linking `int t(int a, int b) { return a % b; }` with
`symbols.ld`: the `bl` resolves to `0x080172C8`.

The ROM carries a second copy of each helper in the `0x0834xxxx` region
(`sub_08344BB8`, `sub_08344C50`, `sub_08344DA8`). A linker symbol has one
value, so these aliases serve the main region. A function in the high
region that needs `/` or `%` will link to the low copy, emit a different
`bl` offset than the ROM, and fail `make check` -- call the `sub_` name
directly there.

| Cluster | Range | Funcs | libgcc | newlib |
|---|---|---|---|---|
| 1 | 0x08017230-0x0801767C | 9 | 5 | 4 (`stdio/vfprintf.o`) |
| 2 | 0x080185DC-0x08018948 | 5 | 0 | 5 (`vfprintf`, `wsetup`, `dtoa`) |
| 3 | 0x08019640-0x0801CCD4 | 72 | 22 | 50 |
| 4 | 0x08344BB8-0x08344DA8 | 6 | 6 | 0 |

The vendored `tools/agbcc/libc/` is **newlib** (see its `COPYING.NEWLIB`),
including ARM/RDI monitor support. Cluster 3's 50 newlib functions come
from `stdio/{fflush,findfp,fvwrite,fwalk,makebuf}.o`, `locale/locale.o`,
`stdlib/{mallocr,freer,callocr,mprec}.o`,
`string/{memchr,memcpy,memmove,memset,strcmp,strlen}.o`,
`reent/{sbrkr,writer,closer,fstatr,lseekr,readr}.o`, and
`arm/syscalls.o`. All 59 match the compiled instruction and data bytes
with relocation fields excluded, built with
`old_agbcc -O2 -fno-builtin`, **no interwork**, and the vendored
preprocessing settings; 188 call targets were cross-checked for
relocation-address consistency.

#### Newlib built from source (2026-09-23)

All 34 of the ROM's newlib code objects, plus the data-only `reent/impure.o`,
build from `tools/agbcc/libc` (Makefile `NEWLIB_OBJS`) and link whole at
their ROM addresses. They replaced 73 luvdis blocks: all 59 flagged newlib
blocks, 9 matched `src/` leaves (`_mbtowc_r`, `__malloc_lock`/`unlock`,
`__errno`, `isatty`, `_localeconv_r`, `findslot`, `remap_handle`, `_fstat`),
and 5 "game" targets that were never game code
(`sprintf`, `_Bfree`, `_hi0bits`, `_lo0bits`, `abort`). The newlib run is
0x08017558-0x0801B5EC; `sprintf.o` at 0x08017558 was hidden inside the
`__umodsi3` block.

How it was placed, reusable for libgcc:

- **Locate by masked bytes.** Build every vendored object, then slide each
  `.text` over the ROM with its relocation fields masked. The objects tiled
  the run with no gaps. Two false hits (tiny objects matching inside a
  larger one) are easy to spot.
- **Derive every other address from the ROM's resolved relocations.** Each
  `.text` relocation's ROM value, minus its addend, is the target's address,
  so one pass gives each object's `.rodata`/`.data`/`.bss` base and every
  external symbol. `.rodata` sits in link order at 0x08339464-0x0833967D
  (`impure.o`'s two bytes fill the gap after `dtoa.o`); `.data` is used in
  place in ROM at 0x083FF7BC-0x083FFF04 (`_impure_ptr` 0x083FFAA8,
  `__malloc_av_` 0x083FFAC0); `arm/syscalls.o`'s `.bss` is 0x020004A8, and
  `errno`/`end` are 0x0202F244/0x0202F248.
- **Place data sections inside the one `.text` output section**, between the
  asm fragments cut around them. The linker's zero fill reproduces every
  alignment gap.
- **Aliases live in `ldscript.ld`, not `symbols.ld`.** Game code still calls
  newlib by luvdis name (`sub_08017594 = sprintf;`), and newlib calls the
  asm that remains (`__muldf3 = sub_0801BAE0;`). The RAM-module links read
  `symbols.ld` and have no newlib, so a C-name right-hand side there fails.
- **`errno` is COMMON**; a script definition (`errno = 0x0202F244;`) wins.

**`locale.o` and `arm/syscalls.o` needed the stock compiler.** Each has a
call that passes a string literal next to a register argument
(`strcmp(locale, "C")`, `_write(1, "...", 32)`), and the ROM loads the
address first: the stock `precompute_register_parameters` behaviour that the
fork's patch removed. They were the evidence that led to reverting the
patch (see "Reverted 2026-09-23: the `calls.c` precompute patch"); since
then all 34 newlib code objects build from source, `syscalls.o`'s `.bss`
placed at 0x020004A8 in a NOLOAD section and `end` set in `ldscript.ld`.

#### libagbsyscall from pokeemerald (2026-09-23)

The ROM's BIOS-call wrappers are Nintendo's `libagbsyscall`, in archive
member order (alphabetical) and pokeemerald's exact shapes. Each separately
linked module carries its own copy: the main program (8 at 0x08016E0C), the
high 0x0834 module (5 at 0x08344B60) and the multiboot island (5 at
0x083647F8). All 18 build from `lib/libagbsyscall.s` with
`--defsym L_<Name>=1`; the high and island copies are renamed to their
luvdis names with `objcopy --redefine-sym`, because one link cannot hold three
`CpuSet`s. `include/gba/compat.h` keeps its `u32`-typed shim names
(`sub_08016E10` and two others) through `ldscript.ld` aliases; pointing it at
`syscall.h`'s pointer prototypes adds about 100 int-to-pointer warnings.

Not covered: the two `svc 0x2A` (`SoundGetJumpList`) stubs at 0x0800151C
and 0x0833ABDC. That syscall is not in pokeemerald's newer SDK.

#### EEPROM_V120 from kl-eod-decomp (2026-09-23)

The ROM links Nintendo's EEPROM save library, revision `EEPROM_V120` (the
version string is at 0x083393E0). Its nine functions fill
0x08016E38-0x080171F4 in source order. Six were matched in `src/` as game
code, `sub_08017000` (`ReadEepromDword`) and `sub_080170B8`
(`ProgramEepromDword`) were parked, and the timer interrupt handler at
0x08016E7C was never a luvdis block. All nine now build from `lib/eeprom.c`,
which is `src/eeprom.c` from Dream-Atelier/kl-eod-decomp (Klonoa: Empire of
Dreams links the same revision) without `ProgramEepromDwordEx`. This ROM
doesn't link that function: `_call_via_r0` sits at its address.

**The library was built at `-O1`.** Klonoa's Makefile builds it with
`old_agbcc -O1`, and pokeemerald builds Nintendo's Flash library at `-O`.
At `-O2`, seven of the nine functions differ. That explains the two parked
drafts: their recorded wall was gcse PRE hoisting, and gcse doesn't run at
`-O1`. Both drafts, tuned for `-O2`, still scored closer to the ROM at `-O1`.

At `-O1`, agbcc also emits a table of every global each function
references into `.rodata`. The ROM's 88 bytes at 0x0833940C are that table,
so the object carries its whole `.rodata` (0x083393E0-0x08339464): the
version string, both configs, the timer reload values, then the table.
Its RAM stays extern, fixed in `ldscript.ld`. Game code calls the library
by its luvdis names through `ldscript.ld` aliases.

#### Why `pop {rN, pc}` appears at all

`thumb_pushpop` (`tools/agbcc/gcc/thumb.c:601`) refuses a direct PC pop
when `TARGET_THUMB_INTERWORK` is set, unconditionally -- no optimisation
level and no other flag bypasses it. The runtime objects were built
without that flag, so they carry the other epilogue form. An earlier note
in this file called these bytes unreachable from C; that was wrong, and it
predated the `old_agbcc` switch without being retested. The correct
conclusion is narrower: unreachable *under the project's flags*, and
irrelevant anyway because the functions are not game code.

Related facts on the gate: `naked` suppresses the epilogue rather than
selecting `pop {pc}`; this Thumb backend does not recognise
`is_called_in_ARM_mode`, so that branch in `thumb_exit` is dead;
`section` affects placement only; the `mov pc` patterns in `thumb.md` are
indirect jumps, not returns; a register-held return address uses `bx`
even without interwork.

#### Flag matrix results

Only these cells match:

| Function | Compiler | -O | Interwork |
|---|---|---|---|
| `__muldi3` -> 0x08017398 | either | O2, O3 | off |
| `__pack_d` -> 0x0801B5EC | `old_agbcc` only | O2, O3, Os | off |

Compiler choice is invariant for `__muldi3` (both binaries emit identical
bytes in all eight cells, failures included) but discriminates for
`__pack_d`, where every `agbcc` cell fails -- further independent support
for `old_agbcc`. No test so far separates O2 from O3.

#### Build architecture

Leave `src/` and its flags alone. Newlib now builds this way (above). For
the rest of the runtime assembly, use a separate build group with its own flags:
clusters 1-2 as explicit newlib objects (`vfprintf.o` spans both), libgcc2
source for multiplication and negation while keeping the handwritten
division assembly, cluster 3 as explicit newlib plus float-runtime objects
plus `__lshrdi3`, and cluster 4 left as the duplicate runtime assembly it
is. Reusing identical global library symbols needs separate names or
isolation. Avoid blanket archive linking: member order, extra functions,
data placement and duplicate symbols all matter, and some runtime objects
contain functions already present in the current build. Keep the existing
assembly until each replacement passes placement and full ROM checks.
Changing global flags, or replacing library objects without removing
overlapping definitions, would put the current 250 matches at risk.

#### Consequence for the denominator

The 743 count includes the runtime library, the SDK code and the 7 luvdis
false positives recorded above. None is a decompilation target.
`scripts/progress.py` counts 142 non-targets: the 33 libgcc blocks still in
asm, the 101 `LIBRARY_BLOCKS` (73 newlib, 14 libagbsyscall, 6 `m4a_1.s`,
8 EEPROM), libgcc's `__div0` leaf in `src/` (`RUNTIME_LEAVES`, which the
asm-only epilogue check cannot see), and the 7 false positives. The
game-code denominator is **601**.

### One or two instructions, cause identified in the compiler (5)

| Function | Difference | Cause |
|---|---|---|
| `sub_08014004` | 2 bytes: the two `movs #0` are emitted in the wrong order | Initialising `a` first gives the right order but moves `a` from `r6` to `r7`, because an earlier birth lengthens its live range and lowers `QTY_CMP_PRI`. The two are coupled; 9 shapes tried |
| `sub_08012B50` | prologue narrows `b` then `a`, ours does `a` then `b` | `assign_parms` (`gcc/function.c:4246`) defers every parameter conversion into `conversion_insns`, flushed at 4537, so conversions always emerge in declaration order. A body conversion reorders them but emits `lsls r0,r0,#24 / lsrs r4,r0,#24` instead of the ROM's copy-plus-in-place form |
| `sub_08003738` | 3 instructions permuted at one call site | `precompute_register_parameters` (`gcc/calls.c`) copies any argument whose `rtx_cost > 2` into a pseudo before the cheap constants load, and `thumb.h`'s `CONST_COSTS` gives address constants `COSTS_N_INSNS(3)` with `SMALL_REGISTER_CLASSES` set. The ROM's ldr-last form needs `args[2].value` to already be a REG at expand time. Matched; since 2026-09-23 with register pins on the constant arguments and a stock compiler |
| `sub_0800F3C0` | first loop counter in `r6`, ROM uses `r4` | `QTY_CMP_PRI` tie broken by quantity creation order; 7 shapes tried |
| `sub_08001170` | 4 bytes: agbcc folds `+4` into the load offset, the ROM computes `(base+4)+i` | Address reassociation happens during expansion regardless of parenthesisation, loop form (`goto` included), or operand order. The pool-loaded `5` IS solved: `extern u8 gUnk_00000005[];` used by address, with `gUnk_00000005 = 0x00000005;` in symbols.ld |

### Ruled out: per-file flags for the game-code near-misses

The runtime-library clusters turned out to use different flags, which made
a per-translation-unit flag story plausible for the stuck game functions
too. It is not the answer. All nine remaining drafts were compiled across
`{old_agbcc, agbcc}` x `{-O1, -O2, -O3, -Os}` with interwork on and
byte-compared: **72 cells, no matches.** `sub_08001170`, `sub_08003738`,
`sub_0800F3C0`, `sub_080129E8`, `sub_08012A80`, `sub_08012B50`,
`sub_08013964`, `sub_08014004`, `sub_0801177C`.

Flags can produce an individual symptom in isolation -- `sub_08013964`'s
missing `r6` push appears under `-O1`, and under `-O2 -fforce-addr` -- but
those cells change 65 other lines. The phantom register is coupled to the
source shape, not to a flag. Do not re-run this sweep; extend it only if a
new flag or compiler revision enters the tree.

### The phantom-register family (3)

`sub_08013964` (r6), `sub_08012A80` (r9), `sub_080129E8` (r7). The ROM
saves a callee-saved register and never reads it, so `regs_ever_live` was
set by a pseudo that reload later eliminated. A dead extra parameter does
not do it: `assign_parms` emits the copy but DCE deletes it before
allocation. `sub_080129E8` is the harder case - its r7 is also *stored*
(`movs r7, #0`) and never read.

`sub_08013964` is otherwise byte-identical, and its early exit is a bare
`return;` in an `s8` function - not `return 0;`, which emits
`movs r0, #0; b end` plus a mid-function pool.

### The last three callees, characterised

All three are one or two instructions from matching inside functions that
otherwise reproduce exactly. Drafts are in `docs/learnings/drafts/`.

**`sub_08001170`** differs by **exactly one instruction**:

    ROM:   ldr r1, =0x0801DA90 | mov r8, r1 | mov r5, r8
    ours:  ldr r6, =0x0801DA90 | mov r8, r6

GCC propagates the constant straight into `p`'s register instead of
copying it from `base`; the 2-byte shift and the p/n register swap that
follow are consequences of that one elision. The ROM keeps `base` in
**r8**, a high register, so each use needs its own `mov` -- which is why
it recomputes `base + 4` inside the loop rather than hoisting it.

Tried without success: `base` derived from `p`; a third variable holding
the address; the global inlined; `base` assigned twice to break the
single-set constant equivalence; 14 permutations of local declaration
order; `do/while`, `while` and count-up loop forms; four associations of
the address expression. Hoisting `base` before the `if (cnt != 0)` guard
**does** produce the missing copy and the correct 140 bytes, but then GCC
hoists `base + 4` out of the loop. Something must give both at once.

**`sub_0800295C`** is 9 bytes out, a pure r3/r4 tie between the address
copy for `gUnk_0200215C` and the address of `gUnk_020020E0`. Size,
branches and pool are all correct. `volatile` on either global, extern
declaration order, the parameter type, the type of the unused stack
`buf`, pointer locals for either global, and no-op `(u8)`/`(u32)` casts at
seven separate read sites all leave it at 18 differing lines.

**`sub_0801177C`** needs structural work -- 221 differing instructions in
a 360-instruction function -- but one real fix is recorded in its draft:
`0x06016000` was written as an integer literal, so it is a `CONST_INT`
costing 10 and gets precomputed. Written as an address
(`(u32)gUnk_06016000`, symbol added to `symbols.ld`) it was excluded by the
since-reverted `calls.c` patch and both addresses loaded in parameter order,
matching the ROM. Under the stock compiler, pin the other arguments instead.

That call site then leaves only the third argument, `0x80 << 5`. It is
*shiftable*, so `CONST_COSTS` gives it `COSTS_N_INSNS(2)` = 6, still over
the threshold, and our compiler precomputes it -- the ROM does not. Note
the ROM **does** precompute a cost-10 `CONST_INT` elsewhere
(`sub_080017D0`'s `0x05000318`), so the distinction is not simply
"constants are never precomputed". Argument order is a source-level lever
now (register pins), so do not patch the compiler for this site.

### Unfinished, not blocked (0)

Both entries that stood here are decompiled: `sub_0801177C` (724 b) and
`sub_0800295C` (1808 b). The sizes quoted while they were stuck were the
`thumb_func_start` block sizes, which exclude trailing `.byte` rows and
are therefore lower bounds -- the same trap `sub_0800F8D0` fell into.

### Resolved: `sub_0800F8D0` was mis-scoped

`sub_0800F8D0` is not the 84-byte function the size scan reported. It is a
16-entry jump table whose case bodies run to a shared epilogue at
`_08010058`, spanning `0x0800F8D0`-`0x08010074`, 1956 bytes; luvdis lumped
the cases in as trailing `.byte` rows. It is a real `switch` (agbcc
`mov pc, r0` tablejump) and it matched as one file holding all 16 cases.
**Any size taken from a `thumb_func_start` block that excludes `.byte`
rows is a lower bound, not the size.**

To read a function luvdis truncated this way, disassemble the raw ROM over
the real range instead of the ELF:

    arm-none-eabi-objdump -D -b binary -m armv4t -M force-thumb \
        --adjust-vma=0x08000000 --start-address=0x0800F95C \
        --stop-address=0x08010078 baserom.gba

`scripts/extract.py` refuses a cut that contains `.byte` rows, so this one
was cut by hand: the fragment ended at the function, so truncating it at
the last row before `thumb_func_start` was the whole edit.

## Reverted 2026-09-23: the `calls.c` precompute patch

**The patch was not necessary, and `tools/agbcc` is stock again**: the
submodule points at upstream Dream-Atelier/agbcc `a0f70c9`, so the fork and
CI's access token are no longer needed. The claim
below that `sub_08003738`'s argument order is unreachable from any C was
wrong. Pinning the constant arguments to their registers reproduces it
under the stock compiler:

    register u32 a0 asm("r0") = 0;
    register u32 a1 asm("r1") = 4;
    if (sub_0800295C(a0, a1, gUnk_0202CD90) != 0) {

Hard-register variables are loaded where they are declared, before
`expand_call` precomputes the address, and their argument moves become
no-ops, so the address load lands last. Pinning only `r1` is not enough.

Evidence: every `src/*.c` compiled with both compilers differs in real
codegen in exactly one function, `sub_08003738`; 13 others differ only in
local label numbers. The eight functions re-matched for the patch with a
hoisted local compile identically under stock. With the pin, `make check`
prints MATCH on the stock compiler, and newlib's `locale.o` and
`arm/syscalls.o`, which the patched compiler could not reproduce, build from
source.

**The idiom now:** an address argument loaded before the other arguments
is the compiler's default (a hoisted local also works); loaded after them,
it needs the other arguments pinned with `register ... asm("rN")`.

The original record of why the patch was added follows.

### Original record: the compiler is patched

The `tools/agbcc` submodule points at
[shohamc1/agbcc-heat2002](https://github.com/shohamc1/agbcc-heat2002), a
fork of Dream-Atelier/agbcc carrying one extra commit (`51e46db` on
`a0f70c9`). Upstream history is intact, so `git log` and `git blame` on
`gcc/calls.c` still work and rebasing onto future upstream is a normal
operation. The compiler binary is gitignored, so a fresh clone needs
`git submodule update --init` then `tools/agbcc/build.sh` before
`make check` will pass.

**What it changes.** `precompute_register_parameters()` copies any argument
whose `rtx_cost` exceeds 2 into a pseudo before the cheaper argument
constants are emitted. `thumb.h` rates `SYMBOL_REF` at `COSTS_N_INSNS(3)`
and sets `SMALL_REGISTER_CLASSES`, so for an address constant the copy is
unconditional and no flag reaches it. The patch adds three lines excluding
`SYMBOL_REF`, `LABEL_REF` and `CONST`.

**Why it was needed.** The ROM contains both argument orders for the same
call shape: `sub_080128E0` and `sub_08003738` both call
`sub_0800295C(imm, imm, &global)`, loading the address first and last
respectively. The unpatched compiler emits address-first for both, so
`sub_08003738`'s bytes were unreachable from any C.

**The idiom this creates.** The compiler no longer forces the order; the
source selects it:

| ROM shows | Write |
|---|---|
| address loaded **first** | assign it to a local before the call |
| address loaded **last** | pass the constant directly |

Eight functions matched under the old behaviour by compensating for it and
were re-matched with that one edit each: `sub_080041E0`, `sub_0800F1EC`,
`sub_080102F0`, `sub_08010334`, `sub_08008338` (twice, two addresses),
`sub_080128E0`, `sub_08014278`, `sub_0801661C`.

**The cost-table explanation was tested and refuted.** `gcc/calls.c` is
target-independent, so the better-shaped theory was that the retail
compiler's ARM cost table rated address constants below the `> 2`
threshold, needing no generic change. `COSTS_N_INSNS(N)` is `N * 4 - 2`,
so `COSTS_N_INSNS(1)` is 2 and is not `> 2`; `thumb.h` rates `SYMBOL_REF`
at `COSTS_N_INSNS(3)` = 10, and on Thumb an address constant really is a
single pool load, so 1 looks like the correct value and 3 like an ARM-ism.

Rating it 1 does reproduce the ROM's argument order with clean upstream
`calls.c`. But against the same baseline it breaks **14** functions where
the precompute patch breaks 8, and the six extra failures are not
argument-ordering cases: `sub_08016CB0`, `sub_0833FF44` and `sub_08008A20`
differ by 26, 40 and 125 lines, since `rtx_cost` feeds CSE and allocation.

The ROM's own codegen is consistent with cost 3 everywhere except the
precompute decision. Had the retail compiler used 1, that would show
throughout the ROM rather than only at argument setup, and the 249
functions matching untouched say it did not. So the retail cost model
agrees with the vendored one, and the divergence is specifically the
precompute condition. Do not re-test the cost table.

**Status: validated hypothesis.** 257/257 functions match and the whole-ROM
SHA1 verifies, but that is not proof the retail compiler carried exactly
this condition. Confirmation means finding the upstream revision. If a
future function contradicts the rule, revisit it rather than adding a
second special case. The full evidence -- ~35 source forms, a 16-cell
compiler/-O/interwork matrix, five flags, and four rival patch rules
scoring 12/9/8/10 broken -- is in the fork's README.

**Do not re-run these.** Ruled out before patching: every spelling of a
constant argument; local pointers of three types at every statement
insertion point; variadic, K&R and unprototyped declarations; structs by
value; register pressure from 4 to 12 live values; both vendored trees
(identical `calls.c`); both compiler builds; `-O1/-O2/-O3/-Os`; interwork
on and off; `-fno-expensive-optimizations`, `-fno-cse-follow-jumps`,
`-fno-force-mem`, `-fno-caller-saves`.

A methodological warning for anyone testing further rules: a candidate that
needs to count arguments before deciding requires splitting
`precompute_register_parameters` into two passes, and the original
interleaves each argument's expand/convert with its precompute copy.
Splitting it reorders emitted insns and changes codegen independently of
the rule under test, so such a variant tests a rule *and* a bug. Two
candidates were discarded on that basis after their failure lists turned
out to be artifacts.

## Codegen rules learned in the 204-250 run

- A `goto` loop suppresses loop-invariant hoisting and loop rotation:
  GCC 2.95 only sees loops through front-end loop notes. If the ROM
  re-loads a global address every iteration, or spins on a flag with no
  guard load ahead of the loop, the source used `goto`.
- Keep a `<< 16` inside the loop body and loop-invariant motion hoists it
  into the preheader after the base-address load. That reproduces the
  "constants first, shifts later" order in `sub_08003F4C`.
- Storing a call result through a temp moves the destination address
  computation after the value: `x = f() + w; p->field = x;` versus
  `p->field = f() + w;`.
- A `u8 t = v;` temp for a call argument can flip register assignment;
  pass `v` straight to the call, CSE reuses the narrowed temp. Conversely
  two `sel = v;` statements sometimes need merging into
  `if (A || B) sel = v;` so both paths reach a shared block.
- Repeated reads of a global with no intervening call do NOT imply
  `volatile`: a volatile MEM cannot fold into a `zero_extend`, so it
  forces an extra register move. `gUnk_020020A0` reads three times and is
  plain.
- Statement position for `n--` is load-bearing: GCC PRE-hoists `j + 1`
  and `n - 1` to the inner preheader in source order.
- A bare `return;` in a non-void function produces an early exit that
  branches straight to the epilogue with no value materialised.

## Resolved 2026-09-13: sub_0800CB18 (matched, 68 bytes)

The whole register web hung on the tail: the ROM builds the table index
IN PLACE on y (`y = y + 0x80; y = y << 8; y = y + 0x80; return t[a + y];`
with `t = gUnk_0806C97C;` assigned BEFORE the updates so the pool ldr
comes first). With no index temps stealing r0, the table qty takes r0,
which frees r2 for the `a` loop-local — both old diffs resolved at once.
`a / 2` (not `(a + (a >> 31)) >> 1`, which emits `asrs #31` for the sign
bit) and the zero-return block placed via
`if (y <= 0x7F) goto table; zero: return 0; table: ...` complete it.
See src/sub_0800CB18.c.

## Quarantined 2026-09-13 (round 2): sub_0800C2CC and sub_0800C358

`docs/learnings/drafts/sub_0800C2CC.c` (140 bytes, fresh attempt this
round): instruction stream/pool/prologue fully solved via
`q = (u16 *)(4 * e[1] + (u32)p);` (temp-first plus) + two-statement
sum; remaining diff is one allocation web (v wants r1 not r2, dx/dy
swapped).

### Resolved 2026-09-14: sub_0800C358 (MATCH, 216 bytes)

`src/sub_0800C358.c` matches all 216 bytes at `0x0800C358`. Compute the
table offset before adding the data address:

```c
entry = (u8 *)(p->unk100[xi * 48 + yi] + (u32)p->unkFC);
```

This one expression selects `p` in r3 and `xi` in r2, and places the
`unkFC` address calculation after the table-index calculation. The former
pointer-first expression selected the wrong registers and computed that
address too early. Keep the raw-field shifts for `yi` and `xi`.

Two independent Luna experiments and `python3 scripts/match.py sub_0800C358`
confirmed the full match. No register declarations, compiler changes, or
flag changes were needed. The C object replaces the original asm at its ROM
address. A clean copy of the commit contents passed `make check` and
`make test`; unrelated local drafts were excluded from that copy.

## Resolved 2026-09-15: sub_08001150 (matched, 32 bytes) — the dead write-back globalizer

Parked after ~30 variants with one stable 4-instruction register swap
(narrowed `v` wanted r1, the tag load r3; every shape gave the reverse).
A 5-agent permutation campaign (~200 variants) closed it. **The lever: an
eliminated write-back that keeps a loaded value live across a branch.**
Appending `*(u32 *)(r2 + 0x34) = t;` as the last statement of the if-body
changes nothing semantically and emits nothing (the store writes back the
just-loaded value and is dead-store-eliminated), but its *use* crosses the
basic-block boundary — which moves the tag pseudo out of block-local
allocation into global allocation, where the ordering is
v→r1, tag→r3, ptr→r2: exactly the ROM's homes. The draft's own analysis had
identified "the tag pseudo being global" as one of two flip routes and then
declared it "not constructible without extra instructions" — wrong, in the
same way the `bcfef4c` note warns about. Two agents converged on this fix
independently (one via flat pointer writes, one via struct fields with an
early return); `register`-asm pins on r3 also matched but are unnecessary.

Campaign negatives worth keeping: literal-valued locals (the `bcfef4c`
missing-variable axis) reached diff 9 of 32 bytes but never 0; operand
order and spelling at every address site (`r2+OFF` vs `OFF+r2` vs
`((u16*)r2)[i]`, compare spelling, v-use spelling) is fully inelastic here —
53 variants, one object. Generalisation: when a *block-local* quantity sits
in the register a *global* allocno needs, look for a zero-emission second
use of the block-local value after the branch (a write-back store of the
loaded value is the canonical form). Try this on remaining
"register-permutation-only" drafts before any deeper analysis.

## Resolved 2026-09-16: sub_08016ED8 (matched, 100 bytes) - a hard-register pin decides the ior's output

The draft was four instructions off at `0x08016EEA`: the ROM computes the
IE update as `ldrh r1; orrs r1, r2; strh r1`, and every C shape gave
`ldrh r2; orrs r1, r2; strh r1`. The fix pins the mask to r2 and keeps it
inside the `|=`:

```c
register u32 mask asm("r2");
*(volatile u16 *)0x04000200 |= (mask = 8 << gUnk_02000494);
```

The pass that decides this is regmove, not local-alloc. A thumb `orrs` is
two-address, so regmove rewrites the ior's output to be one of its inputs.
A `u16 |=` narrows the ior to 16 bits, so the IE value reaches it as
`subreg:SI (reg:HI)`. regmove skips a subreg input and picks the mask
pseudo, and the mask chain then outranks the value in local-alloc. When
the IE value is a plain SImode register (`volatile u32` IE, wrong bytes),
regmove picks the value and the ROM's registers fall out. A hard register
can't become the output either, so pinning the mask leaves the value
chain as the only candidate.

What doesn't reach it:

- **A plain SImode value from C.** A volatile load can't be merged by
  combine, and a non-volatile one folds into the ior as
  `subreg:SI (mem:HI)`. `u32` locals for the value, the mask, or the
  result all keep the subreg.
- **The pin as its own statement.** `mask = 8 << x;` before the `|=`
  fixes the cluster but loads the IE address after the mask, which
  shifts every later address register. Keep the assignment inside the
  `|=`, or load the address first through a pointer local.

`sub_08016F80` uses the same lever (`register u16 v asm("r4")` as an ior
input). Try it on any diff where an ior, and, or xor output lands in the
wrong chain.

Permuter trial: `scripts/permute.py` ran about 30 minutes with `-j8` from a
score of 25 and found nothing lower. Its C parser can't accept `asm()` pins,
so it couldn't reach this fix.

## Resolved 2026-09-23: sub_08000958 + sub_08000972 — built from lib/m4a_1.s

Confirmed hand-written: they are `MPlayJumpTableCopy` and `chk_adr_r2` /
`ld_r3_tp_adr_i` from the MP2K driver's `m4a_1.s`. The whole of
0x080004B8-0x080010CC (and its high copy at 0x08339B78) is that one file.
`lib/m4a_1.s` is pokeemerald's `m4a_1.s` with five edits for this older
revision (listed in its header: no compressed-sample mixer path, fw kept in
`lr`, no `SoundMainRAM_Unk1`/`Unk2`, no second status check in `MPlayMain`,
no track count in `ply_note`). It builds both copies byte-for-byte; the six
blocks it covers (`sub_08000958`, `sub_08000972`, `sub_08000DC8` =
`TrackStop`, and their high twins) are `M4A_BLOCKS` in `progress.py`.
To find the edits, assemble pokeemerald's file, match each routine against
the ROM with relocations masked, and diff the instruction streams of the
routines that miss; most "misses" are only pc-relative offsets shifted by an
earlier size change. The original analysis follows.

### Original analysis (2026-09-14)

The pair shares literal pool `_08000988` (guide step 6a: extract together or
not at all), but the stronger result is that no agbcc C can produce these
bytes at all — it is hand-written assembly in the retail source:

- The caller keeps its loop state in r0-r3 ACROSS the `bl` callee
  (`ldr r3,[r2]; bl sub_08000972; stm r0!,{r3}; adds r2,#4; subs r1,#1`).
  All four are call-used registers; agbcc's reload must move every live
  value into r4-r7 (or spill it) around any call, so the ROM's register
  choice is structurally unreachable.
- The callee returns its result in r3 and pops the CALLER's r0 back
  (`push {r0}; ...; movs r3,#0; ...; pop {r0}; bx lr`) — a hand-rolled
  custom convention; any C callee ends `add r0, r3, #0; bx lr` (AAPCS
  return in r0), and a single-reg `push {r0}` prologue never appears in
  `tools/agbcc/gcc/thumb.c` (pretend-args pushes rN..r3, reload spills
  via `str [sp,#off]`).
- The caller is a leaf-call idiom `mov r12, lr ... bx r12` around a `bl`;
  `thumb_function_prologue` always pushes lr for any non-leaf, and IPREGISTER
  (r12) appears in the compiler only in the >12-byte struct-return epilogue.

Swept and refuted: two-function splits with 4-arg/value/out-param callees,
a single merged function, and a 16-byte struct return (GCC 2.95 returns
structs via hidden memory pointer). The identical sibling pair
sub_0833A018/sub_0833A032 (same bytes except the pool constant) is the same
hand-asm macro instantiated twice. Full analysis and the closest reachable
C shapes were in `docs/learnings/drafts/sub_08000958.c` (removed on
resolution; `git log` has it).

## Resolved 2026-09-15: sub_08006A34 (matched, 2240 bytes)

`src/sub_08006A34.c` matches. Its header records all three levers. Two of
them are worth trying on other register-only drafts.

**Shared multi-block variable defeats a local tie.** At `0x8006c98` the
sum was tied to the dying partial by `block_alloc`, not steered by the
global `set_preference` that the old header blamed. `combine_regs` refuses
to tie a pseudo that isn't local to its block. One function-scope
`u32 time;` assigned at the two unsigned compare sites made the sum's
register span several blocks. It then took the first free register, `r1`,
as the ROM does. Check the ROM first: the time sum appears seven times, and
only the two sites that use `r1` share the variable. So look for identical
expressions whose destination register differs between copies.

**Inline register pins keep evaluation order.** At `0x8006b84`,
`register s32 dx asm("r6");` assigned inside the original expression
(`(dx = corners[1] - l4) * ...`) matched. The same pin as a separate
initialiser fixed the registers but moved the subtraction.

**A constant derived from a zero needs an int temporary.** The ROM computed
`p->unk4D = -1` as `subs r0, r1, #1`. A literal takes the byte store's
constant fast path and loads `movs r0, #255`. `p->unk4D = z - 1` is narrowed
to QImode, so combine folds it back to a constant. `s32 m = z - 1;
p->unk4D = m;` keeps the subtraction in SImode on the same zero register that
the next store uses, and CSE keeps it because an SImode -1 costs more than
`(plus reg -1)` on Thumb. When the ROM derives a constant from a register
that holds zero or a nearby value, look for this shape.

## Campaign record 2026-09-22: the endgame push (603/646)

Every eligible function in the ROM has now been attempted. Since the
2026-09-21 campaigns, 89 more functions matched (514 -> 603 of 646; 82.0%
of code bytes). `make check` MATCH at every commit.

**What worked, in order of lever value:**
1. **Twin/sibling mining.** The 0x0833xxxx-0x0834xxxx region is the same
   game module as 0x0800xxxx-0x0801xxxx with lookup tables relocated
   ROM->RAM — 20+ functions this campaign matched as table-swap ports,
   most on the first compile. Find twins with a NORMALIZED-instruction
   search (mnemonics with registers/immediates blanked, difflib ratio
   0.88+; the three known-real twins score 0.955/0.959). A raw byte-diff
   "site count" is NOT a similarity metric — a few long differing runs
   imitate a twin (129 bytes in 5 runs once scored as "5 sites").
2. **The D684 rewrite method** (see the resolution section below) closed
   6 of 9 parked drafts; the hardest (sub_0833D31C, permuter floor 505)
   fell to its matched low twin's source, ported wholesale.
3. Second-chance rounds with the newest levers closed sub_0800920C.

**New levers proven this campaign:**
- Re-mention a pointer's global in the for-init (`for (j=0, q=gFoo;...)`):
  cse turns the second pool load into a copy at the for-init position —
  the late `mov r8,r0` callee-saved stash, in plain C.
- A dead `u8 pad[0x28]` / `s32 tmp[4]` FIRST IN DECLARATION grows the
  frame and pushes a specific spill to its ROM slot (sub_0800920C,
  sub_0800CD38; sub_08004980 precedent).
- Chained assignments (`g = x1 = pc->f02;`) defeat CSE across aliased
  s16 param stores; `goto` INTO an if-body places a shared return block
  mid-function instead of merged at the end.
- **agbcc's first cse canonicalizes const-0 mode-dependently**: SI/HI-mode
  lookups resolve to the first-assigned zero pseudo, QImode lookups to
  another. An `int zero` assigned once forces the QI site to rematerialize
  `movs rX,#0` at the store (sub_08011B08's `zero` is load-bearing).
- The jump pass ALWAYS converts `if (c) p=&A; else p=&B;` into
  default+override at -O2; write `x = *(p = &A)` / `x = *(p = &B)` inside
  the arms instead, and cross-jumping re-merges the derefs (sub_0833F468).
- Busy-wait shape: `first = gFlag; t -= 3; if (first == 0) do ;
  while (gFlag == 0);` with gFlag volatile (sub_0833BF80).
- `t = arg1; ... t -= 3;` (plain copy, then compound sub) defeats the
  tree fold of `(u8)(x-3)` into `(u8)(x+253)`; loop bounds `i != N`, not
  `i < N` (GCC reverses `<` into a countdown).
- Explicit `*24` pointer scaling synthesizes `((i*3)<<3)` where implicit
  array scaling picks a different shift (sub_0833F468).

**Wall classes now precisely characterized (drafts in drafts/, residuals
in their headers):**
- **gcse PRE hoisting** (sub_08004B1C; sub_08017000 and sub_080170B8 were
  the EEPROM library, built at -O1 where gcse doesn't run): the
  earlier "goto loops suppress invariant hoisting" note was INCOMPLETE —
  gcse runs on the raw CFG before loop.c; goto only suppresses LICM.
  `-dG` dumps name each insert. Partial counter-levers: volatile-cast one
  read of the hoisted expression's global; split a pointer init inside
  the loop; place the counter increment as the body's first statement.
- **RAM-linked switch tables — SOLVED as a class** (2026-09-22). The
  module images were compiled to run from EWRAM; their jumptables embed
  the module's link addresses. The build now reproduces this faithfully:
  match.py links RAM functions at their EWRAM base (RAM_LINK_OVERRIDES,
  derived from each table-base constant's self+4 pattern) standalone
  (symbols.ld + generated defsyms, no -R); the Makefile links each such
  C object into a standalone image at its EWRAM base and embeds it as
  data at the ROM address via an .incbin wrapper with a .thumb_func
  symbol; module-internal callees resolve through a typed .thumb_set
  alias stub (ram/aliases_0834.s) -- script absolutes get interwork
  veneers, and the main ELF's real definitions would override the
  aliases at ROM addresses. Landed: sub_08364550 (480b, multiboot
  island, base 0x02000668) and sub_08340EFC (400b, base 0x0200847C).
  Remaining: sub_08341288 (base 0x02008808, machinery ready; draft at
  798/804 bytes -- six instructions in two analyzed hunks, the const-set
  elision rule traced); sub_08342258 and sub_08343A6C are ALSO own-libgcc-blocked.
  The luvdis-mangled table/case bodies are repaired by an assemble-and-
  byte-compare oracle (docs: the sub_08364550 commit).
- **High-region own libgcc -- SOLVED as a class** (2026-09-22): the
  high module resolved `/` and `%` to its own libgcc copy (sub_08344BB8,
  sub_08344C50, sub_08344DA8), but symbols.ld's single __divsi3 alias
  points low, and calling sub_08344BB8 by name loses the libcall's
  hard-r0 return and flips the allocation. Every caller at or above
  sub_0833AD00 uses the high copies and none below sub_080199F0 does
  (checked against the ROM's bl targets), so the Makefile now runs
  `objcopy --redefine-sym` on objects built from src/sub_083[3-9]*.c,
  renaming __divsi3/__modsi3/__umodsi3 to the high copies. Write `/`
  and `%` as operators there. sub_08343EA8 MATCHED with this: it is
  instruction-identical to the matched sub_0800D684 and was ported from
  that source. sub_08343A6C and sub_08342258 MATCHED the same day,
  each ported from its low twin (sub_0800D248, sub_0800A80C) once the
  twin was matched. Before drafting a 0x0834 function from scratch, look
  for an instruction-identical low twin: normalise both streams (strip
  pool offsets and branch targets) and compare.
- **Spill-slot order is gcse hash order (sub_0800D248, 2026-09-22).**
  Pseudos that PRE creates for hoisted expressions are numbered in
  hash-bucket order, and reload assigns spill slots in pseudo order, so
  the frame layout of a function with many spilled invariants depends on
  `expr_hash_table_size = (real_insns / 2) | 1` at gcse time. The insn
  count includes insns that combine, jump, or flow delete later, so
  code-neutral rewrites (a `u8` local, an `s16` prototype parameter, an
  early `return 0` that cross-jumps) shift the table size by two insns
  each. To diagnose: `-dG` prints the table size and each expression's
  hash; the hash of `(plus (reg R) (const V))` is `(13772 + R + V) % M`.
  Fit M from the ROM's slot order, then tune the count. Other levers from
  that function: `long long` temporaries whose dead high half occupies a
  register (changes which regs reload may spill), a struct declared
  separately instead of `arr[N]` (its address becomes a PRE pseudo with
  no home, so reload inherits it), and `inline` non-static helpers whose
  out-of-line bodies land after the function.
- **Allocation battles** (~15 drafts, several ONE instruction from
  matching: sub_0800BEA4 one reload copy, ~~sub_080047E8 one zero-pseudo
  swap~~ MATCHED 2026-09-22, sub_0833F468 and ~~sub_0833BF80~~ (MATCHED 2026-09-23;
  its pool word was a `gUnk_08338FB0` typo) one pool word
  each at FULL instruction parity — NB: re-verified 2026-09-22, the
  BANKED drafts for F468/BF80 are NOT at parity (89%/72% of instructions
  differ); the parity state was a lost working copy). Root causes per RTL
  dumps: global-alloc priority `floor_log2(nrefs)*nrefs/live_length` with
  pseudo-number ties, plus jump.c cross-jump pairing (sub_0800AB78: which
  branch's bl survives the merge is emission-order-driven; min-2 pairing
  reduced to min-1 by the CODE_LABEL decrement).

## Session record 2026-09-22: the 21-draft near-miss sweep

One full pass over every parked near-miss draft. **1 matched and
integrated: sub_080047E8** (606/646). Everything else re-characterized;
the materially-improved drafts (11B08, 4A20, 7C44, A80C, 03330) are
banked with updated headers. New levers and walls:

- **`register`-pinned locals win stubborn allocation ties.** 47E8's
  "unflippable" zero-pseudo swap (50k permuter iters at floor 60) fell to
  `register u8 z asm("r10")` on first compile (a pin of w to r2 also
  matched). The pin is legal in `src/` (0x08016ED8 precedent) — the
  permuter just can't parse it.
- **Direct volatile casts share ONE address pseudo across calls.**
  Writing every KEYINPUT read as `*(volatile u32/u8 *)0x04000128`
  directly (no pointer variable) makes cse share a single pool load,
  homed callee-saved across the intervening call (verified in isolation).
  A pointer VARIABLE carrying the same address is always defeated by
  REG_EQUIV: cse2 substitutes the known constant at later uses and the
  home is freed — an `asm("r7")` pin does NOT prevent this (the pin binds
  the def site only). This rebuilt 11B08/4A20 prologues byte-exact.
- **Per-use reload copies vs one coalesced copy:** an UNPINNED local homed
  in a high reg gets per-use `mov r0,r9` copies at each OR; PINNING the
  same variable coalesces them to one copy (reload inheritance). Target
  11B08/4A20 wants FIVE per-use copies; both spellings reachable, neither
  fully matches — the remaining delta on both twins is one {m,keyaddr}
  r7/r9 home swap (target: keyaddr=r7 direct + m=r9 with per-use copies;
  ours: m=r7 + keyaddr=r9 stash). 11B08 at 312/316, 4A20 at 312/316,
  both 151-153 instructions with only register names + that swap left.
- **sub_08004B1C:** the retail code reads `idx` UNINITIALIZED from r4
  (`lsls r0,r4,#2` with no r4 def — a real bug faithfully compiled).
  GCC assigns the uninit pseudo a garbage register, and WHICH register
  follows the rest of the allocation; several source shapes flip it
  (r4/r7). Remaining delta is a 2-instr r7-push ripple.
- **Frame pads:** 7C44 needs `u8 pad[0x2C]` (frame 64), 03330
  `unused[20]` — banked into the drafts. A80C's 20 bytes turned out to be
  a wholly unused local plus nothing else once the spill went away.
- **Permuter gaps, re-confirmed:** (a) it cannot score RAM-linked
  functions (sub_08341288 run sat at score floor 3475 with 848 constant
  errors — the EWRAM-base link isn't reproduced for candidates); (b)
  sub_08004B1C hits `TypeError: '<' not supported between NoneType and
  int` in `_eval_candidate` (STRUCT_FLOOR vs None `_last_score`) and
  every iteration reports "12 permuter failures" with base score stuck
  at 1000; (c) BEA4's pin-free base floors at 1430 after 1.2k iters
  (the r10 pin the match needs is unparseable). Manual iteration beat
  all three runs.
- **Continuation session (same day): the RAM-link permuter is FIXED and
  the 08341288 fragment repaired** (commit 1d7bc94): permute.py now links
  BOTH target and candidate at the EWRAM base (mixed bases made every
  objdump annotation line differ), and the luvdis-mangled switch case
  bodies in asm/rom_08341282.s are real instructions again (verified by
  the make-check byte oracle). sub_08341288 is now 804/804 bytes,
  395/401 instructions, TWO hunks, both root-caused to reload/remat
  behavior (see its draft header): (a) the q pseudo's const def is
  rematerialized at the strb (operand-0 address reload processed first
  -> addr steals r0) where the retail build homed q in r0 un-remat'd;
  (b) the *p4e zero's early def is deleted by the cse const-0 mode
  table and rewired to the later HI zero. ~20 source spellings each,
  invariant; asm pins cascade. The permuter ran 2800 iterations at
  STRUCT_FLOOR=1000 without luck — the needed def-early/store-late
  split is not a statement permutation. These two are the best
  compiler-side-look candidates found so far (right alongside
  08343EA8's libgcc-alias need).
- 17000's "one allocation decision" is `dest` homed r5 in target vs r8
  in ours (r7-push cascade); parameter pins (`register ... asm()` on a
  PARAMETER) are a syntax error in agbcc, and a pinned LOCAL copy costs
  the same cascade differently. EAA0/9C4C: target saves THREE high regs
  (r8/r9/sl) vs our two — one more live-across-call variable (9C4C's
  stashes arg1 to sl across the very first call).

## Batch notes 2026-09-22: second smallest-functions campaign (51 matched)

51 more functions matched and integrated (90-362 bytes; one commit per
function, `make check` MATCH throughout). Progress 514 -> 565 / 646.

**Resolved from earlier park notes:**
- `sub_080019F4`, `sub_08001A74` and their high twins `sub_0833B0B4` /
  `sub_0833B134` all match. The 01A74 fix is pret's `TrkVolPitSet`
  statement structure (pokeemerald `src/m4a.c`); 019F4 is a byte-for-byte
  port of the matched twin with only the callee renamed. The "428 bytes"
  figure quoted for sub_08001A74 below was the block *with trailing data*;
  the function is 180 bytes (ends `bx r0` at 0x08001B26).
- **Twin correction**: `sub_08002638`'s high twin is `sub_0833BDB4`, NOT
  `sub_0833BCF8` (which is a standalone bubble sort). Both 02638 and BDB4
  are matched; BCF8 remains a near-miss (np home r8 vs r10).

**New levers proven this campaign:**
- Consecutive constant stores are auto-related by CSE: `*p = 0x808;
  p -= 1; *p = 0x740;` makes GCC 2.95 emit the `ldr r2,=K / subs r2,#imm /
  adds r0,r2 / strh` chain. No staging locals, no pins. (sub_08002638)
- A division that "should" inline but calls `__divsi3` may be hand-written
  fixed point in the original source: `((s32)(a - b) * (s32)0xC28F5C29) >> 4`
  is exact for /0x190 on 0x190-aligned pointers and defeats synth_mult;
  removing the helper call also fixed the whole allocation. (sub_0834108C)
- `register u32 m asm("r12")` for an and/or mask forces the
  `movs rX / mov ip, rX` pair — general form of the regmove-ior lever.
- Assignment-in-condition `(m = CONST) & global` materialises the constant
  before the load.
- GCC 2.95 emits walk deltas from CSE-canonicalised `p+K` chains, so the
  last post-increment of a walk folds away unless consumed: write the final
  store without `++` and subtract from the pre-increment pointer.
  (sub_08005C18)
- Matched-twin C ports byte-for-byte across engine copies when only the
  callee changes (sub_080019F4 <- sub_0833B0B4, sub_0833E714 <- sub_08005C18).

**Still near-miss, drafts in `docs/learnings/drafts/` (residuals in headers):**
`sub_0833DA34` (const pair swap), `sub_08343DF8` (idx home r6 vs r7),
`sub_0833EE88` (glyph-arm r0/r1 tie, floor 50), `sub_08004B1C` (3-qty
key-test rotation — the block_alloc sort-bug case), `sub_083415B0`
(q stashed to r8 too early), `sub_0833BCF8` (np r8 vs r10),
`sub_08017000` / `sub_080170B8` (r7-push cascade + CSE2 pool fusion; since
built at -O1 as the EEPROM library),
`sub_0833D31C` (asrs-vs-lsrs lever conflict, floor 505). All are
register-allocation ties; none hits a documented compiler wall.

## Batch notes 2026-09-21: smallest-52 campaign

52 functions matched and integrated in one campaign (24-112 bytes each; commits
`073d5a9..6b7e9a5`, one function per commit, `make check` MATCH at every step).
Findings worth keeping:

- **`sub_0800F0BC` is blocked, corroborated** (already marked BLOCKED in
  `docs/decomp-queue.md`): the tail is `subs r0, r0, r1; bgt _label` — the
  branch reads the SUBS flags with no `cmp`. agbcc's thumb.md has no
  `*subsi_compare0` pattern, and a corpus scan of all matched objects found
  zero `sub`+`bcc` sites. The `register u32 pcv asm("r15")` idiom does
  reproduce the `mov r2, pc` prologue, but the residual diff is exactly the
  missing `cmp r0, #0` (26 vs 24 bytes). Draft kept at
  `docs/learnings/drafts/sub_0800F0BC.c`.
- **Two more luvdis false positives**: `sub_08120E3A` and `sub_08248272`
  (both `non_word_aligned_thumb_func_start`). A `push {…}` opcode byte
  (0xB5xx) inside a data run; each "function" is one instruction followed by
  `.byte` rows. Same tell as the five known ones, which makes it seven, not
  five. Both are in `LUVDIS_FALSE_POSITIVES` since 2026-09-23, with the
  selftest updated.
- **The epilogue pop register reveals the return type** (session discovery,
  from `thumb_exit` in `tools/agbcc/gcc/thumb.c`): `pop {r0}; bx r0` = void
  return, `pop {r1}` = returns a ≤4-byte value, `pop {r2}` = ≤8 bytes,
  `pop {r3}` = larger. A "void-looking" function ending `pop {r1}; bx r1`
  RETURNS a value — declare it `u32` (avoids spurious narrowing pairs).
  Proven on `sub_0833D6D8`/`sub_0833D6A0`/`sub_0833D7E8`.

## Resolved 2026-09-23: sub_08000DC8 + sub_0833A488 — `TrackStop`, hand-written

These are `TrackStop` (plus `ChnVolSetAsm`, `ply_note` and the rest of the
file's tail) from the MP2K driver's `m4a_1.s`, so the `tst rX, rY` below is
simply hand-written. Both copies now build from `lib/m4a_1.s`; see the
resolved entry for sub_08000958 above. The original analysis follows.

### Original analysis (2026-09-16)

Both halves of this m4a twin pair are blocked in the compiler, not by
register allocation. The ROM uses a two-register `tst r0, r1`, and
`tools/agbcc/gcc/thumb.md:818` defines the only `tst` pattern in the whole
machine description as single-operand:

    (define_insn "tstsi"
      [(set (cc0) (match_operand:SI 0 "s_register_operand" "l"))]
      ""
      "cmp\\t%0, #0")

`tst` appears exactly once in that file, so no C agbcc accepts can emit the
register-vs-register form. A test compile of `if (head->flags & 0x80)`
yields `ands r0, r1; cmp r0, #0` instead.

A second, independent blocker sits in the same function: `ands r0, r3; beq`
reuses the flags straight off the ANDS, and agbcc always inserts a separate
`cmp rN, #0` before the branch. No available C construct produces bare
flag reuse after ANDS.

The high twin sub_0833A488 has the same `tst r0, r1` and the same fused
`ands`/`beq` at the same relative offsets (asm/rom_08339B78.s), so it is
equally blocked, not merely likely to be. Leave both in asm.

Earlier draft and analysis were in `docs/learnings/drafts/sub_08000DC8.c`
(removed on resolution; `git log` has it).

## Near-miss drafts parked 2026-09-16 (m4a low region)

Three m4a low-region functions have drafts that build but do not yet match.
They are NOT blocked in the compiler as far as anyone has shown; they were
abandoned mid-iteration when a session limit killed the run. Start from
these files, not from scratch:

- `docs/learnings/drafts/sub_080019F4.c` (128 bytes) — diverges at the tail
  `bx r0`; the trailing flags check was being reshaped when work stopped.
- `docs/learnings/drafts/sub_08001A74.c` (428 bytes) — diverges at the tail
  `bx r0`.
- `docs/learnings/drafts/sub_08001C20.c` (1340 bytes) — diverges around
  `pop {r4}`.

Their high twins (sub_0833B0B4, sub_0833B134, sub_0833B2E0) were never
attempted. sub_08002638 and its twin sub_0833BCF8 were never attempted
either.

### The m4a engine is duplicated at delta 0x3396C0

Established 2026-09-16 and worth reusing. The ROM carries the MP2K/m4a
sound engine twice: a low copy near 0x08000260 and a high copy near
0x08339920, offset by exactly 0x3396C0. Engine ident is 0x68736D53
("Smsh"), one revision below pret's 0x68736D54.

The delta holds ONLY for a twin function's own address. It does NOT hold
for callees or data:

- Shared leaf routines exist once, not twice. The `swi 0x0B` CpuSet wrapper
  is at sub_08344B64; the BX trampoline table at `_08344B80`.
- RAM globals in the high copy sit at unrelated addresses (e.g.
  gUnk_02000580 -> gUnk_020375D0, a delta of 0x37050).
- One literal in sub_0833AF48 is 0x020017A9 where the low twin has
  gCallback_08000B69, which is not the delta of anything.
- The two copies are configured differently, not just relocated. The low
  copy runs 5 music players and the high copy 4, read from the linker
  constants `gNumMusicPlayersLow` and `gNumMusicPlayersHigh` in
  `m4aSoundInit` (sub_08001170 / sub_0833A830). See
  `docs/m4a-map.md`.

Read every call target and literal off the target disassembly. Computing
them from the delta produces confident, wrong answers.

Also note: the span 0x080004B8-0x08000958 is undecoded `.byte` data in
`asm/rom_080004B8.s` with no `thumb_func_start`. It is real MP2K code (it
carries the hi-register epilogue at 0x080008E0 and the `Smsh` ident), but
luvdis never split it, so it is invisible to progress.py's numerator and
denominator alike.

## Resolved 2026-09-22: sub_0800D684 (matched, 2006 bytes)

`src/sub_0800D684.c` matches. The 49-recolour residual of the old draft was never
reachable from the old draft, because the draft was fitted to the instruction
stream with carriers, self-stores and pins, and its pseudo structure differed
from the retail source in one place that decides the whole loop allocation.
The fix came from rewriting the function as plain C from the asm and then
comparing the allocator's decisions (`global.c:find_reg`, instrumented to print
each allocno's conflicts, `regs_used_so_far` and `regs_someone_prefers`)
against what the ROM's registers imply. Three findings transfer:

**A two-element array written element-wise occupies a register pair for the
whole loop.** The rotation deltas are `s32 d[2]`, assigned as `d[0] = pa[4];
d[1] = pa[5]; d[0] -= pb[4]; d[1] -= pb[5];`. An 8-byte array is a DImode
pseudo, and a store to one element is a partial def, which flow treats as a
use as well, so the pseudo is live from function entry to its last use. It
therefore conflicts with every loop allocno and needs two consecutive
registers, r5:r6. That is what pushed `e`, `u`, `w`, `v[0]`'s temporary and
`other` to r4, r7, r8, r9, r10, spilled `car`, and put the pre-loop
address copy in r7. The old record's "two invisible occupants of r5/r6" and
its spill-set difference (`{0,1,2,3,4}` versus `{0,1,2,3,6}`) were both this
one array. When the ROM avoids a consecutive register pair across a region
with no visible use of it, look for a small array or struct written by
element. `d[2]` as two scalars, or as a whole-struct copy, both lose this.

**A pointer local used only for one call still gets a callee-saved register.**
`pa = gUnk_0202CCB0; sub_0800D5D4(car, pa);` is the address-first idiom from
the compiler-patch section, but here the loop also hoists the same address,
and cse-after-loop turns the hoisted load into a copy of `pa`. That extends
`pa` across the call, so it is a global allocno rather than a local one, and
it takes r7 (never used by `local_alloc`, since r7 is the frame pointer
register). If `pa` were also used inside the loop it would be rematerialised
everywhere, including at the call.

**Declaration order sets spill-slot order.** `reload` hands out slots in
decreasing pseudo number, and the frame grows downward, so the ROM's slot
layout (`car` 0x24, `a2` 0x28, `i` 0x2C, `m` 0x30, `q` 0x38, `count` 0x40)
reads off the declaration order directly: `count` is declared after `m` and
`q`. Address-taken locals (`hit`, `v[4]`) are placed at expand time and come
first.

Smaller points, all recorded in the source header: `t = (w * e) / u;
t += v[0];` must be two statements (one expression ties the division result
to r0); the post-loop speed clamp needs its own variable rather than reusing
`t`; `other = base` is assigned before the pre-loop call; and the range
pre-check is `px = car->x; px -= other->x; pz = (car->z - other->z) >> 8;
px >>= 8;`, because `px` must be the load's target while `pz`'s two operands
must be separate temporaries (the block has three local quantities, so
`block_alloc`'s three-quantity sort applies).

The pre-resolution record (about 150 lines of spill-set and allocator
tracing) and the `docs/learnings/drafts/sub_0800D684*` drafts, handoffs and
`d684-tools/` were removed when the function matched; `git log` has them. The
one thing worth keeping from them: 325 000 variants of a fitted draft could not
reach a different pseudo structure. When a draft is instruction-identical but
tens of registers off, rewrite from the asm and diff the allocator, do not
permute.

## Resolved 2026-09-23: sub_0833BF80 (1584B) — MATCHED

Parked 2026-09-22 with gcse PRE owning `(u8)t`; matched the next day. The
last session's fixes, each reusable:

- **An empty-body `do ; while` always gets a pre-test.** `expand_end_loop`
  (the Cygnus loop-test variant) rotates every loop whose exit is not the
  last insn, and jump.c's `duplicate_loop_exit_test` then copies the test
  in front of the `NOTE_INSN_LOOP_BEG`. A bare `L: ldrb; cmp; beq L` with
  no pre-test comes from a `goto` loop, which has no loop notes. A goto
  loop also left gcse PRE free to insert the ROM's preload order.
- **A label on a `return` blocks jump.c's range swap.** The "if (foo)
  bar; else break;" optimization inverts `if (c) goto L1; A; goto L2; L1:
  B; goto X; L2:` into `B` first. It needs the first label after the
  conditional jump to be the jump's own target, so `if (flag != 0) { ret1:
  return 1; }` (with another path doing `goto ret1`) keeps the source order.
- **ARM promotes `s8` locals zero-extended** (`PROMOTE_MODE` forces
  `UNSIGNEDP` for QImode). An `s8 rr = f();` compiles to `lsrs`, and the
  test folds to `cmp` on the shifted value. The ROM's `asrs r1; cmp r1`
  with the same register stored later is an `s32` local assigned from an
  `s8`-returning call.
- **Check which block a statement lives in before chasing registers.** Two
  of the largest deltas were structural: a copy block inside the else arm,
  and a call inside the `if`. The branch targets in the diff show both.
- **The "one pool word" was a typo**: the draft passed `gUnk_08338FB0`
  where the ROM (and every other caller of `sub_0833B074`) uses
  `gUnk_02038FB0`.

Findings from the parked sessions, still reusable:

**1. A 3-case switch ALWAYS emits a median-rooted tree — read the walk to
recover the source shape.** gcc 2.95 builds case AVL trees (rotations on
balance ±2), flattens to a list only when the root has a left child, then
`balance_case_nodes` splits any list of >2 nodes at the middle (the
cost-table lopsided path is unreachable when any case value is a control
character — 1, 2 fail `cost_table[i] >= 0`). So cases {1,2,39} in ANY
source order emit `cmp #2; beq/bgt; [left 1]; [right 39]`. The ROM's
dispatch at 0x833c470 is `cmp#1;beq C1 / cmp#1;ble D / cmp#2;beq C2 /
cmp#39;beq C27 / b D` — a right-chain 1→2→39, impossible from one 3-case
switch. It is `if (r != 1) { if (r > 1) switch (r) { case 2: ...; case
0x27: ...; } } else { case-1 body }`: the else-arm placement puts the
==1 body out of line after the dispatch (bodies at 0x833c482/48a follow
`b D`), the `r > 1` guard is the `cmp#1; ble D`, and the 2-case switch
{i=2,39} keeps its AVL chain (2 nodes, no split) emitting the beq chain.
Verified in the draft: this source compiles to the ROM dispatch exactly.

**2. gcse PRE on a register cast-pair is a wall class worth naming.** When
a u8 extraction of a u32 local appears twice, PRE hoists the `<<24` into
the variable's home register (two edge inserts + `lsrs` extracts), where
the ROM keeps independent `lsls/lsrs` pairs per site. Killed levers: deep
casts (front end folds them), re-deriving from the argument (allocator
keeps the argument callee-saved instead), shifting gcse-time insn counts
(dead stores are deleted before gcse), and every u8/s8/pad perturbation
(expr table pinned at 349 buckets, PRE persisted). The `-dG` dump names
the expression (`PRE: redundant insn N (expression E) in bb B, reaching
reg is R`) — diagnose there first. The surviving hypothesis: the original
source split the value across two pseudos gcse could not canonicalize,
or its bb structure around the first site's predecessors differs in a way
that breaks partial availability.
