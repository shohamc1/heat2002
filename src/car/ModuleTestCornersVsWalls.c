#include "global.h"
#include "functions.h"
#include "variables.h"

s32 ModuleTestCornersVsWalls(struct CornerSweep *corn, struct SweepBox *box, struct SweepBox *cbox, struct WallHit *out,
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
            gUnk_020375A0 = x1 = pc->x >> 16;
            gUnk_020375A4 = y1 = pc->z >> 16;
            gUnk_020375A8 = x2 = pc->nextX >> 16;
            gUnk_020375AC = y2 = pc->nextZ >> 16;
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
                out->unk0F = wall->edgeAngle;
                out->unk10 = *w;
                out->cornerIndex = (u8)i;
            }
        }
    }
}
