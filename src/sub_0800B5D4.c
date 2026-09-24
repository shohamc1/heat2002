#include "global.h"

void RemoveTask(u32 a);
void FreeTask(u32 a);

void sub_0800B5D4(u32 a)
{
    if (--*(u32 *)(a + 0x18) == 0)
    {
        RemoveTask(a);
        FreeTask(a);
    }
}
