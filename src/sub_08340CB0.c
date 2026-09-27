#include "global.h"
#include "car.h"
#include "variables.h"


u8 sub_08340CB0(s32 v)
{
    if ((*(s32 *)&gUnk_0203DD34) > v)
        return 0;
    if ((gModule_Cars[0].progress & 0xFFFF) < (u32)v)
        return 0;
    return 1;
}
