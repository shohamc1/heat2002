#include "global.h"
#include "functions.h"
#include "data.h"

#include "variables.h"


void DrawLinkPostRaceMenu(u8 selected)
{
    u8 cur = selected;
    const u8 *text; DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x5A);
    ((void (*)(void))DrawBigText)();
    text = GetString(0x05);
    DrawTextCenteredHighlight(text, 7, selected == 0);
    text = GetString(0x06);
    DrawTextCenteredHighlight(text, 9, selected == 1);
    text = GetString(0x07);
    DrawTextCenteredHighlight(text, 0xB, selected == 2);
    text = GetString(0x08);
    DrawTextCenteredHighlight(text, 0xD, cur == 3);
}


u8 LinkPostRaceMenu(void)
{
    u8 palette[0x200];
    s8 choice;
    s8 cursor;
    u16 old;
    u16 keys;

    ResetLinkState();
    cursor = 0;
    LoadMenuScreen(1, (u16 *)palette);
    DrawLinkPostRaceMenu(0);
    FadeToBrightenedPalette((u32)palette, 0x0F);
    choice = 0x40;
    do
    {
        old = gPlayerKeys[0];
        if (ExchangeLinkInput() != 0)
        {
            choice = 5;
        }
        else
        {
            keys = (gPlayerKeys[0] ^ old) & gPlayerKeys[0];
            if (keys & 9)
                choice = cursor;
            cursor = MenuMoveVertical(keys, cursor, 0, 3);
            DrawLinkPostRaceMenu(cursor);
            WaitForVBlank();
        }
    } while (choice == 0x40);
    FadeToColor(0, 0x0F);
    return choice;
}

