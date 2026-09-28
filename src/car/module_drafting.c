#include "global.h"
#include "variables.h"

#include "car.h"
void ModuleWorldToCarLocal(s32 *car, s32 x, s32 y, s32 *out)
{
    s32 angIdx;
    s32 sin;
    s32 cos;
    s32 relx;
    s32 rely;

    angIdx = -(car[75] >> 11) & 0x1F;
    angIdx = angIdx << 3;
    sin = gModule_SinTable[angIdx];
    angIdx = angIdx + 0x40;
    cos = gModule_SinTable[angIdx];
    relx = (x - car[0]) >> 16;
    rely = (y - car[2]) >> 16;
    out[0] = (relx * cos - sin * rely) >> 8;
    out[1] = (sin * relx + rely * cos) >> 8;
}


u8 ModuleCheckDrafting(u8 *car)
{
    struct Out08343234
    {
        s32 f0;
        s32 f4;
    };
    struct Out08343234 relPos1;
    struct Out08343234 relPos2;
    u8 i;
    u8 *other;
    u32 count;

    count = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        count = gModule_NumLinkPlayers[0];
    other = (u8 *)gModule_Cars;
    for (i = 0; i != count; i++, other += 0x190)
    {
        if (other == car)
            continue;
        ModuleWorldToCarLocal((s32 *)car, *(u32 *)(other + 0), *(u32 *)(other + 8), &relPos1);
        if ((u32)(relPos1.f4 + 100) > 100)
            continue;
        if (relPos1.f0 < -16)
            continue;
        if (relPos1.f0 > 16)
            continue;
        ModuleWorldToCarLocal((u32)other, *(u32 *)(car + 0), *(u32 *)(car + 8), &relPos2);
        if (relPos2.f4 < 0)
            continue;
        if (relPos2.f0 < -16)
            continue;
        if (relPos2.f0 > 16)
            continue;
        car[0x176] = 15;
        return 1;
    }
    return 0;
}

