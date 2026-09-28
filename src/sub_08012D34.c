#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "functions.h"
#include "variables.h"



u8 sub_08012D34(u8 a)
{
    u8 buf[0x200];
    s8 sel;
    u8 v;

    v = 0;
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    LoadMenuScreen(6, (u16 *)buf);
    ClearOamBuffer();
    sub_08012C4C(a);
    UpdateSprites();
    gVBlankWorkDone = v;
    WaitForVBlank();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    do
    {
        ClearOamBuffer();
        ReadKeys();
        sub_08012C4C(a);
        if (gKeysPressed & 1)
            sel = v;
        UpdateSprites();
        gVBlankWorkDone = 0;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
