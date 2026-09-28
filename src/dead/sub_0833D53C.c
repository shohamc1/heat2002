#include "global.h"
#include "functions.h"

void ModuleBeginFadeToBrightenedPalette(u32 a, u32 b);
void ModuleUpdatePaletteFade(void);

void sub_0833D53C(u32 a, u32 b)
{
    u32 i;

    ModuleBeginFadeToBrightenedPalette(b, a);
    for (i = 0; i != b; i++)
    {
        ModuleWaitForVBlank();
        ModuleUpdatePaletteFade();
    }
}
