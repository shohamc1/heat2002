#include "global.h"
extern void sub_08016E10(u32 src, u32 dest, u32 control);
extern u16 sub_08011C44(u32 r, u32 g, u32 b);

void sub_0800F328(u32 src, u16 *dst)
{
    sub_08016E10(src, (u32)dst, 0x80 << 1);
    sub_08016E10(0x08332BC8, (u32)&dst[0xF0], 0x10);
    sub_08016E10(0x08332BC8, (u32)&dst[0xE0], 0x10);
    dst[0xEA] = sub_08011C44(0x34, 0x34, 0x34);
    dst[0xEB] = sub_08011C44(0x24, 0x24, 0x24);
    dst[0xEC] = sub_08011C44(0x0E, 0x0E, 0x0E);
    dst[0xED] = sub_08011C44(0, 0, 0);
}
