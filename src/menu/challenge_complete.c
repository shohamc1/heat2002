#include "global.h"
#include "functions.h"
#include "data.h"

#include "variables.h"


void DrawChallengeCategoryComplete(u8 category)
{
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0xA9);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0xC5), 6, 1);
    DrawTextCenteredHighlight(GetString(category + 0xC5), 7, 1);
    if (category != 4)
        DrawTextCenteredHighlight(GetString(category + 0xAA), 0xA, 1);
    else
        DrawTextCenteredHighlight(GetString(0xB3), 0xA, 1);
}


u8 ShowChallengeCategoryComplete(u8 category)
{
    u8 palette[0x200];
    s8 done;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 zero = 0;
    LoadMenuScreen(3, (u16 *)palette);
    DrawChallengeCategoryComplete(category);
    FadeToBrightenedPalette((u32)palette, 0x0F);
    done = 0x40;
    do {
        ReadKeys();
        DrawChallengeCategoryComplete(category);
        if (gKeysPressed & 1)
            done = zero;
        WaitForVBlank();
    } while (done != 0);
    FadeToColor(0, 0x0F);
    return done;
}

