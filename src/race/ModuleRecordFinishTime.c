#include "global.h"
#include "variables.h"

void ModuleRecordFinishTime(u16 *car)
{
    u16 *finishWords = car;
    u16 time = gModule_RaceMin[0];
    u32 idx = 0x82;

    finishWords[idx] = time;
    time = gModule_RaceSec[0];
    idx += 1;
    finishWords[idx] = time;
    time = gModule_RaceMs[0];
    idx += 1;
    finishWords[idx] = time;
    *(u8 *)((u32)car + 0x7D) = 1;
}
