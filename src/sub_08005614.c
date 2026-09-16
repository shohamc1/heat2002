#include "global.h"

extern u8 gUnk_0200215C;
extern u8 gUnk_020020CC;
extern u16 gUnk_020253A0[];
extern u16 gUnk_02025200[];
extern u16 gUnk_02025380[];

void sub_08005614(u32 a, u32 b, u32 c)
{
    if ((u8)(gUnk_0200215C - 3) <= 1)
        return;
    gUnk_020253A0[gUnk_020020CC] = c;
    gUnk_02025200[gUnk_020020CC] = b;
    gUnk_02025380[gUnk_020020CC] = a;
}
