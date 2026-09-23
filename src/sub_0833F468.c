/*
 * sub_0833F468 -- the high module's copy of sub_08006A34. The first ~230
 * instructions (the gate-crossing test) are identical to the low copy; the
 * lap bookkeeping drops the low copy's mode-0x10 challenge checks. Ported
 * from that source, so its three levers apply here unchanged: the dx/dy
 * register pins inside the determinant test, `time` at the two unsigned
 * compares, and `m = z - 1` for the node reset.
 */

#include "global.h"

struct Car {
    s32 unk00;                          /* 0x00 */
    u8 pad04[4];
    s32 unk08;                          /* 0x08 */
    s32 unk0C;                          /* 0x0C */
    u8 pad10[4];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x34 - 0x18];
    u16 unk34;                          /* 0x34 */
    u16 unk36;                          /* 0x36 */
    u16 unk38;                          /* 0x38 */
    u8 pad3A[0x4C - 0x3A];
    u8 unk4C;                           /* 0x4C */
    u8 unk4D;                           /* 0x4D */
    u8 unk4E;                           /* 0x4E */
    s32 unk50;                          /* 0x50 */
    u8 pad54[0x15C - 0x54];
    u32 unk15C;                         /* 0x15C */
    u8 pad160[0x166 - 0x160];
    u8 unk166;                          /* 0x166 */
    u8 unk167;                          /* 0x167 */
    u8 unk168;                          /* 0x168 */
    u8 pad169[0x16C - 0x169];
    u32 unk16C;                         /* 0x16C */
    u8 pad170[0x174 - 0x170];
    u8 unk174;                          /* 0x174 */
    u8 pad175[0x18E - 0x175];
    u8 unk18E;                          /* 0x18E */
};

struct Track {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u16 unk10;
    u8 pad12[2];
    u8 unk14;
    u8 pad15[3];
};

extern volatile u8 gUnk_020390EC;
extern u8 gUnk_020390CC;
extern u8 gUnk_0203E120[];
extern u8 gUnk_0203E1B0;
extern u8 gUnk_020390BC[];
extern u8 gUnk_020390A0[];
extern u8 gUnk_0203DD10;
extern u8 gUnk_0203916C;
extern u32 gUnk_0203DFC4;
extern u8 gUnk_0203E104;
extern struct Car gUnk_0203D520[];
extern u16 gUnk_0203B6C8;
extern u16 gUnk_0203B6A8;
extern u16 gUnk_0203B858;
extern u8 gUnk_0203E1E0;
extern struct Track *gUnk_0203B860;
extern u8 gUnk_02039194;
extern u32 gUnk_0203DE40;
extern u16 gUnk_0203B704;
extern u16 gUnk_0203B6D0;
extern u16 gUnk_0203B6D4;
extern u8 gUnk_0203B864;
extern u8 gUnk_0203B868[];

extern void sub_08342908(void);
extern void sub_08341EC8(struct Car *p);
extern void sub_0833E160(u16 a, u16 b, u16 c);
extern void sub_08342BA4(u16 a, u16 b, u16 c);
extern void sub_08342D10(void);
extern void sub_08342A94(void);
extern void sub_0833E05C(void);
extern void sub_0833E094(u8 x);

