#include "global.h"

void sub_08344B60(u32 a, u32 b, u32 c);

void sub_0833D070(u32 a, u32 b)
{
    u32 i;

    for (i = 0; i != 0x1C; i++) {
        sub_08344B60(a, b, 0x10);
        a += 0x40;
        b += 0x40;
    }
}
