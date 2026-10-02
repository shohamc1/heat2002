#include "global.h"
#include "variables.h"
#include "gba/io_reg.h"
#include "car.h"
#include "functions.h"

/*
 * Per-frame car update: the high-region (0x0834 module) copy of
 * sub_0800A80C, instruction-identical, ported from that matched source.
 * Its `/` libcalls resolve to the module copy through the Makefile rename
 * for src/sub_083[3-9]*.c objects.
 *
 * Per-frame car update: zero the impulse accumulators, run the sub-steps,
 * apply track collision (ModuleCollideCarWithWalls) and car collision (ModuleCollideCars),
 * then integrate position and heading.
 *
 * Shapes the retail bytes depend on:
 * - `unused[5]` is a 20-byte local the compiled code never touches; the
 *   ROM's frame is 20 bytes with no sp-relative access.
 * - `if (car->pitState != 0) v = 0; else v = ModuleCollideCarWithWalls(car);`: the
 *   redundant `v = 0` lets cse fold the following `v != 0` test on that
 *   path, so the branch is threaded past it. Without the else the branch
 *   lands on the test.
 * - The sound call is one call behind `DC == 0 ? car == base : car ==
 *   base + idx`, which gives the `beq/b` then `bne` layout.
 * - The `gUnk_020390CC` loop is written with a goto so loop.c does not
 *   hoist the store address out of it.
 * - Everything from the sound check to the unk40 division is inside
 *   `if (v != 0)`.
 */
extern u16 gModule_TrackAiDragDivisors[];
extern u16 gModule_PitEntryProgressPoints[];
extern u16 gModule_PitExitProgressPoints[];

void ModuleClampSteerHeading(struct Car *car)
{
    register u32 rot PIN(r9);
    u32 tableIdx;
    register s32 scale PIN(r1);
    s32 sinHeading;
    s32 cosHeading;
    register s32 sin1 PIN(r5);
    register s32 cos1 PIN(r4);
    register s32 steerIdx PIN(r2);
    register s32 steerVal PIN(r0);
    register s32 sinSteer PIN(r3);
    register s32 cosSteer PIN(r2);
    register s32 sin2 PIN(r8);
    s32 cos2;
    s32 newSteer;
    register s32 *steerPtr PIN(r6);
    s16 *p;
    register u32 rot2 PIN(r1);
    s32 tmp;
    register s32 idx PIN(r0);

    rot = (car->heading >> 10) << 16;
    tableIdx = rot >> 14;
    sinHeading = gModule_SinTable[tableIdx];
    cosHeading = gModule_SinTable[tableIdx + 0x40];
    scale = -256;
    tmp = -(sinHeading * scale);
    sin1 = tmp >> 8;
    tmp = cosHeading * scale;
    cos1 = tmp >> 8;
    steerPtr = &car->steerHeading;
    steerVal = *steerPtr;
    steerIdx = (steerVal >> 10) & 0x3F;
    steerIdx = steerIdx << 2;
    sinSteer = gModule_SinTable[steerIdx];
    idx = steerIdx;
    asm volatile("" : "+r"(idx));
    idx += 0x40;
    cosSteer = gModule_SinTable[idx];
    sin2 = -(sinSteer * scale) >> 8;
    cos2 = (cosSteer * scale) >> 8;
    if ((sin2 * sin1 + cos1 * cos2) >> 8 > 141)
        return;
    rot2 = rot;
    tableIdx = rot2 >> 14;
    p = &gModule_SinTable[tableIdx];
    sin1 = gModule_SinTable[tableIdx + 0x40];
    cos1 = *p;
    if (sin2 * sin1 + cos1 * cos2 < 0)
        newSteer = car->heading - 0x2800;
    else
        newSteer = car->heading + 0x2800;
    *steerPtr = newSteer;
    car->steerHeading = (u16)car->steerHeading;
}

