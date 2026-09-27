#include "global.h"
#include "functions.h"
#include "variables.h"
u8 sub_08012B50(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 sel;
    /* The signed local keeps the parameter conversions in ROM order. */
    s8 v = a;
    sub_08011C9C(3, (u16 *)buf);
    /* sub_08012AF8: this file's old prototype takes a second
       argument the matched definition drops; call through a
       function pointer with the old signature. */
    ((void (*)(u8, u8))sub_08012AF8)(v, b);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8, u8))sub_08012AF8)(v, b);
        if (gKeysPressed & 1)
            sel = v;
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
