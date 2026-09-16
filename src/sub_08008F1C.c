#include "global.h"

struct Car {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u8 pad10[0x14 - 0x10];
    u32 unk14;
    u8 pad18[0x2C - 0x18];
    u32 unk2C;
    u8 pad30[0x34 - 0x30];
    u16 unk34;
    u8 pad36[0x190 - 0x36];
};

extern u8 gUnk_0200215C;
extern u8 gUnk_0202CAF0;
extern u8 gUnk_0202EED0;
extern struct Car *gUnk_0202EFC0[];
extern u32 gUnk_0202A3F0[];
extern struct Car gUnk_0202A550[];
extern u8 gUnk_020020CC;
extern u8 gUnk_0202ED70;
extern u8 gUnk_0202CAE8;
extern u32 gUnk_0202CB14;
extern u32 *gUnk_083C9E74[];
extern u8 gUnk_083681B0[];
extern u32 *gUnk_083C9574[];
extern u32 *gUnk_083C97B4[];
extern s32 gUnk_08368170[];

extern void sub_08004944(u32 a);
extern void sub_08007BB8(u8 a);
extern void sub_08008D70(void);
extern void sub_080097A4(u8 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void sub_0800BD98(s32 x, s16 *out, u16 *a3, void *a4);
extern void sub_0800BEA4(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void sub_08008D20(void);

void sub_08008F1C(u32 a1)
{
    u8 a;
    u32 eed0;
    u32 *p;
    struct Car **pp;
    u32 i;
    u32 off;
    struct Car *car;

    u32 d;
    register u32 sh asm("r1");
    register u32 v0 asm("r0");
    register u32 obj asm("r0");

    s16 out[4];
    register u32 garbage asm("r1");

    sub_08004944(a1);
    a = a1;
    sub_08007BB8(a);
    gUnk_0202CAF0 = 0;
    eed0 = gUnk_0202EED0;
    sub_08008D70();
    if (gUnk_0200215C == 0) {
        pp = gUnk_0202EFC0;
        p = gUnk_0202A3F0;
        i = 0;
        do {
            sub_080097A4(i, (u32)*pp, p[0] << 16, p[1] << 16, p[2] << 8,
                         *pp++ - gUnk_0202A550 + eed0);
            p += 3;
            i++;
        } while (i != 0x18);
    } else {
        p = gUnk_0202A3F0;
        i = 0;
        off = 0;
        do {
            sub_080097A4(i, off + (u32)gUnk_0202A550, p[0] << 16, p[1] << 16, p[2] << 8,
                         i + eed0);
            p += 3;
            off += 400;
            i++;
        } while (i != 0x18);
    }
    if (gUnk_0200215C == 0x0E || gUnk_0200215C == 0x09 || gUnk_0200215C == 0x0D
        || gUnk_0200215C == 0x11) {
        car = gUnk_0202EFC0[0];
        d = *(u16 *)gUnk_083C9E74[gUnk_020020CC * 12 + 5] * gUnk_083681B0[gUnk_020020CC] / 100;
        sub_0800BD98(d, out, (u16 *)gUnk_083C9574[gUnk_020020CC * 12 + 5],
                     (void *)gUnk_083C97B4[gUnk_020020CC * 12 + 5]);
        v0 = *(s32 *)&out[0];
        sh = v0 << 16;
        car->unk00 = sh;
        car->unk08 = *(s32 *)&out[2] << 16;
        car->unk0C = 0;
        car->unk14 = 0;
        car->unk2C = 0;
        car->unk34 = 0;
        if (gUnk_020020CC == 1)
            sub_0800BEA4(gUnk_0202EFC0, garbage, car->unk04, 0x46, 1);
        else
            sub_0800BEA4(gUnk_0202EFC0, garbage, car->unk04, 0x64, 1);
    }
    if (gUnk_0200215C == 0x0F) {
        car = gUnk_0202EFC0[0];
        d = *(u16 *)gUnk_083C9E74[gUnk_020020CC * 12 + 5] * gUnk_08368170[gUnk_0202ED70] / 100;
        sub_0800BD98(d, out, (u16 *)gUnk_083C9574[gUnk_020020CC * 12 + 5],
                     (void *)gUnk_083C97B4[gUnk_020020CC * 12 + 5]);
        car->unk00 = *(s32 *)&out[0] << 16;
        car->unk08 = *(s32 *)&out[2] << 16;
        car->unk0C = 0;
        car->unk14 = 0;
        car->unk2C = 0;
        car->unk34 = 0;
        if (gUnk_0202ED70 == 6)
            goto l_inner;
        if (gUnk_0202ED70 == 0xA)
            goto l_inner;
        if (gUnk_0202ED70 == 0xB)
            goto l_inner;
        if (gUnk_0202ED70 == 0xC)
            goto l_50;
        if (gUnk_0202ED70 == 0xE)
            goto l_inner;
        if (gUnk_0202ED70 != 0xF)
            goto l_180;
l_inner:
        if (gUnk_0202ED70 == 0xC)
            goto l_50;
        if (gUnk_0202ED70 == 6) {
            obj = (u32)gUnk_0202EFC0;
            sub_0800BEA4(obj, 0, 0, 0x28, 1);
            goto l_1d0;
        }
        if (gUnk_0202ED70 == 0xB)
            goto l_50;
        if (gUnk_0202ED70 != 0xE)
            goto l_16c;
l_50:
        obj = (u32)gUnk_0202EFC0;
        sub_0800BEA4(obj, 0, 0, 0x50, 1);
        goto l_1d0;
l_16c:
        gUnk_0202EFC0[0] = gUnk_0202A550;
        sub_0800BEA4(gUnk_0202EFC0, 0, 0, 0x32, 0);
        goto l_1d0;
l_180:
        if (gUnk_0202ED70 == 3) {
            sub_0800BEA4(gUnk_0202EFC0, 0, 0, 0x14, 1);
            goto l_1d0;
        }
        if (gUnk_0202ED70 == 0xD) {
            sub_0800BEA4(gUnk_0202EFC0, 0, 0, 0x4B, 1);
            goto l_1d0;
        }
        if (gUnk_0202ED70 == 2) {
            sub_0800BEA4(gUnk_0202EFC0, 0, 0, 0x32, 1);
            goto l_1d0;
        }
        sub_0800BEA4(gUnk_0202EFC0, 0, 0, 0x32, 0);
l_1d0:
        gUnk_0202CAE8 = 0;
        gUnk_0202CB14 = 0;
        sub_08008D20();
    }
}
