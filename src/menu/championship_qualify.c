#include "global.h"
#include "functions.h"
#include "variables.h"

extern const u8 *const gChampionshipRetainTexts[];
#include "data.h"
#include "m4a.h"
#include "car.h"
extern u32 gChampionshipQualifyLapTimeTargets[];
extern u8 gChampionshipTrackIds[];

void DrawChampionshipQualifyResult(s8 passed)
{
    GetString(0x14);
    /* DrawBigText: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(void))DrawBigText)();
    if (passed != 0) {
        DrawText(GetString(0x17), 0, 9, 1);
        DrawText(GetString(0x18), 0, 0xA, 1);
        DrawText(GetString(0x19), 0, 0xB, 1);
        DrawText(gChampionshipRetainTexts[gChampionshipIndex], 0, 0xD, 1);
    } else {
        DrawText(GetString(0x15), 0, 0xD, 1);
        DrawText(GetString(0x16), 0, 0xE, 1);
    }
}

void ShowChampionshipQualifyResult(s8 passed)
{
    void *src;
    u8 palette[0x200];
    s8 done;

    ZeroTextLayer();
    LoadResultsScreenBackdrop();
    src = gResultsScreenPalette;
    BuildScreenPalette((u32)src, (u16 *)palette);
    /* DrawChampionshipQualifyResult: this file's old prototype took u8; the matched definition takes s8 */
    ((void (*)(u8))DrawChampionshipQualifyResult)(passed);
    FadeToBrightenedPalette((u32)palette, 0x0F);
    done = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8))DrawChampionshipQualifyResult)(passed);
        if (gKeysPressed & 1)
            done = passed;
        WaitForVBlank();
    } while (done == 0x40);
    FadeToColor(0, 0x0F);
}

u8 RunChampionshipQualifyTest(void)
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
    /* RunRace: the ROM caller passes a third argument the matched definition drops; call
       through a function pointer with the old prototype. */
    ((u8 (*)(u8, u8, void *))RunRace)(0, 0x0D, raceArg);
    if (gOptions[2] != 0)
        m4aSongNumStart(3);
    ResetBgScroll();
    /* The cast is load-bearing: a direct u8 argument to the s8 parameter
       makes agbcc emit a sign extension the ROM does not have. */
    ((void (*)(u8))ShowChampionshipQualifyResult)(gChallengeResult);
    return gChallengeResult;
}
