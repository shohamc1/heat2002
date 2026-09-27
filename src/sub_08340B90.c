#include "global.h"
#include "functions.h"
#include "car.h"



void sub_08340B90(void)
{
    u32 i;
    u8 v;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x5; i++)
        gModule_Cars[i].driverId = 99;
    i = 1;
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
        gModule_Cars[i].driverId = v;
        i++;
        if (i == 0x5)
            break;
    }
}
