#include "global.h"

extern s32 gUnk_02022E20[];
extern s32 gUnk_02023A20[];
extern u16 gUnk_02022E18;
extern u8 gUnk_02022E14;

void BeginFadeToBrightenedPalette(s32 arg0, u16 *src)
{
    s32 *base;
    s32 *out;
    s32 i;
    register s32 v asm("r4");
    s32 x, y, z;
    s32 scaled;

    i = 0;
    base = gUnk_02022E20;
    out = gUnk_02023A20;
    do {
        x = *src++;
        v = x;
        x = x & 0x1F;
        y = (v >> 5) & 0x1F;
        z = (v >> 10) & 0x1F;
        scaled = x * 3;
        x = scaled / 2;
        if (x > 31)
            x = 31;
        y = y * 3 / 2;
        if (y > 31)
            y = 31;
        z = z * 3 / 2;
        if (z > 31)
            z = 31;
        x <<= 16;
        y <<= 16;
        z <<= 16;
        out[0] = (x - base[0]) / arg0;
        out[1] = (y - base[1]) / arg0;
        out[2] = (z - base[2]) / arg0;
        base += 3;
        out += 3;
        i++;
    } while (i != 256);

    gUnk_02022E18 = arg0;
    gUnk_02022E14 = 1;
}
