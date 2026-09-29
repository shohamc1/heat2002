#include "global.h"
#include "variables.h"

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
