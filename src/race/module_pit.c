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

    if (car != (u32)gModule_Cars)
    {
        ret = 0;
        if (*(s32 *)(car + 0x9C) <= 0xA0 << 6)
            ret = 1;
        tireWear = *(s32 *)(car + 0x8C);
        wearLimit = 0x3E7FF;
    }
    else
    {
        ret = 0;
        if (*(s32 *)(car + 0x9C) <= 0xA0 << 6)
            ret = 1;
        tireWear = *(s32 *)(car + 0x8C);
        wearLimit = 0x5DBFF;
    }
    if (tireWear > wearLimit
        || *(s32 *)(car + 0x90) > wearLimit
        || *(s32 *)(car + 0x94) > wearLimit
        || *(s32 *)(car + 0x98) > wearLimit)
        ret = 1;
    return ret;
}

