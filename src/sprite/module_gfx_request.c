#include "global.h"
#include "functions.h"
#include "variables.h"

struct ObjTileCacheEntry *ModuleRequestObjTiles16(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache16;
    for (i = 0; i != 24; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache16;
    for (i = 0; i != 24; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles2(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache2;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache2;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles8(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache8;
    for (i = 0; i != 20; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache8;
    for (i = 0; i != 20; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles4(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache4;
    for (i = 0; i != 0x10; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache4;
    for (i = 0; i != 0x10; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles1(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }

    return 0;
}
