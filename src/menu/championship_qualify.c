#include "global.h"
#include "functions.h"
#include "variables.h"
#include "data.h"
#include "m4a.h"
#include "car.h"

extern const u8 *const gChampionshipRetainTexts[];
extern u32 gChampionshipQualifyLapTimeTargets[];
extern u8 gChampionshipTrackIds[];

void DrawChampionshipQualifyResult(s8 passed)
{
    DrawBigText(GetString(20));
    if (passed != 0) {
        DrawText(GetString(23), 0, 9, 1);
        DrawText(GetString(24), 0, 10, 1);
        DrawText(GetString(25), 0, 11, 1);
        DrawText(gChampionshipRetainTexts[gChampionshipIndex], 0, 13, 1);
    } else {
        DrawText(GetString(21), 0, 13, 1);
        DrawText(GetString(22), 0, 14, 1);
    }
}

void ShowChampionshipQualifyResult(s8 passed)
{
    const void *src;
    u8 palette[0x200];
    s8 done;

    ZeroTextLayer();
    LoadResultsScreenBackdrop();
    src = gResultsScreenPalette;
    BuildScreenPalette(src, (u16 *)palette);
    /* Both calls pass passed as u8: a direct call to the s8 parameter would
       sign-extend it, which the ROM doesn't. */
    ((void (*)(u8))DrawChampionshipQualifyResult)(passed);
    FadeToBrightenedPalette(palette, 0x0F);
    done = 64;
    do {
        ReadKeys();
        ((void (*)(u8))DrawChampionshipQualifyResult)(passed);
        if (gKeysPressed & 1)
            done = passed;
        WaitForVBlank();
    } while (done == 0x40);
    FadeToColor(0, 0x0F);
}

u8 RunChampionshipQualifyTest(u8 unused)
{
    u8 *raceArg;

    gNumLaps = 2;
    gUnk_0202ED84 = gChampionshipQualifyLapTimeTargets[gChampionshipIndex];
    gTrackId = gChampionshipTrackIds[gChampionshipIndex];
    gChallengeResult = 0;
    gCars[0].finishTime = 0;
    gCars[0].finished = 1;
    AssignRandomDrivers();
    FinishAllCars(1);
    SortCarsByTime();
    TrackSelectMenu(0, gTrackId);
    raceArg = gUnk_0202CDA8;
    RunRace(0, 0x0D, raceArg);
    if (gOptions[2] != 0)
        m4aSongNumStart(3);
    ResetBgScroll();
    /* The cast is load-bearing: a direct u8 argument to the s8 parameter
       makes agbcc emit a sign extension the ROM does not have. */
    ((void (*)(u8))ShowChampionshipQualifyResult)(gChallengeResult);
    return gChallengeResult;
}
