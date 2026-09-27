#include "global.h"
#include "variables.h"


void sub_08008D70(void)
{
    u8 i;

    i = 0;
    do {
        gWaypointSpeedSamples[i] = 0;
        i++;
    } while (i != 13);
}
