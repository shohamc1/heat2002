#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
u8 sub_08014A84(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    LoadMenuScreen(6, (u16 *)buf);
    sub_08014A38(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014A38(v);
        if (gKeysPressed & 1)
            sel = v;
        if (gKeysPressed & 2)
            sel = 0x0A;
        v = MenuMoveVertical(gKeysPressed, v, 0, 1);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
