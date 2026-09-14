/*
 * sub_0800DE9C (304b incl. 16b trailing data; code = 288b) — QUARANTINED
 * after 14 iterations. EVERYTHING matches except 2 insns in the loop's
 * tile computation. Target:
 *   ldr r7, [pc, #64]  @ =0x1FF
 *   adds r0, r7, #0    ; copy of const
 *   adds r1, r2, #0    ; copy of t2 into tile's home
 *   ands r1, r0        ; tile = t2 & 0x1FF
 * agbcc folds this to `ldr r1, =0x1FF; ands r1, r2` (const materialized
 * straight into the ands dest — reload's cheaper choice). Tried: tile as
 * s32/u16 local, inline expression, const-left `0x1FF & t2`, compound
 * `tile = t2; tile &= 0x1FF;`, separate c1 = 0x1FF local (coalesces into
 * tile's home r1). Everything else byte-matches: the m1/m2/p/q locals
 * (mask constants must be opaque locals or combine truncates 0xFFFFFE00
 * to 0xFE00 and materializes via movs+lsls instead of the pool), the
 * for-init copies `for (i = 0, gg = g, a1 = m1, a2 = m2; ...)` (reproduces
 * the mov r10/mov r9/adds r4 preheader dance exactly), the if/else with
 * DUPLICATED e[4] bodies and `if (x < i*32+32)` polarity, integer-form
 * `e = (u8 *)((i + 10) * 8 + (u32)gg)` for the adds operand order, tile
 * local (computes before the load so orrs r0, r1 lands in A's reg).
 * The lever left: something making the 0x1FF const pseudo refuse to
 * coalesce with tile's home r1 (e.g. a second 0x1FF use, or reload
 * pressure at that point).
 */
#include "global.h"

extern s16 gUnk_0202E960[];

void sub_0800DE9C(u16 x, u16 y)
{
    s16 *g = gUnk_0202E960;
    s16 *gg;
    u16 *p;
    u16 *q;
    s32 m1, m2, a1, a2;
    u8 *e;
    u16 i;
    s32 t2;
    s32 tile;

    p = &g[0x25];
    m1 = ~0x1FF;
    *p &= m1;
    ((u8 *)g)[0x48] = y;
    ((u8 *)g)[0x4B] = (((u8 *)g)[0x4B] & 0x3F) | 0x80;
    ((u8 *)g)[0x4D] &= 0x0F;
    q = &g[0x26];
    m2 = ~0x3FF;
    *q = (*q & m2) | 0x10;

    for (i = 0, gg = g, a1 = m1, a2 = m2; i < 8; i++) {
        e = (u8 *)((i + 10) * 8 + (u32)gg);
        t2 = i * 32 + 32;
        tile = t2 & 0x1FF;
        *(u16 *)&e[2] = (*(u16 *)&e[2] & a1) | tile;
        e[0] = y;
        e[3] = (e[3] & 0x3F) | 0x80;
        e[5] &= 0x0F;
        if (x < t2)
            *(u16 *)&e[4] = (*(u16 *)&e[4] & a2) | 0x20;
        else
            *(u16 *)&e[4] = (*(u16 *)&e[4] & a2) | 0x10;
    }

    g[0x41] = (g[0x41] & ~0x1FF) | 0xD0;
    ((u8 *)g)[0x80] = y;
    ((u8 *)g)[0x83] = (((u8 *)g)[0x83] & 0x3F) | 0x80;
    ((u8 *)g)[0x85] &= 0x0F;
    g[0x42] = (g[0x42] & ~0x3FF) | 0x20;
}
