#include "global.h"
#include "variables.h"


void sub_0833E110(u32 a, u32 b, u32 c)
{
    u8 t;

    t = gModule_GameMode[0] - 3;
    if (t > 1)
    {
        gModule_TrackRecordMs[gModule_TrackId] = c;
        gModule_TrackRecordSec[gModule_TrackId] = b;
        gModule_TrackRecordMin[gModule_TrackId] = a;
    }
}
