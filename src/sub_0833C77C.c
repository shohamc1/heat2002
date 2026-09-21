#include "global.h"

u16 sub_0833C77C(u16 x)
{
    u16 v;

    v = ((x & 1) ? -1 : 0) & 8;
    if (x & 2)
        v |= 2;
    if (x & 4)
        v |= 1;
    if (x & 8)
        v |= 0x10;
    if (x & 0x10)
        v |= 0x20;
    if (x & 0x20)
        v |= 0x80;
    if (x & 0x40)
        v |= 0x40;
    return v;
}
