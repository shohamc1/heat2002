#include "global.h"
#include "variables.h"
#include "car.h"

u8 ModuleFindFreePitStall(void)
{
    u8 i;

    for (i = 1; i != 8; i++) {
        if (gUnk_0203DDE8[i] == 0)
            return i;
    }
    return 0x63;
}

u32 ModuleCarNeedsPit(u32 car)
{
    s32 ret;
    s32 tireWear;
    s32 wearLimit;

    if (car != (u32)gModule_Cars) {
        ret = 0;
        if (((struct Car *)car)->fuel <= 0xA0 << 6)
            ret = 1;
        tireWear = ((struct Car *)car)->tireWear0;
        wearLimit = 0x3E7FF;
    } else {
        ret = 0;
        if (((struct Car *)car)->fuel <= 0xA0 << 6)
            ret = 1;
        tireWear = ((struct Car *)car)->tireWear0;
        wearLimit = 0x5DBFF;
    }
    if (tireWear > wearLimit || ((struct Car *)car)->tireWear1 > wearLimit || ((struct Car *)car)->tireWear2 > wearLimit ||
        ((struct Car *)car)->tireWear3 > wearLimit)
        ret = 1;
    return ret;
}
