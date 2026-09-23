#include "global.h"

struct Car {
    u8 pad00[0x2C];
    s32 unk2C;
    u8 pad30[0x3E - 0x30];
    u8 unk3E;
    u16 unk40;
    u8 pad42[0x7C - 0x42];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x9C - 0x7E];
    s32 unk9C;
    u8 padA0[0xA2 - 0xA0];
    u16 unkA2;
    u8 padA4[0xE4 - 0xA4];
    u16 *unkE4;
    u16 *unkE8;
    u16 *unkEC;
    u8 padF0[0x13C - 0xF0];
    s32 unk13C;
    u8 pad140[0x14C - 0x140];
    s32 unk14C;
    u8 pad150[0x175 - 0x150];
    u8 unk175;
    u8 pad176[0x190 - 0x176];
};

extern u8 gUnk_0202EEB0;
extern struct Car gUnk_0202A550[];
extern u8 gUnk_0202A51C;
extern u8 gUnk_020020A8;
extern u8 gUnk_020021E0;
extern u8 gUnk_020020DC;

s16 sub_0800A034(struct Car *a);
void sub_0800A5BC(struct Car *a);

void sub_0800A084(struct Car *car, s32 arg1)
{
    u8 pad[0x28];
    register s32 v __asm__("r7");
    register s32 mode __asm__("r8");
    register u16 *pa __asm__("ip");
    register u16 **tbl __asm__("r9");
    struct Car *base;
    s32 t1;
    s32 t2;
    s32 t3;
    s16 r;
    u8 *gear;
    s16 *spd;

    mode = arg1;
    v = 0;
    if (mode & 1) {
        if (gUnk_0202EEB0 != 0 && car->unk175 == 0) {
            car->unk9C -= 0xA;
            if (car->unk9C < 0)
                car->unk9C = v;
        }
        car->unkA2 = 0x100;
        base = gUnk_0202A550;
        pa = &car->unkA2;
        if (car == base) {
            t1 = *(s32 *)((u32)pa - 6);
            if (t1 == 0 && (gUnk_0202A51C & 8) != 0)
                *pa = t1;
        }
        if (gUnk_020020A8 != 0) {
            t2 = (*pa * car->unkE4[car->unk3E]) >> 6;
            gear = &car->unk3E;
            tbl = &car->unkE4;
        } else {
            t2 = (*pa * car->unkE4[car->unk3E]) >> 8;
            gear = &car->unk3E;
            tbl = &car->unkE4;
        }
        v += t2;
        spd = &car->unk40;
        if (car->unk2C > 0)
            v += (*pa * (*tbl)[car->unk3E]) >> 5;
    } else if (car->unk2C > 0) {
        car->unk14C = -car->unk2C >> 2;
        gear = &car->unk3E;
    } else if (car->unkA2 != 0) {
        car->unkA2 -= 0x20;
        if (car->unkA2 > 0x8000)
            car->unkA2 = v;
        v = (car->unkA2 * car->unkE4[car->unk3E]) >> 8;
        gear = &car->unk3E;
    } else {
        v = -(car->unk40 * 4) >> 16;
        gear = &car->unk3E;
    }
    spd = &car->unk40;
    if (mode & 2) {
        v += -(car->unk40 * 6) >> 8;
        car->unk14C += 0x18000;
        if (car->unk2C > 0) {
            if (gUnk_020021E0 != 0 || (gUnk_020020DC != 0 && car->unk7D != 0))
                sub_0800A5BC(car);
            else if (car->unk2C > 0x3E800)
                car->unk14C = 0x3E800 - car->unk2C;
        }
    }
    if (car->unk2C < 0) {
        t3 = car->unk40;
        if (t3 + v > 0x32C8)
            v = 0x32C8 - t3;
        if (t3 + v < 0)
            v = -t3;
        car->unk40 = t3 + v;
    } else {
        car->unk40 = 0;
    }
    if (car->unk2C > 0)
        r = 0;
    else
        r = sub_0800A034(car);
    car->unk13C = -((-car->unkE8[car->unk3E]) * v) >> 8;
    if (car->unk2C <= 0) {
        car->unk40 = ((-car->unkEC[r]) * car->unk2C) >> 8;
        car->unk3E = r;
    } else {
        car->unk3E = 0;
        car->unk40 = 0;
    }
}
