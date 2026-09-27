#include "global.h"
#include "functions.h"
#include "variables.h"

struct Car {
    u8 pad00[0x2C];
    s32 speed;
    u8 pad30[0x3E - 0x30];
    u8 gear;
    u16 rpm;
    u8 pad42[0x7C - 0x42];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x9C - 0x7E];
    s32 fuel;
    u8 padA0[0xA2 - 0xA0];
    u16 unkA2;
    u8 padA4[0xE4 - 0xA4];
    u16 *unkE4;
    u16 *unkE8;
    u16 *unkEC;
    u8 padF0[0x13C - 0xF0];
    s32 unk13C;
    u8 pad140[0x14C - 0x140];
    s32 drag;
    u8 pad150[0x175 - 0x150];
    u8 pitState;
    u8 pad176[0x190 - 0x176];
};

extern struct Car gCars[];

s16 sub_0800A034(struct Car *a);

void UpdateEngine(struct Car *car, s32 mode)
{
    u8 pad[0x28];
    s32 v;
    s32 t3;
    s32 r;

    v = 0;
    if (mode & 1) {
        if (gUnk_0202EEB0 != 0 && car->pitState == 0) {
            car->fuel -= 0xA;
            if (car->fuel < 0)
                car->fuel = 0;
        }
        car->unkA2 = 0x100;
        if (car == gCars && car->fuel == 0 && (gUnk_0202A51C & 8) != 0)
            car->unkA2 = 0;
        if (gUnk_020020A8 != 0)
            v += (car->unkE4[car->gear] * car->unkA2) >> 6;
        else
            v += (car->unkE4[car->gear] * car->unkA2) >> 8;
        if (car->speed > 0)
            v += (car->unkE4[car->gear] * car->unkA2) >> 5;
    } else if (car->speed > 0) {
        car->drag = -car->speed >> 2;
    } else if (car->unkA2 != 0) {
        car->unkA2 -= 0x20;
        if (car->unkA2 > 0x8000)
            car->unkA2 = 0;
        v = (car->unkE4[car->gear] * car->unkA2) >> 8;
    } else {
        v = -(car->rpm * 4) >> 16;
    }
    if (mode & 2) {
        v += -(car->rpm * 6) >> 8;
        car->drag += 0x18000;
        if (car->speed > 0) {
            if (gUnk_020021E0 != 0 || (gIsLinkRace != 0 && car->unk7D != 0))
                StopCar((struct Unk0A5BC *)car);
            else if (car->speed > 0x3E800)
                car->drag = 0x3E800 - car->speed;
        }
    }
    if (car->speed < 0) {
        t3 = car->rpm;
        if (t3 + v > 0x32C8)
            v = 0x32C8 - t3;
        if (t3 + v < 0)
            v = -t3;
        car->rpm = t3 + v;
    } else {
        car->rpm = 0;
    }
    t3 = car->speed;
    if (t3 <= 0)
        r = sub_0800A034(car);
    else
        r = 0;
    car->unk13C = -((-car->unkE8[car->gear]) * v) >> 8;
    if (car->speed <= 0) {
        car->rpm = ((-car->unkEC[r]) * car->speed) >> 8;
        car->gear = r;
    } else {
        car->gear = 0;
        car->rpm = 0;
    }
}
