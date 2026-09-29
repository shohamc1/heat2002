#include "global.h"
#include "functions.h"
#include "variables.h"

struct WallRec
{
    u16 vertex0;   /* index into gWallVertices */
    u16 vertex1;   /* 0x02 */
    s32 normalX;   /* 0x04: 1.15 unit normal of the wall segment */
    s32 normalZ;   /* 0x08 */
    s32 minX;      /* 0x0C: segment AABB */
    s32 maxX;      /* 0x10 */
    s32 minZ;      /* 0x14 */
    s32 maxZ;      /* 0x18 */
    u8 steerAngle;    /* 0x1C: post-hit steer heading, gSinTable index */
    u8 steerAngleOpp; /* 0x1D: +0x80, used when heading opposes it */
    u8 unk1E;         /* 0x1E */
};

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
    u8 pad00[4];   /* 0x00 */
    s32 normalX;   /* 0x04: wall normal, slightly amplified */
    s32 normalZ;   /* 0x08 */
    u8 cornerIndex;    /* 0x0C: which car corner hit */
    u8 steerAngle;     /* 0x0D */
    u8 steerAngleOpp;  /* 0x0E */
    u8 unk0F;          /* 0x0F */
    s32 unk10;         /* 0x10: winning wall index (write-only) */
};

struct Pt
{
    s32 x;
    s32 y;
};

s32 ModuleTestCornersVsWalls(struct Corner *corn, struct Box *box, struct Box *cbox, struct Hit *out, u16 *wallList,
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
    s32 det;

    for (w = wallList; *w != 0xFFFF; w = wnext) {
        wall = &gModule_Walls[*w];
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
        pax = gModule_WallVertices[wall->vertex0].x;
        pay = gModule_WallVertices[wall->vertex0].y;
        pbx = gModule_WallVertices[wall->vertex1].x;
        pby = gModule_WallVertices[wall->vertex1].y;
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
            gUnk_020375B0 = pax;
            gUnk_020375B4 = pay;
            gUnk_020375B8 = pbx;
            gUnk_020375BC = pby;
            gUnk_020375A0 = x1 = pc->xHi;
            gUnk_020375A4 = y1 = pc->zHi;
            gUnk_020375A8 = x2 = pc->nextXHi;
            gUnk_020375AC = y2 = pc->nextZHi;
            gUnk_020375C0 = det = (x2 - x1) * (pby - pay) - (y2 - y1) * (pbx - pax);
            if (det == 0)
                continue;
            gUnk_020375C8 = ((y1 - pay) * (pbx - pax) - (x1 - pax) * (pby - pay)) << 8;
            t1 = sub_08344BB8(((y1 - pay) * (pbx - pax) - (x1 - pax) * (pby - pay)) << 8, det);
            gUnk_020375C8 = t1;
            lim = 0x100;
            if (t1 > lim)
                continue;
            gUnk_020375C4 = ((x2 - x1) * (y1 - pay) - (y2 - y1) * (x1 - pax)) << 8;
            t2 = sub_08344BB8(((x2 - x1) * (y1 - pay) - (y2 - y1) * (x1 - pax)) << 8, det);
            gUnk_020375C4 = t2;
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
