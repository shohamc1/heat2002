#include "global.h"
#include "gba/defines.h"
#include "car.h"
#include "variables.h"
#include "functions.h"
#include "data.h"

extern u8 gText_Timer[];
extern u8 gText_MPH[];
extern u8 gText_BlankRow8[];
extern u8 gText_BlankRow12_2[];

/*.bss_challenge places this buffer at 0x0202A3F0. It ends at 0x0202A510,
   where the car globals begin. */
EWRAM_DATA u32 gUnk_0202A3F0[0x48] = {0};
extern u8 gChallengeEndDelay;

u8 IsProgressPointCrossed(s32 point)
{
    if (gUnk_0202CB14 > point)
        return 0;
    if ((((volatile struct Car *)gCars)[0].progress & 0xFFFF) < (u32)point)
        return 0;
    return 1;
}

u8 IsChallengeTimeWithin(s32 limitMs)
{
    if (gChallengeTimerSec * 1000 + gChallengeTimerMs <= limitMs)
        return 1;
    return 0;
}

void DrawChallengeTimer(void)
{
    const u8 *tilemap;
    u32 *dest;

    tilemap = (const u8 *)gTextLayerMapPtr[0];
    dest = (u32 *)(tilemap + 0x250);
    DrawTextAt(gText_Timer, 8, 8);
    /* The calls pass the digit unnarrowed (DrawBigDigit narrows it to u8
       itself) and the destination as a u32 view. */
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, 0);
    dest = (u32 *)(tilemap + 0x254);
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, gUnk_0202CAE4);
    dest = (u32 *)(tilemap + 0x25A);
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, gChallengeTimerSec / 10);
    dest = (u32 *)(tilemap + 0x25E);
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, gChallengeTimerSec % 10);
    dest = (u32 *)(tilemap + 0x264);
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, gChallengeTimerMs / 100 % 10);
    dest = (u32 *)(tilemap + 0x268);
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, gChallengeTimerMs / 10 % 10);
}

void DrawChallengeSpeed(s32 mph)
{
    u32 *tilemap;
    u32 *dest;
    const u8 *label;

    tilemap = (u32 *)gTextLayerMapPtr[0];
    dest = tilemap + 0xE5;
    /* The calls pass the digit unnarrowed (DrawBigDigit narrows it to u8
       itself) and the destination as a u32 view. */
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, mph / 100 % 10);
    dest = tilemap + 0xE6;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, mph / 10 % 10);
    dest = tilemap + 0xE7;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, mph % 10);
    label = gText_MPH;
    DrawTextAt(label, 16, 15);
}

void ClearChallengeSpeed(void)
{
    DrawTextAt(gText_BlankRow8, 10, 14);
    DrawTextAt(gText_BlankRow12_2, 10, 15);
}

void UpdateChallengeTimer(void)
{
    u32 ms;
    s32 val;

    ms = gChallengeTimerMs;
    gChallengeTimerMs = ms + 0x28;
    val = ms + 0x28;
    if (val > 999) {
        gChallengeTimerMs = ms - 0x3C0;
        gChallengeTimerSec = gChallengeTimerSec + 1;
        val = gChallengeTimerSec;
        if (val > 59) {
            gChallengeTimerSec = gChallengeTimerSec - 0x3C;
            gUnk_0202CAE4 = gUnk_0202CAE4 + 1;
        }
    }
}

void ResetChallengeTimer(void)
{
    gChallengeTimerMs = 0;
    gChallengeTimerSec = 0;
    gUnk_0202CAE4 = 0;
}

s32 GetAverageWaypointSpeed(void)
{
    u8 i;
    u32 sample;
    u32 sum;

    sum = 0;
    for (i = 0; i != 13; i = (u8)(i + 1)) {
        sample = gWaypointSpeedSamples[i];
        sum += sample;
        if (sample == 0)
            return 0;
    }
    return sub_08017230(sum, 13) - 1;
}

void ClearWaypointSpeedSamples(void)
{
    u8 i;

    i = 0;
    do {
        gWaypointSpeedSamples[i] = 0;
        i++;
    } while (i != 13);
}

void UpdateChallenge(void)
{
    u8 phase;
    s32 speed;

    if (gGameMode == 16) {
        UpdateChallengeTimer();
        switch (gChallengeIndex) {
            case 0:
                phase = gChallengePhase;
                switch (phase) {
                    case 0:
                        if (IsProgressPointCrossed(0xDC)) {
                            gChallengePhase = 1;
                            ResetChallengeTimer();
                        }
                        break;
                    case 1:
                        if (IsProgressPointCrossed(0x15E)) {
                            if (IsChallengeTimeWithin(0x2328))
                                gChallengeResult = phase;
                            EndRace();
                            gChallengePhase = 0;
                        }
                        DrawChallengeTimer();
                        break;
                }
                break;
            case 1:
            case 2:
            case 3:
            case 5:
            case 6:
            case 7:
            case 8:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                break;
            case 4:
                phase = gChallengePhase;
                switch (phase) {
                    case 0:
                        if (IsProgressPointCrossed(0x55)) {
                            gChallengePhase = 1;
                            ResetChallengeTimer();
                        }
                        break;
                    case 1:
                        if (IsProgressPointCrossed(0x96)) {
                            if (IsChallengeTimeWithin(0xFA0))
                                gChallengeResult = phase;
                            EndRace();
                            gChallengePhase = 0;
                        }
                        DrawChallengeTimer();
                        break;
                }
                break;
            case 9:
                speed = GetAverageWaypointSpeed();
                if (speed < 0)
                    speed = 0;
                if (speed > gChallengeBestValue)
                    gChallengeBestValue = speed;
                if (gChallengeBestValue > 118) {
                    gChallengeResult = 1;
                    EndRace();
                }
                if (gChallengeBestValue > 121) {
                    if (gChallengeEndDelay & 8)
                        DrawChallengeSpeed(gChallengeBestValue);
                    else
                        ClearChallengeSpeed();
                    gChallengeEndDelay++;
                    if (gChallengeEndDelay > 0x40)
                        EndRace();
                } else if (gChallengeBestValue != 0) {
                    DrawChallengeSpeed(speed);
                }
                break;
        }
        gUnk_0202CB14 = gCars[0].progress & 0xFFFF;
    }
}
