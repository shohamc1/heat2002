# 2026-09-23 twin sweep — full experiment log

Session covering the three twin pairs from the parked.md twin map
(plus cross-pollination with sub_0833C874, which another session
matched). None of the three reached MATCH. This document records
everything tried, including the failures, so the next session does not
repeat the dead ends. Summaries also live in `parked.md`; the improved
sources live in `drafts/`.

| Function | Twin | Start of session | End of session | Remaining |
| --- | --- | ---: | ---: | --- |
| sub_080097A4 | sub_08341288 | dead-agent draft, ~800 diff lines | struct + param type fixed, ~350 | switch arm merge + pointer-home permutation |
| sub_08009C4C | sub_083416DC | 485 diff lines (752 B) | **764/764 bytes, 28 diff lines** | five reload-scratch register picks |
| sub_0800A084 | sub_08341B14 | 480 diff lines | two competing 480-line states | car r4↔r5 allocation cascade |

Method note: every experiment below was run through
`python3 scripts/match.py NAME` after editing `src/NAME.c`; the "result"
column is the count of unified-diff `+/-` lines. Micro-experiments
(small standalone functions compiled directly with `old_agbcc -O2
-mthumb-interwork -fhex-asm`) were used to isolate compiler behaviors
without touching the repo.

## Common discoveries (reusable levers)

1. **A u16 stack parameter must be drafted as `u32`.** GCC 2.95's
   `assign_parms` (function.c:4174) gives every scalar parm a pseudo at
   entry unless it is volatile or address-taken — and both of those
   instead create an *entry home copy*, which is also wrong. Only
   word-typed parms keep a REG_EQUIV to their incoming slot, which
   reload can demote to per-use slot reads under register pressure;
   `convert_move` truncates from memory with a narrow load, so u16
   stores still compile to `ldrh`+`strh`. Verified end-to-end on
   sub_080097A4's 6th parameter (read 3×: `ldrh`, `ldrh`, word `ldr`).
   Tested and rejected: `volatile u16` (home + entry copy, per-use
   reads through a frame slot), 4-byte struct-by-value (small structs
   pass as SImode and integrate like scalars).
2. **Array base addresses expand before their index.** For
   `gTable[field]`, old_agbcc emits the table-base pool load first,
   then the index address chain. A pointer local *assigned before* the
   expression therefore inverts the order. Two source forms restore
   it: hoist the bare table (`u32 **tbl = gTable;` immediately before
   the pinned/local pointer assignment), or embed the assignment in
   the index (`gTable[*(p = &car->f162)]`) — the two compile
   identically.
3. **CSE-bind assignments after the expression.** If the ROM computes
   an address inside an expression and *then* keeps it across a join
   (`mov r9, r5`, `adds r6, r2` copies), the original computed the
   expression plainly and assigned the pointer variable *afterward*;
   CSE binds the assignment to the expression's pseudo. This creates
   the spanning pseudo that global alloc homes in a high register.
   Applies to sub_0800A084's `gear`/`tbl`.
4. **`x |= CONST;` as a statement.** Where the ROM ORs into a
   variable's home and then passes the variable (note a trailing
   `adds r0, r4, #0` copy), write the OR as a statement and pass the
   variable. An inline `f(x | CONST)` builds the constant in the
   argument register instead.
5. **Split shift-then-add assignments.** `k = (x + C1) >> N; k += C2;`
   lands the `asrs` directly in k's register; the one-statement form
   stages through an extra `adds rX, r0, #0` move.
6. **Calls inside `a + f(...)` evaluate first.** GCC 2.95 evaluates the
   call operand of a plus before the other operand regardless of
   source order (both orders tested). To compute the table row before
   the call, split the statement and pin the row local if the split
   alone rotates the allocation (see 8).
7. **Anchor pins.** A single `register ... asm("rN")` pin — *any one*
   of the pins the ROM's registers suggest — is often enough to lock
   the whole function's allocation into place; the others can be plain
   locals. sub_08009C4C needs exactly one of {a→r4, row→r5}; with zero
   anchors the allocation rotates (car→r8, etc.). Verified: each pin
   individually removable at 28 diff lines; all removed = 582.
