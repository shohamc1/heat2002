#include "global.h"
#include "gba/compat.h"
extern u16 sub_08011C44(u32 r, u32 g, u32 b);

void sub_0800F328(u32 src, u16 *dst)
{
    CpuCopy16(src, (u32)dst, 0x200);
    CpuCopy16(0x08332BC8, (u32)&dst[0xF0], 0x20);
    CpuCopy16(0x08332BC8, (u32)&dst[0xE0], 0x20);
    dst[0xEA] = sub_08011C44(0x34, 0x34, 0x34);
    dst[0xEB] = sub_08011C44(0x24, 0x24, 0x24);
    dst[0xEC] = sub_08011C44(0x0E, 0x0E, 0x0E);
    dst[0xED] = sub_08011C44(0, 0, 0);
}
