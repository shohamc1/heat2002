#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
s16 sub_0800A034(struct Car *a);
#include "data.h"
struct Unk0800A310 {
    u32 posX;
    u32 unk4;
    u32 posZ;
    u32 velX;
    u32 unk10;
    u32 velZ;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 speed;
    u32 unk30;
    u16 heading;
    u16 respawnHeading;
    u16 respawnWaypoint;
    u16 unk3A;
    s16 yawRate;
    u8 pad3E[0xA4 - 0x3E];
    s32 cornerX[4];
    s32 cornerZ[4];
    s32 nextCornerX[4];
    s32 nextCornerZ[4];
};
extern s32 gCornerOffsetX[]; /* 0x08368270 */
extern s32 gCornerOffsetZ[]; /* 0x08368280 */

void UpdateEngine(struct Car *car, s32 mode)
{
    u8 pad[0x28];
    s32 v;
    s32 t3;
    s32 r;

    v = 0;
    if (mode & 1) {
        if (gDamagePitsEnabled != 0 && car->pitState == 0) {
            car->fuel -= 0xA;
            if (car->fuel < 0)
                car->fuel = 0;
        }
        car->throttleLevel = 0x100;
        if (car == gCars && car->fuel == 0 && (gFuelOutStutterCounter & 8) != 0)
            car->throttleLevel = 0;
        if (gPreRaceSimActive != 0)
            v += (car->gearPowerTable[car->gear] * car->throttleLevel) >> 6;
        else
            v += (car->gearPowerTable[car->gear] * car->throttleLevel) >> 8;
        if (car->speed > 0)
            v += (car->gearPowerTable[car->gear] * car->throttleLevel) >> 5;
    } else if (car->speed > 0) {
        car->drag = -car->speed >> 2;
    } else if (car->throttleLevel != 0) {
        car->throttleLevel -= 0x20;
        if (car->throttleLevel > 0x8000)
            car->throttleLevel = 0;
        v = (car->gearPowerTable[car->gear] * car->throttleLevel) >> 8;
    } else {
        v = -(car->rpm * 4) >> 16;
    }
    if (mode & 2) {
        v += -(car->rpm * 6) >> 8;
        car->drag += 0x18000;
        if (car->speed > 0) {
            if (gRaceEndState != 0 || (gIsLinkRace != 0 && car->finished != 0))
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
    car->engineForce = -((-car->gearRatioTable[car->gear]) * v) >> 8;
    if (car->speed <= 0) {
        car->rpm = ((-car->rpmPerSpeedTable[r]) * car->speed) >> 8;
        car->gear = r;
    } else {
        car->gear = 0;
        car->rpm = 0;
    }
}

void ComputeForwardSpeed(s32 *a)
{
    u32 ang;
    u16 i;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    ang = ((u16 *)a)[0x1A];
    i = (-(ang >> 11) & 0x1F) << 3;
    dx = gSinTable[i];
    dy = gSinTable[i + 0x40];
    x = a[3];
    y = a[5];
    a[0xB] = (x * dx + y * dy) >> 8;
}

void ComputeCarCorners(struct Unk0800A310 *obj)
{
    s32 sin;
    s32 cos;
    s32 i;
    u32 idx;
    s32 a;
    s32 b;

    idx = obj->heading >> 8;
    sin = gSinTable[idx];
    cos = gSinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gCornerOffsetX[i];
        b = gCornerOffsetZ[i];
        obj->cornerX[i] = (cos * a - sin * b) >> 8;
        obj->cornerZ[i] = (sin * a + cos * b) >> 8;
        obj->cornerX[i] += obj->posX;
        obj->cornerZ[i] += obj->posZ;
    }

    idx = (obj->heading + obj->yawRate) >> 8 & 0xFF;
    sin = gSinTable[idx];
    cos = gSinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        a = gCornerOffsetX[i];
        b = gCornerOffsetZ[i];
        obj->nextCornerX[i] = (cos * a - sin * b) >> 8;
        obj->nextCornerZ[i] = (sin * a + cos * b) >> 8;
        obj->nextCornerX[i] += obj->posX + obj->velX;
        obj->nextCornerZ[i] += obj->posZ + obj->velZ;
    }
}
