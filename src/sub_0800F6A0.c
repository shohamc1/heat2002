#include "global.h"
#include "gba/compat.h"
#include "functions.h"

extern const u8 gUnk_08313DF0[];
extern const u32 gUnk_0833338C[];
extern const u8 gUnk_0831397C[];
extern const u8 gUnk_08313AA8[];
extern const u8 gUnk_0831377C[];
void sub_0800F6A0(void)
{
    u8 buf[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16((u32)gUnk_08313DF0, VRAM, 0xA280);
    CpuCopy16((u32)gUnk_0833338C, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0x88 << 3;
    sub_080106CC((u16 *)((u32)gUnk_0831397C),(u16 *)((u32)gUnk_08313AA8));
    sub_0800F328((u32)gUnk_0831377C, (u16 *)buf);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    WaitFramesOrKey(0x96 << 2);
    FadeToColor(0, 0x0F);
}
