#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
#include "m4a.h"
#include "data.h"

extern u8 gPitLaneIndices[];
extern u8 gText_PitControl[];
extern u8 gText_BlankRow16_3[];
extern u8 gText_GetReady[];
extern u32 gPitStopTireServiceTimes[];
extern u32 gPitStopRepairTimes[];

extern const u8 gText_BlankRow20_2[];

extern s32 gPitFuelToAdd;
extern s32 gPlayerPitProgressRate;
void ClearPitStopProgressBar(void)
{ DrawTextAt(gText_BlankRow20_2, 7, 10); }

void DrawPitStopProgressBar(u8 percent)
{
    u8 pad[0x28];
    u16 *dest;
    u8 row;
    u8 cell;
    u8 rowEnd;
    u32 glyphOff;

    dest = (u16 *)(gTextLayerMapPtr[0] + 0x290);
    glyphOff = 0x730;
    *dest = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)];
    dest = (u16 *)(gTextLayerMapPtr[0] + 0x292);
    row = 0;
    cell = 0;
    do {
        rowEnd = row + 7;
        if (percent > rowEnd) {
            glyphOff = 0x742;
            *dest = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)];
            dest++;
        }
        if (percent < row) {
            glyphOff = 0x732;
            *dest = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)];
            dest++;
        } else if (percent <= rowEnd) {
            glyphOff = 0x734 + 2 * (u8)(percent - row);
            *dest = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)];
            dest++;
        }
        row += 8;
        cell++;
    } while (cell != 12);
    glyphOff = 0x744;
    *dest = (0xE0 << 8) | gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + glyphOff)];
}

void EnterPit(struct Car *car, u8 stall)
{
    if (gGameMode == 3)
        return;
    if (car->pitState != 0)
        return;

    if (car == gCars) {
        gPlayerPittedFlag = 1;
    } else {
        car->prePitLane = car->lanePosition;
        car->pitCollidable = 1;
    }
    car->pitState = 1;
    SetCarLane(car, gPitLaneIndices[gTrackId] << 8);
    if (car == gCars && gDamagePitsEnabled != 0)
        InitPitMenu();
    car->pitStall = stall;
    gPitStallOccupied[stall] = 1;
}

void UpdatePitStop(struct Car *a1, u8 a2)
{
    u32 v;
    s32 *p;

    if (gPitMenuActive != 0 && a1 == gCars)
        UpdatePitMenu();
    if (a1 == gCars && gDamagePitsEnabled == 0)
        DrawTextCentered(gText_PitControl, 10, 1);
    switch (a1->pitState) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            UpdateAiDriver(a1, a2);
            break;
        case 4:
            if (gPitMenuActive == 0 && gPitServiceEnabled == 0)
                a1->pitState = 5;
            else if (gDamagePitsEnabled != 0)
                StopCar(a1);
            else
                a1->pitState = 5;
            if (gPitMenuActive != 0 && a1 == gCars) {
                StopCar(a1);
                break;
            }
            a1->pitProgress = 0;
            a1->pitDuration = 0x6400;
            a1->pitState = 5;
            if (a1 != gCars)
                break;
            a1->pitDuration = gPitStopTireServiceTimes[gPitServiceSelections[0]];
            if (gPitServiceSelections[1] == 2)
                gPitFuelToAdd = 0;
            if (gPitServiceSelections[1] == 1) {
                if (a1->fuel > 0x8200)
                    gPitFuelToAdd = 0xB400 - a1->fuel;
                else
                    gPitFuelToAdd = 0x3200;
            }
            if (gPitServiceSelections[1] == 0)
                gPitFuelToAdd = 0xB400 - a1->fuel;
            p = &a1->pitDuration;
            *p += gPitFuelToAdd;
            *p += gPitStopRepairTimes[gPitServiceSelections[2]];
            gPlayerPitProgressRate = 0x6400 / (*p >> 8);
            *p = 0x6400;
            break;
        case 5:
            if (gDamagePitsEnabled != 0)
                StopCar(a1);
            if (a1->pitProgress < a1->pitDuration && (a1 != gCars || gPitServiceEnabled != 0) &&
                gDamagePitsEnabled != 0)
                goto l_big;
            if (a1 == gCars) {
                ClearPitStopProgressBar();
                a1->pitExitPending = 1;
            } else {
                a1->pitExitPending = 1;
            }
            a1->pitState = 6;
            break;
        l_big:
            if (a1 == gCars) {
                if (gPitServiceEnabled != 0) {
                    if (gOptions[3] != 0) {
                        if (gIsDemo == 0 && gRaceEndState == 0 && (Random8() & 15) > 13) {
                            v = Random8() & 3;
                            if (v == 0)
                                m4aSongNumStart(25);
                            if (v == 1)
                                m4aSongNumStart(26);
                            if (v == 2)
                                m4aSongNumStart(24);
                            if (v == 3)
                                m4aSongNumStart(24);
                        }
                    }
                    DrawPitStopProgressBar((a1->pitProgress >> 8) % 100);
                }
            }
            if (a1 != gCars)
                a1->pitProgress += 0x100;
            else
                a1->pitProgress += gPlayerPitProgressRate;
            if (a1 == gCars) {
                if (gPitServiceEnabled == 0)
                    break;
                if (gPitFuelToAdd > 0) {
                    gPitFuelToAdd -= 0x100;
                    a1->fuel += 0x100;
                }
                if (gPitServiceSelections[0] != 3) {
                    a1->tireWear0 = 0;
                    a1->tireWear1 = 0;
                    a1->tireWear2 = 0;
                    a1->tireWear3 = 0;
                }
                if (gPitServiceSelections[2] == 0)
                    a1->damage = 0;
            } else {
                a1->fuel = 0xB400;
                a1->tireWear0 = 0;
                a1->tireWear1 = 0;
                a1->tireWear2 = 0;
                a1->tireWear3 = 0;
                a1->damage = 0;
            }
            break;
        case 6:
            v = a1->pitExitPending;
            if (v == 0) {
                a1->pitState = v;
                if (a1 != gCars) {
                    SetCarLane(a1, a1->prePitLane);
                    a1->pitCollidable = 1;
                }
                gPitStallOccupied[a1->pitStall] = v;
                if (a1 == gCars)
                    DrawTextAt(gText_BlankRow16_3, 9, 10);
            } else {
                UpdateAiDriver(a1, a2);
                if (a1 == gCars && gDamagePitsEnabled != 0)
                    DrawTextAt(gText_GetReady, 10, 10);
            }
            break;
    }
}
