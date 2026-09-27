#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u8 a, u16 *dst);
extern void DrawMessageBox(u32 a, u32 b, u32 c);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);
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
