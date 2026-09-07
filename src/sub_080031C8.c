#include "global.h"

u16 sub_080031C8(u16 keys)
{
    u16 t = keys & 8;
    u16 r = t != 0;

    if (keys & 2)
        r |= 2;
    if (keys & 1)
        r |= 4;
    if (keys & 0x10)
        r |= 8;
    if (keys & 0x20)
        r |= 0x10;
    if (keys & 0x80)
        r |= 0x20;
    if (keys & 0x40)
        r |= 0x40;
    return r;
}
