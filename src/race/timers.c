#include "global.h"
#include "variables.h"

void ResetLapTimer(void)
{
    gLapMs[0] = 0;
    gLapSec[0] = 0;
    gLapMin[0] = 0;
}

void ResetRaceTimer(void)
{
    gRaceMs = 0;
    gRaceSec = 0;
    gRaceMin = 0;
}
