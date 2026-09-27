#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

u8 sub_08014004(void)
{
    u8 buf[0x200];
    s8 v;
    s32 a;
    s8 sel;
    /* The copy and narrowed test below preserve initialization/register order. */
    a = 0;
    v = a;
    SortCarsByTime();
    sub_08011C9C(6, (u16 *)buf);
    /* sub_08013E3C: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(s32))sub_08013E3C)(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(s32))sub_08013E3C)(a);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && a == 1) {
            a = 0;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && (u8)a == 0) {
            a = 1;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
