#include "global.h"

void sub_0833D12C(s32 src[], u16 dst[])
{
    s32 a, b, c;
    int i;

    i = 0;
    do {
        a = *src++;
        b = *src++;
        c = *src++;
        a >>= 16;
        b >>= 16;
        c >>= 16;
        a &= 0x1F;
        b &= 0x1F;
        c &= 0x1F;
        *dst++ = a | (b << 5) | (c << 10);
        i++;
    } while (i != 0x10);
}
