#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"


void ModuleDrawTime(u32 a, u16 b, u16 c, u16 d);
void ModuleDrawLinkMarker(u8 a, u32 b, u8 c);

void ModuleDrawLinkFinishTimes(void)
{
    struct Car *car;
    struct Car *finishedCar;
    u32 dest;
    u8 row;
    u8 place;
    u8 i;
    u8 carIdx;

    if (gModule_NumFinishedCars == 0)
        return;
    car = gModule_Cars;
    if (gModule_IsLinkRace != 0)
        car = &gModule_Cars[gModule_LinkPlayerId];
    if (car->finished == 0)
        return;
    row = 5;
    if (gModule_IsLinkRace != 0)
        row = 2;
    place = 1;
    for (i = 0; i != gModule_NumFinishedCars; i++)
    {
        u32 *tbl = gModule_TextLayerMapPtr;

        carIdx = gModule_FinishedCarOrder[i];
        finishedCar = &gModule_Cars[carIdx];
        if (gModule_IsLinkRace != 0)
            dest = (0x14 + tbl[0]) + row * 128;
        else
            dest = (0x14 + tbl[0]) + row * 64;
        ModuleDrawSmallDigit((u16 *)dest, place);
        ModuleDrawTime(dest, finishedCar->finishMin, finishedCar->finishSec, finishedCar->finishMs);
        if (gModule_IsLinkRace != 0)
            ModuleDrawLinkMarker(0x40, row * 16, gModule_FinishedCarOrder[i]);
        row++;
        place++;
    }
}
