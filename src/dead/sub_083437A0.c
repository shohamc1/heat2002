#include "global.h"
#include "functions.h"
#include "variables.h"

struct WallRec {
    u16 f00;
    u16 f02;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 f1C;
    u8 f1D;
    u8 f1E;
};

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

struct Pt {
    s32 x;
    s32 y;
};



s32 sub_083437A0(struct Seg *seg, struct Box *box2, struct Box *box,
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
    s32 det;

    po = out;
    pbox = box;
    for (w = wallList; *w != 0xFFFF; w++) {
        wall = &gModule_Walls[*w];
        pax = gModule_WallVertices[wall->f00].x;
        pay = gModule_WallVertices[wall->f00].y;
        pbx = gModule_WallVertices[wall->f02].x;
        pby = gModule_WallVertices[wall->f02].y;
        dx0 = seg->f10;
        wf04 = wall->f04;
        if (dx0 * wf04 + seg->f14 * wall->f08 > 0)
            continue;
        if (pbox->f00 > wall->f10)
            continue;
        if (pbox->f08 > wall->f18)
            continue;
        if (pbox->f04 < wall->f0C)
            continue;
        if (pbox->f0C < wall->f14)
            continue;
        gUnk_020375B0 = pax;
        gUnk_020375B4 = pay;
        gUnk_020375B8 = pbx;
        gUnk_020375BC = pby;
        gUnk_020375A0 = x0 = seg->f00;
        gUnk_020375A4 = y0 = seg->f04;
        gUnk_020375A8 = x1 = seg->f08;
        gUnk_020375AC = y1 = seg->f0C;
        gUnk_020375C0 = det = (x1 - x0) * (pby - pay) - (y1 - y0) * (pbx - pax);
        if (det == 0)
            continue;
        gUnk_020375C8 = ((y0 - pay) * (pbx - pax)
                       - (x0 - pax) * (pby - pay)) << 8;
        t1 = sub_08344BB8(((y0 - pay) * (pbx - pax)
                         - (x0 - pax) * (pby - pay)) << 8, det);
        gUnk_020375C8 = t1;
        lim = 0x100;
        if (t1 > lim)
            continue;
        gUnk_020375C4 = ((x1 - x0) * (y0 - pay)
                       - (y1 - y0) * (x0 - pax)) << 8;
        t2 = sub_08344BB8(((x1 - x0) * (y0 - pay)
                         - (y1 - y0) * (x0 - pax)) << 8, det);
        gUnk_020375C4 = t2;
        if (t2 > lim)
            continue;
        po->f04 = wf04;
        po->f08 = wall->f08;
        return 1;
    }
    return 0;
}
