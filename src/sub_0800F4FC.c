#include "global.h"
#include "gba/compat.h"

extern const u8 gUnk_082E4B04[];
extern const u32 gUnk_0833338C[];
extern const u8 gUnk_082E4528[];
extern void WaitForVBlank(void);
extern void sub_08010680(u32 a);
void sub_0800F4FC(void)
{
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16((u32)gUnk_082E4B04, VRAM, 0xA280);
    CpuCopy16((u32)gUnk_0833338C, BG_SCREEN_ADDR(24), 0x2000);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    sub_08010680((u32)gUnk_082E4528);
}
