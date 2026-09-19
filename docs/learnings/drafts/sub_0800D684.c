/*
 * sub_0800D684 -- SEVENTH PASS (2026-09-19). Status: 2006-byte function, size
 * 2010, 2 structural hunks (the post-loop `cc` remat inserts), sdiff 602.
 *
 * Every change beyond the original reconstruction is semantics-preserving and
 * most only pay off as a set; the full narrative, the corrected metric and the
 * analysis of what still differs are in
 * docs/learnings/drafts/sub_0800D684-NEXT.md
 *
 * Recent accepted edits, in order:
 *   - mirror-1 edge-0 guard carrier `(d0 = (e = v2 - 0x1C00))` dropped;
 *   - mirror-1 edge-2 guard value carried through `d1`; mirror-2 edge-0 guard
 *     value carried through `d1`; mirror-1 edge-1 bound carried in `k3`;
 *   - mirror-1 edge-3 self-store routed through `d0`;
 *   - mirror-2 edge-3 bound carried in `d1`;
 *   - pre-loop call argument carried in `k0`; post-loop `(*cc).c` carried in
 *     `d1`; `dz = 4`/`k3 = 4` shift carrier; `gUnk_083FDA2C[ccd].f0` dot
 *     spelling; `-gUnk_0202CC90.g` direct global read;
 *   - mirror-1 `d0 = pa[4];` respelled `d0 = gUnk_0202CCB0[4];` (pa is set
 *     once and never reassigned; the global is read-only here).
 */
/*
 * sub_0800D684 -- FIFTH PASS (2026-09-18). Status: 2006-byte function,
 * exact instruction count (959) not reproduced; 6 structural hunks at
 * size 2010. Full narrative: docs/learnings/drafts/sub_0800D684-FIFTH-PASS.md
 *
 * Two edits adopted this pass, both in the post-loop block:
 *   1. `d1 = (s32)&((struct Ent *)u)->unk55; v55 = *(u8 *)d1;` became
 *      `k2 = (s32)&((struct Ent *)u)->unk55; v55 = *(u8 *)k2; d1 = k2;`
 *      -- the ROM materialises the address into a temp, loads through it
 *      and only then copies it into d1's register; spelling it that way
 *      also produces the ROM's third `movs r1,#0` before sub_0800BA34
 *      (the loaded byte lands in r1 and kills the stale zero).
 *   2. `hit2 = (struct Ent *)w;` moved above `u->unk48 = u->unk2C;` so
 *      hit2/w stay coalesced; without it edit 1 costs a `mov r8,r9` and
 *      a 2-byte pool pad.
 *
 * Remaining hunks (all reload/spill-register choices, not allocno ones):
 *   T52            pre-loop: ROM `ldr r7,=pa; adds r1,r7,#0`, ours `ldr r1,=pa`
 *   O264           `adds r6,r4,#0` emitted for `k1 = e; d1 = k1;`
 *   O505/T511      second-half edge-2 `e << 16` scheduled one slot early
 *   O598/O617      two extra cc rematerialisations in the post-loop block
 *
 * Measured arithmetic (112 variants, exact for 105): size == 2006 +
 * 2*(o_extra - t_extra). tail_k2 is at excess +2, so acceptance needs the
 * other sites to net -2 instructions; the 505/511 pair is count-neutral.
 * Ruled out this pass: unpatched precompute calls.c (byte-identical output
 * for this function), literal-address CONST_INT forms, -f sweeps, the
 * reload `last_spill_reg` rotation (index shifts 0..5 change nothing or
 * regress), and ~2900 single self-store/re-read dials.
 */
