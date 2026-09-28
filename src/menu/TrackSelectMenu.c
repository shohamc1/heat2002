#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"


u8 TrackSelectMenu(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    if (a == 0)
        v = b;
    gTrackSelectFrameCount = 0;
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    UpdateSprites();
    gVBlankWorkDone = 0;
    WaitForVBlank();
    ZeroTextLayer();
    LoadMenuBackdrop();
    BuildScreenPalette((u32)gMenuPalette, (u16 *)buf);
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
            || (a == 0 && gTrackSelectFrameCount == 0x20))
            sel = v;
        if (a != 0)
            v = MenuMoveHorizontalClamped(gKeysPressed, v, 0, 0x0B);
        if (v == 7) {
            if (gKeysPressed & DPAD_LEFT)
                v = 6;
            if (gKeysPressed & DPAD_RIGHT)
                v = 8;
        }
        gTrackSelectCursor = v;
        if ((gKeysPressed & B_BUTTON) && a != 0)
            sel = 0;
        UpdateSprites();
        gVBlankWorkDone = 0;
    spin:
        if (gVBlankWorkDone == 0)
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
