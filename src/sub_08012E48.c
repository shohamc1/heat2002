#include "global.h"

extern u16 gKeysPressed;
extern u8 gOptions[];
extern u8 gUnk_0202ED70;

extern void sub_08011C9C(u8 a, u16 *dst);
extern void sub_08012DEC(u8 a, u8 b);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void ReadKeys(void);
extern s16 MenuMoveVertical(u16 keys, s16 v, s16 lo, s16 hi);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);

u8 sub_08012E48(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    WaitForVBlank();
    sub_08011C9C(3, (u16 *)buf);
    sub_08012DEC(0, gUnk_0202ED70);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08012DEC(v, gUnk_0202ED70);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 1);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel ^ 1;
}
