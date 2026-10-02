#include "global.h"
#include "variables.h"
#include "functions.h"
#include "gba/compat.h"

#define GBA_CPUSET sub_08344B64

void ModulePackFadePalette(void);
extern u16 gModule_PaletteBuffer[];

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

void ModuleBeginFadeToColor(u32 steps, u32 color)
{
    u8 active;
    u32 shifted;
    u32 mask5;
    u32 mask5High;
    u32 red;
    u32 green;
    u32 blue;
    u32 i;
    u32 *colors;
    u32 *deltas;

    shifted = color << 16;
    mask5 = 0x1F;
    mask5High = 0x1F0000;
    green = (shifted >> 21) & mask5;
    blue = (shifted >> 26) & mask5;
    red = shifted & mask5High;
    green = green << 16;
    blue = blue << 16;
    i = 0;
    colors = gModule_PaletteFadeColors;
    deltas = gModule_PaletteFadeDeltas;
    do {
        deltas[0] = sub_08344BB8(red - colors[0], steps);
        deltas[1] = sub_08344BB8(green - colors[1], steps);
        deltas[2] = sub_08344BB8(blue - colors[2], steps);
        colors += 3;
        deltas += 3;
        i++;
    } while (i != 0x100);
    gModule_PaletteFadeSteps = steps;
    {
        register u32 active PIN(r0) = 1;
        gModule_PaletteFadeActive = active;
    }
}

void ModuleBeginFadeToBrightenedPalette(s32 steps, u16 *src)
{
    s32 *colors;
    s32 *deltas;
    s32 i;
    register s32 color PIN(r4);
    s32 red, green, blue;
    s32 scaled;

    i = 0;
    colors = (s32 *)gModule_PaletteFadeColors;
    deltas = (s32 *)gModule_PaletteFadeDeltas;
    do {
        red = *src++;
        color = red;
        red = red & 0x1F;
        green = (color >> 5) & 0x1F;
        blue = (color >> 10) & 0x1F;
        scaled = red * 3;
        red = scaled / 2;
        if (red > 31)
            red = 31;
        green = green * 3 / 2;
        if (green > 31)
            green = 31;
        blue = blue * 3 / 2;
        if (blue > 31)
            blue = 31;
        red <<= 16;
        green <<= 16;
        blue <<= 16;
        deltas[0] = sub_08344BB8(red - colors[0], steps);
        deltas[1] = sub_08344BB8(green - colors[1], steps);
        deltas[2] = sub_08344BB8(blue - colors[2], steps);
        colors += 3;
        deltas += 3;
        i++;
    } while (i != 256);

    gModule_PaletteFadeSteps = steps;
    {
        register u32 one PIN(r0) = 1;
        gModule_PaletteFadeActive = one;
    }
}

void ModuleSetFadeDeltasColors240To255(s32 steps)
{
    u32 white;
    s32 *deltas;
    s32 *colors;
    s32 *deltaBase;
    s32 *colorBase;
    s32 idx;
    u32 off;

    idx = 240;
    deltaBase = (s32 *)gModule_PaletteFadeDeltas;
    colorBase = (s32 *)gModule_PaletteFadeColors;
    off = 0xB40;
    colors = (s32 *)((u32)colorBase + off);
    deltas = (s32 *)((u32)deltaBase + off);
    do {
    loop:
        white = 0x1F0000;
        deltas[0] = sub_08344BB8(white - colors[0], steps);
        deltas[1] = sub_08344BB8(white - colors[1], steps);
        deltas[2] = sub_08344BB8(white - colors[2], steps);
        colors += 3;
        deltas += 3;
        idx++;
    } while (0);
    if (idx != 256) {
        if (1) {
            goto loop;
        }
    }
}

void ModuleUpdatePaletteFade(void)
{
    int steps;
    u32 i;
    u32 n;
    u32 *colors;
    u32 *deltas;

    steps = gModule_PaletteFadeSteps;
    if (steps == 0)
        gModule_PaletteFadeActive = steps;
    if (gModule_PaletteFadeActive != 0) {
        ModulePackFadePalette();
        i = 0;
        n = 0x300;
        colors = gModule_PaletteFadeColors;
        deltas = gModule_PaletteFadeDeltas;
        do {
            *colors++ += *deltas++;
            i++;
        } while (i != n);
        gModule_PaletteFadeSteps -= 1;
    }
    gModule_PaletteBufferDirty = 1;
}

void ModulePackFadePalette(void)
{
    u32 i;
    u16 *dst;
    s32 *src;
    s32 r;
    s32 g;
    s32 b;

    src = (s32 *)gModule_PaletteFadeColors;
    dst = gModule_PaletteBuffer;
    for (i = 0; i != 0x100; i++) {
        r = *src++;
        g = *src++;
        b = *src++;
        r >>= 16;
        g >>= 16;
        b >>= 16;
        r &= 0x1F;
        g &= 0x1F;
        b &= 0x1F;
        *dst++ = r | (g << 5) | (b << 10);
    }
}

void ModuleFlushPaletteBuffer(void)
{
    if (gModule_PaletteBufferDirty != 0) {
        CpuSet(gModule_PaletteBuffer, (void *)PLTT, 0x80 << 1);
        gModule_PaletteBufferDirty = 0;
    }
}

void ModuleFadeToColor(u32 color, u32 steps)
{
    u16 color16 = (u16)color;
    u32 i;

    ModuleBeginFadeToColor(steps, color16);
    for (i = 0; i != steps; i++) {
        ModuleWaitForVBlank();
        ModuleUpdatePaletteFade();
    }
}
