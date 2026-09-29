#include "global.h"
#include "functions.h"
#include "variables.h"

struct Box {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
};

struct Seg {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
};

struct Hit {
    s32 f00;
    s32 f04;
    s32 f08;
    u8 f0C;
    u8 f0D;
    u8 f0E;
    u8 f0F;
    s32 f10;
};



s32 TestSegmentVsWalls(struct Seg *seg, struct Box *box2, struct Box *box,
                 struct Hit *out, u16 *wallList)
{
    s32 tmp[4];
    struct Hit *po;
    s32 pax, pay, pbx, pby;
    struct Box *pbox;
    u16 *w;
    struct WallRec *wall;
    s32 wf04;
    s32 dx0;
    s32 t1, t2;
    u32 lim;
    s32 x0, y0, x1, y1;

    po = out;
    pbox = box;
    for (w = wallList; *w != 0xFFFF; w++) {
        wall = &gWalls[*w];
        pax = gWallVertices[wall->vertex0].x;
        pay = gWallVertices[wall->vertex0].y;
        pbx = gWallVertices[wall->vertex1].x;
        pby = gWallVertices[wall->vertex1].y;
        dx0 = seg->f10;
        wf04 = wall->normalX;
        if (dx0 * wf04 + seg->f14 * wall->normalZ > 0)
            continue;
        if (pbox->f00 > wall->maxX)
            continue;
        if (pbox->f08 > wall->maxZ)
            continue;
        if (pbox->f04 < wall->minX)
            continue;
        if (pbox->f0C < wall->minZ)
            continue;
        gUnk_02000470 = pax;
        gUnk_02000474 = pay;
        gUnk_02000478 = pbx;
        gUnk_0200047C = pby;
        gUnk_02000460 = x0 = seg->f00;
        gUnk_02000464 = y0 = seg->f04;
        gUnk_02000468 = x1 = seg->f08;
        gUnk_0200046C = y1 = seg->f0C;
        gUnk_02000480 = (x1 - x0) * (pby - pay) - (y1 - y0) * (pbx - pax);
        if (gUnk_02000480 == 0)
            continue;
        gUnk_02000488 = ((y0 - pay) * (pbx - pax)
                       - (x0 - pax) * (pby - pay)) << 8;
        t1 = (((y0 - pay) * (pbx - pax)
             - (x0 - pax) * (pby - pay)) << 8) / gUnk_02000480;
        gUnk_02000488 = t1;
        lim = 0x100;
        if (t1 > lim)
            continue;
        gUnk_02000484 = ((x1 - x0) * (y0 - pay)
                       - (y1 - y0) * (x0 - pax)) << 8;
        t2 = (((x1 - x0) * (y0 - pay)
             - (y1 - y0) * (x0 - pax)) << 8) / gUnk_02000480;
        gUnk_02000484 = t2;
        if (t2 > lim)
            continue;
        po->f04 = wf04;
        po->f08 = wall->normalZ;
        return 1;
    }
    return 0;
}
