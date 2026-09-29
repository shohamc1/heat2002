#include "global.h"
#include "variables.h"
#include "car.h"
#include "functions.h"

void ModuleWorldToCarLocal(struct Car *car, s32 x, s32 z, s32 *out)
{
    s32 angIdx;
    s32 sin;
    s32 cos;
    s32 relx;
    s32 rely;

    angIdx = -(car->steerHeading >> 11) & 0x1F;
    angIdx = angIdx << 3;
    sin = gModule_SinTable[angIdx];
    angIdx = angIdx + 0x40;
    cos = gModule_SinTable[angIdx];
    relx = (x - car->posX) >> 16;
    rely = (z - car->posZ) >> 16;
    out[0] = (relx * cos - sin * rely) >> 8;
    out[1] = (sin * relx + rely * cos) >> 8;
}

u8 ModuleCheckDrafting(struct Car *car)
{
    s32 relPos1[2];
    s32 relPos2[2];
    u8 i;
    struct Car *other;
    u32 count;

    count = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        count = gModule_NumLinkPlayers[0];
    other = gModule_Cars;
    for (i = 0; i != count; i++, other++) {
        if (other == car)
            continue;
        ModuleWorldToCarLocal(car, other->posX, other->posZ, relPos1);
        if ((u32)(relPos1[1] + 100) > 100)
            continue;
        if (relPos1[0] < -16)
            continue;
        if (relPos1[0] > 16)
            continue;
        ModuleWorldToCarLocal(other, car->posX, car->posZ, relPos2);
        if (relPos2[1] < 0)
            continue;
        if (relPos2[0] < -16)
            continue;
        if (relPos2[0] > 16)
            continue;
        car->draftTimer = 15;
        return 1;
    }
    return 0;
}

void ModuleInitCarSteering(s32 *steer, u32 heading)
{
    steer[1] = heading;
    steer[0] = heading;
}
