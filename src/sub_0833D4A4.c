#include "global.h"

extern s32 gUnk_020392D0[];
extern u16 gUnk_0203AAD0[];

void sub_0833D4A4(void)
{
    u32 i;
    u16 *dst;
    s32 *src;
    s32 r;
    s32 g;
    s32 b;

    src = gUnk_020392D0;
    dst = gUnk_0203AAD0;
    for (i = 0; i != 0x100; i++)
    {
        r = *src++;
        g = *src++;
        b = *src++;
        r >>= 16;
        g >>= 16;
        b >>= 16;
        r &= 0x1F;
        g &= 0x1F;
        b &= 0x1F;
        *dst++ = r | (g << 5) | (b << 10);
    }
}
