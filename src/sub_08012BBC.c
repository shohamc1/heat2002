#include "global.h"
#include "functions.h"
extern u16 gKeysPressed;
u8 sub_08012BBC(s8 arg)
{
    u8 buf[0x200];
    s8 sel;
    sub_08011C9C(3, (u16 *)buf);
    /* sub_08012B24: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8))sub_08012B24)(arg);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8))sub_08012B24)(arg);
        if (gKeysPressed & 1)
            sel = arg;
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
