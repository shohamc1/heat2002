#include "global.h"
#include "variables.h"

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
    v = gUnk_0200215C[0];
    if (v == 0xA)
        gUnk_0202521C = 0x14;
    if (v == 0) {
        n = (u8)(3 - gOptions[0]);
        base = gUnk_08365330;
        p = base + gTrackId;
        n += 3;
        gUnk_0202521C = *p + n;
    }
}
