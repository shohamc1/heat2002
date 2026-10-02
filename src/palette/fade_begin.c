#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "functions.h"

/* This file owns the palette-fade runs (issue 5 step 3, run rule):
   gPaletteFadeColors (0x02022E20-0x02023A20) is the 256-colour fade state,
   one u32 per 5-bit channel with the value in the high half, and
   gPaletteFadeDeltas (0x02023A20-0x02024620) the matching per-channel delta
   each BeginFade* routine divides into it (256 colours x 3 channels x 4
   bytes = 0xC00 each). One contiguous span, one owner, one section: the
   first buffer ends exactly where the second begins, so .bss_fade_begin
   places the single ewram_data at 0x02022E20 and neither run pads. */
EWRAM_DATA u32 gPaletteFadeColors[0x300] = { 0 }; /* 0x02022E20 */
EWRAM_DATA s32 gPaletteFadeDeltas[0x300] = { 0 }; /* 0x02023A20 */

void FillFadePalette(u16 color)
{
    s32 i;
    u32 r = color & 0x1F;
    u32 g = (color >> 5) & 0x1F;
    u32 b = (color >> 10) & 0x1F;
    for (i = 0; i != 0x100; i++) {
        gPaletteFadeColors[i * 3] = r << 16;
        gPaletteFadeColors[i * 3 + 1] = g << 16;
        gPaletteFadeColors[i * 3 + 2] = b << 16;
    }
}

void BeginFadeToColor(s32 a, u32 b)
{
    u32 v = b << 16;
    register u32 m PIN(r0) = 0x1F;
    register s32 r PIN(r10) = 0x1F0000;
    u32 gp = m & (v >> 21);
    u32 bp = m & (v >> 26);
    register s32 g PIN(r8);
    register u32 i PIN(r9);
    u32 k;

    r &= v;
    g = gp << 16;
    bp <<= 16;
    i = 0;
    k = 0;
    do {
        gPaletteFadeDeltas[k] = (r - (s32)gPaletteFadeColors[k]) / a;
        gPaletteFadeDeltas[k + 1] = (g - (s32)gPaletteFadeColors[k + 1]) / a;
        gPaletteFadeDeltas[k + 2] = ((s32)bp - (s32)gPaletteFadeColors[k + 2]) / a;
        k += 3;
    } while (++i != 256);
    gPaletteFadeSteps = a;
    gFadeActive = 1;
}

void BeginFadeToBrightenedPalette(s32 arg0, u16 *src)
{
    s32 *base;
    s32 *out;
    s32 i;
    register s32 v PIN(r4);
    s32 x, y, z;
    s32 scaled;

    i = 0;
    base = (s32 *)gPaletteFadeColors;
    out = gPaletteFadeDeltas;
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

    gPaletteFadeSteps = arg0;
    gFadeActive = 1;
}

void SetFadeDeltasColors240To255(u32 frames)
{
    register u32 *colorBase PIN(r1);
    register u32 *deltaBase PIN(r2);
    register u32 *colorPtr PIN(r6);
    register u32 colorIdx PIN(r8);
    u32 *deltaPtr;
    u32 target;

    colorIdx = 0xF0;
    deltaBase = (u32 *)gPaletteFadeDeltas;
    colorBase = gPaletteFadeColors;
    colorPtr = colorBase + 0x2D0;
    deltaPtr = deltaBase + 0x2D0;
loop:
    target = 0xF8 << 0xD;
    deltaPtr[0] = sub_08017230(target - colorPtr[0], frames);
    deltaPtr[1] = sub_08017230(target - colorPtr[1], frames);
    deltaPtr[2] = sub_08017230(target - colorPtr[2], frames);
    colorPtr += 3;
    deltaPtr += 3;
    colorIdx++;
    if (colorIdx != 0x100)
        goto loop;
}
