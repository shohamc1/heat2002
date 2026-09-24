#include "global.h"
void sub_08003E84(s32 *src, u32 pal, s32 *dst)
{
    u16 *pk = (u16 *)pal;
    s32 i = 0;
    s32 m = 0x1F;
    do {
        s32 v = *pk++;
        s32 q = v;
        s32 g;
        v &= m;
        g = q >> 5;
        g &= m;
        q = q >> 10;
        q &= m;
        v <<= 16;
        g <<= 16;
        q <<= 16;
        *dst++ = (v - *src++) / 16;
        *dst++ = (g - *src++) / 16;
        *dst++ = (q - *src++) / 16;
        i++;
    } while (i != 16);
}
