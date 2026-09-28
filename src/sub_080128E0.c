#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

extern u32 gChampionshipQualifyLapTimeTargets[];
extern u8 gChampionshipTrackIds[];


u8 sub_080128E0(void)
{
    u8 *p;

    gNumLaps = 2;
    gUnk_0202ED84 = gChampionshipQualifyLapTimeTargets[gChampionshipIndex];
    gTrackId = gChampionshipTrackIds[gChampionshipIndex];
    gChallengeResult = 0;
    gCars[0].finishTime = 0;
    gCars[0].finished = 1;
    AssignRandomDrivers();
    sub_08016D28(1);
    SortCarsByTime();
    TrackSelectMenu(0, gTrackId);
    p = gUnk_0202CDA8;
    /* RunRace: the ROM caller passes a third argument the matched definition drops; call
       through a function pointer with the old prototype. */
    ((u8 (*)(u8, u8, void *))RunRace)(0, 0x0D, p);
    if (gOptions[2] != 0)
        m4aSongNumStart(3);
    ResetBgScroll();
    /* The cast is load-bearing: a direct u8 argument to the s8 parameter
       makes agbcc emit a sign extension the ROM does not have. */
    ((void (*)(u8))sub_08012874)(gChallengeResult);
    return gChallengeResult;
}
