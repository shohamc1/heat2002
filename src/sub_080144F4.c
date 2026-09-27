#include "global.h"
#include "functions.h"
#include "m4a.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
u8 sub_080144F4(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(2, (u16 *)buf);
    sub_08014480(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014480(v);
        if (gKeysPressed & 1)
            sel = v;
        if (gKeysPressed & 2)
            sel = 0x0A;
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
