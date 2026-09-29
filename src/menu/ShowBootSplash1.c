#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "data.h"

extern const u8 gBootSplash1Gfx[];
extern const u16 gBootSplash1MetatileMap[];
extern const u16 gBootSplash1MetatileTable[];
extern const u8 gBootSplash1Palette[];
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
