#include "global.h"
#include "variables.h"
#include "car.h"

extern u8 gUnk_0203DCF0;
extern u32 gModule_DriverGearPowerTables[];
extern u32 gModule_DriverGearRatioTables[];
extern u32 gModule_DriverRpmPerSpeedTables[];

void ModuleInitCarSteering(s32 *p, u32 v);

void ModuleInitCar(u8 carIdx, struct Car *car, s32 posX, s32 posZ, u32 heading)
{
    u8 i;

    if (gModule_GameMode[0] == 4)
        car->driverId = 0;
    car->lapStartedFlag = 0;
    car->pitState = 0;
    gUnk_0203DCF0 = 0;
    car->torqueDampTimer = 0;
    car->draftTimer = 0;
    car->lapsLed = 0;
    gUnk_0203D4E8 = 0;
    car->ledLapFlag = 1;
    car->lapLedTimer = 0;
    car->posX = posX;
    car->posZ = posZ;
    car->heading = heading;
    car->speed = 0;
    car->unk28 = 0;
    car->rpm = 0;
    car->gear = 0;
    car->hitCooldown = 0;
    car->waypoint = 0;
    car->firstStepCrossed = 0;
    car->driverPalette = gModule_DriverPalettes[carIdx * 3];
    car->carState = 0;
    car->unk84 = 1;
    car->unk30 = 0;
    car->damage = 0;
    car->throttleLevel = 0;
    car->tireWear0 = 0;
    car->tireWear1 = 0;
    car->tireWear2 = 0;
    car->tireWear3 = 0;
    car->fuel = 0xB400;
    if (gModule_GameMode[0] == 0xF && gUnk_0203DFB0 == 3 && car == gModule_Cars)
        car->fuel = 0x5000;
    if (gModule_GameMode[0] != 5 && gModule_GameMode[0] != 0x11)
        car->finishTime = 0;
    car->onApron = 0;
    car->onGrass = 0;
    car->behindBgFlag = 0;
    ModuleInitCarSteering(&car->unk128, heading);
    car->unk134 = 0;
    car->unk138 = -1;
    car->wasOnGrass = 0;
    car->onGrass = 0;
    i = 0;
    do {
        gUnk_0203DDE8[i] = 0;
        i++;
    } while (i != 8);
    /* One store per arm: jump2 merges the stores into one strb behind a new
       label, and jumps to a label created in that pass never cross-jump,
       so the equal-valued arms stay separate as in the ROM. */
    if (gModule_GameMode[0] == 0xF) {
        switch (gUnk_0203DFB0) {
            case 0:
                car->lap = 1;
                break;
            case 1:
                car->lap = 4;
                break;
            case 2:
                car->lap = 5;
                break;
            case 3:
                car->lap = 0x28;
                break;
            case 6:
                car->lap = 0x28;
                break;
            case 10:
                car->lap = 0xF;
                break;
            case 11:
                car->lap = 0xF;
                break;
            case 12:
                car->lap = 0x55;
                break;
            case 13:
                car->lap = 0x12;
                break;
            case 14:
                car->lap = 5;
                break;
            case 15:
                car->lap = 0x14;
                break;
            default:
                car->lap = 0;
                break;
        }
    } else {
        car->lap = 0;
    }
    if ((u8)(gModule_GameMode[0] - 3) > 1)
        car->lap--;
    car->progress = 0;
    car->tickCount = 0x12C;
    car->velX = 0;
    car->velZ = 0;
    car->steerRamp = 0;
    car->forceX = 0;
    car->forceZ = 0;
    car->engineForce = 0;
    car->torque = 0;
    car->drag = 0;
    car->racePosition = 0x63;
    (*(s32 *)&car->gearPowerTable) = gModule_DriverGearPowerTables[car->driverId];
    (*(s32 *)&car->gearRatioTable) = gModule_DriverGearRatioTables[car->driverId];
    (*(s32 *)&car->rpmPerSpeedTable) = gModule_DriverRpmPerSpeedTables[car->driverId];
    if (gModule_IsLinkRace == 0 && carIdx != 0 && gModule_GameMode[0] != 2) {
        car->gearPowerTable = gUnk_0202713E;
        car->gearRatioTable = gUnk_0202714A;
        car->rpmPerSpeedTable = gUnk_02027154;
        (*(s32 *)&car->gearPowerTable) = gModule_DriverGearPowerTables[0];
        (*(s32 *)&car->gearRatioTable) = gModule_DriverGearRatioTables[0];
        (*(s32 *)&car->rpmPerSpeedTable) = gModule_DriverRpmPerSpeedTables[0];
    }
    car->unk158 = 0;
    car->finished = 0;
    car->respawnHeading = heading;
    car->respawnWaypoint = 0;
    car->zoneGripFlag = 0;
    car->subStep = 0;
    car->yawRate = 0;
}
