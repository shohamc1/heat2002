#include "global.h"
#include "functions.h"
#include "variables.h"

struct Box
{
    s32 minX; /* 0x00: corner-sweep AABB, world units */
    s32 maxX; /* 0x04 */
    s32 minZ; /* 0x08 */
    s32 maxZ; /* 0x0C */
};

struct Corner
{
    u16 unk00;   /* low half of x */
    s16 xHi;     /* 0x02: current X, world units */
    u16 unk04;   /* 0x04 */
    s16 zHi;     /* 0x06: current Z */
    u16 unk08;   /* 0x08 */
    s16 nextXHi; /* 0x0A: next-frame X */
    u16 unk0C;   /* 0x0C */
    s16 nextZHi; /* 0x0E: next-frame Z */
    s32 deltaX;  /* 0x10: nextCornerX - cornerX */
    s32 deltaZ;  /* 0x14 */
};

struct Hit
{
    u8 pad00[4];      /* 0x00 */
    s32 normalX;      /* 0x04: wall normal, slightly amplified */
    s32 normalZ;      /* 0x08 */
    u8 cornerIndex;   /* 0x0C: which car corner hit */
    u8 steerAngle;    /* 0x0D */
    u8 steerAngleOpp; /* 0x0E */
    u8 unk0F;         /* 0x0F */
    s32 unk10;        /* 0x10: winning wall index (write-only) */
};

s32 TestCornersVsWalls(struct Corner *corn, struct Box *box, struct Box *cbox, struct Hit *out, u16 *wallList,
                       s32 *best)
{
    s32 tmp[4];
    s32 pax, pay, pbx, pby;
    struct Corner *pc;
    struct Box *pq;
    s32 i;
    u16 *w;
    u16 *wnext;
    u32 lim;
    struct WallRec *wall;
    s32 x, y;
    s32 t1, t2;
    s32 x1, y1, x2, y2;

    for (w = wallList; *w != 0xFFFF; w = wnext) {
        wall = &gWalls[*w];
        x = box->minX;
        y = wall->maxX;
        wnext = w + 1;
        if (x > y)
            continue;
        if (box->minZ > wall->maxZ)
            continue;
        if (box->maxX < wall->minX)
            continue;
        if (box->maxZ < wall->minZ)
            continue;
        pax = gWallVertices[wall->vertex0].x;
        pay = gWallVertices[wall->vertex0].y;
        pbx = gWallVertices[wall->vertex1].x;
        pby = gWallVertices[wall->vertex1].y;
        pc = corn;
        pq = cbox;
        for (i = 0; i != 4; i++, pc++, pq++) {
            if (pq->minX > wall->maxX + 1)
                continue;
            if (pq->minZ > wall->maxZ + 1)
                continue;
            if (pq->maxX < wall->minX - 1)
                continue;
            if (pq->maxZ < wall->minZ - 1)
                continue;
            if ((pc->deltaX >> 8) * wall->normalX + (pc->deltaZ >> 8) * wall->normalZ > 0)
                continue;
            gUnk_02000470 = pax;
            gUnk_02000474 = pay;
            gUnk_02000478 = pbx;
            gUnk_0200047C = pby;
            gUnk_02000460 = x1 = pc->xHi;
            gUnk_02000464 = y1 = pc->zHi;
            gUnk_02000468 = x2 = pc->nextXHi;
            gUnk_0200046C = y2 = pc->nextZHi;
            gUnk_02000480 = (x2 - x1) * (pby - pay) - (y2 - y1) * (pbx - pax);
            if (gUnk_02000480 == 0)
                continue;
            gUnk_02000488 = ((y1 - pay) * (pbx - pax) - (x1 - pax) * (pby - pay)) << 8;
            t1 = (((y1 - pay) * (pbx - pax) - (x1 - pax) * (pby - pay)) << 8) / gUnk_02000480;
            gUnk_02000488 = t1;
            lim = 0x100;
            if (t1 > lim)
                continue;
            gUnk_02000484 = ((x2 - x1) * (y1 - pay) - (y2 - y1) * (x1 - pax)) << 8;
            t2 = (((x2 - x1) * (y1 - pay) - (y2 - y1) * (x1 - pax)) << 8) / gUnk_02000480;
            gUnk_02000484 = t2;
            if (t2 > lim)
                continue;
            if (t1 < *best) {
                *best = t2;
                out->normalX = (wall->normalX * 0x104) >> 8;
                out->normalZ = (wall->normalZ * 0x104) >> 8;
                out->steerAngle = wall->steerAngle;
                out->steerAngleOpp = wall->steerAngleOpp;
                out->unk0F = wall->unk1E;
                out->unk10 = *w;
                out->cornerIndex = (u8)i;
            }
        }
    }
}