void ModuleUpdateSteering(struct Car *car, u16 keys)
{
    s32 steerRate;
    u32 steerRamp;
    s32 speedTerm;

    car->unk84 = 1;
    if (car == gModule_Cars && car->speed > 0) {
        if (!(keys & (DPAD_RIGHT | DPAD_LEFT)))
            car->steerHeading = (car->steerHeading + car->heading) / 2;
        if (keys & DPAD_LEFT)
            car->steerHeading = car->heading - 0x1400;
        if (keys & DPAD_RIGHT) {
            car->steerHeading = car->heading + 0x1400;
        }
        return;
    }
    if (keys & (DPAD_RIGHT | DPAD_LEFT)) {
        u8 cur = car->steerRamp;
        if ((s8)car->steerRamp >= 0)
            car->steerRamp = cur + 1;
    } else {
        if (car->steerRamp != 0)
            car->steerRamp = car->steerRamp - 1;
    }
    steerRamp = car->steerRamp;
    steerRate = (steerRamp * 3 >> 2) + 0x100;
    speedTerm = -(car->speed) >> 12;
    if (speedTerm < 0)
        speedTerm = 0;
    speedTerm = 0xFF - speedTerm;
    steerRate += speedTerm * 2;
    if (keys & DPAD_LEFT) {
        car->steerHeading -= steerRate;
        car->unk84 = 0;
    } else if (keys & DPAD_RIGHT) {
        car->steerHeading += steerRate;
        car->unk84 = 2;
    }
}

void ModuleUpdateCarPhysics(struct Car *car, u32 keys, u8 idx)
{
    s32 unused[5];
    s32 wallHit;
    s32 dragBase;

    car->forceX = 0;
    car->forceZ = 0;
    car->torque = 0;
    ModuleResetCarSurface(car);
    if (car->hitCooldown != 0)
        car->hitCooldown--;
    ModuleUpdateSteering(car, keys);
    ModuleComputeForwardSpeed(car);
    ModuleUpdateEngine(car, keys);
    ModuleUpdateTireForces(car, idx);
    wallHit = 0;
    ModuleComputeCarCorners(car);
    if (gModule_GameMode == 4 || gModule_TrackId <= 11) {
        if (car->pitState != 0)
            wallHit = 0;
        else
            wallHit = ModuleCollideCarWithWalls(car);
    }
    if (wallHit != 0 && (u8)(car->carState - 1) <= 2)
        wallHit = -1;
    dragBase = car->speed >> 6;
    car->drag = dragBase * dragBase;
    if (dragBase > 0)
        car->drag = -car->drag;
    if (gModule_IsLinkRace != 0 || gModule_GameMode == 4 || gModule_GameMode == 3) {
        car->drag = car->drag / 215;
    } else if (car == gModule_Cars || gModule_GameMode == 9 || gModule_GameMode == 13 || gModule_GameMode == 14 ||
               gModule_GameMode == 15 || gModule_GameMode == 17 || gModule_GameMode == 4) {
        if (car->onApron != 0)
            car->drag = car->drag / 250;
        else if (car->onGrass != 0)
            car->drag = car->drag / 100;
        else
            car->drag = car->drag / 480;
    } else {
        car->drag = car->drag / gModule_TrackAiDragDivisors[gModule_TrackId];
    }
    if (gUnk_020390B8 != 0 && (u8)(gModule_GameMode - 3) > 1)
        car->drag = 0;
    if (car == gModule_Cars || gModule_IsLinkRace != 0) {
        if (gModule_GameMode != 9 && gModule_GameMode != 13 && gModule_GameMode != 14 && gModule_GameMode != 15 &&
            gModule_GameMode != 17 && (ModuleCheckDrafting(car) != 0 || car->draftTimer != 0)) {
            if (car->draftTimer != 0)
                car->draftTimer--;
            car->drag = (car->drag * 3) >> 2;
            ModuleAddDraftStreakTask(idx, 0);
            ModuleAddDraftStreakTask(idx, 1);
        }
    }
    if (gModule_GameMode != 2)
        ModuleCollideCars(car);
    car->prevProgress = car->progress;
again:
    gUnk_020390CC = ModuleUpdateLapProgress(car, idx);
    if (gUnk_020390CC != 0)
        goto again;
    car->posX += car->velX;
    car->posZ += car->velZ;
    car->heading = car->heading + car->yawRate;
    if (wallHit != 0) {
        if (gModule_IsDemo == 0 && gModule_RaceEndState == 0 && gModule_Options[3] != 0) {
            if (gModule_IsLinkRace == 0 ? car == gModule_Cars : car == gModule_Cars + gModule_LinkPlayerId)
                ModuleM4aSongNumStart(18);
        }
        if ((u8)(car->carState - 5) > 2 && gModule_DamagePitsEnabled != 0)
            car->damage -= wallHit >> 12;
        car->hitCooldown = 6;
        ModuleComputeForwardSpeed(car);
        car->impactSpeed = car->speed;
        if (car->speed > 0)
            car->impactSpeed = 0;
        car->rpm = (car->impactSpeed << 8) / -car->gearRatioTable[car->gear];
    }
    car->velX += car->forceX;
    car->velZ += car->forceZ;
    car->yawRate = (u16)car->torque + car->yawRate;
    car->yawRate = ((s16)car->yawRate * 31) >> 5;
}

