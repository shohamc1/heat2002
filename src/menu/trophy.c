#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "gba/syscall.h"
#include "data.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "variables.h"

#if PORTABLE
extern const u8 *const gChampionshipTrophyGfx;
#else
extern u32 gChampionshipTrophyGfx;
#endif
extern u8 gText_Congratulations_2[];
extern u8 gText_YouCompletedTheSeason[];
extern u8 gGoldTrophyPalette[];
extern u8 gSilverTrophyPalette[];
extern u8 gBronzeTrophyPalette[];
extern u8 gText_Gold[];
extern u8 gText_Silver[];
extern u8 gText_Bronze[];

void DrawTrophyScreen(u32 place)
{
    const void *palette;

    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(143));
    if (place <= 2) {
        DrawTextCenteredHighlight(GetString(145), 4, 1);
    } else {
        DrawTextCenteredHighlight(gText_Congratulations_2, 6, 1);
        DrawTextCenteredHighlight(gText_YouCompletedTheSeason, 10, 1);
    }
    if (place <= 2)
        RLUnCompVram(gChampionshipTrophyGfx, OBJ_VRAM0);
    if (place == 0) {
        palette = gGoldTrophyPalette;
        DrawCachedSprite(88, 64, 0, palette, place);
    }
    if (place == 1) {
        palette = gSilverTrophyPalette;
        DrawCachedSprite(88, 64, 0, palette, 0);
    }
    if (place == 2) {
        palette = gBronzeTrophyPalette;
        DrawCachedSprite(88, 64, 0, palette, 0);
    }
    if (place == 0)
        DrawTextCenteredHighlight(gText_Gold, 18, 1);
    if (place == 1)
        DrawTextCenteredHighlight(gText_Silver, 18, 1);
    if (place == 2)
        DrawTextCenteredHighlight(gText_Bronze, 18, 1);
}

u8 TrophyScreen(u8 place)
{
    u8 buf[0x200];
    s8 sel;
    u8 done;

    done = 0;
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    LoadMenuScreen(6, (u16 *)buf);
    ClearOamBuffer();
    DrawTrophyScreen(place);
    UpdateSprites();
    gVBlankWorkDone = done;
    WaitForVBlank();
    FadeToBrightenedPalette(buf, 0x0F);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON;
    sel = 64;
    do {
        ClearOamBuffer();
        ReadKeys();
        DrawTrophyScreen(place);
        if (gKeysPressed & 1)
            sel = done;
        UpdateSprites();
        gVBlankWorkDone = 0;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
