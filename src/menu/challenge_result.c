#include "global.h"
#include "functions.h"
#include "data.h"

// The retail body ignores both arguments; callers still pass them.
#include "variables.h"

void DrawChallengePassed(u8 unused1, u8 unused2)
{
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0xA9);
    ((void (*)(void))DrawBigText)();
    text = GetString(0xAA);
    DrawTextCenteredHighlight(text, 6, 1);
}

void DrawChallengeFailed(void)
{
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0xBD);
    ((void (*)(void))DrawBigText)();
    text = GetString(0xBE);
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
    FadeToBrightenedPalette((u32)palette, 0x0F);
    done = 0x40;
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
