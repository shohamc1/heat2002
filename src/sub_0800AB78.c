#include "global.h"

struct Car {
    u8 pad00[0x7C];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x88 - 0x7E];
    s32 unk88;
    u8 pad8C[0xA0 - 0x8C];
    u16 unkA0;
    u8 padA2[0x150 - 0xA2];
    u8 unk150;
    u8 pad151[0x15C - 0x151];
    s32 unk15C;
    u8 pad160[0x166 - 0x160];
    u8 unk166;
    u8 pad167[0x175 - 0x167];
    u8 unk175;
    u8 pad176[0x190 - 0x176];
};

extern u8 gUnk_020020DC;
extern u8 gUnk_020021E0;
extern u16 gUnk_020020A0[];
extern u8 gUnk_0200215C;
extern u16 gKeysHeld;
extern u32 gUnk_0200209C;
extern u8 gUnk_0202EF90;
extern struct Car gUnk_0202A550[];

void sub_080093BC(struct Car *a, u8 b);
void sub_08009B20(u8 a);
void sub_0800A628(struct Car *a);
void sub_0800B8A8(struct Car *a);
void sub_0800C534(struct Car *a, u8 b);
void sub_0800A80C(struct Car *a, u16 b, u8 c);

void sub_0800AB78(struct Car *car, u8 idx)
{
    u16 *p;
    u32 v;

    v = gUnk_020020DC;
    if (v != 0) {
        if (gUnk_020021E0 == 0 && car->unk7D == 0)
            sub_0800A80C(car, gUnk_020020A0[idx], idx);
        else
            sub_0800A80C(car, 2, idx);
        sub_0800A628(car);
    } else if (idx == 0) {
        if (car->unk175 != 0) {
            sub_080093BC(car, 0);
            sub_0800A80C(car, car->unkA0, 0);
        } else if (gUnk_0200215C == 9 || gUnk_0200215C == 0xD || gUnk_0200215C == 0xE
                || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11) {
            sub_0800C534(car, idx);
            sub_0800A80C(car, car->unkA0, idx);
        } else {
            /* One shared sub_0800A628 call, as in the gUnk_020020DC branch:
               a call that ends a block before a label gets a USE insn from
               flow, which keeps jump2 from cross-jumping the call itself. */
            if (gUnk_020021E0 == 0)
                sub_0800A80C(car, gKeysHeld, 0);
            else
                sub_0800A80C(car, 2, 0);
            sub_0800A628(car);
        }
    } else {
        if (gUnk_0200215C == 9 || gUnk_0200215C == 0xD || gUnk_0200215C == 0xE
                || gUnk_0200215C == 0xF || gUnk_0200215C == 0x11)
            goto common;
        if (gUnk_0200215C != 4) {
            if (gUnk_020021E0 == 0) {
                if (car->unk175 != 0) {
                    sub_080093BC(car, idx);
                } else {
common:
                    sub_0800C534(car, idx);
                }
                p = &car->unkA0;
            } else {
                car->unkA0 = 2;
                p = &car->unkA0;
            }
        } else {
            car->unkA0 = v;
            p = &car->unkA0;
        }
        sub_0800A628(car);
        sub_0800A80C(car, *p, idx);
    }

    if (car->unk88 > 0x11940 && car->unk7C != 1 && (gUnk_0200209C & 0x3F) == 0)
        sub_0800B8A8(car);

    if (gUnk_020020DC != 0) {
        if (idx == gUnk_0202EF90) {
            sub_08009B20(idx);
            if (gUnk_0202A550[idx].unk150 != 0 && gUnk_0202A550[idx].unk150 != 0x63)
                gUnk_0202A550[idx].unk166 = 0;
        }
    } else if (idx == 0) {
        sub_08009B20(0);
        if (gUnk_0202A550[0].unk150 != 0 && gUnk_0202A550[0].unk150 != 0x63)
            gUnk_0202A550[0].unk166 = idx;
    }
    car->unk15C++;
}
