#include "global.h"

extern u32 gUnk_020250F0[];
extern u8 gUnk_0203E004;

u32 sub_0833BD94(u16 a)
{
    return gUnk_020250F0[gUnk_0203E004 + a * 5];
}
