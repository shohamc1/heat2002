#include "global.h"

extern u16 *gUnk_0203DE8C;
extern u16 *gUnk_0203DE88;

u16 *sub_083434BC(s32 a, s32 b)
{
    s32 x;
    s32 y;

    x = a >> 7;
    y = b >> 7;
    if (x > 0x30 || y > 0x30 || x < 0 || y < 0)
        return gUnk_0203DE8C + *gUnk_0203DE88;
    return gUnk_0203DE8C + gUnk_0203DE88[y * 0x30 + x];
}
