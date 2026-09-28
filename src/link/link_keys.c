#include "global.h"
#include "gba/io_reg.h"

u16 PackLinkKeys(u16 keys)
{
    u16 t = keys & 8;
    u16 r = t != 0;

    if (keys & B_BUTTON)
        r |= 2;
    if (keys & A_BUTTON)
        r |= 4;
    if (keys & DPAD_RIGHT)
        r |= 8;
    if (keys & DPAD_LEFT)
        r |= 0x10;
    if (keys & DPAD_DOWN)
        r |= 0x20;
    if (keys & DPAD_UP)
        r |= 0x40;
    return r;
}

u32 UnpackLinkKeys(u16 a)
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
