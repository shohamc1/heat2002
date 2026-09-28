#include "global.h"
#include "gba/io_reg.h"
#include "car.h"
#include "m4a.h"
#include "variables.h"
#include "functions.h"

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
void ComputeForwardSpeed(struct Car *a);
void UpdateEngine(struct Car *a, u32 b);
void sub_08008480(struct Car *a, u8 b);
void ComputeCarCorners(struct Car *a);
s32 CollideCarWithWalls(struct Car *a);
s32 CheckDrafting(struct Car *a);
void sub_0800B618(u8 a, u8 b);
u8 CollideCars(struct Car *a);
u8 UpdateLapProgress(struct Car *p, u8 a1);

void UpdatePitStop(struct Car *a, u8 b);
void UpdateRacePosition(u8 a);
void sub_0800A628(struct Car *a);
void sub_0800B8A8(struct Car *a);

extern u16 gPitEntryProgressPoints[];
extern u16 gPitExitProgressPoints[];

void UpdateCar(struct Car *p, u8 idx);
u8 CarNeedsPit(struct Car *p);
u8 FindFreePitStall(u8 a);
void EnterPit(struct Car *p, u8 a);

void UpdateSteering(s32 *a, u16 keys)
{
    s32 t;
    u32 v;
    s32 x;

    ((u8 *)a)[0x84] = 1;
    if (a == (s32 *)gCars && a[0xB] > 0) {
        if (!(keys & (DPAD_RIGHT | DPAD_LEFT)))
            a[75] = (a[75] + ((u16 *)a)[0x1A]) / 2;
        if (keys & DPAD_LEFT)
            a[75] = ((u16 *)a)[0x1A] - 0x1400;
        if (keys & DPAD_RIGHT) {
            a[75] = ((u16 *)a)[0x1A] + 0x1400;
        }
        return;
    }
    if (keys & (DPAD_RIGHT | DPAD_LEFT)) {
        u8 cur = ((u8 *)a)[0x110];
        if ((s8)((u8 *)a)[0x110] >= 0)
            ((u8 *)a)[0x110] = cur + 1;
    } else {
        if (((u8 *)a)[0x110] != 0)
            ((u8 *)a)[0x110] = ((u8 *)a)[0x110] - 1;
    }
    v = ((u8 *)a)[0x110];
    t = (v * 3 >> 2) + 0x100;
    x = -(a[0xB]) >> 12;
    if (x < 0)
        x = 0;
    x = 0xFF - x;
    t += x * 2;
    if (keys & DPAD_LEFT) {
        a[75] -= t;
        ((u8 *)a)[0x84] = 0;
    } else if (keys & DPAD_RIGHT) {
        a[75] += t;
        ((u8 *)a)[0x84] = 2;
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
    sub_08007C44(car);
    if (car->hitCooldown != 0)
        car->hitCooldown--;
    UpdateSteering((s32 *)car, b);
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
        sub_0800A628(car);
    } else if (idx == 0) {
        if (car->pitState != 0) {
            UpdatePitStop(car, 0);
            UpdateCarPhysics(car, car->aiInput, 0);
        } else if (gGameMode[0] == 9 || gGameMode[0] == 0xD || gGameMode[0] == 0xE
                || gGameMode[0] == 0xF || gGameMode[0] == 0x11) {
            UpdateAiDriver((struct Unk0800C534 *)car, idx);
            UpdateCarPhysics(car, car->aiInput, idx);
        } else {
            /* One shared sub_0800A628 call, as in the gIsLinkRace branch:
               a call that ends a block before a label gets a USE insn from
               flow, which keeps jump2 from cross-jumping the call itself. */
            if (gRaceEndState == 0)
                UpdateCarPhysics(car, gKeysHeld, 0);
            else
                UpdateCarPhysics(car, 2, 0);
            sub_0800A628(car);
        }
    } else {
        if (gGameMode[0] == 9 || gGameMode[0] == 0xD || gGameMode[0] == 0xE
                || gGameMode[0] == 0xF || gGameMode[0] == 0x11)
            goto common;
        if (gGameMode[0] != 4) {
            if (gRaceEndState == 0) {
                if (car->pitState != 0) {
                    UpdatePitStop(car, idx);
                } else {
common:
                    UpdateAiDriver((struct Unk0800C534 *)car, idx);
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
        sub_0800A628(car);
        UpdateCarPhysics(car, *p, idx);
    }

    if (car->damage > 0x11940 && car->carState != 1 && ((*(u32 *)&gFrameCounter) & 0x3F) == 0)
        sub_0800B8A8(car);

    if (gIsLinkRace != 0) {
        if (idx == gLinkPlayerId[0]) {
            UpdateRacePosition(idx);
            if (gCars[idx].racePosition != 0 && gCars[idx].racePosition != 0x63)
                gCars[idx].ledLapFlag = 0;
        }
    } else if (idx == 0) {
        UpdateRacePosition(0);
        if (gCars[0].racePosition != 0 && gCars[0].racePosition != 0x63)
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
    if (gIsLinkRace != 0 || gGameMode[0] == 4)
        count = gNumLinkPlayers[0];
    if (gGameMode[0] == 2)
        count = 1;
    gFuelOutStutterCounter++;
    for (i = 0; i != count; i++) {
        UpdateCar(p, i);
        if (p->prevProgress <= gPitEntryProgressPoints[gTrackId]
            && ((*(u32 *)&p->progress) & 0xFFFF) >= gPitEntryProgressPoints[gTrackId] && CarNeedsPit(p) != 0
            && p != gCars) {
            v = gDamagePitsEnabled;
            if (v != 0) {
                v = FindFreePitStall(v);
                if (v != 0x63)
                    EnterPit(p, FindFreePitStall(v));
            }
        }
        if (p != gCars && p->pitState != 0) {
            if (p->prevProgress <= gPitExitProgressPoints[gTrackId]
                && ((*(u32 *)&p->progress) & 0xFFFF) >= gPitExitProgressPoints[gTrackId])
                p->pitCollidable = 0;
        }
        p++;
    }
}
