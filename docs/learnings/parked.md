# Parked functions and known dead ends

Things that were attempted and did *not* match, with the reason. Read this
before picking a ticket: several of these look like easy leaves and are not.
A park is not a permanent verdict — it is a record of what was already tried,
so the next attempt starts from the failure instead of rediscovering it.

## Not functions at all (luvdis false positives)

Five entries in the 743 count are data runs that the seed heuristic
(`BL` target ∩ `push {..., lr}` prologue) misclassified. A `0xB5` byte
appears in data roughly 1-in-256 of the time, and these five landed on one
that a `bl` also happens to point near.

| "Function" | Tell |
|---|---|
| `sub_08026DB6` | `push` immediately followed by `bhi`/`bcs` on no comparison; `.2byte 0xF9BF @ bl lr+894` |
| `sub_0824C6F0` | two `push` in a row, then a solid `.byte` run |
| `sub_0827B7CA` | `strb r5, [r2, r1]` before any register is set up |
| `sub_080462B2` | `.2byte 0xFA4A @ bl lr+1172` — a `bl` into the middle of nowhere |
| `sub_08121316` | `add sp, #0x000`, then a second `push` |

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

Leave `src/` and its flags alone. If runtime assembly is ever replaced by
source-built objects, use a separate build group with its own flags:
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

The 743 count includes 92 runtime-library functions and the 5 luvdis
false positives recorded above. Neither group is a decompilation target,
so the real game-code denominator is about **646**. `scripts/progress.py`
still divides by 743; a future change could report both.

### One or two instructions, cause identified in the compiler (5)

| Function | Difference | Cause |
|---|---|---|
| `sub_08014004` | 2 bytes: the two `movs #0` are emitted in the wrong order | Initialising `a` first gives the right order but moves `a` from `r6` to `r7`, because an earlier birth lengthens its live range and lowers `QTY_CMP_PRI`. The two are coupled; 9 shapes tried |
| `sub_08012B50` | prologue narrows `b` then `a`, ours does `a` then `b` | `assign_parms` (`gcc/function.c:4246`) defers every parameter conversion into `conversion_insns`, flushed at 4537, so conversions always emerge in declaration order. A body conversion reorders them but emits `lsls r0,r0,#24 / lsrs r4,r0,#24` instead of the ROM's copy-plus-in-place form |
| `sub_08003738` | 3 instructions permuted at one call site | `precompute_register_parameters` (`gcc/calls.c`) copies any argument whose `rtx_cost > 2` into a pseudo before the cheap constants load, and `thumb.h`'s `CONST_COSTS` gives address constants `COSTS_N_INSNS(3)` with `SMALL_REGISTER_CLASSES` set. The ROM's ldr-last form needs `args[2].value` to already be a REG at expand time |
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
(`(u32)gUnk_06016000`, symbol added to `symbols.ld`) it is excluded by the
fork's patch and both addresses load in parameter order, matching the ROM.