/*
 * sub_0800D684 quarantine notes (2026-09-17, third pass) -- 2006/2006
 * bytes (EXACT byte-count and instruction-count match: 959 instructions
 * on both sides), regmasked diff = 8 instructions (target/ours
 * disassembly with register names blanked, `[pc, #N]` and `0x...`
 * operands normalized, then diffed). Down from 16 this pass via
 * twenty-five more fixes (see "THIRD-PASS FIXES" below). Every call, every
 * guard, the full edge math, the post-loop hit processing, and the
 * return shape match. The 8-line diff is downstream of a handful of
 * true differences clustered around the second (cursor-vs-a1) loop
 * half's edge-1/edge-2 region: `fulldiff.py` (ad hoc script; see below)
 * shows 8 scattered single/double-instruction delete+insert pairs (net
 * 4 extra each way) rather than one clean substitution -- see fix 20's
 * note for how this shape changed from the earlier single-hunk state.
 *
 * KEY DISCOVERIES this pass, roughly in the order they mattered:
 *
 * 1. Pointer aliasing (carried over from the first pass): read
 *    gUnk_0202CCB0/gUnk_0202CD30 through local `pa`/`pb`, and
 *    gUnk_0202CC90 through a local `cc = &gUnk_0202CC90;` assigned
 *    alongside `pa`/`pb` before the loop. Each alias reproduces a
 *    mid-function pool-reload pattern the raw global reference doesn't.
 * 2. The `hit2 = (struct Ent *)w;` split (carried over): introduced
 *    right after `u->unk48 = u->unk2C;`, used for the rest of that
 *    block instead of repeated `(struct Ent *)w` casts.
 * 3. `for` loop, not `goto`-threaded (carried over): fixes the
 *    loop-entry pool-load order.
 * 4. The dx/dz register-color tie (see "REMAINING DIFF" in the old
 *    notes below -- now resolved as a side effect of items 1-3 plus
 *    natural reallocation once other pressure changed; no dedicated
 *    fix was needed once the rest of the loop body matched).
 * 5. ASYMMETRY IS REAL AND LOAD-BEARING. The two mirrored loop halves
 *    (a1-vs-cursor and cursor-vs-a1) are NOT byte-symmetric in the
 *    target, and forcing them to match by copy-pasting one shape onto
 *    both makes things worse every time this was tried. Concretely:
 *      - `edge index 1`'s guard reads `e = -0x1C00 - v2` in the FIRST
 *        half but `e = -0x1C00 - v1` in the SECOND half (found by
 *        comparing raw disasm operands directly: the first half reads
 *        stack slot v[1], the second genuinely needs v[0], confirmed by
 *        testing v2 in the second half too -- it grows the function by
 *        4 bytes, so v1 is correct there).
 *      - `if ((u8)(hit2->unk7C - 5) > 2)` in the SECOND half's mirrored
 *        block reads through `((struct Ent *)w)->unk7C` (the pre-alias
 *        cast) instead of `hit2->unk7C`, even though `hit2 = (struct
 *        Ent *)w;` was just assigned one line earlier.
 *      - `k1 = gUnk_083FDA2C[(*cc).d].f0;` needed rewriting as
 *        `k1 = (&gUnk_083FDA2C[(*cc).d])->f0;` (address-then-arrow
 *        instead of direct dot access) to get a downstream `cc`-pointer
 *        reload to line up; the mirrored `k0 = ....f1;` line must NOT
 *        get the same treatment (tried; regresses).
 *      - `sub_0800BA34(v55, v55, -6, 0, v55, v55, 0x400);`: target
 *        loads three separate zero immediates (`movs r0,#0`, `movs
 *        r1,#0`, `movs r3,#0`); ours elides the `r1` one via proven
 *        dataflow. Still unresolved (2 bytes' worth by itself, but
 *        total byte count already matches target exactly, so this is
 *        balanced by an equal-and-opposite difference elsewhere -- not
 *        a size bug, just an unmatched pair of instruction identities).
 *      - `a1->unk175 = a1->unk175;` (a genuine no-op self-store) right
 *        before `loop_continue:` measurably changes downstream register
 *        allocation and is required for the match; it forces a real
 *        memory touch (unlike a `register` variable self-assign, which
 *        the compiler elides with no effect -- tried and confirmed inert).
 *      - `*(u8 *)d1 = 0x10; hit2->unk55 = 0x10;` needed rewriting to
 *        share one materialized `v55 = 0x10;` local instead of two
 *        independent literal-0x10 stores, to get the constant reused
 *        across both `strb`s instead of reloaded.
 *
 * METHODOLOGY that worked this pass:
 * - A masked-diff comparator (blank register names + `[pc,#N]` operands
 *   + hex immediates, then diff line-for-line) tracks real progress far
 *   better than raw byte count or unmasked instruction diff, both of
 *   which swing wildly on one register recoloring.
 * - A full, non-truncated instruction-count comparator (compare the
 *   *actual* target length against ours, not clipped to whichever is
 *   shorter) is what actually found the "only one instruction identity
 *   differs, nothing is missing or extra" fact above -- match.py's own
 *   truncate-to-ours-length diff view hides this because it can only
 *   ever compare min(ours, target) bytes.
 * - The permuter (`scripts/permute.py`, run repeatedly at each new
 *   plateau with `-j6`, several thousand iterations each) found EVERY
 *   asymmetric fix listed above. None of them were guessable from
 *   first-principles register-allocator reasoning; they were only
 *   found by feeding the permuter's own low-scoring candidates back
 *   through the masked-diff comparator to separate genuine wins from
 *   candidates that scored well on the permuter's internal metric but
 *   didn't move our real diff count (this happened often -- always
 *   verify a permuter candidate against masked-diff before adopting it).
 * - Register `asm("rN")` pins remain a dead end for every variable
 *   tried (cursor, v1hold, d0, d1, u, w, dx, dz, self, other, out,
 *   `cc`): pinning any of them after the rest of the function settled
 *   into place regresses badly, because "correct" register colors here
 *   come from priority-driven global-alloc reacting to the whole
 *   function's pressure, not from any single variable's own preference.
 *
 * THIRD-PASS FIXES (16 -> 12), all found by re-running the permuter
 * from the second-pass 16-diff state and hand-isolating the genuine
 * change from its cosmetic reformatting, per the same workflow as the
 * second pass:
 * 1. `dz = self->unk08;` rewritten as `d0 = self->unk08; dz = d0;`
 *    (route the load through the otherwise-dead `d0` local instead of
 *    assigning `dz` directly). Worth 16 -> 16 masked-diff instructions
 *    on its own but many fewer raw diff lines (300 -> 280 unmatched);
 *    kept because it is a strict improvement with no size or structure
 *    cost.
 * 2. `v1hold = (v1 = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);`
 *    (the FIRST loop half's occurrence only) rewritten with the nesting
 *    order swapped: `v1 = (v1hold = (...));`. This is the same
 *    expression, evaluated the same way by C semantics, but changes
 *    which of the two stores (`mov r9, r1` to the register vs `str r1,
 *    [sp, #16]` to the stack) the compiler emits first, matching the
 *    target's order. Worth 16 -> 14 masked-diff instructions.
 *    ASYMMETRY AGAIN: applying the identical swap to the SECOND loop
 *    half's mirrored occurrence (`v1hold = (v1 = ((k1 = pa[1]) ...`)
 *    also independently reaches 14 masked-diff instructions, fixing a
 *    different (complementary) subset of the diff -- but applying BOTH
 *    swaps simultaneously regresses catastrophically (291 masked diff).
 *    Only one of the two mirrored blocks wants this order; empirically
 *    the first half's swap left a slightly cleaner raw diff (278 vs 288
 *    unmatched lines) and was kept.
 * 3. The SECOND loop half's `v1hold = (v1 = ((k1 = pa[1]) * d0 - (k0 =
 *    pa[0]) * d1) >> 8);` (the one item 2 says NOT to swap directly)
 *    instead routes through `e` (dead at that point, reused as a
 *    carrier -- same idiom as fix 1's `d0`): `e = (v1 = (...)); v1hold
 *    = e;`. This is NOT the same as swapping the nesting order (that
 *    regresses when combined with fix 2, per item 2's note); routing
 *    through an unrelated dead local instead avoids the conflict. Worth
 *    14 -> 12 masked-diff instructions on top of fixes 1 and 2.
 * 4. `if ((u32)(edgeq + v2 + 0x1C00) <= 0x3800)` (all three of edges
 *    2 and 3 that use this shape, in both loop halves) routed through
 *    `d1` as a carrier: `d1 = edgeq + v2 + 0x1C00; if ((u32)d1 <=
 *    0x3800)`. Stays at 12 masked-diff instructions (does not touch
 *    the one remaining true hunk) but cuts the raw unmatched-line count
 *    from 276 to 260 with no size or structure cost -- a strict
 *    cleanup, kept because it makes the remaining diff easier to read
 *    and may reduce noise for future permuter runs.
 * 5. A `lim3800` local (named `new_var` by the permuter), set to
 *    `0x3800` right after the `dz > 0x6400` guard, used as the RHS of
 *    ONE specific edge-3 bound check in the FIRST loop half only:
 *    `if ((u32)d1 <= lim3800)` in place of the literal `0x3800`.
 *    Applying the same substitution to the other three `<= 0x3800`
 *    occurrences (edge 2 of either half, or edge 3 of the second half)
 *    was tried individually; each one regresses (masked diff rises to
 *    14-16). Only this one occurrence wants the carrier. Worth
 *    12 -> 12 masked-diff instructions but cuts unmatched lines
 *    260 -> 248; another strict cleanup, same rationale as fix 4.
 * 6. `hit2->unk88 -= d0 >> 14;` (the SECOND loop half's `unk88`
 *    decrement only) wrapped in a `do { ... } while (0);` -- a no-op
 *    control-flow wrapper, not a temp-variable carrier. Cuts unmatched
 *    lines 248 -> 238 with no size/structure cost. Applying the same
 *    wrapper to the mirrored FIRST-half statement
 *    (`u->unk88 -= d0 >> 12;`) has no effect either way; left as a
 *    plain statement there.
 * 7. `k1 = (&gUnk_083FDA2C[(*cc).d])->f0;` further split: added
 *    `ccd = (*cc).d;` right after `ang = ...;` and read `ccd` in place
 *    of `(*cc).d` for the `k1` index only (`k0`'s `.f1` line keeps
 *    reading `(*cc).d` directly, per fix 3's note that only one of the
 *    two wants the treatment). No masked-diff change alone but sets up
 *    fix 8.
 * 8. The SECOND half's edge-3 bound check split one step further:
 *    `d1 = edgeq + v2 + 0x1C00;` became `k2 = edgeq + v2; d1 = k2 +
 *    0x1C00;`. Combined with fix 7, cuts unmatched lines 238 -> 236.
 *    The same `k2 = edgeq + v2; d1 = k2 + 0x1C00;` split, applied to
 *    the remaining three `edgeq + v2 + 0x1C00` sites from fix 4 (edge 2
 *    of both halves, edge 3 of the first half), cuts unmatched lines
 *    further: 236 -> 234 -> 232 -> 230, one site at a time, each a
 *    strict improvement.
 * 9. The same `k2 = edgeq + v1;` split applied to the FIRST half's
 *    edge-1 check (`if ((u32)(edgeq + v1 + 0xF00) <= 0x1E00)` ->
 *    `k2 = edgeq + v1; if ((u32)(k2 + 0xF00) <= 0x1E00)`) even though
 *    that check already matched byte-for-byte before the split. Cuts
 *    unmatched lines 230 -> 222 with no size/structure cost -- proof
 *    that these carrier splits reduce noise even on already-correct
 *    code, not just on mismatching lines. The mirrored split on the
 *    SECOND half's actual-mismatching edge-1 check (`edgeq += v1;` ->
 *    `k2 = edgeq + v1;`) was also tried: net neutral (stays at 222),
 *    not adopted to keep the diff smaller.
 *
 * CORRECTNESS CAUTION found this pass: a permuter candidate at score
 * 1440 (masked diff 12, unmatched 192 -- better than any fix above)
 * introduced `d1 = u;` inside edge-1's guard block, then read `d1` in
 * place of `u` for edge-1's own call args AND for edges 2 and 3's
 * `edgeq = e * u / w;` expressions afterward. This is byte-improving
 * but a REAL correctness bug: if edge-1's guard is false, `d1` is never
 * updated and edges 2/3 would read a stale, unrelated value (`d1` last
 * held `pa[7] - pb[7]` from the matrix setup) instead of the current
 * `u`. Tried keeping only the edge-1-local half of the change (`d1 = u`
 * used just for edge-1's own two args, `u` untouched in edges 2/3):
 * regresses badly (222 -> 362 unmatched), confirming the byte-match was
 * inseparable from the unsafe cross-edge propagation. NOT adopted.
 * General lesson: a permuter candidate that reuses a variable across a
 * conditional boundary needs a dataflow check (is the reused variable
 * actually live and equal on every path that reaches the reuse?) before
 * being trusted, even when it byte-matches better than every known-good
 * alternative.
 * 10. The SECOND half's edge-3 bound check dropped its `d1` carrier
 *    entirely, inlining `k2 + 0x1C00` straight into the `if`:
 *    `k2 = edgeq + v2; if ((u32)(k2 + 0x1C00) <= 0x3800)`. This is safe
 *    (no cross-conditional reuse, `d1` was purely local to this one
 *    check already). Cuts unmatched lines 222 -> 220.
 * 11. The same `d1`-drop from fix 10 applied to the SECOND half's
 *    edge-2 check too (`d1 = k2 + 0x1C00; if ((u32)d1 <= 0x3800)` ->
 *    `if ((u32)(k2 + 0x1C00) <= 0x3800)`). Cuts unmatched lines
 *    220 -> 216. The remaining two `d1 = k2 + 0x1C00;` sites (FIRST
 *    half's edge-2 and edge-3) do NOT want this same drop -- tried,
 *    regresses to 234.
 * 12. `&gUnk_0202CC90` replaced with the already-live `cc` pointer for
 *    every `sub_0800D64C` call EXCEPT the FIRST half's edge-0 call
 *    (which keeps the raw global address -- tried converting it too,
 *    regresses 214 -> 216). Cuts unmatched lines 216 -> 214.
 * 13. The pre-loop `sub_0800D5D4(a1, pa);` call (open since the very
 *    first pass; see finding #1 in the "REMAINING DIFF" notes further
 *    down) finally fixed: `k2 = (s32)pa; sub_0800D5D4(a1, (s32 *)k2);`
 *    -- route `pa`'s address through the otherwise-dead `k2` local via
 *    an `(s32)`/`(s32 *)` round-trip cast, same carrier idiom as fixes
 *    4-12 applied to a POINTER instead of an int. A dedicated `struct
 *    Ent *`-typed carrier (tried first, casting `pa` to `struct Ent *`
 *    and back) has NO effect; the round-trip must go through `k2`
 *    specifically. Fixes the LAST remaining register-color echo outside
 *    the one true hunk: masked diff drops 12 -> 10 (unmatched lines
 *    unchanged at 214, since this hunk's lines were already counted
 *    within the raw diff).
 * 14. The SECOND loop half's edge-0 guard (mirror of fix pattern used
 *    elsewhere): `(e = v2 - 0x1C00) >= 0` -> `(d1 = (e = v2 - 0x1C00)) >= 0`,
 *    routing the assignment through the already-live `d1` local (found by
 *    the permuter, isolated via a pycparser-reprint diff against the
 *    pre-candidate source to strip cosmetic brace/formatting noise).
 *    Verified safe: `d1` is unconditionally overwritten at
 *    `d1 = gUnk_0801CD08[ang];` before its next read, so this write is
 *    never read stale on any control-flow path. Stays at masked diff 10
 *    (same single true hunk per `fulldiff.py`); cuts unmatched lines
 *    214 -> 202.
 * 15. The FIRST half's edge-2 check drops its `d1 = k2 + 0x1C00;`
 *    carrier too (same drop as fix 10/11 applied to the SECOND half):
 *    `d1 = k2 + 0x1C00; if ((u32)d1 <= 0x3800)` ->
 *    `if ((u32)(k2 + 0x1C00) <= 0x3800)`. Safe for the same reason as
 *    fix 10/11: the immediately following edge-3 check unconditionally
 *    overwrites `d1` again before any read, so no stale-value path
 *    exists. Stays at masked diff 10; cuts unmatched lines 202 -> 198.
 *    The remaining `d1 = k2 + 0x1C00;` site (SECOND half's edge-3,
 *    using `lim3800`) still wants to keep its carrier -- not re-tried
 *    this round, consistent with fix 10's finding.
 * 16. The post-loop `hit2->unk55 == 0` gate's `gUnk_020021E0 == 0` term
 *    (in the big `&&`-chain deciding whether to call `sub_08001208`)
 *    routed through the otherwise-dead `k2` local: `k2 = gUnk_020021E0;
 *    if (k2 == 0 && ...)`. `k2` is not read anywhere else in the
 *    post-loop section (its last prior use is inside the loop, long
 *    done), so this is a fresh write with no stale-value path. Stays at
 *    masked diff 10 (same single true hunk); cuts unmatched lines
 *    198 -> 194.
 * 17. The SECOND half's edge-1 guard (the one directly adjacent to the
 *    true hunk) mirrors fix 14's shape: `(e = -0x1C00 - v1) >= 0` ->
 *    `(d1 = (e = -0x1C00 - v2)) >= 0`. `d1` is not read again until its
 *    next unconditional overwrite further down (same safety argument as
 *    fix 14). Does NOT fix the true hunk itself (still the identical
 *    single `ldr [sp,#20]` vs `[sp,#16]` substitution per `fulldiff.py`)
 *    but is a further genuine cleanup: masked diff stays 10, unmatched
 *    lines 194 -> 192.
 * 18. The FIRST half's edge-2 call routes its `e` shift-argument through
 *    the otherwise-dead `k1` local: `(e << 16) / w` ->
 *    `k1 = e; ... (k1 << 16) / w`. `k1`'s last prior use is well before
 *    this point (the pool-load matrix computation) and its next write is
 *    the following iteration's matrix computation, so this is a fresh,
 *    non-conflicting write. Stays at masked diff 10 (same single true
 *    hunk); cuts unmatched lines 192 -> 188.
 * 19. The `lim3800` local (see key discovery #5) drops its assignment
 *    and use entirely: `lim3800 = 0x3800;` is removed, and the SECOND
 *    half's edge-3 check reverts to the plain literal
 *    `if ((u32)d1 <= 0x3800)`. The `s32 lim3800;` *declaration* is kept
 *    (unused) to preserve its slot in agbcc's declaration-order register
 *    allocation. Semantically trivial (dead variable, equal literal);
 *    stays at masked diff 10 (same single true hunk); cuts unmatched
 *    lines 188 -> 178.
 * 20. Found via a parallel Codex agent session working the same permuter
 *    output (found independently of this session; verified here before
 *    adopting). The SECOND half's edge-1 guard changes from
 *    `(d1 = (e = -0x1C00 - v1)) >= 0` to
 *    `(d1 = (e = -0x1C00 - v2)) >= 0`, while the body keeps
 *    `edgeq += v1;` unchanged -- an asymmetric guard-uses-v2/body-uses-v1
 *    split. This is NOT a standalone regression of the old "v2 grows the
 *    function by 4 bytes" finding: that test never paired the guard
 *    change with the accompanying edge-2 change below, and in isolation
 *    it still regresses. The pairing matters. Notably, the FIRST half's
 *    own edge-1 (line ~482) already has this exact shape (guard reads
 *    `v2`, body reads `v1`) -- so this brings the second half in line
 *    with a pattern the first half needed all along, which is likely why
 *    it works. Combined with: the SECOND half's edge-2 call wraps in
 *    braces and routes its shift argument through a new `s32 fraction;`
 *    local: `fraction = e << 16; sub_0800D64C(..., fraction / w);` in
 *    place of `(e << 16) / w`. Together these two changes drop the
 *    masked diff from 10 to **8** and change the true-hunk shape: where
 *    `fulldiff.py` used to show one clean `REPLACE` block, it now shows
 *    8 scattered single/double-instruction delete+insert pairs (net 4
 *    extra each way, same as before) -- meaning several nearby
 *    instructions reordered as a side effect, not that the diff grew.
 *    Cuts unmatched lines 178 -> 162 in the raw metric even though the
 *    masked metric is the one that actually improved.
 *
 * CORRECTNESS CAUTION (second instance this pass): a permuter candidate
 * building on fix 20 reached masked diff **6** by introducing a new
 * `u32 bound3800;` local (declared between `u` and `w`), assigned
 * `bound3800 = 0x3800;` **only inside the FIRST half's edge-3 `if`
 * block**, then read at TWO sites: that same edge-3 check (safe, same
 * block) AND the SECOND half's edge-2 check (`<= bound3800` in place of
 * `<= 0x3800`) -- a completely different, later conditional block, with
 * no intervening unconditional write. If the first half's edge-3 guard
 * (`w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0`) is false for a given
 * loop iteration, `bound3800` is read at the second half's edge-2 holding
 * a stale value from a previous iteration (or garbage on the first
 * iteration) instead of `0x3800`. This is the same class of bug as the
 * 1440-candidate caution above: byte-improving, but a genuine dataflow
 * bug, not a legitimate fix. NOT adopted. Verified by hand-tracing every
 * write and read of the introduced variable across the whole loop body
 * -- do not re-adopt this shape unless `bound3800` (or equivalent) is
 * given an unconditional write before every read that can reach it.
 * 21. A second genuine no-op self-store (same idiom as the
 *    `a1->unk175 = a1->unk175;` one, key discovery #5): after the FIRST
 *    half's edge-3 call, unconditionally (whenever the outer edge-3
 *    guard is true, regardless of the inner bound check):
 *    `gUnk_083FDA2C[(*cc).d].f1 = gUnk_083FDA2C[(*cc).d].f1;`. A genuine
 *    memory read-then-write of an already-read struct field, not a
 *    pins-style trick. Stays at masked diff 8 (`fulldiff.py` still shows
 *    the same 8 scattered delete/insert pairs, net 4 extra each way);
 *    cuts unmatched lines 162 -> 156.
 * 22. Fix 18's `k1 = e;` carrier (FIRST half's edge-2) extended one more
 *    hop: `k1 = e; ... (k1 << 16) / w` -> `k1 = e; d1 = k1; ... (d1 <<
 *    16) / w`. `d1` is unconditionally overwritten again at the very
 *    next block (edge-3's `d1 = k2 + 0x1C00;`), so no stale-value path.
 *    Stays at masked diff 8; cuts unmatched lines 156 -> 152.
 * 23. A THIRD genuine no-op self-store (same idiom as fix 21 and key
 *    discovery #5's original): `a1->unk175 = a1->unk175;` inserted
 *    pre-loop, right after `cc = &gUnk_0202CC90;` and before the
 *    `k2 = (s32)pa;` / `sub_0800D5D4(a1, ...)` pair from fix 13. Stays
 *    at masked diff 8 (same 8 scattered delete/insert pairs); cuts
 *    unmatched lines 152 -> 146.
 * 24. `dz -= other->unk08;` (in the pre-loop `dx`/`dz` distance setup)
 *    routed through the otherwise-dead `edgeq` local: `edgeq =
 *    other->unk08; dz -= edgeq;`. `edgeq` is not read again until its
 *    next legitimate write deep inside the edge checks, so no
 *    stale-value path. Stays at masked diff 8; cuts unmatched lines
 *    146 -> 144.
 * 25. Two changes together: the SECOND half's edge-1 guard (the one
 *    directly adjacent to the true hunk) has its comparison operands
 *    reordered, `u > 0` -> `0 < u` (semantically identical, but changes
 *    which operand the compiler loads first); and in the post-loop
 *    section, `w = (s32)(*cc).c;` routes through the otherwise-dead
 *    `d0` local: `d0 = (s32)(*cc).c; w = d0;` (`d0` is unconditionally
 *    overwritten again two statements later, so no stale-value path).
 *    Stays at masked diff 8; cuts unmatched lines 144 -> 142.
 *
 * NEXT STEP: the true diff is no longer one clean substitution (that
 * was true only up through fix 19). Since fix 20, `fulldiff.py` shows
 * 8 scattered single/double-instruction delete+insert pairs (net 4
 * extra each way). Their exact locations and target-vs-ours context
 * (re-derived by rerunning the detailed opcode-level diff after fix 25):
 *
 * 1. Pre-loop `sub_0800D5D4(a1, pa);` call: target loads `pa`'s address
 *    into r7 first, then copies r7->r1 for the call (`adds r1,r7,#0`);
 *    ours loads directly into r1 with no r7 intermediary. This is the
 *    single most promising lead: it suggests the target keeps `pa`
 *    resident in a callee-saved hard register (r7) across the whole
 *    function, while our allocator does not. RTL-traced at `-dl`
 *    (local-alloc): confirmed our RTL for this call is a direct
 *    pseudo-to-r1 load with no r7-pinned pseudo involved at all, i.e.
 *    the difference originates upstream of local-alloc, in how `pa`'s
 *    pseudo register gets its allocation priority. Tried reverting fix
 *    13's `k2 = (s32)pa; sub_0800D5D4(a1,(s32*)k2);` round-trip back to
 *    a plain `sub_0800D5D4(a1, pa);`: regresses masked diff 8 -> 10, so
 *    fix 13's shape is still net-necessary even though it doesn't
 *    produce this specific r7 pattern. NOT solved.
 * 2. Index ~264 (SECOND half, edge-1 area): ours has one extra
 *    `adds r6,r4,#0`-style register copy target doesn't have. Not
 *    investigated in RTL this round; likely related to #1's r7/pa
 *    lifetime story since it's in the same neighborhood.
 * 3-4. Indices ~505/511 (post-loop hit setup, building a >4-arg
 *    `sub_0800D64C`-shaped stack-argument call): a `lsls r0,r4,#16`
 *    (the `e << 16` shift for one call's last argument) is scheduled
 *    one position earlier in ours than in target, which instead
 *    schedules it right before the call, interleaved with other stack
 *    stores (`str r1,[sp,#8]` then the shift then `bl`). Consistent
 *    with agbcc's right-to-left argument evaluation; not tried this
 *    round because the source line producing this specific call could
 *    not be conclusively identified.
 * 5-6. Indices ~598/617 (post-loop `gUnk_083FDA2C[...]`-style array
 *    field reads): ours reloads a `[pc]`-relative pool address at each
 *    read; target computes the base address once and reuses it via a
 *    register offset from an already-loaded base. This is the same
 *    "address kept live vs. reloaded from pool" pattern as #1, just for
 *    a different pointer. Not yet tried.
 * 7. Indices ~683-684 (the `d1 = (s32)&((struct Ent*)u)->unk55;`
 *    address computation): target computes the address into r0 first,
 *    then copies r0->r6 for long-term holding (since `d1` must survive
 *    across every subsequent call in the post-loop block, through to
 *    `*(u8*)d1 = v55;` at the very end); ours computes directly into r6
 *    with no r0 intermediary. Tried routing the computation through
 *    `k0`/`k1`/`k2`/`k3`/`edgeq` as a carrier before assigning to `d1`:
 *    every variant is a pure no-op (identical masked-diff and
 *    unmatched-line counts). NOT solved.
 * 8. Indices ~693-694 (the `sub_0800BA34(v55, v55, -6, 0, v55, v55,
 *    0x400);` call, gated by `if (v55 == 0)`): target loads three
 *    separate zero immediates (`movs r0,#0`, `movs r1,#0`, `movs
 *    r3,#0` for arguments a, b, d -- all provably 0 inside this branch);
 *    ours only emits two (`movs r0,#0`, `movs r3,#0`), missing the `r1`
 *    one. RTL-traced across all four dump stages: at `-dl` (local-alloc)
 *    our RTL already has all three separate `(set (reg N) (const_int
 *    0))` insns with `REG_EQUAL` notes. At `-dg` (global-alloc) two of
 *    them get replaced with `NOTE_INSN_DELETED` -- specifically the `r1
 *    = 0` insn and an insn related to the `-6` constant -- as dead-code
 *    elimination, apparently because hard register r0 gets reused
 *    sequentially for three unrelated transient values right before the
 *    call (`v55` for the stack-passed args, then `1024` for another
 *    stack arg, then finally `0` for register arg `a`), and something
 *    in that reuse chain makes global-alloc conclude r1's separate zero
 *    load is redundant. This call site is extremely fragile: every
 *    variant tried (`volatile` read on one `v55` use, a distinct local
 *    for the `b` argument, carrier locals for the `-6` or `0x400`
 *    literals) regresses catastrophically (masked diff 8 -> 34-57,
 *    byte count grows by 12-24). NOT solved; do not re-try these exact
 *    shapes without a new idea for why r0's three-way reuse specifically
 *    triggers this elimination.
 *
 * None of these 8 are the same root cause as each other in any way
 * that's been proven; #1/#2/#5/#6 share an "address kept live in a
 * register vs. reloaded from a literal pool" flavor, #7 is a narrower
 * version of the same idea that didn't respond to carrier routing, and
 * #8 is an unrelated dead-code-elimination quirk. The permuter (see
 * fixes 14-25) is what found every fix that DID land; manual RTL tracing
 * this round explained several of the remaining hunks precisely but
 * did not yield a working fix for any of them.
 *
 * FULL MANUAL SWEEP of all 8 hunks (source-level options now genuinely
 * exhausted for each, not just theorized):
 * - #1 (`pa`/r7): reverting fix 13 back to a plain `sub_0800D5D4(a1,
 *   pa);` regresses masked diff 8 -> 10. NOT fixable this way.
 * - #2 (index ~264, extra register copy near the FIRST half's edge-2
 *   bound check): confirmed this is fix 18/22's `k1 = e; d1 = k1;`
 *   pair. Tried moving both statements inside the `if ((u32)(k2 +
 *   0x1C00) <= 0x3800)` block (masked diff unchanged at 8, but raw
 *   unmatched exploded 142 -> 530 from unrelated recoloring elsewhere);
 *   tried moving only `d1 = k1;` inside (regresses to 12 masked diff,
 *   byte count wrong at 2010); tried swapping `k1`/`d1` order relative
 *   to `k2` (no effect, ties baseline). NOT fixable this way.
 * - #3-4 (indices ~505/511, the same edge-2 call's stack-argument
 *   setup): confirmed the `(k1 << 16)` shift computes one position too
 *   early relative to target, which defers it to immediately before
 *   the division call. Tried reverting fix 22's `d1` hop (regresses
 *   146); tried `k1`/`d1` before `k2` (no effect); tried routing the
 *   shift through `edgeq` instead (regresses badly, 23 masked diff);
 *   tried dropping the carrier entirely and inlining `(e << 16)`
 *   (masked diff unchanged, raw unmatched exploded to 530, same
 *   pattern as #2). NOT fixable this way.
 * - #5-6 (indices ~598/617, the post-loop `ccd = (*cc).d; k1 =
 *   (&gUnk_083FDA2C[ccd])->f0; k0 = gUnk_083FDA2C[(*cc).d].f1;`
 *   sequence): confirmed `[r4, #9]` in target's asm is `cc->d` read
 *   from a `cc` that's already resident in r4 -- the exact same
 *   "`cc` not kept in a stable register" story as `pa` in #1. Tried
 *   making `k0`'s line use `ccd` instead of `(*cc).d` directly (no
 *   effect, re-confirming fix 3's much earlier finding under the
 *   current draft state); tried `cc->d` arrow style uniformly for both
 *   lines (no effect); tried adding an extra harmless `cc`-field read
 *   right after `cc = &gUnk_0202CC90;` to raise its allocation
 *   priority (no effect); tried the same for `pa` (no effect). NOT
 *   fixable this way -- register-allocation priority in this compiler
 *   is a whole-function computation that a single extra local
 *   reference does not visibly perturb.
 * - #7 (`d1 = (s32)&((struct Ent*)u)->unk55;`): all 5 carrier variants
 *   (`k0`/`k1`/`k2`/`k3`/`edgeq`) are pure no-ops. NOT fixable this way.
 * - #8 (`sub_0800BA34` call): every variant tried regresses
 *   catastrophically (masked diff 8 -> 34-57, byte count grows). NOT
 *   fixable this way; this call site is unusually fragile to any touch.
 *
 * CONCLUSION: `pa` and `cc` not being held in stable callee-saved
 * registers across the whole function (hunks #1, #2, #3-4, #5-6, and
 * likely a contributing factor in #7) is a real, well-understood,
 * *global* register-allocation-priority difference from the target's
 * compile. It has resisted every local C-shape lever available:
 * carrier splits, self-stores, statement reordering, arrow-vs-dot
 * access style, and raising reference counts. It is not a function of
 * any one statement's shape but of the compiler's whole-function
 * priority computation, which is not steerable from individual call
 * sites without either (a) a coordinated rewrite touching every use of
 * `pa`/`cc` simultaneously in a way not yet found, or (b) accepting
 * this as the final structural difference between the two compiles.
 *
 * Also tried, as a direct test of the r7 theory: `register s32 *pa
 * asm("r7");` and, separately, `register struct Unk0802CC90 *cc
 * asm("r7");` (neither variable had been pin-tested before -- the
 * general pin note above covers a different variable list). Both
 * regress catastrophically (masked diff 8 -> 527 and 8 -> 550
 * respectively), consistent with every other pin ever tried on this
 * function: forcing a specific hard register onto one pseudo starves
 * every other live range that the global allocator would otherwise
 * have balanced against it, regardless of which register or which
 * variable. This closes off pins as an avenue entirely, including the
 * specific r7 hint from the disassembly.
 *
 * COMPILER MODIFICATION attempted and refuted: `global.c`'s
 * `allocno_compare` (the priority function driving global register
 * allocation order) was patched to boost priority for allocnos that
 * cross calls (`allocno_calls_crossed[v] != 0`), both proportionally
 * (`pri *= 1 + calls_crossed`) and as a flat 2x multiplier. Both
 * regressed the target function itself (masked diff 8 -> 373 and
 * 8 -> 18 respectively) before any whole-corpus regression test was
 * even needed. This refutes the specific theory that under-prioritizing
 * call-crossing pseudos is the mechanism; the compiler was rebuilt and
 * the original binary restored (MD5-verified identical) after each
 * test. Do not re-attempt this exact patch shape.
 *
 * FLAG SWEEP specific to this function (the corpus-wide 72-cell sweep
 * in `parked.md` covered nine other functions, not this one): all
 * 16 cells of `{old_agbcc, agbcc} x {-O1,-O2,-O3,-Os} x {interwork
 * on/off}` tested against this exact draft. Only `old_agbcc -O2
 * -mthumb-interwork` (already the Makefile's flags) produces the
 * correct 2006-byte length; every other cell gives the wrong size
 * outright (1998-2078 bytes). Confirms this function was built with
 * the same flags as the rest of the ROM.
 *
 * CODEBASE SEARCH for a sibling idiom: searched all of `src/*.c` for
 * functions with the same "pointer aliases a global before a loop,
 * survives calls inside the loop" shape. Found two functions using
 * `register T *p asm("rN")` successfully (`sub_0800BB58`,
 * `sub_0801177C`), but both pin a pointer whose *initial* value is
 * already cheap to obtain (a function parameter already in a register,
 * or a stack-local array's address) -- neither faces our case of a
 * pointer that must come from an expensive literal-pool load of a
 * global's address. `sub_0801177C`'s header comment explicitly
 * describes its technique as re-deriving the pointer fresh every loop
 * iteration rather than carrying it across calls, which only works
 * because re-deriving a stack address is nearly free; re-deriving `pa`/
 * `cc` from their globals would require the exact literal-pool reload
 * we are trying to avoid, so this idiom does not transfer. A directly
 * analogous *unpinned* function, `sub_0800AD80` (`p = gUnk_0202A550;`
 * surviving four calls per loop iteration, matched with zero register
 * tricks), confirms rather than refutes the priority theory: its loop
 * body is far simpler than ours, with much lower local register
 * pressure, so its long-lived pointer never has to compete with a dozen
 * short-lived edge-math temporaries the way `pa`/`cc` do here. Also
 * tried a genuinely different technique found in `sub_0800E200`
 * (forcing a value into a specific hard register for a narrow scope via
 * `register T x asm("rN") = value; __asm__ volatile ("" : : "r" (x));`,
 * rather than pinning the variable's storage class for its whole
 * lifetime) on the pre-loop `sub_0800D5D4(a1, pa)` call, forcing `pa`'s
 * value into r7 for just that call: regresses to masked diff 91, byte
 * count wrong (2030). NOT fixable this way either.
 *
 * Do not integrate or edit linker/asm fragments until `python3
 * scripts/match.py sub_0800D684` prints `MATCH (2006 bytes @
 * 0x0800d684)`. `src/sub_0800D684.c` is untracked; this file is the
 * keeper draft.
 */
