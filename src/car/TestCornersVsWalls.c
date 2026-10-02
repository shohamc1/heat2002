#include "global.h"
#include "functions.h"
#include "variables.h"
#include "gba/defines.h"

/* The eleven s32 wall-test scratch values occupy 0x02000460-0x0200048C.
.bss_TestCornersVsWalls places them before the MultiBoot library BSS. */
EWRAM_DATA s32 gUnk_02000460 = 0;
EWRAM_DATA s32 gUnk_02000464 = 0;
EWRAM_DATA s32 gUnk_02000468 = 0;
EWRAM_DATA s32 gUnk_0200046C = 0;
EWRAM_DATA s32 gUnk_02000470 = 0;
EWRAM_DATA s32 gUnk_02000474 = 0;
EWRAM_DATA s32 gUnk_02000478 = 0;
EWRAM_DATA s32 gUnk_0200047C = 0;
EWRAM_DATA s32 gUnk_02000480 = 0;
EWRAM_DATA s32 gUnk_02000484 = 0;
EWRAM_DATA s32 gUnk_02000488 = 0;

s32 TestCornersVsWalls(struct CornerSweep *corn, struct SweepBox *box, struct SweepBox *cbox, struct WallHit *out,
                       u16 *wallList, s32 *best)
{
    s32 tmp[4];
    s32 pax, pay, pbx, pby;
    struct CornerSweep *pc;
    struct SweepBox *pq;
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
            gUnk_02000460 = x1 = pc->x >> 16;
            gUnk_02000464 = y1 = pc->z >> 16;
            gUnk_02000468 = x2 = pc->nextX >> 16;
            gUnk_0200046C = y2 = pc->nextZ >> 16;
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
                out->unk0F = wall->edgeAngle;
                out->unk10 = *w;
                out->cornerIndex = (u8)i;
            }
        }
    }
#if PORTABLE
    /* The ROM falls off the end; no caller reads the result. */
    return 0;
#endif
}
