#include "global.h"
#include "car.h"
#include "variables.h"
#include "functions.h"

extern u8 gRacePointsTable[];
u32 GetCarOrderIndex(struct Car *car);
/* Non-const on purpose: with a const extern, old_agbcc allocates the
   table base to r3 and the destination pointer to r2, swapped from the
   ROM. Solved-walls 31 variant: keep this file's declared view. */
extern struct TrackGrid gTrackStartGrids[];

u32 GetCarOrderIndex(struct Car *car)
{
    struct Car **order = gCarOrder;
    u8 i;

    for (i = 0; i != 24; i++, order++) {
        if (*order == car)
            return i;
    }
    return 0x18;
}

void AwardRacePoints(struct Car *a1, u32 a2)
{
    u8 i;
    u8 flag;
    s32 t;

    UpdateRacePosition((u8)a2);
    t = GetCarOrderIndex(a1);
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

void BuildStartingGrid(u8 a1)
{
    u32 x = gTrackStartGrids[a1].originX;
    u32 y = gTrackStartGrids[a1].originY;
    u32 *p = gUnk_0202A3F0;
    u8 j;

    for (j = 0; j != 12; j++) {
        p[0] = x;
        p[1] = y;
        p[2] = gTrackStartGrids[a1].direction;
        p += 3;
        p[0] = x + gTrackStartGrids[a1].pairOffsetX;
        p[1] = y + gTrackStartGrids[a1].pairOffsetY;
        p[2] = gTrackStartGrids[a1].direction;
        p += 3;
        x += gTrackStartGrids[a1].rowStepX;
        y += gTrackStartGrids[a1].rowStepY;
    }
}
