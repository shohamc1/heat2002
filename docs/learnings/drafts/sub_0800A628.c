/*
 * sub_0800A628 quarantine notes (220/224 bytes, 2026-09-14):
 * Instruction stream/pool/branches solved: rot kept via `register u32 rot
 * asm("r9")` (blocks combine folding (x>>10)<<16>>14 -> <<2 when rot is
 * single-ref after CSE unifies group-3's table address); group-2 index as
 * TWO statements `j = (*q >> 10) & 0x3F; j = j << 2;` (blocks <<2<<1 -> <<3
 * fusion); m = -256 local as the muls multiplier (produces the ROM's
 * muls/negs/asrs idiom). Remaining diff: one register-allocation web.
 * ROM homes: t1=r3,t2=r2,m=r1,sin1=r5,ncos1=r4,q=r6,table=r7,sin2=r8,
 * ncos2=r3; ours (unpinned): sin1=r3,ncos1=r4,sin2=r6,ncos2=r5,q=r5->r8
 * reload copy, table=r6, m=r2, idx=r1. Pinning sin1/cos1 fixed r5/r4 but
 * moved the muls chain in-register (mov r5,r3 style) - wrong shape.
 * Also: group 3 computes cos-slot address first in ours; ROM computes the
 * sin-slot address first then loads cos-slot first (addr-sin, addr-cos,
 * load-cos, load-sin) - pointer-local attempts reassociated instead.
 */
#include "global.h"

extern s16 gUnk_0801CD08[]; /* 0x0801CD08 */

void sub_0800A628(s32 *a)
{
    register u32 rot asm("r9");
    u32 i;
    s32 m;
    s32 t1;
    s32 t2;
    s32 sin1;
    s32 cos1;
    u32 j;
    s32 t3;
    s32 t4;
    s32 sin2;
    s32 cos2;
    s32 val;
    s32 *q;

    rot = (((u16 *)a)[0x1A] >> 10) << 16;
    i = rot >> 14;
    t1 = gUnk_0801CD08[i];
    t2 = gUnk_0801CD08[i + 0x40];
    m = -256;
    sin1 = -(t1 * m) >> 8;
    cos1 = (t2 * m) >> 8;
    q = &a[0x4B];
    j = (*q >> 10) & 0x3F;
    j = j << 2;
    t3 = gUnk_0801CD08[j];
    t4 = gUnk_0801CD08[j + 0x40];
    sin2 = -(t3 * m) >> 8;
    cos2 = (t4 * m) >> 8;
    if ((sin2 * sin1 + cos1 * cos2) >> 8 > 0x8D)
        return;
    i = rot >> 14;
    cos1 = gUnk_0801CD08[i + 0x40];
    sin1 = gUnk_0801CD08[i];
    if (sin2 * cos1 + sin1 * cos2 < 0)
        val = ((u16 *)a)[0x1A] - 0x2800;
    else
        val = ((u16 *)a)[0x1A] + 0x2800;
    *q = val;
    a[0x4B] = *(u16 *)&a[0x4B];
}
