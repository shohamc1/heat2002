#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

void DrawNewGameLoadMenu(u8 cursor)
{
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(78));
    text = GetString(95);
    DrawTextCenteredHighlight(text, 8, cursor == 0);
    text = GetString(94);
    DrawTextCenteredHighlight(text, 10, cursor == 1);
}

u8 NewGameLoadMenu(void)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;
    cursor = 0;
    LoadMenuScreen(6, (u16 *)buf);
    DrawNewGameLoadMenu(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
    do {
        ReadKeys();
        DrawNewGameLoadMenu(cursor);
        if (gKeysPressed & 1)
            sel = cursor;
        if (gKeysPressed & 2)
            sel = 10;
        cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 1);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
