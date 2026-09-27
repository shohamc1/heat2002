#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

u8 sub_08010EA0(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    u8 t;
    v = 0;
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    sub_080047DC();
    gVBlankWorkDone = 0;
    WaitForVBlank();
    ZeroTextLayer();
    sub_0800F4FC();
    sub_0800F328((u32)gMenuPalette, (u16 *)buf);
    sub_08010E04(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    do {
        ClearOamBuffer();
        t = v;
        sub_08010E04(t);
        ReadKeys();
        if (gKeysPressed & 1)
            sel = t;
inner:
        v = MenuMoveHorizontal(gKeysPressed, v, 0, 0x0B);
        if (v == 6 || v == 7 || v == 10 || v == 11) {
            if ((gKeysPressed & 0x30) == 0)
                gKeysPressed |= 0x10;
            goto inner;
        }
        if (gKeysPressed & 2)
            sel = 0;
        sub_080047DC();
        gVBlankWorkDone = 0;
wait:
        if (gVBlankWorkDone == 0)
            goto wait;
        WaitForVBlank();
        WaitForVBlank();
    } while (sel == 0x40);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel != 0 ? v : 0;
}
