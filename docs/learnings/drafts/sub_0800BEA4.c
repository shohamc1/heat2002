#include "global.h"

struct Car {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u8 pad0C[0x18 - 0x0C];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x34 - 0x30];
    s16 unk34;
    u8 pad36[0xF4 - 0x36];
    s32 unkF4;
    s32 unkF8;
    u8 padFC[0x154 - 0xFC];
    s32 unk154;
};

extern u8 gUnk_02002090;
extern u8 gUnk_0200215C;
extern u8 gUnk_0202ED70;
extern s32 gUnk_0202CC24;
extern s32 gUnk_0202CC34;
extern s32 gUnk_0202CC38;
extern s32 gUnk_0202CC3C;

s32 sub_0800BBFC(s32 a, s32 b, s32 c, s32 d, s32 e);
void sub_0800BD44(s32 a, s32 b, s32 c, struct Car *d);
void sub_0800BD98(s32 a, s32 *b, s32 c, s32 d);
void sub_0800BE00(struct Car *a, s32 b);
void sub_0800C28C(struct Car *a);
s32 sub_0800C358(struct Car *a, s32 b);
void sub_0800C534(struct Car *a, u8 b);
s32 sub_0800CB18(s32 a, s32 b);
s32 sub_080172C8(s32 a, s32 b);

void sub_0800BEA4(struct Car **arr, s32 a1, s32 a2, s32 a3, u8 a4)
{
    register s32 step __asm__("r10");
    s32 t2;
    struct Car **pp;
    struct Car *car;
    s32 *op;
    s32 out[2];
    s32 x;
    s32 i, k;
    s32 da;
    s32 db;
    s32 t3;

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
    car->unk2C = 0;
    sub_0800C28C(car);
    car->unk18 = car->unk00;
    car->unk1C = car->unk08;
    if (sub_0800C358(car, 0) == -1)
        return;
    x = sub_0800BBFC(gUnk_0202CC24, gUnk_0202CC38, car->unkF4, gUnk_0202CC3C,
                     gUnk_0202CC34);
    x -= 5000;
    if (x < 0)
        x += car->unk154;
    pp = arr;
    i = 0;
    if (i != gUnk_02002090) {
        op = out;
        t2 = a3 * 3;
        step = t2 / 2;
        do {
            car = *pp;
            if (a4 != 0)
                sub_0800BE00(car, 0x500);
            else if (i & 1)
                sub_0800BE00(car, 0x100);
            else
                sub_0800BE00(car, 0x500);
            sub_0800BD44(x, car->unkF4, car->unkF8, car);
            sub_0800BD98(x, out, car->unkF4, car->unkF8);
            car->unk00 = out[0] << 16;
            car->unk08 = op[1] << 16;
            sub_0800BD98(sub_080172C8(x + 0x32, car->unk154), out, car->unkF4,
                         car->unkF8);
            da = (out[0] << 16) - car->unk00;
            db = (op[1] << 16) - car->unk08;
            t3 = sub_0800CB18(da >> 5, db >> 5);
            db = 0xFFFF8400 - (t3 << 8);
            car->unk34 = db;
            if (gUnk_0200215C == 0xF && i == 0 && gUnk_0202ED70 == 3)
                x -= 500;
            if (a4 != 0 || (i & 1)) {
                x -= step;
                if (x < 0)
                    x += car->unk154;
            }
            i++;
            pp++;
        } while (i != gUnk_02002090);
    }
    for (k = 0; k != 0x32; k++) {
        pp = arr;
        for (i = 0; i != gUnk_02002090; i++, pp++)
            sub_0800C534(*pp, (u8)i);
    }
}