8. **Pinning a base pointer kills address CSE.** A register-local
   alias of a struct pointer makes every field access re-materialize
   the address (sub_0800A084's `unk9C -= 0xA` computed its address
   twice). Pin pointer-*locals* (addresses of fields), never the
   struct pointer itself.
9. **Declaration order is irrelevant.** GCC 2.95 creates scalar
   pseudos at first reference, not at declaration. Five declaration
   permutations of sub_08009C4C produced byte-identical output.
10. **Reload decides the constant splits.** `movs #imm; lsls` chains
    for offsets > 255 and the `ldrb` input loads do not exist at
    local-alloc time (constants still inline in their `plus` insns in
    the `.lreg` dump); reload creates them after global alloc. Their
    registers come from `allocate_reload_reg` (reload1.c:5026):
    round-robin over `spill_regs` starting after `last_spill_reg`,
    with a pass-0 that only shares regs used by reloads *of the same
    insn*. These are not steerable from C by any shape found.
11. **Global-alloc priority.** `allocno_compare` (global.c):
    `floor_log2(n_refs) * n_refs / live_length * 10000 * size`,
    descending, ties by ascending allocno number (creation order).
    `find_reg` pass 0 tries to share an already-allocated reg, pass 1
    scans first-fit from r0 up (skipping call-used regs for
    call-crossing pseudos). Short-lived few-ref pseudos out-rank
    long-lived many-ref ones — which is why expression temps can
    displace `car` from r4.
12. **High-vs-low pointer homes decide address-chain shape.** Pointers
    homed in high regs (r8-r12) are computed as
    `movs rX,#imm; adds rX,rX,rm` (+`mov high, rX`); low-homed ones as
    `adds rX,rm,#0; adds rX,#imm8`. Seen in both sub_080097A4 and
    sub_08009C4C.

## sub_080097A4 (twin sub_08341288) — 892 B

Starting point: the wave-4 dead-agent draft. Progress this session:
~800 diff lines → ~350.

### Fixed

- **`struct Ent` layout**: the draft was missing 4 bytes after `f00`
  and 2 between `f38`/`f3C` — every field compiled to
  name-minus-4/-2 (e.g. `f34` at 0x30). Detected from
  `strh r1, [r5, #62] @ 0x3e` for `car->f40`. Added `u8 pad04[4]` and
  `u8 pad3A[2]`; field names now equal offsets.
- **`f168` is `u8`**, not `s32` (target `strb`, ours `str`); fixed
  with `u8 f168; u8 pad169[3]`.
- **6th parameter type**: the big one — see lever 1. `u16 d` → `u32 d`
  removed the entry `ldr r1,[sp,#40]; lsls #16; lsrs #16; mov r10,r1`
  block, which had stolen r10 from the p7d pointer local and forced
  `sub sp, #8` (target has `#4`). The three target reads (`ldrh`,
  `ldrh`, word `ldr`) fall out naturally.
- **`car->f58` is two array refs**, one per arm of the
  `gUnk_0200215C == 4` test (each arm has its own pool load; the
   scale/load/store tail merges by cross-jumping). The draft's ternary
   index hoisted the base load — wrong.

### Tried and rejected (all still in the ~350-line state)

- `volatile u16 d` and 4-byte-struct-by-value `d` (see lever 1).
- Everything in the switch section below.

### Blocker 1 — the switch's duplicate-valued arms

The ROM keeps **11 separate bodies** for the 11 cases; the three
duplicate-valued pairs (0x28/0x28 for cases 3/6, 0xF/0xF for 10/11,
5/5 for 2/14) each have *two adjacent identical bodies*. Every source
shape tried merges them into one shared body (jump-table entries point
at the same address):

| Shape | Result |
| --- | --- |
| plain `break` in every case | merged (expand_case shares `case A: case B:` labels, and cross-jump merges the rest) |
| `goto out;` on cases 6/11/14, `out:` after the if/else | merged (tensioning unifies the labels first) |
| nested switch (outer on `g`, case 0xF = inner switch) | merged |
| `else { goto out; }` | merged |

