#include "global.h"
#include "car.h"

s32 GetGearForSpeed(struct Car *car, s32 speed)
{
    u16 *rpmPerSpeedTable;
    u16 nextGear;
    s16 gear;
    s32 rpm;

    nextGear = 0;
    rpmPerSpeedTable = (u16 *)car->rpmPerSpeedTable;
    do {
        gear = nextGear;
        rpm = (-(s32)rpmPerSpeedTable[gear] * speed) >> 8;
        if ((u32)(rpm - 2001) <= 0x2326)
            return gear;
        nextGear = gear + 1;
    } while ((s16)nextGear != 5);
    if (speed > -150000)
        return 0;
    return 4;
}
