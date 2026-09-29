#include "global.h"
#include "functions.h"
#include "data.h"

#include "m4a.h"
#include "variables.h"

void DrawMultiplayerMenu(u8 selected)
{
    const u8 *text;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x5A);
    ((void (*)(void))DrawBigText)();
    text = GetString(0x51);
    DrawTextCenteredHighlight(text, 9, selected == 0);
    text = GetString(0x52);
    DrawTextCenteredHighlight(text, 0xB, selected == 1);
}

s8 MultiplayerMenu(void)
{
    u8 palette[0x200];
    s32 cursor;
    s8 choice;
    cursor = 0;
    choice = 0;
    LoadMenuScreen(4, (u16 *)palette);
    /* DrawMultiplayerMenu: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(s32))DrawMultiplayerMenu)(0);
    FadeToBrightenedPalette((u32)palette, 0x0F);
    do {
        ReadKeys();
        ((void (*)(s32))DrawMultiplayerMenu)(cursor);
        if (gKeysPressed & 0xC0) {
            cursor ^= 1;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        if (gKeysPressed & 2)
            choice = -1;
        if (gKeysPressed & 9) {
            choice = cursor + 1;
            if (gOptions[3])
                m4aSongNumStart(9);
        }
        WaitForVBlank();
    } while (choice == 0);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return choice;
}
