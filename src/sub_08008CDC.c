#include "global.h"

extern u32 gUnk_0202A534;
extern u32 gUnk_0202CADC;
extern u32 gUnk_0202CAE4;

void sub_08008CDC(void)
{
    u32 v;
    s32 s;

    v = gUnk_0202A534;
    gUnk_0202A534 = v + 0x28;
    s = v + 0x28;
    if (s > 0x3E7)
    {
        gUnk_0202A534 = v - 0x3C0;
        gUnk_0202CADC = gUnk_0202CADC + 1;
        s = gUnk_0202CADC;
        if (s > 0x3B)
        {
            gUnk_0202CADC = gUnk_0202CADC - 0x3C;
            gUnk_0202CAE4 = gUnk_0202CAE4 + 1;
        }
    }
}
