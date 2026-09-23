#include "global.h"

struct Ent {
    s32 f00;
    u8 pad04[4];
    s32 f08;
    s32 f0C;
    u8 pad10[4];
    s32 f14;
    u8 pad18[0x28 - 0x18];
    s32 f28;
    s32 f2C;
    s32 f30;
    u16 f34;
    u16 f36;
    u16 f38;
    u8 pad3A[2];
    u16 f3C;
    u8 f3E;
    u8 pad3F;
    u16 f40;
    u8 pad42[0x4C - 0x42];
    u8 f4C;
    u8 f4D;
    u8 f4E;
    u8 pad4F;
    s32 f50;
    u8 pad54;
    u8 f55;
    u8 pad56[0x58 - 0x56];
    s32 f58;
    u8 pad5C[0x7C - 0x5C];
    u8 f7C;
    u8 f7D;
    u8 pad7E[0x84 - 0x7E];
    u8 f84;
    u8 pad85[0x88 - 0x85];
    s32 f88;
    s32 f8C;
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    u8 padA0[0xA2 - 0xA0];
    u16 fA2;
    u8 padA4[0xE4 - 0xA4];
    s32 fE4;
    s32 fE8;
    s32 fEC;
    u8 padF0[0x110 - 0xF0];
    u8 f110;
    u8 pad111[0x128 - 0x111];
    u32 f128;
    u8 pad12C[0x134 - 0x12C];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    s32 f144;
    s32 f148;
    s32 f14C;
    u8 f150;
    u8 pad151[0x158 - 0x151];
    s32 f158;
    s32 f15C;
    u16 f160;
    u8 f162;
    u8 pad163[3];
    u8 f166;
    u8 f167;
    u8 f168;
    u8 pad169[3];
    s32 f16C;
    u8 f170;
    u8 f171;
    u8 f172;
    u8 f173;
    u8 f174;
    u8 f175;
    u8 f176;
    u8 pad177[0x17C - 0x177];
    s32 f17C;
    u8 pad180[0x180 - 0x180];
    u8 f180;
    u8 pad181[0x184 - 0x181];
    s32 f184;
    u8 pad188[0x18E - 0x188];
    u8 f18E;
};

extern u8 gUnk_0200215C;
extern u8 gUnk_020020DC;
extern u8 gUnk_0202CAD0;
extern u8 gUnk_0202A51C;
extern u32 gUnk_020253B8;
extern u8 gUnk_0202ED70;
extern struct Ent gUnk_0202A550[];
extern u8 gUnk_0202CBC8[];
extern u32 *gUnk_08367730[];
extern u32 gUnk_08367FBC[];
extern u32 gUnk_08368034[];
extern u32 gUnk_083680AC[];

void sub_0800C0E8(u32 a, u8 b);
void sub_0800C984(u32 *p, u32 v);

void sub_080097A4(u8 a, struct Ent *car, s32 b, s32 c, u32 d)
{
    u8 i;
    u8 v;

    if (gUnk_0200215C == 4)
        car->f162 = 0;
    car->f18E = 0;
    car->f175 = 0;
    gUnk_0202CAD0 = 0;
    car->f180 = 0;
    car->f176 = 0;
    car->f17C = gUnk_020253B8;
    car->f168 = 0;
    gUnk_0202A51C = 0;
    car->f166 = 1;
    car->f167 = 0;
    car->f00 = b;
    car->f08 = c;
    car->f34 = d;
    car->f2C = 0;
    car->f28 = 0;
    car->f40 = 0;
    car->f3E = 0;
    car->f55 = 0;
    car->f4D = 0;
    car->f174 = 0;
    if (gUnk_0200215C == 4) {
        car->f58 = gUnk_08367730[a * 3];
    } else {
        car->f58 = gUnk_08367730[car->f162];
    }
    car->f7C = 0;
    car->f84 = 1;
    car->f30 = 0;
    car->f88 = 0;
    car->fA2 = 0;
    car->f8C = 0;
    car->f90 = 0;
    car->f94 = 0;
    car->f98 = 0;
    car->f9C = 0xB400;
    if (gUnk_0200215C == 0xF && gUnk_0202ED70 == 3 && car == gUnk_0202A550)
        car->f9C = 0x5000;
    if (gUnk_0200215C != 4)
        sub_0800C0E8((u32)car, a);
    if (gUnk_0200215C != 5 && gUnk_0200215C != 0x11)
        car->f16C = 0;
    car->f170 = 0;
    car->f171 = 0;
    car->f172 = 0;
    sub_0800C984(&car->f128, d);
    car->f134 = 0;
    car->f138 = -1;
    car->f173 = 0;
    car->f171 = 0;
    i = 0;
    do {
        gUnk_0202CBC8[i] = 0;
        i++;
    } while (i != 8);
    if (gUnk_0200215C == 0xF) {
        switch (gUnk_0202ED70) {
        case 0:
            v = 1;
            break;
        case 1:
            v = 4;
            break;
        case 2:
            v = 5;
            break;
        case 3:
            v = 0x28;
            break;
        case 6:
            v = 0x28;
            goto out;
        case 10:
            v = 0xF;
            break;
        case 11:
            v = 0xF;
            goto out;
        case 12:
            v = 0x55;
            break;
        case 13:
            v = 0x12;
            break;
        case 14:
            v = 5;
            goto out;
        case 15:
            v = 0x14;
            break;
        default:
            v = 0;
            break;
        }
    } else {
        v = 0;
    }
out:
    car->f4C = v;
    if ((u8)(gUnk_0200215C - 3) > 1)
        car->f4C--;
    car->f50 = 0;
    car->f15C = 0x12C;
    car->f0C = 0;
    car->f14 = 0;
    car->f110 = 0;
    car->f140 = 0;
    car->f144 = 0;
    car->f13C = 0;
    car->f148 = 0;
    car->f14C = 0;
    car->f150 = 0x63;
    car->fE4 = gUnk_08367FBC[car->f162];
    car->fE8 = gUnk_08368034[car->f162];
    car->fEC = gUnk_083680AC[car->f162];
    if (gUnk_020020DC == 0 && a != 0 && gUnk_0200215C != 2) {
        car->fE4 = 0x08367BFA;
        car->fE8 = 0x08367C06;
        car->fEC = 0x08367C10;
        car->fE4 = gUnk_08367FBC[0];
        car->fE8 = gUnk_08368034[0];
        car->fEC = gUnk_083680AC[0];
    }
    car->f158 = 0;
    car->f7D = 0;
    car->f36 = d;
    car->f38 = 0;
    car->f160 = 0;
    car->f4E = 0;
    car->f3C = 0;
}
