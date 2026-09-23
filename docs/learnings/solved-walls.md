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

## Open walls

Stalled functions whose symptom has no fix yet. Start here if you pick one
of them, and move the entry into the symptom index once it matches.

None as of 2026-09-23.

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
