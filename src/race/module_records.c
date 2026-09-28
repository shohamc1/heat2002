#include "global.h"
#include "variables.h"

void ModuleSetTrackRecord(u32 a, u32 b, u32 c);
void ModuleAddTrackRecordTasks(void);


void ModuleSetTrackRecord(u32 min, u32 sec, u32 ms)
{
    u8 modeMinus3;

    modeMinus3 = gModule_GameMode[0] - 3;
    if (modeMinus3 > 1)
    {
        gModule_TrackRecordMs[gModule_TrackId] = ms;
        gModule_TrackRecordSec[gModule_TrackId] = sec;
        gModule_TrackRecordMin[gModule_TrackId] = min;
    }
}


void ModuleCheckTrackRecord(u16 min, u16 sec, u16 ms)
{
    s32 total;
    s32 best;

    total = min * 60000 + sec * 1000 + ms;
    best = 60000 * gModule_TrackRecordMin[gModule_TrackId] + gModule_TrackRecordSec[gModule_TrackId] * 1000 + gModule_TrackRecordMs[gModule_TrackId];
    if (total > best)
        return;
    if ((u8)(gModule_GameMode[0] - 3) <= 1)
        return;
    ModuleSetTrackRecord(min, sec, ms);
    gUnk_02039100 = 1;
    ModuleAddTrackRecordTasks();
}

