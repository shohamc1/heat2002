#include "global.h"
#include "car.h"
#include "variables.h"

#include "functions.h"
#include "data.h"
extern u8 gText_Timer[];
extern u8 gText_MPH[];
extern u8 gText_BlankRow8[];
extern u8 gText_BlankRow12_2[];
extern u8 gChallengeEndDelay;

u8 IsProgressPointCrossed(s32 point)
{
    if ((*(s32 *)&gUnk_0202CB14) > point)
        return 0;
    if ((((volatile struct Car *)gCars)[0].progress & 0xFFFF) < (u32)point)
        return 0;
    return 1;
}

u32 IsChallengeTimeWithin(s32 limitMs)
{
    if ((*(s32 *)&gChallengeTimerSec) * 1000 + (*(s32 *)&gChallengeTimerMs) <= limitMs)
        return 1;
    return 0;
}

void DrawChallengeTimer(void)
{
    u32 tilemap;
    u32 *dest;

    tilemap = *(u32 *)&gTextLayerMapPtr;
    dest = tilemap + 0x250;
    DrawTextAt(gText_Timer, 8, 8);
    /* DrawBigDigit: this file's old prototype took (u32 *, u32); the matched definition takes (u16 *, u8); call through
     * a function pointer with the old signature. */
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, 0);
    dest = tilemap + 0x254;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, (*(s32 *)&gUnk_0202CAE4));
    dest = tilemap + 0x25A;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, (*(s32 *)&gChallengeTimerSec) / 10);
    dest = tilemap + 0x25E;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, (*(s32 *)&gChallengeTimerSec) % 10);
    dest = tilemap + 0x264;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, (*(s32 *)&gChallengeTimerMs) / 100 % 10);
    dest = tilemap + 0x268;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, (*(s32 *)&gChallengeTimerMs) / 10 % 10);
}

void DrawChallengeSpeed(s32 mph)
{
    u32 *tilemap;
    u32 *dest;
    u32 label;

    tilemap = (u32 *)*(u32 *)&gTextLayerMapPtr;
    dest = tilemap + 0xE5;
    /* DrawBigDigit: this file's old prototype took (u32 *, u32); the matched definition takes (u16 *, u8); call through
     * a function pointer with the old signature. */
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, mph / 100 % 10);
    dest = tilemap + 0xE6;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, mph / 10 % 10);
    dest = tilemap + 0xE7;
    ((void (*)(u32 *, u32))DrawBigDigit)(dest, mph % 10);
    label = (u32)gText_MPH;
    DrawTextAt(label, 0x10, 0x0F);
}

void ClearChallengeSpeed(void)
{
    DrawTextAt(gText_BlankRow8, 0x0A, 0x0E);
    DrawTextAt(gText_BlankRow12_2, 0x0A, 0x0F);
}

void UpdateChallengeTimer(void)
{
    u32 ms;
    s32 val;

    ms = gChallengeTimerMs;
    gChallengeTimerMs = ms + 0x28;
    val = ms + 0x28;
    if (val > 0x3E7) {
        gChallengeTimerMs = ms - 0x3C0;
        gChallengeTimerSec = gChallengeTimerSec + 1;
        val = gChallengeTimerSec;
        if (val > 0x3B) {
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

    if (gGameMode[0] == 0x10) {
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
                            /* IsChallengeTimeWithin: this file's old prototype returns u8; the matched definition
                             * returns u32 */
                            if (((u8 (*)(u32))IsChallengeTimeWithin)(0x2328))
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
                            if (((u8 (*)(u32))IsChallengeTimeWithin)(0xFA0))
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
                if (speed > (*(s32 *)&gChallengeBestValue))
                    (*(s32 *)&gChallengeBestValue) = speed;
                if ((*(s32 *)&gChallengeBestValue) > 0x76) {
                    gChallengeResult = 1;
                    EndRace();
                }
                if ((*(s32 *)&gChallengeBestValue) > 0x79) {
                    if (gChallengeEndDelay & 8)
                        DrawChallengeSpeed((*(s32 *)&gChallengeBestValue));
                    else
                        ClearChallengeSpeed();
                    gChallengeEndDelay++;
                    if (gChallengeEndDelay > 0x40)
                        EndRace();
                } else if ((*(s32 *)&gChallengeBestValue) != 0) {
                    DrawChallengeSpeed(speed);
                }
                break;
        }
        gUnk_0202CB14 = gCars[0].progress & 0xFFFF;
    }
}
