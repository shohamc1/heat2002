#include "global.h"

void sub_08003DF4(u16 src[], s32 dst[])
{
    s32 a, b, c;
    int i;
    s32 *d;
    u16 *s;

    d = dst;
    s = src;
    i = 0;
    do {
        a = *s++;
        b = a;
        c = a;
        a &= 0x1F;
        b >>= 5;
        b &= 0x1F;
        c >>= 10;
        c &= 0x1F;
        *d++ = a << 16;
        *d++ = b << 16;
        *d++ = c << 16;
        i++;
    } while (i != 0x10);
}