That call site then leaves only the third argument, `0x80 << 5`. It is
*shiftable*, so `CONST_COSTS` gives it `COSTS_N_INSNS(2)` = 6, still over
the threshold, and our compiler precomputes it -- the ROM does not. Note
the ROM **does** precompute a cost-10 `CONST_INT` elsewhere
(`sub_080017D0`'s `0x05000318`), so the distinction is not simply
"constants are never precomputed". Do not widen the compiler patch on the
strength of this one site; it wants the same treatment the current patch
got -- rival rules built, whole corpus regression-tested.

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

## The compiler is patched: no precompute of address constants

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

## Parked 2026-09-14: sub_08000958 + sub_08000972 — hand-written asm, not a C target

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
C shapes: `docs/learnings/drafts/sub_08000958.c`. Leave both halves in asm.

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
`sub_08017000` / `sub_080170B8` (r7-push cascade + CSE2 pool fusion),
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
  five. The 646 game-code denominator was deliberately NOT adjusted — that
  needs a matching `progress.py` change and selftest update, not a drive-by.
- **The epilogue pop register reveals the return type** (session discovery,
  from `thumb_exit` in `tools/agbcc/gcc/thumb.c`): `pop {r0}; bx r0` = void
  return, `pop {r1}` = returns a ≤4-byte value, `pop {r2}` = ≤8 bytes,
  `pop {r3}` = larger. A "void-looking" function ending `pop {r1}; bx r1`
  RETURNS a value — declare it `u32` (avoids spurious narrowing pairs).
  Proven on `sub_0833D6D8`/`sub_0833D6A0`/`sub_0833D7E8`.

## Parked 2026-09-16: sub_08000DC8 + sub_0833A488 — `tst rX, rY` is unreachable

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

Earlier draft and analysis: `docs/learnings/drafts/sub_08000DC8.c`.

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

## sub_0800D684: instruction-identical, 49 register encodings short

`src/sub_0800D684.c` (2006 bytes) reproduces the ROM's instruction stream
byte for byte from 0x800d684 to 0x800de58. `match.py` still reports MISMATCH
because 49 register operands differ (45 single recolours priced 5, 4 double
priced 10; `sdiff` 265 under `d684-tools/filediff.py`). No shape, immediate or
pool-offset difference remains.

Both residual causes were traced into the compiler and neither is expressible
in C:

1. **uid 91's reload pair** - **explained** (cont. 122).  `allocate_reload_reg`
   walks `spill_regs` cyclically from a cursor reset once per pass and advanced
   once per allocation.  Instrumenting `reload_reg_used` at that insn gives
   `{0 2 4 5 7 8 9 10 11..16}` - r0, r2 and r4 in use, r1/r3/r6 free.  With our
   array {0,1,2,3,6} the constant's scan takes index 4 = r6; the ROM's
   instruction `adds r0, r3, r1` follows exactly if its array was
   **{0,1,2,3,4}**: index 4 = r4 (in use, skipped), index 0 = r0 (in use,
   skipped), index 1 = r1 (free).  So the two compiles differ in their *spill
   set*, and everything downstream of that pick follows.  Why the sets differ
   is the open half: cont. 116's candidate is that our `d1` is homed in r6
   (the tail walks memory through `[r6]`), forcing r6 into the set.
   Corroborated four ways: the used-register bitmap above; the `SPILLSET`
   dump, which shows pinning `d1` to r4 removes r6 from the set (cont. 123);
   the whole-function usage counts (r6: 46 in the target, 70 here - cont. 125);
   and the forced-allocation map, where matching the target's register at that
   site makes the rest worse, which only a differing array explains (cont. 120).
   Our body cannot be compiled without r6 - every r6-free `RT_SET` variant
   ICEs - so the configuration cannot be tested here.

2. **A home swap between `e` and `d1`** - at the two `(d1 = (e = ...))` carrier
   guards the ROM's result lands in r4 and ours in r6.  r6 is *dead* across
   those blocks in the ROM (bracketing uses at 0x800d7ce and 0x800d932), so
   this is a `find_reg` priority outcome, not an occupancy: ours is
   `e`->r4 / `d1`->r6 and the ROM's is `e`->r6 / `d1`->r4.  Closed across every
   carrier spelling, nesting, comma, drop, role-split, dead-variable and pin
   variant, and across the literal-variable lever from commit `bcfef4c`
   applied in seven forms (all neutral or worse - the assignments fold away
   before global-alloc, and this C has no conditional loop-carried slack left).

   Mechanism (cont. 129/130): the destination of the carrier instruction is
   the *result temporary*, not `e` itself, and r4 is **live** at that insn -
   the used-register mark set there is exactly the callee-saved registers the
   loop keeps across calls.  Ours has `e` resident in r4 through the loop, so
   the temporary cannot take r4 and lands in r6; the ROM's lands in r4, so its
   `e` was resident elsewhere.  So the variable whose home differs is `e`.

   Quantified: `find_reg`'s priority is `floor(log2(refs)) * refs /
   live_length`, and the `.greg` dump gives `d1` = 70 refs / 357 insns (1.18)
   versus `e` = 48 refs / 138 insns (1.74).  `e` outranks `d1` and takes r4;
   the ROM needs the reverse, i.e. `d1`'s live length below ~241 insns instead
   of 357.  Shortening it means splitting the variable, which adds a
   declaration and costs 2 hunks, and routing the carriers through an existing
   variable instead only moves the deviation (best 325).

Roughly 325 000 semantics-preserving source variants across ten lanes, plus
spelling sweeps over constants, casts, widths, declaration order, alias
respelling per occurrence, bounds, comparisons, increments and prototypes, all
bottom out at 265.  The one compiler rule change that reproduced the pick
produced 2022 bytes with the corpus broken and was reverted.

Full record, tooling (including the `reload_set.patch` diagnostic compiler),
lane reports and the integration recipe: `docs/learnings/drafts/sub_0800D684-NEXT.md`.

**Quantified (cont. 139/140).** Counting register occurrences over the function:

    ours:  r5 x40, r6 x70
    ROM:   r5 x38, r6 x46

24 extra uses of r6, and the diff list's pairs are dominated by `(r6, X)` - our r6 against the
ROM's r4/r3/r2/r1/r0.  The pairs are not a bijection, so this is not a global renaming: it is one
extra long-lived resident, pseudo 36 (`d1`), homed r6 because its conflict set contains hard r4
(inherited from the pinned `cc2 asm("r4")`).  The ROM's `lsls r0, r4, #16` shows its `d1` in r4.

**The homes are reachable, and it does not help.**  Giving 36 r4 - leaving 45 (`e`) in r4 as
well, disjoint ranges, exactly as the ROM has them - scores **3031**, and the other 45 sites
break with it.  The two halves of the residual are in tension: fixing the four carrier
instructions costs far more than it gains.  That is why every one-lever move fails, and why the
265 baseline is stable in both directions.

**Twelve compiler rules measured, all reverted, none better than 265:** scan start `i = -1`
(7185); no cursor advance for constants (7185); per-insn cursor reset (7518); `REG_ALLOC_ORDER`
swap (no effect - neither `find_reg` nor `find_free_reg` consults it); r6 not a spill candidate
(2056); `RT_SET=01234` (cc1 ICE, `NEWSPILL` cascade); deny r4 to all (28173); deny r4 to `e`
(385); give `d1` r4 (3031); swap r4 between them (3151); `combine_regs` off (29707); and
`prune_preferences` off (neutral - `regs_someone_prefers` is empty, so the barrier is a plain
conflict and not a tunable).

**The reload-side account is closed (cont. 141-149).**  Running the reload instrument's own
`RT` trace, which reports each pick directly rather than reconstructing it:

    RT uid=91 rnum=1 reg=6 idx=4 nspills=5 last=3 in=(const_int 399) out=

Five-entry pool, index 4 -> r6, reloading the constant 399 - cont. 122's account, now confirmed
by measurement.  Two structural facts explain the rest:

* `calculate_needs_all_insns` (reload1.c:924) runs before `reload_as_needed` (1023), so the pool
  is **fully built before any register is chosen** - which is why uid 91 reports `nspills=5`
  while its own candidate list shows only the first entries.
* r6 enters the pool from the **tail** (first `NEWSPILL ... reg=6` is at uid 1447, the `[r6]`
  walker), so `d1` being homed r6 and r6 being a spill register are two faces of one fact.

The whole residual therefore reduces to one sentence: **the ROM's code has a need for r4 at some
insn where ours has a need for r6, and `{0,1,2,3,4}` versus `{0,1,2,3,6}` - hence everything
downstream - follows entirely from that difference in which registers are live when.**

Measured and refuted since this entry was first written: fifteen spill-set configurations (six
ICE outright, `{0,1,2,3,4}` among them), thirteen compiler rules (scan start, cursor advance and
per-insn reset, `REG_ALLOC_ORDER`, r6 as non-candidate, reload preference order, `combine_regs`,
`prune_preferences` - the last neutral, `regs_someone_prefers` being empty), and the whole-function
counts: ours r5 x40 / r6 x70 against the ROM's r5 x38 / r6 x46.

Two tools are kept for the next attempt, both in `drafts/d684-tools/`: `reload_set.patch` (the
`RT`/`NEWSPILL`/`ORDER` instrumentation, whose `pot` output is the *candidate* list and not the
pool - the trap that produced one false contradiction) and `uidprint.patch` (emits `INSN_UID` as
an assembly comment, so address-to-uid maps are measured rather than assumed).

**Why r6 enters the pool, measured (cont. 158-165).**  At uid 1447 a reload needs a register of
class `BASE_REGS` (`class=4`; `thumb.h`: `BASE_REGS = 0x020ff` = r0-r7 + sp).  The candidate scan
offers, in order:

    pot: 12 6 9 10 0 4 3 2 1 8 7 5 11 13 14 15 16
    uses(by regno): r0=24 r1=77 r2=30 r3=27 r4=24 r5=427 r6=0 r7=315 r8=200 r9=0 r10=0 ...

r12 is rejected by the class test; r9 and r10 are r8-r15, also outside BASE_REGS; **r6 is unused at
this insn**, so it is the first free in-class candidate and is taken.  It enters `used_spill_regs`,
`finish_spills` sorts the set to `{0,1,2,3,6}` (index 4 = r6), and uid 91's scan reaches index 4,
putting constant 399 in r6 where the ROM's `adds r0, r3, r1` has r1.

The ROM's pool is `{0,1,2,3,4}`: its code needed r4 at some insn where r4 was free, and never
needed r6 at all.  So the residual is which values are live at one instruction - a property of the
body, and every lever attempted (15 spill sets, 13 allocator rules, 19 flags, 20 `volatile`
variants, two compiler builds, ~325 000 source variants) scores worse than the 265 baseline.

One trap for the next reader: the ORDER dump's `uses` line labels the **sorted** array by position,
not by register - reading it as if indexed by regno produced a wrong "r6 has 27 uses" claim
(cont. 158, retracted in cont. 165).  Key on `hard_reg_n_uses[k].regno`.

**The weights, derived (cont. 166-173).**  `order_regs_for_reload` zeroes each entry *inside* its
outer loop, so iteration `i` wipes whatever earlier iterations added to `hard_reg_n_uses[i]`.
A register `h` therefore keeps only contributions from iterations `i >= h` that are not bad:

    uses[h] = |{ i : h <= i < 17, i not in bad }| x refs(h)

which reproduces all eight measured weights exactly (24, 77, 30, 27, 24, 427, 315, 200) and makes
the observed `12 - h` form a special case.  It matters only as documentation: the ordering test is
the *binary* unused/used split, so r6 - with no live resident - is weight 0 under any of this.

Three explanations of the weights were proposed and refuted by measurement before the code was
re-read (cont. 166 sum over live resid ents, cont. 169, cont. 170 sum over all residents); the
empirical fit was then checked on a second, independent chain (cont. 172) before being derived
(cont. 173).  Same discipline as the rest of this file: measure, record the fit, then explain.
