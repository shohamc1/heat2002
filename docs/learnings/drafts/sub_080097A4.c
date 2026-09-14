/*
 * PARKED (wave 4): rebuild diverges from the ROM (object 876 bytes; first
 * diff at 0x0800993A -- register-allocation pattern differs, target uses
 * `adds rX, rY, #0; adds rX, #imm` where ours emits `movs rX, #imm; adds
 * rX, rX, rY`). Dead-agent mid-edit state, same class as sub_0800C430.
 * Also needs a hand-cut when fixed: extract.py refuses because jump-table
 * .byte rows sit inside the block.
 */
#include "global.h"

struct Car {
    s32 unk00;                          /* 0x00 */
    u8 pad04[4];
    s32 unk08;                          /* 0x08 */
    s32 unk0C;                          /* 0x0C */
    u8 pad10[4];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x10];
    s32 unk28;                          /* 0x28 */
    s32 unk2C;                          /* 0x2C */
    s32 unk30;                          /* 0x30 */
    u16 unk34;                          /* 0x34 */
    u16 unk36;                          /* 0x36 */
    u16 unk38;                          /* 0x38 */
    u8 pad3A[2];
    u16 unk3C;                          /* 0x3C */
    u8 unk3E;                           /* 0x3E */
    u16 unk40;                          /* 0x40 */
    u8 pad42[0xA];
    u8 unk4C;                           /* 0x4C */
    u8 unk4D;                           /* 0x4D */
    u8 unk4E;                           /* 0x4E */
    u8 pad4F[1];
    s32 unk50;                          /* 0x50 */
    u8 pad54[1];
    u8 unk55;                           /* 0x55 */
    u8 pad56[2];
    s32 unk58;                          /* 0x58 */
    u8 pad5C[0x20];
    u8 unk7C;                           /* 0x7C */
    u8 unk7D;                           /* 0x7D */
    u8 pad7E[6];
    u8 unk84;                           /* 0x84 */
    u8 pad85[3];
    s32 unk88;                          /* 0x88 */
    s32 unk8C;                          /* 0x8C */
    s32 unk90;                          /* 0x90 */
    s32 unk94;                          /* 0x94 */
    s32 unk98;                          /* 0x98 */
    s32 unk9C;                          /* 0x9C */
    u8 padA0[2];
    u16 unkA2;                          /* 0xA2 */
    u8 padA4[0x40];
    s32 unkE4;                          /* 0xE4 */
    s32 unkE8;                          /* 0xE8 */
    s32 unkEC;                          /* 0xEC */
    u8 padF0[0x20];
    u8 unk110;                          /* 0x110 */
    u8 pad111[0x17];
    s32 unk128;                         /* 0x128 */
    u8 pad12C[8];
    s32 unk134;                         /* 0x134 */
    s32 unk138;                         /* 0x138 */
    s32 unk13C;                         /* 0x13C */
    s32 unk140;                         /* 0x140 */
    s32 unk144;                         /* 0x144 */
    s32 unk148;                         /* 0x148 */
    s32 unk14C;                         /* 0x14C */
    u8 unk150;                          /* 0x150 */
    u8 pad151[7];
    u16 unk158;                         /* 0x158 */
    u8 unk15A;                          /* 0x15A */
    u8 pad15B[1];
    s32 unk15C;                         /* 0x15C */
    u16 unk160;                         /* 0x160 */
    u8 unk162;                          /* 0x162 */
    u8 pad163[3];
    u8 unk166;                          /* 0x166 */
    u8 unk167;                          /* 0x167 */
    u8 unk168;                          /* 0x168 */
    u8 pad169[3];
    s32 unk16C;                         /* 0x16C */
    u8 unk170;                          /* 0x170 */
    u8 unk171;                          /* 0x171 */
    u8 unk172;                          /* 0x172 */
    u8 unk173;                          /* 0x173 */
    u8 unk174;                          /* 0x174 */
    u8 unk175;                          /* 0x175 */
    u8 unk176;                          /* 0x176 */
    u8 pad177[5];
    s32 unk17C;                         /* 0x17C */
    u8 unk180;                          /* 0x180 */
    u8 pad181[0xD];
    u8 unk18E;                          /* 0x18E */
    u8 pad18F[1];
};

