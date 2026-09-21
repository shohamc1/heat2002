#include "global.h"

u16 sub_0833C70C(u16 p)
{
    u16 r;
    u16 q;

    q = p & 8;
    r = q != 0;
    if (p & 2) r = r | 2;
    if (p & 1) r = r | 4;
    if (p & 0x10) r = r | 8;
    if (p & 0x20) r = r | 0x10;
    if (p & 0x80) r = r | 0x20;
    if (p & 0x40) r = r | 0x40;
    return r;
}
