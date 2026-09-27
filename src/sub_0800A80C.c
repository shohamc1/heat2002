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
 * - The `gUnk_020020BC` loop is written with a goto so loop.c does not
 *   hoist the store address out of it.
 * - Everything from the sound check to the unk40 division is inside
 *   `if (v != 0)`.
 */

extern u16 gUnk_08368290[];

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
    if (car->unk55 != 0)
        car->unk55--;
    UpdateSteering(car, b);
    ComputeForwardSpeed(car);
    UpdateEngine(car, b);
    sub_08008480(car, c);
    v = 0;
    ComputeCarCorners(car);
    if (gUnk_0200215C[0] == 4 || gTrackId <= 0xB) {
        if (car->pitState != 0)
            v = 0;
        else
            v = CollideCarWithWalls(car);
    }
    if (v != 0 && (u8)(car->unk7C - 1) <= 2)
        v = -1;
    t = car->speed >> 6;
    car->drag = t * t;
    if (t > 0)
        car->drag = -car->drag;
    if (gIsLinkRace != 0 || gUnk_0200215C[0] == 4 || gUnk_0200215C[0] == 3) {
        car->drag = car->drag / 215;
    } else if (car == gCars || gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0xD
        || gUnk_0200215C[0] == 0xE || gUnk_0200215C[0] == 0xF || gUnk_0200215C[0] == 0x11
        || gUnk_0200215C[0] == 4) {
        if (car->unk170 != 0)
            car->drag = car->drag / 250;
        else if (car->unk171 != 0)
            car->drag = car->drag / 100;
        else
            car->drag = car->drag / 480;
    } else {
        car->drag = car->drag / gUnk_08368290[gTrackId];
    }
    if (gUnk_020020A8 != 0 && (u8)(gUnk_0200215C[0] - 3) > 1)
        car->drag = 0;
    if (car == gCars || gIsLinkRace != 0) {
        if (gUnk_0200215C[0] != 9 && gUnk_0200215C[0] != 0xD && gUnk_0200215C[0] != 0xE
            && gUnk_0200215C[0] != 0xF && gUnk_0200215C[0] != 0x11
            && (CheckDrafting(car) != 0 || car->draftTimer != 0)) {
            if (car->draftTimer != 0)
                car->draftTimer--;
            car->drag = (car->drag * 3) >> 2;
            sub_0800B618(c, 0);
            sub_0800B618(c, 1);
        }
    }
    if (gUnk_0200215C[0] != 2)
        CollideCars(car);
    car->unk18C = car->progress;
again:
    gUnk_020020BC = UpdateLapProgress(car, c);
    if (gUnk_020020BC != 0)
        goto again;
    car->posX += car->velX;
    car->posZ += car->velZ;
    car->heading = car->heading + car->yawRate;
    if (v != 0) {
        if (gIsDemo == 0 && gUnk_020021E0 == 0 && gOptions[3] != 0) {
            if (gIsLinkRace == 0 ? car == gCars
                                    : car == gCars + gLinkPlayerId[0])
                m4aSongNumStart(0x12);
        }
        if ((u8)(car->unk7C - 5) > 2 && gUnk_0202EEB0 != 0)
            car->damage -= v >> 12;
        car->unk55 = 6;
        ComputeForwardSpeed(car);
        car->unk48 = car->speed;
        if (car->speed > 0)
            car->unk48 = 0;
        car->rpm = (car->unk48 << 8) / -car->unkE8[car->gear];
    }
    car->velX += car->forceX;
    car->velZ += car->forceZ;
    car->yawRate = *(u16 *)&car->torque + car->yawRate;
    car->yawRate = ((s16)car->yawRate * 31) >> 5;
}
