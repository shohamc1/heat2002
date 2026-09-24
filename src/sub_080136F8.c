#include "global.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08013684(u8 a, u8 b, u8 c);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern u8 MenuMoveVertical(u16 keys, s8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
s8 sub_080136F8(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(6, buf);
    sub_08013684(0, a, b);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08013684(v, a, b);
        if ((gKeysPressed & 9) && (b == 0 || v != 0) && (a == 0 || v != 1))
            sel = v;
        if (gKeysPressed & 2)
            sel = 0xFF;
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
again:
        if ((v == 0 && (a != 0 || b != 0)) || (v == 1 && a != 0)) {
            if (gKeysPressed & 0xC0)
                v = MenuMoveVertical(gKeysPressed, v, 0, 3);
            else
                v = MenuMoveVertical(0x80, v, 0, 3);
            goto again;
        }
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