Mechanism, read from the compiler source: `find_cross_jump`
(jump.c:2687) walks back from two jumps, matching insns (patterns,
after reload renumbering); `movs rX,#C; b join` arms with equal C
match fully, the preceding CODE_LABEL decrements the required minimum,
and `do_cross_jump` redirects + deletes. The arms end up in the same
`jump_chain` because `mark_all_labels`/threading unifies the
break-target and goto-target labels through empty blocks before the
cross-jump pass runs (jump2 runs *after* reload, toplev.c:3164).
For the original to keep 11 bodies, the duplicate arms' jumps must
have been in *different* jump chains at jump2 time — i.e. the labels
never tensioned together — and no C shape I found prevents that while
still producing the ROM's final all-arms-point-at-the-store layout.
The `bhi` range-guard and `bne` g-guard both target the shared
`movs r0, #0` (default) body in the ROM, so the else-path and default
*were* merged — the compiler demonstrably merges some identical bodies
here but not the three duplicate pairs.

### Blocker 2 — pointer-local homes

Target: p4c=r2, pe4=r6, pe8=r7, pec=r12, p7d=r10, p4e=[sp] (with the
shape rule of lever 12). Ours permutes (p4c→r12 etc.). The permutation
follows from local/global allocation order over the six pointer
pseudos plus the `d`/`&g` cache pseudos; not yet steerable. Likely
coupled to blocker 1 (the switch region's pseudo structure).

## sub_08009C4C (twin sub_083416DC) — 764 B

Starting point: wave-5d dead-agent draft, 485 diff lines at 752 bytes.
**End state: 764/764 bytes, 28 diff lines** — five register picks.
Two passes of work.

### First pass — structural fixes (485 → 28)

| Change | Result |
| --- | --- |
| split `k = (car->unk34 + 0x200) >> 10; k += 0x28;` (lever 5) | removes `adds r4, r0, #0` move |
| flip branch OR constant `0x1000000` → `0x10000000` (target `0x80<<21`) | real constant bug found |
| `a \|= 0x10000000;` statement + pass `a` (lever 4) | restores `orrs r4,r0; adds r0,r4,#0` |
| pin `&car->unk162` → r8; later shown removable (lever 7) | fixes flip-branch homes |
| hoist `tbl = gUnk_083676B8;` before the pointer assignment (lever 2) | fixes table-before-chain order |
| E38 row: pin r5 **and** split `row = gUnk_083681E8[idx]; row += sub_080172C8(...)` (lever 6) | fixes call-after-table order; the split alone rotated the whole allocation — the pin re-anchors it |
| else-branch row pinned r5 too | fixes its home |
| remove `k4`/`row` intermediates from the flip branch (natural `[k]` indexing; the `k*4` mult lands in r7 once r4 is anchored) | matches `lsls r7, r4, #2` |
| scope `a`,`b` into the flip branch | neutral but kept (cleaner) |

### Second pass — everything that did NOT move the five sites

Applied the sub_0833C874 lessons (mask literals already inline;
volatile discipline already correct; **separate counters per branch**):
splitting `k`/`t`/`t5` into per-branch variables — all three at once
756 B/236 lines (worse); `k` alone neutral.

| Experiment | Result (diff lines) |
| --- | ---: |
| k-math: split the `+0x200` into its own statement | 38 (reintroduces the move) |
| k-math: `512` literal / `(s32)` cast / `/1024` / reassoc `(x>>10)+1` | 28 / 28 / 639 / 28 |
| `0x200 + car->unk34` commuted; `0x20 & k` commuted; `&= 63` decimal | 28 each |
| t5 row hoisted to local; flip==0 row hoists; `*(gUnk_08367730 + car->unk162)` ptr-arith | 28 / 28 / 46 |
| flip branch: no `tbl` hoist | 38 (chain before table) |
| flip branch: `gUnk_083676B8 + *p162` pointer arithmetic | 415 |
| flip branch: row hoist `*(u32 **)(t3 + k*4)` | 207 |
| embedded `*(p162 = &car->unk162)` in the index (lever 2) | 28 (identical bytes to hoist; drops the invented local — kept) |
| unpinned `u8 *p162` local instead of r8 pin | 28 (identical — kept) |
| no `tbl`, no `p162`, plain `gTable[car->unk162][k]` everywhere | 398 (car→r8 cascade: CSE does not unify the two pluses across the intervening call) |
| all pins removed | 582 |
| pin isolation: a-pin only / row-pins only / a+one-row / one-row only | 28 each — exactly one anchor suffices (lever 7) |
| single function-scope `row` (one pseudo, two assignments) | 28 — kept in the final draft |
| inline `gUnk_0202A550` (drop `base` local); `__attribute__((unused))` | 28 each |
| random search: 9 binary source-shape knobs (t5/f01/f02/fl1/fl2/a/b/k/u172), 24+ combinations | best = the base itself |
| compiled with the **other** `agbcc` binary | same 28, same five sites |

### The five remaining sites (all reload scratches — lever 10)

1. t5-site chain `movs #0xB1; lsls #1`: target r3, ours r2.
2. flip==0 first lookup `ldrb r?, [r7]`: r3 vs r2.
3. flip lookup1 `ldrb r?, [r0]`: r2 vs r0.
4. flip lookup2 `mov r?, r8; ldrb r?, [r?]`: r3 vs r0.
5. else-branch chain: r3 vs r2.

Ours picks first-fit from r0 (skipping the live table pseudo in r1);
the ROM rotates r2→r3→r2→r3, implying one additional occupied or
forbidden register at each site in the original compile. Traced via
`-dc -dl -dg` dumps: at `.lreg` the constants are still inline in
their `plus` insns and the loads are fused
`(ashift (subreg (mem ...)) 2)`; the splits and input reloads appear
only after global alloc, created by reload. No source shape moved
them; they are reload-internal state. Both agbcc binaries produce the
same picks.

## sub_0800A084 (twin sub_08341B14) — 592 B

Starting point: wave-4 dead-agent draft with pins v(r7), mode(r8),
tbl(r9), pa(ip) — 480 diff lines, everything matching through
`0x800a0e4`, the t2 region wrong (tbl chain emitted before the index
address, plus two extra reloads `mov r3, ip; mov r0, r9` per arm).

### What the ROM actually does (solved)

The target computes the `&car->unk3E` index address *before* the
`&car->unkE4` chain, and homes the chain in r9 with `gear`'s copy
(`adds r6, r2`) at the join: the original had **no tbl/gear variables
before the expression** — `t2 = (*pa * car->unkE4[car->unk3E]) >> 6`
computes both addresses in expansion order, and
`gear = &car->unk3E; tbl = &car->unkE4;` assigned *afterward* bind by
CSE (lever 3). That is what produces `mov r9, r5` (tbl's home
establishment) and `adds r6, r2` (gear's join copy) — and the >>5
re-lookup reads both through their homes.

### The cascade

Restructuring the arms this way fixes the entire t2 region — and moves
`car` from r4 to r5, because a pa-pointer cache pseudo (created by the
restructure) then wins r4 and everything rotates. Results:

| Experiment | Result |
| --- | --- |
| original draft (a1: pins, tbl assigned before expression) | 480 lines, right allocation, wrong arm order |
| expression-first arms, unpinned tbl | 556 (car→r5, r9 unused) |
| + `gear`/`tbl` assigned in-arm after the expression | 560 |
| + tbl pinned r9 | 482 (right structure, car still r5) |
| car aliased to a pinned r4 register-local | 612 — prologue matches to `0x800a09a`, but the pin kills address CSE: `unk9C -= 0xA` computes its address twice (lever 8) |

The saved draft is the expression-first form with the four original
pins. Breaking the r4/r5 circle needs either a natural way to keep the
pa-cache pseudo out of r4 or to boost `car`'s priority — i.e. the same
class of reload/alloc state as sub_08009C4C's five sites.

## Cross-pollination with sub_0833C874 (matched by another session)

Their match notes: mask literals written inline; **separate counters
per branch** (a shared counter kept a compiler-created address pseudo
alive that pushed `phase` out of r10); volatile only where the ROM
re-reads hardware; a volatile timer read and `i = 0` in the delay loop
as the last two diffs.

Applied here: the counter lesson was tested first on sub_08009C4C
(neutral there); the mask/volatile lessons were already satisfied.
Their "one address pseudo stays alive and displaces a high home"
diagnosis is the same phenomenon as this session's anchor-pin and
reload-scratch findings, from the other side.

## Compiler internals read (file:line map)

- `gcc/function.c` 4150-4470 — `assign_parms`: scalar parms get
  pseudos; volatile/addressable create entry home-copies; word-sized
  parms keep slot REG_EQUIV (lever 1).
- `gcc/expr.c` 5285-5530 — `expand_expr` ARRAY_REF falls through to
  COMPONENT_REF handling; inner (base) operand expands first (lever 2).
- `gcc/toplev.c` 3067-3181 — pass order: regmove → local+global alloc
  → reload → flow2 → jump2 (cross-jumping) → machdep reorg.
- `gcc/jump.c` 589-680, 1947-1996, 2687-2870 — threading,
  cross-jump chain walk over same-label jumps, `find_cross_jump`
  matching rules (sub_080097A4 blocker 1).
- `gcc/gcse.c` 1219-1345 — `load_killed_in_block_p`: calls kill all
  loads for gcse (ruled out gcse as the arm-merge mechanism).
- `gcc/global.c` — `allocno_compare` (priority formula, lever 11),
  `find_reg` (share pass, first-fit pass).
- `gcc/local-alloc.c` 1868-1990 — `find_free_reg`: insn-granular
  `regs_live_at`, r0-first.
- `gcc/reload1.c` 5026-5230 — `allocate_reload_reg`: round-robin over
  `spill_regs` from `last_spill_reg`; pass 0 shares only within the
  same insn (lever 10).
- `gcc/reload.c` 675+ — `push_reload`.

## Ranked leads for the next session

1. **sub_08009C4C five sites**: find what occupies r2/r3 at those five
   points in the original compile. It is a reload artifact invisible in
   the final code; candidates are an extra reload earlier in the
   function (the round-robin `last_spill_reg` advances one slot per
   allocation) or a `RELOAD_FOR_OTHER` marking. The function is
   otherwise done — 764/764 bytes.
2. **sub_080097A4 switch**: find a source form whose duplicate case
   arms sit in different jump chains at jump2 time (labels that
   tensioning cannot unify). Then re-attack the pointer permutation,
   which is probably coupled.
3. **sub_0800A084**: break the pa-cache/car r4-r5 circle — e.g. find
   the source shape whose pa reads reload per-use (as the ROM does)
   instead of caching the ip pin in r4.
4. The anchor-pin observation (lever 7) suggests all three functions
   are missing *one* structural detail each that supplied the natural
   allocation pressure; each pin is a marker for exactly that gap.

## Post-mortem addendum: the fixes that landed (2026-09-23, later)

Another agent matched both remaining functions of this sweep, plus the
sub_08003330/sub_0833C874 pair:

- **sub_08009C4C** (`6d50015`, "unpin the unk162 pointer"): the only
  change from the state above was removing the *last* pin
  (`register u8 *p162 asm("r8")` → plain `u8 *p162`). The pin made
  expand copy r8 into a fresh pseudo before every ldrb (a high hard reg
  is never a valid thumb base); as a plain local it still lands in r8,
  but reload fixes each address itself, one of those reloads needs r3,
  and adding r3 to reload's spill set shifts the round-robin to the
  ROM's picks at all five sites. **Lesson missed here: I tested each
  pin's removal individually but never the winning *combination* —
  "individually removable" was mistaken for "only one anchor needed".**
  Exhaust pin subsets, not single pins.
- **sub_0800A084** (`4832f44`, "let GCSE build the pointer copies"):
  plain field accesses everywhere — no `pa`/`tbl`/`gear` locals and no
  pins at all; GCSE creates the spanning address pseudos and the
  `mov r9, r5`-style copies. Two priority details: writing each product
  as `element * car->unkA2` (operand order) lengthens the unkA2
  pointer's live range so `v` is allocated first (v r7, pointer ip,
  mode r8), and reusing `t3` for the `unk2C` load before
  `sub_0800A034` puts that load in r1.
- sub_08341B14/sub_083416DC followed as direct ports of their twins.

### Applying these to sub_080097A4 (largest remaining, 892 B)

The pointer-local-free rewrite (all six `p4c`/`pe4`/`pe8`/`pec`/`p7d`/
`p4e` locals replaced by plain field expressions) lets GCSE hoist the
six address computations before the CBC8 loop — the correct structure,
matching the ROM's layout — but lands at 364 diff lines vs the old
draft's 350: the homes rotate (f4C→ip instead of r2; loop base r3
instead of r4). Type variants (v/i as s32), loop form (for vs do/while),
constant spellings, and the other compiler binary are all neutral;
`i` widened to s32 is worse (436). The new draft keeps the plainest
form as the better base.

