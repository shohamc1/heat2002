#include "global.h"

struct Unk0202A550
{
    s32 unk0;
    s32 filler4;
    s32 unk8;
    u8 fillerC[0x170 - 0xC];
    u8 unk170;
    u8 unk171;
    u8 unk172;
    u8 unk173;
    u8 filler174;
    u8 unk175;
    u8 filler176[0x182 - 0x176];
    u16 unk182;
    u8 filler184[400 - 0x184];
};

extern struct Unk0202A550 gUnk_0202A550[];
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

extern void sub_0800930C(struct Unk0202A550 *p, u8 a);
extern u8 sub_0800CBB8(s32 x, s32 y);
extern void sub_08001208(u16 a);
extern u8 sub_080025FC(void);
extern void sub_080019B4(void *a);

void sub_08007C44(struct Unk0202A550 *work)
{
    u8 unused[40];
    u32 idx;
    s32 px;
    s32 py;
    s32 xs;
    s32 ys;
    s32 xBase;
    s32 yBase;
    s32 x;
    s32 y;
    u8 mask;
    u8 count;
    u8 flag;
    u8 result;

    work->unk170 = 0;
    work->unk173 = work->unk171;
    work->unk171 = 0;
    work->unk172 = 0;
    if (gUnk_0200215C == 4)
        return;
    if (gUnk_020020CC == 7)
        return;
    idx = 0;
    if (gUnk_020020DC != 0)
        idx = gUnk_0202EF90;
    px = work->unk0;
    py = work->unk8;
    xs = px >> 19;
    ys = py >> 19;
    yBase = ys + 2;
    xBase = xs + 1;
    work->unk170 = 0;
    work->unk171 = 0;
    work->unk172 = 0;
    count = 0;
    for (y = yBase - 1; y != yBase + 2; y++)
    {
        x = xBase - 1;
        if (x != xBase + 2)
        {
            mask = 1;
            do
            {
            result = sub_0800CBB8(x, y);
            if (result & mask)
                work->unk172 = mask;
            if ((u8)(result - 2) <= 1 && x == xBase && y == yBase)
                work->unk170 = mask;
            if ((u8)(result - 4) <= 1 && x == xBase && y == yBase)
                work->unk171 = mask;
            if (result == 6)
                count++;
            if ((u8)(result - 8) <= 1 && work->unk175 == 6)
                work->unk182 = 0;
            x++;
            } while (x != xBase + 2);
        }
    }
    if (count > 4 || (count != 0 && (gUnk_020020CC == 3 || gUnk_020020CC == 5
        || gUnk_020020CC == 8 || gUnk_020020CC == 0xB || gUnk_020020CC == 2)))
    {
        if (gUnk_020020DC == 0 && work == &gUnk_0202A550[0])
            sub_0800930C(work, 0);
    }
    flag = 0;
    if ((u8)(gUnk_0200215C - 0xF) <= 1 && gUnk_0202ED70 == 0xC)
        flag = 1;
    if (work == &gUnk_0202A550[idx] && work->unk171 != 0 && work->unk173 == 0
        && flag == 0 && gUnk_0202EF00[3] != 0 && gUnk_020020E0 == 0
        && gUnk_020021E0 == 0)
        sub_08001208(0x1C);
    if (work == &gUnk_0202A550[idx] && work->unk171 != 0
        && (sub_080025FC() & 0x1F) == 0 && gUnk_0202EF00[3] != 0
        && gUnk_020020E0 == 0 && gUnk_020021E0 == 0 && flag == 0)
        sub_08001208(0x1D);
    if (work == &gUnk_0202A550[idx] && (*(u32 *)&work->unk170 & 0xFF00FF00) == 0x10000000)
    {
        sub_080019B4(gUnk_02001FA0);
        sub_080019B4(gUnk_02002030);
        sub_080019B4(gUnk_02001FE0);
    }
    if (gUnk_0200215C == 0x10 && gUnk_0202ED70 == 0xC)
        work->unk171 = 0;
}
