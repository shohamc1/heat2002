#include "global.h"
#include "functions.h"
#include "variables.h"
#include "data.h"
extern u8 gText_HudPosLabel[];
extern u8 gText_BlankRow16_2[];
extern u8 gText_Lap[];
struct Car {
    u8 pad00[0x8C];
    s32 tireWear0;
    s32 tireWear1;
    s32 tireWear2;
    s32 tireWear3;
};
extern u8 gTireWearBlinkCounter;

void DrawRacePosition(s32 arg)
{
    u16 *q;
    u16 *p;
    if (gGameMode[0] == 0x0A || gGameMode[0] == 0x02)
        return;
    if (arg == 0x64 || gGameMode[0] == 5) {
        p = (u16 *)gTextLayerMapPtr[0];
        p[0x16] = 0xE047;
        p[0x17] = 0xE047;
        p[0x18] = 0xE047;
        p[0x19] = 0xE047;
        p[0x1A] = 0xE047;
        p[0x1B] = 0xE047;
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        q = p + 0x36;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q = 0xE047;
        return;
    }
    sub_0800649C((u8 *)((u32)gText_HudPosLabel), 0x16, 0);
    if (arg <= 9) {
        register u16 *w asm("r0");
        p = (u16 *)gTextLayerMapPtr[0];
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        w = p + 0x3C;
        *w++ = 0xE047;
        *w = 0xE047;
        w -= 0x23;
        DrawBigDigit((u16 *)((u32)w), (u8)arg);
    } else if (arg <= 0x13) {
        DrawBigDigit((u16 *)(gTextLayerMapPtr[0] + 0x34), 1);
        DrawBigDigit((u16 *)(gTextLayerMapPtr[0] + 0x38), (u8)(arg - 0x0A));
    } else {
        DrawBigDigit((u16 *)(gTextLayerMapPtr[0] + 0x34), 2);
        DrawBigDigit((u16 *)(gTextLayerMapPtr[0] + 0x38), (u8)(arg - 0x14));
    }
}

void DrawLapCounter(s32 a, s32 b)
{
    u8 *q;
    u8 *base;
    u8 *p;

    if (a == 999) {
        q = gText_BlankRow16_2;
        sub_0800649C((u8 *)((u32)q), 0, 1);
        sub_0800649C((u8 *)((u32)q), 0, 0);
        return;
    }
    if (a > b)
        a = b;
    sub_0800649C((u8 *)((u32)gText_Lap), 0, 1);
    base = (u8 *)gTextLayerMapPtr[0];
    p = base + 8;
    if (a > 99) {
        DrawBigDigit((u16 *)p, sub_08017230(a, 100));
        p += 4;
        DrawBigDigit((u16 *)p, sub_080172C8(sub_08017230(a, 10), 10));
        p += 4;
        DrawBigDigit((u16 *)p, sub_080172C8(a, 10));
        p += 4;
    } else if (a > 9) {
        DrawBigDigit((u16 *)p, sub_080172C8(sub_08017230(a, 10), 10));
        p = base + 12;
        DrawBigDigit((u16 *)p, sub_080172C8(a, 10));
        p += 4;
    } else {
        DrawBigDigit((u16 *)p, sub_080172C8(a, 10));
        p = base + 12;
    }
    p += 0x40;
    DrawSmallDigit((u16 *)p, 11);
    p += 2;
    if (b > 99) {
        DrawSmallDigit((u16 *)p, sub_08017230(b, 100));
        p += 2;
        DrawSmallDigit((u16 *)p, sub_080172C8(sub_08017230(b, 10), 10));
        p += 2;
        DrawSmallDigit((u16 *)p, sub_080172C8(b, 10));
    } else if (b > 9) {
        DrawSmallDigit((u16 *)p, sub_080172C8(sub_08017230(b, 10), 10));
        p += 2;
        DrawSmallDigit((u16 *)p, sub_080172C8(b, 10));
    } else {
        DrawSmallDigit((u16 *)p, sub_080172C8(b, 10));
    }
}

void DrawTireWear(struct Car *p)
{
    u16 *dest;
    u32 off;

    if (gDamagePitsEnabled == 0)
        return;
    dest = (u16 *)(gTextLayerMapPtr[0] + 0x4A4);
    if (p->tireWear0 <= 0x7CFFF || (gTireWearBlinkCounter & 8) != 0) {
        off = 0x6C2;
        *dest = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    } else {
        off = 0x6BE;
        *dest = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    }
    if (p->tireWear1 <= 0x7CFFF || (gTireWearBlinkCounter & 8) != 0) {
        off = 0x6C4;
        dest[1] = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    } else {
        off = 0x6C0;
        dest[1] = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    }
    if (p->tireWear2 <= 0x7CFFF || (gTireWearBlinkCounter & 8) != 0) {
        off = 0x74A;
        dest[0x20] = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    } else {
        off = 0x746;
        dest[0x20] = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    }
    if (p->tireWear3 <= 0x7CFFF || (gTireWearBlinkCounter & 8) != 0) {
        off = 0x74C;
        dest[0x21] = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    } else {
        off = 0x748;
        dest[0x21] = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)];
    }
    gTireWearBlinkCounter++;
}