void ModuleUpdateCar(struct Car *car, u8 idx)
{
    if (gModule_IsLinkRace != 0) {
        if (gModule_RaceEndState == 0 && car->finished == 0)
            ModuleUpdateCarPhysics(car, gUnk_020390B0[idx], idx);
        else
            ModuleUpdateCarPhysics(car, 2, idx);
        ModuleClampSteerHeading(car);
    }
    if (car->damage > 0x11940 && car->carState != 1 && (gModule_FrameCounter & 0x3F) == 0)
        ModuleAddDamageSmokeTask(car);
    if (gModule_IsLinkRace != 0) {
        if (idx == gModule_LinkPlayerId) {
            ModuleUpdateRacePosition(idx);
            if (gModule_Cars[idx].racePosition != 0 && gModule_Cars[idx].racePosition != 99)
                gModule_Cars[idx].ledLapFlag = 0;
        }
    } else if (idx == 0) {
        ModuleUpdateRacePosition(0);
        if (gModule_Cars[0].racePosition != 0 && gModule_Cars[0].racePosition != 99)
            gModule_Cars[0].ledLapFlag = idx;
    }
    car->tickCount++;
}

void ModuleUpdateAllCars(void)
{
    struct Car *car;
    u8 count;
    s32 i;
    u16 *unused;
    u8 pitStall;

    ModuleReadKeys();
    car = gModule_Cars;
    count = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0 || gModule_GameMode == 4)
        count = gModule_NumLinkPlayers[0];
    if (gModule_GameMode == 2)
        count = 1;
    gUnk_0203D4E8++;
    for (i = 0; i != count; i++) {
        ModuleUpdateCar(car, i);
        if (car->prevProgress <= gModule_PitEntryProgressPoints[gModule_TrackId] &&
            ((u32)car->progress & 0xFFFF) >= gModule_PitEntryProgressPoints[gModule_TrackId] &&
            ModuleCarNeedsPit(car) != 0 && car != gModule_Cars) {
            pitStall = gModule_DamagePitsEnabled;
            if (pitStall != 0) {
                pitStall = ModuleFindFreePitStall(pitStall);
                if (pitStall != 99)
                    ModuleEnterPit(car, ModuleFindFreePitStall(pitStall));
            }
        }
        if (car != gModule_Cars && car->pitState != 0) {
            if (car->prevProgress <= gModule_PitExitProgressPoints[gModule_TrackId] &&
                ((u32)car->progress & 0xFFFF) >= gModule_PitExitProgressPoints[gModule_TrackId])
                car->pitCollidable = 0;
        }
        car++;
    }
}
