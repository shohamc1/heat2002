#include "global.h"
#include "functions.h"

struct Unk0202A550
{
    u8 filler0[0x162];
    u8 driverId;
    u8 filler163[400 - 0x163];
};

extern struct Unk0202A550 gCars[];


void AssignRandomDrivers(void)
{
    u32 i;
    u8 v;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x18; i++)
        gCars[i].driverId = 99;
    i = 1;
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
        gCars[i].driverId = v;
        i++;
        if (i == 0x18)
            break;
    }
}
