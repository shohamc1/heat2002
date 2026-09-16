/*
 * PARKED (wave 4): rebuild diverges from the ROM (object 576 bytes; first
 * diff at 0x0800BF26 -- branch targets land 4 bytes early, pool offsets
 * 4 bytes early: mid-function code is 4 bytes shorter than target).
 * Dead-agent mid-edit state, same class as sub_0800C430. Also needs a
 * hand-cut when fixed: extract.py refuses because .byte rows sit inside
 * the block.
 */
#include "global.h"

struct UnkObjBEA4 {
    /* 0x000 */ s32 f00;
    /* 0x004 */ u32 f04;
    /* 0x008 */ s32 f08;
    /* 0x00C */ u32 f0C;
    /* 0x010 */ u32 f10;
    /* 0x014 */ u32 f14;
    /* 0x018 */ u32 f18;
    /* 0x01C */ u32 f1C;
    /* 0x020 */ u32 f20;
    /* 0x024 */ u32 f24;
    /* 0x028 */ u32 f28;
    /* 0x02C */ u32 f2C;
    /* 0x030 */ u32 f30;
    /* 0x034 */ u16 f34;
    /* 0x036 */ u8 pad36[0xF4 - 0x36];
    /* 0x0F4 */ u16 *fF4;
    /* 0x0F8 */ void *fF8;
    /* 0x0FC */ u8 padFC[0x154 - 0xFC];
    /* 0x154 */ s32 f154;
};

extern u32 gUnk_0202CC24[];
extern u32 gUnk_0202CC38[];
extern u32 gUnk_0202CC3C[];
extern u32 gUnk_0202CC34[];
extern u8 gUnk_02002090;
extern u8 gUnk_0200215C;
extern u8 gUnk_0202ED70;

void sub_0800BE00(struct UnkObjBEA4 *v, s32 a);
void sub_0800C28C(struct UnkObjBEA4 *v);
s32 sub_0800C358(struct UnkObjBEA4 *v, s32 a);
s32 sub_0800BBFC(s32 a, s32 b, u16 *c, void *d, s32 e);
void sub_0800BD44(s32 a, u16 *b, void *c, void *d);
void sub_0800BD98(s32 a, s32 *out, u16 *b, void *c);
s32 sub_0800CB18(s32 a, s32 b);
s32 sub_080172C8(s32 a, s32 b);
void sub_0800C534(struct UnkObjBEA4 *v, u8 a);

void sub_0800BEA4(struct UnkObjBEA4 **list, s32 p2, s32 p3, s32 a3, u8 flag)
{
    struct UnkObjBEA4 *v;
    s32 out[2];

    s32 *py;
    struct UnkObjBEA4 **it;
    s32 d;
    s32 camx;
    s32 i;
    s32 dxx, dyy;
    s32 j;

    v = *list;
    i = 0;
    do {
        if (flag == 0) {
            if ((i & 1) != 0)
                sub_0800BE00(v, 0x100);
            else
                sub_0800BE00(v, 0x500);
        } else {
            sub_0800BE00(v, 0x500);
        }
        i++;
    } while (i != 24);

    v = *list;
    v->f2C = 0;
    sub_0800C28C(v);
    v->f18 = v->f00;
    v->f1C = v->f08;
    if (sub_0800C358(v, 0) == -1)
        return;

    camx = sub_0800BBFC(gUnk_0202CC24[0], gUnk_0202CC38[0], v->fF4, gUnk_0202CC3C[0], gUnk_0202CC34[0]);
    camx += -5000;
    if (camx < 0)
        camx += v->f154;

    it = list;
    i = 0;
    if (i != gUnk_02002090) {
    py = out;
    d = a3 * 3 / 2;
    do {
        v = *it;
        if (flag != 0) {
            sub_0800BE00(v, 0x500);
        } else {
            if ((i & 1) != 0)
                sub_0800BE00(v, 0x100);
            else
                sub_0800BE00(v, 0x500);
        }
        sub_0800BD44(camx, v->fF4, v->fF8, v);
        sub_0800BD98(camx, out, v->fF4, v->fF8);
        v->f00 = out[0] << 16;
        v->f08 = py[1] << 16;
        sub_0800BD98((camx + 0x32) % v->f154, out, v->fF4, v->fF8);
        dxx = (out[0] << 16) - v->f00;
        dyy = (py[1] << 16) - v->f08;
        v->f34 = -31744 - (sub_0800CB18(dxx >> 5, dyy >> 5) << 8);
        if (gUnk_0200215C == 0xF && i == 0 && gUnk_0202ED70 == 3)
            camx += -500;
        if (flag != 0 || (i & 1) != 0) {
            camx -= d;
            if (camx < 0)
                camx += v->f154;
        }
        i++;
        it++;
    } while (i != gUnk_02002090);
    }

    j = 0;
    while (j != 50) {
        it = list;
        i = 0;
        while (i != gUnk_02002090) {
            v = *it++;
            sub_0800C534(v, (u8)i);
            i++;
        }
        j++;
    }
}
