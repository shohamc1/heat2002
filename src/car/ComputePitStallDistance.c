#include "global.h"
#include "variables.h"
#include "data.h"
#include "car.h"
#include "functions.h"

s32 ComputePitStallDistance(struct Car *car)
{
    s32 *stalls;
    s32 *stallZPtr;
    s32 stallIdx;
    s32 dx;
    s32 dz;
    s32 carX;
    s32 carZ;

    stalls = (s32 *)gPitStallPositions;
    stallIdx = gTrackId * 8 + car->pitStall;
    dx = stalls[stallIdx * 2];
    stallZPtr = (s32 *)((stallIdx * 2 + 1) * 4 + (u32)stalls);
    dz = *stallZPtr;
    carX = ((s16 *)&car->posX)[1]; /* high half of posX */
    carZ = ((s16 *)&car->posZ)[1]; /* high half of posZ */
    dx = dx - carX;
    if (dx < 0)
        dx = -dx;
    carZ = dz - carZ;
    if (carZ < 0)
        carZ = -carZ;
    if (dx > carZ)
        carZ = dx;
    return carZ;
}
