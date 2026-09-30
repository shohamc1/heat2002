#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "gba/syscall.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "m4a.h"
#include "variables.h"

extern const u8 gText_TrackMichigan[];
extern const u8 gText_TrackIntlSpeedway[];
extern const u8 gTrackSelectArrowPalette[];
extern const u8 gTrackSelectLeftArrowGfx[];
extern const u8 gTrackSelectRightArrowGfx[];
extern const struct TrackSelectEntry gTrackSelectEntries[];
void Draw32x32Sprite(u32 tile, u32 pal, u32 c);

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
    BuildScreenPalette(gMenuPalette, (u16 *)palette);
    DrawDriverSelect(0);
    FadeToBrightenedPalette(palette, 0x0F);
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON;
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
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    WaitForVBlank();
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return choice != 0 ? cursor : 0;
}

u8 DrawTrackSelect(u8 a, u8 b)
{
    u8 unused[0x34];
    u8 *p;

    if (b != 0) {
        GetString(0xA1);
        /* DrawBigText: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(void))DrawBigText)();
    }
    p = (u8 *)gText_BlankRowMenu;
    DrawText(p, 0, 4, 0);
    DrawText(p, 0, 5, 0);
    if (a != 3) {
        DrawTextCenteredHighlight(gTrackSelectEntries[a].nameText, 4, 1);
    } else {
        DrawTextCenteredHighlight(gText_TrackMichigan, 4, 1);
        DrawTextCenteredHighlight(gText_TrackIntlSpeedway, 5, 1);
    }
    CpuCopy16((u32)gTrackSelectEntries[a].previewPalette, OBJ_PLTT, OBJ_PLTT_SIZE);
    CpuCopy16((u32)gTrackSelectArrowPalette, OBJ_PLTT + 0x1E0, 0x20);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->topLeftGfx, OBJ_VRAM0);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->topRightGfx, OBJ_VRAM0 + 0x1000);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->bottomLeftGfx, OBJ_VRAM0 + 0x2000);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->bottomRightGfx, OBJ_VRAM0 + 0x3000);
    Draw64x64Sprite(0x38, 0x20, 0);
    Draw64x64Sprite(0x78, 0x20, 0x80);
    Draw64x64Sprite(0x38, 0x60, 0x80 << 1);
    Draw64x64Sprite(0x78, 0x60, 0xC0 << 1);
    if (b != 0 && (gTrackSelectFrameCount & 4) != 0) {
        RLUnCompVram((u32)gTrackSelectLeftArrowGfx, OBJ_VRAM1);
        RLUnCompVram((u32)gTrackSelectRightArrowGfx, OBJ_VRAM1 + 0x1000);
        if (a != 0)
            Draw32x32Sprite(0x10, 0x48, 0x80 << 2);
        if (a != 0xB)
            Draw32x32Sprite(0xD0, 0x48, 0xA0 << 2);
    }
    gTrackSelectFrameCount++;
}

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
    BuildScreenPalette(gMenuPalette, (u16 *)buf);
    DrawTrackSelect(v, a);
    FadeToBrightenedPalette(buf, 0x0F);
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON;
    sel = 0x40;
    do {
        ClearOamBuffer();
        DrawTrackSelect(v, a);
        ReadKeys();
        if (((gKeysPressed & A_BUTTON) && a == 1) || (a == 0 && gTrackSelectFrameCount == 0x20))
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
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    WaitForVBlank();
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel != 0 ? v : 0;
}
