#include "global.h"
#include "variables.h"
#include "car.h"
#include "data.h"

void UpdateRaceTimers(void);
void DrawTime(u32 a, u16 b, u16 c, u16 d);
void DrawSpeedNeedle(u32 a);
void DrawLowFuelWarning(s32 a);
void DrawTireWear(void *a);
void DrawPitStopWarning(void *a);
void DummyHudHook(void *a);
void UpdateTrackCues(void *a);

void sub_08005FA8(void)
{
    u32 base;
    u32 obj;
    struct Car *car;
    s32 v;

    UpdateRaceTimers();
    base = gTextLayerMapPtr[0];
    obj = base + 0x448;
    DrawTime(obj, gLapMin, gLapSec, gLapMs);
    obj = base + 0x488;
    if (gIsTimeTrial != 0)
        DrawTime(obj, gTrackRecordMin[gTrackId], gTrackRecordSec[gTrackId], gTrackRecordMs[gTrackId]);
    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId];
    else
        car = gCars;
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    DrawSpeedNeedle(v);
    DrawLowFuelWarning(car->fuel << 8);
    DrawTireWear(car);
    DrawPitStopWarning(car);
    DummyHudHook(car);
    UpdateTrackCues(car);
}

void sub_08006090(void)
{
}
