#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

// The retail body ignores both arguments; callers still pass them.
void DrawChallengePassed(u8 unused1, u8 unused2)
{
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(169));
    text = GetString(170);
    DrawTextCenteredHighlight(text, 6, 1);
}

void DrawChallengeFailed(u8 unused)
{
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(189));
    text = GetString(190);
    DrawTextCenteredHighlight(text, 6, 1);
}

u8 ShowChallengePassed(u8 challengeIdx, u8 alreadyBeaten)
{
    u8 palette[0x200];
    s8 done;
    /* The signed local keeps the parameter conversions in ROM order. */
    s8 resultIdx = challengeIdx;
    LoadMenuScreen(3, (u16 *)palette);
    DrawChallengePassed(resultIdx, alreadyBeaten);
    FadeToBrightenedPalette(palette, 0x0F);
    done = 64;
    do {
        ReadKeys();
        DrawChallengePassed(resultIdx, alreadyBeaten);
        if (gKeysPressed & 1)
            done = resultIdx;
        WaitForVBlank();
    } while (done == 0x40);
    FadeToColor(0, 0x0F);
    return done;
}

u8 ChallengeFailedScreen(s8 challengeIdx)
{
    u8 buf[0x200];
    s8 sel;
    LoadMenuScreen(3, (u16 *)buf);
    DrawChallengeFailed(challengeIdx);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
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
