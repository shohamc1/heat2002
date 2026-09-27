#include "global.h"
#include "variables.h"


void AddTask(u32 r0)
{
    u32 r2 = gUnk_02025FD0;
    *(u32 *)(r0 + 0x14) = r2;
    *(u32 *)(r0 + 0x10) = 0;
    *(u32 *)(r2 + 0x10) = r0;
    gUnk_02025FD0 = r0;
}
