#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

extern const u8 gText_QualifyingResults[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_0801435C(void)
{
    return sub_08012384((u32)gText_QualifyingResults, 0x30, 0x4C);
}

void sub_08014374(void)
{
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(0x12));
    DrawTextCenteredHighlight(GetString(0x11), 7, 1);
    DrawTextCenteredHighlight(GetString(0x11), 8, 1);
    DrawTextCenteredHighlight(GetString(0x11), 9, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xA, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xB, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xC, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xD, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xE, 1);
}

u8 sub_08014400(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    LoadMenuScreen(2, (u16 *)buf);
    sub_08014374();
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014374();
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
