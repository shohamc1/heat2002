#include "global.h"
#include "functions.h"
#include "variables.h"
#include "data.h"
#include "m4a.h"

#include "car.h"

extern u8 gText_HudPosLabel[];
extern u8 gText_BlankRow16_2[];
extern u8 gText_Lap[];
extern u8 gTireWearBlinkCounter;

extern u8 gSpeedNeedleGfx[];
extern u8 gUnk_02025250;
extern u8 gText_PitStopNeeded[];
extern u8 gText_BlankRow20[];
extern u8 gUnk_02025228;
extern u8 gLowFuelWarningGfx[];

void DrawSpeedNeedle(u32 speed)
{
    u16 pos[2];
    struct ObjTileCacheEntry *entry;
    u32 attr;
    u32 tileAttr;

    pos[0] = 200;
    pos[1] = 120;
    entry = RequestObjTiles16((GfxSrc)gSpeedNeedleGfx);
    if (entry != 0) {
        attr = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80000000;
        tileAttr = entry->tileIndex | ((u8)RequestObjPalette(gHudWarningIconPalette) << 12);
        attr |= 0x100;
        AddOamEntry(attr, tileAttr);
    }
    gUnk_0202522C = (speed + 0xA0) & 0xFF;
}

void DrawPitStopWarning(struct Car *car)
{
    const u8 *text;

    if (CarNeedsPit(car) != 0 && (gUnk_02025250 & 8) != 0) {
        text = gText_PitStopNeeded;
        DrawTextCentered(text, 6, 1);
    } else {
        text = gText_BlankRow20;
        DrawTextCentered(text, 6, 1);
    }
    gUnk_02025250 = gUnk_02025250 + 1;
}

void DummyHudHook(struct Car *unused)
{}

void DrawLowFuelWarning(s32 fuel)
{
    u16 pos[2];
    struct ObjTileCacheEntry *entry;
    u32 attr;
    u32 tileAttr;
    u16 *dest;
    u32 glyphOff;

    if (gDamagePitsEnabled == 0)
        return;
    gUnk_02025228++;
    pos[0] = 170;
    pos[1] = 137;
    entry = RequestObjTiles4((GfxSrc)gLowFuelWarningGfx);
    if (entry != 0) {
        attr = pos[1] & 0xFF;
        attr |= (pos[0] & 0x1FF) << 16;
        attr |= 0x40000000;
        tileAttr = entry->tileIndex | ((u32)RequestObjPalette(gHudWarningIconPalette) << 24) >> 12;
        AddOamEntry(attr | 0x02000100, tileAttr);
    }
    gUnk_02025398 = ((fuel >> 16) + 0xBE) & 0xFF;
    dest = (u16 *)(gTextLayerMapPtr[0] + 0x4EE);
    if (fuel <= 0x31FF && (gFrameCounter & 0x10) != 0) {
        glyphOff = 0x5B2;
        *dest = 0xE000 | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)];
        if (gOptions[3] != 0) {
            if (gIsDemo == 0)
                m4aSongNumStart(27);
        }
    } else {
        glyphOff = 0x5B4;
        *dest = 0xE000 | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)];
    }
}

void DrawRacePosition(s32 arg)
{
    u16 *q;
    u16 *p;
    if (gGameMode == 10 || gGameMode == 2)
        return;
    if (arg == 100 || gGameMode == 5) {
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
    DrawTextAt(gText_HudPosLabel, 22, 0);
    if (arg <= 9) {
        register u16 *w PIN(r0);
        p = (u16 *)gTextLayerMapPtr[0];
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        w = p + 0x3C;
        *w++ = 0xE047;
        *w = 0xE047;
        w -= 0x23;
        DrawBigDigit(w, (u8)arg);
    } else if (arg <= 19) {
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
        DrawTextAt(q, 0, 1);
        DrawTextAt(q, 0, 0);
        return;
    }
    if (a > b)
        a = b;
    DrawTextAt(gText_Lap, 0, 1);
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
