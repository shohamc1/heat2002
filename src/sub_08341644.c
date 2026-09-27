#include "global.h"
#include "variables.h"


u32 sub_08341644(s32 x, s32 y, s32 *out)
{
    s32 dx = x - ((s32 *)gModule_Camera)[0];
    s32 dy = y - ((s32 *)gModule_Camera)[1];
    s32 a = dx - dy;
    s32 b;
    u32 res;

    a *= 2;
    dx = dx + dy;
    a += 0xF10000;
    b = dx + 0xA10000;
    a >>= 17;
    b >>= 17;
    if ((u32)(a + 0x18) > 0x120)
        return 0;
    res = b + 0x20;
    if (res > 0xD0)
        return 0;
    out[0] = a;
    out[1] = b;
}
