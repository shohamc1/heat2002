#include "global.h"
#include "gba/compat.h"

extern u32 gUnk_082B370C[];
extern u32 gUnk_082B350C[];

void sub_08004238(u32 a, u32 b);
void sub_080102BC(u32 a);
void sub_0800420C(u32 a, u32 b);

void sub_080102F0(void)
{
    u32 p;

    volatile u16 *r = &REG_BG2CNT;
    *r = 0x81;
    r = &REG_DISPCNT;
    *r = 0x444;
    p = (u32)gUnk_082B370C;
    RLUnCompVram(p, VRAM);
    sub_08004238((u32)gUnk_082B350C, 0xF);
    sub_080102BC(0x78);
    sub_0800420C(0, 0xF);
}
