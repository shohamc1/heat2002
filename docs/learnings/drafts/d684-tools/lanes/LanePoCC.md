# Lane LanePoCC — post-loop `cc` handling via access-spelling / alias families

Baseline copied to /tmp/LanePoCC/base.c; never touched the repo. 1842 candidates scored.

| rank | variant | hunks | sdiff | size | head (hunks/sdiff) | tail (hunks/sdiff) |
|------|---------|-------|-------|------|--------------------|--------------------|
| 1 (best = unchanged baseline) | base.c | 2 | 627 | 2010 | 0/337 | 2/290 |
| 2 | leads/lead_Aglobal_a.c (`u0 = gUnk_0202CC90.a;`) | 11 | 2007 | **2006** | 5/1173 | 6/834 |
| 3 | leads/lead_ACglobal_ac.c (`u0`/`d1` reads direct-global) | 9 | 1786 | 2002 | 5/1171 | 4/615 |

Nothing beat the baseline. Min over all 1842 candidates: **hunks 2, sdiff 627** — no unadopted improvement; adopted edit set is EMPTY.

Families searched (all scored with filediff + d684tool `check`, split head/tail attribution in parts.py):
1. **Direct-global reads**: 4 tail `(*cc)` reads × 15 non-empty subsets × 5 A-spellings × 5 C-spellings × 2 carrier/no-carrier × 3 D × 2 K × 3 G spellings (~1350). Only `A`/`C` conversions move anything; `D`/`K` are exact no-ops.
2. **Alias pointer** `cp` (block-scope, outer-scope, `=cc`, `=&gUnk_0202CC90`, cast round-trip, decl-init, pre-loop/loop-end/tail-top assignment): agbcc value-numbers `cp` back to `cc`, byte-identical asm; `= &gUnk_0202CC90` collapses to the direct-global form.
3. **Interleaving** (400+ valid topological orders of the 11 tail statements incl. sin loads, `q0/q1`, `u0`/`w` carriers): every reorder regressed ≥ 3 hunks / 3139 sdiff — the scheduler already produces the target order.
4. **Carrying `&gUnk_0202CC90` across the block boundary**: as in 2, folded; outer-scope declaration added to the decl block regressed 16–21 hunks.
5. Byte-typed alias `u8 *bp` with explicit-offset typed loads (`*(struct Ent**)bp`, `*(s32*)(bp+12)`): folded identically.

Equivalence audit (only lever with real semantic content is #1): `cc` is assigned once (line 739) and never rebound, and `gUnk_0202CC90` is read-only in this file (its only `.` access, line 878, is a read), so `(*cc).x ≡ gUnk_0202CC90.x` at all four tail sites; no lever writes a variable another lever reads.

**Learning:** the two tail hunks are a *rematerialisation* artefact, not a spelling/liveness one. Both the ROM and our draft load `&gUnk_0202CC90` from the literal pool once at the tail head (target `ldr r4,[pc]` @800db42, ours `ldr r6,[pc]` @800db42) and reuse it for the `->a`/`->c` reads; ours then re-loads the pool for `->d` and `->g` because the address pseudo is constant-equivalent (`reg_equiv_constant`) and its chosen register r6 is clobbered by the sin-table `ldrsh r6`. r4 is *free* in our tail until index 646, so this is not register pressure — it is the allocator declining to give the constant-equivalent pseudo a stable register, exactly the whole-function-priority story the draft header documents for `pa`/`cc`. The one lever that removes both remats is spelling the `->a` read (and optionally `->c`) as a direct global read: that gives size 2006 (target size) and no remats, but re-allocates the whole function (5 structural head hunks) and nets worse (11 hunks / 2007). So the hunk pair and the global `cc`-vs-`global` re-allocation are coupled: fixing the tail *requires* paying the head, which is why every tail-local lever is neutral and every global-read lever overshoots.