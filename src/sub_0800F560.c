#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "data.h"

extern const u8 gBootSplash1Gfx[];
extern const u16 gBootSplash1MetatileMap[];
extern const u16 gBootSplash1MetatileTable[];
extern const u8 gBootSplash1Palette[];
void sub_0800F560(void)
{
    u8 buf[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16((u32)gBootSplash1Gfx, VRAM, 0xA280);
    CpuCopy16((u32)gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    sub_080106CC((u16 *)((u32)gBootSplash1MetatileMap),(u16 *)((u32)gBootSplash1MetatileTable));
    sub_0800F328((u32)gBootSplash1Palette, (u16 *)buf);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    WaitFrames(0xB4);
    FadeToColor(0, 0x0F);
}
