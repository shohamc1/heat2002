#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "m4a.h"

extern u16 gKeysPressed;
extern u8 gOptions[];
u8 sub_08014E28(void)
{
    u8 buf[0x200];
    s8 z;
    s8 v;
    s8 sel;
    z = 0;
    v = 0;
    SortCarsByTime();
    sub_08011C9C(1, (u16 *)buf);
    sub_08014C60(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014C60(v);
        if (gKeysPressed & A_BUTTON)
            sel = z;
        if ((gKeysPressed & DPAD_UP) && v != 0) {
            v = 0;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && v == 0) {
            v = 1;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
