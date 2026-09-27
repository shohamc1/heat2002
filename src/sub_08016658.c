#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u16 gSeasonSaveFlag[];

void SaveSeason(void)
{
    u16 *p;
    s32 i;
    struct Car *q;
    u32 t;

    StopAllSongsAndVSyncOff();
    p = gSeasonSaveFlag;
    *p = 1;
    p += 27;
    *p++ = (*(u8 *)&gSeasonRaceIndex);
    *p++ = (gQualifyingDone << 8) | gPracticeDone;
    *p++ = gSeasonRaceIncomplete;
    *p++ = gChampionshipIndex;
    q = gCars;
    i = 0;
    do {
        *p++ = q->driverId;
        *p++ = q->points;
        t = q->finishTime;
        *p++ = t >> 16;
        *p++ = t;
        i++;
        q++;
    } while (i != 0x18);
    i = 0;
    do {
        *p++ = gChampionshipAvailable[i];
        i++;
    } while (i != 0x11);
    *p = gSeasonNumLaps;
    WriteSaveBlocks(0x40, 0xF0);
    WriteSaveBlocks(8, 8);
    sub_080100B0();
}
