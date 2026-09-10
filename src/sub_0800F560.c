#include "global.h"
extern void sub_08016E10(u32 src, u32 dest, u32 control);
extern void sub_08000458(void);
extern void sub_080106CC(u32 a, u32 b);
extern void sub_0800F328(u32 a, void *b);
extern void sub_08004238(void *a, u32 b);
extern void sub_080102A4(u32 a);
extern void sub_0800420C(u32 a, u32 b);
void sub_0800F560(void)
{
    u8 buf[0x200];
    *(volatile u16 *)0x04000008 = 0x1C0D;
    *(volatile u16 *)0x0400000C = 0x1F82;
    sub_08016E10(0x0831A450, 0xC0 << 19, 0x5140);
    sub_08016E10(0x0833338C, 0x0600C000, 0x80 << 5);
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_080106CC(0x0831A0E4, 0x0831A210);
    sub_0800F328(0x08319EE4, buf);
    sub_08004238(buf, 0x0F);
    sub_080102A4(0xB4);
    sub_0800420C(0, 0x0F);
}
