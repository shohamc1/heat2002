#include "global.h"
#include "data.h"
#include "variables.h"
#include "car.h"
#include "functions.h"
#include "m4a.h"

struct unk_D64C
{
    u32 a;
    u32 c;
    u8 b;
    u8 d;
    u32 g;
};
struct Coll
{
    struct Car *a;
    struct Car *c;
    u8 b;
    u8 d;
    s32 g;
};
struct Pt2
{
    s32 f0;
    s32 f1;
};

extern s32 gCarCollFrameSelf[8];
extern s32 gCarCollFrameOther[8];
extern struct Coll gCarCollContact;
extern struct Pt2 gCarCollisionNormals[];
extern u8 gUnk_0202A530;
void KeepNearestCarContact(s32 a, u8 b, s32 c, u8 d, struct unk_D64C *e, u8 *f, s32 g, s32 h);
void DummyCarHitHook(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void DummyCarDamageHook(s32 a, u8 b);
void ComputeForwardSpeed(struct Car *a);

void BuildCarCollFrame(struct Car *car, s32 *frame)
{
    s32 x, z;
    s32 v;

    v = -(car->heading >> 8) & 0xFF;
    frame[0] = gSinTable[v];
    frame[1] = gSinTable[v + 0x40];
    x = car->posX;
    frame[4] = x >> 8;
    z = car->posZ;
    frame[5] = z >> 8;
    v = car->heading + (s16)car->yawRate;
    v = -(v >> 8) & 0xFF;
    frame[2] = gSinTable[v];
    frame[3] = gSinTable[v + 0x40];
    frame[6] = (x + car->velX) >> 8;
    frame[7] = (z + car->velZ) >> 8;
}

void KeepNearestCarContact(s32 a, u8 b, s32 c, u8 d, struct unk_D64C *e, u8 *f, s32 g, s32 h)
{
    if (h < gUnk_0202CD24) {
        e->a = a;
        e->c = c;
        e->b = b;
        e->d = d;
        e->g = g;
        *f = 1;
        gUnk_0202CD24 = h;
    }
}

/*
 * Car-vs-car box collision test. For every other car within range, the
 * relative position and next-frame position are rotated into the other
 * car's frame (and the reverse), and each of the four box edges is tested
 * for a crossing. The nearest crossing (smallest time) is kept by
 * KeepNearestCarContact in gCarCollContact; after the loop the impulse is applied.
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
u8 CollideCars(struct Car *car)
{
    u8 hit;
    s32 v[4];
    s32 a2;
    u8 i;
    struct Car *other;
    s32 d[2];
    s32 px, pz;
    s32 w, u;
    s32 e, t;
    s32 *pa;
    s32 m[2];
    s32 q[2];
    u8 count;
    struct Car *a, *b;
    s32 ang, s, c, nx, nz, f;
    s32 sd;

    count = gNumCars[0];
    if (gIsLinkRace != 0)
        count = gNumLinkPlayers[0];
    if (car->finished != 0 && gIsLinkRace != 0)
        return 0;
    if (car->pitState != 0) {
        if (car == gCars)
            return 0;
        if (car->pitCollidable == 0)
            return 0;
    }
    gUnk_0202CD24 = 0x200000;
    hit = 0;
    other = gCars;
    pa = gCarCollFrameSelf;
    BuildCarCollFrame(car, pa);
    for (i = 0; i != count; i++, other++) {
        if (other == car)
            continue;
        if (other->pitState != 0) {
            if (other == gCars)
                continue;
            if (other->pitCollidable == 0)
                continue;
        }
        if (other->finished != 0 && gIsLinkRace != 0)
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
        BuildCarCollFrame(other, gCarCollFrameOther);

        d[0] = gCarCollFrameSelf[4];
        d[1] = gCarCollFrameSelf[5];
        d[0] -= gCarCollFrameOther[4];
        d[1] -= gCarCollFrameOther[5];
        v[0] = (gCarCollFrameOther[1] * d[0] - gCarCollFrameOther[0] * d[1]) >> 8;
        v[1] = (gCarCollFrameOther[0] * d[0] + gCarCollFrameOther[1] * d[1]) >> 8;
        d[0] = gCarCollFrameSelf[6];
        d[1] = gCarCollFrameSelf[7];
        d[0] -= gCarCollFrameOther[6];
        d[1] -= gCarCollFrameOther[7];
        v[2] = (gCarCollFrameOther[3] * d[0] - gCarCollFrameOther[2] * d[1]) >> 8;
        v[3] = (gCarCollFrameOther[2] * d[0] + gCarCollFrameOther[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    car, a2, other, 0, &gCarCollContact, &hit, -u, (e << 16) / -u);
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    car, a2, other, 1, &gCarCollContact, &hit, u, (e << 16) / u);
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    car, a2, other, 2, &gCarCollContact, &hit, w, (e << 16) / w);
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    car, a2, other, 3, &gCarCollContact, &hit, -w, (e << 16) / -w);
        }

        d[0] = gCarCollFrameOther[4];
        d[1] = gCarCollFrameOther[5];
        d[0] -= gCarCollFrameSelf[4];
        d[1] -= gCarCollFrameSelf[5];
        v[0] = (gCarCollFrameSelf[1] * d[0] - gCarCollFrameSelf[0] * d[1]) >> 8;
        v[1] = (gCarCollFrameSelf[0] * d[0] + gCarCollFrameSelf[1] * d[1]) >> 8;
        d[0] = gCarCollFrameOther[6];
        d[1] = gCarCollFrameOther[7];
        d[0] -= gCarCollFrameSelf[6];
        d[1] -= gCarCollFrameSelf[7];
        v[2] = (gCarCollFrameSelf[3] * d[0] - gCarCollFrameSelf[2] * d[1]) >> 8;
        v[3] = (gCarCollFrameSelf[2] * d[0] + gCarCollFrameSelf[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    other, a2, car, 0, &gCarCollContact, &hit, -u, (e << 16) / -u);
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    other, a2, car, 1, &gCarCollContact, &hit, u, (e << 16) / u);
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    other, a2, car, 2, &gCarCollContact, &hit, w, (e << 16) / w);
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ((void (*)(struct Car *, s32, struct Car *, s32, struct Coll *, u8 *, s32, s32))KeepNearestCarContact)(
                    other, a2, car, 3, &gCarCollContact, &hit, -w, (e << 16) / -w);
        }
    }

    if (hit != 0) {
        a = gCarCollContact.a;
        b = gCarCollContact.c;
        ang = b->heading >> 8;
        s = gSinTable[ang];
        c = gSinTable[ang + 0x40];
        nx = gCarCollisionNormals[gCarCollContact.d].f0;
        nz = gCarCollisionNormals[gCarCollContact.d].f1;
        m[0] = (nx * c - nz * s) >> 4;
        m[1] = (nx * s + nz * c) >> 4;
        f = -gCarCollContact.g;
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
        if (a->hitCooldown == 0)
            DummyCarHitHook(0, 0, -6, 0, 0, 0, 0x400);
        if (a->carState < 5 || a->carState > 7) {
            if (gDamagePitsEnabled != 0)
                a->damage -= f >> 12;
            if (a->damage > 40000) {
                sd = -a->speed >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    DummyCarDamageHook(a - gCars, gUnk_0202A530 % 3);
                else
                    DummyCarDamageHook(a - gCars, 4);
            }
            gUnk_0202A530++;
        }
        ComputeForwardSpeed(a);
        a->impactSpeed = a->speed;
        if (a->speed > 0)
            a->impactSpeed = 0;
        a->rpm = (a->impactSpeed << 8) / -a->gearRatioTable[a->gear];
        if (b->carState < 5 || b->carState > 7) {
            if (gDamagePitsEnabled != 0)
                b->damage -= f >> 14;
            if (b->damage > 40000) {
                sd = -b->speed >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    DummyCarDamageHook(b - gCars, gUnk_0202A530 % 3);
                else
                    DummyCarDamageHook(b - gCars, 4);
            }
            gUnk_0202A530++;
        }
        ComputeForwardSpeed(b);
        b->impactSpeed = b->speed;
        if (b->speed > 0)
            b->impactSpeed = 0;
        b->rpm = (b->impactSpeed << 8) / -b->gearRatioTable[b->gear];
        if (a == gCars || b == gCars || gIsLinkRace != 0) {
            if (gRaceEndState == 0 && gIsDemo == 0 && gOptions[3] != 0 && (car == gCars || gIsLinkRace != 0) &&
                a->hitCooldown == 0 && b->hitCooldown == 0)
                m4aSongNumStart(0x12);
        }
        a->hitCooldown = 0x10;
        b->hitCooldown = 0x10;
        return 1;
    }
    return 0;
}
