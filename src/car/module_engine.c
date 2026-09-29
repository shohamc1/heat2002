#include "global.h"
#include "car.h"
#include "variables.h"

u32 ModuleGetGearForSpeed(struct Car *car, s32 speed);
void ModuleStopCar(struct Car *a);
extern s32 gUnk_020277B4[]; /* 0x020277B4 */
extern s32 gUnk_020277C4[]; /* 0x020277C4 */

u32 ModuleGetGearForSpeed(struct Car *car, s32 speed)
{
    u16 *rpmPerSpeedTable;
    s16 gear;
    s32 rpm;

    gear = 0;
    rpmPerSpeedTable = (u16 *)car->rpmPerSpeedTable;
    do {
        rpm = -(s32)rpmPerSpeedTable[gear] * speed >> 8;
        if ((u32)(rpm - 2001) <= 8998)
            return gear;
        gear++;
    } while (gear != 5);
    if (speed > -150000)
        return 0;
    return 4;
}

void ModuleUpdateEngine(struct Car *car, s32 mode)
{
    u8 pad[0x28];
    s32 v;
    s32 t3;
    s32 r;

    v = 0;
    if (mode & 1) {
        if (gModule_DamagePitsEnabled != 0 && car->pitState == 0) {
            car->fuel -= 0xA;
            if (car->fuel < 0)
                car->fuel = 0;
        }
        car->throttleLevel = 0x100;
        if (car == gModule_Cars && car->fuel == 0 && (gUnk_0203D4E8 & 8) != 0)
            car->throttleLevel = 0;
        if (gUnk_020390B8 != 0)
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
            if (gModule_RaceEndState != 0 || (gModule_IsLinkRace != 0 && car->finished != 0))
                ModuleStopCar(car);
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
        r = ((s16 (*)(struct Car *))ModuleGetGearForSpeed)(car);
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

void ModuleComputeForwardSpeed(u8 *car)
{
    s32 i;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    i = -(s32)(((struct Car *)car)->heading >> 11) & 0x1F;
    i = i << 3;
    dx = gModule_SinTable[i];
    i = i + 0x40;
    dy = gModule_SinTable[i];
    x = ((struct Car *)car)->velX;
    y = ((struct Car *)car)->velZ;
    ((struct Car *)car)->speed = (x * dx + y * dy) >> 8;
}

void ModuleComputeCarCorners(struct Car *car)
{
    s32 sin;
    s32 cos;
    s32 i;
    u32 idx;
    s32 offsetX;
    s32 offsetZ;

    idx = car->heading >> 8;
    sin = gModule_SinTable[idx];
    cos = gModule_SinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        offsetX = gUnk_020277B4[i];
        offsetZ = gUnk_020277C4[i];
        car->cornerX[i] = (cos * offsetX - sin * offsetZ) >> 8;
        car->cornerZ[i] = (sin * offsetX + cos * offsetZ) >> 8;
        car->cornerX[i] += car->posX;
        car->cornerZ[i] += car->posZ;
    }

    idx = (car->heading + (s16)car->yawRate) >> 8 & 0xFF;
    sin = gModule_SinTable[idx];
    cos = gModule_SinTable[idx + 0x40];
    for (i = 0; i != 4; i++) {
        offsetX = gUnk_020277B4[i];
        offsetZ = gUnk_020277C4[i];
        car->nextCornerX[i] = (cos * offsetX - sin * offsetZ) >> 8;
        car->nextCornerZ[i] = (sin * offsetX + cos * offsetZ) >> 8;
        car->nextCornerX[i] += car->posX + car->velX;
        car->nextCornerZ[i] += car->posZ + car->velZ;
    }
}
