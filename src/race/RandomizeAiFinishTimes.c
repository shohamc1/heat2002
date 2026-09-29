#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
extern const struct AiFinishTimeRange gTrackAiFinishTimeRanges[];
void RandomizeAiFinishTimes(void)
{
    u32 minTime = gTrackAiFinishTimeRanges[gTrackId].min;
    u32 maxTime = gTrackAiFinishTimeRanges[gTrackId].max;
    struct Car *car = (struct Car *)gAiCars;
    s32 i = 0;
    do {
        car->finishTime = RandomInRange(minTime, maxTime);
        i++;
        car++;
    } while (i != 0x17);
}
