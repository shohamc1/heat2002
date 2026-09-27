#include "global.h"
#include "functions.h"
#include "m4a.h"

extern u16 gKeysPressed;
extern u8 gOptions[];
extern u8 gUnk_0202ED70;


u8 sub_080126BC(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    sub_08011C9C(3, (u16 *)buf);
    sub_0801264C(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_0801264C(v);
        if (gKeysPressed & 1) {
            sel = v;
            gUnk_0202ED70 = v;
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
