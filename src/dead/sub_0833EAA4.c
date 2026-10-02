#include "global.h"
#include "variables.h"
#include "car.h"

void ModuleUpdateRaceTimers(void);
void ModuleDrawTime(u32 a, u16 b, u16 c, u16 d);
void ModuleDrawSpeedNeedle(u32 a);
void ModuleDrawLowFuelWarning(s32 a);
void ModuleDrawTireWear(void *a);
void ModuleDrawPitStopWarning(void *a);
void ModuleDummyHudHook(void *a);
void ModuleUpdateTrackCues(void *a);

void sub_0833EAA4(void)
{
    u32 base;
    u32 obj;
    struct Car *car;
    s32 v;

    ModuleUpdateRaceTimers();
    base = gModule_TextLayerMapPtr[0];
    obj = base + 0x448;
    ModuleDrawTime(obj, gModule_LapMin[0], gModule_LapSec, gModule_LapMs[0]);
    obj = base + 0x488;
    if (gUnk_0203E1E0[0] != 0)
        ModuleDrawTime(obj, gModule_TrackRecordMin[gModule_TrackId], gModule_TrackRecordSec[gModule_TrackId], gModule_TrackRecordMs[gModule_TrackId]);
    if (gModule_IsLinkRace != 0)
        car = &gModule_Cars[gModule_LinkPlayerId];
    else
        car = gModule_Cars;
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    ModuleDrawSpeedNeedle(v);
    ModuleDrawLowFuelWarning(car->fuel << 8);
    ModuleDrawTireWear(car);
    ModuleDrawPitStopWarning(car);
    ModuleDummyHudHook(car);
    ModuleUpdateTrackCues(car);
}

void sub_0833EB8C(void)
{
}
