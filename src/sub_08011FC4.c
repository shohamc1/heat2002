#include "global.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
extern void sub_08011C9C(u8 a, u16 *dst);
extern void sub_08011F78(s32 a);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
s8 sub_08011FC4(void)
{
    u8 buf[0x200];
    s32 a;
    s8 b;
    a = 0;
    b = 0;
    sub_08011C9C(4, (u16 *)buf);
    sub_08011F78(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    do {
        ReadKeys();
        sub_08011F78(a);
        if (gKeysPressed & 0xC0) {
            a ^= 1;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        if (gKeysPressed & 2)
            b = -1;
        if (gKeysPressed & 9) {
            b = a + 1;
            if (gOptions[3])
                m4aSongNumStart(9);
        }
        WaitForVBlank();
    } while (b == 0);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return b;
}
