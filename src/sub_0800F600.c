#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "data.h"

extern const u8 gUnk_083107FC[];
extern const u8 gUnk_08310380[];
extern const u8 gUnk_083104AC[];
extern const u8 gUnk_08310180[];
void sub_0800F600(void)
{
    u8 buf[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16((u32)gUnk_083107FC, VRAM, 0xA280);
    CpuCopy16((u32)gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0x88 << 3;
    sub_080106CC((u16 *)((u32)gUnk_08310380),(u16 *)((u32)gUnk_083104AC));
    sub_0800F328((u32)gUnk_08310180, (u16 *)buf);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    WaitFramesOrKey(0x96 << 2);
    FadeToColor(0, 0x0F);
}
