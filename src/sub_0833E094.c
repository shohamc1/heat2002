#include "global.h"
#include "variables.h"


void sub_0833E094(u8 value)
{
    s32 v = value;

    gModule_CountdownSeconds = v;
    if (v > 99)
        gModule_CountdownSeconds = 99;
}
