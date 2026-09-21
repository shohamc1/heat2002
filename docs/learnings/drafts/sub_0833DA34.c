#include "global.h"

extern u8 gUnk_0203B850;
extern u8 gUnk_020390BC;
extern u16 gUnk_0203B6FC;
extern u16 gUnk_0203B848;
extern u16 gUnk_020390B0[];

u16 sub_0833DA34(void)
{
    u16 i;
    u16 v;
    u8 n;

    if (gUnk_0203B850 == 0xFF)
    {
        v = 0;
        i = 0;
        n = gUnk_020390BC;
        for (; i != n; i++)
        {
            if ((gUnk_020390B0[i] & 8) != 0)
            {
                gUnk_0203B850 = i;
                v = gUnk_020390B0[i];
            }
        }
        gUnk_0203B6FC = v & ~gUnk_0203B848;
        gUnk_0203B848 = v;
    }
    else
    {
        v = gUnk_020390B0[gUnk_0203B850];
        gUnk_0203B6FC = v & ~gUnk_0203B848;
        gUnk_0203B848 = v;
    }
    return gUnk_0203B6FC;
}
