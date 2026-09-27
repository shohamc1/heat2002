#include "global.h"
#include "data.h"
#include "variables.h"

struct Car {
    u8 pad00[0x8C];
    s32 tireWear0;
    s32 tireWear1;
    s32 tireWear2;
    s32 tireWear3;
};

extern u8 gTireWearBlinkCounter;

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
