#include "global.h"
#include "variables.h"


void SetTrackRecord(u32 a, u32 b, u32 c)
{
    if ((u8)(gGameMode[0] - 3) <= 1)
        return;
    gTrackRecordMs[gTrackId] = c;
    gTrackRecordSec[gTrackId] = b;
    gTrackRecordMin[gTrackId] = a;
}
