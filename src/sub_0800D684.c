#include "global.h"
#include "data.h"
#include "m4a.h"

/*
 * Car-vs-car box collision test. For every other car within range, the
 * relative position and next-frame position are rotated into the other
 * car's frame (and the reverse), and each of the four box edges is tested
 * for a crossing. The nearest crossing (smallest time) is kept by
 * sub_0800D64C in gUnk_0202CC90; after the loop the impulse is applied.
 *
 * Shapes the retail bytes depend on (see docs/learnings/parked.md):
 * - `d[2]` is written element-wise, never whole. Each partial store keeps the
 *   DImode pseudo live around the whole loop, so it holds r5:r6 throughout
 *   and pushes e/u/w/other to r4/r7/r8/r10 and `car` to the stack.
 * - `pa` is a pointer local used only for the first call: the loop-hoisted
 *   copy of the address extends it across the call, so it lands in r7.
 * - `a2` is never assigned; the retail code passes an uninitialised slot.
 * - `count` is declared after `m`/`q` so its spill slot is the highest one.
 * - `t = (w * e) / u; t += v[0];` must be two statements.
 * - The range pre-check is `px` load-then-subtract and `pz` in one expression.
 */

struct Ent {
    s32 posX;
    u8 pad04[4];
    s32 posZ;
    s32 velX;
    u8 pad10[4];
    s32 velZ;
    u8 pad18[0x2C - 0x18];
    s32 speed;
    u8 pad30[0x34 - 0x30];
    u16 heading;
    u8 pad36[0x3E - 0x36];
    u8 gear;
    u8 pad3F;
    s16 rpm;
    u8 pad42[0x48 - 0x42];
    s32 unk48;
    u8 pad4C[0x55 - 0x4C];
    u8 unk55;
    u8 pad56[0x7C - 0x56];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x88 - 0x7E];
    s32 damage;
    u8 pad8C[0xE8 - 0x8C];
    u16 *unkE8;
    u8 padEC[0x140 - 0xEC];
    s32 forceX;
    s32 forceZ;
    s32 torque;
    u8 pad14C[0x175 - 0x14C];
    u8 pitState;
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

extern u8 gNumCars;
extern u8 gIsLinkRace;
extern u8 gNumLinkPlayers;
extern struct Ent gCars[];
extern s32 gUnk_0202CD24;
extern s32 gUnk_0202CCB0[8];
extern s32 gUnk_0202CD30[8];
extern struct Coll gUnk_0202CC90;
extern struct Pt2 gUnk_083FDA2C[];
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202A530;
extern u8 gUnk_020021E0;
extern u8 gIsDemo;
extern u8 gOptions[];

void sub_0800D5D4(struct Ent *a, s32 *d);
void sub_0800D64C(struct Ent *a, s32 b, struct Ent *c, s32 d, struct Coll *e,
                  u8 *f, s32 g, s32 h);
