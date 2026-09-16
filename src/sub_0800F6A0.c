#include "global.h"
#include "gba/io_reg.h"
extern void sub_08016E10(u32 src, u32 dest, u32 control);
extern void sub_08000458(void);
extern void sub_080106CC(u32 a, u32 b);
extern void sub_0800F328(u32 a, void *b);
extern void sub_08004238(void *a, u32 b);
extern void sub_080102BC(u32 a);
extern void sub_0800420C(u32 a, u32 b);
void sub_0800F6A0(void)
{
    u8 buf[0x200];
    REG_BG0CNT = 0x1C0D;
    REG_BG2CNT = 0x1F82;
    sub_08016E10(0x08313DF0, 0xC0 << 19, 0x5140);
    sub_08016E10(0x0833338C, 0x0600C000, 0x80 << 5);
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0x88 << 3;
    sub_080106CC(0x0831397C, 0x08313AA8);
    sub_0800F328(0x0831377C, buf);
    sub_08004238(buf, 0x0F);
    sub_080102BC(0x96 << 2);
    sub_0800420C(0, 0x0F);
}
