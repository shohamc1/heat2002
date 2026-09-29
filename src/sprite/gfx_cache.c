#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "functions.h"
#include "gba/syscall.h"

struct ObjPaletteCacheEntry
{
    u8 age;
    u8 pending;
    u8 pad02;
    u32 palette;
    u32 palDest;
};
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

extern u16 gObjTileCache64Tiles[];
extern u16 gObjTileCache16Tiles[];
extern u16 gObjTileCache2Tiles[];
extern u16 gObjTileCache8Tiles[];
extern u16 gObjTileCache4Tiles[];
extern u16 gObjTileCache1Tiles[];
extern s32 gObjPalBytesCopiedThisFrame;
extern s32 gObjPalBytesPeak;

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
        register u32 f asm("r12") = 0xFFFF;
        do {
            entries->gfx = f;
            entries->age = 0;
            entries->pending = 0;
            entries->tileIndex = *tiles;
            tile = *tiles;
            entries->vramDest = OBJ_VRAM0 + (tile << 5);
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
    u32 color;
    struct ObjPaletteCacheEntry *q;

    {
        u16 *b = gObjTileCache64Tiles;
        u32 *c = gObjTileCache64;
        InitObjTileCache(4, b, c);
    }
    {
        u16 *b = gObjTileCache16Tiles;
        u32 *c = gObjTileCache16;
        InitObjTileCache(0x18, b, c);
    }
    {
        u16 *b = gObjTileCache2Tiles;
        u32 *c = gObjTileCache2;
        InitObjTileCache(0x20, b, c);
    }
    {
        u16 *b = gObjTileCache8Tiles;
        u32 *c = gObjTileCache8;
        InitObjTileCache(0x14, b, c);
    }
    {
        u16 *b = gObjTileCache4Tiles;
        u32 *c = gObjTileCache4;
        InitObjTileCache(0x10, b, c);
    }
    {
        u16 *b = gObjTileCache1Tiles;
        u32 *c = gObjTileCache1;
        InitObjTileCache(0x20, b, c);
    }
    i = 0;
    color = OBJ_PLTT;
    q = (struct ObjPaletteCacheEntry *)gObjPaletteCache;
    for (; i != 0x10; q++, i++) {
        InitObjPaletteCacheEntry(q);
        q->palDest = color;
        color += 0x20;
    }
}