The dominant blocker remains the switch: the ROM keeps 11 separate arm
bodies including three duplicate-valued adjacent pairs, while the
zero-valued table gaps point at the single default body — i.e. the
original compile cross-jumped *nothing* in the switch (gap-to-default
pointing is expand_case, not cross-jump). Every C shape tried (plain
breaks, gotos to one label, gotos to three stacked labels — defeated
by GCC's label compaction — nested switch, else-goto, direct
per-arm field stores) merges the equal-value pairs, and both agbcc
binaries do it. The remaining explanation is that the arms' value
insns carried different registers at cross-jump time (per-arm reload
state), which no tested source shape produces.

## sub_08007C44 session (2026-09-23, later) — 692/692 bytes

Started at the 2026-09-22 draft state (700 B build, 214 raw diff lines).
Now 692/692 bytes with 53 normalized differing instructions (pool-offset
ripples excluded — match.py's raw count is ~300 because a 0-byte shift
moves every `ldr [pc, #N]`; a normalized comparison script that masks
pc-relative offsets and pool data is the honest metric near the end).

What fixed it, in order of discovery:

- **`bit` is a variable assigned between the loops** (`bit = 1;` in the
  outer body, before the inner loop), not a per-inner-iteration constant.
  The ROM's `movs r3,#1` sits *before* the inner-loop label, the value
  spills across the `sub_0800CBB8` call (slot 0x38) and all four uses
  (the AND plus three `= bit` stores) reload it. With `bit = 1` inside
  the inner loop, GCC constant-folds it (reg_equiv_constant remat) and
  emits one `movs` per basic block instead.