u8 sub_0833F468(struct Car *p, u8 a1)
{
    u8 unused1[40];
    s32 corners[4];
    u8 unused2[28];
    u8 v58;
    s32 l0, l4, l8, lC;
    struct Track *e, *b;
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

    e = &gUnk_0203B860[p->unk4D];
    b = e + 1;
    if (e->unk10 == 1)
        b = gUnk_0203B860;

    corners[0] = p->unk00 >> 16;
    corners[1] = p->unk08 >> 16;
    corners[2] = (p->unk00 + p->unk0C) >> 16;
    corners[3] = (p->unk08 + p->unk14) >> 16;

    x0 = e->f0;
    x1 = e->f4;
    x2 = e->f8;
    x3 = e->fC;
    y0 = b->f0;
    y1 = b->f4;
    y2 = b->f8;
    y3 = b->fC;

    l0 = (x0 * (16 - p->unk4E) + y0 * p->unk4E) >> 4;
    l8 = (x2 * (16 - p->unk4E) + y2 * p->unk4E) >> 4;
    l4 = (x1 * (16 - p->unk4E) + y1 * p->unk4E) >> 4;
    lC = (x3 * (16 - p->unk4E) + y3 * p->unk4E) >> 4;

    p->unk50 = ((s8)p->unk4C << 16) + p->unk4D * 16 + p->unk4E;

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
    p->unk4E = p->unk4E + 1;
    gUnk_020390CC = 1;
    p->unk50 = ((s8)p->unk4C << 16) + p->unk4D * 16 + p->unk4E;
    if (p->unk4E != 0x10)
        return 1;
    p->unk4E = 0;
    p->unk36 = p->unk34;
    p->unk38 = p->unk4D;
    {
    s32 t = e->unk10;
    if (t == 1) {
        if (gUnk_0203916C == 0x0C) {
            if ((time = gUnk_0203B6C8 * 60000 + gUnk_0203B6A8 * 1000 + gUnk_0203B858) < gUnk_0203DFC4)
                gUnk_0203E104 = t;
        }
        if (a1 == v6C && gUnk_0203916C != 0x0C && p->unk166 != 0) {
            p->unk167 = 0x1E;
            p->unk168 = p->unk168 + 1;
        }
        p->unk4C = p->unk4C + 1;
        {
        s32 z = 0;
        s32 m = z - 1;
        p->unk4D = m;
        }
        p->unk4E = 0;
        p->unk50 = ((s8)p->unk4C << 16) + p->unk4D * 16;
        if (a1 == v6C) {
            if (gUnk_0203E1E0 != 0 && p->unk18E != 0)
                sub_0833E160(gUnk_0203B6C8, gUnk_0203B6A8, gUnk_0203B858);
        }
        p->unk166 = 1;
        if (p == gUnk_0203D520 && gUnk_0203916C == 5 && p->unk18E != 0) {
            if ((time = gUnk_0203B6C8 * 60000 + gUnk_0203B6A8 * 1000 + gUnk_0203B858) < p->unk16C)
                p->unk16C = gUnk_0203B6C8 * 60000 + gUnk_0203B6A8 * 1000 + gUnk_0203B858;
        }
        if (*(s8 *)&p->unk4C == gUnk_02039194) {
            if (gUnk_0203916C == 0 || gUnk_0203916C == 6 || gUnk_0203916C == 1)
                p->unk16C = gUnk_0203B704 * 60000 + gUnk_0203B6D0 * 1000 + gUnk_0203B6D4;
            if (a1 == v6C && p->unk18E != 0)
                sub_08342BA4(gUnk_0203B6C8, gUnk_0203B6A8, gUnk_0203B858);
            if (gUnk_0203916C != 2) {
                sub_08341EC8(p);
                gUnk_0203B868[gUnk_0203B864] = a1;
                gUnk_0203B864 = gUnk_0203B864 + 1;
                if ((u8)(gUnk_0203916C - 3) <= 1)
                    p->unk16C = gUnk_0203B704 * 60000 + gUnk_0203B6D0 * 1000 + gUnk_0203B6D4;
                if (gUnk_0203B864 == v68) {
                    if (gUnk_0203916C != 0x10) {
                        if (gUnk_0203916C != 0xF) {
                            if (gUnk_0203916C != 2) {
                                if (gUnk_0203916C != 0xE)
                                    sub_08342908();
                            }
                        }
                    }
                }
            }
        } else {
            if (a1 == v6C && p->unk18E != 0)
                sub_08342BA4(gUnk_0203B6C8, gUnk_0203B6A8, gUnk_0203B858);
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
            if (a1 == v6C && gUnk_0203916C != 0xA) {
                s32 inner = v58 / 2 + 6;
                sub_0833E094((u8)(e->unk14 + inner));
            }
        }
        {
        s32 t2 = e->unk10;
        if (t2 == 1 && p->unk18E == 0) {
            if (p == gUnk_0203D520)
                sub_08342A94();
            p->unk18E = t2;
        }
        }
    }
    p->unk4D = p->unk4D + 1;
    return 1;
}
