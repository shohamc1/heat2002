#include "global.h"
#include "gba/defines.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"

void PackFadePalette(void);
extern u8 gPaletteBufferDirty; /* 0x02022E10 */
extern u32 gPaletteBuffer[];   /* 0x02024620 */

/* This file owns the third palette-fade run (issue 5 step 3, run rule):
   gPaletteBuffer (0x02024620-0x02024820) is PackFadePalette's packed
   256-colour u16 staging buffer, which FlushPaletteBuffer CpuCopy16s to
   PLTT (0x200 bytes, one run, one variable, no pads). ldscript.ld's
   .bss_fade places ewram_data at 0x02024620; oam.c's run starts at the
   buffer's end. */
EWRAM_DATA u32 gPaletteBuffer[0x80] = { 0 }; /* 0x02024620, 0x200 bytes as u16 */

void UpdatePaletteFade(void)
{
    u32 v = *(s16 *)&gPaletteFadeSteps;
    u8 *p = &gFadeActive;
    if (v == 0)
        *p = v;
    if (*p != 0) {
        u32 i;
        u32 n;
        u32 *r3;
        u32 *r4;
        PackFadePalette();
        i = 0;
        n = 0x300;
        r3 = gPaletteFadeColors;
        r4 = (u32 *)gPaletteFadeDeltas;
        while (i != n) {
            *r3++ += *r4++;
            i++;
        }
        gPaletteFadeSteps = gPaletteFadeSteps - 1;
    }
    gPaletteBufferDirty = 1;
}

void PackFadePalette(void)
{
    s32 *r6 = (s32 *)gPaletteFadeColors;
    u16 *r5 = (u16 *)gPaletteBuffer;
    u32 r4 = 0;
    u32 m = 0x1F;
    u32 r7 = 0x80 << 1;

    while (r4 != r7) {
        s32 x = *r6++;
        s32 y = *r6++;
        s32 z = *r6++;
        x >>= 16;
        y >>= 16;
        z >>= 16;
        x &= m;
        y &= m;
        z &= m;
        *r5++ = RGB(x, y, z);
        r4++;
    }
}

void FlushPaletteBuffer(void)
{
    u32 *p;

    if (gPaletteBufferDirty != 0) {
        p = gPaletteBuffer;
        CpuCopy16(p, PLTT, PLTT_SIZE / 2);
        gPaletteBufferDirty = 0;
    }
}

void FadeToColor(u32 r0, u32 r1)
{
    u32 r4;
    u32 r2 = (u16)r0;

    BeginFadeToColor(r1, r2);
    for (r4 = 0; r4 != r1; r4++) {
        WaitForVBlank();
        UpdatePaletteFade();
    }
}

void FadeToBrightenedPalette(void *a, u32 b)
{
    u32 i;

    BeginFadeToBrightenedPalette(b, a);
    for (i = 0; i != b; i++) {
        WaitForVBlank();
        UpdatePaletteFade();
    }
}
