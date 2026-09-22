#include "global.h"

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
 * - `if (car->unk175 != 0) v = 0; else v = sub_08343A6C(car);`: the
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

struct Car {
    s32 unk00;                          /* 0x00 */
    u8 pad04[4];
    s32 unk08;                          /* 0x08 */
    s32 unk0C;                          /* 0x0C */
    u8 pad10[4];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x2C - 0x18];
    s32 unk2C;                          /* 0x2C */
    u8 pad30[4];
    u16 unk34;                          /* 0x34 */
    u8 pad36[0x3C - 0x36];
    u16 unk3C;                          /* 0x3C */
    u8 unk3E;                           /* 0x3E */
    u8 pad3F;
    s16 unk40;                          /* 0x40 */
    u8 pad42[0x48 - 0x42];
    s32 unk48;                          /* 0x48 */
    u8 pad4C[4];
    s32 unk50;                          /* 0x50 */
    u8 pad54;
    u8 unk55;                           /* 0x55 */
    u8 pad56[0x7C - 0x56];
    u8 unk7C;                           /* 0x7C */
    u8 pad7D[0x88 - 0x7D];
    s32 unk88;                          /* 0x88 */
    u8 pad8C[0xE8 - 0x8C];
    u16 *unkE8;                         /* 0xE8 */
    u8 padEC[0x140 - 0xEC];
    s32 unk140;                         /* 0x140 */
    s32 unk144;                         /* 0x144 */
    s32 unk148;                         /* 0x148 */
    s32 unk14C;                         /* 0x14C */
    u8 pad150[0x170 - 0x150];
    u8 unk170;                          /* 0x170 */
    u8 unk171;                          /* 0x171 */
    u8 pad172[3];
    u8 unk175;                          /* 0x175 */
    u8 unk176;                          /* 0x176 */
    u8 pad177[0x18C - 0x177];
    u16 unk18C;                         /* 0x18C */
    u8 pad18E[0x190 - 0x18E];
};

extern u8 gUnk_0203916C;
extern u8 gUnk_020390DC;
extern u8 gUnk_020390EC;
extern u8 gUnk_020390B8;
extern u8 gUnk_020390F0;
extern u8 gUnk_020391F0;
extern u8 gUnk_0203E120[];
extern u8 gUnk_0203E0E0;
extern u8 gUnk_0203E1B0;
extern u8 gUnk_020390CC;
extern struct Car gUnk_0203D520[];
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

    car->unk140 = 0;
    car->unk144 = 0;
    car->unk148 = 0;
    sub_0834029C(car);
    if (car->unk55 != 0)
        car->unk55--;
    sub_08342154(car, b);
    sub_08341D64(car);
    sub_08341B14(car, b);
    sub_083405F0(car, c);
    v = 0;
    sub_08341DA0(car);
    if (gUnk_0203916C == 4 || gUnk_020390DC <= 0xB) {
        if (car->unk175 != 0)
            v = 0;
        else
            v = sub_08343A6C(car);
    }
    if (v != 0 && (u8)(car->unk7C - 1) <= 2)
        v = -1;
    t = car->unk2C >> 6;
    car->unk14C = t * t;
    if (t > 0)
        car->unk14C = -car->unk14C;
    if (gUnk_020390EC != 0 || gUnk_0203916C == 4 || gUnk_0203916C == 3) {
        car->unk14C = car->unk14C / 215;
    } else if (car == gUnk_0203D520 || gUnk_0203916C == 9 || gUnk_0203916C == 0xD
        || gUnk_0203916C == 0xE || gUnk_0203916C == 0xF || gUnk_0203916C == 0x11
        || gUnk_0203916C == 4) {
        if (car->unk170 != 0)
            car->unk14C = car->unk14C / 250;
        else if (car->unk171 != 0)
            car->unk14C = car->unk14C / 100;
        else
            car->unk14C = car->unk14C / 480;
    } else {
        car->unk14C = car->unk14C / gUnk_020277D4[gUnk_020390DC];
    }
    if (gUnk_020390B8 != 0 && (u8)(gUnk_0203916C - 3) > 1)
        car->unk14C = 0;
    if (car == gUnk_0203D520 || gUnk_020390EC != 0) {
        if (gUnk_0203916C != 9 && gUnk_0203916C != 0xD && gUnk_0203916C != 0xE
            && gUnk_0203916C != 0xF && gUnk_0203916C != 0x11
            && (sub_08343234(car) != 0 || car->unk176 != 0)) {
            if (car->unk176 != 0)
                car->unk176--;
            car->unk14C = (car->unk14C * 3) >> 2;
            sub_08342DE8(c, 0);
            sub_08342DE8(c, 1);
        }
    }
    if (gUnk_0203916C != 2)
        sub_08343EA8(car);
    car->unk18C = car->unk50;
again:
    gUnk_020390CC = sub_0833F468(car, c);
    if (gUnk_020390CC != 0)
        goto again;
    car->unk00 += car->unk0C;
    car->unk08 += car->unk14;
    car->unk34 = car->unk34 + car->unk3C;
    if (v != 0) {
        if (gUnk_020390F0 == 0 && gUnk_020391F0 == 0 && gUnk_0203E120[3] != 0) {
            if (gUnk_020390EC == 0 ? car == gUnk_0203D520
                                    : car == gUnk_0203D520 + gUnk_0203E1B0)
                sub_0833A8C8(0x12);
        }
        if ((u8)(car->unk7C - 5) > 2 && gUnk_0203E0E0 != 0)
            car->unk88 -= v >> 12;
        car->unk55 = 6;
        sub_08341D64(car);
        car->unk48 = car->unk2C;
        if (car->unk2C > 0)
            car->unk48 = 0;
        car->unk40 = (car->unk48 << 8) / -car->unkE8[car->unk3E];
    }
    car->unk0C += car->unk140;
    car->unk14 += car->unk144;
    car->unk3C = *(u16 *)&car->unk148 + car->unk3C;
    car->unk3C = ((s16)car->unk3C * 31) >> 5;
}
