#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
u8 sub_08012F1C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(3, (u16 *)buf);
    /* sub_08012EE8: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(u8, u8))sub_08012EE8)(0, gUnk_0202ED70);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8, u8))sub_08012EE8)(v, gUnk_0202ED70);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
