#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "gba/syscall.h"

extern u32 gBootSplash3Gfx[];
extern u32 gBootSplash3Palette[];
extern u32 gBootSplash2Gfx[];
extern u32 gBootSplash2Palette[];

void ShowBootSplash3(void)
{
    u32 src;

    volatile u16 *reg = &REG_BG2CNT;
    *reg = 0x81;
    reg = &REG_DISPCNT;
    *reg = 0x444;
    src = (u32)gBootSplash3Gfx;
    RLUnCompVram(src, VRAM);
    FadeToBrightenedPalette(gBootSplash3Palette, 0xF);
    WaitFramesOrKey(0x78);
    FadeToColor(0, 0xF);
}

void ShowBootSplash2(void)
{
    u32 src;

    volatile u16 *reg;

    WaitForVBlank();
    reg = &REG_BG2CNT;
    *reg = 0x81;
    reg = &REG_DISPCNT;
    *reg = 0x444;
    src = (u32)gBootSplash2Gfx;
    RLUnCompVram(src, VRAM);
    FadeToBrightenedPalette(gBootSplash2Palette, 0xF);
    WaitFramesOrKey(0x78);
    FadeToColor(0, 0xF);
}
