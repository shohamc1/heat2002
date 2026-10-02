#include "global.h"
#include "gba/io_reg.h"
#include "car.h"
#include "m4a.h"
#include "variables.h"
#include "functions.h"
#include "data.h"

/*
 * Per-frame car update: zero the impulse accumulators, run the sub-steps,
 * apply track collision (CollideCarWithWalls) and car collision (CollideCars),
 * then integrate position and heading.
 *
 * Shapes the retail bytes depend on:
 * - `unused[5]` is a 20-byte local the compiled code never touches; the
 *   ROM's frame is 20 bytes with no sp-relative access.
 * - `if (car->pitState != 0) v = 0; else v = CollideCarWithWalls(car);`: the
 *   redundant `v = 0` lets cse fold the following `v != 0` test on that
 *   path, so the branch is threaded past it. Without the else the branch
 *   lands on the test.
 * - The sound call is one call behind `DC == 0 ? car == base : car ==
 *   base + idx`, which gives the `beq/b` then `bne` layout.
 * - The `gLapProgressAdvanced` loop is written with a goto so loop.c does not
 *   hoist the store address out of it.
 * - Everything from the sound check to the unk40 division is inside
 *   `if (v != 0)`.
 */
extern u16 gTrackAiDragDivisors[];
void ClampSteerHeading(struct Car *car);
extern u16 gPitEntryProgressPoints[];
extern u16 gPitExitProgressPoints[];

/* gLapProgressAdvanced (0x020020BC) and gIsLinkRace (0x020020DC) moved to
   src/system/globals.c, the 0x02000DE0-0x02022E20 EWRAM run's owner, and
   gFuelOutStutterCounter (0x0202A51C) to src/car/globals.c, the
   0x0202A510-0x0202CBE0 run's owner; all three are declared in
   variables.h. */

void ClampSteerHeading(struct Car *car)
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
    const s16 *p;
    register u32 rot2 PIN(r1);
    s32 tmp;
    register s32 idx PIN(r0);

    rot = (car->heading >> 10) << 16;
    tableIdx = rot >> 14;
    sinHeading = gSinTable[tableIdx];
    cosHeading = gSinTable[tableIdx + 0x40];
    scale = -256;
    tmp = -(sinHeading * scale);
    sin1 = tmp >> 8;
    tmp = cosHeading * scale;
    cos1 = tmp >> 8;
    steerPtr = &car->steerHeading;
    steerVal = *steerPtr;
    steerIdx = (steerVal >> 10) & 0x3F;
    steerIdx = steerIdx << 2;
    sinSteer = gSinTable[steerIdx];
    idx = steerIdx;
    asm volatile("" : "+r"(idx));
    idx += 0x40;
    cosSteer = gSinTable[idx];
    sin2 = -(sinSteer * scale) >> 8;
    cos2 = (cosSteer * scale) >> 8;
    if ((sin2 * sin1 + cos1 * cos2) >> 8 > 141)
        return;
    rot2 = rot;
    tableIdx = rot2 >> 14;
    p = &gSinTable[tableIdx];
    sin1 = gSinTable[tableIdx + 0x40];
    cos1 = *p;
    if (sin2 * sin1 + cos1 * cos2 < 0)
        newSteer = car->heading - 0x2800;
    else
        newSteer = car->heading + 0x2800;
    *steerPtr = newSteer;
    car->steerHeading = (u16)car->steerHeading;
}

