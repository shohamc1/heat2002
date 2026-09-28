#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

void sub_0801264C(u32 x)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x14);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x15), 8, x == 0);
    DrawTextCenteredHighlight(GetString(0x16), 0xA, x == 1);
    DrawTextCenteredHighlight(GetString(0x17), 0xC, x == 2);
    DrawTextCenteredHighlight(GetString(0x18), 0xE, x == 3);
}

u8 sub_080126BC(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    sub_08011C9C(3, (u16 *)buf);
    sub_0801264C(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_0801264C(v);
        if (gKeysPressed & 1) {
            sel = v;
            gChallengeIndex = v;
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void sub_08012758(void)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x8F);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x90), 8, 1);
}

u8 sub_08012784(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    sub_08011C9C(0, (u16 *)buf);
    /* sub_08012758: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(s8))sub_08012758)(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(s8))sub_08012758)(v);
        if (gKeysPressed & 1)
            sel = v;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
