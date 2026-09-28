#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"
#include "car.h"

extern u8 gTrackStartOffsetPercents[];
extern s32 gChallengeStartOffsetPercents[];


/* InitCar: this file's old prototype takes a sixth argument the matched
   definition drops; call through a function pointer with the old signature. */
void InitRaceCars(u32 a1)
{
    u8 a;
    u32 eed0;
    u32 *p;
    struct Car **pp;
    u32 i;
    u32 off;
    struct Car *car;

    u32 d;
    register u32 sh asm("r1");
    register u32 v0 asm("r0");
    register u32 obj asm("r0");

    s16 out[4];
    register u32 garbage asm("r1");

    /* LoadTrackCues: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(u32))LoadTrackCues)(a1);
    a = a1;
    BuildStartingGrid(a);
    gStartedCarCount = 0;
    eed0 = gUnk_0202EED0;
    ClearWaypointSpeedSamples();
    if (gGameMode[0] == 0) {
        pp = (struct Car **)gCarOrder;
        p = gUnk_0202A3F0;
        i = 0;
        do {
            ((void (*)(u8, u32, u32, u32, u32, u32))InitCar)(i, (u32)*pp, p[0] << 16, p[1] << 16, p[2] << 8,
                         *pp++ - gCars + eed0);
            p += 3;
            i++;
        } while (i != 0x18);
    } else {
        p = gUnk_0202A3F0;
        i = 0;
        off = 0;
        do {
            ((void (*)(u8, u32, u32, u32, u32, u32))InitCar)(i, off + (u32)gCars, p[0] << 16, p[1] << 16, p[2] << 8,
                         i + eed0);
            p += 3;
            off += 400;
            i++;
        } while (i != 0x18);
    }
    if (gGameMode[0] == 0x0E || gGameMode[0] == 0x09 || gGameMode[0] == 0x0D
        || gGameMode[0] == 0x11) {
        car = ((struct Car **)gCarOrder)[0];
        d = *(u16 *)gLaneLengthPtrs[gTrackId * 12 + 5] * gTrackStartOffsetPercents[gTrackId] / 100;
        GetLanePositionAtDistance(d, out, (u16 *)gLanePointTables[gTrackId * 12 + 5],
                     (void *)gLaneSegmentTables[gTrackId * 12 + 5]);
        v0 = *(s32 *)&out[0];
        sh = v0 << 16;
        car->posX = sh;
        car->posZ = *(s32 *)&out[2] << 16;
        car->velX = 0;
        car->velZ = 0;
        car->speed = 0;
        car->heading = 0;
        if (gTrackId == 1)
            PlaceCarsAlongLane((struct Car **)gCarOrder, garbage, car->unk04, 0x46, 1);
        else
            PlaceCarsAlongLane((struct Car **)gCarOrder, garbage, car->unk04, 0x64, 1);
    }
    if (gGameMode[0] == 0x0F) {
        car = ((struct Car **)gCarOrder)[0];
        d = *(u16 *)gLaneLengthPtrs[gTrackId * 12 + 5] * gChallengeStartOffsetPercents[gChallengeIndex] / 100;
        GetLanePositionAtDistance(d, out, (u16 *)gLanePointTables[gTrackId * 12 + 5],
                     (void *)gLaneSegmentTables[gTrackId * 12 + 5]);
        car->posX = *(s32 *)&out[0] << 16;
        car->posZ = *(s32 *)&out[2] << 16;
        car->velX = 0;
        car->velZ = 0;
        car->speed = 0;
        car->heading = 0;
        if (gChallengeIndex == 6)
            goto l_inner;
        if (gChallengeIndex == 0xA)
            goto l_inner;
        if (gChallengeIndex == 0xB)
            goto l_inner;
        if (gChallengeIndex == 0xC)
            goto l_50;
        if (gChallengeIndex == 0xE)
            goto l_inner;
        if (gChallengeIndex != 0xF)
            goto l_180;
l_inner:
        if (gChallengeIndex == 0xC)
            goto l_50;
        if (gChallengeIndex == 6) {
            obj = (u32)gCarOrder;
            PlaceCarsAlongLane((struct Car **)obj, 0, 0, 0x28, 1);
            goto l_1d0;
        }
        if (gChallengeIndex == 0xB)
            goto l_50;
        if (gChallengeIndex != 0xE)
            goto l_16c;
l_50:
        obj = (u32)gCarOrder;
        PlaceCarsAlongLane((struct Car **)obj, 0, 0, 0x50, 1);
        goto l_1d0;
l_16c:
        ((struct Car **)gCarOrder)[0] = gCars;
        PlaceCarsAlongLane((struct Car **)gCarOrder, 0, 0, 0x32, 0);
        goto l_1d0;
l_180:
        if (gChallengeIndex == 3) {
            PlaceCarsAlongLane((struct Car **)gCarOrder, 0, 0, 0x14, 1);
            goto l_1d0;
        }
        if (gChallengeIndex == 0xD) {
            PlaceCarsAlongLane((struct Car **)gCarOrder, 0, 0, 0x4B, 1);
            goto l_1d0;
        }
        if (gChallengeIndex == 2) {
            PlaceCarsAlongLane((struct Car **)gCarOrder, 0, 0, 0x32, 1);
            goto l_1d0;
        }
        PlaceCarsAlongLane((struct Car **)gCarOrder, 0, 0, 0x32, 0);
l_1d0:
        gChallengePhase = 0;
        gUnk_0202CB14 = 0;
        ResetChallengeTimer();
    }
}
