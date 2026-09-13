/* sub_0800C2CC -- quarantined draft. 140/140 bytes, instruction stream,
 * branch layout, pool order (0xFFFF, gUnk_0202CC24, gUnk_0202CC38) and
 * prologue (a->ip, b->r8) all match. Remaining diff is ONE allocation web
 * in the product block 0x0800C2E0-0x0800C2FA plus its downstream renames:
 *   1. target: v (the accumulated sum, global pseudo) homed r1; ours r2.
 *      Consequence: ours needs a reload copy `adds r2, r1, #0` before the
 *      first muls (target `muls r1, r6` directly); ours' (b-y0) lands r1
 *      (target r2), so the SECOND mult's copy reads the wrong register.
 *   2. dx/dy swap: target dx=r6 dy=r7, ours dx=r7 dy=r6 (global-alloc
 *      pass-0 prefers r7; first-processed allocno dx gets it).
 * Structure solved (keep when revisiting):
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
 * the first product (still gets r2: ta's qty range covers its own death
 * insn, so r1 is blocked for anything born at the mult); ta assigned
 * before q (breaks load order); q declared last/first; +=/*= forms;
 * e[2]*v operand swap; v declared last; all four /tmp variants in
 * c1/c2/c3. The missing lever: something must block r1 over the (b-y0)
 * birth window [14,16] so (b-y0) takes r2 and leave r1 for v, AND the
 * global pass must process dy before dx (or block r7 for dx). Neither
 * reached from any statement shape tried; block-alloc qty data is in
 * /tmp/decomp/t4.c.lreg (qty spans include the death insn).
 */
#include "global.h"

extern u32 gUnk_0202CC24[];
extern u32 gUnk_0202CC38[];

u32 sub_0800C2CC(s32 a, s32 b, u16 *p, u8 *e)
{
    u16 *q;
    s32 x0;
    s32 y0;
    s32 dx;
    s32 dy;
    s32 v;
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
