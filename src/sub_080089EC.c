#include "global.h"

s32 sub_080089EC(s32 a, s32 b)
{
    s32 sign = 0;
    s32 offs = 0;

    if (a < 0)
    {
        a = -a;
        sign = 1;
        offs = 0x80;
    }
    if (b < 0)
    {
        b = -b;
        sign ^= 1;
    }
    {
        s32 r = (b << 6) / (a + b);

        if (sign != 0)
            r = -r;
        return offs + r;
    }
}
