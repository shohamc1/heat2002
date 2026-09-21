#include "global.h"

#define DIV_HI(a, b) (__extension__({ \
    register s32 _d0 asm("r0") = (a); \
    register s32 _d1 asm("r1") = (b); \
    s32 _rr; \
    asm volatile("bl sub_08344BB8" : "=l"(_d0) : "0"(_d0), "l"(_d1) \
                 : "r2", "r3", "r12", "lr", "cc"); \
    _rr = _d0; \
    _rr; }))
#define DIV_T(a, b) (__extension__({ \
    register s32 _d0 asm("r0") = (a); \
    register s32 _d1 asm("r1") = (b); \
    register s32 _rr asm("r1"); \
    asm volatile("bl sub_08344BB8\n\tadd %0, r0, #0" : "=l"(_rr) : "r"(_d0), "r"(_d1) \
                 : "r2", "r3", "r12", "lr", "cc"); \
    _rr; }))

/*
 * High-region twin of sub_0800D684 (car-vs-car box collision test).
 * NEAR-MISS DRAFT: 2010 of 2022 bytes; residual diagnosed below.
 * Same shapes; see docs/learnings/parked.md for the low-region record:
 * - d[2] written element-wise keeps the DImode pseudo (r5:r6) live
 *   across the whole loop.
 * - pa is a pointer local used only for the first call.
 * - a2 is never assigned.
 * - count is declared after m/q so its spill slot is the highest one.
 * - The range pre-check is px load-then-subtract and pz in one expression.
 *
 * The ROM's high region was built with its own libgcc: `/` resolved to
 * sub_08344BB8 there, but our symbols.ld aliases __divsi3 to sub_08017230,
 * so the divisions cannot use the `/` operator. A plain explicit call
 * changes the RTL two ways (verified by compiling sub_0800D684.c both
 * ways): a tree-level CALL argument is pre-evaluated to the front of the
 * argument list (the target emits stack args 5,6,7 and the nested div
 * LAST), and it loses the libcall's hard-r0 return, which changes the
 * loop allocation (car kept in r10 instead of spilled to sp+0x24).
 * DIV_HI/DIV_T above restore both with r0/r1-pinned statement-expressions;
 * DIV_T bakes the forced copy ("add %0, r0, #0", result pinned r1) that
 * `t = div; t += v[0];` needs at the eight t-sites. Modulo by 3 is an
 * explicit sub_08344DA8 call (unsigned mod helper).
 *
 * Remaining 12-byte residual (3 items):
 *  1. In the SECOND rotation half, GCC schedules edge2's `mov r0, r8;
 *     muls r0, r4` product before the mid-function pool and branches over
 *     it; the libcall kept the product attached to the div. Baking the
 *     movs into the asm template fixes this but breaks agbcc's long-branch
 *     trampolines ("branch out of range" in gas).
 *  2. `mov r4, r8; adds r4, #0x55` (&b->unk55) is emitted after the
 *     a->unk55 load; the target emits it between the load and its compare.
 *  3. Consequential mid-pool position/order shift (16 bytes later).
 */

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

