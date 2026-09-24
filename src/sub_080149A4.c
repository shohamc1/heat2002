#include "global.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08014944(u8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern u8 MenuMoveVertical(u16 keys, s8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
u8 sub_080149A4(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(5, buf);
    sub_08014944(0);
    FadeToBrightenedPalette(buf, 0x0F);
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
