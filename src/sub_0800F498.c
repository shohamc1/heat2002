#include "global.h"
extern u32 gUnk_082EE8E0[];
extern u32 gUnk_0833338C[];
extern u32 gUnk_082EE304[];
void sub_08016E10(u32 src, u32 dest, u32 control);
void sub_08000458(void);
void sub_08010680(u32 a);

void sub_0800F498(void)
{
    u32 src;
    u32 dest;
    u32 ctrl;

    *(volatile u16 *)0x04000008 = 0x1C0E;
    *(volatile u16 *)0x0400000C = 0x1F82;
    src = gUnk_082EE8E0;
    dest = 0xC0 << 19;
    ctrl = 0x5140;
    sub_08016E10(src, dest, ctrl);
    src = gUnk_0833338C;
    dest = 0x0600C000;
    ctrl = 0x80 << 5;
    sub_08016E10(src, dest, ctrl);
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_08010680(gUnk_082EE304);
}
