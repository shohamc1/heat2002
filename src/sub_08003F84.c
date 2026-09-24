#include "global.h"

extern s32 gUnk_02022E20[];
extern s32 gUnk_02023A20[];
extern u16 gUnk_02022E18;
extern u8 gUnk_02022E14;

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
        gUnk_02023A20[k] = (r - gUnk_02022E20[k]) / a;
        gUnk_02023A20[k + 1] = (g - gUnk_02022E20[k + 1]) / a;
        gUnk_02023A20[k + 2] = ((s32)bp - gUnk_02022E20[k + 2]) / a;
        k += 3;
    } while (++i != 256);
    gUnk_02022E18 = a;
    gUnk_02022E14 = 1;
}
