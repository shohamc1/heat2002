#include "global.h"
#include "variables.h"

struct Unk0800A438 {
    u8 pad0[0x7D];
    u8 unk7D;
    u8 pad7E[0x104 - 0x7E];
    u16 finishMin;
    u16 finishSec;
    u16 finishMs;
};


void RecordFinishTime(struct Unk0800A438 *obj)
{
    obj->finishMin = gUnk_02025260;
    obj->finishSec = gUnk_02025220;
    obj->finishMs = gUnk_02025224;
    obj->unk7D = 1;
}
