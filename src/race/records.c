#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "car.h"
#include "functions.h"

void SetTrackRecord(u32 a, u32 b, u32 c);

void SetTrackRecord(u32 a, u32 b, u32 c)
{
    if ((u8)(gGameMode - 3) <= 1)
        return;
    gTrackRecordMs[gTrackId] = c;
    gTrackRecordSec[gTrackId] = b;
    gTrackRecordMin[gTrackId] = a;
}

void CheckTrackRecord(u16 a1, u16 a2, u16 a3)
{
    if (a1 * 60000 + a2 * 1000 + a3 <=
        gTrackRecordMin[gTrackId] * 60000 + gTrackRecordSec[gTrackId] * 1000 + gTrackRecordMs[gTrackId]) {
        if (gGameMode == 3 || gGameMode == 4)
            return;
        SetTrackRecord(a1, a2, a3);
        gNewTrackRecord = 1;
        AddTrackRecordTasks();
    }
}

void UpdateRaceTimers(void)
{
    u16 *p2;
    u16 *p1;
    u8 i;
    u8 v8;
    do {
        if (gRaceStarted == 0) {
            return;
        }
        if (gRaceEndState != 0) {
            return;
        }
        v8 = gGameMode - 3;
        p1 = &gLapMs;
        p2 = &gRaceMs;
        if (v8 <= 2) {
            for (i = 0; i != gNumLinkPlayers[0]; i++) {
                gCars[i].finishTime = gCars[i].finishTime + 1;
            }
        }
        *p1 += 40;
    } while (0);
    if ((*p1) > 999) {
        *p1 -= 1000;
        gLapSec = gLapSec + 1;
        if (gLapSec > 59) {
            gLapSec = gLapSec - 60;
            gLapMin = gLapMin + 1;
        }
    }
    *p2 += 40;
    if ((*p2) > 999) {
        *p2 -= 1000;
        gRaceSec = gRaceSec + 1;
        if (gRaceSec > 59) {
            gRaceSec = gRaceSec - 60;
            gRaceMin = gRaceMin + 1;
        }
    }
}
