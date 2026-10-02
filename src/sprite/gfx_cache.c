#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "functions.h"
#include "gba/syscall.h"

extern u16 gObjTileCache64Tiles[];
extern u16 gObjTileCache16Tiles[];
extern u16 gObjTileCache2Tiles[];
extern u16 gObjTileCache8Tiles[];
extern u16 gObjTileCache4Tiles[];
extern u16 gObjTileCache1Tiles[];

/* The file's RAM variables, defined in address order (ldscript.ld's
   .bss_gfx_cache places the section at 0x02025400). The seven caches run
   contiguously to the two counters: 0x14 bytes per ObjTileCacheEntry
   (counts 0x18/0x20/0x20/0x14/0x10/4) and 0x0C per ObjPaletteCacheEntry
   (0x10), which is exactly each variable's span to the next symbol. */
EWRAM_DATA struct ObjTileCacheEntry gObjTileCache16[0x18] = {0};
EWRAM_DATA struct ObjTileCacheEntry gObjTileCache2[0x20] = {0};
EWRAM_DATA struct ObjTileCacheEntry gObjTileCache1[0x20] = {0};
EWRAM_DATA struct ObjTileCacheEntry gObjTileCache8[0x14] = {0};
EWRAM_DATA struct ObjTileCacheEntry gObjTileCache4[0x10] = {0};
EWRAM_DATA struct ObjTileCacheEntry gObjTileCache64[0x4] = {0};
EWRAM_DATA struct ObjPaletteCacheEntry gObjPaletteCache[0x10] = {0};
EWRAM_DATA s32 gObjPalBytesPeak = 0;
EWRAM_DATA s32 gObjPalBytesCopiedThisFrame = 0;

void InitObjPaletteCacheEntry(struct ObjPaletteCacheEntry *entry)
{
    entry->palette = 0xFFFF;
    entry->age = 0;
    entry->pending = 0;
}

void InitObjTileCache(u32 count, u16 *tiles, struct ObjTileCacheEntry *entries)
{
    u32 i;
    u32 tile;

    i = 0;
    if (i != count) {
        register u32 f PIN(r12) = 0xFFFF;
        do {
            entries->gfx = f;
            entries->age = 0;
            entries->pending = 0;
            entries->tileIndex = *tiles;
            tile = *tiles;
            entries->vramDest = (GfxAddr)(OBJ_VRAM0 + (tile << 5));
            entries->unk06 = 0;
            i++;
            entries++;
            tiles++;
        } while (i != count);
    }
}

void InitGfxCaches(void)
{
    u32 i;
    u8 *color;
    struct ObjPaletteCacheEntry *q;

    {
        u16 *b = gObjTileCache64Tiles;
        struct ObjTileCacheEntry *c = gObjTileCache64;
        InitObjTileCache(4, b, c);
    }
    {
        u16 *b = gObjTileCache16Tiles;
        struct ObjTileCacheEntry *c = gObjTileCache16;
        InitObjTileCache(0x18, b, c);
    }
    {
        u16 *b = gObjTileCache2Tiles;
        struct ObjTileCacheEntry *c = gObjTileCache2;
        InitObjTileCache(0x20, b, c);
    }
    {
        u16 *b = gObjTileCache8Tiles;
        struct ObjTileCacheEntry *c = gObjTileCache8;
        InitObjTileCache(0x14, b, c);
    }
    {
        u16 *b = gObjTileCache4Tiles;
        struct ObjTileCacheEntry *c = gObjTileCache4;
        InitObjTileCache(0x10, b, c);
    }
    {
        u16 *b = gObjTileCache1Tiles;
        struct ObjTileCacheEntry *c = gObjTileCache1;
        InitObjTileCache(0x20, b, c);
    }
    i = 0;
    color = (u8 *)OBJ_PLTT;
    q = gObjPaletteCache;
    for (; i != 0x10; q++, i++) {
        InitObjPaletteCacheEntry(q);
        q->palDest = (GfxAddr)color;
        color += 0x20;
    }
}

void AgeGfxCaches(void)
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

    p = gObjTileCache64;
    i = 0;
    a2 = gObjTileCache16;
    a3 = gObjTileCache2;
    a4 = gObjTileCache8;
    a5 = gObjTileCache4;
    a6 = gObjTileCache1;
    q = gObjPaletteCache;
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

