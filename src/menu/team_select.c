#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

extern const u8 *const gChampionshipTeamNames[];
extern const u8 *const gChampionshipQualifyTexts[];
extern const u8 *const gChampionshipLockedTexts[];
#include "gba/compat.h"
#include "gba/syscall.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "m4a.h"

void DrawTeamSelectInfo(u8 teamId)
{
    u8 *blankRow;

    blankRow = gText_BlankRowMenu;
    DrawText(blankRow, 0, 4, 0);
    DrawTextCenteredHighlight(gChampionshipTeamNames[teamId], 4, 1);
    DrawText(blankRow, 0, 0x11, 0);
    DrawText(blankRow, 0, 0x12, 0);
    DrawText(blankRow, 0, 0x13, 0);
    if (gChampionshipAvailable[teamId] != 0)
        DrawText(gChampionshipQualifyTexts[teamId], 0, 0x11, 1);
    else
        DrawText(gChampionshipLockedTexts[teamId], 0, 0x11, 1);
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
    } while (i != 0x1E);
    i = 0;
    do {
        if (i != drivers[0] && gDriverRoster[i].teamId == teamId)
            drivers[1] = i;
        i++;
    } while (i != 0x1E);
    lowByte = &drivers[0];
    return (drivers[1] << 8) | *lowByte;
}

u32 DrawTeamSelect(u8 teamId)
{
    u8 unused[0xC];
    u8 drivers[2];
    s32 pair;

    /* FindTeamDriverPair: this file's old prototype returns s32; the matched definition returns u16 */
    pair = ((s32 (*)(u8))FindTeamDriverPair)(teamId);
    drivers[0] = pair;
    drivers[1] = (pair & 0xFF00) >> 8;
    GetString(0x70);
    ((void (*)(void))DrawBigText)();
    DrawTeamSelectInfo(teamId);
    CpuCopy16((u32)gDriverCarPalettes[0], OBJ_PLTT, OBJ_PLTT_SIZE);
    if (drivers[1] == 0xFF) {
        RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[drivers[0]], OBJ_VRAM0);
        RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[drivers[0]], OBJ_VRAM0 + 0x1000);
        Draw64x64Sprite(0x38, 0x30, 0);
        Draw64x64Sprite(0x78, 0x30, 0x80);
    } else {
        RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[drivers[0]], OBJ_VRAM0);
        RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[drivers[0]], OBJ_VRAM0 + 0x1000);
        RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[drivers[1]], OBJ_VRAM0 + 0x2000);
        RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[drivers[1]], OBJ_VRAM0 + 0x3000);
        Draw64x64Sprite(0x60, 0x30, 0x80 << 1);
        Draw64x64Sprite(0xA0, 0x30, 0xC0 << 1);
        Draw64x64Sprite(0x10, 0x30, 0);
        Draw64x64Sprite(0x50, 0x30, 0x80);
    }
}

u8 TeamSelectMenu(void)
{
    u8 palette[0x200];
    s8 cursor;
    s8 choice;

    cursor = 0x0C;
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
    DrawTeamSelect(0x0C);
    FadeToBrightenedPalette((u32)palette, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    choice = 0x40;
    do {
        ClearOamBuffer();
        DrawTeamSelect(cursor);
        ReadKeys();
        if ((gKeysPressed & 1) && gChampionshipAvailable[cursor] != 0)
            choice = cursor;
        cursor = MenuMoveHorizontal(gKeysPressed, cursor, 0, 0x10);
        if (gKeysPressed & 2)
            choice = 0;
        UpdateSprites();
        gVBlankWorkDone = 0;
    spin:
        if (gVBlankWorkDone == 0)
            goto spin;
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
