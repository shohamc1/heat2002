#include "global.h"

extern u32 gUnk_0203B6CC;   /* 0x0203B6CC */

void sub_0833E094(u8 value)
{
    s32 v = value;

    gUnk_0203B6CC = v;
    if (v > 99)
        gUnk_0203B6CC = 99;
}
