#include "global.h"
#include "gba/compat.h"

extern u32 gUnk_0830EE78[];
extern u32 gUnk_0830EC78[];

void WaitForVBlank(void);
void FadeToBrightenedPalette(u32 a, u32 b);
void WaitFramesOrKey(u32 a);
void FadeToColor(u32 a, u32 b);

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
    FadeToBrightenedPalette((u32)gUnk_0830EC78, 0xF);
    WaitFramesOrKey(0x78);
    FadeToColor(0, 0xF);
}
