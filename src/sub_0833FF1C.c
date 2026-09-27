#include "global.h"

extern u32 gUnk_0203C380;
extern u8 gUnk_0203C340[];

void sub_0833FF1C(void)
{
    u32 i;
    for (i = 0; i != 0x40; i++)
        gUnk_0203C340[i] = 0;
    gUnk_0203C380 = 0;
}
