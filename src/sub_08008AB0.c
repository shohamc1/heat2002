#include "global.h"
#include "functions.h"
#include "car.h"


void FillUnassignedDrivers(void)
{
    u8 v;
    u32 i;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x18; i++)
    {
        if (gCars[i].driverId != 99)
            continue;
        for (;;)
        {
            v = 0x1F & Random8();
            if (v > 0x1D)
                continue;
            dup = 0;
            j = 0;
            do
            {
                if (v == gCars[j].driverId)
                    dup = 1;
                j++;
            } while (j != 0x18);
            if (dup != 0)
                continue;
            break;
        }
        gCars[i].driverId = v;
    }
}
