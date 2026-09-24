#include "global.h"

void sub_08007950(u32 a);
void sub_0800792C(u32 a);

void sub_0800B5D4(u32 a)
{
    if (--*(u32 *)(a + 0x18) == 0)
    {
        sub_08007950(a);
        sub_0800792C(a);
    }
}
