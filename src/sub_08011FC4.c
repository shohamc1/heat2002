#include "global.h"
#include "functions.h"
#include "m4a.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
s8 sub_08011FC4(void)
{
    u8 buf[0x200];
    s32 a;
    s8 b;
    a = 0;
    b = 0;
    sub_08011C9C(4, (u16 *)buf);
    /* sub_08011F78: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(s32))sub_08011F78)(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    do {
        ReadKeys();
        ((void (*)(s32))sub_08011F78)(a);
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
