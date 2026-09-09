#include "global.h"

extern u32 gUnk_0203DD60[];

void sub_08340EE0(void)
{
    u32 i;
    for (i = 0; i != 13; i = (u8)(i + 1))
        gUnk_0203DD60[i] = 0;
}
