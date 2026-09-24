#include "global.h"

extern u32 AddOamEntry(u32 a, u32 b);

void sub_08010134(u32 a, u32 b, u32 c, u32 d)
{
    u32 v = d << 24;
    u32 x = (b & 0xFF) | ((a & 0x1FF) << 16) | 0xC0000000;
    u32 y = v >> 12;

    y |= 0x800;
    y |= c;
    AddOamEntry(x, y);
}
