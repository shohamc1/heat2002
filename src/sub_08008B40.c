#include "global.h"
#include "car.h"
#include "variables.h"


u8 sub_08008B40(s32 v)
{
    if ((*(s32 *)&gUnk_0202CB14) > v)
        return 0;
    if ((((volatile struct Car *)gCars)[0].progress & 0xFFFF) < (u32)v)
        return 0;
    return 1;
}
