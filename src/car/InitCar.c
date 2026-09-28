#include "global.h"
#include "data.h"
#include "variables.h"
#include "car.h"

extern const u16 *const gDriverGearPowerTables[];
extern const u16 *const gDriverGearRatioTables[];
extern const u16 *const gDriverRpmPerSpeedTables[];

void SetCarLaneByIndex(u32 a, u8 b);
void InitCarSteering(u32 *p, u32 v);

void InitCar(u8 a, struct Car *car, s32 b, s32 c, u32 d)
{
    u8 i;

    if (gGameMode[0] == 4)
        car->driverId = 0;
    car->lapStartedFlag = 0;
    car->pitState = 0;
    gPitMenuActive = 0;
    car->torqueDampTimer = 0;
    car->draftTimer = 0;
    car->trackCueCursor = gTrackCueList;
    car->lapsLed = 0;
    gFuelOutStutterCounter = 0;
    car->ledLapFlag = 1;
    car->lapLedTimer = 0;
    car->posX = b;
    car->posZ = c;
    car->heading = d;
    car->speed = 0;
    car->unk28 = 0;
    car->rpm = 0;
    car->gear = 0;
    car->hitCooldown = 0;
    car->waypoint = 0;
    car->firstStepCrossed = 0;
    if (gGameMode[0] == 4) {
        car->driverPalette = (u32)gDriverPalettes[a * 3];
    } else {
        car->driverPalette = (u32)gDriverPalettes[car->driverId];
    }
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
    if (gGameMode[0] == 0xF && gChallengeIndex == 3 && car == gCars)
        car->fuel = 0x5000;
    if (gGameMode[0] != 4)
        SetCarLaneByIndex((u32)car, a);
    if (gGameMode[0] != 5 && gGameMode[0] != 0x11)
        car->finishTime = 0;
    car->onApron = 0;
    car->onGrass = 0;
    car->behindBgFlag = 0;
    InitCarSteering((u32 *)&car->unk128, d);
    car->unk134 = 0;
    car->unk138 = -1;
    car->wasOnGrass = 0;
    car->onGrass = 0;
    i = 0;
    do {
        gPitStallOccupied[i] = 0;
        i++;
    } while (i != 8);
    /* One store per arm: jump2 merges the stores into one strb behind a new
       label, and jumps to a label created in that pass never cross-jump,
       so the equal-valued arms stay separate as in the ROM. */
    if (gGameMode[0] == 0xF) {
        switch (gChallengeIndex) {
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
    if ((u8)(gGameMode[0] - 3) > 1)
        car->lap--;
    car->progress = 0;
    car->tickCount = 0x12C;
    car->velX = 0;
    car->velZ = 0;
    car->unk110 = 0;
    car->forceX = 0;
    car->forceZ = 0;
    car->engineForce = 0;
    car->torque = 0;
    car->drag = 0;
    car->racePosition = 0x63;
    car->gearPowerTable = gDriverGearPowerTables[car->driverId];
    car->gearRatioTable = gDriverGearRatioTables[car->driverId];
    car->rpmPerSpeedTable = gDriverRpmPerSpeedTables[car->driverId];
    if (gIsLinkRace == 0 && a != 0 && gGameMode[0] != 2) {
        car->gearPowerTable = gAiDriverGearPowerTable;
        car->gearRatioTable = gAiDriverGearRatioTable;
        car->rpmPerSpeedTable = gAiDriverRpmPerSpeedTable;
        car->gearPowerTable = gDriverGearPowerTables[0];
        car->gearRatioTable = gDriverGearRatioTables[0];
        car->rpmPerSpeedTable = gDriverRpmPerSpeedTables[0];
    }
    car->unk158 = 0;
    car->finished = 0;
    car->respawnHeading = d;
    car->respawnWaypoint = 0;
    car->zoneGripFlag = 0;
    car->subStep = 0;
    car->yawRate = 0;
}
