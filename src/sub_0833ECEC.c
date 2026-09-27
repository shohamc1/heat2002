#include "global.h"
#include "variables.h"


void sub_0833ECEC(void)
{
    u16 *p = (u16 *)(*(u32 *)&gUnk_020251B8);
    u32 i = 0;

    do {
        *p++ = 0xE047;
        i++;
    } while (i != 0x380);
}
