#include "global.h"

extern u8 gUnk_0202CBC8[];

u8 sub_080079AC(void)
{
    u8 i;

    for (i = 1; i != 8; i++) {
        if (gUnk_0202CBC8[i] == 0)
            return i;
    }
    return 0x63;
}
