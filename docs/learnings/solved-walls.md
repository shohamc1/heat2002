# Symptoms and fixes for stalled functions

Use this page when `match.py` keeps printing `MISMATCH` and the remaining
diff looks like compiler behaviour you can't control. Find your symptom in
the index, then follow its entry.

On 2026-09-23 the last nine unmatched game functions matched. Earlier
sessions had parked most of them as reload, allocation or cross-jumping
walls, some after hundreds of variants and long permuter runs. Every fix was
a change of source shape in plain C. None needed a compiler change or a
register pin, and several removed pins that earlier drafts depended on.

In `match.py` output, `-` lines are the target (the ROM) and `+` lines are
ours (your build). The snippets below use the same convention.

This page grows with every wall solved. If you match a function that
stalled, or you stop on one that doesn't match, you must update this page
before you finish. See [Keep this page current](#keep-this-page-current).

## Symptom index

Find the row that matches what your diff shows. Each row links to an entry
with the target and ours asm, the cause and the fix.

| What your diff shows | Likely cause | Entry |
| --- | --- | --- |
| Target copies a constant into another register before using it (`adds r0, r3, #0`); ours uses it directly, often 2 or 4 bytes shorter | The operation ran in 16 bits | [1](#1-a-constant-copied-through-a-second-register) |
| Ours has an extra `ldrh` just before a `strh` to the same address | Store to a `volatile` array element by name | [2](#2-an-extra-ldrh-before-a-strh) |
| Target loads several pool words; ours loads one and makes the others with `adds rN, #imm` | The words are symbol addresses, not integers | [3](#3-pool-constants-derived-with-adds) |
| Ours jumps into the middle of a loop and tests the exit at the bottom; target runs the loop body in order and ends with `b top` | `break` where the source had `goto` | [4](#4-a-loop-entered-by-a-jump-into-its-middle) |
| Two stack slots swapped, or ours keeps `sp` in a register (`mov r6, sp`) and addresses locals through it | A fill value that belongs in a `volatile` block-scope temp | [5](#5-stack-slots-in-the-wrong-order) |
| Ours loads `&table[N]` as one pool word; target loads the table and adds the offset | The index was constant only after optimisation | [6](#6-a-constant-table-index-folded-too-early) |
| Target keeps a separate `movs r0, #C; b join` body per case, even for equal values; ours shares one, and the build is smaller | The source stored the result in every case | [7](#7-switch-cases-with-equal-values-merged) |
| Two arms share a call's code differently: target keeps one arm's `bl`, ours keeps the other arm's | Where the source put a shared call | [8](#8-the-wrong-arm-keeps-its-call) |
| Two values swap registers, everything else matches | Equal allocation priority, broken by pseudo age | [9](#9-two-values-swap-registers) |
| Target keeps a value in a high register (`r8` to `r10`) and spills another; ours does the opposite | The kept value had more uses in the source | [10](#10-the-wrong-value-wins-a-high-register) |
| Only the scratch register of a `mov rX, r10` or similar copy differs | A register pin on a variable | [11](#11-only-a-reload-scratch-register-differs) |
| A fix to one expression rotates every callee-saved register | A temporary lengthened a live range | [12](#12-one-change-rotates-every-register) |
| Ours pushes one more callee-saved register, holding a global's address | A fresh mention of a global where the source reused a pointer | [13](#13-an-extra-pushed-register-holding-a-global-address) |
| Target loads the `ands` constant into the output register and the spilled value into the other (`movs r0, #15; ldr r1, [sp, #N]; ands r0, r1`); ours swaps them | The variable's declared type is wider than the source's | [14](#14-an-ands-constant-in-the-wrong-register) |
| Target is a bare `bx rN` with no `push`/`pop`, often followed by a dead `bx lr` | Inline asm in a non-naked function | [15](#15-a-bare-bx-rn-with-no-pop) |
| Target copies a call result (`adds r1, r0, #0`) and stores the original r0; ours stores the copy's register | CSE folded the copy into the call result's pseudo | [22](#22-a-store-reads-the-copy-instead-of-the-call-result) |
| A high-module copy of a matched function diverges in registers and reloads around a dead read, with no branch in the target | The branch that used the read was still in the source | [23](#23-registers-drift-around-a-dead-read-that-ends-no-branch) |
| An address argument's pool load lands AFTER the `str` of a stack argument; ours loads it first | The address was precomputed before the stack store | [24](#24-an-address-argument-loaded-after-a-stack-argument-store) |
| Target negates 3-address (`negs r1, r0; adds r0, r1, #0`); ours is 2-address (`negs r0, r0`) | Unary minus folded into the two-address negation | [25](#25-a-three-address-negation) |
| A final add reads the accumulator as its SECOND input (`adds r0, r2, r0`) and ours emits `adds r0, r0, r2` or copies around it | The expander canonicalises `v = x + v` to `(v, x)` | [26](#26-a-final-add-reads-the-accumulator-as-its-second-input) |
| A call result must move out of r0 before its first use (`adds r1, r0, #0` then in-place shifts) and no plain shape moves it | The call's return register wins every local-alloc tie | [27](#27-a-call-result-stuck-in-r0) |
| Ours ends a loop `cmp #N-1; bls`; target has `cmp #N; bne` | The loop condition was an equality test, not `<` | [28](#28-cmp-n-1bls-vs-cmp-nbne) |
| Ours emits `movs rX,#4; add ip,rX` at a loop head plus an extra entry home store; target has `adds rY,#4; mov ip,rY` | The counter increment was written at the loop head | [29](#29-a-counter-increment-at-the-loop-head) |
| A pseudo dies or rematerialises where the target keeps it homed, and no source shape stops it | Zero-emission liveness keepers and hard-register materialisation | [30](#30-zero-emission-liveness-keepers) |
| A caller changes bytes (or stops compiling) after an `extern` was rewritten to a canonical signature: extra or missing narrowing pairs, a lost `ldrsb`, a rotated register pair | The prototype decided the caller's conversions | [31](#31-the-callers-bytes-change-after-a-shared-prototype-changed) |
| Target loads the memory *before* the pool constant it combines with, ours loads the constant first, after `volatile` left the `extern` | The access needs its volatile order back, as a cast | [32](#32-a-memory-load-the-target-puts-before-a-constant) |
| Your notes say the difference is invariant under many variants | The variants shared a wrong structure | [Start from a plain rewrite](#start-from-a-plain-rewrite) |

## Start from a plain rewrite

Do this first if your draft uses register pins, invented pointer locals or
permuter output. A draft fitted to the ROM has a pseudo structure the
original source never had. Local edits can't repair that, which is why
earlier sessions measured "invariant under 60 variants": each variant sat
inside the same wrong structure.

To start again, do the following:

1. Write the function from the asm in the plainest C you can: one statement
   per ROM operation, field accesses instead of pointer locals, and no
   `register ... asm("rN")`.
2. Use the `include/gba/` headers: `REG_*`, `INTR_FLAG_*`, `DmaCopy32`,
   `DmaFill32`, `CpuFastSet`. Macros carry structure that hand-written C
   misses (see entry 5).
3. Keep the draft out of `src/`. Another session may build from the same
   checkout, and an unmatched `src/*.c` breaks its `make`. Compile the draft
   with the Makefile's own commands and link it the way `match.py` does.
4. Fix the instruction sequence and sizes first. Look at register names only
   once the instructions line up.

`CgbSound [sub_08001C88]` (m4a `CgbSound`) was parked at 228 diff lines with a
register pin, a status local and pointer arithmetic fitted to the ROM.
tmc's `CgbSound`, edited for the older revision, scored 82 on its first
build and matched after two changes. For m4a code, start from
`tools/tmc/src/gba/m4a.c`.

`sub_0800E008`'s old struct draft was stuck at 516 bytes. The plain rewrite
built at 504 bytes with three diff lines after two changes.

## Code-shape symptoms

### 1. A constant copied through a second register

The target builds a constant in one register and copies it before use:

```
-   movs r3, #0x80
-   lsls r3, r3, #1
-   adds r0, r3, #0
-   orrs r1, r0
+   movs r0, #0x80
+   lsls r0, r0, #1
+   orrs r1, r0
```

The same shape with a subtraction:

```
-   ldr r2, =0xFFFF8400
-   adds r1, r2, #0
-   subs r1, r1, r0
+   negs r0, r0
+   adds r1, r0, r2
```

**Cause.** The operation ran in 16 bits. GCC shortens a bitwise or
arithmetic operation on `u16` or `s16` operands, loads the constant into a
HImode pseudo, and reload copies it into the SImode operand register.

**Fix.** Make the operation narrow in the source. Any one of these works:

- Store the expression straight into a 16-bit field. A 32-bit temporary
  followed by a store doesn't narrow it:

  ```c
  car->unk34 = -0x7C00 - (sub_0800CB18(da >> 5, db >> 5) << 8);
  ```

- Cast one operand:

  ```c
  ed[0] = ((u16)((id + 1) << 12) | 0x100) | ((*edd0 + 1) & 0xFF);
  ```

- Use a compound assignment on a `vu16` register:
  `REG_IE |= INTR_FLAG_GAMEPAK;`.

**Seen in:** `sub_0800BEA4` (`ab803a6`), `sub_08011B08` (`2e66b02`),
`sub_0800E008` (`b3dc387`).

**Variant:** plain `REG_*` macro stores also synthesise the *derived*
constants and descending register addresses automatically — consecutive
`REG_BG3CNT = 0x1D0B; REG_BG2CNT = 0x1E01; ...` produce `adds r2, #0xF6`
(0x1E01 from 0x1D0B), `subs r2, #0xC8`, `subs r1, #2`, `adds r1, #0x4A`
— no pointer walk or staging locals. Seen in `SetTrackBgCnt [sub_08002718]` (`a6b058e`).

### 2. An extra `ldrh` before a `strh`

```
+   ldrh r2, [r1, #0]
    strh r0, [r1, #0]
```

**Cause.** agbcc compiles a store to an element of a `volatile` array, by
the array's name, as a read-modify-write.

**Fix.** Store through a pointer:

```c
extern vu16 gUnk_0202ED78[];
vu16 *ed = gUnk_0202ED78;   /* before the loop */
ed[0] = t;                  /* not gUnk_0202ED78[0] = t */
```

**Seen in:** `sub_08011B08` (`2e66b02`).

### 3. Pool constants derived with `adds`

```
-   ldr r0, =0x08367C06
+   adds r0, #12
    str r0, [r7, #0]
-   ldr r0, =0x08367C10
+   adds r0, #10
```

**Cause.** The pool words are addresses of symbols. Written as integers,
the compiler derives each one from the last.

**Fix.** Check `symbols.ld` for the symbols, then use them:

```c
extern u8 gUnk_08367BFA[];
car->fE4 = (s32)gUnk_08367BFA;
```

**Seen in:** `sub_080097A4` (`eea3c92`).

### 4. A loop entered by a jump into its middle

Ours starts the loop with a `b` into the body, lays the exit test at the
bottom (`cmp r5, #7; bne loop`), and places part of the body after the
entry jump. The target runs the body in source order, leaves with a forward
`beq exit`, and ends the body with `b top`.

**Cause.** `expand_end_loop` (stmt.c:2009) scans the whole loop body for a
jump to the loop's end label. A `break` is such a jump. When it finds one,
it moves everything up to that jump to the bottom of the loop and enters
the loop with a jump.

**Fix.** Leave the loop with `goto` to a label after it. That label isn't
the loop's end label, so the loop keeps its order:

```c
for (;;) {
    /* ... */
    if (idx == 7)
        goto done;
    /* ... */
}
done:
```

A `return` inside the loop also avoids the rotation.

**Variant (both directions exist in the ROM):** the *same source loop*
appears unrolled in one copy and rolled in its twin — the unrolled copy
needs `goto done`, the rolled copy needs `break`. When a loop's layout
argues for the "wrong" keyword, check for a same-shape twin in the other
engine copy before assuming a different source. Seen in `sub_083642FC`
(`4cf7e72`, rolled, `break`) vs `sub_0800E008` (`b3dc387`, unrolled,
`goto done`).

**Seen in:** `sub_0800E008` (`b3dc387`).

### 5. Stack slots in the wrong order

Two locals sit in swapped stack slots, or ours computes `mov r6, sp` once
and addresses the frame through `r6` (`ldr r4, [r6, #4]`) where the target
uses `[sp, #4]`.

**Cause.** A `volatile` block-scope local gets its stack slot when it's
declared. An address-taken scalar gets its slot later, when the compiler
finds that it can't stay in a register. An 8-byte struct used to force the
order becomes a DImode pseudo and causes the `mov r6, sp` base.

**Fix.** Look for a header macro with a `volatile` temporary. A DMA fill
with a constant value is `DmaFill32`, whose `vu32 tmp` takes `sp+0` ahead
of an address-taken counter at `sp+4`. Every fill in the function reuses
that slot:

```c
u32 frame;   /* address passed to a callee: sp+4 */
/* ... */
DmaFill32(3, 0xA0, gUnk_0202E960, 0x400);   /* tmp: sp+0 */
```

**Seen in:** `sub_0800E008` (`b3dc387`).

### 6. A constant table index folded too early

```
-   ldr r0, =gUnk_08332DC8
-   adds r4, r0, #0
-   adds r4, #0xC0
-   movs r2, #0x80
-   lsls r2, r2, #1
-   adds r7, r0, r2
+   ldr r4, =gUnk_08332DC8+0xC0
+   adds r7, r4, #0
+   adds r7, #0x40
```

**Cause.** A constant index at the source level becomes one pool word. The
target's index became constant only after optimisation, so the table base
stayed in a register.

**Fix.** Compute the index from a variable assigned inside the loop body,
with the same formula the other loops use. Assigned before the loop, it
folds too early:

```c
while ((c = *str++) != 0) {
    ch = ' ' - 0x20;            /* inside the loop */
    base = (ch >> 5) * 64 + 0x60;
    tile = &gUnk_08332DC8[base + (ch & 0x1F)];
    /* ... */
}
```

**Seen in:** `sub_08006738` (`481d8ec`).

### 15. A bare `bx rN` with no `pop`

The target jumps through an argument register with `bx r0` and no
`push`/`pop`, and a `bx lr` follows that nothing reaches.

```
    bx r0
    bx lr
```

**Cause.** agbcc emits `bx` only in `thumb_exit` (thumb.c:601): after a
`pop`, or with `lr` in a leaf. No C statement reaches a bare `bx r0`. GCC
2.95 has no Thumb sibcall, and `indirect_jump` is `mov pc, rN`.

**Fix.** Write the jump as inline asm in a normal, non-naked function. The
compiler adds its leaf epilogue, the dead `bx lr`:

```c
void sub_0800DE5C(void (*func)(void))
{
    asm("bx r0");
}
```

**Seen in:** `sub_0800DE5C`.

## Branch-merging symptoms

jump2 cross-jumps identical code after register allocation (toplev.c runs
it after reload). Its choices look arbitrary until you know three rules;
entries 7, 8 and 10 each follow from one of them.

### 7. Switch cases with equal values merged

The target has one `movs r0, #C; b join` body per case, including two cases
that both load `#0x28`. Ours points both jump-table entries at one body, and
the build is smaller.

**Cause.** When the source assigns a variable in each case and stores it
once after the switch, jump2 merges the equal arms. When each case stores
the field itself, jump2 first merges the stores into one `strb` behind a
new label. Jumps to a label created in the same jump2 pass never join
`jump_chain` (jump.c:1977), so the arms are never compared with each other.

**Fix.** Store in every case, and in the `else` branch:

```c
switch (gUnk_0202ED70) {
case 3:
    car->f4C = 0x28;
    break;
case 6:
    car->f4C = 0x28;
    break;
/* ... */
default:
    car->f4C = 0;
    break;
}
```

**Seen in:** `sub_080097A4` (`eea3c92`), `sub_08341288` (`e82fcc7`).

### 8. The wrong arm keeps its call

Two if/else arms end in the same call. In the target, the first arm keeps
its own `bl` and the second jumps into another arm's `bl`. Ours does the
reverse:

```
-   adds r2, r6, #0
-   bl sub_0800A80C
-   b _0800AC4A
+   adds r2, r6, #0
+   b 0x800ac3e
```

**Cause.** flow.c:354 inserts `(use (const_int 0))` after a call that ends
a block right before a label. `find_cross_jump` never matches an INSN with
a CALL_INSN, so a call followed by a jump only merges with another call
followed by a jump. A call that falls into a label only merges with
another such call.

**Fix.** Work out from the target which calls fell into a label: those are
the calls that merged with each other. Then place the shared call after an
if/else, so each arm's call falls into it:

```c
if (gUnk_020021E0 == 0)
    sub_0800A80C(car, gKeysHeld, 0);
else
    sub_0800A80C(car, 2, 0);
sub_0800A628(car);   /* once, not in each arm */
```

**Seen in:** `sub_0800AB78` (`9e6d1fa`).

**Variant:** the same rule fixes a surviving branch INTO a store: the
target branches from one arm straight into the other arm's `strh`. Write
the store in BOTH arms with different value expressions (the load arm
stores the register, the else arm stores 0) so jump2 merges the two
identical stores into the join block; a local `v` crossing the branch
gets its own register and a promotion copy instead.

**Seen in:** `sub_0800F85C` (`473a73b`).

## Register-allocation symptoms

When the instructions match and only register numbers differ, compute the
allocator's inputs instead of trying spellings at random.

`allocno_compare` (global.c:605) orders pseudos by

```
(int)(floor_log2(refs) * refs / live_length * 10000 * size)
```

and breaks ties by the lower pseudo number. `refs` counts every set and
use, weighted by loop depth. Compile with `-dl` and read the
`Register N used R times across L insns` lines in the `.lreg` dump to get
both numbers for each pseudo.

### 9. Two values swap registers

Everything matches except two values that trade registers:

```
-   ldr r7, =0x04000128
-   ldr r1, [r7, #0]
+   ldr r6, =0x04000128
+   ldr r1, [r6, #0]
```

**Cause.** The two pseudos have equal priority. In `sub_08011B08` both had
6 refs over 90 insns, and the tie went to the older pseudo.

**Fix.** Make the value that the target gives the lower register older. A
declared variable gets its pseudo at its declaration, before any temporary
made while expanding statements. Assign it where the target computes it,
inside the expression if needed:

```c
u8 *edd0;
/* ... */
ed[0] = ((u16)((id + 1) << 12) | 0x100)
      | ((*(edd0 = &gUnk_0202EDD0) + 1) & 0xFF);
/* ... */
*edd0 = v - 1;
```

**Seen in:** `sub_08011B08` (`2e66b02`), `sub_08344A20` (`1fc914a`).

**Variant:** If the swap is between a global's *address* pseudo and a
short-lived temp (menu loop: address in r6, loop-exit temp in r7; target
wants r7/r6), the two priorities can differ by about 1%
(`floor_log2(refs)*refs/live_length`: 10/56 vs 3/17). Make one read of
the global volatile — a read *not* combined with a constant, such as the
call argument — to lengthen the address pseudo's live range and flip the
order, while the other read stays non-volatile and keeps the
constant-first hoist:

```c
if (gKeysPressed & 1)          /* non-volatile: movs before ldrh */
    sel = v;
v = sub_08011D38(*(volatile u16 *)&gKeysPressed, v, 0, 0);
```

**Seen in:** `sub_0801303C` (`767ffb8`), `sub_08013A7C`, `sub_08014400`,
`sub_08015244` (2026-09-24).

### 10. The wrong value wins a high register

The target keeps a value in a high register and spills another to the
stack. Ours does the opposite:

```
-   mov r1, sp
-   adds r1, #4
-   str r1, [sp, #20]
    ...
-   mov sl, r0
+   str r0, [sp, #20]
+   add r1, sp, #4
+   mov sl, r1
```

**Cause.** The value the target keeps had a higher priority, usually more
references. jump2 merges duplicated code after allocation, so two source
copies count twice for the allocator even though the ROM shows one copy.

Check the loop preheader order too. loop.c inserts hoisted values after any
preheader code the source wrote. If the target sets a hoisted value (here
`&out`) before a value you compute explicitly before the loop, the target's
value was hoisted by loop.c as well. loop.c only moves an invariant when
`threshold * savings * lifetime >= insn_count` (loop.c:1833). A value
computed once and used right away stays in the loop; two matching copies
raise the savings and get hoisted.

**Fix.** If one block in the target is reached from two conditions,
consider whether the source had two copies:

```c
if (a4 != 0) {
    x -= a3 * 3 / 2;
    if (x < 0)
        x += car->unk154;
} else if (i & 1) {
    x -= a3 * 3 / 2;
    if (x < 0)
        x += car->unk154;
}
```

This replaced a `step` variable pinned to r10.

**Seen in:** `sub_0800BEA4` (`ab803a6`).

### 11. Only a reload scratch register differs

The instructions match, but the scratch register of a copy out of a high
register differs:

```
-   mov r0, sl
-   subs r7, r7, r0
+   mov r2, sl
+   subs r7, r7, r2
```

**Cause.** A variable pinned to a hard register with
`register ... asm("rN")` goes through reload differently from a pseudo
that global allocation puts in the same register. Earlier notes called
these picks a reload round-robin artefact that no source can move.

**Fix.** Remove the pin and find the source shape that gives the value its
register naturally (see entries 9 and 10). In `sub_0800BEA4`, the scratch
picks fixed themselves once the pin was gone.

**Seen in:** `sub_0800BEA4` (`ab803a6`).

### 12. One change rotates every register

A fix to one expression is right, but every callee-saved register moves
along by one.

**Cause.** The change added RTL insns inside the live range of a
long-lived value, which lowered its priority below a rival's. In
`sub_08011B08`, a `u16 t` temporary lengthened the SIOCNT pointer's range
from 90 to 94 insns, which dropped it below the loop counter.

**Fix.** Compare the `.lreg` statistics before and after the change, and
find a spelling of the same operation that adds fewer insns. A cast inside
the expression replaced the `u16` temporary.

**Seen in:** `sub_08011B08` (`2e66b02`).

### 13. An extra pushed register holding a global address

Ours pushes one more callee-saved register than the target and keeps a
global's address in it.

**Cause.** A fresh mention of the global is partially redundant with
earlier loads of the same address, so GCSE's partial redundancy
elimination hoists it into a second pointer pseudo.

**Fix.** Write through the pointer the function already holds instead of
naming the global again. In `sub_08004B1C`, an embedded index assignment,
`p[j = idx - 5] = val;`, kept one pointer pseudo.

**Seen in:** `sub_08004B1C` (`24c1c59`).

### 14. An `ands` constant in the wrong register

The instructions match, but the constant and a spilled variable trade
registers around an `ands`:

```
-   movs r0, #15
-   ldr r1, [sp, #24]
+   movs r1, #15
+   ldr r0, [sp, #24]
    ands r0, r1
```

**Cause.** The expression is stored to a `u8`, so `convert_to_integer`
narrows the `&` to 8 bits (convert.c:280). With an `s32` variable, the
widened `andsi3` gets the constant as `(subreg:SI (reg:QI))`. Regmove's
backward pass skips any operand that isn't a plain `REG` (regmove.c:2713),
so it can't make the dying constant the output. It copies the variable into
the output instead (regmove.c:2951), and reload loads the variable there.
Declared `u8`, the variable is promoted to an `SImode` pseudo
(`PROMOTE_MODE`, thumb.h:344) and the constant arrives as a plain `SImode`
register, which regmove ties to the output.

**Fix.** Declare the variable `u8`. A `(u8)` cast on each assignment gives
the same `lsls`/`lsrs` zero-extension but not this tie:

```c
u8 envelopeStepTimeAndDir;
/* ... */
*nrx2ptr = (envelopeStepTimeAndDir & 0xf) + (channels->envelopeVolume << 4);
```

**Seen in:** `CgbSound` (CgbSound).

## Other signs of source structure

The following patterns look like compiler quirks but reflect the source:

- A register read after a loop that may not have run: the source reuses a
  variable set in the earlier loop. Keep the reuse (`sub_08006738`'s
  `tile`).
- Two loops whose counters sit in different registers: the source has two
  counter variables.
- A 16-bit truncation mid-expression, such as `lsls #22; adds #0x600000;
  lsrs #16`: a `u16` temporary holds part of the expression.

## Find the pass that decides

When your symptom isn't in the index, find the compiler pass that creates
the difference, then read that pass's source for the condition that decides
it.

1. Compile the draft with dump flags: `-dr` (initial RTL), `-dj` and `-dJ`
   (jump passes), `-dl` (local allocation, with register statistics) and
   `-dg` (global allocation and reload).
2. Find the first dump in which your code differs from what the target
   implies. A merge that the target lacks, for example, shows up first in
   the `.jump2` dump.
3. Read the pass in `tools/agbcc/gcc`. The rules on this page came from
   `find_cross_jump` (jump.c:2687), the cross-jump loop in `jump_optimize`
   (jump.c:1961), the `use` insertion in flow.c (flow.c:354),
   `expand_end_loop` (stmt.c:2009), `allocno_compare` (global.c:605) and
   loop.c's move threshold (loop.c:1833).
4. Test spellings in a batch: generate each variant from a script and score
   them all. Many spellings fold to the same tree and change nothing, so
   check that a variant changes the RTL before you count it as tested.


### 16. A pointer reassigned per store group lands in a high register

Everything matches except a rotation of the callee-saved registers: the
target keeps several buffer-address pointers in r4, ours puts one in r7
and shifts the others down.

**Cause.** `local-alloc.c:359` only allocates pseudos with
`REG_N_DEATHS(i) == 1`. A pointer variable assigned once per store group
(`p = buf; p[0] = ...; p = buf; p[1] = ...`) has one death per def but
multiple defs, so it is punted to global allocation and lands in a high
register, rotating everything below it.

**Fix.** N separate single-assignment pointer variables, one per store:
`p0 = buf; p0[0] = <call-heavy RHS>;`. The `X = buf;` statement is also
what places `mov rX, sp` before the calls — a plain `buf[i] = f() + c`
emits the sp copy after them.

**Seen in:** `sub_0800B46C` (`6305f70`).

### 17. A comparison folded into a branchless bit trick

Ours materialises the boolean with `bics/negs/orrs/lsrs` (or an `eors`
variant); the target is a branch between constant loads.

**Cause.** When a comparison's constant equals the mask
(`(x & 0x7F) != 0x7F`), combine folds the whole test into a branchless
bit trick, in every boolean-producing context tried.

**Fix.** Put the comparison where it can only be a branch condition, and
return the constants from the arms:

```c
if ((arg0 & 0x7F) == 0x7F)
    return 0;
return 1;
```

Jump threading then produces the target's `beq/movs #1/b/movs #0`
single-epilogue shape.

**Seen in:** `sub_080031B0` (`3f36ab7`).

### 18. A quotient that loses its register copy

`a * b / 256` written as one expression coalesces into the return
register and loses the target's `adds r1, r0, #0` copy.

**Cause.** In the single-expression form the product pseudo dies at the
division; nothing keeps a second value alive across it.

**Fix.** The compound-assignment idiom keeps the product pseudo live
past the quotient copy:

```c
s32 prod = arg0 * arg1;
prod /= 256;
return prod;
```

**Seen in:** `sub_08000328` (`7f26ed4`).

### 19. An extra copy between a u8 load and its test

The target loads a byte into a scratch and copies it into the variable's
register before testing (`ldrb r0; adds r4, r0, #0; cmp r4`); ours tests
straight out of the load.

**Cause.** In `store_expr`'s `SUBREG_PROMOTED_VAR_P` path (expr.c), a
non-volatile RHS memory is fed straight to `convert_move`, which emits
one zero-extending load into the variable's pseudo. A volatile memory
goes through `copy_to_reg` first, giving the load-then-move pair.

**Fix.** Declare that global volatile — and assign it to the local
before the test (`v = gUnk_020020C0; if (v == 0)`), so the compare reads
the local.

**Seen in:** `sub_0800306C` (`f8a1ae1`).

### 20. A sub-word parameter's entry copy emitted after later parameters

The target copies argument registers in an order no plain signature
produces (`dst`'s move before `pal`'s, with `pal` second).

**Cause.** `assign_parms` (function.c:4231) defers a parm whose nominal
mode differs from its passed mode — any sub-word integer — to
`conversion_insns`, emitted after all immediate parm copies.

**Fix.** Pass the parameter word-typed and cast in the body:

```c
void f(s32 *src, u32 pal, s32 *dst)
{
    u16 *pk = (u16 *)pal;
```

**Seen in:** `sub_08003E84` (`17214bd`).


### 21. A block layout only -O1 produces

The target keeps a distant block behind a real unconditional branch
(`bge Lpos; b Lneg` with the Lneg body far below); at the project's
-O2 ours always hoists the body up to the branch.

**Cause.** The vendored compiler's Cygnus-local `merge_blocks` pass
(flow.c:3811, run from toplev.c only when `optimize > 1`) moves any
single-predecessor distant successor block up next to its
unconditional-jump header. No C shape prevents it; ~40 variants and a
long permuter run never moved it.

**Fix.** A per-object -O1 override in the Makefile (the eeprom.o
precedent; requires maintainer authorization — the default flags are
the original build's):

    $(BUILD)/src/NAME.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))

The -O1 build may then expose a new class of diff: cse (without
follow-jumps, an -O2-only feature) absorbing a pointer copy's uses.
If the ROM splits one address across two registers (pool register used
sparingly, copy register for the body), pin both and split the sites:

```c
register struct T *w asm("r5") = &g;   /* head test + one store */
register struct T *p asm("r4") = w;    /* every other access */
```

Watch also for a pinned variable's read-modify-write re-loading
clumsily (`adds r0, r1, #0; adds r0, #1`) — route it through a plain
local, one per distinct temp register the ROM uses.

**Seen in:** `sub_0800E640` (`cc44719`), `sub_08364730` (`b7bc932`).

### 22. A store reads the copy instead of the call result

The target copies a call's result and stores the original, keeping the
copy for a later test; ours stores the copy's register:

```
 bl   MenuMoveVertical
 adds r1, r0, #0
-strb r0, [r4, #0]
+strb r1, [r4, #0]
 movs r0, #0xC0
```

**Cause.** `make_regs_eqv` (cse.c) makes a copy the canonical register
of its class when the copy lives past the CSE block and longer than the
original, and `canon_reg` (cse.c:2369) then rewrites the store to read
it. `canon_reg` never replaces a hard register, so an original that is
a hard register survives.

**Fix.** Pin the call result to r0 in a block scope and assign the
long-lived local from it:

```c
{
    register u32 r asm("r0") =
        MenuMoveVertical(gKeysPressed, gUnk_0202EF78[v], 0, 9);
    gUnk_0202EF78[v] = t = r;
}
```

**Seen in:** `sub_080132F8`.

### 23. Registers drift around a dead read that ends no branch

A high-module copy of a matched function reads a field into a register
and never uses it (`ldrh r3, [r3, #16]`), with no branch after it. Ours
matches the instructions, but the pointer register, a reload register
and ties around the read all differ, and earlier drafts piled up pins
without closing the gap.

**Cause.** The read was the condition of an `if`/`else` whose arms only
assigned a variable that is overwritten later. Flow deletes the arms, and
the branch disappears only after reload. Until then the branch splits the
blocks, which changes which pseudos local-alloc handles, and the join
label clears reload inheritance (reload1.c, `reload_as_needed`). Without
the branch, ours inherited r1 for the pointer where the target reloads
it into r3.

**Fix.** Keep the low-region twin's `if`/`else` even when its result is
dead:

```c
if (e->unk10 == 1)
    e = gUnk_0203B860;
else
    e = e + 1;
```

With the branch back, the plain C matched with no pins, no `volatile`
and no index tricks.

**Seen in:** `sub_08341F64` (twin of `sub_0800A4D4`).

### 24. An address argument loaded after a stack-argument store

A call with an address argument and a 5th stack argument: the target
stores the stack argument first and loads the address's pool word after
it; ours loads the address before everything.

```
-   movs r3, #0x00
-   str  r3, [sp, #0x00]
-   ldr  r3, =0x08331360
+   ldr  r3, =0x08331360
+   movs r2, #0x00
+   str  r2, [sp, #0x00]
    bl   QueueSprite
```

**Cause.** `precompute_register_parameters` (calls.c:585) copies any
argument whose `rtx_cost` exceeds 2 into a pseudo before the cheaper
constants and stack stores are emitted, in a forward scan. A symbol
address costs 10 (`thumb.h` `CONST_COSTS`), so it is always precomputed
and its pool load lands before the stack store. A register pin cannot
fix this: the stack-arg scratch clobbers r3.

**Fix.** Pass the address through a local assigned just before the call,
inside the loop, so precompute sees a cheap REG:

```c
pal = (u32)gTrackTileSpritePalette;
QueueSprite(t, x, y, pal, 0);
```

The load then lands in the register-load loop after the stack store, and
the separate def is folded away.

**Variant:** `fold-const`'s `associate:` reassociation reorders
`(out[0] - 0x78) + g[6]` to evaluate the global first. Split it with a
temp: `t = out[0] - 0x78; out[0] = t + g[6];`.

**Seen in:** `sub_08008160` (`c227b68`).

### 25. A three-address negation

The target negates into a second register and copies back:

```
-   negs r1, r0
-   adds r0, r1, #0
+   negs r0, r0
```

**Cause.** Every plain spelling (inline `-a`, `n = -a;`, `0 - a`,
operand reorders) folds the minus into the two-address `negs`.

**Fix.** Pin the negation to the other register:

```c
register s32 n asm("r1") = -a;
Modulo(n, 6);
```

**Seen in:** `sub_08010768` (`d41d047`).

### 26. A final add reads the accumulator as its second input

The target's last add has the accumulator as op2 (`adds r0, r2, r0`);
ours emits `adds r0, r0, r2` or inserts `adds rN, rM, #0` copies around
the multiplies.

**Cause.** Three rules stack up: the expander canonicalises `v = x + v`
to `(v, x)` when the destination matches an operand; `mulsi3`'s
early-clobber `=&l` destination cannot share its parameter's register,
so separate-dest spellings pay reload copies; and local-alloc's priority
`log2(refs)*refs/lifetime` decides which product takes r0.

**Fix.** Pin the accumulated value to the outgoing argument register and
let the products allocate around it:

```c
register u32 s asm("r0") = a * a + b * b;
return sub_0800CAB4(s);
```

**Seen in:** `sub_0800CB5C` (`7b4b9c1`).

### 27. A call result stuck in r0

The target copies a call result out of r0 immediately and transforms it
in place in the copy register (`adds r1, r0, #0; lsls r1, r1, #24`); in
ours the whole chain runs in r0, whatever the source shape.

**Cause.** The assignment from a call records an r0 copy *suggestion*
for the destination quantity (local-alloc's `combine_regs` hard-reg
case), and the suggestion pass runs before priority allocation, so r0
always wins. A bare `register u32 t asm("r1")` pin fails too: CSE
propagates the hard-register copy and deletes it.

**Fix.** Pin plus a no-op barrier after every assignment, with the
transforms written as compound assignments so they compute in place in
the pinned register (the `sub_0800CBB8` idiom):

```c
register u32 t asm("r1");
t = GetTrackTileType(...);
asm volatile("" : "+r"(t));
t = t << 24;
asm volatile("" : "+r"(t));
```

With r1 occupied, the next mask reloads into r0 and the `ands`'s
commutative tie produces the target's operand order.

**Seen in:** `sub_0800CC00` + `sub_0800CC4C` (`1fd5d13`).

### 28. `cmp #N-1; bls` vs `cmp #N; bne`

Ours ends a loop with `cmp r6, #15; bls` where the target has
`cmp r6, #16; bne`.

**Cause.** Thumb has no unsigned compare-below-immediate, so a `< N`
condition compiles to `<= N-1`. The source loop condition was an
equality test.

**Fix.** Write the exit as an equality: `} while (i != 16);`. Related:
an operand's narrowing shift appearing *before* an earlier statement's
arithmetic means the narrowing was a separate statement, not part of a
later initializer — GCC 2.95 never interleaves straight-line statement
evaluation.

**Seen in:** `sub_080069D8` (`3300818`).

### 29. A counter increment at the loop head

Ours emits `movs r1, #4; add ip, r1` at a do-while's head and an extra
`mov ip, r0` home store at entry; the target has `adds r0, #4; mov ip, r0`.

**Cause.** The counter's `+=` was written at the head of the loop body
in C. Written as the last statement before the test, GCC 2.95 rotates
it: the increment lands at the tail and the old value rides in the
counter register across the loop boundary with no entry reload.

**Fix.** Move the `+=` to the tail:

```c
do {
    /* body */
    row += 4;
} while (row != 24);
```

**Seen in:** `sub_08003C78` (`d04f498`); same shape as the matched
`DrawTrackMapWindow [sub_08003BFC]`.

### 30. Zero-emission liveness keepers

A pseudo (usually a pointer or a pooled address) dies early or is
rematerialised by reload where the target keeps it homed across the
region, and no declaration order, type or spelling stops it. Three tools
from the same family, all proven on one function:

1. **A hard-register copy survives cse.** Assign the address to a soft
   local, then copy it into a `register ... asm("rN")` pin. cse's
   `canon_reg` never substitutes a hard register, so `ldr r0,=X;
   adds r5, r0, #0` keeps both insns.
2. **A u32 load/store-back pair keeps a pseudo homed.** Reading
   `*(u32 *)p` and writing the value back emits nothing —
   `reload_cse_noop_set_p` deletes the store after reload while every
   earlier pass sees both insns — but the use keeps the pointer's
   allocation alive. Use u32 views: under `PROMOTE_MODE` a u8
   load-back store never matches, so the pair would emit.
3. **A hard-register destination escapes cse path reprocessing.** cse's
   first pass reprocesses fallthrough arms and ties any later read of
   the same symbol to the first pseudo. Materialising the address into
   a pinned register at the first read records no pool-load set, so a
   later arm re-loads the pool word fresh — sharing the pool entry, as
   the target shows (`ldr r0, [pc, #8]` next to `ldr r0, [pc, #48]`).

**Seen in:** `sub_0800A4D4` (`ecc2fa4`) — its source header carries the
full campaign log. `sub_08341F64` closed by entry 23 instead; these
levers remain the toolkit for allocation webs that survive a plain
rewrite.

### 31. The caller's bytes change after a shared prototype changed

The function itself is untouched, but after rewriting one of its `extern`
declarations to a canonical signature, `match.py` reports the caller
mismatching. Four shapes, all one cause:

```
-   adds r0, r4, #0        ldrsb r0, [r5, r0]        (nothing)
+   lsls r0, r0, #16       ldrb  r0, [r5]            lsls r0, r0, #16
+   lsrs r0, r0, #16                                asrs r0, r0, #16
```

**Cause.** The prototype decides the caller's conversions. A parameter
that narrowed (`u32` to `u16` or `u8`) adds a mask or sign-extension pair
at the call; a parameter that widened removes the `ldrsb` the old `s8`
declaration forced; a return that changed width or sign adds a conversion
of the result, and can rotate the register allocation (entry 9) on top;
and a call that passed more arguments than the new prototype takes no
longer compiles. The original game source itself declared these functions
inconsistently, so the "wrong" old declaration was reproducing the ROM.

**Fix.** Keep the canonical `extern` and repair the one call site, in this
order. Cast the argument or result to the old type when the cast survives
(`(s8)ExchangeLinkInput()`); a cast the compiler elides as dead (an `(s8)`
argument into a `u8` parameter) needs a call through a function pointer
with the file's old signature instead:

```c
v = ((u8 (*)(u16, s8, u32, u32))MenuMoveVertical)(gKeysPressed, v, 0, 3);
```

`old_agbcc` folds a cast of a known function symbol back into the direct
`bl`, so the wrap is byte-identical — verified function by function; add a
comment naming the old prototype at each wrap. Note `match.py` symptoms
first: a whole-function diff, or many files whose only differences are
pool words and `bl` targets shifted by a constant, means some *other*
function changed size and moved the labels — fix that one first (compare
`arm-none-eabi-nm -S` sizes against a pristine build) before touching
callers that look broken.

**Seen in:** the phase-1 signature unification of 29 functions
(`FadeToBrightenedPalette`, `sub_08011C9C`, `GetString`, `MenuMoveVertical`,
...) in 96 files: `SendMultibootIsland` and `sub_080132F8` (return-width
pairs), `LinkTrackSelect` (the `ldrsb` of an `s8` parameter),
`sub_0801465C` (an `s16` return rotating r5/r6), `sub_0833E7FC` (removed
narrowing restored as `(u8)` argument casts), `RunRace` (an `s8` return
cast).

**Variant:** phase 2's scalar-to-array rewrite (a `gX` extern became
`gX[]`, every use became `gX[0]`) rotated registers in four of the 108
files it touched, with the bytes otherwise identical: `SetupChallenge`
(r5/r6 around sixteen `gNumCars[0] = C` stores), `MainMenuLoop`, and the
twins `DetectLinkPlayers`/`sub_08344A20` (a `movs r2, #0` for a later
store group hoisted above the block). `arr[0]` and the scalar end up as
the same `MEM` of a `SYMBOL_REF`, but the `ARRAY_REF` expansion path
changes local-alloc's pseudo priorities (entry 12). Spelling the access
as a pointer deref — `*(u8 *)&gNumLinkPlayers = v;` — reproduces the
scalar's expansion and matched all four.

**Variant:** a shared extern's `const` can change the users' bytes by
itself. `gUnk_08365340`'s users agreed on `extern u8 *gX`, but the ROM
definition in `src/data/rom_0836524C.c` says `const u32`, so the header
first followed the definition; re-typing the users' derefs to match
rotated registers, and `extern u8 * const gX` in the header mismatched
`sub_08006738` and `sub_080065A8` on its own. Plain `extern u8 *gX` —
exactly the type the users agreed on, with the definition re-typed to
`u8 * const gX = (u8 *)...` so its initializer bytes and `.rodata`
placement stay — matched everything. When a header replaces local
externs, give it the agreed type verbatim; force `const` only on plain
data arrays, never on the pointer object itself.

**Variant:** the 2026-09-27 struct-Car merge (81 files onto
`include/car.h`) found three rules for view-casts that keep a file's
bytes when the shared type differs from the local one. (1) On a bare
array symbol, a field-address cast folds the offset into the pool word:
`(*(u32 *)&gCars[0].progress)` emits `ldr r0, =0x0202A5A0; ldr r0,
[r0]` where the ROM has `ldr r0, =gCars; ldr r0, [r0, #0x50]`. Cast the
ARRAY first instead — `((volatile struct Car *)gCars)[0].progress` or
`((struct S8View *)gCars)->lap` — which keeps the offset inside the
`MEM`; through a pointer local, `&p->field` wraps are safe. (2) A
same-width sign-only difference (u32 vs s32, an s16 store into a u16
field) needs no cast when the value is only loaded, stored, or passed —
and adding one can itself rotate registers; a cast is required only when
the old sign fed a comparison (`bhi` vs `bgt`), a sign-extending
promotion, or a shift. (3) A load-WIDTH difference (s8 vs u8 field,
u32 vs `u16 *` slot) always needs the cast. Longest-first ordering stops
`->unk14` renames clobbering `->unk140`/`->unk14C`.

**Variant:** phase 4's extern unification (2026-09-27, 112 variables)
found two more rules. (1) **Address-context folding**: every spelling every spelling
that computes an element address — `((T *)arr)[i]`, `*(T *)&arr[i]`,
`*(T *)((u8 *)arr + k*i)` — funnels into `pointer_int_sum`'s distributive
law (c-typeck.c ~2663) plus `expand_expr`'s EXPAND_SUM folding, so a
constant index lands in the literal-pool word (`=arr+0x4A6`) and the
base+offset `ldr [rX, #imm]` disappears. The original `arr[i]` survives
because `get_inner_reference` expands ARRAY_REF offsets in EXPAND_NORMAL
context, materialising base and offset separately. When a view-cast must
reproduce that, hoist the byte offset into a `u32 off` local (its
assignment is a normal-context MODIFY, and the local is opaque to every
SUM-context fold) and cast the base: `*(u16 *)((u8 *)arr + off)`; for a
struct view over a flat array, wrap it — `struct S { struct E r[N]; }`
and `((struct S *)arr)->r[i].f` keeps the subscript expansion where a
direct cast folds constant indices. (2) **Per-iteration pointer
reloads**: a loop that read an extern POINTER variable (`gP[i] = 0`)
reloads `gP`'s word every iteration; under an array canonical the
equivalent load gets hoisted out of the loop. Write the read as
`(*(volatile u32 *)&gP[0])` — one volatile word read inside the loop —
and the reload returns (`sub_0800DFCC`, `sub_0800524C`, `sub_0833DC7C`,
`TitleScreen`). (3) A struct-*array* extern in a header above the
files' local struct definitions changes their codegen (the
extern-headers-plan trap); complete the tag in a shared header first —
`include/structs.h` holds `struct Track` (0x64) and the m4a table
structs, exactly as `car.h` holds `struct Car`.

**Variant:** a *local* struct-array extern's `const` alone can swap the
user's registers: `BuildStartingGrid` (`race/grid.c`) matched with
`extern struct TrackGrid gTrackStartGrids[]` and, with `extern const`
added and nothing else changed, the whole body diffed — old_agbcc gave
the table base r3 and the destination pointer r2 where the ROM has them
r2/r3. Dropping the `const` from the user's declaration (the definition
in `src/data/race_setup.c` stays `const`) matched. The sibling
conversions of the same batch (`gTireGripDefaults` in
`src/car/tire_grip.c`, `gTrackAiFinishTimeRanges` in
`sub_08016CB0.c`) matched *with* `const`, so spell the extern plain
first and let `match.py` decide.

### 33. Struct initializer words shifted at each row tail

**What your diff shows.** After converting a flat `const u32 tbl[]` to a
`struct T[]` initializer, `make check` mismatches only at each row's tail:
the last words are off by one member (the ROM's `unk5E` holds the value
your build put in `unk60`, and the true tail word became zero).

**Cause.** GCC 2.95 takes a braced sub-initializer for a *scalar* member
and consumes only its first element, silently discarding the rest, then
continues with the next member. Writing `{ a, b }, { c, d, e }` for the
trailing `u16 unk5C, u16 unk5E, u16 unk60, u8 pad[2]` produced
`unk5C = a`, `unk5E = c`, `unk60 = 0`. Braces belong only around real
array members.

**Fix.** Emit the scalars bare and brace only the arrays:

```c
{ ..., { pad0, ..., pad15 }, unk5C, unk5E, unk60, { p0, p1 } }
```

**Seen in:** `gTrackData` (`src/data/rom_08364AC8.c`, 2026-09-29); the
12 row tails matched after unbracing the two u16 pairs.

### 32. A memory load the target puts before a constant

You removed `volatile` from an `extern` (or moved the declaration to a
header, where it must be plain), and the function now mismatches: the
target loads the memory first and its pool constant after; ours hoists the
constant above the memory access.

```asm
-8000430: ldr  r2, [pc, #8]      @ &gUnk_02000DD0
-8000432: ldrh r1, [r2, #0]      @ memory first
-8000434: ldr  r0, [pc, #8]      @ constant second
-8000436: ands r0, r1
+8000430: ldr  r1, [pc, #8]
+8000432: ldr  r0, [pc, #12]     @ constant first
+8000434: ldrh r2, [r1, #0]      @ memory second
+8000436: ands r0, r2
```

**Cause.** Under `old_agbcc` a volatile access suppresses the constant
hoist (see "Use `old_agbcc`, not `agbcc`" in `CLAUDE.md`). The file once
declared the global `extern volatile`, or through a `vu16`/`vu32` typedef,
so every access in it compiled in the memory-first order.

**Fix.** Keep the `extern` plain — a declaration shared through a header
must work for every file — and cast the accesses that need the order to a
volatile pointer: `*(vu16 *)&gUnk_02000DD0 &= 0xFFFE;`. The cast is
byte-identical to the old volatile extern. There is no `vs8` typedef:
write `*(volatile s8 *)&g`. Two shapes to know: a statement that is only
a read (`*(vu8 *)&gUnk_0200215C[0];`) keeps a load the compiler would
otherwise delete; casting every access to the once-volatile global
reproduces the old build exactly, so start there and let `match.py` decide.

**The 2026-09-27 sweep.** `volatile` was removed from every `extern` line
in `src/` — 49 lines in 43 files, keyword and `vu16`/`vu32` typedef
spellings, plus one `struct Track *volatile` pointer. Each object was
rebuilt and every function in it re-matched (list them with
`arm-none-eabi-nm build/src/FILE.o | awk '$2 == "T" {print $3}'`). Thirty-
one functions matched without a cast. Twelve lost the memory-first order
and got casts at their accesses to the once-volatile global:
`ClearVBlankFlag`, `ReadKeys`, `RunRace`, `MainVBlankCallback`,
`sub_080032AC`, `sub_08008394`, `sub_08339AF0`, `sub_08339B4C`,
`sub_0833BF80`, `sub_0833C5B0`, `sub_0833C7F0`, `sub_08340504`. All 43
printed `MATCH`, and `make check` printed `MATCH` with no `extern
volatile` left in the tree.

## Open walls

Stalled functions whose symptom has no fix yet. Start here if you pick one
of them, and move the entry into the symptom index once it matches.

None as of 2026-09-25 — every game-code function (1001/1001) is matched.

## Keep this page current

This page is only useful if every agent that solves or abandons a stalled
function records it. Follow these rules before you end a session.

### When to add or change an entry

Update this page in any of these cases:

- You matched a function after the obvious fixes failed, or after earlier
  notes called it a wall. Add an entry unless an existing entry's fix is
  what worked.
- An existing entry's symptom matched your diff but its fix didn't work,
  and something else did. Add your fix to that entry under a
  **Variant:** line, with the function that needed it.
- An entry's symptom matched but its fix didn't work, and you didn't find
  another. Add an **Also seen, unresolved:** line to that entry naming the
  function, and add the function to [Open walls](#open-walls).
- You stop on a function that still doesn't match. Add it to
  [Open walls](#open-walls) with its symptom and what you tried.
- You found a compiler rule that explains a symptom, even without a match.
  Add it to the entry's **Cause** with the source file and line.

Only record a fix after `python3 scripts/match.py NAME` prints `MATCH` and
`make check` prints `MATCH`. A fix that only shrank the diff belongs in
[Open walls](#open-walls), not in an entry.

### How to write an entry

To add an entry, do the following:

1. Add a row to the [symptom index](#symptom-index). Describe the symptom
   as it appears in `match.py`'s diff, not as its cause. The next agent
   knows only what their diff shows.
2. Put the new entry in the section that fits: code shape, branch merging
   or register allocation. Number it one above the highest existing entry,
   and keep the numbers of existing entries so links stay valid.
3. Use the template below. Show real `-`/`+` asm from `match.py`, cut to
   the lines that differ plus one line of context.
4. Name the compiler rule behind the symptom with a file and line in
   `tools/agbcc/gcc` when you know it. A symptom without a cause is still
   worth recording.
5. Give the smallest C that reproduces the fix, and the function and commit
   where it matched.

The following template shows the entry layout:

````markdown
### N. SHORT_SYMPTOM_TITLE

WHAT_YOUR_DIFF_SHOWS, in one or two sentences.

```
-   TARGET_LINE
+   OURS_LINE
```

**Cause.** THE_COMPILER_RULE (FILE.c:LINE).

**Fix.** WHAT_TO_CHANGE_IN_THE_SOURCE:

```c
MINIMAL_C
```

**Seen in:** `FUNCTION_NAME` (`COMMIT`).
````

Replace the following:

- `N`: the next unused entry number.
- `SHORT_SYMPTOM_TITLE`: the symptom in a few words, such as "An extra
  `ldrh` before a `strh`".
- `WHAT_YOUR_DIFF_SHOWS`: the pattern in the diff, in terms of target and
  ours.
- `TARGET_LINE`, `OURS_LINE`: the asm lines from `match.py`.
- `THE_COMPILER_RULE`, `FILE.c:LINE`: why the compiler produces the
  difference, and where the source decides it.
- `WHAT_TO_CHANGE_IN_THE_SOURCE`, `MINIMAL_C`: the fix.
- `FUNCTION_NAME`, `COMMIT`: where the fix matched.

### Rules for editing

Follow these rules when you change this page:

- Commit your change to this page with the function's match commit, or in
  a docs commit right after it.
- Don't delete an entry because a later function needed a different fix.
  Add a **Variant:** line instead.
- Keep each entry self-contained. An agent jumps straight to it from the
  index.
- Write in the style of the rest of the page: second person, present
  tense, short sentences.
