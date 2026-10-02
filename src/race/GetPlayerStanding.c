#include "global.h"
#include "functions.h"
#include "car.h"
#include "variables.h"

u32 GetPlayerStanding(void)
{
    u32 i;
    for (i = 0; i != 24; i = (u8)(i + 1)) {
        if (gCarOrder[i] == gCars)
            return i;
    }
    return 0x17;
}
