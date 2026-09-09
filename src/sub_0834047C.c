#include "global.h"

u32 sub_08344BB8(u32 a, u32 b);

void sub_0834047C(u16 *a, u16 *b)
{
    u32 i;
    for (i = 0; (u8)i != 5; i = (u8)(i + 1))
    {
        u16 *d = (u16 *)((u32)i * 2 + (u32)b);
        *d = sub_08344BB8(0x80 << 9, a[i]);
    }
}
