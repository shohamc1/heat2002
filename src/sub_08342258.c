#include "global.h"
#include "variables.h"
#include "car.h"

/*
 * Per-frame car update: the high-region (0x0834 module) copy of
 * sub_0800A80C, instruction-identical, ported from that matched source.
 * Its `/` libcalls resolve to the module copy through the Makefile rename
 * for src/sub_083[3-9]*.c objects.
 *
 * Per-frame car update: zero the impulse accumulators, run the sub-steps,
 * apply track collision (sub_08343A6C) and car collision (sub_08343EA8),
 * then integrate position and heading.
 *
 * Shapes the retail bytes depend on:
 * - `unused[5]` is a 20-byte local the compiled code never touches; the
 *   ROM's frame is 20 bytes with no sp-relative access.
 * - `if (car->pitState != 0) v = 0; else v = sub_08343A6C(car);`: the
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

void sub_0834029C(struct Car *a);
void sub_08342154(struct Car *a, u16 keys);
void sub_08341D64(struct Car *a);
void sub_08341B14(struct Car *a, u32 b);
void sub_083405F0(struct Car *a, u8 b);
void sub_08341DA0(struct Car *a);
s32 sub_08343A6C(struct Car *a);
s32 sub_08343234(struct Car *a);
void sub_08342DE8(u8 a, u8 b);
u8 sub_08343EA8(struct Car *a);
u8 sub_0833F468(struct Car *p, u8 a1);
void sub_0833A8C8(u16 idx);

void sub_08342258(struct Car *car, u32 b, u8 c)
{
    s32 unused[5];
    s32 v;
    s32 t;

    car->forceX = 0;
    car->forceZ = 0;
    car->torque = 0;
    sub_0834029C(car);
    if (car->unk55 != 0)
        car->unk55--;
    sub_08342154(car, b);
    sub_08341D64(car);
    sub_08341B14(car, b);
    sub_083405F0(car, c);
    v = 0;
    sub_08341DA0(car);
    if (gUnk_0203916C[0] == 4 || gUnk_020390DC <= 0xB) {
        if (car->pitState != 0)
            v = 0;
        else
            v = sub_08343A6C(car);
    }
    if (v != 0 && (u8)(car->unk7C - 1) <= 2)
        v = -1;
    t = car->speed >> 6;
    car->drag = t * t;
    if (t > 0)
        car->drag = -car->drag;
    if (gUnk_020390EC != 0 || gUnk_0203916C[0] == 4 || gUnk_0203916C[0] == 3) {
        car->drag = car->drag / 215;
    } else if (car == gModule_Cars || gUnk_0203916C[0] == 9 || gUnk_0203916C[0] == 0xD
        || gUnk_0203916C[0] == 0xE || gUnk_0203916C[0] == 0xF || gUnk_0203916C[0] == 0x11
        || gUnk_0203916C[0] == 4) {
        if (car->unk170 != 0)
            car->drag = car->drag / 250;
        else if (car->unk171 != 0)
            car->drag = car->drag / 100;
        else
            car->drag = car->drag / 480;
    } else {
        car->drag = car->drag / gUnk_020277D4[gUnk_020390DC];
    }
    if (gUnk_020390B8 != 0 && (u8)(gUnk_0203916C[0] - 3) > 1)
        car->drag = 0;
    if (car == gModule_Cars || gUnk_020390EC != 0) {
        if (gUnk_0203916C[0] != 9 && gUnk_0203916C[0] != 0xD && gUnk_0203916C[0] != 0xE
            && gUnk_0203916C[0] != 0xF && gUnk_0203916C[0] != 0x11
            && (sub_08343234(car) != 0 || car->draftTimer != 0)) {
            if (car->draftTimer != 0)
                car->draftTimer--;
            car->drag = (car->drag * 3) >> 2;
            sub_08342DE8(c, 0);
            sub_08342DE8(c, 1);
        }
    }
    if (gUnk_0203916C[0] != 2)
        sub_08343EA8(car);
    car->unk18C = car->progress;
again:
    gUnk_020390CC = sub_0833F468(car, c);
    if (gUnk_020390CC != 0)
        goto again;
    car->posX += car->velX;
    car->posZ += car->velZ;
    car->heading = car->heading + car->yawRate;
    if (v != 0) {
        if (gUnk_020390F0[0] == 0 && gUnk_020391F0 == 0 && gUnk_0203E120[3] != 0) {
            if (gUnk_020390EC == 0 ? car == gModule_Cars
                                    : car == gModule_Cars + gUnk_0203E1B0)
                sub_0833A8C8(0x12);
        }
        if ((u8)(car->unk7C - 5) > 2 && gUnk_0203E0E0 != 0)
            car->damage -= v >> 12;
        car->unk55 = 6;
        sub_08341D64(car);
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
