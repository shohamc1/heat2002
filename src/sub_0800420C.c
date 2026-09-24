#include "global.h"

void BeginFadeToColor(u32 a, u32 b);
void WaitForVBlank(void);
void UpdatePaletteFade(void);

void FadeToColor(u32 r0, u32 r1)
{
    u32 r4;
    u32 r2 = (u16)r0;

    BeginFadeToColor(r1, r2);
    for (r4 = 0; r4 != r1; r4++)
    {
        WaitForVBlank();
        UpdatePaletteFade();
    }
}
