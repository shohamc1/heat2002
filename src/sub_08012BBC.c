#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012B24(u8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);
u8 sub_08012BBC(s8 arg)
{
    u8 buf[0x200];
    s8 sel;
    sub_08011C9C(3, buf);
    sub_08012B24(arg);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08012B24(arg);
        if (gKeysPressed & 1)
            sel = arg;
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
