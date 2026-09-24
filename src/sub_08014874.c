#include "global.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
extern s8 gUnk_0202EF60[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08014708(u8 a, u8 b);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern u8 MenuMoveVertical(u16 keys, s8 v, s16 lo, s16 hi);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
u8 sub_08014874(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s32 sel;
    v = b;
    sub_08011C9C(5, buf);
    sub_08014708(a, v);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014708(a, v);
    retry:
        v = MenuMoveVertical(gKeysPressed, v, (b >> 2) * 4, (b >> 2) * 4 + 3);
        if (gUnk_0202EF60[v] == -1)
            goto retry;
        if (gKeysPressed & 3)
            sel = 1;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return v;
}
