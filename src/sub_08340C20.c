#include "global.h"
#include "functions.h"
#include "car.h"



void sub_08340C20(void)
{
    u8 v;
    u32 i;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x5; i++)
    {
        if (gModule_Cars[i].driverId != 99)
            continue;
        for (;;)
        {
            v = 0x1F & sub_0833BCBC();
            if (v > 0x1D)
                continue;
            dup = 0;
            j = 0;
            do
            {
                if (v == gModule_Cars[j].driverId)
                    dup = 1;
                j++;
            } while (j != 0x5);
            if (dup != 0)
                continue;
            break;
        }
        gModule_Cars[i].driverId = v;
    }
}
