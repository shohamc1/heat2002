#include "global.h"
#include "functions.h"

extern u16 gKeysPressed;


u8 sub_08015244(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    SortCarsByTime();
    sub_08011C9C(0, (u16 *)buf);
    sub_080150F4();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_080150F4();
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(*(volatile u16 *)&gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
