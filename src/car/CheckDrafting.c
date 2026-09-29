#include "global.h"
#include "variables.h"
#include "car.h"
#include "functions.h"

u8 CheckDrafting(struct Car *car)
{
    s32 d1[2];
    s32 d2[2];
    u8 count;
    u8 i;
    struct Car *other;

    count = gNumCars[0];
    if (gIsLinkRace != 0)
        count = gNumLinkPlayers[0];
    other = gCars;
    for (i = 0; i != count; i++, other++) {
        if (other == car)
            continue;
        WorldToCarLocal(car, other->posX, other->posZ, d1);
        if ((u32)(d1[1] + 100) > 100)
            continue;
        {
            s32 dx = d1[0];
            s32 lim = -16;

            if (dx < lim || dx > 16)
                continue;
            WorldToCarLocal(other, car->posX, car->posZ, d2);
            if (d2[1] < 0)
                continue;
            if (d2[0] < lim || d2[0] > 16)
                continue;
        }
        car->draftTimer = 15;
        return 1;
    }
    return 0;
}
