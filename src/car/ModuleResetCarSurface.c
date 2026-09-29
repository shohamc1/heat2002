#include "global.h"
#include "car.h"

void ModuleResetCarSurface(u8 *car)
{
    u32 carAddr = (u32)car;
    u8 wasGrass;
    u32 sp[0x0A];

    (void)sp;
    ((struct Car *)carAddr)->onApron = 0;
    wasGrass = ((struct Car *)carAddr)->onGrass;
    ((struct Car *)carAddr)->wasOnGrass = wasGrass;
    ((struct Car *)carAddr)->onGrass = 0;
    ((struct Car *)carAddr)->behindBgFlag = 0;
}
