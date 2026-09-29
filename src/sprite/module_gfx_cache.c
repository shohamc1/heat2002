#include "global.h"
#include "variables.h"

extern u8 gUnk_020269C4[];
extern u8 gUnk_020269CC[];
extern u8 gUnk_020269FC[];
extern u8 gUnk_02026A3C[];
extern u8 gUnk_02026A64[];
extern u8 gUnk_02026A84[];

void ModuleInitObjPaletteCacheEntry(struct ObjPaletteCacheEntry *entry)
{
    entry->palette = 0xFFFF;
    entry->age = 0;
    entry->pending = 0;
}

void ModuleInitObjTileCache(u32 count, u16 *tiles, struct ObjTileCacheEntry *entries)
{
    u32 i;

    for (i = 0; i != count; i++, entries++, tiles++) {
        entries->gfx = 0xFFFF;
        entries->age = 0;
        entries->pending = 0;
        entries->tileIndex = *tiles;
        entries->vramDest = (*tiles << 5) + 0x06010000;
        entries->unk06 = 0;
    }
}

void ModuleInitGfxCaches(void)
{
    u32 i;
    u32 color;
    struct ObjPaletteCacheEntry *entry;
    u16 *src;
    void *dest;

    src = gUnk_020269C4;
    dest = gModule_ObjTileCache64;
    ModuleInitObjTileCache(4, src, dest);
    src = gUnk_020269CC;
    dest = gModule_ObjTileCache16;
    ModuleInitObjTileCache(0x18, src, dest);
    src = gUnk_020269FC;
    dest = gModule_ObjTileCache2;
    ModuleInitObjTileCache(0x20, src, dest);
    src = gUnk_02026A3C;
    dest = gModule_ObjTileCache8;
    ModuleInitObjTileCache(0x14, src, dest);
    src = gUnk_02026A64;
    dest = gModule_ObjTileCache4;
    ModuleInitObjTileCache(0x10, src, dest);
    src = gUnk_02026A84;
    dest = gModule_ObjTileCache1;
    ModuleInitObjTileCache(0x20, src, dest);

    i = 0;
    color = 0x05000200;
    entry = gModule_ObjPaletteCache;
    do {
        ModuleInitObjPaletteCacheEntry(entry);
        entry->palDest = color;
        color += 0x20;
        entry++;
        i++;
    } while (i != 16);
}

void ModuleAgeGfxCaches(void)
{
    struct ObjTileCacheEntry *p;
    struct ObjTileCacheEntry *a2;
    struct ObjTileCacheEntry *a3;
    struct ObjTileCacheEntry *a4;
    struct ObjTileCacheEntry *a5;
    struct ObjTileCacheEntry *a6;
    struct ObjPaletteCacheEntry *q;
    struct ObjPaletteCacheEntry *pal;
    u32 i;

    p = gModule_ObjTileCache64;
    i = 0;
    a2 = gModule_ObjTileCache16;
    a3 = gModule_ObjTileCache2;
    a4 = gModule_ObjTileCache8;
    a5 = gModule_ObjTileCache4;
    a6 = gModule_ObjTileCache1;
    q = gModule_ObjPaletteCache;
    for (; i != 4; i++, p++) {
        if (p->age == 0)
            p->gfx = 0xFFFF;
        else
            p->age--;
    }
    p = a2;
    for (i = 0; i != 0x18; i++, p++) {
        if (p->age == 0)
            p->gfx = 0xFFFF;
        else
            p->age--;
    }
    p = a3;
    for (i = 0; i != 0x20; i++, p++) {
        if (p->age == 0)
            p->gfx = 0xFFFF;
        else
            p->age--;
    }
    p = a4;
    for (i = 0; i != 0x14; i++, p++) {
        if (p->age == 0)
            p->gfx = 0xFFFF;
        else
            p->age--;
    }
    p = a5;
    for (i = 0; i != 0x10; i++, p++) {
        if (p->age == 0)
            p->gfx = 0xFFFF;
        else
            p->age--;
    }
    p = a6;
    for (i = 0; i != 0x20; i++, p++) {
        if (p->age == 0)
            p->gfx = 0xFFFF;
        else
            p->age--;
    }
    pal = q;
    for (i = 0; i != 0x10; i++, pal++) {
        if (pal->age == 0)
            pal->palette = 0xFFFF;
        else
            pal->age--;
    }
}