void UpdateSteering(struct Car *car, u16 keys)
{
    s32 t;
    u32 v;
    s32 x;

    car->unk84 = 1;
    if (car == gCars && car->speed > 0) {
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
    v = car->steerRamp;
    t = (v * 3 >> 2) + 0x100;
    x = -(car->speed) >> 12;
    if (x < 0)
        x = 0;
    x = 0xFF - x;
    t += x * 2;
    if (keys & DPAD_LEFT) {
        car->steerHeading -= t;
        car->unk84 = 0;
    } else if (keys & DPAD_RIGHT) {
        car->steerHeading += t;
        car->unk84 = 2;
    }
}

void UpdateCarPhysics(struct Car *car, u32 b, u8 c)
{
    s32 unused[5];
    s32 v;
    s32 t;

    car->forceX = 0;
    car->forceZ = 0;
    car->torque = 0;
    UpdateCarSurface(car);
    if (car->hitCooldown != 0)
        car->hitCooldown--;
    UpdateSteering(car, b);
    ComputeForwardSpeed(car);
    UpdateEngine(car, b);
    UpdateTireForces(car, c);
    v = 0;
    ComputeCarCorners(car);
    if (gGameMode == 4 || gTrackId <= 11) {
        if (car->pitState != 0)
            v = 0;
        else
            v = CollideCarWithWalls(car);
    }
    if (v != 0 && (u8)(car->carState - 1) <= 2)
        v = -1;
    t = car->speed >> 6;
    car->drag = t * t;
    if (t > 0)
        car->drag = -car->drag;
    if (gIsLinkRace != 0 || gGameMode == 4 || gGameMode == 3) {
        car->drag = car->drag / 215;
    } else if (car == gCars || gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 ||
               gGameMode == 17 || gGameMode == 4) {
        if (car->onApron != 0)
            car->drag = car->drag / 250;
        else if (car->onGrass != 0)
            car->drag = car->drag / 100;
        else
            car->drag = car->drag / 480;
    } else {
        car->drag = car->drag / gTrackAiDragDivisors[gTrackId];
    }
    if (gPreRaceSimActive != 0 && (u8)(gGameMode - 3) > 1)
        car->drag = 0;
    if (car == gCars || gIsLinkRace != 0) {
        if (gGameMode != 9 && gGameMode != 13 && gGameMode != 14 && gGameMode != 15 && gGameMode != 17 &&
            (CheckDrafting(car) != 0 || car->draftTimer != 0)) {
            if (car->draftTimer != 0)
                car->draftTimer--;
            car->drag = (car->drag * 3) >> 2;
            AddDraftStreakTask(c, 0);
            AddDraftStreakTask(c, 1);
        }
    }
    if (gGameMode != 2)
        CollideCars(car);
    car->prevProgress = car->progress;
again:
    gLapProgressAdvanced = UpdateLapProgress(car, c);
    if (gLapProgressAdvanced != 0)
        goto again;
    car->posX += car->velX;
    car->posZ += car->velZ;
    car->heading = car->heading + car->yawRate;
    if (v != 0) {
        if (gIsDemo == 0 && gRaceEndState == 0 && gOptions[3] != 0) {
            if (gIsLinkRace == 0 ? car == gCars : car == gCars + gLinkPlayerId)
                m4aSongNumStart(18);
        }
        if ((u8)(car->carState - 5) > 2 && gDamagePitsEnabled != 0)
            car->damage -= v >> 12;
        car->hitCooldown = 6;
        ComputeForwardSpeed(car);
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

void UpdateCar(struct Car *car, u8 idx)
{
    u16 *p;
    u32 v;

    v = gIsLinkRace;
    if (v != 0) {
        if (gRaceEndState == 0 && car->finished == 0)
            UpdateCarPhysics(car, gPlayerKeys[idx], idx);
        else
            UpdateCarPhysics(car, 2, idx);
        ClampSteerHeading(car);
    } else if (idx == 0) {
        if (car->pitState != 0) {
            UpdatePitStop(car, 0);
            UpdateCarPhysics(car, car->aiInput, 0);
        } else if (gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 || gGameMode == 17) {
            UpdateAiDriver(car, idx);
            UpdateCarPhysics(car, car->aiInput, idx);
        } else {
            /* One shared ClampSteerHeading call, as in the gIsLinkRace branch:
               a call that ends a block before a label gets a USE insn from
               flow, which keeps jump2 from cross-jumping the call itself. */
            if (gRaceEndState == 0)
                UpdateCarPhysics(car, gKeysHeld, 0);
            else
                UpdateCarPhysics(car, 2, 0);
            ClampSteerHeading(car);
        }
    } else {
        if (gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 || gGameMode == 17)
            goto common;
        if (gGameMode != 4) {
            if (gRaceEndState == 0) {
                if (car->pitState != 0) {
                    UpdatePitStop(car, idx);
                } else {
                common:
                    UpdateAiDriver(car, idx);
                }
                p = &car->aiInput;
            } else {
                car->aiInput = 2;
                p = &car->aiInput;
            }
        } else {
            car->aiInput = v;
            p = &car->aiInput;
        }
        ClampSteerHeading(car);
        UpdateCarPhysics(car, *p, idx);
    }

    if (car->damage > 0x11940 && car->carState != 1 && ((*(u32 *)&gFrameCounter) & 0x3F) == 0)
        AddDamageSmokeTask(car);

    if (gIsLinkRace != 0) {
        if (idx == gLinkPlayerId) {
            UpdateRacePosition(idx);
            if (gCars[idx].racePosition != 0 && gCars[idx].racePosition != 99)
                gCars[idx].ledLapFlag = 0;
        }
    } else if (idx == 0) {
        UpdateRacePosition(0);
        if (gCars[0].racePosition != 0 && gCars[0].racePosition != 99)
            gCars[0].ledLapFlag = idx;
    }
    car->tickCount++;
}

void UpdateAllCars(void)
{
    struct Car *p;
    u8 count;
    s32 i;
    u16 *t;
    u8 v;

    ReadKeys();
    p = gCars;
    count = gNumCars[0];
    if (gIsLinkRace != 0 || gGameMode == 4)
        count = gNumLinkPlayers[0];
    if (gGameMode == 2)
        count = 1;
    gFuelOutStutterCounter++;
    for (i = 0; i != count; i++) {
        UpdateCar(p, i);
        if (p->prevProgress <= gPitEntryProgressPoints[gTrackId] &&
            ((u32)p->progress & 0xFFFF) >= gPitEntryProgressPoints[gTrackId] && CarNeedsPit(p) != 0 && p != gCars) {
            v = gDamagePitsEnabled;
            if (v != 0) {
                v = FindFreePitStall(v);
                if (v != 99)
                    EnterPit(p, FindFreePitStall(v));
            }
        }
        if (p != gCars && p->pitState != 0) {
            if (p->prevProgress <= gPitExitProgressPoints[gTrackId] &&
                ((u32)p->progress & 0xFFFF) >= gPitExitProgressPoints[gTrackId])
                p->pitCollidable = 0;
        }
        p++;
    }
}
