/*
 * sub_0800D684 quarantine notes (2026-09-14, F4) — 1990/2012 bytes,
 * 839/878 instructions identical after masking register names (multiset
 * diff: 39 instructions, fully characterized below). Control flow, all
 * calls (2x sub_0800D5D4, 8x sub_0800D64C with stack args 5-8), the
 * 64-bit-free edge math, the post-loop hit processing, E708/A2D4/1208
 * tails and the return-block placement (tail wrapped in if(flag!=0),
 * return 0 last) all match.
 *
 * REMAINING DIFF = one register-allocation web:
 *  - ROM spills v1..v4 at their definitions into consecutive slots
 *    0x10/0x14/0x18/0x1C (frame 0x44) and reloads them in later edge
 *    blocks: v1: `mov r9, r1; str r1,[sp,#0x10]` (r9 used by w and
 *    edge-1's q0+v1, [sp,#0x10] reloaded in edges 2-4); v2: r4 + slot,
 *    edge-1 computes e IN PLACE on r4 (`adds r4,r4,pool(-0x1C00)`),
 *    edges 3/4 reload [sp,#0x14]; v3: r2 at def (dies at w), slot for
 *    edge 3/4 tests; v4: r1 + slot, edge 2 reloads [sp,#0x1C].
 *    Hypothesis for next attempt: emulate the retail compiler's
 *    region-splitting with split variables, e.g.
 *      v1 = (v1s = (a*d10 - b*d14) >> 8);   [yields: mov r9, r1; str [sp,#0x10]]
 *      w/E1 use v1 (pinned r9 is safe, dies before first call);
 *      E2-E4 use v1s. Same for v2/v4 (v2a CANNOT be pinned: edge-1's
 *      e takes over r4 after v2a dies).
 *    Ours (no pins except cursor->r10): v1->r9 ✓, v3->slot ✓ but
 *    v2/v4 swapped-ish, u->r5 (want r7), w->r7 (want r8); frame 0x2C.
 *  - 2x ldrh-vs-ldrsh fixed by u16 *unkE8 (element negated as u16).
 *  - 1 pool-load order: ROM loads =0x0202A550 BEFORE the unk175 test's
 *    `cmp r0,#0` (pre-expansion of the == operand); ours loads it at
 *    its compare. Tried operand reversal/side-effect shapes, no luck.
 *  - adds-vs-add copies follow from the register web (high-reg adds).
 *
 * Register pins that WORK: cursor asm("r10") (saved via push mapping).
 * Pins that MISCOMPILE (GCC 2.95 register-asm ignores conflicts):
 * v1+r9 with u/w unpinned, u+r7 or w+r8 while v2/v4 land there —
 * always check the emitted asm for a pinned reg being clobbered.
 *
 * Structure notes: a2 is an UNINITIALIZED s32 local read as D64C's 2nd
 * arg — [sp,#0x28] is loaded 8x, never stored (ROM reads garbage; our
 * plain `s32 a2;` local reproduces the no-store behavior). The D64C
 * calls: 8 args, stack args stored first (e,f,g then div for h), then
 * r0-r3. Edge k order: 0,1,2,3 per half; second half passes
 * (cursor, a2, a1, k). e is an assignment-expression inside the &&
 * chain — that reproduced the ROM's guard structure exactly.
 * Post-loop: lim = -gUnk_0202CC90.g; q0/q1 = -(lim*m)/256 (floor via
 * the adds #0xFF idiom — plain /256); lim *= 1000 after the unk140
 * stores; hit1 uses lim>>12 for unk88, hit2 uses lim>>14. The E708
 * first arg: (s32)((u8*)hit - (u8*)gUnk_0202A550) * (s32)0xC28F5C29
 * >> 4 (asrs — the u32 multiply emits lsr). gUnk_0202A530 % 3 passes
 * through a u8 param (lsls/lsrs #0x18).
 *
 * UPDATE (wave-5a harvest, 2026-09-14): the crashed F5 agent's src copy
 * was this draft + the split-variable hypothesis APPLIED (v1s..v4s
 * locals: `v1s = (v1 = ... >> 8);` etc., using v1s in the later edge
 * blocks). Fresh-verified: builds, but NO improvement — 274/1990 bytes
 * positionally equal and 876 raw diff lines for BOTH variants (register
 * renames dominate the raw diff; masked multiset unchanged at 39). The
 * split-variable shape is a wash; not worth re-trying as-is. Also fixed
 * the nested comment in this header that made the draft fail to build
 * standalone. The src copy was deleted; this draft is the keeper.
 */
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
void sub_0800BA34(u8 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
void sub_0800E708(s32 a, u8 b);
void sub_0800A2D4(struct Ent *a);
void sub_08001208(u16 idx);

u8 sub_0800D684(struct Ent *a1)
{
    s32 v1, v2, v3, v4;
    u8 flag;
    s32 a2;
    u8 i;
    s32 m0, m1, q0, q1;
    u8 count;
    register struct Ent *cursor asm("r10");
    s32 d10, d14, d18, d1C;
    s32 c4, c5, c6, c7;
    s32 dx, dz;
    s32 u, w;
    s32 e;
    s32 lim;
    struct Ent *hit1;
    struct Ent *hit2;
    s32 ang;
    s32 t1, t2;
    s32 p1, p2;
    u8 v55;

    count = gUnk_02002090;
    if (gUnk_020020DC != 0)
        count = gUnk_020020AC;
    if (a1->unk7D != 0 && gUnk_020020DC != 0)
        return 0;
    if (a1->unk175 != 0 && a1 == (struct Ent *)gUnk_0202A550)
        return 0;
    if (a1->unk18F == 0)
        return 0;
    gUnk_0202CD24 = 0x200000;
    flag = 0;
    cursor = (struct Ent *)gUnk_0202A550;
    sub_0800D5D4(a1, gUnk_0202CCB0);
    for (i = 0; i != count; i++, cursor = (struct Ent *)((u8 *)cursor + 0x190)) {
        if (cursor == a1)
            continue;
        if (cursor->unk175 != 0 && cursor == (struct Ent *)gUnk_0202A550)
            continue;
        if (cursor->unk18F == 0)
            continue;
        if (cursor->unk7D != 0 && gUnk_020020DC != 0)
            continue;
        dx = a1->unk00 - cursor->unk00;
        dz = a1->unk08 - cursor->unk08;
        dz >>= 8;
        dx >>= 8;
        if (dx < 0)
            dx = -dx;
        if (dx > 0x6400)
            continue;
        if (dz < 0)
            dz = -dz;
        if (dz > 0x6400)
            continue;
        sub_0800D5D4(cursor, gUnk_0202CD30);
        c4 = gUnk_0202CCB0[4];
        c5 = gUnk_0202CCB0[5];
        d10 = c4 - gUnk_0202CD30[4];
        d14 = c5 - gUnk_0202CD30[5];
        v1 = (gUnk_0202CD30[1] * d10 - gUnk_0202CD30[0] * d14) >> 8;
        v2 = (gUnk_0202CD30[0] * d10 + gUnk_0202CD30[1] * d14) >> 8;
        c6 = gUnk_0202CCB0[6];
        c7 = gUnk_0202CCB0[7];
        d18 = c6 - gUnk_0202CD30[6];
        d1C = c7 - gUnk_0202CD30[7];
        v3 = (gUnk_0202CD30[3] * d18 - gUnk_0202CD30[2] * d1C) >> 8;
        v4 = (gUnk_0202CD30[2] * d18 + gUnk_0202CD30[3] * d1C) >> 8;
        w = v3 - v1;
        u = v4 - v2;
        if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {
            q0 = w * e / u;
            if ((u32)(q0 + v1 + 0xF00) <= 0x1E00)
                sub_0800D64C(a1, a2, cursor, 0, &gUnk_0202CC90, &flag, -u, (e << 16) / -u);
        }
        if (u > 0 && v4 >= -0x1C00 && (e = -0x1C00 - v1) >= 0) {
            q0 = w * e / u;
            if ((u32)(q0 + v1 + 0xF00) <= 0x1E00)
                sub_0800D64C(a1, a2, cursor, 1, &gUnk_0202CC90, &flag, u, (e << 16) / u);
        }
        if (w > 0 && v3 >= -0xF00 && (e = -0xF00 - v1) >= 0) {
            q0 = e * u / w;
            if ((u32)(q0 + v2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 2, &gUnk_0202CC90, &flag, w, (e << 16) / w);
        }
        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {
            q0 = e * u / w;
            if ((u32)(q0 + v2 + 0x1C00) <= 0x3800)
                sub_0800D64C(a1, a2, cursor, 3, &gUnk_0202CC90, &flag, -w, (e << 16) / -w);
        }
        c4 = gUnk_0202CD30[4];
        c5 = gUnk_0202CD30[5];
        d10 = c4 - gUnk_0202CCB0[4];
        d14 = c5 - gUnk_0202CCB0[5];
        v1 = (gUnk_0202CCB0[1] * d10 - gUnk_0202CCB0[0] * d14) >> 8;
        v2 = (gUnk_0202CCB0[0] * d10 + gUnk_0202CCB0[1] * d14) >> 8;
        c6 = gUnk_0202CD30[6];
        c7 = gUnk_0202CD30[7];
        d18 = c6 - gUnk_0202CCB0[6];
        d1C = c7 - gUnk_0202CCB0[7];
        v3 = (gUnk_0202CCB0[3] * d18 - gUnk_0202CCB0[2] * d1C) >> 8;
        v4 = (gUnk_0202CCB0[2] * d18 + gUnk_0202CCB0[3] * d1C) >> 8;
        w = v3 - v1;
        u = v4 - v2;
        if (u < 0 && v4 <= 0x1C00 && (e = v2 - 0x1C00) >= 0) {
            q0 = w * e / u;
            if ((u32)(q0 + v1 + 0xF00) <= 0x1E00)
                sub_0800D64C(cursor, a2, a1, 0, &gUnk_0202CC90, &flag, -u, (e << 16) / -u);
        }
        if (u > 0 && v4 >= -0x1C00 && (e = -0x1C00 - v1) >= 0) {
            q0 = w * e / u;
            if ((u32)(q0 + v1 + 0xF00) <= 0x1E00)
                sub_0800D64C(cursor, a2, a1, 1, &gUnk_0202CC90, &flag, u, (e << 16) / u);
        }
        if (w > 0 && v3 >= -0xF00 && (e = -0xF00 - v1) >= 0) {
            q0 = e * u / w;
            if ((u32)(q0 + v2 + 0x1C00) <= 0x3800)
                sub_0800D64C(cursor, a2, a1, 2, &gUnk_0202CC90, &flag, w, (e << 16) / w);
        }
        if (w < 0 && v3 <= 0xF00 && (e = v1 - 0xF00) >= 0) {
            q0 = e * u / w;
            if ((u32)(q0 + v2 + 0x1C00) <= 0x3800)
                sub_0800D64C(cursor, a2, a1, 3, &gUnk_0202CC90, &flag, -w, (e << 16) / -w);
        }
    }
    if (flag != 0) {
    hit1 = gUnk_0202CC90.a;
    hit2 = gUnk_0202CC90.c;
    ang = hit2->unk34 >> 8;
    t1 = gUnk_0801CD08[ang];
    t2 = gUnk_0801CD08[ang + 0x40];
    p1 = gUnk_083FDA2C[gUnk_0202CC90.d].f0;
    p2 = gUnk_083FDA2C[gUnk_0202CC90.d].f1;
    m0 = (p1 * t2 - p2 * t1) >> 4;
    m1 = (p1 * t1 + p2 * t2) >> 4;
    lim = -gUnk_0202CC90.g;
    q0 = -(lim * m0) / 256;
    q1 = -(lim * m1) / 256;
    hit1->unk0C += q0;
    hit1->unk14 += q1;
    hit1->unk140 = 0;
    hit1->unk144 = 0;
    hit1->unk148 = 0;
    hit2->unk0C -= q0;
    hit2->unk14 -= q1;
    hit2->unk140 = 0;
    hit2->unk144 = 0;
    hit2->unk148 = 0;
    lim *= 1000;
    v55 = hit1->unk55;
    if (v55 == 0)
        sub_0800BA34(&hit1->unk55, v55, 0, 0, v55, v55, -6, 0x400);
    if ((u8)(hit1->unk7C - 5) > 2) {
        if (gUnk_0202EEB0 != 0)
            hit1->unk88 -= lim >> 12;
        if (hit1->unk88 > 40000) {
            e = -hit1->unk2C >> 12;
            if (e < 0)
                e = 0;
            if (e > 0x32)
                sub_0800E708((s32)((u8 *)hit1 - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> 4,
                             gUnk_0202A530 % 3);
            else
                sub_0800E708((s32)((u8 *)hit1 - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> 4, 4);
        }
        gUnk_0202A530++;
    }
    sub_0800A2D4(hit1);
    hit1->unk48 = hit1->unk2C;
    if (hit1->unk2C > 0)
        hit1->unk48 = 0;
    hit1->unk40 = (hit1->unk48 << 8) / -hit1->unkE8[hit1->unk3E];
    if ((u8)(hit2->unk7C - 5) > 2) {
        if (gUnk_0202EEB0 != 0)
            hit2->unk88 -= lim >> 14;
        if (hit2->unk88 > 40000) {
            e = -hit2->unk2C >> 12;
            if (e < 0)
                e = 0;
            if (e > 0x32)
                sub_0800E708((s32)((u8 *)hit2 - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> 4,
                             gUnk_0202A530 % 3);
            else
                sub_0800E708((s32)((u8 *)hit2 - (u8 *)gUnk_0202A550) * (s32)0xC28F5C29 >> 4, 4);
        }
        gUnk_0202A530++;
    }
    sub_0800A2D4(hit2);
    hit2->unk48 = hit2->unk2C;
    if (hit2->unk2C > 0)
        hit2->unk48 = 0;
    hit2->unk40 = (hit2->unk48 << 8) / -hit2->unkE8[hit2->unk3E];
    if (hit1 == (struct Ent *)gUnk_0202A550 || hit2 == (struct Ent *)gUnk_0202A550
        || gUnk_020020DC != 0) {
        if (gUnk_020021E0 == 0 && gUnk_020020E0 == 0 && gUnk_0202EF00[3] != 0
            && (a1 == (struct Ent *)gUnk_0202A550 || gUnk_020020DC != 0)
            && hit1->unk55 == 0 && hit2->unk55 == 0)
            sub_08001208(0x12);
    }
    hit1->unk55 = 0x10;
    hit2->unk55 = 0x10;
    return 1;
    }
    return 0;
}
