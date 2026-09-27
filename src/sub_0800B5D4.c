#include "global.h"
#include "functions.h"


void sub_0800B5D4(u32 a)
{
    if (--*(u32 *)(a + 0x18) == 0)
    {
        RemoveTask(a);
        FreeTask(a);
    }
}
