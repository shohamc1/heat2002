/*
 * sub_0800CBB8 (72b) — QUARANTINED after ~15 iterations. Structure 100%
 * solved; remaining diff is ONLY a register swap: target keeps the two mask
 * results c,d in r3,r2 (const-3 as op0: "movs r2,#3; adds r3,r2; ands r3,r0;
 * ands r2,r1") and runs the w/mult/base scratch chain in r0/r1; agbcc gives
 * c,d r0/r1 (ands in place on the dying x-1/y-1) and runs the chain in r2/r3.
 * Tried: operand order 3&(x-1) vs (x-1)&3, u/v locals for x-1/y-1, pinning
 * b=r5 (kept: gives pop {r4,r5} and muls r0,r5), pinning c=r3/d=r2 (worse:
 * const goes to r6, push {r4,r5,r6}), pinning m=r0 (worse: r4/r6 temps),
 * u32 m/base, param-rewrite style, t/v pointer locals (these ARE right —
 * they give the late ldrh and lazy DEC pool load), gcse-hoisting (absent).
 * Every instruction and its ORDER matches except which of r0..r3 holds what
 * between the masks and the t add. The lever left: something that makes the
 * x-1/y-1 pseudos conflict with c/d's range so c,d cannot coalesce into
 * r0/r1 (e.g. keeping x-1 live past the mask, or flipping reload's
 * round-robin start so the first pool-address reload lands in r0).
 */
#include "global.h"

extern u32 gUnk_02002200[];
extern u32 gUnk_0200BC50[];
extern u32 gUnk_02022DEC[];

u8 sub_0800CBB8(s32 x, s32 y)
{
    s32 a = (x - 1) >> 2;
    register s32 b asm("r5") = (y - 1) >> 2;
    s32 c = 3 & (x - 1);
    s32 d = 3 & (y - 1);
    s32 m = gUnk_02002200[0] * b;
    s32 base = gUnk_0200BC50[0];
    u16 *t = (u16 *)(a * 2 + (m * 2 + base));
    s32 v = c + d * 4;

    return *(u8 *)(*t * 16 + gUnk_02022DEC[0] + v);
}
