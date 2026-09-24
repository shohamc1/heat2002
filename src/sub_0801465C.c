#include "global.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
extern u8 gUnk_0202EF08[];
extern u8 gUnk_0202EF14;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08014614(s8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern u8 MenuMoveVertical(u16 keys, s8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
u8 sub_0801465C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(5, buf);
    sub_08014614(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014614(v);
        if (gKeysPressed & 1) {
            sel = v;
            gUnk_0202EF14 = v;
        }
    retry:
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
        if (gUnk_0202EF08[v] == 0)
            goto retry;
        if (gKeysPressed & 2)
            sel = 0;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
