/*
 * sub_0800D248 quarantine notes (2026-09-14, F4)
 * Best build: 868/908 bytes. The loop body, MIN/MAX chains, 64-bit math
 * (t = muldi3(f4,unk04) + muldi3(f5,unk08); t = t*192>>8 [NOT >>34:
 * GCC keeps <<6 and >>8 separate]; clamp `if (t > -0x80000000LL)`;
 * >>29 products; return t>>7), the s16-table tail, and the CD38 call
 * (args corner/sp+8, out=&boxes[4], boxes, &res, tile, &best) all match
 * instruction-for-instruction after masking register names.
 * MIN/MAX macros must be called with the ROM's operand order:
 *   MIN(corner[i].f[2], corner[i].f[0]) — GCC 2.95 loads the SECOND
 *   macro operand first for `a < b ? a : b`, and the ROM loads f0 first.
 * In-loop store pattern is [min][i*0x10+slot addr][asrs #16][str];
 * the direct `boxes[i].w = MIN(..) >> 16` form computes the address
 * FIRST (wrong); `m = MIN(..); boxes[i].w = m >> 16;` gives the right
 * order but changes the box addressing to walkers.
 * Remaining blockers (all one allocation web in the setup block):
 *  - ROM: i->ip(r12), corner-walker->r8, byte-offset-walker->r9,
 *    &boxes[0].w0 spilled to slot 0xFC (16 pointer slots, frame 0x118).
 *    Ours: i->r9, walker->r7, offset->r8, w0 in ip (15 slots, 0x114).
 *    Pinning i to r12 explodes (loses strength reduction, 988 bytes).
 *  - ROM setup computes &boxes[0] as `adds r6,#0x58` chained off the
 *    live f2 pseudo (sp+0x10), out as `adds r2,#0x90` off f4, best as
 *    `adds r3,#0xB0` off f5, res as `adds r6,#0x50` off w0 — source-
 *    level pointer arithmetic we could not reconstruct; ours uses fresh
 *    `add rX, sp, #N`.
 * out = &boxes[4] (NOT &boxes[3].unk04): chains write boxes[4].w0..w3
 * and CD38 gets a2=out. Struct Ent pads: unk34/36/38/3A/3C u16s,
 * pad3E[0x7C-0x3E], unk7C, pad7D[0xA4-0x7D], unkA4/B4/C4/D4[4],
 * padE4[0x12C-0xE4], unk12C.
 */
#include "global.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Ent {
    u8 pad00[0x0C];
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x34 - 0x18];
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u8 pad3E[0x7C - 0x3E];
    u8 unk7C;
    u8 pad7D[0xA4 - 0x7D];
    s32 unkA4[4];
    s32 unkB4[4];
    s32 unkC4[4];
    s32 unkD4[4];
    u8 padE4[0x12C - 0xE4];
    s32 unk12C;
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

extern s16 gUnk_0801CD08[];
extern s32 gUnk_0202CC4C;
extern s32 gUnk_0202CC50[];
extern s32 gUnk_0202CC64;
extern s32 gUnk_0202CC70;

u16 *sub_0800CC98(s32 x, s32 y);
void sub_0800CD38(struct Corner *a1, struct Box *a2, struct Box *a3,
                  struct Res *a4, u16 *a5, s32 *a6);
void sub_0800B614(s32 a, s32 b);

s32 sub_0800D248(struct Ent *a)
{
    struct Corner corner[4];
    struct Box boxes[5];
    struct Res res;
    s32 best;
    long long t;
    struct Box *out;
    u16 *tile;
    s32 i;
    u8 j;
    s32 v;
    s32 d0;
    s32 d1;

    if (a->unk7C == 1)
        return 0;
    for (i = 0; i != 4; i++) {
        corner[i].f[0] = a->unkA4[i];
        corner[i].f[1] = a->unkB4[i];
        corner[i].f[2] = a->unkC4[i];
        corner[i].f[3] = a->unkD4[i];
        corner[i].f[4] = corner[i].f[2] - corner[i].f[0];
        corner[i].f[5] = corner[i].f[3] - corner[i].f[1];
        boxes[i].unk00 = MIN(corner[i].f[2], corner[i].f[0]) >> 16;
        boxes[i].unk08 = MIN(corner[i].f[3], corner[i].f[1]) >> 16;
        boxes[i].unk04 = MAX(corner[i].f[2], corner[i].f[0]) >> 16;
        boxes[i].unk0C = MAX(corner[i].f[3], corner[i].f[1]) >> 16;
    }
    out = &boxes[4];
    out->unk00 = MIN(boxes[0].unk00, boxes[1].unk00);
    out->unk00 = MIN(out->unk00, boxes[2].unk00);
    out->unk00 = MIN(out->unk00, boxes[3].unk00);
    out->unk08 = MIN(boxes[0].unk08, boxes[1].unk08);
    out->unk08 = MIN(out->unk08, boxes[2].unk08);
    out->unk08 = MIN(out->unk08, boxes[3].unk08);
    out->unk04 = MAX(boxes[0].unk04, boxes[1].unk04);
    out->unk04 = MAX(out->unk04, boxes[2].unk04);
    out->unk04 = MAX(out->unk04, boxes[3].unk04);
    out->unk0C = MAX(boxes[0].unk0C, boxes[1].unk0C);
    out->unk0C = MAX(out->unk0C, boxes[2].unk0C);
    out->unk0C = MAX(out->unk0C, boxes[3].unk0C);
    tile = sub_0800CC98(corner[0].f[0] >> 16, corner[0].f[1] >> 16);
    best = 99999;
    sub_0800CD38(corner, out, boxes, &res, tile, &best);
    if (best == 99999)
        return 0;
    j = res.unk0C;
    t = (long long)corner[j].f[4] * res.unk04 + (long long)corner[j].f[5] * res.unk08;
    t = t * 192 >> 8;
    if (t > -0x80000000LL)
        t = -0x80000000LL;
    d0 = ((long long)res.unk04 * t) >> 29;
    d1 = ((long long)res.unk08 * t) >> 29;
    gUnk_0202CC70 = a->unk0C;
    gUnk_0202CC64 = a->unk14;
    gUnk_0202CC4C = t;
    gUnk_0202CC50[1] = res.unk04;
    gUnk_0202CC50[2] = res.unk08;
    a->unk0C -= d0;
    a->unk14 -= d1;
    sub_0800B614(a->unkA4[j], a->unkB4[j]);
    v = res.unk0D;
    {
        s32 v1 = gUnk_0801CD08[res.unk0D];
        s32 v2 = gUnk_0801CD08[res.unk0D + 0x40];
        s32 ang = a->unk34 >> 8;
        s32 v3 = gUnk_0801CD08[ang];
        s32 v4 = gUnk_0801CD08[ang + 0x40];

        if (v3 * v1 + v4 * v2 <= 0)
            v = res.unk0E;
        a->unk12C = v << 8;
        a->unk3C += (s16)((v << 8) - a->unk34) >> 4;
    }
    return t >> 7;
}
