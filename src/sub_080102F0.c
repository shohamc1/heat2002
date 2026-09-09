#include "global.h"

extern u32 gUnk_082B370C[];
extern u32 gUnk_082B350C[];

void sub_08016E28(u32 a, u32 b);
void sub_08004238(u32 a, u32 b);
void sub_080102BC(u32 a);
void sub_0800420C(u32 a, u32 b);

void sub_080102F0(void)
{
    volatile u16 *r = (volatile u16 *)0x0400000C;
    *r = 0x81;
    r = (volatile u16 *)0x04000000;
    *r = 0x444;
    sub_08016E28((u32)gUnk_082B370C, 0xC0 << 19);
    sub_08004238((u32)gUnk_082B350C, 0xF);
    sub_080102BC(0x78);
    sub_0800420C(0, 0xF);
}
