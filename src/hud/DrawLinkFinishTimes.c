#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"
#include "data.h"

void DrawLinkFinishTimes(void)
{
    struct Car *car;
    struct Car *finishedCar;
    u8 *dest;
    u8 row;
    u8 place;
    u8 i;
    u8 carIdx;

    if (gNumFinishedCars == 0)
        return;
    car = gCars;
    if (gIsLinkRace != 0)
        car = &gCars[gLinkPlayerId];
    if (car->finished == 0)
        return;
    row = 5;
    if (gIsLinkRace != 0)
        row = 2;
    place = 1;
    for (i = 0; i != gNumFinishedCars; i++) {
        u8 **tbl = (u8 **)&gTextLayerMapPtr;

        carIdx = gFinishedCarOrder[i];
        finishedCar = &gCars[carIdx];
        if (gIsLinkRace != 0)
            dest = (0x14 + tbl[0]) + row * 128;
        else
            dest = (0x14 + tbl[0]) + row * 64;
        DrawSmallDigit((u16 *)dest, place);
        DrawTime((u16 *)dest, finishedCar->finishMin, finishedCar->finishSec, finishedCar->finishMs);
        if (gIsLinkRace != 0)
            DrawLinkMarker(64, row * 16, gFinishedCarOrder[i]);
        row++;
        place++;
    }
}
