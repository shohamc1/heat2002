# Handing off sub_08015364

**State: 4042 / 4044 bytes.** Size exact, 1757 of 1757 instructions identical,
a register-normalised diff has zero hunks. One 2-byte run differs:

```
8015d8c  ldr  r1, [pc, #144]     @ &gUnk_0202EEB0   both
8015d8e  movs r2, #1      ROM   |  movs r0, #1      ours
8015d90  strb r2, [r1, #0] ROM  |  strb r0, [r1, #0] ours
8015d92  ldrb r0, [r5, #0]                          both
```

That is `gUnk_0202EEB0 = 1;` in the state2 track-select arm. The C is in
`docs/learnings/drafts/sub_08015364.c` (long header comment with the full
analysis). Copy it to `src/` to build; delete it again before `make check`.

## What I think is happening, and where I may be wrong

The address is loaded one instruction before the constant and stays live across
the constant's whole range. Both allocate first-fit from the same free set, so
whichever is allocated first takes the lower register. The ROM has address r1 <
constant r2, so the address went first - which requires it to be block-local. It
isn't: that pseudo serves five stores across five basic blocks (the `= 1` plus
the four conditional `strb r4,[r1,#0]`), so it is a global allocno and is
assigned after every local quantity. I could not break that contradiction.

Checked with an instrumented `old_agbcc` (a copy of `gcc/` with a printf in
`find_free_reg`; it reproduces the shipped binary byte-for-byte). For the
constant: `born=24 dead=26 nref=4 pri=40000 used=.......XXXXXXXXX` - r0 to r6
all free, so first-fit takes r0.

**Do not trust that argument too far.** Six functions `parked.md` called
unflippable register ties were all solved at source level afterwards, and that
file used to present the same kind of mechanism trace as an impossibility proof.

## Tried and measured

- 48 `extern volatile` variants, one per global. Best non-neutral: 4038.
- The `u32 addr = (u32)&g;` idiom on all 22 scalar globals with 3+ uses. Best: 4030.
- All 11 adjacent swaps of the local declaration list. All 4042, all r0.
- `u8` / `u32` / `s32 one = 1;` at four declaration positions: 4036. Shared
  across the four `= 1` sites: 2720. With the state2 unlock arms: 4012.
- `gUnk_0202EEB0 = one = 1;` - this keeps the ROM's ldr-then-movs order - with a
  second use at six positions in three types. The constant becomes a short-range
  global allocno and lands in **r7** every time.
- The store written as an array, a `u8 *`, `*(u8 *)0x0202EEB0`, and an
  `((u8 *)&g)[0]` macro. Splitting the address so the `= 1` store gets its own
  pseudo does not work - CSE merges them back.
- Six `sub_0800F8D0` signatures (void, no prototype, int, u8, u32, s32 return;
  u8 and u32 parameter; `(void)`-cast call). All 4042, all r0.
- Compiler rival rule: `QTY_CMP_PRI` with `size` in bytes instead of words.
  **114 of 261 functions match, 147 break**, and the target instruction does not
  move. Refuted on both counts.

## The one lever that moved it

`u8 f8d0 = sub_0800F8D0(...)` with a use in the first `if` puts a live value in
r0, and the constant moves to **r1** (whole-function score drops to 2725). So
the shape is reachable: something has to occupy r0 across the store. The problem
is that the value must be consumed inside that same block, which deletes the
ROM's `ldrb r0,[r5,#0]` at 0x8015d92. If you can find a way to keep a quantity
in r0 there without consuming it, that is the crack.

## Read first

`docs/learnings/parked.md` has two findings from this session:

1. `block_alloc`'s three-quantity sort is not a sort - it swaps `qty_order`
   slots while comparing quantity *numbers*, so blocks with exactly three local
   quantities allocate out of priority order. That is why `sub_0801238C` matches
   with the constant in a higher register than the address, which is the exact
   relation this function needs. Count the local quantities in a block
   (`old_agbcc -dl` lists them as "in block N") before calling a tie unreachable.
2. Commit `bcfef4c`'s lever: where the ROM shows an extra live register or an
   ordering you cannot reproduce, look for a variable the C writes as a literal.

Do not change the compiler without evidence that source-level alternatives cannot explain the difference. `make check` currently prints MATCH; keep it that way.

## Follow-up: the exact r2 store is reachable through reload

The original draft is still the best: **4042 / 4044**, unchanged. The compiler
was not modified. Baseline `make check` and `make test` passed.

