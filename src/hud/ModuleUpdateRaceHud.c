#include "global.h"
#include "variables.h"
#include "car.h"

void ModuleUpdateRaceTimers(void);
void ModuleDrawTime(u16 *dest, s32 a, s32 b, s32 c);
void ModuleDrawSpeedNeedle(u32 a1);
void ModuleDrawRacePosition(s32 arg);
void ModuleDrawLapCounter(s32 a, s32 b);
void ModuleDrawLowFuelWarning(s32 arg);
void ModuleDrawTireWear(struct Car *p);
void ModuleDrawPitStopWarning(struct Car *p);
void ModuleDummyHudHook(struct Car *p);
void ModuleUpdateTrackCues(struct Car *p);

void ModuleUpdateRaceHud(void)
{
    struct Car *car;
    u16 *dest;
    s32 v;

    if (gModule_IsLinkRace != 0)
        car = &gModule_Cars[gModule_LinkPlayerId];
    else
        car = &gModule_Cars[0];
    ModuleUpdateRaceTimers();
    dest = (u16 *)(gModule_TextLayerMapPtr[0] + 0x4C6);
    ModuleDrawTime(dest, gModule_LapMin[0], gModule_LapSec[0], gModule_LapMs[0]);
    if (gModule_GameMode[0] == 0x0E || gModule_GameMode[0] == 0x02) {
        dest = (u16 *)(gModule_TextLayerMapPtr[0] + 0x486);
        if (gUnk_0203E1E0[0] != 0)
            ModuleDrawTime(dest, gModule_TrackRecordMin[gModule_TrackId], gModule_TrackRecordSec[gModule_TrackId],
                           gModule_TrackRecordMs[gModule_TrackId]);
    }
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    ModuleDrawSpeedNeedle(v);
    if (gModule_GameMode[0] != 2 && gModule_GameMode[0] != 0x0E) {
        ModuleDrawRacePosition(car->racePosition + 1);
        if (car->lapStartedFlag != 0 || (u8)(gModule_GameMode[0] - 3) <= 1)
            ModuleDrawLapCounter((*(s8 *)&car->lap) + 1, gUnk_02039194);
        else
            ModuleDrawLapCounter(999, gUnk_02039194);
        ModuleDrawLowFuelWarning((*(u32 *)&car->fuel) << 8);
        ModuleDrawTireWear(car);
        ModuleDrawPitStopWarning(car);
        ModuleDummyHudHook(car);
    }
    ModuleUpdateTrackCues(car);
}