struct ObjTileCacheEntry *RequestObjTiles64(GfxSrc gfx, u8 flag)
{
    struct ObjTileCacheEntry *entry;
    struct ObjTileCacheEntry *pool;
    u32 i;

    entry = gObjTileCache64;
    i = 0;
    pool = entry;
    for (; i != 4; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            entry->unk05 = flag;
            return entry;
        }
    }
    entry = pool;
    for (i = 0; i != 4; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->unk05 = flag;
            entry->pending = 1;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }
    return 0;
}

struct ObjTileCacheEntry *RequestObjTiles16(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gObjTileCache16;
    for (i = 0; i != 24; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }
    entry = gObjTileCache16;
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

struct ObjTileCacheEntry *RequestObjTiles2(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gObjTileCache2;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }
    entry = gObjTileCache2;
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

struct ObjTileCacheEntry *RequestObjTiles8(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gObjTileCache8;
    for (i = 0; i != 20; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }
    entry = gObjTileCache8;
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

struct ObjTileCacheEntry *RequestObjTiles4(GfxSrc gfx)
{
    u32 i;
    struct ObjTileCacheEntry *entry;

    entry = gObjTileCache4;
    i = 0;
    do {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
        i++;
        entry++;
    } while (i != 16);
    entry = gObjTileCache4;
    for (i = 0; i != 16; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 1;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }
    return 0;
}

struct ObjTileCacheEntry *RequestObjTiles1(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }
    entry = gObjTileCache1;
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

struct ObjTileCacheEntry *RequestObjTiles1Compressed(GfxSrc gfx)
{
    struct ObjTileCacheEntry *entry;
    u32 i;

    entry = gObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->gfx == (GfxAddr)gfx) {
            entry->age = 1;
            return entry;
        }
    }
    entry = gObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++) {
        if (entry->age == 0) {
            entry->age = 1;
            entry->pending = 3;
            entry->gfx = (GfxAddr)gfx;
            return entry;
        }
    }
    return 0;
}

u8 RequestObjPalette(const void *a)
{
    struct ObjPaletteCacheEntry *p;
    struct ObjPaletteCacheEntry *q;
    u32 i;

    p = gObjPaletteCache;
    i = 0;
    q = p;
    for (; i != 16; i++, p++) {
        if (p->palette == (GfxAddr)a) {
            p->age = 1;
            p->pending = 1;
            return (u8)i;
        }
    }
    p = q;
    for (i = 0; i != 16; i++, p++) {
        if (p->age == 0) {
            p->age = 1;
            p->pending = 1;
            p->palette = (GfxAddr)a;
            return (u8)i;
        }
    }
    return 0;
}

void UploadPendingGfx(void)
{
    u8 buf[0x200];
    struct ObjTileCacheEntry *p;
    struct ObjPaletteCacheEntry *pal;
    u32 i;
    GfxAddr src;
    GfxAddr dest;
    s32 *q;

    gObjPalBytesCopiedThisFrame = 0;

    p = gObjTileCache64;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            RLUnCompVram((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 4);

    p = gObjTileCache16;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            RLUnCompVram((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 24);

    p = gObjTileCache2;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            RLUnCompVram((const void *)src, buf);
            CpuSet(buf, (void *)dest, 0x20);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x20);

    p = gObjTileCache8;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            RLUnCompVram((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 20);

    p = gObjTileCache4;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            RLUnCompVram((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x10);

    p = gObjTileCache1;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            if (p->pending == 1)
                CpuSet((const void *)src, (void *)dest, 0x10);
            else
                RLUnCompVram((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x20);

    pal = gObjPaletteCache;
    i = 0;
    q = &gObjPalBytesCopiedThisFrame;
    do {
        if (pal->pending != 0) {
            src = pal->palette;
            dest = pal->palDest;
            CpuSet((const void *)src, (void *)dest, 0x10);
            pal->pending = 0;
            *q += 0x20;
        }
        i++;
        pal++;
    } while (i != 0x10);

    if (gObjPalBytesCopiedThisFrame > gObjPalBytesPeak)
        gObjPalBytesPeak = gObjPalBytesCopiedThisFrame;
}
