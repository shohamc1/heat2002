#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
extern u16 gKeysPressed;
extern u8 gUnk_020020C0;
extern u8 gOptions[];
extern u8 gUnk_0202EF20[];

u8 sub_08010CD0(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0x0C;
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    sub_080047DC();
    gUnk_020020C0 = 0;
    WaitForVBlank();
    ZeroTextLayer();
    sub_0800F4FC();
    sub_0800F328((u32)gUnk_082E4328, (u16 *)buf);
    sub_08010BA8(0x0C);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    do {
        ClearOamBuffer();
        sub_08010BA8(v);
        ReadKeys();
        if ((gKeysPressed & 1) && gUnk_0202EF20[v] != 0)
            sel = v;
        v = MenuMoveHorizontal(gKeysPressed, v, 0, 0x10);
        if (gKeysPressed & 2)
            sel = 0;
        sub_080047DC();
        gUnk_020020C0 = 0;
    spin:
        if (gUnk_020020C0 == 0)
            goto spin;
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
