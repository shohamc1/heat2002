#include "global.h"
#include "variables.h"


void sub_0833E110(u32 a, u32 b, u32 c);
void sub_08342D64(void);

void sub_0833E160(u16 a, u16 b, u16 c)
{
    s32 total;
    s32 best;

    total = a * 60000 + b * 1000 + c;
    best = 60000 * gModule_TrackRecordMin[gModule_TrackId] + gModule_TrackRecordSec[gModule_TrackId] * 1000 + gModule_TrackRecordMs[gModule_TrackId];
    if (total > best)
        return;
    if ((u8)(gModule_GameMode[0] - 3) <= 1)
        return;
    sub_0833E110(a, b, c);
    gUnk_02039100 = 1;
    sub_08342D64();
}
