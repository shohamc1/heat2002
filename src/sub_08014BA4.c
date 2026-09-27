#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "functions.h"
extern u16 gKeysPressed;
extern u8 gUnk_020020C0;

u8 sub_08014BA4(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    s8 w;

    v = 0;
    sub_08011C9C(12, (u16 *)buf);
    REG_DISPCNT = 0x1341;
    sub_08014B14();
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    /* sub_08014BA0: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8))sub_08014BA0)(0);
    sub_080047DC();
    gUnk_020020C0 = v;
    WaitForVBlank();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    w = 0;
    do {
        AgeGfxCaches();
        ClearOamBuffer();
        ((void (*)(u8))sub_08014BA0)(w);
        sub_080047DC();
        ReadKeys();
        if (gKeysPressed & 1)
            sel = w;
        gUnk_020020C0 = 0;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
