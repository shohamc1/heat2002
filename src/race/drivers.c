#include "global.h"
#include "functions.h"
#include "car.h"

void AssignRandomDrivers(void)
{
    u32 i;
    u8 v;
    u8 dup;
    u8 j;

    for (i = 1; i != 24; i++)
        gCars[i].driverId = 99;
    i = 1;
    for (;;) {
        v = 0x1F & Random8();
        if (v > 29)
            continue;
        dup = 0;
        j = 0;
        do {
            if (v == gCars[j].driverId)
                dup = 1;
            j++;
        } while (j != 24);
        if (dup != 0)
            continue;
        gCars[i].driverId = v;
        i++;
        if (i == 24)
            break;
    }
}

void FillUnassignedDrivers(void)
{
    u8 v;
    u32 i;
    u8 dup;
    u8 j;

    for (i = 1; i != 24; i++) {
        if (gCars[i].driverId != 99)
            continue;
        for (;;) {
            v = 0x1F & Random8();
            if (v > 29)
                continue;
            dup = 0;
            j = 0;
            do {
                if (v == gCars[j].driverId)
                    dup = 1;
                j++;
            } while (j != 24);
            if (dup != 0)
                continue;
            break;
        }
        gCars[i].driverId = v;
    }
}
