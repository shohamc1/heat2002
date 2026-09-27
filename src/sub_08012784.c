#include "global.h"
#include "functions.h"

extern u16 gKeysPressed;


u8 sub_08012784(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    sub_08011C9C(0, (u16 *)buf);
    /* sub_08012758: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(s8))sub_08012758)(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(s8))sub_08012758)(v);
        if (gKeysPressed & 1)
            sel = v;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
