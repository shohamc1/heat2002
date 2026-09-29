#include "global.h"
#include "variables.h"
#include "car.h"

void RecordFinishTime(struct Car *obj)
{
    obj->finishMin = gRaceMin;
    obj->finishSec = gRaceSec;
    obj->finishMs = gRaceMs;
    obj->finished = 1;
}
