#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "gba/syscall.h"
#include "data.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "variables.h"

extern u32 gChampionshipTrophyGfx;
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
    u32 palette;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x8F);
    ((void (*)(void))DrawBigText)();
    if (place <= 2) {
        DrawTextCenteredHighlight(GetString(0x91), 4, 1);
    } else {
        DrawTextCenteredHighlight(gText_Congratulations_2, 6, 1);
        DrawTextCenteredHighlight(gText_YouCompletedTheSeason, 0xA, 1);
    }
    if (place <= 2)
        RLUnCompVram(gChampionshipTrophyGfx, OBJ_VRAM0);
    if (place == 0) {
        palette = (u32)gGoldTrophyPalette;
        DrawCachedSprite(0x58, 0x40, 0, palette, place);
    }
    if (place == 1) {
        palette = (u32)gSilverTrophyPalette;
        DrawCachedSprite(0x58, 0x40, 0, palette, 0);
    }
    if (place == 2) {
        palette = (u32)gBronzeTrophyPalette;
        DrawCachedSprite(0x58, 0x40, 0, palette, 0);
    }
    if (place == 0)
        DrawTextCenteredHighlight(gText_Gold, 0x12, 1);
    if (place == 1)
        DrawTextCenteredHighlight(gText_Silver, 0x12, 1);
    if (place == 2)
        DrawTextCenteredHighlight(gText_Bronze, 0x12, 1);
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
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
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
