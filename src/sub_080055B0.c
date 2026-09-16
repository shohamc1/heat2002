#include "global.h"

extern u32 gUnk_020253C0;
extern s32 gUnk_0202521C;
extern u8 gUnk_02025240;
extern u8 gUnk_02025238;
extern u8 gUnk_0200215C;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_020020CC;
extern u8 gUnk_08365330[];

void sub_080055B0(void)
{
    u32 v;
    u32 n;
    u8 *base;
    u8 *p;

    gUnk_020253C0 = 0;
    gUnk_0202521C = gUnk_02025240;
    gUnk_02025238 = 1;
    v = gUnk_0200215C;
    if (v == 0xA)
        gUnk_0202521C = 0x14;
    if (v == 0) {
        n = (u8)(3 - gUnk_0202EF00[0]);
        base = gUnk_08365330;
        p = base + gUnk_020020CC;
        n += 3;
        gUnk_0202521C = *p + n;
    }
}
