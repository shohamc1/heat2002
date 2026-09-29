#include "global.h"
#include "variables.h"
#include "car.h"

/*
 * Car-vs-track box collision: the high-region (0x0834 module) copy of
 * sub_0800D248, instruction-identical, ported from that matched source.
 * Its `__muldi3` libcalls resolve to the module copy through the Makefile
 * rename for src/sub_083[3-9]*.c objects.
 * Builds the four corner boxes and their union,
 * runs the tile test, then applies the impulse and steering correction.
 *
 * Shapes the retail bytes depend on:
 * - min_08343DE0/max_08343DEC are `inline` min/max helpers written as
 *   `r = b; if (a < b) r = a;` (the ternary folds to MIN_EXPR and flips the
 *   compare). Being non-static inline, GCC also emits them out of line
 *   after the function: the 24 bytes at 0x08343DE0..0x08343DF8.
 * - `total` is a separate struct, not boxes[4]: its address is a PRE'd
 *   pseudo with no register, so reload keeps it in r7 across the chains.
 * - `d0`/`d1` are long long: the dead high half of each product keeps r5
 *   busy through the global stores, which is what pushes reload to r6/r7.
 * - `v` is assigned after the table lookups (CSE reuses the byte load), and
 *   the steering delta is computed in `v` itself with `<< 16` then `>>= 20`.
 * - gcse's PRE pass numbers the 16 hoisted address pseudos in hash-bucket
 *   order, and the table size is (real insns / 2) | 1. The spill-slot order
 *   therefore depends on the pre-gcse insn count: 358 or 359 here. The
 *   early `return 0`, the `u8 ang`, and the `s16` parameters on
 *   ModuleGetWallListAt each add two insns that vanish later; without them the
 *   slots come out permuted.
 */

