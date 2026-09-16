#include "global.h"

extern void sub_0800EA64(void *a1);

void sub_0800EEFC(u8 *a1, u32 a2, u32 a3, u8 a4, u8 a5)
{
    u32 v;
    u32 size;

    if (a1[0x18] != 0 || a1[0x1E] == 0 || a1[0x4A] != 0
        || (*(u32 *)(a1 + 0x20) = a2, size = (a3 + 0xF) & ~0xF, size - 0x100 > 0x0003FF00))
    {
        sub_0800EA64(a1);
    }
    else
    {
        *(u32 *)(a1 + 0x24) = a2 + size;
        switch (((a5 << 24) + (4 << 24)) >> 24)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            v = (a4 << 3) | (3 - (s8)a5);
            break;
        case 4:
            v = a4 | 0x38;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            v = (a4 << 3) | ((s8)a5 - 1);
            break;
        }
        v &= 0x3F;
        {
            s32 t = v << 1;
            *(s8 *)(a1 + 0x1C) = t | -0x7F;
        }
        a1[0x18] = 0xD0;
    }
}
