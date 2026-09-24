#include "global.h"

extern u8 gUnk_0203D520[];

u32 sub_0834009C(u32 a0, u32 a1, u32 count)
{
    u32 p;
    u8 i;

    i = 0;
    p = (u32)gUnk_0203D520;
    while (i != 0x05) {
        if (*(u8 *)(p + 0x175) != 0)
            count = (u8)(count + 1);
        p += 0x190;
        i++;
        p += 0x190;
    }
    return count;
}
