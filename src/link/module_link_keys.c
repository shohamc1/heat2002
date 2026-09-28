#include "global.h"


u16 ModulePackLinkKeys(u16 keys)
{
    u16 r;
    u16 t;

    t = keys & 8;
    r = t != 0;
    if (keys & 2) r = r | 2;
    if (keys & 1) r = r | 4;
    if (keys & 0x10) r = r | 8;
    if (keys & 0x20) r = r | 0x10;
    if (keys & 0x80) r = r | 0x20;
    if (keys & 0x40) r = r | 0x40;
    return r;
}


u16 ModuleUnpackLinkKeys(u16 packed)
{
    u16 r;

    r = ((packed & 1) ? -1 : 0) & 8;
    if (packed & 2)
        r |= 2;
    if (packed & 4)
        r |= 1;
    if (packed & 8)
        r |= 0x10;
    if (packed & 0x10)
        r |= 0x20;
    if (packed & 0x20)
        r |= 0x80;
    if (packed & 0x40)
        r |= 0x40;
    return r;
}

