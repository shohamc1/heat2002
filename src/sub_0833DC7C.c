#include "global.h"
#include "variables.h"


void sub_0833DC7C(void)
{
    u8 i = 0;

    do {
        u16 *b = (u16 *)(*(volatile u32 *)&gUnk_020251B8);  /* per-iteration reload, as the ROM loop */
        u16 *q = (u16 *)(2 * i + (u32)b);
        q[0x100] = 0x47;
        q[0x120] = 0x47;
        i++;
    } while (i != 0x1B);
}
