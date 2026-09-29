#include "global.h"
#include "variables.h"
#include "car.h"
#include "functions.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 callback;
};

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
extern u8 gModule_TimeLabel[];
void *ModuleAllocTask(void);
void ModuleAddTask(u32 r0);
void ModuleDrawHudLabels(void);
void ModuleInitCountdown(void);
void ModuleUpdateRaceHud(void);
void ModuleInitRaceHud(void);
extern u8 gModule_PitLabelBlock[];

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

void ModuleClearTextLayer(void)
{
    u16 *p = (u16 *)(*(u32 *)&gModule_TextLayerMapPtr);
    u32 i = 0;

    do {
        *p++ = 0xE047;
        i++;
    } while (i != 0x380);
}

void ModuleDrawHudLabels(void)
{
    u16 *dst;
    u8 row;
    u8 col;
    u32 rowStride;
    u32 glyphOff;
    dst = (u16 *)(*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
    for (row = 0; row != 6; row++) {
        rowStride = (row + 8) * 68;
        for (col = 0; col != 10; col++) {
            glyphOff = 2 * (((row + 8) * 68) + col + 0x33);
            *dst = gModule_FontTileEntries[*(u16 *)((u8 *)gUnk_02021594 + glyphOff)] | 0xE000;
            dst++;
        }

        dst += 22;
    }

    dst = (u16 *)(*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
    if (gModule_DamagePitsEnabled == 0) {
        for (row = 0; row != 6; row++) {
            for (col = 0; col != 4; col++) {
                *dst = 0x47;
                dst++;
            }

            dst += 28;
        }
    }
}

void ModuleInitRaceHud(void)
{
    void *task;

    if (gModule_IsDemo[0] != 0)
        return;
    task = ModuleAllocTask();
    if (task != 0) {
        ((struct Task *)task)->callback = (u32)ModuleUpdateRaceHud;
        ModuleAddTask((u32)task);
    }
    ModuleDrawHudLabels();
    ModuleDrawText(gModule_TimeLabel, 0, 0x13);
    ModuleInitCountdown();
}

void ModuleInitTimeTrialHud(void)
{
    ModuleInitRaceHud();
    if (gUnk_0203E1E0[0] != 0)
        ModuleDrawText(gModule_PitLabelBlock, 0, 0x12);
}
