#include "global.h"
#include "variables.h"


u8 ModuleRequestObjPalette(u32 palette)
{
    u32 *p;
    u32 i;

    p = gUnk_0203C270;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (p[1] == palette) {
            *(u8 *)p = 1;
            *((u8 *)p + 1) = 1;
            return i;
        }
    }
    p = gUnk_0203C270;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (*(u8 *)p == 0) {
            *(u8 *)p = 1;
            *((u8 *)p + 1) = 1;
            p[1] = palette;
            return i;
        }
    }
    return 0;
}
