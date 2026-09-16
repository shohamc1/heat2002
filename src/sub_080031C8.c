#include "global.h"
#include "gba/io_reg.h"

u16 sub_080031C8(u16 keys)
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
