#include "global.h"
#include "variables.h"


void RemoveTask(u32 p)
{
    u32 next;
    u32 prev;

    next = *(u32 *)(p + 0x14);
    prev = *(u32 *)(p + 0x10);
    if (prev != 0)
    {
        *(u32 *)(prev + 0x14) = next;
    }
    else
    {
        gUnk_02025FD0 = next;
    }
    if (next != 0)
    {
        *(u32 *)(next + 0x10) = prev;
    }
}
