#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

u8 ModuleFindFreePitStall(u8 unused)
{
    u8 i;

    for (i = 1; i != 8; i++) {
        if (gUnk_0203DDE8[i] == 0)
            return i;
    }
    return 0x63;
}

u8 ModuleCarNeedsPit(struct Car *car)
{
    s32 ret;
    s32 tireWear;
    s32 wearLimit;

    if (car != gModule_Cars) {
        ret = 0;
        if (car->fuel <= 160 << 6)
            ret = 1;
        tireWear = car->tireWear0;
        wearLimit = 0x3E7FF;
    } else {
        ret = 0;
        if (car->fuel <= 160 << 6)
            ret = 1;
        tireWear = car->tireWear0;
        wearLimit = 0x5DBFF;
    }
    if (tireWear > wearLimit || car->tireWear1 > wearLimit || car->tireWear2 > wearLimit || car->tireWear3 > wearLimit)
        ret = 1;
    return ret;
}
