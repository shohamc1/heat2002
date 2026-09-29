#include "global.h"
#include "functions.h"
#include "variables.h"

u8 ChallengeFailedScreen(s8 challengeIdx)
{
    u8 buf[0x200];
    s8 sel;
    LoadMenuScreen(3, (u16 *)buf);
    DrawChallengeFailed(challengeIdx);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawChallengeFailed(challengeIdx);
        if (gKeysPressed & 1)
            sel = challengeIdx;
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
