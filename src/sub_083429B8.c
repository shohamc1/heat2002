#include "global.h"
#include "functions.h"
#include "variables.h"


void sub_0833EE88(u8 *str, u32 y, u32 z);

void sub_083429B8(u32 a)
{
    if (++*(u32 *)(a + 0x18) == 0x30)
    {
        sub_0833FFA8(a);
        sub_0833FF84(a);
    }
    sub_0833EE88(gUnk_0200D118, 8, 1);
}
