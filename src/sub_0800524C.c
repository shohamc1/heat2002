#include "global.h"

extern u16 *gUnk_08364B08;

void sub_0800524C(void)
{
    u8 i;

    for (i = 0; i != 0x1B; i++)
    {
        gUnk_08364B08[i + 0x100] = 0x47;
        gUnk_08364B08[i + 0x120] = 0x47;
    }
}
