#include "global.h"
#include "variables.h"

struct ObjTileCacheEntry
{
    u32 age;
    u8 pending;
    u8 unk05;
    u8 unk06;
    u8 unk07;
    u32 gfx;
    u32 vramDest;
    u32 tileIndex; /* OAM attr2 base: tile number, OR'd with palette/priority at each use */
};
struct ObjPaletteCacheEntry
{
    u8 age;
    u8 pending;
    u8 pad02;
    u32 palette;
    u32 palDest;
};
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
    entry = (struct ObjPaletteCacheEntry *)gUnk_0203C270;
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
    u32 *p;
    u32 *a2;
    u32 *a3;
    u32 *a4;
    u32 *a5;
    u32 *a6;
    u32 *q;
    u32 i;

    p = (u32 *)gModule_ObjTileCache64;
    i = 0;
    a2 = (u32 *)gModule_ObjTileCache16;
    a3 = (u32 *)gModule_ObjTileCache2;
    a4 = (u32 *)gModule_ObjTileCache8;
    a5 = (u32 *)gModule_ObjTileCache4;
    a6 = (u32 *)gModule_ObjTileCache1;
    q = gUnk_0203C270;
    for (; i != 4; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a2;
    for (i = 0; i != 0x18; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a3;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a4;
    for (i = 0; i != 0x14; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a5;
    for (i = 0; i != 0x10; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a6;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = q;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (*(u8 *)p == 0)
            *(u32 *)(p + 1) = 0xFFFF;
        else
            (*(u8 *)p)--;
    }
}
