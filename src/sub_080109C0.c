#include "global.h"

u32 AddOamEntry(u32 a, u32 b);

void sub_080109C0(u8 *str, u32 attr, u32 pal)
{
    u8 *s;
    u32 a;
    u8 c;

    a = attr;
    s = str;
    for (c = *s++; c != 0; c = *s++)
    {
        if (c != 0x20)
            AddOamEntry(((a & 0x1FF) << 0x10) | (pal & 0xFF), (c + 0x2E0) | 0xD800);
        a += 4;
    }
}
