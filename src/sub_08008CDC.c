#include "global.h"
#include "variables.h"


void sub_08008CDC(void)
{
    u32 v;
    s32 s;

    v = gChallengeTimerMs;
    gChallengeTimerMs = v + 0x28;
    s = v + 0x28;
    if (s > 0x3E7)
    {
        gChallengeTimerMs = v - 0x3C0;
        gChallengeTimerSec = gChallengeTimerSec + 1;
        s = gChallengeTimerSec;
        if (s > 0x3B)
        {
            gChallengeTimerSec = gChallengeTimerSec - 0x3C;
            gUnk_0202CAE4 = gUnk_0202CAE4 + 1;
        }
    }
}
