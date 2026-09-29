#include "global.h"
#include "functions.h"
#include "variables.h"

extern s32 gUnk_0203C334;
extern s32 gUnk_0203C330;

struct ObjTileCacheEntry
{
    u32 age;
    u8 pending;
    u8 unk05;
    u8 unk06;
    u8 unk07;
    u32 gfx;
    u32 vramDest;
    u32 tileIndex;
};
struct ObjPaletteCacheEntry
{
    u8 age;
    u8 pending;
    u8 pad02;
    u32 palette;
    u32 palDest;
};

void sub_08344B70(u32 a, u32 b);

void ModuleUploadPendingGfx(void)
{
    u8 buf[0x200];
    u8 *p;
    u32 i;
    s32 src;
    s32 dest;
    s32 *q;

    gUnk_0203C334 = 0;

    p = gModule_ObjTileCache64;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            sub_08344B70(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 4);

    p = gModule_ObjTileCache16;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            sub_08344B70(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x18);

    p = gModule_ObjTileCache2;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            sub_08344B70(src, (u32)buf);
            sub_08344B64((u32)buf, dest, 0x20);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = gModule_ObjTileCache8;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            sub_08344B70(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x14);

    p = gModule_ObjTileCache4;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            sub_08344B70(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x10);

    p = gModule_ObjTileCache1;
    i = 0;
    do {
        if (((struct ObjTileCacheEntry *)p)->pending != 0) {
            src = ((struct ObjTileCacheEntry *)p)->gfx;
            dest = ((struct ObjTileCacheEntry *)p)->vramDest;
            if (((struct ObjTileCacheEntry *)p)->pending == 1)
                sub_08344B64(src, dest, 0x10);
            else
                sub_08344B70(src, dest);
            ((struct ObjTileCacheEntry *)p)->pending = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = (u8 *)gUnk_0203C270;
    i = 0;
    q = &gUnk_0203C334;
    do {
        if (((struct ObjPaletteCacheEntry *)p)->pending != 0) {
            src = ((struct ObjPaletteCacheEntry *)p)->palette;
            dest = ((struct ObjPaletteCacheEntry *)p)->palDest;
            sub_08344B64(src, dest, 0x10);
            ((struct ObjPaletteCacheEntry *)p)->pending = 0;
            *q += 0x20;
        }
        i++;
        p += 0xC;
    } while (i != 0x10);

    if (gUnk_0203C334 > gUnk_0203C330)
        gUnk_0203C330 = gUnk_0203C334;
}
