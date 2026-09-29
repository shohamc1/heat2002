#include "global.h"
#include "functions.h"
#include "variables.h"

extern s32 gUnk_0203C334;
extern s32 gUnk_0203C330;

void sub_08344B70(u32 a, u32 b);

void ModuleUploadPendingGfx(void)
{
    u8 buf[0x200];
    struct ObjTileCacheEntry *p;
    struct ObjPaletteCacheEntry *pal;
    u32 i;
    s32 src;
    s32 dest;
    s32 *q;

    gUnk_0203C334 = 0;

    p = gModule_ObjTileCache64;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70(src, dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 4);

    p = gModule_ObjTileCache16;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70(src, dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x18);

    p = gModule_ObjTileCache2;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70(src, (u32)buf);
            sub_08344B64((u32)buf, dest, 0x20);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x20);

    p = gModule_ObjTileCache8;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70(src, dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x14);

    p = gModule_ObjTileCache4;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70(src, dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x10);

    p = gModule_ObjTileCache1;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            if (p->pending == 1)
                sub_08344B64(src, dest, 0x10);
            else
                sub_08344B70(src, dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x20);

    pal = gModule_ObjPaletteCache;
    i = 0;
    q = &gUnk_0203C334;
    do {
        if (pal->pending != 0) {
            src = pal->palette;
            dest = pal->palDest;
            sub_08344B64(src, dest, 0x10);
            pal->pending = 0;
            *q += 0x20;
        }
        i++;
        pal++;
    } while (i != 0x10);

    if (gUnk_0203C334 > gUnk_0203C330)
        gUnk_0203C330 = gUnk_0203C334;
}
