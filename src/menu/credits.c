#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "data.h"

extern const u8 gCreditsPage1Gfx[];
extern const u16 gCreditsPage1MetatileMap[];
extern const u16 gCreditsPage1MetatileTable[];
extern const u8 gCreditsPage1Palette[];
extern const u8 gCreditsPage2Gfx[];
extern const u16 gCreditsPage2MetatileMap[];
extern const u16 gCreditsPage2MetatileTable[];
extern const u8 gCreditsPage2Palette[];
extern const u8 gCreditsPage3Gfx[];
extern const u16 gCreditsPage3MetatileMap[];
extern const u16 gCreditsPage3MetatileTable[];
extern const u8 gCreditsPage3Palette[];

void ShowCreditsPage1(void)
{
    u8 palette[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(gCreditsPage1Gfx, VRAM, 0xA280);
    CpuCopy16(gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON;
    DrawMetatileMap(gCreditsPage1MetatileMap, gCreditsPage1MetatileTable);
    BuildScreenPalette(gCreditsPage1Palette, (u16 *)palette);
    FadeToBrightenedPalette(palette, 0x0F);
    WaitFramesOrKey(600);
    FadeToColor(0, 0x0F);
}

void ShowCreditsPage2(void)
{
    u8 palette[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(gCreditsPage2Gfx, VRAM, 0xA280);
    CpuCopy16(gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON;
    DrawMetatileMap(gCreditsPage2MetatileMap, gCreditsPage2MetatileTable);
    BuildScreenPalette(gCreditsPage2Palette, (u16 *)palette);
    FadeToBrightenedPalette(palette, 0x0F);
    WaitFramesOrKey(600);
    FadeToColor(0, 0x0F);
}

void ShowCreditsPage3(void)
{
    u8 palette[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(gCreditsPage3Gfx, VRAM, 0xA280);
    CpuCopy16(gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON;
    DrawMetatileMap(gCreditsPage3MetatileMap, gCreditsPage3MetatileTable);
    BuildScreenPalette(gCreditsPage3Palette, (u16 *)palette);
    FadeToBrightenedPalette(palette, 0x0F);
    WaitFramesOrKey(600);
    FadeToColor(0, 0x0F);
}