A useful combined experiment scores **4039 / 4044**, with the correct size and
**the entire instruction stream from 0x08015d86 onward matching exactly**.
Apply these three changes to the original draft:

```diff
     u8 track;
+    s8 one;
 
+    one = 1;
     gUnk_0202F030 = 0;
```

In the state2 arm only:

```diff
-        gUnk_020020CC = gUnk_083FDE2D[gUnk_0202ED70];
+        gUnk_020020CC = gUnk_083FDE2D[*(volatile u8 *)&gUnk_0202ED70];
         sub_0800F8D0(gUnk_0202ED70);
-        gUnk_0202EEB0 = 1;
+        gUnk_0202EEB0 = one;
```

The complete remaining diff is:

```text
address   ROM                         variant
8015d7a   ldr  r1, [pc, #184]          ldr  r2, [pc, #184]
8015d7c   ldr  r0, [pc, #240]          ldr  r1, [pc, #240]
8015d7e   ldrb r2, [r5, #0]            ldrb r0, [r5, #0]
8015d80   adds r0, r2, r0              adds r0, r0, r1
8015d84   strb r0, [r1, #0]            strb r0, [r2, #0]
```

**Why this matters:** keeping r0 live across the flag store is not necessary.
The `one` local is rematerialised by reload, not allocated as the original
block-local literal. On its own it gives r3 and three later register-pair
changes (4036 matching bytes). The volatile table index prevents its load
from becoming a memory-equivalent reload; that removes a preceding reload
allocation, and the rematerialised `one` now receives r2. Subsequent reload
choices also return to the ROM's registers. The remaining problem is entirely
in allocation of the preceding lookup's destination address, table address,
and index. The volatile access is a diagnostic source form, not evidence
that the original global was volatile.

Further source experiments did not improve on the original draft:

- Constant-local lifetimes at eleven positions, six integer types, and reuse
  of existing non-live locals; additional compare/store uses of that local.
- The rematerialised constant combined with scalar/array address locals,
  including state2-only address substitutions.
- Single-access volatile casts throughout the state2 track accesses; index
  and argument temporaries, casts, and a shared index/argument temporary.
- The 4039 variant with destination/table/index locals in all six orders,
  pointer and integer address forms, reversed pointer-addition expressions,
  and destination/table volatility or signedness.
- Call parameter widths with the rematerialised constant; chained flag
  assignments and separate assignments in subsets of the four reset arms.
- Comma/statement-expression call-plus-store forms, 64-bit integer constants,
  const/register locals, and scalar-in-aggregate constant forms.

No fixed-register variables, inline assembly, compiler flags, or ROM edits
were used. These results do not establish a need for a compiler change.
The next useful source-level target is the five-byte lookup allocation above,
not another attempt to keep r0 live across the call.

---

## Session 2 findings (still 4042; the mechanism note above is wrong in part)

### The ROM itself proves a block-local constant cannot be `r2` here

`sub_08008090` contains this shape at `0x8008126`, and it already matches:

```
8008120  ldr  r0, [pc]   @ &gUnk_0202CAD0   block-local address
8008122  movs r2, #0                        GLOBAL allocno (stored twice)
8008124  strb r2, [r0, #0]
8008126  ldr  r1, [pc]   @ &gUnk_0202A53C   GLOBAL allocno (stored twice)
8008128  movs r0, #1                        block-local constant
800812a  strb r0, [r1, #0]
...
8008140  strb r2, [r1, #0]                  both globals reused here
```

That is our exact configuration: a global address in `r1` and a block-local
constant. The retail compiler put the constant in `r0`, which is what we emit
at `0x8015d8e`. The same file shows a constant that is a *global* allocno
landing in `r2`. So the constant at `0x8015d8e` is not a plain block-local
pseudo, and no amount of reordering inside block 160 will move it.

### Why `local_alloc` cannot produce the ROM's pair

`find_free_reg` takes the first register outside
`fixed_reg_set | regs_live_at[birth..death) | ~class | eliminables`. For the
constant, birth/death are 24/26, so only `regs_live_at[24]` matters, and that
holds hard registers plus quantities already allocated **in this block**.
Getting `r2` needs both `r0` and `r1` marked there. `r1` can only be marked by
a local quantity whose range covers index 24, and that quantity would conflict
with the address allocno's range, which starts at index 22. `global_alloc`
respects local assignments, so the address could then not be `r1`. The pair
(address `r1`, constant `r2`) is unreachable from `local_alloc`.

