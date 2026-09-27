#include "global.h"
#include "variables.h"


void FreeTask(u32 p)
{
    gUnk_02025ED0[*(u32 *)(p + 0x3C)] = 0;
}
