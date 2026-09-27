#include "global.h"
#include "car.h"
#include "variables.h"


u32 sub_08012C20(void)
{
    u32 i;
    for (i = 0; i != 0x18; i = (u8)(i + 1)) {
        if (gCarOrder[i] == (u32)&gCars)
            return i;
    }
    return 0x17;
}
