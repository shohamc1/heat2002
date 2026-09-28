#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "gba/syscall.h"

#include "gba/io_reg.h"
#include "gba/defines.h"
#include "m4a.h"
#include "variables.h"


u8 DrawDriverSelect(u8 driverIdx)
{
    u8 unused[0xC];

    GetString(0x9C);
    /* DrawBigText: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(void))DrawBigText)();
    DrawText(gText_BlankRowMenu, 0, 6, 0);
    DrawTextCenteredHighlight(gDriverRoster[driverIdx].name, 6, 1);
    CpuCopy16((u32)gDriverCarPalettes[driverIdx], OBJ_PLTT, OBJ_PLTT_SIZE);
    RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[driverIdx], OBJ_VRAM0);
    RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[driverIdx], OBJ_VRAM0 + 0x1000);
    Draw64x64Sprite(0x38, 0x40, 0);
    Draw64x64Sprite(0x78, 0x40, 0x80);
}


u8 DriverSelectMenu(void)
{
    u8 palette[0x200];
    s8 cursor;
    s8 choice;
    u8 driver;
    cursor = 0;
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    UpdateSprites();
    gVBlankWorkDone = 0;
    WaitForVBlank();
    ZeroTextLayer();
    LoadMenuBackdrop();
    BuildScreenPalette((u32)gMenuPalette, (u16 *)palette);
    DrawDriverSelect(0);
    FadeToBrightenedPalette((u32)palette, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    choice = 0x40;
    do {
        ClearOamBuffer();
        driver = cursor;
        DrawDriverSelect(driver);
        ReadKeys();
        if (gKeysPressed & 1)
            choice = driver;
inner:
        cursor = MenuMoveHorizontal(gKeysPressed, cursor, 0, 0x0B);
        if (cursor == 6 || cursor == 7 || cursor == 10 || cursor == 11) {
            if ((gKeysPressed & 0x30) == 0)
                gKeysPressed |= 0x10;
            goto inner;
        }
        if (gKeysPressed & 2)
            choice = 0;
        UpdateSprites();
        gVBlankWorkDone = 0;
wait:
        if (gVBlankWorkDone == 0)
            goto wait;
        WaitForVBlank();
        WaitForVBlank();
    } while (choice == 0x40);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return choice != 0 ? cursor : 0;
}

