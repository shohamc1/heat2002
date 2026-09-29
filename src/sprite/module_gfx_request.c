#include "global.h"
#include "variables.h"

struct ObjTileCacheEntry *ModuleRequestObjTiles16(void *gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache16;
    for (i = 0; i != 0x18; i++, entry++) {
        if (entry->gfx == gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache16;
    for (i = 0; i != 0x18; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles2(void *gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache2;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->gfx == gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache2;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles8(void *gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache8;
    for (i = 0; i != 0x14; i++, entry++) {
        if (entry->gfx == gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache8;
    for (i = 0; i != 0x14; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles4(void *gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache4;
    for (i = 0; i != 0x10; i++, entry++) {
        if (entry->gfx == gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache4;
    for (i = 0; i != 0x10; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = gfx;
            return entry;
        }
    }

    return 0;
}

struct ObjTileCacheEntry *ModuleRequestObjTiles1(void *gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->gfx == gfx) {
            entry->age = 1;
            return entry;
        }
    }

    entry = gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = gfx;
            return entry;
        }
    }

    return 0;
}
