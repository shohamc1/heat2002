#include "global.h"
#include "variables.h"

void SetTrackRecord(u32 a, u32 b, u32 c);
void AddTrackRecordTasks(void);
extern u32 gUnk_0202A6BC[];

void SetTrackRecord(u32 a, u32 b, u32 c)
{
    if ((u8)(gGameMode[0] - 3) <= 1)
        return;
    gTrackRecordMs[gTrackId] = c;
    gTrackRecordSec[gTrackId] = b;
    gTrackRecordMin[gTrackId] = a;
}

void CheckTrackRecord(u16 a1, u16 a2, u16 a3)
{
    if (a1 * 60000 + a2 * 1000 + a3 <=
        gTrackRecordMin[gTrackId] * 60000 + gTrackRecordSec[gTrackId] * 1000 + gTrackRecordMs[gTrackId]) {
        if (gGameMode[0] == 3 || gGameMode[0] == 4)
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
        v8 = gGameMode[0] - 3;
        p1 = &gLapMs[0];
        p2 = &gRaceMs;
        if (v8 <= 2) {
            for (i = 0; i != gNumLinkPlayers[0]; i++) {
                gUnk_0202A6BC[i * 100] = gUnk_0202A6BC[i * 100] + 1;
            }
        }
        *p1 += 40;
    } while (0);
    if ((*p1) > 999) {
        *p1 -= 1000;
        gLapSec[0] = gLapSec[0] + 1;
        if (gLapSec[0] > 59) {
            gLapSec[0] = gLapSec[0] - 60;
            gLapMin[0] = gLapMin[0] + 1;
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
