#include "global.h"
#include "functions.h"
#include "data.h"

void sub_080109C0(const u8 *str, u32 attr, u32 pal)
{
    const u8 *s;
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

void sub_080109C0(const u8 *str, u32 attr, u32 pal);

void sub_08010A04(u32 a0, u32 a1, u32 a2)
{
    u8 v = a0;
    u8 w = v;

    if (v == 1)
        sub_080109C0(gText_A, a1, a2);
    if (v == 2)
        sub_080109C0(gText_Ab, a1, a2);
    if (v == 3)
        sub_080109C0(gText_Abc, a1, a2);
    if (v == 4)
        sub_080109C0(gText_Abcd, a1, a2);
    if (v == 5)
        sub_080109C0(gText_Abcde, a1, a2);
    if (v == 6)
        sub_080109C0(gText_Abcdee, a1, a2);
    if (v == 7)
        sub_080109C0(gText_Abcdeee, a1, a2);
    if (w == 8)
        sub_080109C0(gText_Abcdeeee, a1, a2);
}
