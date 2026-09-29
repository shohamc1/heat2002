#include "global.h"
#include "variables.h"

u32 ModuleWorldToScreen(s32 x, s32 y, s32 *out)
{
    s32 dx = x - ((s32 *)gModule_Camera)[0];
    s32 dy = y - ((s32 *)gModule_Camera)[1];
    s32 u = dx - dy;
    s32 v;
    u32 res;

    u *= 2;
    dx = dx + dy;
    u += 0xF10000;
    v = dx + 0xA10000;
    u >>= 17;
    v >>= 17;
    if ((u32)(u + 0x18) > 0x120)
        return 0;
    res = v + 0x20;
    if (res > 0xD0)
        return 0;
    out[0] = u;
    out[1] = v;
}
