#include "global.h"
#include "variables.h"


void sub_08341D64(u8 *a)
{
    s32 idx;
    s32 v1;
    s32 v2;
    s32 x;
    s32 y;

    idx = -(s32)(*(u16 *)(a + 0x34) >> 11) & 0x1F;
    idx = idx << 3;
    v1 = gModule_SinTable[idx];
    idx = idx + 0x40;
    v2 = gModule_SinTable[idx];
    x = *(s32 *)(a + 0x0C);
    y = *(s32 *)(a + 0x14);
    *(s32 *)(a + 0x2C) = (x * v1 + y * v2) >> 8;
}
