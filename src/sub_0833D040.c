#include "global.h"

extern u8 gUnk_02039234[];

void sub_08344B60(u32 a, u32 b, u32 c);

void sub_0833D040(u32 a, u32 b)
{
    u32 i;
    u32 p = a;
    u32 q = b;

    if (gUnk_02039234[0] != 0)
        p += 4;
    for (i = 0; i != 0x18; i++) {
        sub_08344B60(p, q, 0x10);
        p += 0x48;
        q += 0x40;
    }
}
