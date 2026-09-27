#include "global.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

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

void sub_08007C44(struct Car *a);
void UpdateSteering(struct Car *a, u16 keys);
void ComputeForwardSpeed(struct Car *a);
void UpdateEngine(struct Car *a, u32 b);
void sub_08008480(struct Car *a, u8 b);
void ComputeCarCorners(struct Car *a);
s32 CollideCarWithWalls(struct Car *a);
s32 CheckDrafting(struct Car *a);
void sub_0800B618(u8 a, u8 b);
u8 CollideCars(struct Car *a);
u8 UpdateLapProgress(struct Car *p, u8 a1);

void UpdateCarPhysics(struct Car *car, u32 b, u8 c)
{
    s32 unused[5];
    s32 v;
    s32 t;

    car->forceX = 0;
    car->forceZ = 0;
    car->torque = 0;
    sub_08007C44(car);
    if (car->hitCooldown != 0)
        car->hitCooldown--;
    UpdateSteering(car, b);
    ComputeForwardSpeed(car);
    UpdateEngine(car, b);
    sub_08008480(car, c);
    v = 0;
    ComputeCarCorners(car);
    if (gGameMode[0] == 4 || gTrackId <= 0xB) {
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
    if (gIsLinkRace != 0 || gGameMode[0] == 4 || gGameMode[0] == 3) {
        car->drag = car->drag / 215;
    } else if (car == gCars || gGameMode[0] == 9 || gGameMode[0] == 0xD
        || gGameMode[0] == 0xE || gGameMode[0] == 0xF || gGameMode[0] == 0x11
        || gGameMode[0] == 4) {
        if (car->onApron != 0)
            car->drag = car->drag / 250;
        else if (car->onGrass != 0)
            car->drag = car->drag / 100;
        else
            car->drag = car->drag / 480;
    } else {
        car->drag = car->drag / gTrackAiDragDivisors[gTrackId];
    }
    if (gPreRaceSimActive != 0 && (u8)(gGameMode[0] - 3) > 1)
        car->drag = 0;
    if (car == gCars || gIsLinkRace != 0) {
        if (gGameMode[0] != 9 && gGameMode[0] != 0xD && gGameMode[0] != 0xE
            && gGameMode[0] != 0xF && gGameMode[0] != 0x11
            && (CheckDrafting(car) != 0 || car->draftTimer != 0)) {
            if (car->draftTimer != 0)
                car->draftTimer--;
            car->drag = (car->drag * 3) >> 2;
            sub_0800B618(c, 0);
            sub_0800B618(c, 1);
        }
    }
    if (gGameMode[0] != 2)
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
            if (gIsLinkRace == 0 ? car == gCars
                                    : car == gCars + gLinkPlayerId[0])
                m4aSongNumStart(0x12);
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
    car->yawRate = *(u16 *)&car->torque + car->yawRate;
    car->yawRate = ((s16)car->yawRate * 31) >> 5;
}
