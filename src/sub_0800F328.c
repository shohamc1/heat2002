#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"

void sub_0800F328(u32 src, u16 *dst)
{
    CpuCopy16(src, (u32)dst, 0x200);
    CpuCopy16((u32)gFontPalette, (u32)&dst[0xF0], 0x20);
    CpuCopy16((u32)gFontPalette, (u32)&dst[0xE0], 0x20);
    dst[0xEA] = RgbFromPercent(0x34, 0x34, 0x34);
    dst[0xEB] = RgbFromPercent(0x24, 0x24, 0x24);
    dst[0xEC] = RgbFromPercent(0x0E, 0x0E, 0x0E);
    dst[0xED] = RgbFromPercent(0, 0, 0);
}
