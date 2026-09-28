#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
#include "data.h"


void DrawTime(u32 a, u16 b, u16 c, u16 d);
void DrawLinkMarker(u8 a, u32 b, u8 c);

void DrawLinkFinishTimes(void)
{
    struct Car *car;
    struct Car *finishedCar;
    u32 dest;
    u8 row;
    u8 place;
    u8 i;
    u8 carIdx;

    if (gNumFinishedCars == 0)
        return;
    car = gCars;
    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId[0]];
    if (car->finished == 0)
        return;
    row = 5;
    if (gIsLinkRace != 0)
        row = 2;
    place = 1;
    for (i = 0; i != gNumFinishedCars; i++)
    {
        u32 *tbl = gTextLayerMapPtr;

        carIdx = gFinishedCarOrder[i];
        finishedCar = &gCars[carIdx];
        if (gIsLinkRace != 0)
            dest = (0x14 + tbl[0]) + row * 128;
        else
            dest = (0x14 + tbl[0]) + row * 64;
        DrawSmallDigit((u16 *)dest, place);
        DrawTime(dest, finishedCar->finishMin, finishedCar->finishSec, finishedCar->finishMs);
        if (gIsLinkRace != 0)
            DrawLinkMarker(0x40, row * 16, gFinishedCarOrder[i]);
        row++;
        place++;
    }
}
