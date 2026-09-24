#include "global.h"
struct Unk0202A550 { u8 filler[400]; };
extern struct Unk0202A550 gCars[];
extern void AwardRacePoints(struct Unk0202A550 *p, u8 i);
u32 AwardAllRacePoints(void)
{
    u8 i = 0;
    do {
        AwardRacePoints(&gCars[i], i);
        i++;
    } while (i != 0x18);
}
