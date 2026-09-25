#include "global.h"
#include "gba/compat.h"

extern const u8 gUnk_083107FC[];
extern const u32 gUnk_0833338C[];
extern const u8 gUnk_08310380[];
extern const u8 gUnk_083104AC[];
extern const u8 gUnk_08310180[];
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
    CpuCopy16((u32)gUnk_083107FC, VRAM, 0xA280);
    CpuCopy16((u32)gUnk_0833338C, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0x88 << 3;
    sub_080106CC((u32)gUnk_08310380, (u32)gUnk_083104AC);
    sub_0800F328((u32)gUnk_08310180, buf);
    FadeToBrightenedPalette(buf, 0x0F);
    WaitFramesOrKey(0x96 << 2);
    FadeToColor(0, 0x0F);
}
