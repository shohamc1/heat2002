#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_0833D288(u32 a0, u32 a1)
{
    u8 one;
    u32 x;
    u32 m1;
    u32 m0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 i;
    u32 *g;
    u32 *h;

    x = a1 << 16;
    m1 = 0x1F;
    m0 = 0x1F0000;
    v1 = (x >> 21) & m1;
    v2 = (x >> 26) & m1;
    v0 = x & m0;
    v1 = v1 << 16;
    v2 = v2 << 16;
    i = 0;
    g = gModule_PaletteFadeColors;
    h = gModule_PaletteFadeDeltas;
    do
    {
        h[0] = sub_08344BB8(v0 - g[0], a0);
        h[1] = sub_08344BB8(v1 - g[1], a0);
        h[2] = sub_08344BB8(v2 - g[2], a0);
        g += 3;
        h += 3;
        i++;
    } while (i != 0x100);
    gModule_PaletteFadeSteps = a0;
    {
        register u32 one __asm__("r0") = 1;
        gModule_PaletteFadeActive = one;
    }
}
