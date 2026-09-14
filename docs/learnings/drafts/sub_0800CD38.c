/*
 * sub_0800CD38 quarantine notes (2026-09-14, F4)
 * Best build: 572/580 bytes, register-identical after masking reg names
 * EXCEPT 6 single-instruction hunks (all "target reloads, ours reuses"):
 *  1. gUnk_02000480 pool ldr r3 comes BEFORE `mov r0, ip; subs (dz)` in
 *     target; ours computes dz first, loads pool at the store. Tried: fused
 *     nested assignment `g480 = (cross = ...)`, separate statements,
 *     pointer local pg (GCC folds it), comma-expression, volatile on g480
 *     (reorders worse), raw cast *(s32*)0x02000480 (moves other hunks).
 *  2. target reloads p0y `ldr r0,[sp,#0x24]` right before `subs r7,r5,r0`
 *     (a = x0 - p0y); ours reuses the r6 value from ex computation.
 *  3/4. target re-loads the g488/g484 pool addresses between the div-result
 *     copy and the second store (`adds r4,r0,#0; ldr r0,[pc]; str`); ours
 *     CSEs one address pseudo and holds it in r4 across the __divsi3 call.
 *     Casting only the 2nd store `*(s32 *)0x02000488 = nx;` DOES reproduce
 *     the per-store pool load but restructures the prologue/s16 region.
 *  5. a4 fill: target copies wall `mov r0, r8` then `mov r2, r8` (two
 *     copies); ours copies once into r3 and reuses.
 *  6. a4 fill: target reloads a4 `[sp,#0x1C]` before EACH field store;
 *     ours holds one copy. `volatile struct Result *a4` param makes it
 *     worse (extra ldrb reloads of the u8 fields).
 * Pins used: z0=r12, dz=r10, dx16=r9 (assignment-expr inside cross),
 * a=r7, b=r5 (assignment-exprs inside t). wall naturally lands r8 once
 * dx16 takes r9. v1/v2 temps + explicit `next` local reproduce the
 * wall-lookup/next-store interleaving at 0x0800CD5C.
 */
#include "global.h"

struct Wall {
    u16 unk00;
    u16 unk02;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
};

struct Pt {
    s32 unk00;
    s32 unk04;
};
struct Corner {
    s16 v[8];
    s32 unk10;
    s32 unk14;
};

struct Box {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
};

struct Result {
    u8 pad00[4];
    s32 unk04;
    s32 unk08;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
    s32 unk10;
};

extern u8 *gUnk_0202CC40;
extern u8 *gUnk_0202CC44;
extern s32 gUnk_02000460;
extern s32 gUnk_02000464;
extern s32 gUnk_02000468;
extern s32 gUnk_0200046C;
extern s32 gUnk_02000470;
extern s32 gUnk_02000474;
extern s32 gUnk_02000478;
extern s32 gUnk_0200047C;
extern s32 gUnk_02000480;
extern s32 gUnk_02000484;
extern s32 gUnk_02000488;

void sub_0800CD38(struct Corner *a1, struct Box *a2, struct Box *a3,
                  struct Result *a4, u16 *a5, s32 *a6)
{
    u8 unused[0x10];
    s32 p0x, p0y, p1x, p1y;
    struct Corner *cur1;
    struct Box *cur3;
    s32 j;
    u16 *list;
    u16 *next;
    struct Wall *w;
    struct Pt *pts;
    register s32 z0 asm("r12");
    s32 x0, z1, x1;
    register s32 dz asm("r10");
    register s32 dx16 asm("r9");
    register s32 a asm("r7");
    register s32 b asm("r5");
    s32 cross, t;
    s32 *pg;
    s32 nx, val;
    s32 v1;
    s32 v2;

    for (list = a5; *list != 0xFFFF; list = next) {
        w = (struct Wall *)(gUnk_0202CC40 + (*list << 5));
        v1 = a2->unk00;
        v2 = w->unk10;
        next = list + 1;
        if (v1 > v2 || a2->unk08 > w->unk18
            || a2->unk04 < w->unk0C || a2->unk0C < w->unk14)
            continue;
        pts = (struct Pt *)gUnk_0202CC44;
        p0x = pts[w->unk00].unk00;
        p0y = pts[w->unk00].unk04;
        p1x = pts[w->unk02].unk00;
        p1y = pts[w->unk02].unk04;
        cur1 = a1;
        cur3 = a3;
        for (j = 0; j != 4; j++, cur1++, cur3++) {
            if (cur3->unk00 > w->unk10 + 1 || cur3->unk08 > w->unk18 + 1
                || cur3->unk04 < w->unk0C - 1 || cur3->unk0C < w->unk14 - 1)
                continue;
            if ((cur1->unk10 >> 8) * w->unk04 + (cur1->unk14 >> 8) * w->unk08 > 0)
                continue;
            gUnk_02000470 = p0x;
            gUnk_02000474 = p0y;
            gUnk_02000478 = p1x;
            gUnk_0200047C = p1y;
            gUnk_02000460 = (z0 = cur1->v[1]);
            gUnk_02000464 = (x0 = cur1->v[3]);
            gUnk_02000468 = (z1 = cur1->v[5]);
            gUnk_0200046C = (x1 = cur1->v[7]);
            dz = z1 - z0;
            pg = &gUnk_02000480;
            gUnk_02000480 = (cross = dz * (p1y - p0y) - (dx16 = x1 - x0) * (p1x - p0x));
            if (cross == 0)
                continue;
            t = ((a = x0 - p0y) * (p1x - p0x) - (b = z0 - p0x) * (p1y - p0y)) << 8;
            gUnk_02000488 = t;
            nx = t / cross;
            gUnk_02000488 = nx;
            if ((u32)nx > 0x100)
                continue;
            t = (dz * a - dx16 * b) << 8;
            gUnk_02000484 = t;
            val = t / cross;
            gUnk_02000484 = val;
            if ((u32)val > 0x100)
                continue;
            if (nx < *a6) {
                *a6 = val;
                a4->unk04 = w->unk04 * 260 >> 8;
                a4->unk08 = w->unk08 * 260 >> 8;
                a4->unk0D = w->unk1C;
                a4->unk0E = w->unk1D;
                a4->unk0F = w->unk1E;
                a4->unk10 = *list;
                a4->unk0C = j;
            }
        }
    }
}
