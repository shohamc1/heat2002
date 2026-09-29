#include "global.h"
#include "variables.h"

struct Unk0833E528Ent
{
    u32 field_00;
    u8 field_04;
    u8 field_05[3];
    void *field_08;
    u8 field_0C[4];
    u32 field_10;
};
extern u32 gUnk_02024EE8[];
struct Unk0833E528Ent *ModuleRequestObjTiles16(void *a, u16 *b);
u32 ModuleRequestObjPalette(u32 a);
void ModuleAddOamEntry(u32 a, u32 b);
extern u8 gModule_PitStopNeeded[];
extern u8 gModule_BlankRow20[];
extern u8 gUnk_0203B6F8;
u8 ModuleCarNeedsPit(void);
void ModuleDrawTextCenteredHighlight(const u8 *a, u32 b, u32 c);
extern u8 gUnk_0203B6D8;
extern u8 gUnk_02024F70[];
u32 ModuleRequestObjTiles4(u32 r0);
u32 ModuleRequestObjPalette(u32 r0);
void ModuleAddOamEntry(u32 r0, u32 r1);
void ModuleM4aSongNumStart(u32 r0);
#include "functions.h"
extern u8 gModule_Pos[];
extern u8 gModule_BlankRow16[];
extern u8 gModule_Lap[];
struct Car
{
    u8 pad00[0x8C];
    s32 tireWear0;
    s32 tireWear1;
    s32 tireWear2;
    s32 tireWear3;
};
extern u8 gUnk_0203B6A4;

void ModuleDrawSpeedNeedle(u32 speed)
{
    u16 pos[2];
    struct Unk0833E528Ent *entry;
    u32 attr;
    u32 tileAttr;

    pos[0] = 0xC8;
    pos[1] = 0x78;
    entry = ModuleRequestObjTiles16(gUnk_02024EE8, pos);
    if (entry != 0) {
        attr = pos[1] & 0xFF;
        attr |= (pos[0] & 0x1FF) << 16;
        attr |= 0x80000000;
        tileAttr = entry->field_10 | ((ModuleRequestObjPalette((u32 *)gUnk_02024F50) << 24) >> 12);
        attr |= 0x100;
        ModuleAddOamEntry(attr, tileAttr);
    }
    gUnk_0203B6DC = (speed + 0xA0) & 0xFF;
}

void ModuleDrawPitStopWarning(void)
{
    u32 text;

    if (ModuleCarNeedsPit() != 0 && (gUnk_0203B6F8 & 8) != 0) {
        text = (u32)gModule_PitStopNeeded;
        ModuleDrawTextCenteredHighlight((u8 *)text, 6, 1);
    } else {
        text = (u32)gModule_BlankRow20;
        ModuleDrawTextCenteredHighlight((u8 *)text, 6, 1);
    }
    gUnk_0203B6F8 = gUnk_0203B6F8 + 1;
}

void ModuleDummyHudHook(void)
{}

void ModuleDrawLowFuelWarning(s32 fuel)
{
    u16 pos[2];
    u32 entry;
    u32 attr;
    u32 tileAttr;
    u16 *dest;
    u32 glyphOff;

    if (gModule_DamagePitsEnabled == 0)
        return;
    gUnk_0203B6D8++;
    pos[0] = 0xAA;
    pos[1] = 0x89;
    entry = ModuleRequestObjTiles4((u32)gUnk_02024F70);
    if (entry != 0) {
        attr = pos[1] & 0xFF;
        attr |= (pos[0] & 0x1FF) << 16;
        attr |= 0x40000000;
        tileAttr = *(u32 *)(entry + 0x10) | (((u32)ModuleRequestObjPalette((u32)gUnk_02024F50) << 24) >> 12);
        ModuleAddOamEntry(attr | 0x02000100, tileAttr);
    }
    gUnk_0203B828 = ((fuel >> 16) + 0xBE) & 0xFF;
    dest = (u16 *)(gModule_TextLayerMapPtr[0] + 0x4EE);
    if (fuel <= 0x31FF && ((*(u32 *)&gModule_FrameCounter) & 0x10) != 0) {
        glyphOff = 0x5B2;
        *dest = 0xE000 | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[glyphOff]];
        if (gModule_Options[3] != 0) {
            if (gModule_IsDemo[0] == 0)
                ModuleM4aSongNumStart(0x1B);
        }
    } else {
        glyphOff = 0x5B4;
        *dest = 0xE000 | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[glyphOff]];
    }
}

