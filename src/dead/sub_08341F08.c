#include "global.h"
#include "variables.h"
#include "car.h"


void sub_08341F04(struct Car *p);

void sub_08341F08(struct Car *p)
{
    (*(u32 *)&p->damage) = 0;
    p->carState = 2;
    p->unk80 = 1;
    p->zoneGripFlag = 0;
    p->throttleLevel = 0;
    sub_08341F04(p);
    if (p == gModule_Cars && gModule_GameMode == 0)
    {
        (*(s32 *)&gModule_CountdownSeconds) += 5;
        if ((*(s32 *)&gModule_CountdownSeconds) > 0x63)
            (*(s32 *)&gModule_CountdownSeconds) = 0x63;
    }
}
