#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "data.h"

extern u32 gUnk_082EE8E0[];
extern u32 gUnk_082EE304[];

void sub_0800F498(void)
{
    u32 src;
    u32 dest;
    u32 ctrl;

    REG_BG0CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    src = gUnk_082EE8E0;
    dest = VRAM;
    ctrl = 0x5140;
    CpuCopy16(src, dest, ctrl * 2);
    src = (u32)gUnk_0833338C;
    dest = BG_SCREEN_ADDR(24);
    ctrl = 0x80 << 5;
    CpuCopy16(src, dest, ctrl * 2);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    sub_08010680((u16 *)gUnk_082EE304);
}
