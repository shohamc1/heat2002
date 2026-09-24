#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012AF8(u8 a, u8 b);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);
u8 sub_08012B50(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 sel;
    /* The signed local keeps the parameter conversions in ROM order. */
    s8 v = a;
    sub_08011C9C(3, buf);
    sub_08012AF8(v, b);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08012AF8(v, b);
        if (gKeysPressed & 1)
            sel = v;
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