- **That spill slot is the frame's missing 6th slot.** The old draft's
  `pad[0x2C]` was a hack to reach the 64-byte frame; the real frame is
  `pad[0x28]` + six spilled s32s (p, yend, p2, yc, bit, xc). Pad size
  bugs near the end of a function: count the target's distinct
  `[sp, #N]` offsets first.
- **The two field loads must be hoisted ahead of the shifts** via two
  plain field temps (`yend = car->unk00; y = car->unk08;` then the
  shift/add statements). The ROM loads both fields, then does both
  shifts, then both adds; per-statement `xc = (car->unk00 >> 19) + 1`
  interleaves. The temps are load-only — splitting the shifts or the
  adds into their own statements doubles the spilled-xc store or adds
  register copies (both tried, much worse).
- Small knobs that mattered as a *combination* only: bit u8, statement
  order `yend; cnt; p2`, `cnt` declared last. A 6-knob matrix found the
  pair; no single knob moved anything (the sub_08009C4C lesson again).

Remaining (all one class — allocation order): the head's two surviving
pointer pseudos land r9/r8 where the ROM has r8/r5 (the ROM's &unk172
takes a *low* r5 while skipping a free r4/r7 — the same invisible
reload-state skip as sub_08009C4C's r2/r3), the p-zero scratch (r0 vs
r7), and the xc/yc chain register detail. The xc/yc *order* difference
(both shifts before both adds, one xc store) has no statement form: a
single `xc = (x >> 19) + 1` statement gives one store but interleaves;
split statements give the order but two stores/copy chains.

**Resolved in `2bc9c85`.** A plain-C rewrite matched, and it
contradicts two conclusions above:

- `bit` isn't a variable. With literal `1`s, loop optimisation merges
  the constants into one register and hoists it into the inner loop's
  preheader, where the ROM has `movs r3, #1`. A named `bit` gets
  hoisted out of both loops instead.
- The xc/yc order has a statement form: `a = car->unk00; b =
  car->unk08; cx = a >> 19; cy = b >> 19; cy += 2; cx += 1;` with `a`
  and `b` as fresh block-local temps. Reassigning `cy` stops CSE from
  rebuilding `cy - 1` from the shift result. No `p2` helper is needed.
