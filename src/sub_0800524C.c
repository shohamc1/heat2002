#include "global.h"
#include "data.h"


void sub_0800524C(void)
{
    u8 i;

    for (i = 0; i != 0x1B; i++)
    {
        u16 *b = (u16 *)(*(volatile u32 *)&gUnk_08364B08[0]);
        b[i + 0x100] = 0x47;
        b[i + 0x120] = 0x47;
    }
}