struct Ent
{
    u8 pad00[0x0C];
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x34 - 0x18];
    u16 unk34;
    u16 respawnHeading;
    u16 respawnWaypoint;
    u16 unk3A;
    u16 unk3C;
    u8 pad3E[0x7C - 0x3E];
    u8 carState;
    u8 pad7D[0xA4 - 0x7D];
    s32 cornerX[4];
    s32 cornerZ[4];
    s32 nextCornerX[4];
    s32 nextCornerZ[4];
    u8 padE4[0x12C - 0xE4];
    s32 steerHeading;
};
struct Corner
{ s32 f[6]; };
struct Box
{
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
};
struct Res
{
    u8 pad00[4];
    s32 unk04;
    s32 unk08;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
    s32 unk10;
};
u16 *ModuleGetWallListAt(s16 x, s16 y);
void ModuleTestCornersVsWalls(struct Corner *a1, struct Box *a2, struct Box *a3, struct Res *a4, u16 *a5, s32 *a6);
void ModuleDummyWallHitHook(s32 a, s32 b);
struct Unk08343DF8
{
    s32 unk00;
    u8 pad04[4];
    s32 unk08;
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x34 - 0x18];
    u16 unk34;
    u8 pad36[0x3C - 0x36];
    s16 unk3C;
};
/*
 * Car-vs-car box collision test: the high-region (0x0834 module) copy of
 * sub_0800D684, byte-identical in instruction stream and ported from that
 * matched source with the module's globals and callees. See
 * src/sub_0800D684.c for the shapes the retail bytes depend on.
 *
 * The `/` and `%` here must stay operators: the module links its own
 * libgcc copy (sub_08344BB8, sub_08344DA8), and the Makefile renames the
 * libcall symbols for src/sub_083[3-9]*.c objects. Calling sub_08344BB8
 * directly loses the libcall's hard-r0 return and flips the allocation.
 */
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
extern s32 gModule_CarCollFrameSelf[8];
extern s32 gModule_CarCollFrameOther[8];
extern struct Coll gUnk_0203DEB0;
extern struct Pt2 gUnk_0202AF08[];
extern u8 gUnk_0203D4FC;
void ModuleKeepNearestCarContact(struct Car *a, s32 b, struct Car *c, s32 d, struct Coll *e, u8 *f, s32 g, s32 h);
void ModuleDummyCarHitHook(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void ModuleDummyCarDamageHook(s32 carIdx, u8 damageStage);
void ModuleComputeForwardSpeed(struct Car *a);
void ModuleM4aSongNumStart(u16 idx);

u8 ModuleCollideCars(struct Car *car)
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

    count = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        count = gModule_NumLinkPlayers[0];
    if (car->finished != 0 && gModule_IsLinkRace != 0)
        return 0;
    if (car->pitState != 0) {
        if (car == gModule_Cars)
            return 0;
        if (car->pitCollidable == 0)
            return 0;
    }
    gUnk_0203DF44 = 0x200000;
    hit = 0;
    other = gModule_Cars;
    pa = gModule_CarCollFrameSelf;
    ModuleBuildCarCollFrame(car, pa);
    for (i = 0; i != count; i++, other++) {
        if (other == car)
            continue;
        if (other->pitState != 0) {
            if (other == gModule_Cars)
                continue;
            if (other->pitCollidable == 0)
                continue;
        }
        if (other->finished != 0 && gModule_IsLinkRace != 0)
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
        ModuleBuildCarCollFrame(other, gModule_CarCollFrameOther);

        d[0] = gModule_CarCollFrameSelf[4];
        d[1] = gModule_CarCollFrameSelf[5];
        d[0] -= gModule_CarCollFrameOther[4];
        d[1] -= gModule_CarCollFrameOther[5];
        v[0] = (gModule_CarCollFrameOther[1] * d[0] - gModule_CarCollFrameOther[0] * d[1]) >> 8;
        v[1] = (gModule_CarCollFrameOther[0] * d[0] + gModule_CarCollFrameOther[1] * d[1]) >> 8;
        d[0] = gModule_CarCollFrameSelf[6];
        d[1] = gModule_CarCollFrameSelf[7];
        d[0] -= gModule_CarCollFrameOther[6];
        d[1] -= gModule_CarCollFrameOther[7];
        v[2] = (gModule_CarCollFrameOther[3] * d[0] - gModule_CarCollFrameOther[2] * d[1]) >> 8;
        v[3] = (gModule_CarCollFrameOther[2] * d[0] + gModule_CarCollFrameOther[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ModuleKeepNearestCarContact(car, a2, other, 0, &gUnk_0203DEB0, &hit, -u, (e << 16) / -u);
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ModuleKeepNearestCarContact(car, a2, other, 1, &gUnk_0203DEB0, &hit, u, (e << 16) / u);
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ModuleKeepNearestCarContact(car, a2, other, 2, &gUnk_0203DEB0, &hit, w, (e << 16) / w);
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ModuleKeepNearestCarContact(car, a2, other, 3, &gUnk_0203DEB0, &hit, -w, (e << 16) / -w);
        }

        d[0] = gModule_CarCollFrameOther[4];
        d[1] = gModule_CarCollFrameOther[5];
        d[0] -= gModule_CarCollFrameSelf[4];
        d[1] -= gModule_CarCollFrameSelf[5];
        v[0] = (gModule_CarCollFrameSelf[1] * d[0] - gModule_CarCollFrameSelf[0] * d[1]) >> 8;
        v[1] = (gModule_CarCollFrameSelf[0] * d[0] + gModule_CarCollFrameSelf[1] * d[1]) >> 8;
        d[0] = gModule_CarCollFrameOther[6];
        d[1] = gModule_CarCollFrameOther[7];
        d[0] -= gModule_CarCollFrameSelf[6];
        d[1] -= gModule_CarCollFrameSelf[7];
        v[2] = (gModule_CarCollFrameSelf[3] * d[0] - gModule_CarCollFrameSelf[2] * d[1]) >> 8;
        v[3] = (gModule_CarCollFrameSelf[2] * d[0] + gModule_CarCollFrameSelf[3] * d[1]) >> 8;
        w = v[2] - v[0];
        u = v[3] - v[1];
        if (u < 0 && v[3] <= 0x1C00 && (e = v[1] - 0x1C00) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ModuleKeepNearestCarContact(other, a2, car, 0, &gUnk_0203DEB0, &hit, -u, (e << 16) / -u);
        }
        if (u > 0 && v[3] >= -0x1C00 && (e = -0x1C00 - v[1]) >= 0) {
            t = (w * e) / u;
            t += v[0];
            if (t >= -0xF00 && t <= 0xF00)
                ModuleKeepNearestCarContact(other, a2, car, 1, &gUnk_0203DEB0, &hit, u, (e << 16) / u);
        }
        if (w > 0 && v[2] >= -0xF00 && (e = -0xF00 - v[0]) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ModuleKeepNearestCarContact(other, a2, car, 2, &gUnk_0203DEB0, &hit, w, (e << 16) / w);
        }
        if (w < 0 && v[2] <= 0xF00 && (e = v[0] - 0xF00) >= 0) {
            t = (e * u) / w;
            t += v[1];
            if (t >= -0x1C00 && t <= 0x1C00)
                ModuleKeepNearestCarContact(other, a2, car, 3, &gUnk_0203DEB0, &hit, -w, (e << 16) / -w);
        }
    }

    if (hit != 0) {
        a = gUnk_0203DEB0.a;
        b = gUnk_0203DEB0.c;
        ang = b->heading >> 8;
        s = gModule_SinTable[ang];
        c = gModule_SinTable[ang + 0x40];
        nx = gUnk_0202AF08[gUnk_0203DEB0.d].f0;
        nz = gUnk_0202AF08[gUnk_0203DEB0.d].f1;
        m[0] = (nx * c - nz * s) >> 4;
        m[1] = (nx * s + nz * c) >> 4;
        f = -gUnk_0203DEB0.g;
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
            ModuleDummyCarHitHook(0, 0, -6, 0, 0, 0, 0x400);
        if (a->carState < 5 || a->carState > 7) {
            if (gModule_DamagePitsEnabled != 0)
                a->damage -= f >> 12;
            if (a->damage > 40000) {
                sd = -a->speed >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    ModuleDummyCarDamageHook(a - gModule_Cars, gUnk_0203D4FC % 3);
                else
                    ModuleDummyCarDamageHook(a - gModule_Cars, 4);
            }
            gUnk_0203D4FC++;
        }
        ModuleComputeForwardSpeed(a);
        a->impactSpeed = a->speed;
        if (a->speed > 0)
            a->impactSpeed = 0;
        a->rpm = (a->impactSpeed << 8) / -a->gearRatioTable[a->gear];
        if (b->carState < 5 || b->carState > 7) {
            if (gModule_DamagePitsEnabled != 0)
                b->damage -= f >> 14;
            if (b->damage > 40000) {
                sd = -b->speed >> 12;
                if (sd < 0)
                    sd = 0;
                if (sd > 50)
                    ModuleDummyCarDamageHook(b - gModule_Cars, gUnk_0203D4FC % 3);
                else
                    ModuleDummyCarDamageHook(b - gModule_Cars, 4);
            }
            gUnk_0203D4FC++;
        }
        ModuleComputeForwardSpeed(b);
        b->impactSpeed = b->speed;
        if (b->speed > 0)
            b->impactSpeed = 0;
        b->rpm = (b->impactSpeed << 8) / -b->gearRatioTable[b->gear];
        if (a == gModule_Cars || b == gModule_Cars || gModule_IsLinkRace != 0) {
            if (gModule_RaceEndState == 0 && gModule_IsDemo[0] == 0 && gModule_Options[3] != 0 &&
                (car == gModule_Cars || gModule_IsLinkRace != 0) && a->hitCooldown == 0 && b->hitCooldown == 0)
                ModuleM4aSongNumStart(0x12);
        }
        a->hitCooldown = 0x10;
        b->hitCooldown = 0x10;
        return 1;
    }
    return 0;
}

void ModuleDummyCarDamageHook(s32 carIdx, u8 damageStage)
{}
