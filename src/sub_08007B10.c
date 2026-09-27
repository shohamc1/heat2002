#include "global.h"
#include "variables.h"


u32 sub_08007B10(u32 ptr)
{
    u32 *p = gCarOrder;
    u8 i;

    for (i = 0; i != 0x18; i++, p++) {
        if (*p == ptr)
            return i;
    }
    return 0x18;
}
