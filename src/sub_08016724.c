#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
extern u16 gSeasonSaveData[];
void LoadSeason(void)
{
    struct Car *q;
    u16 *p;
    u32 t;
    s32 i;
    StopAllSongsAndVSyncOff();
    ReadSaveBlocks(0x40, 0xF0);
    p = gSeasonSaveData;
    (*(u8 *)&gSeasonRaceIndex) = *p++;
    gQualifyingDone = *p >> 8;
    gPracticeDone = *p++;
    gSeasonRaceIncomplete = *p++;
    gChampionshipIndex = *p++;
    q = gCars;
    i = 0;
    do {
        q->driverId = *p++;
        q->points = *p++;
        q->finishTime = (*p++ << 16);
        q->finishTime |= *p++;
        i++;
        q++;
    } while (i != 0x18);
    i = 0;
    do {
        gChampionshipAvailable[i] = *p++;
        i++;
    } while (i != 0x11);
    gSeasonNumLaps = *p;
    sub_080100B0();
}
