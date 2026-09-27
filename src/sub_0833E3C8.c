#include "global.h"
#include "variables.h"

extern u16 gUnk_020215D2[];

void sub_0833E3C8(u16 *a, s32 b)
{
    u32 i;
    u16 tile;

    i = (u8)b * 2 + (u32)gUnk_020215D2;
    tile = (gUnk_02022254[*(u16 *)i] & 0xFFF) | 0xE000;
    *a = tile;
}
