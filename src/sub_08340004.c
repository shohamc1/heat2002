#include "global.h"
#include "variables.h"


u8 sub_08340004(void)
{
    u8 i;

    for (i = 1; i != 8; i++) {
        if (gUnk_0203DDE8[i] == 0)
            return i;
    }
    return 0x63;
}