#include "global.h"
#include "global.h"

struct Ent {
    s32 unk00;
    u8 pad04[4];
    s32 unk08;
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x2C - 0x18];
    s32 unk2C;
    u8 pad30[0x34 - 0x30];
    u16 unk34;
    u8 pad36[0x3E - 0x36];
    u8 unk3E;
    u8 pad3F;
    s16 unk40;
    u8 pad42[0x48 - 0x42];
    s32 unk48;
    u8 pad4C[0x55 - 0x4C];
    u8 unk55;
    u8 pad56[0x7C - 0x56];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x88 - 0x7E];
    s32 unk88;
    u8 pad8C[0xE8 - 0x8C];
    u16 *unkE8;
    u8 padEC[0x140 - 0xEC];
    s32 unk140;
    s32 unk144;
    s32 unk148;
    u8 pad14C[0x175 - 0x14C];
    u8 unk175;
    u8 pad176[0x18F - 0x176];
    u8 unk18F;
};

struct Unk0802CC90 {
    struct Ent *a;
    struct Ent *c;
    u8 b;
    u8 d;
    s32 g;
};

struct Pt2 {
    s32 f0;
    s32 f1;
};

extern u8 gUnk_02002090;
extern u8 gUnk_020020DC;
extern u8 gUnk_020020AC;
extern u8 gUnk_0202A550[][0x190];
extern s32 gUnk_0202CD24;
extern s32 gUnk_0202CCB0[];
extern s32 gUnk_0202CD30[];
extern struct Unk0802CC90 gUnk_0202CC90;
extern s16 gUnk_0801CD08[];
extern struct Pt2 gUnk_083FDA2C[];
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202A530;
extern u8 gUnk_020021E0;
extern u8 gUnk_020020E0;
extern u8 gUnk_0202EF00[];

