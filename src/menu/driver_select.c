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

    DrawBigText(GetString(156));
    DrawText(gText_BlankRowMenu, 0, 6, 0);
    DrawTextCenteredHighlight(gDriverRoster[driverIdx].name, 6, 1);
    CpuCopy16(gDriverCarPalettes[driverIdx], OBJ_PLTT, OBJ_PLTT_SIZE);
#if PORTABLE
    RLUnCompVram(*gDriverCarGfxLeftTiles[driverIdx], OBJ_VRAM0);
    RLUnCompVram(*gDriverCarGfxRightTiles[driverIdx], OBJ_VRAM0 + 0x1000);
#else
    RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[driverIdx], OBJ_VRAM0);
    RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[driverIdx], OBJ_VRAM0 + 0x1000);
#endif
    Draw64x64Sprite(56, 64, 0);
    Draw64x64Sprite(120, 64, 128);
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
    BuildScreenPalette(gMenuPalette, (u16 *)palette);
    DrawDriverSelect(0);
    FadeToBrightenedPalette(palette, 0x0F);
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON;
    choice = 64;
    do {
        ClearOamBuffer();
        driver = cursor;
        DrawDriverSelect(driver);
        ReadKeys();
        if (gKeysPressed & 1)
            choice = driver;
    inner:
        cursor = MenuMoveHorizontal(gKeysPressed, cursor, 0, 11);
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
#if PORTABLE
        /* The GBA's VBlank interrupt arrives from hardware mid-spin; the
           hosted build dispatches it only from the frame pump, so pump
           one VBlank here - the same instant the hardware would. */
        if (gVBlankWorkDone == 0)
        {
            VBlankIntrWait();
            goto wait;
        }
#else
        if (gVBlankWorkDone == 0)
            goto wait;
#endif
        WaitForVBlank();
        WaitForVBlank();
    } while (choice == 0x40);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    WaitForVBlank();
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return choice != 0 ? cursor : 0;
}
