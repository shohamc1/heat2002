#include "global.h"

extern u32 gUnk_08364B08;
extern u8 gUnk_0806C8E4[];
extern s32 gUnk_0202CAE4;
extern s32 gUnk_0202CADC;
extern s32 gUnk_0202A534;

void sub_0800649C(u8 *src, u32 x, u32 y);
void sub_08005870(u32 *dest, u32 idx);

void sub_08008B94(void)
{
    u32 base;
    u32 *p;

    base = gUnk_08364B08;
    p = base + 0x250;
    sub_0800649C(gUnk_0806C8E4, 8, 8);
    sub_08005870(p, 0);
    p = base + 0x254;
    sub_08005870(p, gUnk_0202CAE4);
    p = base + 0x25A;
    sub_08005870(p, gUnk_0202CADC / 10);
    p = base + 0x25E;
    sub_08005870(p, gUnk_0202CADC % 10);
    p = base + 0x264;
    sub_08005870(p, gUnk_0202A534 / 100 % 10);
    p = base + 0x268;
    sub_08005870(p, gUnk_0202A534 / 10 % 10);
}
