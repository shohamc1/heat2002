/*
 * sub_0833F468 -- the high module's copy of sub_08006A34. The first ~230
 * instructions (the gate-crossing test) are identical to the low copy; the
 * lap bookkeeping drops the low copy's mode-0x10 challenge checks. Ported
 * from that source, so its three levers apply here unchanged: the dx/dy
 * register pins inside the determinant test, `time` at the two unsigned
 * compares, and `m = z - 1` for the node reset.
 */

#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

/* The 0x18-byte track segment record gUnk_0203B860 points at (waypoint
   quads); local twin of sub_08006A34.c's struct TrackSeg. It shares its
   old tag name with include/structs.h's 0x64-byte struct Track but not
   its layout or stride, so it keeps a local tag. The gUnk_0203B860
   extern (variables.h) is typed struct Track *; the casts below are
   pointer casts only and emit nothing. */
struct TrackSeg {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u16 unk10;
    u8 pad12[2];
    u8 unk14;
    u8 pad15[3];
};

extern u32 gUnk_0203DFC4;
extern u32 gUnk_0203DE40;


u8 sub_0833F468(struct Car *p, u8 a1)
{
    u8 unused1[40];
    s32 corners[4];
    u8 unused2[28];
    u8 v58;
    s32 l0, l4, l8, lC;
    struct TrackSeg *e, *b;
    u8 v68, v6C;
    s32 x0, x1, x2, x3, y0, y1, y2, y3;
    s32 det;
    u32 time;

    v58 = 3 - gUnk_0203E120[0];
    gUnk_020390CC = 0;
    v6C = gUnk_020390EC != 0 ? gUnk_0203E1B0 : 0;
    if (gUnk_020390EC != 0)
        v68 = gUnk_020390BC[0];
    else
        v68 = gUnk_020390A0[0];

    e = &((struct TrackSeg *)gUnk_0203B860)[p->waypoint];
    b = e + 1;
    if (e->unk10 == 1)
        b = (struct TrackSeg *)gUnk_0203B860;

    corners[0] = p->posX >> 16;
    corners[1] = p->posZ >> 16;
    corners[2] = (p->posX + p->velX) >> 16;
    corners[3] = (p->posZ + p->velZ) >> 16;

    x0 = e->f0;
    x1 = e->f4;
    x2 = e->f8;
    x3 = e->fC;
    y0 = b->f0;
    y1 = b->f4;
    y2 = b->f8;
    y3 = b->fC;

    l0 = (x0 * (16 - p->subStep) + y0 * p->subStep) >> 4;
    l8 = (x2 * (16 - p->subStep) + y2 * p->subStep) >> 4;
    l4 = (x1 * (16 - p->subStep) + y1 * p->subStep) >> 4;
    lC = (x3 * (16 - p->subStep) + y3 * p->subStep) >> 4;

    p->progress = ((s8)p->lap << 16) + p->waypoint * 16 + p->subStep;

    det = (corners[2] - corners[0]) * (lC - l4)
        - (corners[3] - corners[1]) * (l8 - l0);
    if (det == 0)
        return 0;
    {
    register s32 dx asm("r6");
    register s32 dy asm("r5");
    if ((u32)((((dx = corners[1] - l4) * (l8 - l0) - (dy = corners[0] - l0) * (lC - l4)) << 8) / det) > 0x100)
        return 0;
    if ((u32)((((dx) * (corners[2] - corners[0]) - (corners[3] - corners[1]) * (dy)) << 8) / det) > 0x100)
        return 0;
    }

    if (p->unk174 == 0) {
        p->unk174 = 1;
        gUnk_0203DD10 = gUnk_0203DD10 + 1;
    }
    p->subStep = p->subStep + 1;
    gUnk_020390CC = 1;
    p->progress = ((s8)p->lap << 16) + p->waypoint * 16 + p->subStep;
    if (p->subStep != 0x10)
        return 1;
    p->subStep = 0;
    p->unk36 = p->heading;
    p->unk38 = p->waypoint;
    {
    s32 t = e->unk10;
    if (t == 1) {
        if (gUnk_0203916C[0] == 0x0C) {
            if ((time = gUnk_0203B6C8[0] * 60000 + gUnk_0203B6A8[0] * 1000 + gUnk_0203B858[0]) < gUnk_0203DFC4)
                gUnk_0203E104 = t;
        }
        if (a1 == v6C && gUnk_0203916C[0] != 0x0C && p->unk166 != 0) {
            p->unk167 = 0x1E;
            p->unk168 = p->unk168 + 1;
        }
        p->lap = p->lap + 1;
        {
        s32 z = 0;
        s32 m = z - 1;
        p->waypoint = m;
        }
        p->subStep = 0;
        p->progress = ((s8)p->lap << 16) + p->waypoint * 16;
        if (a1 == v6C) {
            if (gUnk_0203E1E0[0] != 0 && p->unk18E != 0)
                sub_0833E160(gUnk_0203B6C8[0], gUnk_0203B6A8[0], gUnk_0203B858[0]);
        }
        p->unk166 = 1;
        if (p == gModule_Cars && gUnk_0203916C[0] == 5 && p->unk18E != 0) {
            if ((time = gUnk_0203B6C8[0] * 60000 + gUnk_0203B6A8[0] * 1000 + gUnk_0203B858[0]) < p->unk16C)
                p->unk16C = gUnk_0203B6C8[0] * 60000 + gUnk_0203B6A8[0] * 1000 + gUnk_0203B858[0];
        }
        if (*(s8 *)&p->lap == gUnk_02039194) {
            if (gUnk_0203916C[0] == 0 || gUnk_0203916C[0] == 6 || gUnk_0203916C[0] == 1)
                p->unk16C = gUnk_0203B704[0] * 60000 + gUnk_0203B6D0[0] * 1000 + gUnk_0203B6D4[0];
            if (a1 == v6C && p->unk18E != 0)
                sub_08342BA4(gUnk_0203B6C8[0], gUnk_0203B6A8[0], gUnk_0203B858[0]);
            if (gUnk_0203916C[0] != 2) {
                sub_08341EC8((u16 *)p);
                gUnk_0203B868[gUnk_0203B864] = a1;
                gUnk_0203B864 = gUnk_0203B864 + 1;
                if ((u8)(gUnk_0203916C[0] - 3) <= 1)
                    p->unk16C = gUnk_0203B704[0] * 60000 + gUnk_0203B6D0[0] * 1000 + gUnk_0203B6D4[0];
                if (gUnk_0203B864 == v68) {
                    if (gUnk_0203916C[0] != 0x10) {
                        if (gUnk_0203916C[0] != 0xF) {
                            if (gUnk_0203916C[0] != 2) {
                                if (gUnk_0203916C[0] != 0xE)
                                    sub_08342908();
                            }
                        }
                    }
                }
            }
        } else {
            if (a1 == v6C && p->unk18E != 0)
                sub_08342BA4(gUnk_0203B6C8[0], gUnk_0203B6A8[0], gUnk_0203B858[0]);
        }
        if (a1 == v6C)
            sub_0833E05C();
    }
    }

    if ((u16)(e->unk10 - 1) <= 1) {
        if (a1 == v6C) {
            gUnk_0203DE40 = p->unk15C;
            if (e->unk10 != 1)
                sub_08342D10();
            if (a1 == v6C && gUnk_0203916C[0] != 0xA) {
                s32 inner = v58 / 2 + 6;
                sub_0833E094((u8)(e->unk14 + inner));
            }
        }
        {
        s32 t2 = e->unk10;
        if (t2 == 1 && p->unk18E == 0) {
            if (p == gModule_Cars)
                sub_08342A94();
            p->unk18E = t2;
        }
        }
    }
    p->waypoint = p->waypoint + 1;
    return 1;
}
