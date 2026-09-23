/* 2026-09-23: 692/692 bytes, 53 normalized differing instructions (of ~330).
   Root causes fixed this session: bit must be its own variable assigned between
   the loops (per outer iteration) -- its spill slot is the frame's 6th, so pad
   is 0x28 not 0x2C; the unk00/unk08 loads must be pulled ahead via two field
   temps (yend/y) assigned before the shifts; bit u8; yend/cnt/p2 statement
   order yend,cnt,p2; cnt declared last. Remaining: &170/&172 homes (target r8/r5,
   ours r9/r8 -- target skips a free low, the sub_08009C4C r2/r3 phenomenon),
   the p-zero scratch (r0 vs r7), and the xc/yc chain order (target does both
   shifts before both adds; no statement form found that defers xc's add+store
   past yc's shift -- split adds double the spilled- xc store). */
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
    s32 yend;
    s32 p2;
    s32 yc;
    u8 bit;
    s32 xc;
    s32 x, y;
    u8 v;
    u8 f2;
    u8 cnt;

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
    yend = car->unk00;
    y = car->unk08;
    xc = (yend >> 19) + 1;
    yc = (y >> 19) + 2;
    car->unk170 = 0;
    car->unk171 = 0;
    car->unk172 = 0;
    yend = yc + 2;
    cnt = 0;
    p2 = p * 2;
    for (y = yc - 1; y != yend; y++) {
        bit = 1;
        for (x = xc - 1; x != xc + 2; x++) {
            v = sub_0800CBB8(x, y);
            if (v & bit)
                car->unk172 = bit;
            if ((u8)(v - 2) <= 1 && x == xc && y == yc)
                car->unk170 = bit;
            if ((u8)(v - 4) <= 1 && x == xc && y == yc)
                car->unk171 = bit;
            if (v == 6)
                cnt++;
            if ((u8)(v - 8) <= 1 && car->unk175 == 6)
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
