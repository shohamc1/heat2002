#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
u8 sub_08013114(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(3, (u16 *)buf);
    sub_080130C8(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_080130C8(v);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 1);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
