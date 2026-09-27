#include "global.h"
#include "variables.h"

extern u16 gUnk_020215EA[];

void sub_0833E3F8(u16 *dest, u8 idx)
{
    u16 v;

    v = *(idx + gUnk_020215EA);
    *dest = (gUnk_02022254[v] & 0xFFF) | 0xE000;
}
