#include "global.h"
#include "gba/io_reg.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"


u8 sub_08013D5C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    u8 x;
    x = v = 0;
    ZeroTextLayer();
    sub_0800F498();
    sub_0800F328((u32)gUnk_082EE104, (u16 *)buf);
    SortCarsByTime();
    sub_08013B64(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08013B64(x);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && x == 1) {
            x = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && x == 0) {
            x = 1;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
