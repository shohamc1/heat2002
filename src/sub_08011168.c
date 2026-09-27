#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"

extern u16 gKeysPressed;
extern u8 gUnk_020020C0;
extern u8 gUnk_0202EED8;
extern u8 gOptions[];
extern u8 gUnk_0202EF8C;

u8 TrackSelectMenu(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    if (a == 0)
        v = b;
    gUnk_0202EED8 = 0;
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
    DrawTrackSelect(v, a);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    do {
        ClearOamBuffer();
        DrawTrackSelect(v, a);
        ReadKeys();
        if (((gKeysPressed & A_BUTTON) && a == 1)
            || (a == 0 && gUnk_0202EED8 == 0x20))
            sel = v;
        if (a != 0)
            v = MenuMoveHorizontalClamped(gKeysPressed, v, 0, 0x0B);
        if (v == 7) {
            if (gKeysPressed & DPAD_LEFT)
                v = 6;
            if (gKeysPressed & DPAD_RIGHT)
                v = 8;
        }
        gUnk_0202EF8C = v;
        if ((gKeysPressed & B_BUTTON) && a != 0)
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
