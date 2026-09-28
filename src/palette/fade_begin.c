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

void BeginFadeToColor(s32 a, u32 b)
{
    u32 v = b << 16;
    register u32 m asm("r0") = 0x1F;
    register s32 r asm("r10") = 0x1F0000;
    u32 gp = m & (v >> 21);
    u32 bp = m & (v >> 26);
    register s32 g asm("r8");
    register u32 i asm("r9");
    u32 k;

    r &= v;
    g = gp << 16;
    bp <<= 16;
    i = 0;
    k = 0;
    do {
        gUnk_02023A20[k] = (r - (s32)gUnk_02022E20[k]) / a;
        gUnk_02023A20[k + 1] = (g - (s32)gUnk_02022E20[k + 1]) / a;
        gUnk_02023A20[k + 2] = ((s32)bp - (s32)gUnk_02022E20[k + 2]) / a;
        k += 3;
    } while (++i != 256);
    gUnk_02022E18 = a;
    gFadeActive = 1;
}

void BeginFadeToBrightenedPalette(s32 arg0, u16 *src)
{
    s32 *base;
    s32 *out;
    s32 i;
    register s32 v asm("r4");
    s32 x, y, z;
    s32 scaled;

    i = 0;
    base = (s32 *)gUnk_02022E20;
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
    gFadeActive = 1;
}
