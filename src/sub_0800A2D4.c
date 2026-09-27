#include "global.h"
#include "data.h"


void ComputeForwardSpeed(s32 *a)
{
    u32 ang;
    u16 i;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    ang = ((u16 *)a)[0x1A];
    i = (-(ang >> 11) & 0x1F) << 3;
    dx = gSinTable[i];
    dy = gSinTable[i + 0x40];
    x = a[3];
    y = a[5];
    a[0xB] = (x * dx + y * dy) >> 8;
}
