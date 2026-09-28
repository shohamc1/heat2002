#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

void sub_080139F0(void)
{
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x30);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x11), 7, 1);
    DrawTextCenteredHighlight(GetString(0x11), 8, 1);
    DrawTextCenteredHighlight(GetString(0x11), 9, 1);
    DrawTextCenteredHighlight(GetString(0x11), 10, 1);
    DrawTextCenteredHighlight(GetString(0x11), 11, 1);
    DrawTextCenteredHighlight(GetString(0x11), 12, 1);
    DrawTextCenteredHighlight(GetString(0x11), 13, 1);
    DrawTextCenteredHighlight(GetString(0x11), 14, 1);
}

u8 sub_08013A7C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    LoadMenuScreen(6, (u16 *)buf);
    sub_080139F0();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_080139F0();
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(*(volatile u16 *)&gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
