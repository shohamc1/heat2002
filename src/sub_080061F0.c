#include "global.h"

extern u16 *gUnk_08364B08;

void sub_080061F0(void)
{
    u16 *p = gUnk_08364B08;
    u32 i = 0;

    do {
        *p++ = 0xE047;
        i++;
    } while (i != 0x380);
}
