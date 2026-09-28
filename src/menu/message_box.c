#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

void DrawMessageBox(u32 a, u32 b, u32 c)
{
    u32 x = a;
    u32 y = b;
    u32 z = c;
    /* sub_08006734: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32))sub_08006734)(gUnk_083FDE18[0]);
    sub_080065A8((u8 *)x);
    DrawTextCenteredHighlight((u8 *)y, 6, 1);
    DrawTextCenteredHighlight((u8 *)z, 7, 1);
}

u8 MessageBox(u32 a, u32 b, u32 c)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 v = 0;
    sub_08011C9C(3, (u16 *)buf);
    DrawMessageBox(a, b, c);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawMessageBox(a, b, c);
        if (gKeysPressed & 1)
            sel = v;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
