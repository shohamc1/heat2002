#include "global.h"
#include "functions.h"

struct Car {
    s32 posX;
    s32 unk04;
    s32 posZ;
    u8 pad0C[0x18 - 0x0C];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 speed;
    u8 pad30[0x34 - 0x30];
    s16 heading;
    u8 pad36[0xF4 - 0x36];
    s32 unkF4;
    s32 unkF8;
    u8 padFC[0x154 - 0xFC];
    s32 unk154;
};

extern u8 gNumCars;
extern u8 gUnk_0200215C;
extern u8 gUnk_0202ED70;
extern s32 gUnk_0202CC24;
extern s32 gUnk_0202CC34;
extern s32 gUnk_0202CC38;
extern s32 gUnk_0202CC3C;

s32 sub_0800BBFC(s32 a, s32 b, s32 c, s32 d, s32 e);
void sub_0800BD44(s32 a, s32 b, s32 c, struct Car *d);
void sub_0800C28C(struct Car *a);
s32 sub_0800C358(struct Car *a, s32 b);
s32 Atan2(s32 a, s32 b);

void sub_0800BEA4(struct Car **arr, s32 a1, s32 a2, s32 a3, u8 a4)
{
    struct Car **pp;
    struct Car *car;
    s32 out[2];
    s32 x;
    s32 i, k;
    s32 da;
    s32 db;

    car = *arr;
    for (i = 0; i != 0x18; i++) {
        if (a4 == 0) {
            if (i & 1)
                sub_0800BE00(car, 0x100);
            else
                sub_0800BE00(car, 0x500);
        } else {
            sub_0800BE00(car, 0x500);
        }
    }
    car = *arr;
    car->speed = 0;
    sub_0800C28C(car);
    car->unk18 = car->posX;
    car->unk1C = car->posZ;
    if (sub_0800C358(car, 0) == -1)
        return;
    x = sub_0800BBFC(gUnk_0202CC24, gUnk_0202CC38, car->unkF4, gUnk_0202CC3C,
                     gUnk_0202CC34);
    x -= 5000;
    if (x < 0)
        x += car->unk154;
    pp = arr;
    i = 0;
    if (i != gNumCars) {
        do {
            car = *pp;
            if (a4 != 0)
                sub_0800BE00(car, 0x500);
            else if (i & 1)
                sub_0800BE00(car, 0x100);
            else
                sub_0800BE00(car, 0x500);
            sub_0800BD44(x, car->unkF4, car->unkF8, car);
            sub_0800BD98(x,(struct OutBD98 *)out,(u16 *)(car->unkF4),(void *)(car->unkF8));
            car->posX = out[0] << 16;
            car->posZ = out[1] << 16;
            sub_0800BD98(sub_080172C8(x + 0x32, car->unk154), out, car->unkF4,
                         car->unkF8);
            da = (out[0] << 16) - car->posX;
            db = (out[1] << 16) - car->posZ;
            /* Stored straight to the s16 field, the minus is done in
               HImode, which gives the ROM's constant copy (adds r1, r2, #0). */
            car->heading = -0x7C00 - (Atan2(da >> 5, db >> 5) << 8);
            if (gUnk_0200215C == 0xF && i == 0 && gUnk_0202ED70 == 3)
                x -= 500;
            /* Two copies, merged by cross-jumping after allocation. The two
               uses let loop.c hoist a3 * 3 / 2 and give it r10 ahead of
               the hoisted &out. */
            if (a4 != 0) {
                x -= a3 * 3 / 2;
                if (x < 0)
                    x += car->unk154;
            } else if (i & 1) {
                x -= a3 * 3 / 2;
                if (x < 0)
                    x += car->unk154;
            }
            i++;
            pp++;
        } while (i != gNumCars);
    }
    for (k = 0; k != 0x32; k++) {
        pp = arr;
        for (i = 0; i != gNumCars; i++) {
            car = *pp++;
            UpdateAiDriver((struct Unk0800C534 *)car, (u8)i);
        }
    }
}
