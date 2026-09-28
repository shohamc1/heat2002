#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

void DrawMessageBox(const u8 *title, const u8 *line1, const u8 *line2)
{
    const u8 *x = title;
    const u8 *y = line1;
    const u8 *z = line2;
    sub_08006734(gUnk_083FDE18[0]);
    DrawBigText(x);
    DrawTextCenteredHighlight(y, 6, 1);
    DrawTextCenteredHighlight(z, 7, 1);
}

u8 MessageBox(const u8 *title, const u8 *line1, const u8 *line2)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 v = 0;
    sub_08011C9C(3, (u16 *)buf);
    DrawMessageBox(title, line1, line2);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawMessageBox(title, line1, line2);
        if (gKeysPressed & 1)
            sel = v;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
