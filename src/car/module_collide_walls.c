#include "global.h"
#include "variables.h"

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

inline s32 min_08343DE0(s32 a, s32 b)
{
    s32 r = b;
    if (a < b)
        r = a;
    return r;
}

inline s32 max_08343DEC(s32 a, s32 b)
{
    s32 r = b;
    if (a > b)
        r = a;
    return r;
}

struct Ent {
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

struct Corner {
    s32 f[6];
};

struct Box {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
};

struct Res {
    u8 pad00[4];
    s32 unk04;
    s32 unk08;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
    s32 unk10;
};

extern s32 gUnk_0203DE6C;
extern s32 gUnk_0203DE70[];
extern s32 gUnk_0203DE84;
extern s32 gUnk_0203DE90;

u16 *ModuleGetWallListAt(s16 x, s16 y);
void ModuleTestCornersVsWalls(struct Corner *a1, struct Box *a2, struct Box *a3,
                  struct Res *a4, u16 *a5, s32 *a6);
void ModuleDummyWallHitHook(s32 a, s32 b);

s32 ModuleCollideCarWithWalls(struct Ent *a)
{
    struct Corner corner[4];
    struct Box boxes[4];
    struct Box total;
    struct Res res;
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
            corner[i].f[0] = a->cornerX[i];
            corner[i].f[1] = a->cornerZ[i];
            corner[i].f[2] = a->nextCornerX[i];
            corner[i].f[3] = a->nextCornerZ[i];
            corner[i].f[4] = a->nextCornerX[i] - a->cornerX[i];
            corner[i].f[5] = a->nextCornerZ[i] - a->cornerZ[i];
            boxes[i].unk00 = min_08343DE0(corner[i].f[0], corner[i].f[2]) >> 16;
            boxes[i].unk08 = min_08343DE0(corner[i].f[1], corner[i].f[3]) >> 16;
            boxes[i].unk04 = max_08343DEC(corner[i].f[0], corner[i].f[2]) >> 16;
            boxes[i].unk0C = max_08343DEC(corner[i].f[1], corner[i].f[3]) >> 16;
        }
        total.unk00 = min_08343DE0(boxes[0].unk00, boxes[1].unk00);
        total.unk00 = min_08343DE0(total.unk00, boxes[2].unk00);
        total.unk00 = min_08343DE0(total.unk00, boxes[3].unk00);
        total.unk08 = min_08343DE0(boxes[0].unk08, boxes[1].unk08);
        total.unk08 = min_08343DE0(total.unk08, boxes[2].unk08);
        total.unk08 = min_08343DE0(total.unk08, boxes[3].unk08);
        total.unk04 = max_08343DEC(boxes[0].unk04, boxes[1].unk04);
        total.unk04 = max_08343DEC(total.unk04, boxes[2].unk04);
        total.unk04 = max_08343DEC(total.unk04, boxes[3].unk04);
        total.unk0C = max_08343DEC(boxes[0].unk0C, boxes[1].unk0C);
        total.unk0C = max_08343DEC(total.unk0C, boxes[2].unk0C);
        total.unk0C = max_08343DEC(total.unk0C, boxes[3].unk0C);
        tile = ModuleGetWallListAt(corner[0].f[0] >> 16, corner[0].f[1] >> 16);
        best = 99999;
        ModuleTestCornersVsWalls(corner, &total, boxes, &res, tile, &best);
        if (best != 99999) {
        t = (long long)corner[res.unk0C].f[4] * res.unk04 + (long long)corner[res.unk0C].f[5] * res.unk08;
        t = t * 192 >> 8;
        if (t > -0x80000000LL)
            t = -0x80000000LL;
        d0 = ((long long)res.unk04 * t) >> 29;
        d1 = ((long long)res.unk08 * t) >> 29;
        gUnk_0203DE90 = a->unk0C;
        gUnk_0203DE84 = a->unk14;
        gUnk_0203DE6C = t;
        gUnk_0203DE70[1] = res.unk04;
        gUnk_0203DE70[2] = res.unk08;
        a->unk0C -= d0;
        a->unk14 -= d1;
        ModuleDummyWallHitHook(a->cornerX[res.unk0C], a->cornerZ[res.unk0C]);
        {
            s32 v1 = gModule_SinTable[res.unk0D];
            s32 v2 = gModule_SinTable[res.unk0D + 0x40];
            u8 ang = a->unk34 >> 8;
            s32 v3 = gModule_SinTable[ang];
            s32 v4 = gModule_SinTable[ang + 0x40];

            v = res.unk0D;
            if (v3 * v1 + v4 * v2 <= 0)
                v = res.unk0E;
            a->steerHeading = v << 8;
            v = ((v << 8) - a->unk34) << 16;
        v >>= 20;
        a->unk3C += v;
        }
        return t >> 7;
        }
    }
    return 0;
}