extern u8 gUnk_0200215C;
extern u8 gUnk_0202CAD0;
extern u32 gUnk_020253B8;
extern u8 gUnk_0202A51C;
extern u8 gUnk_0202ED70;
extern struct Car gUnk_0202A550[];
extern u8 gUnk_020020DC;
extern u8 gUnk_0202CBC8[];
extern u32 gUnk_08367730[];
extern u32 gUnk_08367FBC[];
extern u32 gUnk_08368034[];
extern u32 gUnk_083680AC[];
extern u8 gUnk_08367BFA[];
extern u8 gUnk_08367C06[];
extern u8 gUnk_08367C10[];

extern void sub_0800C0E8(struct Car *a, u8 b);
extern void sub_0800C984(s32 *a, u32 b);

void sub_080097A4(u8 idx, struct Car *car, u32 a2, u32 a3, u32 a4)
{
    u8 *p4c, *p4e, *p7d, *p171;
    s32 *pe4, *pe8, *pec;
    u8 i;
    u8 v;

    if (gUnk_0200215C == 4)
        car->unk162 = 0;
    car->unk18E = 0;
    car->unk175 = 0;
    gUnk_0202CAD0 = 0;
    car->unk180 = 0;
    car->unk176 = 0;
    car->unk17C = gUnk_020253B8;
    car->unk168 = 0;
    gUnk_0202A51C = 0;
    car->unk166 = 1;
    car->unk167 = 0;
    car->unk00 = a2;
    car->unk08 = a3;
    car->unk34 = (u16)a4;
    car->unk2C = 0;
    car->unk28 = 0;
    car->unk40 = 0;
    car->unk3E = 0;
    car->unk55 = 0;
    car->unk4D = 0;
    car->unk174 = 0;
    if (gUnk_0200215C == 4)
        car->unk58 = gUnk_08367730[idx * 3];
    else
        car->unk58 = gUnk_08367730[car->unk162];
    car->unk7C = 0;
    car->unk84 = 1;
    car->unk30 = 0;
    car->unk88 = 0;
    car->unkA2 = 0;
    car->unk8C = 0;
    car->unk90 = 0;
    car->unk94 = 0;
    car->unk98 = 0;
    car->unk9C = 0xB400;
    if (gUnk_0200215C == 0xF) {
        if (gUnk_0202ED70 == 3) {
            if (car == gUnk_0202A550)
                car->unk9C = 0x5000;
        }
    }
    if (gUnk_0200215C != 4)
        sub_0800C0E8(car, idx);
    if (gUnk_0200215C != 5 && gUnk_0200215C != 0x11)
        car->unk16C = 0;
    car->unk170 = 0;
    p171 = &car->unk171;
    *p171 = 0;
    car->unk172 = 0;
    sub_0800C984(&car->unk128, a4);
    car->unk134 = 0;
    car->unk138 = -1;
    car->unk173 = 0;
    *p171 = 0;
    i = 0;
    p4c = &car->unk4C;
    pe4 = &car->unkE4;
    pe8 = &car->unkE8;
    pec = &car->unkEC;
    p7d = &car->unk7D;
    p4e = &car->unk4E;
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
            break;
        case 10:
            v = 0xF;
            break;
        case 11:
            v = 0xF;
            break;
        case 12:
            v = 0x55;
            break;
        case 13:
            v = 0x12;
            break;
        case 14:
            v = 5;
            break;
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
    *p4c = v;
    if ((u8)(gUnk_0200215C - 3) > 1)
        *p4c = *p4c - 1;
    car->unk50 = 0;
    car->unk15C = 0x12C;
    car->unk0C = 0;
    car->unk14 = 0;
    car->unk110 = 0;
    car->unk140 = 0;
    car->unk144 = 0;
    car->unk13C = 0;
    car->unk148 = 0;
    car->unk14C = 0;
    car->unk150 = 0x63;
    *pe4 = gUnk_08367FBC[car->unk162];
    *pe8 = gUnk_08368034[car->unk162];
    *pec = gUnk_083680AC[car->unk162];
    if (gUnk_020020DC == 0) {
        if (idx != 0) {
            if (gUnk_0200215C != 2) {
                *pe4 = (u32)gUnk_08367BFA;
                *pe8 = (u32)gUnk_08367C06;
                *pec = (u32)gUnk_08367C10;
                *pe4 = gUnk_08367FBC[0];
                *pe8 = gUnk_08368034[0];
                *pec = gUnk_083680AC[0];
            }
        }
    }
    car->unk158 = 0;
    *p7d = 0;
    car->unk36 = (u16)a4;
    car->unk38 = 0;
    car->unk160 = 0;
    *p4e = 0;
    car->unk3C = 0;
}
