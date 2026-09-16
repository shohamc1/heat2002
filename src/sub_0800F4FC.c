#include "global.h"
#include "gba/io_reg.h"
extern void sub_08016E10(u32 src, u32 dest, u32 control);
extern void sub_08000458(void);
extern void sub_08010680(u32 a);
void sub_0800F4FC(void)
{
    REG_BG0CNT = 0x1C0D;
    REG_BG2CNT = 0x1F82;
    sub_08016E10(0x082E4B04, 0xC0 << 19, 0x5140);
    sub_08016E10(0x0833338C, 0x0600C000, 0x80 << 5);
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_08010680(0x082E4528);
}
