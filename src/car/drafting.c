#include "global.h"
#include "car.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

void WorldToCarLocal(struct Car *car, s32 x, s32 z, s32 *out)
{
    u16 i;
    s32 dx;
    s32 dy;
    s32 relx;
    s32 rely;

    i = ((-(car->steerHeading >> 11)) & 0x1F) << 3;
    dx = gSinTable[i];
    dy = gSinTable[i + 0x40];
    relx = (x - car->posX) >> 16;
    rely = (z - car->posZ) >> 16;
    out[0] = (relx * dy - dx * rely) >> 8;
    out[1] = (dx * relx + rely * dy) >> 8;
}

s32 CheckDrafting(struct Car *car)
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
