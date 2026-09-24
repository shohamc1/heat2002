#include "global.h"

extern u16 gKeysPressed;

extern void SortCarsByTime(void);
extern void sub_08011C9C(u32 a, void *b);
extern void sub_080150F4(void);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern u8 MenuMoveVertical(u16 keys, s8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);

u8 sub_08015244(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    SortCarsByTime();
    sub_08011C9C(0, buf);
    sub_080150F4();
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_080150F4();
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(*(volatile u16 *)&gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
