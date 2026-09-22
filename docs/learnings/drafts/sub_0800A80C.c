/* 2026-09-22: frame pad corrected to match target `sub sp` exactly (sub_0800A80C). */
#include "global.h"

struct Car {
    s32 unk00;                          /* 0x00 */
    u8 pad04[4];
    s32 unk08;                          /* 0x08 */
    s32 unk0C;                          /* 0x0C */
    u8 pad10[4];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x2C - 0x18];
    s32 unk2C;                          /* 0x2C */
    u8 pad30[4];
    u16 unk34;                          /* 0x34 */
    u16 unk3C;                          /* 0x3C */
    u8 unk3E;                           /* 0x3E */
    u8 pad3F;
    s16 unk40;                          /* 0x40 */
    u8 pad42[6];
    s32 unk48;                          /* 0x48 */
    u8 pad4C[8];
    s32 unk50;                          /* 0x50 */
    u8 pad54;
    u8 unk55;                           /* 0x55 */
    u8 pad56[0x7C - 0x56];
    u8 unk7C;                           /* 0x7C */
    u8 pad7D[0x88 - 0x7D];
    s32 unk88;                          /* 0x88 */
    u8 pad8C[0xE8 - 0x8C];
    u16 *unkE8;                         /* 0xE8 */
    u8 padEC[0x140 - 0xEC];
    s32 unk140;                         /* 0x140 */
    s32 unk144;                         /* 0x144 */
    s32 unk148;                         /* 0x148 */
    s32 unk14C;                         /* 0x14C */
    u8 pad150[0x170 - 0x150];
    u8 unk170;                          /* 0x170 */
    u8 unk171;                          /* 0x171 */
    u8 pad172[3];
    u8 unk175;                          /* 0x175 */
    u8 unk176;                          /* 0x176 */
    u8 pad177[0x18C - 0x177];
    u16 unk18C;                         /* 0x18C */
    u8 pad18E[0x190 - 0x18E];
};

extern u8 gUnk_0200215C;
extern u8 gUnk_020020CC;
extern u8 gUnk_020020DC;
extern u8 gUnk_020020A8;
extern u8 gUnk_020020E0;
extern u8 gUnk_020021E0;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202EF90;
extern u8 gUnk_020020BC;
extern struct Car gUnk_0202A550[];
extern u16 gUnk_08368290[];

void sub_08007C44(struct Car *a);
void sub_0800A708(struct Car *a, u16 keys);
void sub_0800A2D4(struct Car *a);
void sub_0800A084(struct Car *a, u32 b);
void sub_08008480(struct Car *a, u8 b);
void sub_0800A310(struct Car *a);
s32 sub_0800D248(struct Car *a);
u8 sub_0800C164(struct Car *a);
void sub_0800B618(u8 a, u8 b);
u8 sub_0800D684(struct Car *a);
u8 sub_08006A34(struct Car *p, u8 a1);
void sub_08001208(u16 idx);

void sub_0800A80C(struct Car *car, u32 b, u8 c)
{
    u8 unused[0x10];
    s32 v;
    s32 t;
    u32 off;

    car->unk140 = 0;
    off = 0x144;
    *(s32 *)((u8 *)car + off) = 0;
    off += 4;
    *(s32 *)((u8 *)car + off) = 0;
    sub_08007C44(car);
    if (car->unk55 != 0)
        car->unk55--;
    sub_0800A708(car, b);
    sub_0800A2D4(car);
    sub_0800A084(car, b);
    sub_08008480(car, c);
    v = 0;
    sub_0800A310(car);
    if (gUnk_0200215C == 4 || gUnk_020020CC <= 0xB) {
        if (car->unk175 == 0)
            v = sub_0800D248(car);
    }
    if (v != 0 && (u8)(car->unk7C - 1) <= 2)
        v = -1;
    t = car->unk2C >> 6;
    car->unk14C = t * t;
    if (t > 0)
        car->unk14C = -car->unk14C;
    if (gUnk_020020DC != 0 || gUnk_0200215C == 4 || gUnk_0200215C == 3) {
        car->unk14C = car->unk14C / 215;
    } else if (car == gUnk_0202A550 || gUnk_0200215C == 9 || gUnk_0200215C == 0xD
        || gUnk_0200215C == 0xE || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11
        || gUnk_0200215C == 4) {
        if (car->unk170 != 0)
            car->unk14C = car->unk14C / 250;
        else if (car->unk171 != 0)
            car->unk14C = car->unk14C / 100;
        else
            car->unk14C = car->unk14C / 480;
    } else {
        car->unk14C = car->unk14C / gUnk_08368290[gUnk_020020CC];
    }
    if (gUnk_020020A8 != 0 && (u8)(gUnk_0200215C - 3) > 1)
        car->unk14C = 0;
    if (car == gUnk_0202A550 || gUnk_020020DC != 0) {
        if (gUnk_0200215C != 9 && gUnk_0200215C != 0xD && gUnk_0200215C != 0xE
            && gUnk_0200215C != 0xF && gUnk_0200215C != 0x11
            && (sub_0800C164(car) != 0 || car->unk176 != 0)) {
            if (car->unk176 != 0)
                car->unk176--;
            car->unk14C = car->unk14C * 3 / 4;
            sub_0800B618(c, 0);
            sub_0800B618(c, 1);
        }
    }
    if (gUnk_0200215C != 2)
        sub_0800D684(car);
    car->unk18C = car->unk50;
    do {
        gUnk_020020BC = sub_08006A34(car, c);
    } while (gUnk_020020BC != 0);
    car->unk00 += car->unk0C;
    car->unk08 += car->unk14;
    car->unk34 = car->unk34 + car->unk3C;
    if (v != 0) {
        if (gUnk_020020E0 == 0 && gUnk_020021E0 == 0 && gUnk_0202EF00[3] != 0) {
            if (gUnk_020020DC != 0) {
                if (car == gUnk_0202A550 + gUnk_0202EF90)
                    sub_08001208(0x12);
            } else if (car == gUnk_0202A550) {
                sub_08001208(0x12);
            }
        }
    }
    if ((u8)(car->unk7C - 5) > 2 && gUnk_0202EEB0 != 0)
        car->unk88 -= v >> 12;
    car->unk55 = 6;
    sub_0800A2D4(car);
    car->unk48 = car->unk2C;
    if (car->unk2C > 0)
        car->unk48 = 0;
    car->unk40 = (car->unk48 << 8) / -car->unkE8[car->unk3E];
    car->unk0C += car->unk140;
    car->unk14 += car->unk144;
    car->unk3C = car->unk3C + *(u16 *)&car->unk148;
    car->unk3C = ((s16)car->unk3C * 31) >> 5;
}