void AgeGfxCaches(void)
{
    u32 *p;
    u32 *a2;
    u32 *a3;
    u32 *a4;
    u32 *a5;
    u32 *a6;
    u32 *q;
    u32 i;

    p = gObjTileCache64;
    i = 0;
    a2 = gObjTileCache16;
    a3 = gObjTileCache2;
    a4 = gObjTileCache8;
    a5 = gObjTileCache4;
    a6 = gObjTileCache1;
    q = gObjPaletteCache;
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

u32 *RequestObjTiles64(u32 gfx, u8 flag)
{
    u32 *entry;
    u32 *pool;
    u32 i;

    entry = gObjTileCache64;
    i = 0;
    pool = entry;
    for (; i != 4; i++, entry += 5) {
        if (entry[2] == gfx) {
            entry[0] = 1;
            *((u8 *)entry + 5) = flag;
            return entry;
        }
    }
    entry = pool;
    for (i = 0; i != 4; i++, entry += 5) {
        if (entry[0] == 0) {
            entry[0] = 1;
            *((u8 *)entry + 5) = flag;
            *((u8 *)entry + 4) = 1;
            entry[2] = gfx;
            return entry;
        }
    }
    return 0;
}

u32 *RequestObjTiles16(u32 gfx)
{
    u32 *entry;
    u32 i;

    entry = gObjTileCache16;
    for (i = 0; i != 0x18; i++, entry += 5) {
        if (entry[2] == gfx) {
            entry[0] = 1;
            return entry;
        }
    }
    entry = gObjTileCache16;
    for (i = 0; i != 0x18; i++, entry += 5) {
        if (entry[0] == 0) {
            entry[0] = 1;
            *(u8 *)(entry + 1) = 1;
            entry[2] = gfx;
            return entry;
        }
    }
    return 0;
}

u32 *RequestObjTiles2(u32 gfx)
{
    u32 *entry;
    u32 i;

    entry = gObjTileCache2;
    for (i = 0; i != 0x20; i++, entry += 5) {
        if (entry[2] == gfx) {
            entry[0] = 1;
            return entry;
        }
    }
    entry = gObjTileCache2;
    for (i = 0; i != 0x20; i++, entry += 5) {
        if (entry[0] == 0) {
            entry[0] = 1;
            *(u8 *)(entry + 1) = 1;
            entry[2] = gfx;
            return entry;
        }
    }
    return 0;
}

u32 *RequestObjTiles8(u32 gfx)
{
    u32 *entry;
    u32 i;

    entry = gObjTileCache8;
    for (i = 0; i != 0x14; i++, entry += 5) {
        if (entry[2] == gfx) {
            entry[0] = 1;
            return entry;
        }
    }
    entry = gObjTileCache8;
    for (i = 0; i != 0x14; i++, entry += 5) {
        if (entry[0] == 0) {
            entry[0] = 1;
            *(u8 *)(entry + 1) = 1;
            entry[2] = gfx;
            return entry;
        }
    }
    return 0;
}

u32 *RequestObjTiles4(u32 gfx)
{
    u32 i;
    u32 *entry;

    entry = gObjTileCache4;
    i = 0;
    do {
        if (entry[2] == gfx) {
            entry[0] = 1;
            return entry;
        }
        i++;
        entry += 5;
    } while (i != 16);
    entry = gObjTileCache4;
    for (i = 0; i != 16; i++, entry += 5) {
        if (entry[0] == 0) {
            entry[0] = 1;
            *(u8 *)(entry + 1) = 1;
            entry[2] = gfx;
            return entry;
        }
    }
    return 0;
}

u32 *RequestObjTiles1(u32 gfx)
{
    u32 *entry;
    u32 i;

    entry = gObjTileCache1;
    for (i = 0; i != 0x20; i++, entry += 5) {
        if (entry[2] == gfx) {
            entry[0] = 1;
            return entry;
        }
    }
    entry = gObjTileCache1;
    for (i = 0; i != 0x20; i++, entry += 5) {
        if (entry[0] == 0) {
            entry[0] = 1;
            *(u8 *)(entry + 1) = 1;
            entry[2] = gfx;
            return entry;
        }
    }
    return 0;
}

u32 *RequestObjTiles1Compressed(u32 gfx)
{
    u32 *entry;
    u32 i;

    entry = gObjTileCache1;
    for (i = 0; i != 0x20; i++, entry += 5) {
        if (entry[2] == gfx) {
            entry[0] = 1;
            return entry;
        }
    }
    entry = gObjTileCache1;
    for (i = 0; i != 0x20; i++, entry += 5) {
        if (entry[0] == 0) {
            entry[0] = 1;
            *(u8 *)(entry + 1) = 3;
            entry[2] = gfx;
            return entry;
        }
    }
    return 0;
}

u8 RequestObjPalette(u32 a)
{
    u32 *p;
    u32 *q;
    u32 i;

    p = gObjPaletteCache;
    i = 0;
    q = p;
    for (; i != 16; i++, p += 3) {
        if (p[1] == a) {
            *((u8 *)p + 0) = 1;
            *((u8 *)p + 1) = 1;
            return (u8)i;
        }
    }
    p = q;
    for (i = 0; i != 16; i++, p += 3) {
        if (*(u8 *)p == 0) {
            *(u8 *)p = 1;
            *((u8 *)p + 1) = 1;
            p[1] = a;
            return (u8)i;
        }
    }
    return 0;
}

void UploadPendingGfx(void)
{
    u8 buf[0x200];
    u8 *p;
    u32 i;
    s32 src;
    s32 dest;
    s32 *q;

    gObjPalBytesCopiedThisFrame = 0;

    p = (u8 *)gObjTileCache64;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            RLUnCompVram(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 4);

    p = (u8 *)gObjTileCache16;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            RLUnCompVram(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x18);

    p = (u8 *)gObjTileCache2;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            RLUnCompVram((const void *)src, buf);
            CpuSet(buf, (void *)dest, 0x20);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = (u8 *)gObjTileCache8;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            RLUnCompVram(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x14);

    p = (u8 *)gObjTileCache4;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            RLUnCompVram(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x10);

    p = (u8 *)gObjTileCache1;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            if (((struct ObjTileCacheEntry *)p)->pending == 1)
                CpuSet(src, dest, 0x10);
            else
                RLUnCompVram(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = (u8 *)gObjPaletteCache;
    i = 0;
    q = &gObjPalBytesCopiedThisFrame;
    do {
        if (((struct ObjPaletteCacheEntry *)p)->pending != 0) {
            src = ((struct ObjPaletteCacheEntry *)p)->palette;
            dest = ((struct ObjPaletteCacheEntry *)p)->palDest;
            CpuSet(src, dest, 0x10);
            ((struct ObjPaletteCacheEntry *)p)->pending = 0;
            *q += 0x20;
        }
        i++;
        p += 0xC;
    } while (i != 0x10);

    if (gObjPalBytesCopiedThisFrame > gObjPalBytesPeak)
        gObjPalBytesPeak = gObjPalBytesCopiedThisFrame;
}
