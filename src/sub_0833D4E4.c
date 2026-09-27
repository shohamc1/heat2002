#include "global.h"
#define GBA_CPUSET sub_08344B64
#include "gba/compat.h"
#include "variables.h"


void sub_0833D4E4(void)
{
    if (gUnk_020392C0 != 0) {
        CpuSet(EWRAM_START + 0x3AAD0, PLTT, 0x80 << 1);
        gUnk_020392C0 = 0;
    }
}
