#include "global.h"
#include "variables.h"
#include "data.h"
#include "functions.h"

#include "car.h"

extern const u8 *const gLaneCellLists[];
extern const u8 *const gLaneCellGrids[];

s32 WorldToLaneDistance(s32 posX, s32 posZ, const u16 *points, const struct LaneSeg *seg, s32 unused)
{
    s32 ax;
    s32 bx;
    s32 az;
    s32 bz;
    s32 dx;
    s32 dy;
    s32 distAlong;
    s32 axisScale;

    ax = points[2 * seg->pointA];
    bx = points[2 * seg->pointB];
    az = points[2 * seg->pointA + 1];
    bz = points[2 * seg->pointB + 1];
    dx = bx - ax;
    if (dx < 0)
        dx = -dx;
    dy = bz - az;
    if (dy < 0)
        dy = -dy;
    if (dx > dy) {
        distAlong = posX - ax;
        axisScale = seg->scaleX;
    } else {
        distAlong = posZ - az;
        axisScale = seg->scaleZ;
    }
    dx = distAlong * axisScale;
    return seg->startDist + (s32)((dx * (seg->endDist - seg->startDist)) >> 16);
}

s32 FindWaypointCrossing(const u16 *points, const struct LaneSeg *laneSeg)
{
    const struct TrackSeg *trackSeg = gTrackSegTables[gTrackId];
    s32 t[6];
    s32 x1, y1, x2, y2;
    s32 reachedLast;
    s32 i;
    s32 segX1, segZ1, segX2, segZ2, cross, param;

    t[0] = points[2 * laneSeg->pointA];
    t[1] = points[2 * laneSeg->pointA + 1];
    t[2] = points[2 * laneSeg->pointB];
    t[3] = points[2 * laneSeg->pointB + 1];
    x1 = t[0];
    y1 = t[1];
    x2 = t[2];
    y2 = t[3];
    reachedLast = 0;
    i = 0;
    do {
        segX1 = trackSeg->corner1X;
        segZ1 = trackSeg->corner1Z;
        segX2 = trackSeg->corner2X;
        segZ2 = trackSeg->corner2Z;
        if (trackSeg->kind == 1)
            reachedLast = 1;
        cross = (x2 - x1) * (segZ2 - segZ1) - (y2 - y1) * (segX2 - segX1);
        if (cross == 0)
            goto next;
        param = ((y1 - segZ1) * (segX2 - segX1) - (x1 - segX1) * (segZ2 - segZ1)) << 8;
        if ((u32)(param / cross) > 256)
            goto next;
        param = ((x2 - x1) * (y1 - segZ1) - (y2 - y1) * (x1 - segX1)) << 8;
        if ((u32)(param / cross) > 256)
            goto next;
        return i;
    next:
        trackSeg++;
        i++;
    } while (reachedLast == 0);
    return -1;
}

void SetCarWaypointAtLaneDistance(s32 dist, const u16 *points, const struct LaneSeg *segments,
                                  struct Car *car)
{
    const struct LaneSeg *seg;
    s32 waypoint;

    seg = segments;
    if (seg->endDist < dist) {
        do {
            seg = seg + 1;
        } while (seg->endDist < dist);
    }
loop:
    waypoint = FindWaypointCrossing(points, seg);
    if (waypoint != -1)
        goto done;
    seg = seg + 1;
    if (seg->pointB == 0xFF) {
        car->lap = car->lap + 1;
        seg = segments;
    }
    goto loop;
done:
    car->waypoint = waypoint;
    car->subStep = 0xF;
}

void GetLanePositionAtDistance(s32 dist, struct LanePos *pos, const u16 *lanePoints, const struct LaneSeg *segments)
{
    register struct LanePos *posOut PIN(r8) = pos;
    register const u16 *points PIN(r6) = lanePoints;
    register const struct LaneSeg *seg PIN(r4) = segments;
    s32 scale;
    s32 rangeStart;

    if (seg->endDist < dist) {
        do {
            seg++;
        } while (seg->endDist < dist);
    }
    rangeStart = seg->startDist;
    scale = sub_08017230((dist - rangeStart) << 16, seg->endDist - rangeStart);
    {
        register const u16 *endPt PIN(r2);
        register const u16 *basePt PIN(r1);
        s32 x0;
        s32 x1;
        s32 y1;
        s32 y0;
        s32 dx;
        s32 dy;
        register s32 outY PIN(r0);

        x1 = seg->pointB;
#if PORTABLE
        /* Pointer-typed walk of the same byte offsets the GBA build does
           with integer address math (see the #else). */
        endPt = (const u16 *)((u8 *)points + x1 * 4);
        basePt = (const u16 *)((u8 *)points + seg->pointA * 4);
#else
        endPt = (const u16 *)(x1 * 4 + (u32)points);
        basePt = (const u16 *)(seg->pointA * 4 + (u32)points);
#endif
        x0 = basePt[0];
        x1 = endPt[0];
        dx = x1 - x0;
        y1 = endPt[1];
        y0 = basePt[1];
        dy = y1 - y0;
        dx = dx * scale >> 16;
        dy = dy * scale >> 16;
        x0 += dx;
        posOut->x = x0;
        outY = points[seg->pointA * 2 + 1] + dy;
        posOut->z = outY;
    }
}

