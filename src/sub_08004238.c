#include "global.h"
#include "functions.h"

void BeginFadeToBrightenedPalette(u32 a, u32 b);

void FadeToBrightenedPalette(u32 a, u32 b)
{
    u32 i;

    BeginFadeToBrightenedPalette(b, a);
    for (i = 0; i != b; i++)
    {
        WaitForVBlank();
        UpdatePaletteFade();
    }
}
