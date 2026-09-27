#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gText_HudBestLabel[];


void sub_08006388(void)
{
    InitRaceHud();
    if (gIsTimeTrial != 0)
    {
        sub_0800649C(gText_HudBestLabel, 0, 0x12);
    }
}
