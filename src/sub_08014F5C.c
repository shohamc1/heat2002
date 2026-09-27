#include "global.h"
#include "functions.h"
#include "variables.h"
u8 sub_08014F5C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(1, (u16 *)buf);
    sub_08014EE8(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014EE8(v);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
