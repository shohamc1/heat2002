#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "gba/compat.h"
#include "gba/syscall.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "m4a.h"

extern const u8 *const gChampionshipTeamNames[];
extern const u8 *const gChampionshipQualifyTexts[];
extern const u8 *const gChampionshipLockedTexts[];

/* The driver-car gfx tables point at one mPtr word each: a real pointer
   hosted, the ROM address in a u32 on the GBA. */
#if PORTABLE
#define DRIVER_CAR_GFX(tbl, i) (*(tbl)[(i)])
#else
#define DRIVER_CAR_GFX(tbl, i) (*(u32 *)(tbl)[(i)])
#endif

void DrawTeamSelectInfo(u8 teamId)
{
    const u8 *blankRow;

    blankRow = gText_BlankRowMenu;
    DrawText(blankRow, 0, 4, 0);
    DrawTextCenteredHighlight(gChampionshipTeamNames[teamId], 4, 1);
    DrawText(blankRow, 0, 17, 0);
    DrawText(blankRow, 0, 18, 0);
    DrawText(blankRow, 0, 19, 0);
    if (gChampionshipAvailable[teamId] != 0)
        DrawText(gChampionshipQualifyTexts[teamId], 0, 17, 1);
    else
        DrawText(gChampionshipLockedTexts[teamId], 0, 17, 1);
}

u16 FindTeamDriverPair(u8 teamId)
{
    u8 drivers[2];
    u8 i;
    u8 *lowByte;

    drivers[0] |= 0xFF;
    drivers[1] |= 0xFF;
    i = 0;
    do {
        if (gDriverRoster[i].teamId == teamId)
            drivers[0] = i;
        i++;
    } while (i != 30);
    i = 0;
    do {
        if (i != drivers[0] && gDriverRoster[i].teamId == teamId)
            drivers[1] = i;
        i++;
    } while (i != 30);
    lowByte = &drivers[0];
    return (drivers[1] << 8) | *lowByte;
}

u32 DrawTeamSelect(u8 teamId)
{
    u8 unused[0xC];
    u8 drivers[2];
    s32 pair;

    /* The ROM uses the u16 result without zero-extending it, which only a
       wider return type gives. */
    pair = ((s32 (*)(u8))FindTeamDriverPair)(teamId);
    drivers[0] = pair;
    drivers[1] = (pair & 0xFF00) >> 8;
    DrawBigText(GetString(112));
    DrawTeamSelectInfo(teamId);
    CpuCopy16(gDriverCarPalettes[0], OBJ_PLTT, OBJ_PLTT_SIZE);
    if (drivers[1] == 0xFF) {
        RLUnCompVram(DRIVER_CAR_GFX(gDriverCarGfxLeftTiles, drivers[0]), OBJ_VRAM0);
        RLUnCompVram(DRIVER_CAR_GFX(gDriverCarGfxRightTiles, drivers[0]), OBJ_VRAM0 + 0x1000);
        Draw64x64Sprite(56, 48, 0);
        Draw64x64Sprite(120, 48, 128);
    } else {
        RLUnCompVram(DRIVER_CAR_GFX(gDriverCarGfxLeftTiles, drivers[0]), OBJ_VRAM0);
        RLUnCompVram(DRIVER_CAR_GFX(gDriverCarGfxRightTiles, drivers[0]), OBJ_VRAM0 + 0x1000);
        RLUnCompVram(DRIVER_CAR_GFX(gDriverCarGfxLeftTiles, drivers[1]), OBJ_VRAM0 + 0x2000);
        RLUnCompVram(DRIVER_CAR_GFX(gDriverCarGfxRightTiles, drivers[1]), OBJ_VRAM0 + 0x3000);
        Draw64x64Sprite(96, 48, 0x100);
        Draw64x64Sprite(160, 48, 192 << 1);
        Draw64x64Sprite(16, 48, 0);
        Draw64x64Sprite(80, 48, 128);
    }
#if PORTABLE
    /* The ROM falls off the end; no caller reads the result. */
    return 0;
#endif
}

u8 TeamSelectMenu(void)
{
    u8 palette[0x200];
    s8 cursor;
    s8 choice;

    cursor = 12;
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
    DrawTeamSelect(0x0C);
    FadeToBrightenedPalette(palette, 0x0F);
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON;
    choice = 64;
    do {
        ClearOamBuffer();
        DrawTeamSelect(cursor);
        ReadKeys();
        if ((gKeysPressed & 1) && gChampionshipAvailable[cursor] != 0)
            choice = cursor;
        cursor = MenuMoveHorizontal(gKeysPressed, cursor, 0, 16);
        if (gKeysPressed & 2)
            choice = 0;
        UpdateSprites();
        gVBlankWorkDone = 0;
    spin:
#if PORTABLE
        /* The GBA's VBlank interrupt arrives from hardware mid-spin; the
           hosted build dispatches it only from the frame pump, so pump
           one VBlank here - the same instant the hardware would. */
        if (gVBlankWorkDone == 0)
        {
            VBlankIntrWait();
            goto spin;
        }
#else
        if (gVBlankWorkDone == 0)
            goto spin;
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
