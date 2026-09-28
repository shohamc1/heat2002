#include "global.h"
#include "variables.h"
#include "car.h"
#include "data.h"


void UpdateRaceTimers(void);
void DrawTime(u16 *dest, s32 a, s32 b, s32 c);
void DrawSpeedNeedle(u32 a1);
void DrawRacePosition(s32 arg);
void DrawLapCounter(s32 a, s32 b);
void DrawLowFuelWarning(s32 arg);
void DrawTireWear(struct Car *p);
void DrawPitStopWarning(struct Car *p);
void DummyHudHook(struct Car *p);
void UpdateTrackCues(struct Car *p);

void UpdateRaceHud(void)
{
    struct Car *car;
    u16 *dest;
    s32 v;

    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId[0]];
    else
        car = &gCars[0];
    UpdateRaceTimers();
    dest = (u16 *)(gTextLayerMapPtr[0] + 0x4C6);
    DrawTime(dest, gLapMin[0], gLapSec[0], gLapMs[0]);
    if (gGameMode[0] == 0x0E || gGameMode[0] == 0x02) {
        dest = (u16 *)(gTextLayerMapPtr[0] + 0x486);
        if (gIsTimeTrial != 0)
            DrawTime(dest,
                         gTrackRecordMin[gTrackId],
                         gTrackRecordSec[gTrackId],
                         gTrackRecordMs[gTrackId]);
    }
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    DrawSpeedNeedle(v);
    if (gGameMode[0] != 2 && gGameMode[0] != 0x0E) {
        DrawRacePosition(car->racePosition + 1);
        if (car->lapStartedFlag != 0 || (u8)(gGameMode[0] - 3) <= 1)
            DrawLapCounter((*(s8 *)&car->lap) + 1, gNumLaps);
        else
            DrawLapCounter(999, gNumLaps);
        DrawLowFuelWarning((*(u32 *)&car->fuel) << 8);
        DrawTireWear(car);
        DrawPitStopWarning(car);
        DummyHudHook(car);
    }
    UpdateTrackCues(car);
}
