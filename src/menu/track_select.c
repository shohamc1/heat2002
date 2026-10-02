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

u8 DrawTrackSelect(u8 a, u8 b)
{
    u8 unused[0x34];
    u8 *p;

    if (b != 0) {
        DrawBigText(GetString(161));
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
    CpuCopy16(gTrackSelectEntries[a].previewPalette, OBJ_PLTT, OBJ_PLTT_SIZE);
    CpuCopy16(gTrackSelectArrowPalette, OBJ_PLTT + 0x1E0, 0x20);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->topLeftGfx, OBJ_VRAM0);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->topRightGfx, OBJ_VRAM0 + 0x1000);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->bottomLeftGfx, OBJ_VRAM0 + 0x2000);
    RLUnCompVram(gTrackSelectEntries[a].previewGfx->bottomRightGfx, OBJ_VRAM0 + 0x3000);
    Draw64x64Sprite(56, 32, 0);
    Draw64x64Sprite(120, 32, 128);
    Draw64x64Sprite(56, 96, 0x100);
    Draw64x64Sprite(120, 96, 192 << 1);
    if (b != 0 && (gTrackSelectFrameCount & 4) != 0) {
        RLUnCompVram(gTrackSelectLeftArrowGfx, OBJ_VRAM1);
        RLUnCompVram(gTrackSelectRightArrowGfx, OBJ_VRAM1 + 0x1000);
        if (a != 0)
            Draw32x32Sprite(16, 72, 128 << 2);
        if (a != 11)
            Draw32x32Sprite(208, 72, 160 << 2);
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
    sel = 64;
    do {
        ClearOamBuffer();
        DrawTrackSelect(v, a);
        ReadKeys();
        if (((gKeysPressed & A_BUTTON) && a == 1) || (a == 0 && gTrackSelectFrameCount == 0x20))
            sel = v;
        if (a != 0)
            v = MenuMoveHorizontalClamped(gKeysPressed, v, 0, 11);
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
#if PORTABLE
        /* The GBA's VBlank interrupt arrives from hardware mid-spin; the
           hosted build dispatches it only from the frame pump, so pump
           one VBlank here - the same instant the hardware would. */
        if (gVBlankWorkDone == 0) {
            VBlankIntrWait();
            goto spin;
        }
#else
        if (gVBlankWorkDone == 0)
            goto spin;
#endif
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
