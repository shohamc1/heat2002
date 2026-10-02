#include "global.h"
#include "variables.h"
#include "car.h"


void DummyCarWreckedHook(struct Car *p);

void sub_0800A478(struct Car *p)
{
    p->damage = 0;
    p->carState = 2;
    p->unk80 = 1;
    p->zoneGripFlag = 0;
    p->throttleLevel = 0;
    DummyCarWreckedHook(p);
    if (p == gCars && gGameMode == 0)
    {
        gCountdownSeconds += 5;
        if (gCountdownSeconds > 0x63)
            gCountdownSeconds = 0x63;
    }
}
