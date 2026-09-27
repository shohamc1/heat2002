#include "global.h"
#include "variables.h"


void sub_0833D5F4(u32 *r0)
{
    if (gModule_IsDemo[0] != 0)
    {
        gModule_Camera[2] = r0[0];
        gModule_Camera[3] = r0[2];
    }
    else
    {
        gModule_Camera[2] = r0[0] + r0[3] * 20;
        gModule_Camera[3] = r0[2] + r0[5] * 20;
    }
}
