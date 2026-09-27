#include "global.h"
#include "variables.h"


void sub_0833D5B8(void)
{
    s32 diffX = gModule_Camera[2] - gModule_Camera[0];
    s32 diffY = gModule_Camera[3] - gModule_Camera[1];

    if (gModule_IsDemo[0] != 0)
    {
        gModule_Camera[0] = gModule_Camera[0] + diffX;
        gModule_Camera[1] = gModule_Camera[1] + diffY;
    }
    else
    {
        gModule_Camera[0] = gModule_Camera[0] + (diffX >> 4);
        gModule_Camera[1] = gModule_Camera[1] + (diffY >> 4);
    }
}
