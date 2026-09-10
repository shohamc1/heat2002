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

## Register-allocation ties that no C shape has flipped

Six functions differ from the ROM by nothing but which hard register a
quantity landed in. Instruction sequence, count, and size all match.

| Function | Difference | Attempts |
|---|---|---|
| `sub_0801238C` (2nd loop) | address in `r1`/value in `r0`; ours swaps them | 6 |
| `sub_0800F3C0` (1st loop) | counter in `r4`; ours uses `r6` | 7 |
| `sub_0800F818` | mixed: the `0x04000128` read wants non-`volatile`, the write wants `volatile` | 6 |
| `sub_08003F4C` | both mask constants hoisted above the shifts | 5 |
| `sub_080144F4` / `sub_08014A84` | one register short; `keys` read lands in `r0` then copies to `r1` | 8 |
| `sub_08003738` | literal pool emitted mid-function, ours is longer | 1 |

`local-alloc.c` orders quantities by
`QTY_CMP_PRI = floor_log2(n_refs) * n_refs * size / (death - birth)`, ties
broken by quantity number (creation order). Declaration order, temporaries,
pointer-vs-index forms, and `for`-vs-`do/while` were all tried and none
moved the assignment. What is missing is a C construct that changes the
*creation order* of the two quantities, not their live ranges.

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

### Unfinished, not blocked (2)

| Function | State |
|---|---|
| `sub_0801177C` (644 b) | Structurally correct and 4 bytes short; the register allocation then differs throughout. Needs the missing 4 bytes found first, after which the cascade should resolve |
| `sub_0800295C` (1486 b) | Largest remaining. The switch shape was identified before the run was cut off; the draft is 1836 bytes against a smaller target |

### Mis-scoped, needs its own ticket (1)

`sub_0800F8D0` is not the 84-byte function the size scan reports. It is a
16-entry jump table whose case bodies run to a shared epilogue at
`_08010058`, spanning `0x0800F8D0`-`0x08010078`, roughly 1960 bytes;
luvdis lumped the cases in as trailing `.byte` rows. It is a real
`switch` (agbcc `mov pc, r0` tablejump) and decompilable, but only as one
file holding all 16 cases. **Any size taken from a `thumb_func_start`
block that excludes `.byte` rows is a lower bound, not the size.**

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
