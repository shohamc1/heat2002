#include "global.h"

extern u16 *gUnk_08364B08;
extern u16 gUnk_08335A8C[];
extern u16 gUnk_0833553C[];

void sub_0800649C(u8 *str, u32 x, u32 y)
{
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;
    u32 w;

    dest = gUnk_08364B08;
    dest += (y << 5) + x;
    color = 0xE0 << 8;
    w = 0x47;
    c = *str++;
    while (c != 0) {
        if (c != 0x20) {
            v = color;
            v |= gUnk_08335A8C[gUnk_0833553C[(u8)(c - 0x21)]];
            *dest++ = v;
        } else {
            w = 0x47;
            *dest++ = w;
        }
        c = *str++;
    }
}
