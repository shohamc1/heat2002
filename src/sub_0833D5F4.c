#include "global.h"

extern u8 gUnk_020390F0[];
extern u32 gUnk_02039110[];

void sub_0833D5F4(u32 *r0)
{
    if (gUnk_020390F0[0] != 0)
    {
        gUnk_02039110[2] = r0[0];
        gUnk_02039110[3] = r0[2];
    }
    else
    {
        gUnk_02039110[2] = r0[0] + r0[3] * 20;
        gUnk_02039110[3] = r0[2] + r0[5] * 20;
    }
}
