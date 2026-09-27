#include "global.h"
#include "variables.h"


u8 FindFreePitStall(void)
{
    u8 i;

    for (i = 1; i != 8; i++) {
        if (gPitStallOccupied[i] == 0)
            return i;
    }
    return 0x63;
}
