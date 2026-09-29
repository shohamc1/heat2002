#include "global.h"
#include "variables.h"

void ModuleSetTrackRecord(u32 a, u32 b, u32 c);
void ModuleAddTrackRecordTasks(void);
extern u32 gUnk_0203D68C[];

void ModuleSetTrackRecord(u32 min, u32 sec, u32 ms)
{
    u8 modeMinus3;

    modeMinus3 = gModule_GameMode[0] - 3;
    if (modeMinus3 > 1) {
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
    best = 60000 * gModule_TrackRecordMin[gModule_TrackId] + gModule_TrackRecordSec[gModule_TrackId] * 1000 +
           gModule_TrackRecordMs[gModule_TrackId];
    if (total > best)
        return;
    if ((u8)(gModule_GameMode[0] - 3) <= 1)
        return;
    ModuleSetTrackRecord(min, sec, ms);
    gUnk_02039100 = 1;
    ModuleAddTrackRecordTasks();
}

void ModuleUpdateRaceTimers(void)
{
    u16 *p2;
    u16 *p1;
    u8 i;
    u8 v8;
    do {
        if (gModule_RaceStarted == 0) {
            return;
        }
        if (gModule_RaceEndState != 0) {
            return;
        }
        v8 = gModule_GameMode[0] - 3;
        p1 = &gModule_LapMs[0];
        p2 = &gModule_RaceMs[0];
        if (v8 <= 2) {
            for (i = 0; i != gModule_NumLinkPlayers[0]; i++) {
                gUnk_0203D68C[i * 100] = gUnk_0203D68C[i * 100] + 1;
            }
        }
        *p1 += 40;
    } while (0);
    if ((*p1) > 999) {
        *p1 -= 1000;
        gModule_LapSec[0] = gModule_LapSec[0] + 1;
        if (gModule_LapSec[0] > 59) {
            gModule_LapSec[0] = gModule_LapSec[0] - 60;
            gModule_LapMin[0] = gModule_LapMin[0] + 1;
        }
    }
    *p2 += 40;
    if ((*p2) > 999) {
        *p2 -= 1000;
        gModule_RaceSec[0] = gModule_RaceSec[0] + 1;
        if (gModule_RaceSec[0] > 59) {
            gModule_RaceSec[0] = gModule_RaceSec[0] - 60;
            gModule_RaceMin[0] = gModule_RaceMin[0] + 1;
        }
    }
}