### The three allocators, measured

| Route | Register | Whole-function score |
|---|---|---|
| `local_alloc`, block-local constant | `r0` | 4042 (current draft) |
| reload rematerialisation (`u8 one = 1;`) | `r3` | 4036 |
| `global_alloc`, long-range constant | `r7` | worse |

`r3` is not arbitrary. The `ldrb r2, [r5, #0]` at `0x8015d7e` is itself a
reload insn (`old_agbcc -dg` shows it as insn 5257, uid >= 5000), so
`allocate_reload_reg` leaves `last_spill_reg` on `r2` and the next reload takes
`r3`. `last_spill_reg` is a function-global round-robin over `spill_regs`.

### The 4039 shape, and why it caps there

Removing that `ldrb` reload shifts the round-robin by one and the constant's
reload lands on `r2`:

```c
u8 one;                 /* declared last; `one = 1;` is the first statement */
...
gUnk_020020CC = gUnk_083FDE2D[*(volatile u8 *)&gUnk_0202ED70];
sub_0800F8D0(gUnk_0202ED70);
gUnk_0202EEB0 = one;
```

**4039 / 4044, `movs r2, #1` correct**, but five bytes break at
`0x8015d7a-0x8015d84`: the `volatile` cast turns the index read into a real
pseudo, and a real pseudo there has the shortest live range, hence the highest
`QTY_CMP_PRI`, and always takes `r0`. The ROM needs that group allocated in the
order `&gUnk_083FDE2D`, `&gUnk_020020CC`, index, which requires the index to
have the *lowest* priority of the three. Its range is two index units, the
shortest possible, so that ordering is not reachable while it is a local
quantity. The three-quantity sort bug does not reach it either: the two orders
it can produce are `[q0,q2,q1]` and `[q2,q1,q0]`, and the one needed is
`[q1,q0,q2]`.

### What is left

The constant has to be a `global_alloc` allocno whose `movs` is emitted at
`0x8015d8e` and that conflicts with something in `r0`. That needs a pseudo
that is set there, used there, and referenced in a second basic block without
emitting an instruction. Nothing in blocks 161-167 stores or passes `1`, so no
such reference was found.

### Also tried this session, all measured

- 45 `extern volatile` declarations, each crossed with the `one` variable: no
  change (4042 / 4036).
- 16 combinations of per-site `volatile` casts on the index read, the call
  argument, the compare reads and the two stores in block 160: only the index
  read moves anything.
- All 1, 2 and 3-edit combinations of ten structural edits (per-site
  `volatile`, the `one` variable, statement swap, the `u32 addr` idiom on
  `gUnk_020020CC`, `gUnk_083FDE2D` and `gUnk_02002098`, pointer-form indexing):
  best 4042, only the `volatile` index plus `one` family reaches `r2`.
- `one` at four declaration positions and four types, and used at one, two,
  three and all four `gUnk_0202EEB0 = 1;` sites: 4036 down to 2720.
- A shared `u8 arg` for the two `gUnk_0202ED70` reads that the ROM puts in
  `r2` (`0x8015d7e` and `0x8015dd6`), plain and `volatile`, inline and as a
  statement: 4042 to 3973.
- `u32 eeb0 = (u32)&gUnk_0202EEB0;` at the store alone and at all five state2
  sites: 1457 and 2734.
- A fake `u8` return from `sub_0800F8D0`, unused and used: 4042 and 2802.

### Process warning

A background job from the previous session was still rewriting
`src/sub_08015364.c` and `build/src/sub_08015364.*` when this one started, so
two `runs.py` calls on the "same" source disagreed. Check
`md5 build/src/sub_08015364.i` against the source you meant to build, or drive
the compiler yourself rather than through `make`.

## Correction to the session-2 counter-example, and the two-branch wall

**`sub_08008090` does not contain that configuration.** It is 36 bytes,
`0x08008090`-`0x080080B4` (`python3 scripts/match.py sub_08008090` confirms the
size). The code quoted at `0x8008120`-`0x8008140` is in the *next*, still
undecompiled function, so it is raw ROM, not verified compiler output. Do not
cite it as "the retail compiler emitted r0 for our configuration".

The ROM fragment is still worth reading, because it shows the mechanism cleanly:

