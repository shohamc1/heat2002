#include "global.h"
#include "variables.h"


void sub_0833D5B8(void)
{
    s32 diffX = gUnk_02039110[2] - gUnk_02039110[0];
    s32 diffY = gUnk_02039110[3] - gUnk_02039110[1];

    if (gUnk_020390F0[0] != 0)
    {
        gUnk_02039110[0] = gUnk_02039110[0] + diffX;
        gUnk_02039110[1] = gUnk_02039110[1] + diffY;
    }
    else
    {
        gUnk_02039110[0] = gUnk_02039110[0] + (diffX >> 4);
        gUnk_02039110[1] = gUnk_02039110[1] + (diffY >> 4);
    }
}
