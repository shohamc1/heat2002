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
extern u16 gUnk_020277D4[];
void ModuleResetCarSurface(struct Car *a);
void ModuleComputeForwardSpeed(struct Car *a);
void ModuleUpdateEngine(struct Car *a, u32 b);
void ModuleUpdateTireForces(struct Car *a, u8 b);
void ModuleComputeCarCorners(struct Car *a);
s32 ModuleCollideCarWithWalls(struct Car *a);
s32 ModuleCheckDrafting(struct Car *a);
void ModuleAddDraftStreakTask(u8 a, u8 b);
u8 ModuleCollideCars(struct Car *a);
u8 ModuleUpdateLapProgress(struct Car *p, u8 a1);
void ModuleM4aSongNumStart(u16 idx);
void ModuleAddDamageSmokeTask(u8 *a);
void ModuleUpdateRacePosition(u8 idx);
extern u16 gUnk_02026DC4[];
extern u16 gUnk_02026DDC[];
u8 ModuleCarNeedsPit(struct Car *p);
u8 ModuleFindFreePitStall(u8 a);
void ModuleEnterPit(struct Car *p, u8 a);

void ModuleClampSteerHeading(struct Car *car)
{
    register u32 rot asm("r9");
    u32 tableIdx;
    register s32 scale asm("r1");
    s32 sinHeading;
    s32 cosHeading;
    register s32 sin1 asm("r5");
    register s32 cos1 asm("r4");
    register s32 steerIdx asm("r2");
    register s32 steerVal asm("r0");
    register s32 sinSteer asm("r3");
    register s32 cosSteer asm("r2");
    register s32 sin2 asm("r8");
    s32 cos2;
    s32 newSteer;
    register s32 *steerPtr asm("r6");
    s16 *p;
    register u32 rot2 asm("r1");
    s32 tmp;
    register s32 idx asm("r0");

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
    if ((sin2 * sin1 + cos1 * cos2) >> 8 > 0x8D)
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
    car->steerHeading = *(u16 *)&car->steerHeading;
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
        u8 cur = car->unk110;
        if ((s8)car->unk110 >= 0)
            car->unk110 = cur + 1;
    } else {
        if (car->unk110 != 0)
            car->unk110 = car->unk110 - 1;
    }
    steerRamp = car->unk110;
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
    if (gModule_GameMode[0] == 4 || gModule_TrackId <= 0xB) {
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
    if (gModule_IsLinkRace != 0 || gModule_GameMode[0] == 4 || gModule_GameMode[0] == 3) {
        car->drag = car->drag / 215;
    } else if (car == gModule_Cars || gModule_GameMode[0] == 9 || gModule_GameMode[0] == 0xD ||
               gModule_GameMode[0] == 0xE || gModule_GameMode[0] == 0xF || gModule_GameMode[0] == 0x11 ||
               gModule_GameMode[0] == 4) {
        if (car->onApron != 0)
            car->drag = car->drag / 250;
        else if (car->onGrass != 0)
            car->drag = car->drag / 100;
        else
            car->drag = car->drag / 480;
    } else {
        car->drag = car->drag / gUnk_020277D4[gModule_TrackId];
    }
    if (gUnk_020390B8 != 0 && (u8)(gModule_GameMode[0] - 3) > 1)
        car->drag = 0;
    if (car == gModule_Cars || gModule_IsLinkRace != 0) {
        if (gModule_GameMode[0] != 9 && gModule_GameMode[0] != 0xD && gModule_GameMode[0] != 0xE &&
            gModule_GameMode[0] != 0xF && gModule_GameMode[0] != 0x11 &&
            (ModuleCheckDrafting(car) != 0 || car->draftTimer != 0)) {
            if (car->draftTimer != 0)
                car->draftTimer--;
            car->drag = (car->drag * 3) >> 2;
            ModuleAddDraftStreakTask(idx, 0);
            ModuleAddDraftStreakTask(idx, 1);
        }
    }
    if (gModule_GameMode[0] != 2)
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
        if (gModule_IsDemo[0] == 0 && gModule_RaceEndState == 0 && gModule_Options[3] != 0) {
            if (gModule_IsLinkRace == 0 ? car == gModule_Cars : car == gModule_Cars + gModule_LinkPlayerId)
                ModuleM4aSongNumStart(0x12);
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
    car->yawRate = *(u16 *)&car->torque + car->yawRate;
    car->yawRate = ((s16)car->yawRate * 31) >> 5;
}

void ModuleUpdateCar(u8 *car, u8 idx)
{
    u8 *posCar;
    u8 *carsBase;
    u32 byteOffset;

    if (gModule_IsLinkRace != 0) {
        if (gModule_RaceEndState == 0 && car[0x7D] == 0)
            ModuleUpdateCarPhysics(car, gUnk_020390B0[idx], idx);
        else
            ModuleUpdateCarPhysics(car, 2, idx);
        ModuleClampSteerHeading((struct Car *)car);
    }
    if (*(s32 *)(car + 0x88) > 0x11940 && car[0x7C] != 1 && (gModule_FrameCounter & 0x3F) == 0)
        ModuleAddDamageSmokeTask(car);
    if (gModule_IsLinkRace != 0) {
        if (idx == gModule_LinkPlayerId) {
            ModuleUpdateRacePosition(idx);
            carsBase = (u8 *)gModule_Cars;
            byteOffset = idx * 400;
            posCar = byteOffset + carsBase;
            if (posCar[0x150] != 0 && posCar[0x150] != 0x63)
                posCar[0x166] = 0;
        }
    } else if (idx == 0) {
        ModuleUpdateRacePosition(0);
        posCar = (u8 *)gModule_Cars;
        byteOffset = 0x150;
        if (posCar[byteOffset] != 0 && posCar[byteOffset] != 0x63)
            posCar[byteOffset + 0x16] = idx;
    }
    *(s32 *)(car + 0x15C) += 1;
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
    if (gModule_IsLinkRace != 0 || gModule_GameMode[0] == 4)
        count = gModule_NumLinkPlayers[0];
    if (gModule_GameMode[0] == 2)
        count = 1;
    gUnk_0203D4E8++;
    for (i = 0; i != count; i++) {
        ModuleUpdateCar(car, i);
        if (car->prevProgress <= gUnk_02026DC4[gModule_TrackId] &&
            (*(u32 *)&car->progress & 0xFFFF) >= gUnk_02026DC4[gModule_TrackId] && ModuleCarNeedsPit(car) != 0 &&
            car != gModule_Cars) {
            pitStall = gModule_DamagePitsEnabled;
            if (pitStall != 0) {
                pitStall = ModuleFindFreePitStall(pitStall);
                if (pitStall != 0x63)
                    ModuleEnterPit(car, ModuleFindFreePitStall(pitStall));
            }
        }
        if (car != gModule_Cars && car->pitState != 0) {
            if (car->prevProgress <= gUnk_02026DDC[gModule_TrackId] &&
                (*(u32 *)&car->progress & 0xFFFF) >= gUnk_02026DDC[gModule_TrackId])
                car->pitCollidable = 0;
        }
        car++;
    }
}
