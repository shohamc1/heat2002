#include "global.h"
#include "car.h"

extern u8 gRacePointsTable[];

void UpdateRacePosition(u8 idx);
u32 sub_08007B10(u32 ptr);

void AwardRacePoints(struct Car *a1, u32 a2)
{
    u8 i;
    u8 flag;
    s32 t;

    UpdateRacePosition((u8)a2);
    t = sub_08007B10((u32)a1);
    a1->points = a1->points + gRacePointsTable[(u8)t];
    if (a1->lapsLed != 0)
        a1->points += 5;
    flag = 1;
    for (i = 0; i != 24; i++) {
        if (a1 == &gCars[i])
            continue;
        if (gCars[i].lapsLed <= a1->lapsLed)
            continue;
        flag = 0;
    }
    if (flag != 0)
        a1->points += 10;
}
