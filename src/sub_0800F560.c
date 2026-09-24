#include "global.h"
#include "gba/compat.h"
extern void WaitForVBlank(void);
extern void sub_080106CC(u32 a, u32 b);
extern void sub_0800F328(u32 a, void *b);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void WaitFrames(u32 a);
extern void FadeToColor(u32 a, u32 b);
void sub_0800F560(void)
{
    u8 buf[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(0x0831A450, VRAM, 0xA280);
    CpuCopy16(0x0833338C, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    sub_080106CC(0x0831A0E4, 0x0831A210);
    sub_0800F328(0x08319EE4, buf);
    FadeToBrightenedPalette(buf, 0x0F);
    WaitFrames(0xB4);
    FadeToColor(0, 0x0F);
}
