#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "data.h"

extern const u8 gUnk_082A9F0C[];
extern const u16 gMainMenuMetatileMapAndTable[];
extern u32 gUnk_082EE8E0[];
#if PORTABLE
extern const u32 gResultsScreenGfxSize;
#endif
extern const u16 gResultsScreenMetatileMapAndTable[];
extern const u8 gUnk_082E4B04[];
extern const u16 gMenuBackdropMetatileMapAndTable[];
extern const u8 gBootSplash1Gfx[];
extern const u16 gBootSplash1MetatileMap[];
extern const u16 gBootSplash1MetatileTable[];
extern const u8 gBootSplash1Palette[];

void LoadMainMenuBackdrop(void)
{
    REG_BG0CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(gUnk_082A9F0C, VRAM, 0xA280);
    CpuCopy16(gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    DrawBackdropMetatileMap(gMainMenuMetatileMapAndTable);
}

void LoadResultsScreenBackdrop(void)
{
    const u8 *src;
    u8 *dest;
    u32 size;

    REG_BG0CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    src = (const u8 *)gUnk_082EE8E0;
    dest = (u8 *)VRAM;
    size = 0x5140;
#if PORTABLE
    /* The ROM copy reads into the next asset. Hosted assets are separate
       objects, so copy only the results tiles that the screen uses. */
    CpuCopy16(src, dest, gResultsScreenGfxSize);
#else
    CpuCopy16(src, dest, size * 2);
#endif
    src = (const u8 *)gTextLayerTiles;
    dest = (u8 *)BG_SCREEN_ADDR(24);
    size = 0x80 << 5;
    CpuCopy16(src, dest, size * 2);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    DrawBackdropMetatileMap(gResultsScreenMetatileMapAndTable);
}

void LoadMenuBackdrop(void)
{
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(gUnk_082E4B04, VRAM, 0xA280);
    CpuCopy16(gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    DrawBackdropMetatileMap(gMenuBackdropMetatileMapAndTable);
}

void ShowBootSplash1(void)
{
    u8 palette[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(gBootSplash1Gfx, VRAM, 0xA280);
    CpuCopy16(gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    DrawMetatileMap(gBootSplash1MetatileMap, gBootSplash1MetatileTable);
    BuildScreenPalette(gBootSplash1Palette, (u16 *)palette);
    FadeToBrightenedPalette(palette, 0x0F);
    WaitFrames(180);
    FadeToColor(0, 0x0F);
}
