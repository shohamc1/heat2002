#include "global.h"

extern u32 gUnk_02002100[];

u32 sub_08009C00(s32 x, s32 y, s32 *out)
{
    s32 dx = x - gUnk_02002100[0];
    s32 dy = y - gUnk_02002100[1];
    s32 u = (dx - dy) * 2;
    s32 t = dx + dy;
    s32 v;

    u = u + 0x00F10000;
    v = t + 0x00A10000;
    u = u >> 17;
    v = v >> 17;
    if ((u32)(u + 0x10) > 0x110)
        return 0;
    if ((u32)(v + 0x20) > 0xC0)
        return 0;
    out[0] = u;
    out[1] = v;
}
