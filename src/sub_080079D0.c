#include "global.h"

struct Unk0202A550Drv
{
    u8 filler0[0x8C];
    s32 tireWear0;
    s32 tireWear1;
    s32 tireWear2;
    s32 tireWear3;
    s32 fuel;
};

extern struct Unk0202A550Drv gCars[];

u8 CarNeedsPit(struct Unk0202A550Drv *a1)
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
