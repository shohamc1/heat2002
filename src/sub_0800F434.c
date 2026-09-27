#include "global.h"
#include "gba/compat.h"
#include "functions.h"

extern const u8 gUnk_082A9F0C[];
extern const u32 gUnk_0833338C[];
extern const u8 gUnk_082A9930[];

void sub_0800F434(void)
{
    REG_BG0CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16((u32)gUnk_082A9F0C, VRAM, 0xA280);
    CpuCopy16((u32)gUnk_0833338C, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    sub_08010680((u16 *)((u32)gUnk_082A9930));
}
