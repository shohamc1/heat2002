#include "global.h"
#include "variables.h"
#include "car.h"
#include "data.h"
#include "functions.h"
#include "gba/compat.h"

extern const u8 gRaceHudObjTiles[];
extern u8 gText_TimeLabel[];
void DrawHudLabels(void);
extern u8 gText_HudBestLabel[];

void UpdateRaceHud(void)
{
    struct Car *car;
    u16 *dest;
    s32 v;

    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId];
    else
        car = &gCars[0];
    UpdateRaceTimers();
    dest = (u16 *)(gTextLayerMapPtr[0] + 0x4C6);
    DrawTime(dest, gLapMin, gLapSec, gLapMs);
    if (gGameMode == 14 || gGameMode == 2) {
        dest = (u16 *)(gTextLayerMapPtr[0] + 0x486);
        if (gIsTimeTrial != 0)
            DrawTime(dest, gTrackRecordMin[gTrackId], gTrackRecordSec[gTrackId], gTrackRecordMs[gTrackId]);
    }
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    DrawSpeedNeedle(v);
    if (gGameMode != 2 && gGameMode != 14) {
        DrawRacePosition(car->racePosition + 1);
        if (car->lapStartedFlag != 0 || (u8)(gGameMode - 3) <= 1)
            DrawLapCounter(car->lap + 1, gNumLaps);
        else
            DrawLapCounter(999, gNumLaps);
        DrawLowFuelWarning((u32)car->fuel << 8);
        DrawTireWear(car);
        DrawPitStopWarning(car);
        DummyHudHook(car);
    }
    UpdateTrackCues(car);
}

void ClearTextLayer(void)
{
    u16 *p = (*(u16 **)&gTextLayerMapPtr);
    u32 i = 0;

    do {
        *p++ = 0xE047;
        i++;
    } while (i != 896);
}

void DrawHudLabels(void)
{
    u16 *dst;
    u8 row;
    u8 col;
    u32 glyphOff;

    dst = (*(u16 **)&gTextLayerMapPtr) + 0x1D4;
    row = 0;
    do {
        col = 0;
        do {
            glyphOff = 2 * ((row + 8) * 68 + col + 0x33);
            *dst++ = gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)] | 0xE000;
            col++;
        } while (col != 10);
        dst += 0x16;
        row++;
    } while (row != 6);
    dst = (*(u16 **)&gTextLayerMapPtr) + 0x1D4;
    if (gDamagePitsEnabled == 0) {
        row = 0;
        do {
            col = 0;
            do {
                *dst++ = 0x47;
                col++;
            } while (col != 4);
            dst += 0x1C;
            row++;
        } while (row != 6);
    }
}

void InitRaceHud(void)
{
    struct Task *task;
    const u8 *src;
    u8 *dst;

    if (gIsDemo != 0)
        return;
    task = AllocTask();
    if (task != 0) {
        task->callback = UpdateRaceHud;
        AddTask(task);
    }
    DrawHudLabels();
    DrawTextAt(gText_TimeLabel, 0, 19);
    src = gRaceHudObjTiles;
    dst = (u8 *)(OBJ_VRAM1 + 0x2280);
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    InitCountdown();
}

void InitTimeTrialHud(void)
{
    InitRaceHud();
    if (gIsTimeTrial != 0) {
        DrawTextAt(gText_HudBestLabel, 0, 18);
    }
}
