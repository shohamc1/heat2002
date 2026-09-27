#include "global.h"
#include "variables.h"


void sub_083431CC(s32 *o, s32 x, s32 y, s32 *out)
{
    s32 idx;
    s32 s1;
    s32 c1;
    s32 dx;
    s32 dy;

    idx = -(o[75] >> 11) & 0x1F;
    idx = idx << 3;
    s1 = gModule_SinTable[idx];
    idx = idx + 0x40;
    c1 = gModule_SinTable[idx];
    dx = (x - o[0]) >> 16;
    dy = (y - o[2]) >> 16;
    out[0] = (dx * c1 - s1 * dy) >> 8;
    out[1] = (s1 * dx + dy * c1) >> 8;
}
