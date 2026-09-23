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
    u8 f180;
    u8 pad181[0x184 - 0x181];
    s32 f184;
    u8 pad188[0x18E - 0x188];
    u8 f18E;
};

extern u8 gUnk_0203916C;
extern u8 gUnk_020390EC;
extern u8 gUnk_0203DCF0;
extern u8 gUnk_0203D4E8;
extern u8 gUnk_0203DFB0;
extern struct Ent gUnk_0203D520[];
extern u8 gUnk_0203DDE8[];
extern u32 *gUnk_02026E1C[];
extern u32 gUnk_02027500[];
extern u32 gUnk_02027578[];
extern u32 gUnk_020275F0[];
extern u8 gUnk_0202713E[];
extern u8 gUnk_0202714A[];
extern u8 gUnk_02027154[];

void sub_083432EC(u32 *p, u32 v);

void sub_08341288(u8 a, struct Ent *car, s32 b, s32 c, u32 d)
{
    u8 i;

    if (gUnk_0203916C == 4)
        car->f162 = 0;
    car->f18E = 0;
    car->f175 = 0;
    gUnk_0203DCF0 = 0;
    car->f180 = 0;
    car->f176 = 0;
    car->f168 = 0;
    gUnk_0203D4E8 = 0;
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
    car->f58 = gUnk_02026E1C[a * 3];
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
    if (gUnk_0203916C == 0xF && gUnk_0203DFB0 == 3 && car == gUnk_0203D520)
        car->f9C = 0x5000;
    if (gUnk_0203916C != 5 && gUnk_0203916C != 0x11)
        car->f16C = 0;
    car->f170 = 0;
    car->f171 = 0;
    car->f172 = 0;
    sub_083432EC(&car->f128, d);
    car->f134 = 0;
    car->f138 = -1;
    car->f173 = 0;
    car->f171 = 0;
    i = 0;
    do {
        gUnk_0203DDE8[i] = 0;
        i++;
    } while (i != 8);
    /* One store per arm: jump2 merges the stores into one strb behind a new
       label, and jumps to a label created in that pass never cross-jump,
       so the equal-valued arms stay separate as in the ROM. */
    if (gUnk_0203916C == 0xF) {
        switch (gUnk_0203DFB0) {
        case 0:
            car->f4C = 1;
            break;
        case 1:
            car->f4C = 4;
            break;
        case 2:
            car->f4C = 5;
            break;
        case 3:
            car->f4C = 0x28;
            break;
        case 6:
            car->f4C = 0x28;
            break;
        case 10:
            car->f4C = 0xF;
            break;
        case 11:
            car->f4C = 0xF;
            break;
        case 12:
            car->f4C = 0x55;
            break;
        case 13:
            car->f4C = 0x12;
            break;
        case 14:
            car->f4C = 5;
            break;
        case 15:
            car->f4C = 0x14;
            break;
        default:
            car->f4C = 0;
            break;
        }
    } else {
        car->f4C = 0;
    }
    if ((u8)(gUnk_0203916C - 3) > 1)
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
    car->fE4 = gUnk_02027500[car->f162];
    car->fE8 = gUnk_02027578[car->f162];
    car->fEC = gUnk_020275F0[car->f162];
    if (gUnk_020390EC == 0 && a != 0 && gUnk_0203916C != 2) {
        car->fE4 = (s32)gUnk_0202713E;
        car->fE8 = (s32)gUnk_0202714A;
        car->fEC = (s32)gUnk_02027154;
        car->fE4 = gUnk_02027500[0];
        car->fE8 = gUnk_02027578[0];
        car->fEC = gUnk_020275F0[0];
    }
    car->f158 = 0;
    car->f7D = 0;
    car->f36 = d;
    car->f38 = 0;
    car->f160 = 0;
    car->f4E = 0;
    car->f3C = 0;
}