struct Coll {
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

extern u8 gUnk_020390A0;
extern u8 gUnk_020390EC;
extern u8 gUnk_020390BC;
extern struct Ent gUnk_0203D520[];
extern s32 gUnk_0203DF44;
extern s32 gUnk_0203DED0[8];
extern s32 gUnk_0203DF50[8];
extern struct Coll gUnk_0203DEB0;
extern s16 gUnk_0200C3E8[];
extern struct Pt2 gUnk_0202AF08[];
extern u8 gUnk_0203E0E0;
extern u8 gUnk_0203D4FC;
extern u8 gUnk_020391F0;
extern u8 gUnk_020390F0;
extern u8 gUnk_0203E120[];

void sub_08343DF8(struct Ent *a, s32 *d);
void sub_08343E70(struct Ent *a, s32 b, struct Ent *c, s32 d, struct Coll *e,
                  u8 *f, s32 g, s32 h);
void sub_08343138(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void sub_08344680(s32 a, u8 b);
void sub_08341D64(struct Ent *a);
void sub_0833A8C8(u16 idx);
s32 sub_08344BB8(s32 a, s32 b);
s32 sub_08344DA8(s32 a, s32 b);

u8 sub_08343EA8(struct Ent *car)
{
    u8 hit;
    s32 v[4];
    s32 a2;
    u8 i;
    struct Ent *other;
    s32 d[2];
    s32 px, pz;
    s32 w, u;
    s32 e, t;
    s32 *pa;
    s32 m[2];
    s32 q[2];
    u8 count;
    struct Ent *a, *b;
    s32 ang, s, c, nx, nz, f;
    s32 sd;

    count = gUnk_020390A0;
    if (gUnk_020390EC != 0)
        count = gUnk_020390BC;
    if (car->unk7D != 0 && gUnk_020390EC != 0)
        return 0;
    if (car->unk175 != 0) {
        if (car == gUnk_0203D520)
            return 0;
        if (car->unk18F == 0)
            return 0;
    }
    gUnk_0203DF44 = 0x200000;
    hit = 0;
    other = gUnk_0203D520;
    pa = gUnk_0203DED0;
    sub_08343DF8(car, pa);
    for (i = 0; i != count; i++, other++) {
        if (other == car)
            continue;
        if (other->unk175 != 0) {
            if (other == gUnk_0203D520)
                continue;
            if (other->unk18F == 0)
                continue;
        }
        if (other->unk7D != 0 && gUnk_020390EC != 0)
            continue;
        px = car->unk00;
        px -= other->unk00;
        pz = (car->unk08 - other->unk08) >> 8;
        px >>= 8;
        if (px < 0)
            px = -px;
        if (px > 0x6400)
            continue;
        if (pz < 0)
            pz = -pz;
        if (pz > 0x6400)
            continue;
        sub_08343DF8(other, gUnk_0203DF50);

        d[0] = gUnk_0203DED0[4];
        d[1] = gUnk_0203DED0[5];
        d[0] -= gUnk_0203DF50[4];
        d[1] -= gUnk_0203DF50[5];
        v[0] = (gUnk_0203DF50[1] * d[0] - gUnk_0203DF50[0] * d[1]) >> 8;
        v[1] = (gUnk_0203DF50[0] * d[0] + gUnk_0203DF50[1] * d[1]) >> 8;
        d[0] = gUnk_0203DED0[6];
        d[1] = gUnk_0203DED0[7];
        d[0] -= gUnk_0203DF50[6];
        d[1] -= gUnk_0203DF50[7];
        v[2] = (gUnk_0203DF50[3] * d[0] - gUnk_0203DF50[2] * d[1]) >> 8;
        v[3] = (gUnk_0203DF50[2] * d[0] + gUnk_0203DF50[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = DIV_T(w * e, u);
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_08343E70(car, a2, other, 0, &gUnk_0203DEB0, &hit, -u, DIV_HI(e << 16, -u));
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = DIV_T(w * e, u);
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_08343E70(car, a2, other, 1, &gUnk_0203DEB0, &hit, u, DIV_HI(e << 16, u));
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = DIV_T(e * u, w);
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_08343E70(car, a2, other, 2, &gUnk_0203DEB0, &hit, w, DIV_HI(e << 16, w));
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = DIV_T(e * u, w);
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_08343E70(car, a2, other, 3, &gUnk_0203DEB0, &hit, -w, DIV_HI(e << 16, -w));
        }

        d[0] = gUnk_0203DF50[4];
        d[1] = gUnk_0203DF50[5];
        d[0] -= gUnk_0203DED0[4];
        d[1] -= gUnk_0203DED0[5];
        v[0] = (gUnk_0203DED0[1] * d[0] - gUnk_0203DED0[0] * d[1]) >> 8;
        v[1] = (gUnk_0203DED0[0] * d[0] + gUnk_0203DED0[1] * d[1]) >> 8;
        d[0] = gUnk_0203DF50[6];
        d[1] = gUnk_0203DF50[7];
        d[0] -= gUnk_0203DED0[6];
        d[1] -= gUnk_0203DED0[7];
        v[2] = (gUnk_0203DED0[3] * d[0] - gUnk_0203DED0[2] * d[1]) >> 8;
        v[3] = (gUnk_0203DED0[2] * d[0] + gUnk_0203DED0[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = DIV_T(w * e, u);
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_08343E70(other, a2, car, 0, &gUnk_0203DEB0, &hit, -u, DIV_HI(e << 16, -u));
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = DIV_T(w * e, u);
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_08343E70(other, a2, car, 1, &gUnk_0203DEB0, &hit, u, DIV_HI(e << 16, u));
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = DIV_T(e * u, w);
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_08343E70(other, a2, car, 2, &gUnk_0203DEB0, &hit, w, DIV_HI(e << 16, w));
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = DIV_T(e * u, w);
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_08343E70(other, a2, car, 3, &gUnk_0203DEB0, &hit, -w, DIV_HI(e << 16, -w));
        }
    }

    if (hit != 0) {
        a = gUnk_0203DEB0.a;
        b = gUnk_0203DEB0.c;
        ang = b->unk34 >> 8;
        s = gUnk_0200C3E8[ang];
        c = gUnk_0200C3E8[ang + 0x40];
        nx = gUnk_0202AF08[gUnk_0203DEB0.d].f0;
        nz = gUnk_0202AF08[gUnk_0203DEB0.d].f1;
        m[0] = (nx * c - nz * s) >> 4;
        m[1] = (nx * s + nz * c) >> 4;
        f = -gUnk_0203DEB0.g;
        q[0] = -(f * m[0]) / 256;
        q[1] = -(f * m[1]) / 256;
        a->unk0C += q[0];
        a->unk14 += q[1];
        a->unk140 = 0;
        a->unk144 = 0;
        a->unk148 = 0;
        b->unk0C -= q[0];
        b->unk14 -= q[1];
        b->unk140 = 0;
        b->unk144 = 0;
        b->unk148 = 0;
        f *= 1000;
        if (a->unk55 == 0)
            sub_08343138(0, 0, -6, 0, 0, 0, 0x400);
        if (a->unk7C < 5 || a->unk7C > 7) {
            if (gUnk_0203E0E0 != 0)
                a->unk88 -= f >> 12;
            if (a->unk88 > 40000) {
                sd = -a->unk2C >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    sub_08344680(a - gUnk_0203D520, sub_08344DA8(gUnk_0203D4FC, 3));
                else
                    sub_08344680(a - gUnk_0203D520, 4);
            }
            gUnk_0203D4FC++;
        }
        sub_08341D64(a);
        a->unk48 = a->unk2C;
        if (a->unk2C > 0)
            a->unk48 = 0;
        a->unk40 = sub_08344BB8(a->unk48 << 8, -a->unkE8[a->unk3E]);
        if (b->unk7C < 5 || b->unk7C > 7) {
            if (gUnk_0203E0E0 != 0)
                b->unk88 -= f >> 14;
            if (b->unk88 > 40000) {
                sd = -b->unk2C >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    sub_08344680(b - gUnk_0203D520, sub_08344DA8(gUnk_0203D4FC, 3));
                else
                    sub_08344680(b - gUnk_0203D520, 4);
            }
            gUnk_0203D4FC++;
        }
        sub_08341D64(b);
        b->unk48 = b->unk2C;
        if (b->unk2C > 0)
            b->unk48 = 0;
        b->unk40 = sub_08344BB8(b->unk48 << 8, -b->unkE8[b->unk3E]);
        if (a == gUnk_0203D520 || b == gUnk_0203D520 || gUnk_020390EC != 0) {
            if (gUnk_020391F0 == 0 && gUnk_020390F0 == 0 && gUnk_0203E120[3] != 0
                && (car == gUnk_0203D520 || gUnk_020390EC != 0)
                && a->unk55 == 0 && b->unk55 == 0)
                sub_0833A8C8(0x12);
        }
        a->unk55 = 0x10;
        b->unk55 = 0x10;
        return 1;
    }
    return 0;
}
