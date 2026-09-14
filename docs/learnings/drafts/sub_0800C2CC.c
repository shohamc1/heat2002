/* sub_0800C2CC -- quarantined draft (wave-5a, fresh-verified 2026-09-14:
 * rm .o; make .o; match.py = MISMATCH, 30 diff lines, 140/140 bytes).
 * Instruction stream, branch layout, pool order (0xFFFF, gUnk_0202CC24,
 * gUnk_0202CC38), prologue (a->ip, b->r8) and the product-block SHAPE all
 * match; with dx pinned asm("r6") and v pinned asm("r1") the earlier
 * reload-copy and v-homing problems are FIXED (first muls is now direct
 * `muls r1, r7`). Remaining diff = ONE register-allocation web, pure
 * register renames, no structural difference:
 *   - target homes x0=r4, y0=r5; ours x0=r6, y0=r4.
 *   - target homes the two product-difference pseudos (x1-x0, y1-y0) in
 *     r6/r7, ours in r7/r5 (follows from the x0/y0 homes).
 *   - tail px/py: target px=r3, py=r2 (with dx copy r6, dy copy r7);
 *     ours px=r2, py=r1 (dx copy r7, dy copy r5). Downstream a-px / b-py
 *     >>2 squares follow the same rename.
 * Unpinning dx/v reverts to the 51-diff-line state (v web + reload
 * copies). Structure solved (keep when revisiting):
 *   - x0/y0 statements share the e[0] address (CSE merges to [base],[base,#2]).
 *   - q must be a statement BEFORE v, spelled with the offset as op0:
 *       q = (u16 *)(4 * e[1] + (u32)p);
 *     giving ldrb/lsls#2/adds r0,r0,r2 (temp-first plus). `&p[2*e[1]]` and
 *     `p + 2*e[1]` both give the p-first plus (adds r2,r2,r0) -- wrong.
 *   - products as two statements so the second's mult takes a NULL target
 *     (keeps its reload copy `adds r0, r2, #0`, matching the ROM):
 *       v = (a - x0) * (*q - x0); v = v + (b - y0) * (q[1] - y0);
 *     a single sum-expression moves the copy to the FIRST mult.
 *   - the interleaving (q-addr, a-x0, x1-load, dx, muls) comes from the q
 *     statement + left-operand-first mult expansion; do not load x1/y1 as
 *     statements.
 *   - `v = v * e[2];` as its own statement (e[2] load after the sum).
 *   - clamp: `if (v < 0) v = 0; if (v > 0xFFFF) v = 0xFFFF;` (pool 0xFFFF).
 *   - dx/dy re-statements after the clamp CSE onto the product pseudos.
 *   - tail: px=x0+((dx*v)>>16), py=y0+((dy*v)>>16), stores, px=(a-px)>>2,
 *     py=(b-py)>>2, return px*px+py*py -- all match modulo reg names.
 * Swept without flipping the web: ta/tb user vars; t1 block-local temp for
 * the first product; ta assigned before q (breaks load order); q declared
 * last/first; +=/*= forms; e[2]*v operand swap; v declared last; pinning
 * BOTH dx and dy; pinning x0/y0 (moves the whole allocation). The missing
 * lever: get global-alloc to home x0=r4/y0=r5 while keeping dx=r6/v=r1
 * pins. Block-alloc qty data is in /tmp/decomp/t4.c.lreg from the
 * earlier session (qty spans include the death insn).
 */
#include "global.h"

extern u32 gUnk_0202CC24[];
extern u32 gUnk_0202CC38[];

u32 sub_0800C2CC(s32 a, s32 b, u16 *p, u8 *e)
{
    u16 *q;
    s32 x0;
    s32 y0;
    register s32 dx asm("r6");
    s32 dy;
    register s32 v asm("r1");
    s32 px;
    s32 py;

    x0 = p[2 * e[0]];
    y0 = p[2 * e[0] + 1];
    q = (u16 *)(4 * e[1] + (u32)p);
    v = (a - x0) * (*q - x0);
    v = v + (b - y0) * (q[1] - y0);
    v = v * e[2];
    if (v < 0)
        v = 0;
    if (v > 0xFFFF)
        v = 0xFFFF;
    dx = *q - x0;
    dy = q[1] - y0;
    px = x0 + ((dx * v) >> 16);
    py = y0 + ((dy * v) >> 16);
    gUnk_0202CC24[0] = px;
    gUnk_0202CC38[0] = py;
    px = (a - px) >> 2;
    py = (b - py) >> 2;
    return px * px + py * py;
}
