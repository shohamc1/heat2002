#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
s8 sub_080136F8(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    LoadMenuScreen(6, (u16 *)buf);
    /* sub_08013684: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8, u8, u8))sub_08013684)(0, a, b);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8, u8, u8))sub_08013684)(v, a, b);
        if ((gKeysPressed & 9) && (b == 0 || v != 0) && (a == 0 || v != 1))
            sel = v;
        if (gKeysPressed & 2)
            sel = 0xFF;
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
again:
        if ((v == 0 && (a != 0 || b != 0)) || (v == 1 && a != 0)) {
            if (gKeysPressed & 0xC0)
                v = MenuMoveVertical(gKeysPressed, v, 0, 3);
            else
                v = MenuMoveVertical(0x80, v, 0, 3);
            goto again;
        }
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
