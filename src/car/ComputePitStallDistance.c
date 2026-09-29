#include "global.h"
#include "variables.h"
#include "data.h"

struct UnkStruct0800C4E0
{
    u8 pad0[2];
    s16 f2;
    u8 pad4[6];
    s16 fA;
    u8 padC[0x175];
    u8 pitStall;
};

s32 ComputePitStallDistance(struct UnkStruct0800C4E0 *car)
{
    s32 *stalls;
    s32 *stallZPtr;
    s32 stallIdx;
    s32 dx;
    s32 dz;
    s32 carX;
    s32 carZ;

    stalls = (s32 *)gPitStallPositions;
    stallIdx = gTrackId * 8 + car->pitStall;
    dx = stalls[stallIdx * 2];
    stallZPtr = (s32 *)((stallIdx * 2 + 1) * 4 + (u32)stalls);
    dz = *stallZPtr;
    carX = car->f2;
    carZ = car->fA;
    dx = dx - carX;
    if (dx < 0)
        dx = -dx;
    carZ = dz - carZ;
    if (carZ < 0)
        carZ = -carZ;
    if (dx > carZ)
        carZ = dx;
    return carZ;
}
