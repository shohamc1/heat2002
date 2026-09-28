#include "global.h"
#include "variables.h"
#include "car.h"
#include "data.h"

void UpdateRaceTimers(void);
void DrawTime(u32 a, u16 b, u16 c, u16 d);
void sub_08005A2C(u32 a);
void sub_08005AF0(s32 a);
void DrawTireWear(void *a);
void sub_08005AA0(void *a);
void sub_08005AEC(void *a);
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
    DrawTime(obj, gLapMin[0], gLapSec[0], gLapMs[0]);
    obj = base + 0x488;
    if (gIsTimeTrial != 0)
        DrawTime(obj, gTrackRecordMin[gTrackId], gTrackRecordSec[gTrackId], gTrackRecordMs[gTrackId]);
    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId[0]];
    else
        car = gCars;
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_08005A2C(v);
    sub_08005AF0(car->fuel << 8);
    DrawTireWear(car);
    sub_08005AA0(car);
    sub_08005AEC(car);
    UpdateTrackCues(car);
}

void sub_08006090(void)
{
}
