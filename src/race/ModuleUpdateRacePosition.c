#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

void ModuleUpdateRacePosition(u8 idx)
{
    u32 numCars;
    u8 position;
    s32 threshold;
    u8 *cars;
    u8 *progress;
    u8 *storeBase;
    u32 carOff;
    u32 j;

    numCars = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        numCars = gModule_NumLinkPlayers[0];
    position = 0;
    cars = (u8 *)gModule_Cars;
    carOff = idx * 400;
    progress = cars + 0x50;
    threshold = *(s32 *)(carOff + progress);
    for (j = 0, storeBase = (u8 *)gModule_Cars; j != numCars; j++) {
        if (j != idx && *(s32 *)(progress + j * 400) > threshold)
            position++;
    }
    *(storeBase + idx * 400 + 0x150) = position;
}
