#include "global.h"
#include "functions.h"
#include "variables.h"

extern s32 gModule_ObjPalBytesCopiedThisFrame;
extern s32 gModule_ObjPalBytesPeak;

void ModuleUploadPendingGfx(void)
{
    u8 buf[0x200];
    struct ObjTileCacheEntry *p;
    struct ObjPaletteCacheEntry *pal;
    u32 i;
    GfxAddr src;
    GfxAddr dest;
    s32 *q;

    gModule_ObjPalBytesCopiedThisFrame = 0;

    p = gModule_ObjTileCache64;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70((const void *)src, (void *)dest);
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
            sub_08344B70((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 24);

    p = gModule_ObjTileCache2;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70((const void *)src, buf);
            sub_08344B64(buf, (void *)dest, 0x20);
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
            sub_08344B70((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 20);

    p = gModule_ObjTileCache4;
    i = 0;
    do {
        if (p->pending != 0) {
            src = p->gfx;
            dest = p->vramDest;
            sub_08344B70((const void *)src, (void *)dest);
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
                sub_08344B64((const void *)src, (void *)dest, 0x10);
            else
                sub_08344B70((const void *)src, (void *)dest);
            p->pending = 0;
        }
        i++;
        p++;
    } while (i != 0x20);

    pal = gModule_ObjPaletteCache;
    i = 0;
    q = &gModule_ObjPalBytesCopiedThisFrame;
    do {
        if (pal->pending != 0) {
            src = pal->palette;
            dest = pal->palDest;
            sub_08344B64((const void *)src, (void *)dest, 0x10);
            pal->pending = 0;
            *q += 0x20;
        }
        i++;
        pal++;
    } while (i != 0x10);

    if (gModule_ObjPalBytesCopiedThisFrame > gModule_ObjPalBytesPeak)
        gModule_ObjPalBytesPeak = gModule_ObjPalBytesCopiedThisFrame;
}
