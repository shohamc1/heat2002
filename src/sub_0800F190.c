#include "global.h"
#include "variables.h"


u32 sub_0800F190(void)
{
    u8 i;

    for (i = 0; i != 0x11; i++) {
        if (gChampionshipAvailable[i] != 0)
            return 1;
    }
    return 0;
}
