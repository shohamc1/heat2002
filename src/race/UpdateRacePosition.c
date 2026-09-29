#include "global.h"
#include "variables.h"
#include "car.h"

void UpdateRacePosition(u8 idx)
{
    u8 n = gNumCars[0];
    u8 count;
    s32 threshold;
    u32 j;

    if (gIsLinkRace != 0)
        n = gNumLinkPlayers[0];
    count = 0;
    threshold = gCars[idx].progress;
    for (j = 0; j != n; j++) {
        if (j != idx && gCars[j].progress > threshold)
            count++;
    }
    gCars[idx].racePosition = count;
}
