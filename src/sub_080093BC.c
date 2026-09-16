#include "global.h"

struct Car {
    u8 pad00[0x88];
    u32 unk88;
    u32 unk8C;
    u32 unk90;
    u32 unk94;
    u32 unk98;
    s32 unk9C;
    u8 padA0[0x175 - 0xA0];
    u8 unk175;
    u8 pad176[0x178 - 0x176];
    u32 unk178;
    u8 pad17C[0x181 - 0x17C];
    u8 unk181;
    u16 unk182;
    s32 unk184;
    s32 unk188;
    u8 pad18C[0x18F - 0x18C];
    u8 unk18F;
};

extern u8 gUnk_0202CAD0;
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202A53C;
extern struct Car gUnk_0202A550[];
extern u8 gUnk_0806C918[];
extern u8 gUnk_0806C924[];
extern u8 gUnk_0806C934[];
extern u32 gUnk_08368124[];
extern u32 gUnk_08368134[];
extern s32 gUnk_0202A520;
extern s32 gUnk_0202CAE0;
extern u8 gUnk_0202CBC0[];
extern u8 gUnk_0202CBC8[];
extern u8 gUnk_0202EF00[];
extern u8 gUnk_020020E0;
extern u8 gUnk_020021E0;

extern void sub_080080B4(void);
extern void sub_08006418(u8 *str, u32 y, u32 z);
extern void sub_0800C534(struct Car *a, u8 b);
extern void sub_0800A5BC(void *p);
extern void sub_080091F8(void);
extern u8 sub_080025FC(void);
extern void sub_08001208(u16 idx);
extern void sub_0800920C(u8 a);
extern void sub_0800649C(u32 a, u32 b, u32 c);
extern void sub_0800BE00(void *base, s32 arg);

void sub_080093BC(struct Car *a1, u8 a2)
{
    u32 v;
    s32 *p;

    if (gUnk_0202CAD0 != 0 && a1 == gUnk_0202A550)
        sub_080080B4();
    if (a1 == gUnk_0202A550 && gUnk_0202EEB0 == 0)
        sub_08006418(gUnk_0806C918, 10, 1);
    switch (a1->unk175) {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
        sub_0800C534(a1, a2);
        break;
    case 4:
        if (gUnk_0202CAD0 == 0 && gUnk_0202A53C == 0)
            a1->unk175 = 5;
        else if (gUnk_0202EEB0 != 0)
            sub_0800A5BC(a1);
        else
            a1->unk175 = 5;
        if (gUnk_0202CAD0 != 0 && a1 == gUnk_0202A550) {
            sub_0800A5BC(a1);
            break;
        }
        a1->unk184 = 0;
        a1->unk188 = 0x6400;
        a1->unk175 = 5;
        if (a1 != gUnk_0202A550)
            break;
        a1->unk188 = gUnk_08368124[gUnk_0202CBC0[0]];
        if (gUnk_0202CBC0[1] == 2)
            gUnk_0202A520 = 0;
        if (gUnk_0202CBC0[1] == 1) {
            if (a1->unk9C > 0x8200)
                gUnk_0202A520 = 0xB400 - a1->unk9C;
            else
                gUnk_0202A520 = 0x3200;
        }
        if (gUnk_0202CBC0[1] == 0)
            gUnk_0202A520 = 0xB400 - a1->unk9C;
        p = &a1->unk188;
        *p += gUnk_0202A520;
        *p += gUnk_08368134[gUnk_0202CBC0[2]];
        gUnk_0202CAE0 = 0x6400 / (*p >> 8);
        *p = 0x6400;
        break;
    case 5:
        if (gUnk_0202EEB0 != 0)
            sub_0800A5BC(a1);
        if (a1->unk184 < a1->unk188
            && (a1 != gUnk_0202A550 || gUnk_0202A53C != 0)
            && gUnk_0202EEB0 != 0)
            goto l_big;
        if (a1 == gUnk_0202A550) {
            sub_080091F8();
            a1->unk182 = 1;
        } else {
            a1->unk182 = 1;
        }
        a1->unk175 = 6;
        break;
l_big:
        if (a1 == gUnk_0202A550) {
            if (gUnk_0202A53C != 0) {
                if (gUnk_0202EF00[3] != 0) {
                    if (gUnk_020020E0 == 0 && gUnk_020021E0 == 0
                        && (sub_080025FC() & 15) > 13) {
                        v = sub_080025FC() & 3;
                        if (v == 0)
                            sub_08001208(25);
                        if (v == 1)
                            sub_08001208(26);
                        if (v == 2)
                            sub_08001208(24);
                        if (v == 3)
                            sub_08001208(24);
                    }
                }
                sub_0800920C((a1->unk184 >> 8) % 100);
            }
        }
        if (a1 != gUnk_0202A550)
            a1->unk184 += 0x100;
        else
            a1->unk184 += gUnk_0202CAE0;
        if (a1 == gUnk_0202A550) {
            if (gUnk_0202A53C == 0)
                break;
            if (gUnk_0202A520 > 0) {
                gUnk_0202A520 -= 0x100;
                a1->unk9C += 0x100;
            }
            if (gUnk_0202CBC0[0] != 3) {
                a1->unk8C = 0;
                a1->unk90 = 0;
                a1->unk94 = 0;
                a1->unk98 = 0;
            }
            if (gUnk_0202CBC0[2] == 0)
                a1->unk88 = 0;
        } else {
            a1->unk9C = 0xB400;
            a1->unk8C = 0;
            a1->unk90 = 0;
            a1->unk94 = 0;
            a1->unk98 = 0;
            a1->unk88 = 0;
        }
        break;
    case 6:
        v = a1->unk182;
        if (v == 0) {
            a1->unk175 = v;
            if (a1 != gUnk_0202A550) {
                sub_0800BE00(a1, a1->unk178);
                a1->unk18F = 1;
            }
            gUnk_0202CBC8[a1->unk181] = v;
            if (a1 == gUnk_0202A550)
                sub_0800649C(gUnk_0806C924, 9, 10);
        } else {
            sub_0800C534(a1, a2);
            if (a1 == gUnk_0202A550 && gUnk_0202EEB0 != 0)
                sub_0800649C(gUnk_0806C934, 10, 10);
        }
        break;
    }
}
