#include "global.h"
#include "variables.h"
#include "car.h"

void DrawCar(u32 arg0, u8 arg1);

void DrawAllCars(void)
{
    u8 n;
    u32 i;
    u8 *p;

    n = gNumCars[0];
    if (gIsLinkRace != 0)
        n = gNumLinkPlayers[0];
    p = (u8 *)gCars;
    i = 0;
    while (i != n) {
        if (gGameMode[0] != 2 || i == 0)
            DrawCar(p, i);
        i++;
        p += 0xC8 * 2;
    }
}
