#include "global.h"
#include "gba/compat.h"
extern void sub_08000458(void);
extern void sub_08010680(u32 a);

void sub_0800F434(void)
{
    REG_BG0CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(0x082A9F0C, VRAM, 0xA280);
    CpuCopy16(0x0833338C, BG_SCREEN_ADDR(24), 0x2000);
    sub_08000458();
    REG_DISPCNT = 0xA8 << 3;
    sub_08010680(0x082A9930);
}
