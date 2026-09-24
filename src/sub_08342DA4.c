#include "global.h"

void sub_0833FFA8(u32 a);
void sub_0833FF84(u32 a);

void sub_08342DA4(u32 a)
{
    if (--*(u32 *)(a + 0x18) == 0)
    {
        sub_0833FFA8(a);
        sub_0833FF84(a);
    }
}
