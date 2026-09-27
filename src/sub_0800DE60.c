#include "global.h"
#include "variables.h"


void sub_0800DE60(u32 id, u32 c)
{
    s16 *g = gOamBuffer;
    u32 v = (id << 23) >> 23;

    g[9] = (g[9] & ~0x1FF) | v;
    ((u8 *)g)[0x10] = c;
    ((u8 *)g)[0x13] = (((u8 *)g)[0x13] & 0x3F) | 0x80;
    g[10] &= ~0x3FF;
}
