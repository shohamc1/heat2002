#include "global.h"

extern u16 *gUnk_08364B08;

void sub_08004A18(void)
{
    u8 i, j;
    u16 *p;

    p = gUnk_08364B08 + 0xA6;
    for (j = 0; j != 8; j++)
    {
        for (i = 0; i != 0x13; i++)
            *p++ = 0xE047;
        p += 13;
    }
}
