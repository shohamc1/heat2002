#include "global.h"
#include "car.h"

u32 ModuleGetGearForSpeed(struct Car *car, s32 speed)
{
    u16 *rpmPerSpeedTable;
    s16 gear;
    s32 rpm;

    gear = 0;
    rpmPerSpeedTable = (u16 *)car->rpmPerSpeedTable;
    do
    {
        rpm = -(s32)rpmPerSpeedTable[gear] * speed >> 8;
        if ((u32)(rpm - 2001) <= 8998)
            return gear;
        gear++;
    } while (gear != 5);
    if (speed > -150000)
        return 0;
    return 4;
}
