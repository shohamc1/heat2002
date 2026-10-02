#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

void DrawChallengeCategoryComplete(u8 category)
{
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(169));
    DrawTextCenteredHighlight(GetString(197), 6, 1);
    DrawTextCenteredHighlight(GetString(category + 197), 7, 1);
    if (category != 4)
        DrawTextCenteredHighlight(GetString(category + 170), 10, 1);
    else
        DrawTextCenteredHighlight(GetString(179), 10, 1);
}

u8 ShowChallengeCategoryComplete(u8 category)
{
    u8 palette[0x200];
    s8 done;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 zero = 0;
    LoadMenuScreen(3, (u16 *)palette);
    DrawChallengeCategoryComplete(category);
    FadeToBrightenedPalette(palette, 0x0F);
    done = 64;
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
