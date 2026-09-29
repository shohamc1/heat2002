#include "global.h"
#include "variables.h"

struct Unk0800A438
{
    u8 pad0[0x7D];
    u8 finished;
    u8 pad7E[0x104 - 0x7E];
    u16 finishMin;
    u16 finishSec;
    u16 finishMs;
};

void RecordFinishTime(struct Unk0800A438 *obj)
{
    obj->finishMin = gRaceMin;
    obj->finishSec = gRaceSec;
    obj->finishMs = gRaceMs;
    obj->finished = 1;
}
