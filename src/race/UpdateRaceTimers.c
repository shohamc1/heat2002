#include "global.h"
#include "variables.h"

extern u32 gUnk_0202A6BC[];
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
