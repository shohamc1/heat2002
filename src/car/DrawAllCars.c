#include "global.h"
#include "variables.h"
#include "car.h"

void DrawCar(struct Car *car, u8 idx);

void DrawAllCars(void)
{
    u8 n;
    u32 i;
    struct Car *p;

    n = gNumCars[0];
    if (gIsLinkRace != 0)
        n = gNumLinkPlayers[0];
    p = gCars;
    i = 0;
    while (i != n) {
        if (gGameMode[0] != 2 || i == 0)
            DrawCar(p, i);
        i++;
        p++;
    }
}
