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

void ModuleKeepNearestCarContact(s32 arg0, u8 arg1, u32 arg2, u8 arg3, u32 *arg4, u8 *arg5, u32 arg6, s32 arg7)
{
    if (arg7 < gUnk_0203DF44) {
        arg4[0] = arg0;
        arg4[1] = arg2;
        ((u8 *)arg4)[8] = arg1;
        ((u8 *)arg4)[9] = arg3;
        arg4[3] = arg6;
        *arg5 = 1;
        gUnk_0203DF44 = arg7;
    }
}
