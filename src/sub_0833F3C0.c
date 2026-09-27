#include "global.h"
#include "variables.h"

extern u32 gUnk_020251B8;

void sub_0833F3C0(u8 *str, u32 y, u8 shade)
{
    u8 *cursor;
    u8 len;
    u8 c;
    u8 w;
    u16 gw;
    u16 *dest;
    u32 e;

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
    if (shade != 0)
        e = 0xF0 << 8;
    c = *str;
    str++;
    if (c != 0)
    {
        do
        {
            gw = gUnk_0201F590[(u8)(c - 0x20)];
            *dest = e | gUnk_0201F9D0[gw];
            dest++;
            c = *str;
            str++;
        } while (c != 0);
    }
}
