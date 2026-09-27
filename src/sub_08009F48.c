#include "global.h"

extern u8 gNumCars[];
extern u8 gIsLinkRace;
extern u8 gNumLinkPlayers[];
extern u8 gCars[];
extern u8 gUnk_0200215C[];

void DrawCar(u32 arg0, u8 arg1);

void DrawAllCars(void)
{
    u8 n;
    u32 i;
    u8 *p;

    n = gNumCars[0];
    if (gIsLinkRace != 0)
        n = gNumLinkPlayers[0];
    p = gCars;
    i = 0;
    while (i != n) {
        if (gUnk_0200215C[0] != 2 || i == 0)
            DrawCar(p, i);
        i++;
        p += 0xC8 * 2;
    }
}
