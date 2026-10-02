#include "global.h"
#include "gba/defines.h"
#include "car.h"
#include "variables.h"
#include "functions.h"
#include "data.h"

extern u8 gTrackStartOffsetPercents[];
extern s32 gChallengeStartOffsetPercents[];

void InitRaceCars(u32 a1)
{
    u8 a;
    u32 eed0;
    u32 *p;
    struct Car **pp;
    u32 i;
    struct Car *car;

    u32 d;
    register u32 sh PIN(r1);
    register u32 v0 PIN(r0);

    struct LanePos out;

    /* Passes a1 unnarrowed; LoadTrackCues narrows it to u8 itself. */
    ((void (*)(u32))LoadTrackCues)(a1);
    a = a1;
    BuildStartingGrid(a);
    gStartedCarCount = 0;
    eed0 = gUnk_0202EED0;
    ClearWaypointSpeedSamples();
    if (gGameMode == 0) {
        pp = gCarOrder;
        p = gUnk_0202A3F0;
        i = 0;
        do {
            /* The ROM loads *pp for r1 and computes the last argument
               from a second load of the same pre-increment word (the
               original was the unsequenced *pp++ expression agbcc
               happened to split that way). Both spellings read pp[0]
               once here, so the sequenced form is the hosted fix. */
            InitCar(i, *pp, p[0] << 16, p[1] << 16, p[2] << 8, (u32)(*pp - gCars + eed0));
            pp++;
            p += 3;
            i++;
        } while (i != 24);
    } else {
        p = gUnk_0202A3F0;
        i = 0;
        do {
            InitCar(i, &gCars[i], p[0] << 16, p[1] << 16, p[2] << 8, i + eed0);
            p += 3;
            i++;
        } while (i != 24);
    }
    if (gGameMode == 14 || gGameMode == 9 || gGameMode == 13 || gGameMode == 17) {
        car = gCarOrder[0];
        d = *(u16 *)gLaneLengthPtrs[gTrackId * 12 + 5] * gTrackStartOffsetPercents[gTrackId] / 100;
        GetLanePositionAtDistance(d, &out, gLanePointTables[gTrackId * 12 + 5], gLaneSegmentTables[gTrackId * 12 + 5]);
        v0 = out.x;
        sh = v0 << 16;
        car->posX = sh;
        car->posZ = out.z << 16;
        car->velX = 0;
        car->velZ = 0;
        car->speed = 0;
        car->heading = 0;
        if (gTrackId == 1)
            PlaceCarsAlongLane(gCarOrder, sh, car->unk04, 70, 1);
        else
            PlaceCarsAlongLane(gCarOrder, sh, car->unk04, 100, 1);
    }
    if (gGameMode == 15) {
        car = (gCarOrder)[0];
        d = *(u16 *)gLaneLengthPtrs[gTrackId * 12 + 5] * gChallengeStartOffsetPercents[gChallengeIndex] / 100;
        GetLanePositionAtDistance(d, &out, gLanePointTables[gTrackId * 12 + 5], gLaneSegmentTables[gTrackId * 12 + 5]);
        car->posX = out.x << 16;
        car->posZ = out.z << 16;
        car->velX = 0;
        car->velZ = 0;
        car->speed = 0;
        car->heading = 0;
        if (gChallengeIndex == 6)
            goto l_inner;
        if (gChallengeIndex == 10)
            goto l_inner;
        if (gChallengeIndex == 11)
            goto l_inner;
        if (gChallengeIndex == 12)
            goto l_50;
        if (gChallengeIndex == 14)
            goto l_inner;
        if (gChallengeIndex != 15)
            goto l_180;
    l_inner:
        if (gChallengeIndex == 12)
            goto l_50;
        if (gChallengeIndex == 6) {
            PlaceCarsAlongLane(gCarOrder, 0, 0, 40, 1);
            goto l_1d0;
        }
        if (gChallengeIndex == 11)
            goto l_50;
        if (gChallengeIndex != 14)
            goto l_16c;
    l_50:
        PlaceCarsAlongLane(gCarOrder, 0, 0, 80, 1);
        goto l_1d0;
    l_16c:
        (gCarOrder)[0] = gCars;
        PlaceCarsAlongLane(gCarOrder, 0, 0, 50, 0);
        goto l_1d0;
    l_180:
        if (gChallengeIndex == 3) {
            PlaceCarsAlongLane(gCarOrder, 0, 0, 20, 1);
            goto l_1d0;
        }
        if (gChallengeIndex == 13) {
            PlaceCarsAlongLane(gCarOrder, 0, 0, 75, 1);
            goto l_1d0;
        }
        if (gChallengeIndex == 2) {
            PlaceCarsAlongLane(gCarOrder, 0, 0, 50, 1);
            goto l_1d0;
        }
        PlaceCarsAlongLane(gCarOrder, 0, 0, 50, 0);
    l_1d0:
        gChallengePhase = 0;
        gUnk_0202CB14 = 0;
        ResetChallengeTimer();
    }
}
