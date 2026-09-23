#include "global.h"

extern u32 gUnk_0203BCD0[];

u32 *sub_0833FD2C(u32 a)
{
    u32 *p;
    u32 i;

    p = gUnk_0203BCD0;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[2] == a) {
            p[0] = 1;
            return p;
        }
    }
    p = gUnk_0203BCD0;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0) {
            p[0] = 1;
            *(u8 *)(p + 1) = 3;
            p[2] = a;
            return p;
        }
    }
    return 0;
}
