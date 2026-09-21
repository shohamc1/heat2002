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

extern u8 gUnk_0203E0E0;
extern struct Car gUnk_0203D520[];
extern u8 gUnk_0203D4E8;
extern u8 gUnk_020390B8;
extern u8 gUnk_020391F0;
extern u8 gUnk_020390EC;

s32 sub_08341AC4(u8 *a, s32 b);
void sub_08342008(struct Car *a);

void sub_08341B14(struct Car *car, s32 arg1)
{
    u8 pad[0x28];
    s32 v;
    s32 t;
    s16 r;
    u8 *gear;
    s16 *spd;
    s32 junk;

    v = 0;
    if (arg1 & 1) {
        if (gUnk_0203E0E0 != 0 && car->unk175 == 0) {
            car->unk9C -= 0xA;
            if (car->unk9C < 0)
                car->unk9C = 0;
        }
        car->unkA2 = 0x100;
        if (car == gUnk_0203D520) {
            t = car->unk9C;
            if (t == 0 && (gUnk_0203D4E8 & 8) != 0)
                car->unkA2 = t;
        }
        if (gUnk_020390B8 != 0)
            t = (car->unkA2 * car->unkE4[car->unk3E]) >> 6;
        else
            t = (car->unkA2 * car->unkE4[car->unk3E]) >> 8;
        v += t;
        gear = &car->unk3E;
        spd = &car->unk40;
        if (car->unk2C > 0)
            v += (car->unkA2 * car->unkE4[car->unk3E]) >> 5;
    } else if (car->unk2C > 0) {
        car->unk14C = -car->unk2C >> 2;
        gear = &car->unk3E;
    } else if (car->unkA2 != 0) {
        car->unkA2 -= 0x20;
        if ((s16)car->unkA2 < 0)
            car->unkA2 = 0;
        v = (car->unkA2 * car->unkE4[car->unk3E]) >> 8;
        gear = &car->unk3E;
    } else {
        v = -(car->unk40 * 4) >> 16;
        gear = &car->unk3E;
    }
    spd = &car->unk40;
    if (arg1 & 2) {
        v += -(car->unk40 * 6) >> 8;
        car->unk14C += 0x18000;
        if (car->unk2C > 0) {
            if (gUnk_020391F0 != 0 || (gUnk_020390EC != 0 && car->unk7D != 0))
                sub_08342008(car);
            else if (car->unk2C > 0x3E800)
                car->unk14C = 0x3E800 - car->unk2C;
        }
    }
    if (car->unk2C < 0) {
        t = car->unk40;
        if (t + v > 0x32C8)
            v = 0x32C8 - t;
        if (t + v < 0)
            v = -t;
        car->unk40 = t + v;
    } else {
        car->unk40 = 0;
    }
    if (car->unk2C > 0)
        r = 0;
    else
        r = sub_08341AC4(car, junk);
    car->unk13C = -((-car->unkE8[car->unk3E]) * v) >> 8;
    if (car->unk2C <= 0) {
        car->unk40 = ((-car->unkEC[r]) * car->unk2C) >> 8;
        car->unk3E = r;
    } else {
        car->unk3E = 0;
        car->unk40 = 0;
    }
}
