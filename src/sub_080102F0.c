#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "gba/syscall.h"

extern u32 gUnk_082B370C[];
extern u32 gBootSplash3Palette[];


void sub_080102F0(void)
{
    u32 p;

    volatile u16 *r = &REG_BG2CNT;
    *r = 0x81;
    r = &REG_DISPCNT;
    *r = 0x444;
    p = (u32)gUnk_082B370C;
    RLUnCompVram(p, VRAM);
    FadeToBrightenedPalette((u32)gBootSplash3Palette, 0xF);
    WaitFramesOrKey(0x78);
    FadeToColor(0, 0xF);
}
