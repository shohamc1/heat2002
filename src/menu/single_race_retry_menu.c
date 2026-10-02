#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

void DrawSingleRaceRetryMenu(u8 cursor)
{
    u8 cursorCopy;

    cursorCopy = cursor;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(9));
    DrawTextCenteredHighlight(GetString(5), 7, cursor == 0);
    DrawTextCenteredHighlight(GetString(6), 9, cursor == 1);
    DrawTextCenteredHighlight(GetString(157), 11, cursor == 2);
    DrawTextCenteredHighlight(GetString(8), 13, cursorCopy == 3);
}

u8 SingleRaceRetryMenu(void)
{
    u8 fadePalette[0x200];
    s8 cursor;
    s8 selection;
    cursor = 0;
    LoadMenuScreen(1, (u16 *)fadePalette);
    DrawSingleRaceRetryMenu(0);
    FadeToBrightenedPalette(fadePalette, 0x0F);
    selection = 64;
    do {
        ReadKeys();
        DrawSingleRaceRetryMenu(cursor);
        if (gKeysPressed & 1)
            selection = cursor;
        cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 3);
        WaitForVBlank();
    } while (selection == 0x40);
    FadeToColor(0, 0x0F);
    return selection;
}
