#include "global.h"

extern u16 *gUnk_08364B08;
extern u16 gUnk_0833553C[];
extern u16 gUnk_08335A8C[];

void sub_08006418(u8 *str, u32 y)
{
    u8 *p;
    u8 len;
    u8 pad;
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;
    u32 w;

    p = str;
    len = 0;
    c = *p;
    while (c != 0) {
        p++;
        len++;
        c = *p;
    }
    pad = (u8)((0x1E - len) / 2);
    dest = gUnk_08364B08;
    dest += (y << 5) + pad;
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
