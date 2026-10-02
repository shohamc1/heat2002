#include "global.h"
#include "functions.h"
#include "car.h"

u32 AwardAllRacePoints(void)
{
    u8 i = 0;
    do {
        AwardRacePoints(&gCars[i], i);
        i++;
    } while (i != 24);
}
