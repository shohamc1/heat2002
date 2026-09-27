#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

s16 sub_0800A034(struct Car *a);

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
