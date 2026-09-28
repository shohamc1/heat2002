#include "global.h"
#include "variables.h"

u32 sub_080057E8(void)
{
    if ((*(u32 *)&gCountdownSeconds) != 0)
        return 1;
    if (gCountdownMs != 0)
        return 1;
    return 0;
}

void sub_0800B09C(void);

void sub_08005808(void)
{
    u32 v;

    if (gRaceStarted == 0)
        return;
    v = gRaceEndState;
    if (v != 0)
        return;
    (*(s32 *)&gCountdownMs) -= 0x18;
    if ((*(s32 *)&gCountdownMs) >= 0)
        return;
    (*(s32 *)&gCountdownMs) += 0x3E8;
    gCountdownSeconds -= 1;
    gUnk_02025238 = 1;
    if (gCountdownSeconds >= 0)
        return;
    gCountdownSeconds = v;
    (*(s32 *)&gCountdownMs) = v;
    if (gGameMode[0] != 0)
        return;
    sub_0800B09C();
}
