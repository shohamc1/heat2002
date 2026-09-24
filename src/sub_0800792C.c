#include "global.h"

extern u8 gUnk_02025ED0[];

void FreeTask(u32 p)
{
    gUnk_02025ED0[*(u32 *)(p + 0x3C)] = 0;
}
