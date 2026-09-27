#include "global.h"
#include "variables.h"


void sub_0833D4A4(void);

void sub_0833D448(void)
{
    int v;
    u32 i;
    u32 n;
    u32 *d;
    u32 *s;

    v = *(s16 *)&gModule_PaletteFadeSteps;
    if (v == 0)
        gModule_PaletteFadeActive = v;
    if (gModule_PaletteFadeActive != 0)
    {
        sub_0833D4A4();
        i = 0;
        n = 0x300;
        d = gModule_PaletteFadeColors;
        s = gModule_PaletteFadeDeltas;
        do {
            *d++ += *s++;
            i++;
        } while (i != n);
        gModule_PaletteFadeSteps -= 1;
    }
    gUnk_020392C0 = 1;
}
