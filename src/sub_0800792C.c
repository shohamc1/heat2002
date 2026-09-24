#include "global.h"

extern u8 gUnk_02025ED0[];

void sub_0800792C(u32 p)
{
    gUnk_02025ED0[*(u32 *)(p + 0x3C)] = 0;
}
