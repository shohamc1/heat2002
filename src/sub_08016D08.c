#include "global.h"

extern u32 gUnk_083FED18[];

u32 sub_08016D08(s32 a, u8 b)
{
    u32 lo = a & 0xFFFF;
    return (a >> 16) * gUnk_083FED18[b] + lo;
}
