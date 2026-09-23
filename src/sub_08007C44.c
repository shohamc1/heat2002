#include "global.h"

struct Car {
    s32 unk00;
    u8 pad04[0x08 - 0x04];
    s32 unk08;
    u8 pad0C[0x170 - 0x0C];
    u8 unk170;
    u8 unk171;
    u8 unk172;
    u8 unk173;
    u8 unk174;
    u8 unk175;
    u8 pad176[0x182 - 0x176];
    u16 unk182;
    u8 pad184[0x190 - 0x184];
};

extern u8 gUnk_0200215C;
extern u8 gUnk_020020CC;
extern u8 gUnk_020020DC;
extern u8 gUnk_0202EF90;
extern u8 gUnk_0202ED70;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_020020E0;
extern u8 gUnk_020021E0;
extern u8 gUnk_02001FA0[];
extern u8 gUnk_02002030[];
extern u8 gUnk_02001FE0[];
extern struct Car gUnk_0202A550[];

void sub_08001208(u16 idx);
u8 sub_080025FC(void);
void sub_0800930C(u8 *a, u8 b);
u8 sub_0800CBB8(s32 x, s32 y);
void sub_080019B4(s32 a);

void sub_08007C44(struct Car *car)
{
    u8 pad[0x28];
    s32 p;
    s32 cx, cy;
    s32 a, b;
    s32 x, y;
    u8 v;
    u8 cnt;
    u8 f2;

    car->unk170 = 0;
    car->unk173 = car->unk171;
    car->unk171 = 0;
    car->unk172 = 0;
    if (gUnk_0200215C == 4)
        return;
    if (gUnk_020020CC == 7)
        return;
    p = 0;
    if (gUnk_020020DC != 0)
        p = gUnk_0202EF90;
    a = car->unk00;
    b = car->unk08;
    cx = a >> 19;
    cy = b >> 19;
    cy += 2;
    cx += 1;
    car->unk170 = 0;
    car->unk171 = 0;
    car->unk172 = 0;
    cnt = 0;
    for (y = cy - 1; y != cy + 2; y++) {
        for (x = cx - 1; x != cx + 2; x++) {
            v = sub_0800CBB8(x, y);
            if (v & 1)
                car->unk172 = 1;
            if ((v == 2 || v == 3) && x == cx && y == cy)
                car->unk170 = 1;
            if ((v == 4 || v == 5) && x == cx && y == cy)
                car->unk171 = 1;
            if (v == 6)
                cnt++;
            if ((v == 8 || v == 9) && car->unk175 == 6)
                car->unk182 = 0;
        }
    }
    if (cnt > 4 || (cnt != 0 && (gUnk_020020CC == 3 || gUnk_020020CC == 5
            || gUnk_020020CC == 8 || gUnk_020020CC == 0xB || gUnk_020020CC == 2))) {
        if (gUnk_020020DC == 0 && car == gUnk_0202A550)
            sub_0800930C((u8 *)car, 0);
    }
    f2 = 0;
    if ((u8)(gUnk_0200215C - 0xF) <= 1 && gUnk_0202ED70 == 0xC)
        f2 = 1;
    if (car == &gUnk_0202A550[p]) {
        if (car->unk171 != 0 && car->unk173 == 0 && f2 == 0 && gUnk_0202EF00[3] != 0
            && gUnk_020020E0 == 0 && gUnk_020021E0 == 0)
            sub_08001208(0x1C);
    }
    if (car == &gUnk_0202A550[p]) {
        if (car->unk171 != 0 && (sub_080025FC() & 0x1F) == 0 && gUnk_0202EF00[3] != 0
            && gUnk_020020E0 == 0 && gUnk_020021E0 == 0 && f2 == 0)
            sub_08001208(0x1D);
    }
    if (car == &gUnk_0202A550[p]) {
        if ((*(u32 *)&car->unk170 & 0xFF00FF00) == 0x01000000) {
            sub_080019B4((s32)gUnk_02001FA0);
            sub_080019B4((s32)gUnk_02002030);
            sub_080019B4((s32)gUnk_02001FE0);
        }
    }
    if (gUnk_0200215C == 0x10 && gUnk_0202ED70 == 0xC)
        car->unk171 = 0;
}