void SetCarLane(struct Car *car, s32 lanePosition)
{
    s32 row = lanePosition >> 8;

    car->lanePosition = lanePosition;
    car->lanePoints = gLanePointTables[row + gTrackId * 12];
    car->laneSegments = gLaneSegmentTables[row + gTrackId * 12];
#if PORTABLE
    car->laneCellLists = gLaneCellLists[row + gTrackId * 12];
    car->laneCellGrid = gLaneCellGrids[row + gTrackId * 12];
#else
    car->laneCellLists = (u32)gLaneCellLists[row + gTrackId * 12];
    car->laneCellGrid = (u32)gLaneCellGrids[row + gTrackId * 12];
#endif
    car->laneLength = *(u16 *)gLaneLengthPtrs[row + gTrackId * 12];
}

void PlaceCarsAlongLane(struct Car **carOrder, s32 unused1, s32 unused2, s32 spacing, u8 singleLane)
{
    struct Car **carPtr;
    struct Car *car;
    struct LanePos pos;
    s32 dist;
    s32 i, k;
    s32 deltaX;
    s32 deltaZ;

    car = *carOrder;
    for (i = 0; i != 24; i++) {
        if (singleLane == 0) {
            if (i & 1)
                SetCarLane(car, 0x100);
            else
                SetCarLane(car, 0x500);
        } else {
            SetCarLane(car, 0x500);
        }
    }
    car = *carOrder;
    car->speed = 0;
    UpdateCarPredictedPos(car);
    car->predictedPosX = car->posX;
    car->predictedPosZ = car->posZ;
    if (FindClosestLaneSegment(car, 0) == -1)
        return;
    dist = WorldToLaneDistance(gClosestLanePointX, gClosestLanePointZ, car->lanePoints, gClosestLaneSegment,
                               gClosestLaneSegmentIndex);
    dist -= 5000;
    if (dist < 0)
        dist += car->laneLength;
    carPtr = carOrder;
    i = 0;
    if (i != gNumCars[0]) {
        do {
            car = *carPtr;
            if (singleLane != 0)
                SetCarLane(car, 0x500);
            else if (i & 1)
                SetCarLane(car, 0x100);
            else
                SetCarLane(car, 0x500);
            SetCarWaypointAtLaneDistance(dist, car->lanePoints, car->laneSegments, car);
            GetLanePositionAtDistance(dist, &pos, car->lanePoints, car->laneSegments);
            car->posX = pos.x << 16;
            car->posZ = pos.z << 16;
            GetLanePositionAtDistance(sub_080172C8(dist + 50, car->laneLength), &pos, car->lanePoints,
                                      car->laneSegments);
            deltaX = (pos.x << 16) - car->posX;
            deltaZ = (pos.z << 16) - car->posZ;
            /* Stored straight to the s16 field, the minus is done in
               HImode, which gives the ROM's constant copy (adds r1, r2, #0). */
            car->heading = -0x7C00 - (Atan2(deltaX >> 5, deltaZ >> 5) << 8);
            if (gGameMode == 15 && i == 0 && gChallengeIndex == 3)
                dist -= 500;
            /* Two copies, merged by cross-jumping after allocation. The two
               uses let loop.c hoist a3 * 3 / 2 and give it r10 ahead of
               the hoisted &out. */
            if (singleLane != 0) {
                dist -= spacing * 3 / 2;
                if (dist < 0)
                    dist += car->laneLength;
            } else if (i & 1) {
                dist -= spacing * 3 / 2;
                if (dist < 0)
                    dist += car->laneLength;
            }
            i++;
            carPtr++;
        } while (i != gNumCars[0]);
    }
    for (k = 0; k != 50; k++) {
        carPtr = carOrder;
        for (i = 0; i != gNumCars[0]; i++) {
            car = *carPtr++;
            UpdateAiDriver(car, (u8)i);
        }
    }
}

void SetCarLaneByIndex(struct Car *car, u8 laneIdx)
{
#if PORTABLE
    /* InitRaceCars initializes 24 cars, but each track has 12 lanes.
       Grid placement assigns the race lanes after initialization. */
    laneIdx %= 12;
#endif
    SetCarLane(car, laneIdx << 8);
}
