#include "global.h"
#include "car.h"
#include "data.h"
#include "functions.h"

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
