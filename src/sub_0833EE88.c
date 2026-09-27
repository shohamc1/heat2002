#include "global.h"
#include "variables.h"

extern u32 gUnk_020251B8;

void sub_0833EE88(u8 *str, u32 y)
{
    u8 *cursor;
    u8 len;
    u8 w;
    u16 *dest;
    u32 e;
    u32 c;
    u32 v;
    u32 t;

    cursor = str;
    len = 0;
    while (*cursor != 0)
    {
        cursor++;
        len++;
    }
    w = (u8)((0x1E - len) / 2);
    dest = (u16 *)gUnk_020251B8;
    dest = (u16 *)((u32)dest + (((y << 5) + w) << 1));
    e = 0xE0 << 8;
    t = 0x47;
    c = *str++;
    while (c != 0)
    {
        if (c != 0x20)
        {
            v = e;
            v |= gUnk_02022254[gUnk_02021D04[(u8)(c - 0x21)]];
            *dest++ = v;
        }
        else
        {
            t = 0x47;
            *dest++ = t;
        }
        c = *str++;
    }
}
