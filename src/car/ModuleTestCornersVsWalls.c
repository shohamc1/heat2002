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

struct Corner {
    u16 f00;
    s16 f02;
    u16 f04;
    s16 f06;
    u16 f08;
    s16 f0A;
    u16 f0C;
    s16 f0E;
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



s32 ModuleTestCornersVsWalls(struct Corner *corn, struct Box *box, struct Box *cbox,
                 struct Hit *out, u16 *wallList, s32 *best)
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
        wall = &gUnk_0203DE60[*w];
        x = box->f00;
        y = wall->f10;
        wnext = w + 1;
        if (x > y)
            continue;
        if (box->f08 > wall->f18)
            continue;
        if (box->f04 < wall->f0C)
            continue;
        if (box->f0C < wall->f14)
            continue;
        pax = gUnk_0203DE64[wall->f00].x;
        pay = gUnk_0203DE64[wall->f00].y;
        pbx = gUnk_0203DE64[wall->f02].x;
        pby = gUnk_0203DE64[wall->f02].y;
        pc = corn;
        pq = cbox;
        for (i = 0; i != 4; i++, pc++, pq++) {
            if (pq->f00 > wall->f10 + 1)
                continue;
            if (pq->f08 > wall->f18 + 1)
                continue;
            if (pq->f04 < wall->f0C - 1)
                continue;
            if (pq->f0C < wall->f14 - 1)
                continue;
            if ((pc->f10 >> 8) * wall->f04 + (pc->f14 >> 8) * wall->f08 > 0)
                continue;
            gUnk_020375B0 = pax;
            gUnk_020375B4 = pay;
            gUnk_020375B8 = pbx;
            gUnk_020375BC = pby;
            gUnk_020375A0 = x1 = pc->f02;
            gUnk_020375A4 = y1 = pc->f06;
            gUnk_020375A8 = x2 = pc->f0A;
            gUnk_020375AC = y2 = pc->f0E;
            gUnk_020375C0 = det = (x2 - x1) * (pby - pay) - (y2 - y1) * (pbx - pax);
            if (det == 0)
                continue;
            gUnk_020375C8 = ((y1 - pay) * (pbx - pax)
                           - (x1 - pax) * (pby - pay)) << 8;
            t1 = sub_08344BB8(((y1 - pay) * (pbx - pax)
                             - (x1 - pax) * (pby - pay)) << 8, det);
            gUnk_020375C8 = t1;
            lim = 0x100;
            if (t1 > lim)
                continue;
            gUnk_020375C4 = ((x2 - x1) * (y1 - pay)
                           - (y2 - y1) * (x1 - pax)) << 8;
            t2 = sub_08344BB8(((x2 - x1) * (y1 - pay)
                             - (y2 - y1) * (x1 - pax)) << 8, det);
            gUnk_020375C4 = t2;
            if (t2 > lim)
                continue;
            if (t1 < *best) {
                *best = t2;
                out->f04 = (wall->f04 * 0x104) >> 8;
                out->f08 = (wall->f08 * 0x104) >> 8;
                out->f0D = wall->f1C;
                out->f0E = wall->f1D;
                out->f0F = wall->f1E;
                out->f10 = *w;
                out->f0C = (u8)i;
            }
        }
    }
}
