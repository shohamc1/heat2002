#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

/* car.h types 0x4C as u8 lap, but this function's load is a signed ldrsb
   (its old local view typed the field s8). Reach it through this view so
   the offset stays inside the MEM like a plain component access. */
struct CarLapS8
{
    u8 pad[0x4C];
    s8 lap;
};

u32 ComputeProgressDistance(s32 progress, u8 trackId)
{
    u32 lapDistance = progress & 0xFFFF;
    return (progress >> 16) * gTrackLapLengths[trackId] + lapDistance;
}

void FinishAllCars(u8 recomposeTimes)
{
    struct Car *car;
    s32 i;
    s32 refDistance;
    u32 refTime;
    u32 msPerUnit;
    u32 finishTime;
    if (recomposeTimes != 0) {
        car = gCars;
        i = 0;
        do {
            if (car->finished != 0)
                car->finishTime = car->finishMin * 60000 + car->finishSec * 1000 + car->finishMs;
            i++;
            car++;
        } while (i != 0x18);
    }
    refDistance = ((struct CarLapS8 *)gCars)->lap * gTrackLapLengths[gTrackId];
    refTime = gCars[0].finishTime;
    msPerUnit = sub_08017230(refTime, refDistance);
    car = gCars;
    i = 0;
    do {
        if (car->finished == 0) {
            finishTime = msPerUnit * (refDistance - ComputeProgressDistance(car->progress, gTrackId)) + refTime;
            car->finishTime = finishTime;
            car->finished = 1;
        }
        i++;
        car++;
    } while (i != 0x18);
}
