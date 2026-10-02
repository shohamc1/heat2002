#include "global.h"
#include "functions.h"
#include "gba/defines.h"
#include "variables.h"

extern u16 gModule_ObjTileCache64Tiles[];
extern u16 gModule_ObjTileCache16Tiles[];
extern u16 gModule_ObjTileCache2Tiles[];
extern u16 gModule_ObjTileCache8Tiles[];
extern u16 gModule_ObjTileCache4Tiles[];
extern u16 gModule_ObjTileCache1Tiles[];

/* This file also owns the high module's gfx-cache EWRAM run
   0x0203B870-0x0203C340 (issue 5 step 3, run rule; MODULE_EWRAM_DATA),
   the module twin of src/sprite/gfx_cache.c's run: the six OBJ tile
   caches, the OBJ palette cache and the two upload counters behind them
   (gModule_ObjPalBytesPeak/gModule_ObjPalBytesCopiedThisFrame, src/sprite/ModuleUploadPendingGfx.c's
   variables, which close the run 8 bytes before
   src/task/module_task.c's task run begins). ldscript.ld's
   .module_ewram_data_gfx_cache places the section at 0x0203B870. */

MODULE_EWRAM_DATA struct ObjTileCacheEntry gModule_ObjTileCache16[0x18] = {0};
MODULE_EWRAM_DATA struct ObjTileCacheEntry gModule_ObjTileCache2[0x20] = {0};
MODULE_EWRAM_DATA struct ObjTileCacheEntry gModule_ObjTileCache1[0x20] = {0};
MODULE_EWRAM_DATA struct ObjTileCacheEntry gModule_ObjTileCache8[0x14] = {0};
MODULE_EWRAM_DATA struct ObjTileCacheEntry gModule_ObjTileCache4[0x10] = {0};
MODULE_EWRAM_DATA struct ObjTileCacheEntry gModule_ObjTileCache64[4] = {0};
MODULE_EWRAM_DATA struct ObjPaletteCacheEntry gModule_ObjPaletteCache[0x10] = {0};
MODULE_EWRAM_DATA s32 gModule_ObjPalBytesPeak = 0;
MODULE_EWRAM_DATA s32 gModule_ObjPalBytesCopiedThisFrame = 0;
static MODULE_EWRAM_DATA u8 gfx_gapC338[0x8] = {0};

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
        entries->vramDest = (GfxAddr)((*tiles << 5) + OBJ_VRAM0);
        entries->unk06 = 0;
    }
}

void ModuleInitGfxCaches(void)
{
    u32 i;
    u32 color;
    struct ObjPaletteCacheEntry *entry;
    u16 *src;
    struct ObjTileCacheEntry *dest;

    src = gModule_ObjTileCache64Tiles;
    dest = gModule_ObjTileCache64;
    ModuleInitObjTileCache(4, src, dest);
    src = gModule_ObjTileCache16Tiles;
    dest = gModule_ObjTileCache16;
    ModuleInitObjTileCache(0x18, src, dest);
    src = gModule_ObjTileCache2Tiles;
    dest = gModule_ObjTileCache2;
    ModuleInitObjTileCache(0x20, src, dest);
    src = gModule_ObjTileCache8Tiles;
    dest = gModule_ObjTileCache8;
    ModuleInitObjTileCache(0x14, src, dest);
    src = gModule_ObjTileCache4Tiles;
    dest = gModule_ObjTileCache4;
    ModuleInitObjTileCache(0x10, src, dest);
    src = gModule_ObjTileCache1Tiles;
    dest = gModule_ObjTileCache1;
    ModuleInitObjTileCache(0x20, src, dest);

    i = 0;
    color = OBJ_PLTT;
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
    for (i = 0; i != 24; i++, p++) {
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
    for (i = 0; i != 20; i++, p++) {
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
