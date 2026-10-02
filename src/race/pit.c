#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

u8 FindFreePitStall(u8 unused)
{
    u8 i;

    for (i = 1; i != 8; i++) {
        if (gPitStallOccupied[i] == 0)
            return i;
    }
    return 0x63;
}

u8 CarNeedsPit(struct Car *a1)
{
    u8 ret;

    if (a1 != gCars) {
        ret = 0;
        if (a1->fuel <= 0x2800)
            ret = 1;
        if (a1->tireWear0 > 0x3E7FF || a1->tireWear1 > 0x3E7FF || a1->tireWear2 > 0x3E7FF || a1->tireWear3 > 0x3E7FF)
            ret = 1;
    } else {
        ret = 0;
        if (a1->fuel <= 0x2800)
            ret = 1;
        if (a1->tireWear0 > 0x5DBFF || a1->tireWear1 > 0x5DBFF || a1->tireWear2 > 0x5DBFF || a1->tireWear3 > 0x5DBFF)
            ret = 1;
    }
    return ret;
}
