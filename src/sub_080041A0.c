#include "global.h"
#include "gba/defines.h"

void PackFadePalette(void)
{
    s32 *r6 = (s32 *)(EWRAM_START + 0x22E20);
    u16 *r5 = (u16 *)(EWRAM_START + 0x24620);
    u32 r4 = 0;
    u32 m = 0x1F;
    u32 r7 = 0x80 << 1;

    while (r4 != r7)
    {
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
