#include "global.h"
#include "variables.h"


u32 sub_08008B6C(s32 arg0)
{
    if ((*(s32 *)&gChallengeTimerSec) * 1000 + (*(s32 *)&gChallengeTimerMs) <= arg0)
        return 1;
    return 0;
}
