#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "gba/syscall.h"

extern u32 gUnk_0830EE78[];
extern u32 gBootSplash2Palette[];


void sub_08010334(void)
{
    u32 p;

    volatile u16 *r;

    WaitForVBlank();
    r = &REG_BG2CNT;
    *r = 0x81;
    r = &REG_DISPCNT;
    *r = 0x444;
    p = (u32)gUnk_0830EE78;
    RLUnCompVram(p, VRAM);
    FadeToBrightenedPalette((u32)gBootSplash2Palette, 0xF);
    WaitFramesOrKey(0x78);
    FadeToColor(0, 0xF);
}