void sub_0800BA34(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void sub_0800E708(s32 a, u8 b);
void ComputeForwardSpeed(struct Ent *a);

u8 CollideCars(struct Ent *car)
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

    count = gNumCars;
    if (gIsLinkRace != 0)
        count = gNumLinkPlayers;
    if (car->unk7D != 0 && gIsLinkRace != 0)
        return 0;
    if (car->pitState != 0) {
        if (car == gCars)
            return 0;
        if (car->unk18F == 0)
            return 0;
    }
    gUnk_0202CD24 = 0x200000;
    hit = 0;
    other = gCars;
    pa = gUnk_0202CCB0;
    sub_0800D5D4(car, pa);
    for (i = 0; i != count; i++, other++) {
        if (other == car)
            continue;
        if (other->pitState != 0) {
            if (other == gCars)
                continue;
            if (other->unk18F == 0)
                continue;
        }
        if (other->unk7D != 0 && gIsLinkRace != 0)
            continue;
        px = car->posX;
        px -= other->posX;
        pz = (car->posZ - other->posZ) >> 8;
        px >>= 8;
        if (px < 0)
            px = -px;
        if (px > 0x6400)
            continue;
        if (pz < 0)
            pz = -pz;
        if (pz > 0x6400)
            continue;
        sub_0800D5D4(other, gUnk_0202CD30);

        d[0] = gUnk_0202CCB0[4];
        d[1] = gUnk_0202CCB0[5];
        d[0] -= gUnk_0202CD30[4];
        d[1] -= gUnk_0202CD30[5];
        v[0] = (gUnk_0202CD30[1] * d[0] - gUnk_0202CD30[0] * d[1]) >> 8;
        v[1] = (gUnk_0202CD30[0] * d[0] + gUnk_0202CD30[1] * d[1]) >> 8;
        d[0] = gUnk_0202CCB0[6];
        d[1] = gUnk_0202CCB0[7];
        d[0] -= gUnk_0202CD30[6];
        d[1] -= gUnk_0202CD30[7];
        v[2] = (gUnk_0202CD30[3] * d[0] - gUnk_0202CD30[2] * d[1]) >> 8;
        v[3] = (gUnk_0202CD30[2] * d[0] + gUnk_0202CD30[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_0800D64C(car, a2, other, 0, &gUnk_0202CC90, &hit, -u, (e << 16) / -u);
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_0800D64C(car, a2, other, 1, &gUnk_0202CC90, &hit, u, (e << 16) / u);
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_0800D64C(car, a2, other, 2, &gUnk_0202CC90, &hit, w, (e << 16) / w);
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_0800D64C(car, a2, other, 3, &gUnk_0202CC90, &hit, -w, (e << 16) / -w);
        }

        d[0] = gUnk_0202CD30[4];
        d[1] = gUnk_0202CD30[5];
        d[0] -= gUnk_0202CCB0[4];
        d[1] -= gUnk_0202CCB0[5];
        v[0] = (gUnk_0202CCB0[1] * d[0] - gUnk_0202CCB0[0] * d[1]) >> 8;
        v[1] = (gUnk_0202CCB0[0] * d[0] + gUnk_0202CCB0[1] * d[1]) >> 8;
        d[0] = gUnk_0202CD30[6];
        d[1] = gUnk_0202CD30[7];
        d[0] -= gUnk_0202CCB0[6];
        d[1] -= gUnk_0202CCB0[7];
        v[2] = (gUnk_0202CCB0[3] * d[0] - gUnk_0202CCB0[2] * d[1]) >> 8;
        v[3] = (gUnk_0202CCB0[2] * d[0] + gUnk_0202CCB0[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_0800D64C(other, a2, car, 0, &gUnk_0202CC90, &hit, -u, (e << 16) / -u);
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                sub_0800D64C(other, a2, car, 1, &gUnk_0202CC90, &hit, u, (e << 16) / u);
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_0800D64C(other, a2, car, 2, &gUnk_0202CC90, &hit, w, (e << 16) / w);
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                sub_0800D64C(other, a2, car, 3, &gUnk_0202CC90, &hit, -w, (e << 16) / -w);
        }
    }

    if (hit != 0) {
        a = gUnk_0202CC90.a;
        b = gUnk_0202CC90.c;
        ang = b->heading >> 8;
        s = gUnk_0801CD08[ang];
        c = gUnk_0801CD08[ang + 0x40];
        nx = gUnk_083FDA2C[gUnk_0202CC90.d].f0;
        nz = gUnk_083FDA2C[gUnk_0202CC90.d].f1;
        m[0] = (nx * c - nz * s) >> 4;
        m[1] = (nx * s + nz * c) >> 4;
        f = -gUnk_0202CC90.g;
        q[0] = -(f * m[0]) / 256;
        q[1] = -(f * m[1]) / 256;
        a->velX += q[0];
        a->velZ += q[1];
        a->forceX = 0;
        a->forceZ = 0;
        a->torque = 0;
        b->velX -= q[0];
        b->velZ -= q[1];
        b->forceX = 0;
        b->forceZ = 0;
        b->torque = 0;
        f *= 1000;
        if (a->unk55 == 0)
            sub_0800BA34(0, 0, -6, 0, 0, 0, 0x400);
        if (a->unk7C < 5 || a->unk7C > 7) {
            if (gUnk_0202EEB0 != 0)
                a->damage -= f >> 12;
            if (a->damage > 40000) {
                sd = -a->speed >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    sub_0800E708(a - gCars, gUnk_0202A530 % 3);
                else
                    sub_0800E708(a - gCars, 4);
            }
            gUnk_0202A530++;
        }
        ComputeForwardSpeed(a);
        a->unk48 = a->speed;
        if (a->speed > 0)
            a->unk48 = 0;
        a->rpm = (a->unk48 << 8) / -a->unkE8[a->gear];
        if (b->unk7C < 5 || b->unk7C > 7) {
            if (gUnk_0202EEB0 != 0)
                b->damage -= f >> 14;
            if (b->damage > 40000) {
                sd = -b->speed >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    sub_0800E708(b - gCars, gUnk_0202A530 % 3);
                else
                    sub_0800E708(b - gCars, 4);
            }
            gUnk_0202A530++;
        }
        ComputeForwardSpeed(b);
        b->unk48 = b->speed;
        if (b->speed > 0)
            b->unk48 = 0;
        b->rpm = (b->unk48 << 8) / -b->unkE8[b->gear];
        if (a == gCars || b == gCars || gIsLinkRace != 0) {
            if (gUnk_020021E0 == 0 && gIsDemo == 0 && gOptions[3] != 0
                && (car == gCars || gIsLinkRace != 0)
                && a->unk55 == 0 && b->unk55 == 0)
                m4aSongNumStart(0x12);
        }
        a->unk55 = 0x10;
        b->unk55 = 0x10;
        return 1;
    }
    return 0;
}
