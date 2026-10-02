#include "global.h"
#include "variables.h"
#include "car.h"
#include "functions.h"

void ModuleBuildCarCollFrame(struct Car *car, s32 *frame)
{
    s32 x, z;
    s32 v;

    v = -(car->heading >> 8) & 0xFF;
    frame[0] = gModule_SinTable[v];
    frame[1] = gModule_SinTable[v + 0x40];
    x = car->posX;
    frame[4] = x >> 8;
    z = car->posZ;
    frame[5] = z >> 8;
    v = car->heading + (s16)car->yawRate;
    v = -(v >> 8) & 0xFF;
    frame[2] = gModule_SinTable[v];
    frame[3] = gModule_SinTable[v + 0x40];
    frame[6] = (x + car->velX) >> 8;
    frame[7] = (z + car->velZ) >> 8;
}

void ModuleKeepNearestCarContact(struct Car *carA, u8 unk08, struct Car *carB, u8 normalIndex,
                                 struct CarContact *contact, u8 *hit, s32 closingSpeed, s32 time)
{
    if (time < gUnk_0203DF44) {
        contact->carA = carA;
        contact->carB = carB;
        contact->unk08 = unk08;
        contact->normalIndex = normalIndex;
        contact->closingSpeed = closingSpeed;
        *hit = 1;
        gUnk_0203DF44 = time;
    }
}
