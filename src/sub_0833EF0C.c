#include "global.h"
#include "variables.h"


void sub_0833EF0C(u8 *str, u32 a2, u32 a3)
{
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;
    u32 w;

    dest = (u16 *)*(u32 *)&gUnk_020251B8;
    dest += (a3 << 5) + a2;
    color = 0xE0 << 8;
    w = 0x47;
    c = *str++;
    while (c != 0) {
        if (c != 0x20) {
            v = color;
            v |= gUnk_02022254[gUnk_02021D04[(u8)(c - 0x21)]];
            *dest++ = v;
        } else {
            w = 0x47;
            *dest++ = w;
        }
        c = *str++;
    }
}
