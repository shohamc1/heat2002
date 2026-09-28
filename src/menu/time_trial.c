#include "global.h"
#include "functions.h"
#include "data.h"

#include "m4a.h"
#include "variables.h"


void DrawTimeTrialMenu(u8 cursor)
{
    u8 sel;

    sel = cursor;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(4);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(5), 7, cursor == 0);
    DrawTextCenteredHighlight(GetString(6), 9, cursor == 1);
    DrawTextCenteredHighlight(GetString(0x9D), 0xB, cursor == 2);
    DrawTextCenteredHighlight(GetString(8), 0xD, sel == 3);
}


u8 TimeTrialMenu(void)
{
    u8 buf[0x200];
    s8 cursor;
    s8 sel;
    cursor = 0;
    LoadMenuScreen(2, (u16 *)buf);
    DrawTimeTrialMenu(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawTimeTrialMenu(cursor);
        if (gKeysPressed & 1)
            sel = cursor;
        if (gKeysPressed & 2)
            sel = 0x0A;
        cursor = MenuMoveVertical(gKeysPressed, cursor, 0, 3);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

