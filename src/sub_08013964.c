#include "global.h"
#include "functions.h"
#include "m4a.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
s8 sub_08013964(void)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 v = 0;
    /* sub_08016634: this file's old prototypes return s8; the matched definitions return wider types */
    if (((s8 (*)(void))sub_08016634)() != 0) {
        if (((s8 (*)(void))sub_08013878)() == 0)
            return;
    }
    sub_08011C9C(6, (u16 *)buf);
    sub_08013908(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    SaveSeason();
    sub_08013908(1);
    sel = 0x40;
    do {
        ReadKeys();
        if (gKeysPressed & 9)
            sel = v;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
