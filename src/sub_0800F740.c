#include "global.h"
#include "gba/compat.h"
extern void sub_08000458(void);
extern void sub_080106CC(u32 a, u32 b);
extern void sub_0800F328(u32 a, void *b);
extern void sub_08004238(void *a, u32 b);
extern void sub_080102BC(u32 a);
extern void sub_0800420C(u32 a, u32 b);
void sub_0800F740(void)
{
    u8 buf[0x200];
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    CpuCopy16(0x083171A4, VRAM, 0xA280);
    CpuCopy16(0x0833338C, BG_SCREEN_ADDR(24), 0x2000);
    sub_08000458();
    REG_DISPCNT = 0x88 << 3;
    sub_080106CC(0x08316D30, 0x08316E5C);
    sub_0800F328(0x08316B30, buf);
    sub_08004238(buf, 0x0F);
    sub_080102BC(0x96 << 2);
    sub_0800420C(0, 0x0F);
}
