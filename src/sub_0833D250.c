#include "global.h"
#include "variables.h"


void sub_0833D250(u32 a1)
{
    u32 x = a1 << 16;
    u32 m = 0x1F;
    u32 f0c = 0x1F0000;
    u32 f1 = (x >> 21) & m;
    u32 f2 = (x >> 26) & m;
    u32 i = 0;
    u32 f0 = x & f0c;
    u32 *p = gModule_PaletteFadeColors;
    u32 s1 = f1 << 16;
    u32 s2 = f2 << 16;
    do {
        p[0] = f0;
        p[1] = s1;
        p[2] = s2;
        p += 3;
        i++;
    } while (i != 0x100);
}
