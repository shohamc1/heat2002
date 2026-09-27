#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"



u8 sub_08015060(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    sub_08011C9C(0, (u16 *)buf);
    sub_08015000(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08015000(v);
        if (gKeysPressed & 1) {
            if (gOptions[3])
                m4aSongNumStart(9);
            sel = v;
        }
        if (gKeysPressed & 2)
            sel = 0x0A;
        v = MenuMoveVertical(gKeysPressed, v, 0, 2);
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
