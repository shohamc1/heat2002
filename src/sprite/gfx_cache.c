#include "global.h"
#include "gba/defines.h"
#include "variables.h"
extern u16 gObjTileCache64Tiles[];
extern u16 gObjTileCache16Tiles[];
extern u16 gObjTileCache2Tiles[];
extern u16 gObjTileCache8Tiles[];
extern u16 gObjTileCache4Tiles[];
extern u16 gObjTileCache1Tiles[];

struct Unk080072F4 {
    u8 a;
    u8 b;
    u16 c;
    u32 d;
};
struct unk_07304
{
    u32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u32 f8;
    u32 fC;
    u32 f10;
};


void InitObjPaletteCacheEntry(struct Unk080072F4 *entry)
{
    entry->d = 0xFFFF;
    entry->a = 0;
    entry->b = 0;
}


void InitObjTileCache(u32 count, u16 *tiles, struct unk_07304 *entries)
{
    u32 i;
    u32 tile;

    i = 0;
    if (i != count)
    {
        register u32 f asm("r12") = 0xFFFF;
        do {
            entries->f8 = f;
            entries->f0 = 0;
            entries->f4 = 0;
            entries->f10 = *tiles;
            tile = *tiles;
            entries->fC = OBJ_VRAM0 + (tile << 5);
            entries->f6 = 0;
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
    u32 *q;

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
    q = gObjPaletteCache;
    for (; i != 0x10; q += 3, i++) {
        InitObjPaletteCacheEntry((void *)q);
        *(u32 *)((u8 *)q + 8) = color;
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

