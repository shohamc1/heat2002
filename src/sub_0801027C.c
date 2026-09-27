#include "global.h"
#include "functions.h"


void sub_0801027C(u32 tile, u32 pal, u32 c)
{
    AddOamEntry((pal & 0xFF) | ((tile & 0x1FF) << 16) | 0x40000000, 0xF800 | c);
}
