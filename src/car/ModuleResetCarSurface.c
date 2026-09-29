#include "global.h"
#include "car.h"

void ModuleResetCarSurface(struct Car *car)
{
    u8 wasGrass;
    u32 sp[0x0A];

    (void)sp;
    car->onApron = 0;
    wasGrass = car->onGrass;
    car->wasOnGrass = wasGrass;
    car->onGrass = 0;
    car->behindBgFlag = 0;
}
