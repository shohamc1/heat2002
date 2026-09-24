#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012984(u8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);
u8 sub_080129E8(u8 arg)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 v = 0;
    sub_08011C9C(3, buf);
    sub_08012984(arg);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08012984(arg);
        if (gKeysPressed & 1)
            sel = v;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
