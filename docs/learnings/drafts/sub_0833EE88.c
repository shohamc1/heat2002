#include "global.h"

extern u32 gUnk_020251B8;
extern u16 gUnk_02022254[];
extern u16 gUnk_02021D04[];

void sub_0833EE88(u8 *str, u32 y)
{
    u8 *cursor;
    u8 len;
    u8 c;
    u32 tile;
    u8 w;
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
    c = *str;
    str++;
    if (c != 0)
    {
        do
        {
            if (c != 0x20)
            {
                tile = gUnk_02022254[gUnk_02021D04[(u8)(c - 0x21)]] | e;
            }
            else
            {
                tile = 0x47;
            }
            *dest = tile;
            dest++;
            c = *str;
            str++;
        } while (c != 0);
    }
}
