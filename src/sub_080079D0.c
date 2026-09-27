#include "global.h"
#include "car.h"

u8 CarNeedsPit(struct Car *a1)
{
    u8 ret;

    if (a1 != gCars)
    {
        ret = 0;
        if (a1->fuel <= 0x2800)
            ret = 1;
        if (a1->tireWear0 > 0x3E7FF
         || a1->tireWear1 > 0x3E7FF
         || a1->tireWear2 > 0x3E7FF
         || a1->tireWear3 > 0x3E7FF)
            ret = 1;
    }
    else
    {
        ret = 0;
        if (a1->fuel <= 0x2800)
            ret = 1;
        if (a1->tireWear0 > 0x5DBFF
         || a1->tireWear1 > 0x5DBFF
         || a1->tireWear2 > 0x5DBFF
         || a1->tireWear3 > 0x5DBFF)
            ret = 1;
    }
    return ret;
}