```
8008120  ldr  r0, [pc, #52]
8008122  movs r2, #0          <- constant 0, lands in r2
8008124  strb r2, [r0, #0]
8008126  ldr  r1, [pc, #52]
8008128  movs r0, #1          <- constant 1, lands in r0
800812a  strb r0, [r1, #0]
  ...
8008140  strb r2, [r1, #0]    <- the 0 reused, different basic block
```

The `0` is stored twice in two basic blocks, so it is a **global allocno**;
global_alloc runs after every local quantity, and the two block-local address
pseudos already hold r0 and r1, so it takes r2. The `1` is block-local and
first-fits to r0. That is exactly the relation `0x8015d8e` needs.

So the target needs the constant to be a global allocno whose live range covers
the stretch where 864 holds r0 and 860 holds r1 - blocks 161 to 167, the four
`cmp`/`strb` pairs - and stops before the `bl` at `0x8015db2`. Crossing that call
sends it to r4-r7 via `call_used_reg_set`. Its last reference must therefore sit
inside blocks 161-167, whose only instructions are `cmp r0, #N` and
`strb r4, [r1, #0]`: the comparisons take immediates, and the stores take the
CSE'd zero in r4. There is no instruction there that can reference it.

Combined with session 2's reload finding, both routes are now closed for the
same underlying reason:

| route | what it needs | why it fails |
|---|---|---|
| reload rematerialisation | `last_spill_reg` one slot back, i.e. no reload at `0x8015d7e` | the index must then be a real pseudo, and its 2-unit range gives it the highest `QTY_CMP_PRI` in that group, so it takes r0 or r1, never the ROM's r2 (measured: 4039, five bytes wrong at `0x8015d7a`-`0x8015d84`) |
| global allocno | a reference in blocks 161-167 | those blocks contain only immediate compares and stores of the r4 zero |

The trade is exact: you can have the index group at `0x8015d7e` or the constant
at `0x8015d8e`, not both. 4042 keeps the index group, 4039 keeps the constant.

## Branch B verified independently, and it is blocked by the same arithmetic

The 4039 shape reproduces the target exactly - confirmed on a clean tree, with
`md5 build/src/sub_08015364.i` checked against the intended source:

```
a28  ldr  r1, [pc, #144]
a2a  movs r2, #1              <- byte-exact
a2c  strb r2, [r1, #0]
```

Only five bytes are wrong, all in the index group, and they are a **rotation**:

```
            &gUnk_020020CC   &gUnk_083FDE2D   index   sum
  ROM           r1                r0            r2     r0
  ours (4039)   r2                r1            r0     r0
```

Instrumented allocation for that block in the 4039 build:

```
qty=2 reg=859 born=10 dead=14 nref=8 pri=60000  -> r0    index + sum, tied
qty=1 reg=854 born=8  dead=12 nref=4 pri=20000  -> r1    &gUnk_083FDE2D
qty=0 reg=853 born=6  dead=16 nref=4 pri=8000   -> r2    &gUnk_020020CC
```

Two things follow.

**The tie flips.** `block_alloc` ties an insn's output to the first *register*
operand that dies in it. In the ROM operand 1 of the `addsi3` is
`(subreg:SI (mem:QI (reg 820)))` - not a REG - so the sum ties to operand 2,
`&gUnk_083FDE2D`, which is why the ROM emits `adds r0, r2, r0` with the result
landing in the table pointer's register. Making the index a real pseudo turns
operand 1 into a REG, so the sum ties to the *index* instead and we emit
`adds r0, r0, r1`. That confirms the ROM's index at `0x8015d7e` is a reload, and
therefore that `last_spill_reg` sits on r2 there and a reload for the constant
would take r3 - so the ROM's constant is not a reload either.

**The rotation cannot be undone.** The ROM needs the index allocated *last* of
the three. Its live range is two index units (born at the add, dead at the add),
which is the shortest possible, so `QTY_CMP_PRI` = 40000 puts it second. To move
it behind `&gUnk_020020CC` you would need either that pointer's `nref` at 16 -
eight references to `gUnk_020020CC` inside block 160, against the ROM's one
store - or the index's range past 10 units, which needs a second use of the
index value that the ROM's instruction stream does not contain.

So the two branches fail for symmetric reasons, both measured:

| branch | score | right | wrong | blocked by |
|---|---|---|---|---|
| A (current draft) | 4042 | index group | the constant | no quantity can live in r0 across `0x8015d8e` |
| B (volatile index + `one`) | 4039 | the constant | index group | the index's 2-unit range makes it the highest priority, so it can never be allocated last |

Both blockers are properties of the ROM's own instruction stream, not of the C.
