#include "global.h"
#include "data.h"

/*
 * Car-vs-track box collision. Builds the four corner boxes and their union,
 * runs the tile test, then applies the impulse and steering correction.
 *
 * Shapes the retail bytes depend on:
 * - Min/Max are `inline` min/max helpers written as
 *   `r = b; if (a < b) r = a;` (the ternary folds to MIN_EXPR and flips the
 *   compare). Being non-static inline (GNU89), GCC also emits them out of
 *   line after the function: the 24 bytes at 0x0800D5BC..0x0800D5D4.
 *   Nothing in the ROM calls those copies.
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
 *   GetWallListAt each add two insns that vanish later; without them the
 *   slots come out permuted.
 */

struct Car
{
    u8 pad00[0x0C];
    s32 velX;
    u8 pad10[4];
    s32 velZ;
    u8 pad18[0x34 - 0x18];
    u16 heading;
    u16 respawnHeading;
    u16 respawnWaypoint;
    u16 unk3A;
    u16 yawRate;
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
{
    s32 x;      /* 0x00: cornerX, 16.16 */
    s32 z;      /* 0x04: cornerZ */
    s32 nextX;  /* 0x08: nextCornerX */
    s32 nextZ;  /* 0x0C: nextCornerZ */
    s32 deltaX; /* 0x10: nextX - x */
    s32 deltaZ; /* 0x14 */
};

struct Box
{
    s32 minX; /* 0x00: corner-sweep AABB, world units */
    s32 maxX; /* 0x04 */
    s32 minZ; /* 0x08 */
    s32 maxZ; /* 0x0C */
};

struct Hit
{
    u8 pad00[4];   /* 0x00 */
    s32 normalX;   /* 0x04 */
    s32 normalZ;   /* 0x08 */
    u8 cornerIndex;    /* 0x0C */
    u8 steerAngle;     /* 0x0D */
    u8 steerAngleOpp;  /* 0x0E */
    u8 unk0F;          /* 0x0F */
    s32 unk10;         /* 0x10 */
};

extern s32 gUnk_0202CC4C;
extern s32 gWallCollisionNormal[];
extern s32 gUnk_0202CC64;
extern s32 gUnk_0202CC70;

u16 *GetWallListAt(s16 x, s16 y);
void TestCornersVsWalls(struct Corner *a1, struct Box *a2, struct Box *a3, struct Hit *a4, u16 *a5, s32 *a6);
void DummyWallHitHook(s32 a, s32 b);

inline s32 Min(s32 a, s32 b)
{
    s32 r = b;
    if (a < b)
        r = a;
    return r;
}

inline s32 Max(s32 a, s32 b)
{
    s32 r = b;
    if (a > b)
        r = a;
    return r;
}

s32 CollideCarWithWalls(struct Car *a)
{
    struct Corner corner[4];
    struct Box boxes[4];
    struct Box total;
    struct Hit res;
    s32 best;
    long long t;
    u16 *tile;
    s32 i;
    s32 v;
    long long d0;
    long long d1;

    if (a->carState == 1)
        return 0;
    {
        for (i = 0; i != 4; i++) {
            corner[i].x = a->cornerX[i];
            corner[i].z = a->cornerZ[i];
            corner[i].nextX = a->nextCornerX[i];
            corner[i].nextZ = a->nextCornerZ[i];
            corner[i].deltaX = a->nextCornerX[i] - a->cornerX[i];
            corner[i].deltaZ = a->nextCornerZ[i] - a->cornerZ[i];
            boxes[i].minX = Min(corner[i].x, corner[i].nextX) >> 16;
            boxes[i].minZ = Min(corner[i].z, corner[i].nextZ) >> 16;
            boxes[i].maxX = Max(corner[i].x, corner[i].nextX) >> 16;
            boxes[i].maxZ = Max(corner[i].z, corner[i].nextZ) >> 16;
        }
        total.minX = Min(boxes[0].minX, boxes[1].minX);
        total.minX = Min(total.minX, boxes[2].minX);
        total.minX = Min(total.minX, boxes[3].minX);
        total.minZ = Min(boxes[0].minZ, boxes[1].minZ);
        total.minZ = Min(total.minZ, boxes[2].minZ);
        total.minZ = Min(total.minZ, boxes[3].minZ);
        total.maxX = Max(boxes[0].maxX, boxes[1].maxX);
        total.maxX = Max(total.maxX, boxes[2].maxX);
        total.maxX = Max(total.maxX, boxes[3].maxX);
        total.maxZ = Max(boxes[0].maxZ, boxes[1].maxZ);
        total.maxZ = Max(total.maxZ, boxes[2].maxZ);
        total.maxZ = Max(total.maxZ, boxes[3].maxZ);
        tile = GetWallListAt(corner[0].x >> 16, corner[0].z >> 16);
        best = 99999;
        TestCornersVsWalls(corner, &total, boxes, &res, tile, &best);
        if (best != 99999) {
            t = (long long)corner[res.cornerIndex].deltaX * res.normalX + (long long)corner[res.cornerIndex].deltaZ * res.normalZ;
            t = t * 192 >> 8;
            if (t > -0x80000000LL)
                t = -0x80000000LL;
            d0 = ((long long)res.normalX * t) >> 29;
            d1 = ((long long)res.normalZ * t) >> 29;
            gUnk_0202CC70 = a->velX;
            gUnk_0202CC64 = a->velZ;
            gUnk_0202CC4C = t;
            gWallCollisionNormal[1] = res.normalX;
            gWallCollisionNormal[2] = res.normalZ;
            a->velX -= d0;
            a->velZ -= d1;
            DummyWallHitHook(a->cornerX[res.cornerIndex], a->cornerZ[res.cornerIndex]);
            {
                s32 v1 = gSinTable[res.steerAngle];
                s32 v2 = gSinTable[res.steerAngle + 0x40];
                u8 ang = a->heading >> 8;
                s32 v3 = gSinTable[ang];
                s32 v4 = gSinTable[ang + 0x40];

                v = res.steerAngle;
                if (v3 * v1 + v4 * v2 <= 0)
                    v = res.steerAngleOpp;
                a->steerHeading = v << 8;
                v = ((v << 8) - a->heading) << 16;
                v >>= 20;
                a->yawRate += v;
            }
            return t >> 7;
        }
    }
    return 0;
}
