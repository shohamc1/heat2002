#include "global.h"

extern u32 AddOamEntry(u32 a, u32 b);

void sub_0801027C(u32 tile, u32 pal, u32 c)
{
    AddOamEntry((pal & 0xFF) | ((tile & 0x1FF) << 16) | 0x40000000, 0xF800 | c);
}
