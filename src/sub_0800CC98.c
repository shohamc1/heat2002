#include "global.h"

extern u16 *gUnk_0202CC68;
extern u16 *gUnk_0202CC6C;

u16 *sub_0800CC98(s32 x, s32 y)
{
    s32 tx = x >> 7;
    s32 ty = y >> 7;

    if (tx > 0x30 || ty > 0x30 || tx < 0 || ty < 0)
        return &gUnk_0202CC6C[gUnk_0202CC68[0]];
    return &gUnk_0202CC6C[gUnk_0202CC68[ty * 48 + tx]];
}
