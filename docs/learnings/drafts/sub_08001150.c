/* sub_08001150 — SOLVED 2026-09-15 (permutation campaign, agents B/C):
 * MATCH (32 bytes). Canonical source in src/sub_08001150.c; this file kept
 * for the learning record.
 *
 * THE FIX: append `*(u32 *)(r2 + 0x34) = t;` as the last statement of the
 * if-body. The store is dead-store-eliminated (t is the value just loaded
 * from that address; zero extra bytes) but its USE crosses the basic-block
 * boundary, which moves the tag pseudo from local-alloc into global-alloc —
 * exactly the "tag pseudo being global" route predicted below, yielding
 * v->r1, tag->r3, ptr->r2. The claim that neither route was "constructible
 * without extra instructions" was wrong: the eliminated write-back is the
 * construct. See parked.md "Resolved 2026-09-15: sub_08001150".
 *
 * Negative results from the same campaign (~200 variants, 5 agents):
 * literal-valued locals (bcfef4c axis) reached diff 9 but never 0; operand
 * order/spelling at every address site is fully inelastic here (all fold
 * identical); register asm() pins on r3 (or r1+r2) also match but are not
 * needed.
 *
 * sub_08001150 (32 bytes @ 0x08001150) — MISMATCH after ~30 source variants
 * (20 in the previous pass, ~10 more 2026-09-13 including the K&R and
 * struct-param shapes). Remaining diff is ALWAYS the same 4-instruction
 * register swap, in every shape tried:
 *   target: lsrs r1, r1, #16 / ldr r3, [r2, #0x34] / cmp r3, r0 / strh r1
 *   ours:   lsrs r3, r1, #16 / ldr r1, [r2, #0x34] / cmp r1, r0 / strh r3
 * i.e. the narrowed u16 (global allocno, preference r1 via set_preference
 * through reg_renumber of the lsls temp) must get r1, and the block-local
 * tag quantity must take r3. local-alloc's find_free_reg scans r0,r1,r2,..:
 * in BB0 the tag qty's window [2*ldrtag .. 2*cmp+1] has r0 blocked by the
 * pool-const qty (windows overlap), but r1 and r2 are FREE in that window:
 * the lsls temp qty is [2*lsls, 2*lsrs) and the param-copy pseudo is a
 * global allocno (pseudos are masked out of regs_live_at during
 * local-alloc). post_mark_life marks [birth, death) so both ranges end
 * exactly at the tag qty's birth. Therefore the tag qty ALWAYS takes r1,
 * which forces v to r3 (global conflict with the local qty in r1).
 * Mechanism traced through tools/agbcc/gcc/local-alloc.c (block_alloc,
 * find_free_reg, post_mark_life) and global.c (set_preference,
 * expand_preferences, find_reg); the walk order (deaths before stores in
 * global_conflicts) confirms v never conflicts the lsls temp itself.
 * What would flip it: a fourth BB0 qty, or a hard reg, live in r1 or r2
 * during the tag window; or the tag pseudo being global (then global-alloc
 * order gives v->r1, tag->r3, ptr->r2 = target). Neither is constructible
 * without extra instructions: any second use of the pointer/tag/const
 * emits code, dead stores survive to asm (verified: E10-style dead init
 * survives), and auto-increment on the tag load would emit ldm/writeback.
 * Tried this pass: u16 second param (assign_parms in-place conversion),
 * K&R definition (caller sub_080013A0 uses unprototyped decl + (u16) cast),
 * struct-pointer param with fields, volatile tag, early-return form,
 * stores-via-param + local copy for the load, t local decl order variants,
 * fused compare (no t local), const local. All produce the identical diff.
 * Previous pass swept: u16/u32/s16 params, (void*) param, v/t/c/r2 locals
 * in all declaration+assignment orders, casts at use vs local copies,
 * direct global compare vs tag local, if/return vs if/body, volatile
 * stores, struct-field access, store order swap.
 */
#include "global.h"

void sub_08001150(u32 r0, u16 v)
{
    u32 r2 = r0;
    u32 t = *(u32 *)(r2 + 0x34);
    u32 c = 0x80 << 1;

    if (t == 0x68736D53)
    {
        *(u16 *)(r2 + 0x26) = v;
        *(u16 *)(r2 + 0x24) = v;
        *(u16 *)(r2 + 0x28) = c;
    }
}
