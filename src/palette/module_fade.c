#include "global.h"
#include "variables.h"


void ModuleFillFadePalette(u32 color)
{
    u32 shifted = color << 16;
    u32 mask = 0x1F;
    u32 redMask = 0x1F0000;
    u32 greenBits = (shifted >> 21) & mask;
    u32 blueBits = (shifted >> 26) & mask;
    u32 i = 0;
    u32 red = shifted & redMask;
    u32 *fadeColors = gModule_PaletteFadeColors;
    u32 green = greenBits << 16;
    u32 blue = blueBits << 16;
    do {
        fadeColors[0] = red;
        fadeColors[1] = green;
        fadeColors[2] = blue;
        fadeColors += 3;
        i++;
    } while (i != 0x100);
}