void ModuleDrawRacePosition(s32 position)
{
    u16 *q;
    u16 *p;
    if (gModule_GameMode[0] == 0x0A || gModule_GameMode[0] == 0x02)
        return;
    if (position == 0x64 || gModule_GameMode[0] == 5) {
        p = (u16 *)gModule_TextLayerMapPtr[0];
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
    ModuleDrawText(gModule_Pos, 0x16, 0);
    if (position <= 9) {
        register u16 *w asm("r0");
        p = (u16 *)gModule_TextLayerMapPtr[0];
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        w = p + 0x3C;
        *w++ = 0xE047;
        *w = 0xE047;
        w -= 0x23;
        ModuleDrawBigDigit((u16 *)((u32)w), (u8)position);
    } else if (position <= 0x13) {
        ModuleDrawBigDigit((u16 *)(gModule_TextLayerMapPtr[0] + 0x34), 1);
        ModuleDrawBigDigit((u16 *)(gModule_TextLayerMapPtr[0] + 0x38), (u8)(position - 0x0A));
    } else {
        ModuleDrawBigDigit((u16 *)(gModule_TextLayerMapPtr[0] + 0x34), 2);
        ModuleDrawBigDigit((u16 *)(gModule_TextLayerMapPtr[0] + 0x38), (u8)(position - 0x14));
    }
}

void ModuleDrawLapCounter(s32 lap, s32 totalLaps)
{
    u8 *q;
    u8 *base;
    u8 *p;

    if (lap == 999) {
        q = gModule_BlankRow16;
        ModuleDrawText(q, 0, 1);
        ModuleDrawText(q, 0, 0);
        return;
    }
    if (lap > totalLaps)
        lap = totalLaps;
    ModuleDrawText(gModule_Lap, 0, 1);
    base = (u8 *)gModule_TextLayerMapPtr[0];
    p = base + 8;
    if (lap > 99) {
        ModuleDrawBigDigit((u16 *)p, sub_08344BB8(lap, 100));
        p += 4;
        ModuleDrawBigDigit((u16 *)p, sub_08344C50(sub_08344BB8(lap, 10), 10));
        p += 4;
        ModuleDrawBigDigit((u16 *)p, sub_08344C50(lap, 10));
        p += 4;
    } else if (lap > 9) {
        ModuleDrawBigDigit((u16 *)p, sub_08344C50(sub_08344BB8(lap, 10), 10));
        p = base + 12;
        ModuleDrawBigDigit((u16 *)p, sub_08344C50(lap, 10));
        p += 4;
    } else {
        ModuleDrawBigDigit((u16 *)p, sub_08344C50(lap, 10));
        p = base + 12;
    }
    p += 0x40;
    ModuleDrawSmallDigit((u16 *)p, 11);
    p += 2;
    if (totalLaps > 99) {
        ModuleDrawSmallDigit((u16 *)p, (u8)sub_08344BB8(totalLaps, 100));
        p += 2;
        ModuleDrawSmallDigit((u16 *)p, (u8)sub_08344C50(sub_08344BB8(totalLaps, 10), 10));
        p += 2;
        ModuleDrawSmallDigit((u16 *)p, (u8)sub_08344C50(totalLaps, 10));
    } else if (totalLaps > 9) {
        ModuleDrawSmallDigit((u16 *)p, (u8)sub_08344C50(sub_08344BB8(totalLaps, 10), 10));
        p += 2;
        ModuleDrawSmallDigit((u16 *)p, (u8)sub_08344C50(totalLaps, 10));
    } else {
        ModuleDrawSmallDigit((u16 *)p, (u8)sub_08344C50(totalLaps, 10));
    }
}

void ModuleDrawTireWear(struct Car *p)
{
    u16 *dest;
    u32 off;

    if (gModule_DamagePitsEnabled == 0)
        return;
    dest = (u16 *)(gModule_TextLayerMapPtr[0] + 0x4A4);
    if (p->tireWear0 <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x6C2;
        *dest = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x6BE;
        *dest = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    }
    if (p->tireWear1 <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x6C4;
        dest[1] = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x6C0;
        dest[1] = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    }
    if (p->tireWear2 <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x74A;
        dest[0x20] = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x746;
        dest[0x20] = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    }
    if (p->tireWear3 <= 0x7CFFF || (gUnk_0203B6A4 & 8) != 0) {
        off = 0x74C;
        dest[0x21] = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    } else {
        off = 0x748;
        dest[0x21] = (0xE0 << 8) | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    }
    gUnk_0203B6A4++;
}