void sub_0800D5D4(struct Ent *a, s32 *d);
void sub_0800D64C(struct Ent *a, s32 b, struct Ent *c, s32 d, struct Unk0802CC90 *e,
                  u8 *f, s32 g, s32 h);
void sub_0800BA34(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void sub_0800E708(s32 a, u8 b);
void sub_0800A2D4(struct Ent *a);
void sub_08001208(u16 idx);

#define v1 v[0]
#define v2 v[1]
#define v3 v[2]
#define v4 v[3]
#define m0 m[0]
#define m1 m[1]
#define q0 q[0]
#define q1 q[1]

u8 sub_0800D684(struct Ent *a1)
{
    u8 flag;
    struct Ent *base;
    u8 a1_175;
    s32 a2;
    u8 i;
    s32 m[2], q[2];
    u8 count;
    struct Ent *cursor;
    struct Ent *self;
    struct Ent *other;
    s32 v1hold;
    s32 d0;
    s32 d1;
    s32 k0, k1, k2, k3;
    s32 dx;
    s32 dz;
    s32 u;
    s32 w;
    s32 e;
    s32 edgeq;
    s32 v[4];
    s32 *pa, *pb;
    s32 lim3800;
    struct Unk0802CC90 *cc;
    register struct Unk0802CC90 *cp asm("r1");
    u8 ccd;
    register struct Unk0802CC90 *cp5 asm("r3");

    count = gUnk_02002090;
    if (gUnk_020020DC != 0)
        count = gUnk_020020AC;
    if (a1->unk7D != 0 && gUnk_020020DC != 0)
        return 0;
    a1_175 = a1->unk175;
    base = (struct Ent *)gUnk_0202A550;
    if (a1_175 != 0) {
        if (a1 == base)
            return 0;
        if (a1->unk18F == 0)
            return 0;
    }
    gUnk_0202CD24 = 0x200000;
    flag = 0;
    cursor = base;
    pa = gUnk_0202CCB0;
    pb = gUnk_0202CD30;
    cc = &gUnk_0202CC90;
    a1->unk175 = a1->unk175;
    k0 = (s32)pa;
    sub_0800D5D4(a1, (s32 *)k0);
    for (i = 0; i != count; i++, cursor = (struct Ent *)((u8 *)cursor + 0x190)) {
        if (cursor == a1)
            goto loop_continue;
        if (cursor->unk175 != 0) {
            if (cursor == (struct Ent *)gUnk_0202A550)
                goto loop_continue;
            if (cursor->unk18F == 0)
                goto loop_continue;
        }
        if (cursor->unk7D != 0 && gUnk_020020DC != 0)
            goto loop_continue;
        {
            self = a1;
            dx = self->unk00;
            other = cursor;
            dx -= other->unk00;
            d0 = self->unk08;
            dz = d0;
            edgeq = other->unk08;
            dz -= edgeq;
        }
        dz >>= 8;
        dx >>= 8;
        if (dx < 0)
            dx = -dx;
        if (dx > 0x6400)
            goto loop_continue;
        if (dz < 0)
            dz = -dz;
        if (dz > 0x6400)
            goto loop_continue;
        sub_0800D5D4(cursor, pb);
        d0 = gUnk_0202CCB0[4];
        d1 = pa[5];
        d0 -= pb[4];
        d1 -= pb[5];
        v1 = (v1hold = ((k1 = pb[1]) * d0 - (k0 = pb[0]) * d1) >> 8);
        v2 = (k0 * d0 + k1 * d1) >> 8;
        d0 = pa[6];
        d1 = pa[7];
        d0 -= pb[6];
        d1 -= pb[7];
        v3 = ((k3 = pb[3]) * d0 - (k2 = pb[2]) * d1) >> 8;
        v4 = (k2 * d0 + k3 * d1) >> 8;
        w = v3 - v1hold;
        u = v4 - v2;
        if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {
            edgeq = w * e / u;
            edgeq += v1hold;
            if ((u32)(edgeq + 0xF00) <= 0x1E00) {
                cp5 = &gUnk_0202CC90;
                sub_0800D64C(a1, a2, cursor, 0, cp5, &flag, -u, (e << 16) / -u);
            }
        }
        if (u > 0 && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {
            edgeq = w * e / u;
            k3 = edgeq + v1;
            if ((u32)(k3 + 0xF00) <= 0x1E00)
                sub_0800D64C(a1, a2, cursor, 1, cc, &flag, u, (e << 16) / u);
        }
        if (w > 0 && v3 >= -0xF00 && (d1 = (e = -0xF00 - v1)) >= 0) {
            edgeq = e * u / w;
            k2 = edgeq + v2;
            k1 = e;
            d1 = k1;
            if ((u32)(k2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, cc, &flag, w, (d1 << 16) / w);
        }
        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {
            edgeq = e * u / w;
            k2 = edgeq + v2;
            d1 = k2 + 0x1C00;
            if ((u32)d1 <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 3, cc, &flag, -w, (e << 16) / -w);
            d0 = gUnk_083FDA2C[(*cc).d].f1; gUnk_083FDA2C[(*cc).d].f1 = d0;
        }
        d0 = pb[4];
        d1 = pb[5];
        d0 -= pa[4];
        d1 -= pa[5];
        e = (v1 = ((k1 = pa[1]) * d0 - (k0 = pa[0]) * d1) >> 8);
        v1hold = e;
        v2 = (k0 * d0 + k1 * d1) >> 8;
        d0 = pb[6];
        d1 = pb[7];
        d0 -= pa[6];
        d1 -= pa[7];
        v3 = ((k3 = pa[3]) * d0 - (k2 = gUnk_0202CCB0[2]) * d1) >> 8;
        v4 = (k2 * d0 + k3 * d1) >> 8;
        w = v3 - v1hold;
        u = v4 - v2;
        if (u < 0 && v4 <= 0x1C00 && (d1 = (e = v2 - 0x1C00)) >= 0) {
            edgeq = w * e / u;
            edgeq += v1hold;
            if ((u32)(edgeq + 0xF00) <= 0x1E00)
                sub_0800D64C(cursor, a2, a1, 0, cc, &flag, -u, (e << 16) / -u);
        }
        if (0 < u && v4 >= -0x1C00 && (e = -0x1C00 - v2) >= 0) {
            edgeq = w * e / u;
            edgeq += v1;
            if ((u32)(edgeq + 0xF00) <= 0x1E00)
                sub_0800D64C(cursor, a2, a1, 1, cc, &flag, u, (e << 16) / u);
        }
        if (w > 0 && v3 >= -0xF00 && (e = -0xF00 - v1) >= 0) {
            edgeq = e * u / w;
            k0 = edgeq + v2;
            if ((u32)(k0 + 0x1C00) <= 0x3800)
                sub_0800D64C(cursor, a2, a1, 2, cc, &flag, w, (e << 16) / w);
        }
        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {
            edgeq = e * u / w;
            d1 = edgeq + v2;
            if ((u32)(d1 + 0x1C00) <= 0x3800) {
                cp = &gUnk_0202CC90;
                sub_0800D64C(cursor, a2, a1, 3, cp, &flag, -w, (e << 16) / -w);
            }
        }
a1->unk175 = a1->unk175;
loop_continue:;
    }
    if (flag != 0) {
    s32 ang;
    u8 v55;
    register s32 k5 asm("r0");
    u8 ve;
    register struct Ent *b5 asm("r2");
    s32 kb;
    s32 sd;
    struct Ent *hit2;

    struct Ent *u0;
    register struct Unk0802CC90 *cc2 asm("r4");
    cc2 = cc;
    u0 = (*cc).a;
    u = (s32)u0;
    w = (s32)(*cc2).c;
    ang = ((struct Ent *)w)->unk34 >> 8;
    ccd = (*cc).d;
    d1 = gUnk_0801CD08[ang];
    d0 = gUnk_0801CD08[ang + 0x40];
    k1 = gUnk_083FDA2C[ccd].f0;
    k0 = gUnk_083FDA2C[(*cc).d].f1;
    m0 = (k1 * d0 - k0 * d1) >> 4;
    m1 = (k1 * d1 + k0 * d0) >> 4;
    d0 = -(*cc2).g;
    q0 = -(d0 * m0) / 256;
    q1 = -(d0 * m1) / 256;
    ((struct Ent *)u)->unk0C += q0;
    ((struct Ent *)u)->unk14 += q1;
    ((struct Ent *)u)->unk140 = 0;
    ((struct Ent *)u)->unk144 = 0;
    ((struct Ent *)u)->unk148 = 0;
    ((struct Ent *)w)->unk0C -= q0;
    ((struct Ent *)w)->unk14 -= q1;
    ((struct Ent *)w)->unk140 = 0;
    ((struct Ent *)w)->unk144 = 0;
    ((struct Ent *)w)->unk148 = 0;
    d0 *= 1000;
    k5 = (s32)&((struct Ent *)u)->unk55;
    v55 = *(u8 *)k5;
    d1 = k5;
    if (v55 == 0)
        sub_0800BA34(v55, v55, -6, 0, v55, v55, 0x400);
    if ((u8)(((struct Ent *)u)->unk7C - 5) > 2) {
        if (gUnk_0202EEB0 != 0)
            ((struct Ent *)u)->unk88 -= d0 >> 12;
        if (((struct Ent *)u)->unk88 > 40000) {
            sd = -((struct Ent *)u)->unk2C >> 12;
            if (sd < 0)
                sd = 0;
            if (sd > 0x32)
                sub_0800E708((s32)((u8 *)((struct Ent *)u) - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> 4,
                             gUnk_0202A530 % 3);
            else
                sub_0800E708((s32)((u8 *)((struct Ent *)u) - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> 4, 4);
        }
        gUnk_0202A530++;
    }
    sub_0800A2D4(((struct Ent *)u));
    hit2 = (struct Ent *)w;
    ((struct Ent *)u)->unk48 = ((struct Ent *)u)->unk2C;
    if (((struct Ent *)u)->unk2C > 0)
        ((struct Ent *)u)->unk48 = 0;
    ((struct Ent *)u)->unk40 = (((struct Ent *)u)->unk48 << 8) / -((struct Ent *)u)->unkE8[((struct Ent *)u)->unk3E];
    if ((u8)(((struct Ent *)w)->unk7C - 5) > 2) {
        if (gUnk_0202EEB0 != 0)
            do
                hit2->unk88 -= d0 >> 14;
            while (0);
        if (hit2->unk88 > 40000) {
            sd = -hit2->unk2C >> 12;
            if (sd < 0)
                sd = 0;
            k3 = 4;
            if (sd > 0x32)
                sub_0800E708((s32)((u8 *)hit2 - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> k3,
                             gUnk_0202A530 % 3);
            else
                sub_0800E708((s32)((u8 *)hit2 - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> k3, 4);
        }
        gUnk_0202A530++;
    }
    sub_0800A2D4(hit2);
    hit2->unk48 = hit2->unk2C;
    if (hit2->unk2C > 0)
        hit2->unk48 = 0;
    hit2->unk40 = (hit2->unk48 << 8) / -hit2->unkE8[hit2->unk3E];
    b5 = (struct Ent *)gUnk_0202A550;
    if (((struct Ent *)u) == b5 || hit2 == b5
        || gUnk_020020DC != 0) {
        kb = gUnk_020021E0;
        if (kb == 0 && gUnk_020020E0 == 0 && gUnk_0202EF00[3] != 0
            && (a1 == b5 || gUnk_020020DC != 0)
            && *(u8 *)d1 == 0 && hit2->unk55 == 0)
            sub_08001208(0x12);
    }
    ve = 0x10;
    *(u8 *)d1 = ve;
    hit2->unk55 = ve;
    return 1;
    }
    return 0;
}
