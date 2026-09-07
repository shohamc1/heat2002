#include "global.h"

u32 sub_08003238(u16 a)
{
    u16 r = 0;
    if (a & 1)
        r = 8;
    if (a & 2)
        r |= 2;
    if (a & 4)
        r |= 1;
    if (a & 8)
        r |= 16;
    if (a & 16)
        r |= 32;
    if (a & 32)
        r |= 128;
    if (a & 64)
        r |= 64;
    return r;
}
