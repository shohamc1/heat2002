/*
 * sub_0800C2CC -- QUARANTINED (wave 6, 2026-09-14; fresh-verified v1 state:
 * rm .o; make .o; match.py = MISMATCH, 140/140 bytes, 30 diff lines).
 * WAVE-6 ADDITIONS (all fresh-verified, all worse than v1's 30 lines):
 *   - pins x0=r4/y0=r5: homes go right BUT the locals break: q-addr homed
 *     r6, *q value copied to a high reg, first mult in-place
 *     (`subs r0,r0,r4; muls r1,r0`), second mult operands swap
 *     (`muls r0,r2`), a/b swap to r8/r9. Pinned callee-saved vars are
 *     blocked from their first set - early pins starve the block-0 locals.
 *   - pins a=ip/b=r8 via copy-locals (`register s32 a asm("ip") = a0;`):
 *     prologue right again but product block damage persists (60 lines).
 *   - pins px=r3/py=r2: tail muls chains go IN PLACE on the pinned regs
 *     (adds r3,r5,#0; muls r3; asrs r3) - same in-place disease as A628
 *     sin1 pin; return-value expansion also changes.
 *   - full web pins (x0,y0,dx,dy,px,py,v,a,b): same local damage.
 *   - unpinned v (keep dx): 102 lines; unpinned dx (keep v): 54 lines.
 *     BOTH pins are load-bearing; dx's pin is CSE-bypassed as a value
 *     (dx = *q - x0 folds onto the product pseudo) but still shifts
 *     allocation.
 *   - x0/y0 declaration swap: 60 lines.
 * KEY NEGATIVE RESULT: the remaining rotation (ours x0=r6, y0=r4, dxp=r7,
 *   dyp=r5, px=r2, py=r1 vs ROM r4/r5/r6/r7/r3/r2 - every web member one
 *   slot "late") is NOT produced by global-alloc's order (greg dump order:
 *   py, px, dxp, x0, y0, dyp; find_reg's low-to-high scan would give dxp
 *   r4, x0 r5...) - RELOAD re-homes the whole web after allocation.
 *   Controlling reload from C: pins only, and early-set pins starve the
 *   locals. Untried axis: reload-level levers (operand order in the tail
 *   products, making px/py born earlier, or changing which pseudos cross
 *   the clamp basic-block boundaries).
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
