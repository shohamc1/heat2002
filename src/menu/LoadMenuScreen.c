#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"

extern const u8 gMainMenuPalette[];

void LoadMenuScreen(u8 selected, u16 *palette)
{
    DrawMainMenu(selected);
    ZeroTextLayer();
    CpuCopy16(gMainMenuPalette, palette, 0x200);
    CpuCopy16(gFontPalette, &palette[0xF0], 0x20);
    CpuCopy16(gFontPalette, &palette[0xE0], 0x20);
    palette[0xEA] = RgbFromPercent(0x34, 0x34, 0x34);
    palette[0xEB] = RgbFromPercent(0x24, 0x24, 0x24);
    palette[0xEC] = RgbFromPercent(0x0E, 0x0E, 0x0E);
    palette[0xED] = RgbFromPercent(0, 0, 0);
}
