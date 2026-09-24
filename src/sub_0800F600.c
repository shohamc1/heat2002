#include "global.h"
#include "gba/compat.h"
extern void WaitForVBlank(void);
extern void sub_080106CC(u32 a, u32 b);
extern void sub_0800F328(u32 a, void *b);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void WaitFramesOrKey(u32 a);
extern void FadeToColor(u32 a, u32 b);
void sub_0800F600(void)
{
    u8 buf[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(0x083107FC, VRAM, 0xA280);
    CpuCopy16(0x0833338C, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0x88 << 3;
    sub_080106CC(0x08310380, 0x083104AC);
    sub_0800F328(0x08310180, buf);
    FadeToBrightenedPalette(buf, 0x0F);
    WaitFramesOrKey(0x96 << 2);
    FadeToColor(0, 0x0F);
}
