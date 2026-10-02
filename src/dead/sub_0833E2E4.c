#include "global.h"
#include "variables.h"

u32 sub_0833E2E4(void)
{
    if (gModule_CountdownSeconds != 0)
        return 1;
    if (gModule_CountdownMs != 0)
        return 1;
    return 0;
}

void sub_083429B4(void);

void sub_0833E304(void)
{
    u32 v;

    if (gModule_RaceStarted == 0)
        return;
    v = gModule_RaceEndState;
    if (v != 0)
        return;
    (*(s32 *)&gModule_CountdownMs) -= 0x18;
    if ((*(s32 *)&gModule_CountdownMs) >= 0)
        return;
    (*(s32 *)&gModule_CountdownMs) += 0x3E8;
    (*(s32 *)&gModule_CountdownSeconds) -= 1;
    gUnk_0203B6E8 = 1;
    if ((*(s32 *)&gModule_CountdownSeconds) >= 0)
        return;
    (*(s32 *)&gModule_CountdownSeconds) = v;
    (*(s32 *)&gModule_CountdownMs) = v;
    if (gModule_GameMode != 0)
        return;
    sub_083429B4();
}
