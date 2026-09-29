#include "global.h"
#include "gba/defines.h"
#include "gba/compat.h"
#include "functions.h"

void PackFadePalette(void);
extern u8 gUnk_02022E10;    /* 0x02022E10 */
extern u32 gUnk_02024620[]; /* 0x02024620 */

void UpdatePaletteFade(void)
{
    u32 v = *(s16 *)(EWRAM_START + 0x22E18);
    u8 *p = (u8 *)(EWRAM_START + 0x22E14);
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
        r3 = (u32 *)(EWRAM_START + 0x22E20);
        r4 = (u32 *)(EWRAM_START + 0x23A20);
        while (i != n) {
            *r3++ += *r4++;
            i++;
        }
        *(u16 *)(EWRAM_START + 0x22E18) = *(u16 *)(EWRAM_START + 0x22E18) - 1;
    }
    *(u8 *)(EWRAM_START + 0x22E10) = 1;
}

void PackFadePalette(void)
{
    s32 *r6 = (s32 *)(EWRAM_START + 0x22E20);
    u16 *r5 = (u16 *)(EWRAM_START + 0x24620);
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
    u32 p;

    if (gUnk_02022E10 != 0) {
        p = (u32)gUnk_02024620;
        CpuCopy16(p, PLTT, PLTT_SIZE / 2);
        gUnk_02022E10 = 0;
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
