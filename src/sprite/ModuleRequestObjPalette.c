#include "global.h"
#include "functions.h"
#include "variables.h"

u8 ModuleRequestObjPalette(const void *palette)
{
    struct ObjPaletteCacheEntry *p;
    u32 i;

    p = gModule_ObjPaletteCache;
    for (i = 0; i != 0x10; i++, p++) {
        if (p->palette == (GfxAddr)palette) {
            p->age = 1;
            p->pending = 1;
            return i;
        }
    }
    p = gModule_ObjPaletteCache;
    for (i = 0; i != 0x10; i++, p++) {
        if (p->age == 0) {
            p->age = 1;
            p->pending = 1;
            p->palette = (GfxAddr)palette;
            return i;
        }
    }
    return 0;
}
