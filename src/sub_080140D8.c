#include "global.h"
#include "functions.h"
struct Unk0202A550 { u8 filler[400]; };
extern struct Unk0202A550 gCars[];
u32 AwardAllRacePoints(void)
{
    u8 i = 0;
    do {
        AwardRacePoints((struct UnkCar *)(&gCars[i]), i);
        i++;
    } while (i != 0x18);
}
