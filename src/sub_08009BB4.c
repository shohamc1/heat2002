#include "global.h"
#include "variables.h"


u32 WorldToScreen(s32 x, s32 y, s32 *out)
{
    s32 dx = x - gCamera[0];
    s32 dy = y - gCamera[1];
    s32 u = (dx - dy) * 2;
    s32 t = dx + dy;
    s32 v;

    u = u + 0x00F10000;
    v = t + 0x00A10000;
    u = u >> 17;
    v = v >> 17;
    if ((u32)(u + 0x18) > 0x120)
        return 0;
    if ((u32)(v + 0x20) > 0xD0)
        return 0;
    out[0] = u;
    out[1] = v;
}
