#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"

extern const u8 gMainMenuPalette[];

void sub_08011C9C(u8 a, u16 *dst)
{
    DrawMainMenu(a);
    ZeroTextLayer();
    CpuCopy16((u32)gMainMenuPalette, dst, 0x200);
    CpuCopy16((u32)gFontPalette, &dst[0xF0], 0x20);
    CpuCopy16((u32)gFontPalette, &dst[0xE0], 0x20);
    dst[0xEA] = RgbFromPercent(0x34, 0x34, 0x34);
    dst[0xEB] = RgbFromPercent(0x24, 0x24, 0x24);
    dst[0xEC] = RgbFromPercent(0x0E, 0x0E, 0x0E);
    dst[0xED] = RgbFromPercent(0, 0, 0);
}
