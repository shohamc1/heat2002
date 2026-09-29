#include "global.h"
#include "variables.h"
#include "car.h"

void ModuleRecordFinishTime(struct Car *car)
{
    car->finishMin = gModule_RaceMin[0];
    car->finishSec = gModule_RaceSec[0];
    car->finishMs = gModule_RaceMs[0];
    car->finished = 1;
}
