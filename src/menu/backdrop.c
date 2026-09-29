#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "data.h"

extern const u8 gUnk_082A9F0C[];
extern const u16 gMainMenuMetatileMapAndTable[];
extern u32 gUnk_082EE8E0[];
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
    CpuCopy16((u32)gUnk_082A9F0C, VRAM, 0xA280);
    CpuCopy16((u32)gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    DrawBackdropMetatileMap(gMainMenuMetatileMapAndTable);
}

void LoadResultsScreenBackdrop(void)
{
    u32 src;
    u32 dest;
    u32 size;

    REG_BG0CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    src = gUnk_082EE8E0;
    dest = VRAM;
    size = 0x5140;
    CpuCopy16(src, dest, size * 2);
    src = (u32)gTextLayerTiles;
    dest = BG_SCREEN_ADDR(24);
    size = 0x80 << 5;
    CpuCopy16(src, dest, size * 2);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    DrawBackdropMetatileMap(gResultsScreenMetatileMapAndTable);
}

void LoadMenuBackdrop(void)
{
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16((u32)gUnk_082E4B04, VRAM, 0xA280);
    CpuCopy16((u32)gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    DrawBackdropMetatileMap(gMenuBackdropMetatileMapAndTable);
}

void ShowBootSplash1(void)
{
    u8 palette[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16((u32)gBootSplash1Gfx, VRAM, 0xA280);
    CpuCopy16((u32)gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    DrawMetatileMap(gBootSplash1MetatileMap, gBootSplash1MetatileTable);
    BuildScreenPalette(gBootSplash1Palette, (u16 *)palette);
    FadeToBrightenedPalette(palette, 0x0F);
    WaitFrames(0xB4);
    FadeToColor(0, 0x0F);
}
