#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

void sub_08014944(u8 a)
{
    const u8 *v;
    u8 b;

    b = a;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x0D);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x05);
    DrawTextCenteredHighlight(v, 8, a == 0);
    v = GetString(0x0E);
    DrawTextCenteredHighlight(v, 0xA, a == 1);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xC, b == 2);
}

u8 sub_080149A4(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(5, (u16 *)buf);
    sub_08014944(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014944(v);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 2);
        if (gKeysPressed & 2)
            sel = 0;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
