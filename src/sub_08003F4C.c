#include "global.h"
#include "variables.h"
void FillFadePalette(u16 color)
{
    s32 i;
    u32 r = color & 0x1F;
    u32 g = (color >> 5) & 0x1F;
    u32 b = (color >> 10) & 0x1F;
    for (i = 0; i != 0x100; i++) {
        gUnk_02022E20[i * 3] = r << 16;
        gUnk_02022E20[i * 3 + 1] = g << 16;
        gUnk_02022E20[i * 3 + 2] = b << 16;
    }
}
