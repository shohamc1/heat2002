#include "global.h"
#include "variables.h"


u32 *sub_080075E4(u32 a)
{
    u32 *p;
    u32 i;

    p = gUnk_02025AE0;
    for (i = 0; i != 0x14; i++, p += 5) {
        if (p[2] == a) {
            p[0] = 1;
            return p;
        }
    }
    p = gUnk_02025AE0;
    for (i = 0; i != 0x14; i++, p += 5) {
        if (p[0] == 0) {
            p[0] = 1;
            *(u8 *)(p + 1) = 1;
            p[2] = a;
            return p;
        }
    }
    return 0;
}
