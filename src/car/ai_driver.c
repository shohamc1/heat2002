#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "car.h"
#include "data.h"
#include "functions.h"

void FindCarAhead(struct Car *car);

/* The file's six RAM variables (the three ClosestLane s32 arrays and
   pointer array -- one element each, every user reads [0] -- with
   gAiCarAheadSide and gUnk_0202CC2C) moved to src/race/globals.c, the
   owner of the 0x0202CBE0-0x0202CCD0 EWRAM run they sit in; they are
   declared in variables.h. */

void UpdateCarPredictedPos(struct Car *car)
{
    if (car->speed > (s32)0xFFFF0000) {
        car->predictedPosX = car->posX;
        car->predictedPosZ = car->posZ;
    } else {
        car->predictedPosX = car->posX + car->velX * 8 + car->velX * 4 + car->velX * 2;
        car->predictedPosZ = car->posZ + car->velZ * 8 + car->velZ * 4 + car->velX * 2;
    }
}

u32 ComputeLaneSegmentDistSq(s32 posX, s32 posZ, const u16 *points, const struct LaneSeg *seg)
{
    const u16 *endPt;
    s32 ax;
    s32 az;
    s32 dx;
    s32 dy;
    s32 proj;
    s32 closestX;
    s32 closestZ;

    ax = points[2 * seg->pointA];
    az = points[(2 * seg->pointA) + 1];
#if PORTABLE
    /* Pointer-typed walk of the same byte offsets the GBA build does with
       integer address math (see the #else). */
    endPt = (const u16 *)((const u8 *)points + 4 * seg->pointB);
#else
    endPt = (const u16 *)(4 * seg->pointB + (u32)points);
#endif
    proj = (posX - ax) * (*endPt - ax);
    closestX = endPt[1];
    dx = posZ - az;
    proj = proj + dx * (closestX - az);
    proj *= seg->projScale;
    if (proj < 0)
        proj = 0;
    if (proj > 0xFFFF)
        proj = 0xFFFF;
    dx = *endPt - ax;
    dy = endPt[1] - az;
    closestX = ax + ((dx * proj) >> 16);
    closestZ = az + ((dy * proj) >> 16);
    gClosestLanePointX = closestX;
    gClosestLanePointZ = closestZ;
    closestX = (posX - closestX) >> 2;
    closestZ = (posZ - closestZ) >> 2;
    proj = closestX * closestX + closestZ * closestZ;
    return proj;
}

s32 FindClosestLaneSegment(struct Car *car, s32 unused)
{
    const struct LaneSeg *segments;
    const u16 *points;
    u32 bestDist;
    const struct LaneSeg *seg;
    s32 carX;
    s32 carZ;
    s32 cellX;
    s32 cellZ;
    u8 *cell;
    u8 segIdx;
    u32 dist;
    u32 bestX;
    u32 bestZ;

    segments = car->laneSegments;
    points = car->lanePoints;
    bestDist = -1;
    gClosestLaneSegment = seg;
    carX = car->predictedPosX >> 16;
    carZ = car->predictedPosZ >> 16;
    cellX = car->predictedPosX >> 23;
    cellZ = car->predictedPosZ >> 23;
    if (cellX < 0)
        cellX = 0;
    if (cellZ < 0)
        cellZ = 0;
    if (cellX > 47)
        cellX = 47;
    if (cellZ > 47)
        cellZ = 47;
    /* Offset first preserves the ROM register and address-load order. */
    cell = (u8 *)(((u16 *)car->laneCellGrid)[cellZ * 48 + cellX] + car->laneCellLists);
    while (*cell != 0xFF) {
        segIdx = *cell;
        seg = segments + segIdx;
        dist = ComputeLaneSegmentDistSq(carX, carZ, points, seg);
        if (dist <= bestDist) {
            bestDist = dist;
            gClosestLaneSegment = seg;
            gClosestLaneSegmentIndex = segIdx;
            bestX = gClosestLanePointX;
            bestZ = gClosestLanePointZ;
        }
        cell++;
    }
    gClosestLanePointX = bestX;
    gClosestLanePointZ = bestZ;
    return bestDist;
}

void FindCarAhead(struct Car *car)
{
    s32 localPos[2];
    s32 carIdx;
    s32 delta;
    struct Car *other = gCars;
    u8 *sidePtr = &gAiCarAheadSide;
    u8 *side;

    *sidePtr = 0;
    gUnk_0202CC2C = 0;
    carIdx = 0;
    if (carIdx == gNumCars[0])
        return;
    side = sidePtr;
    do {
        if (car == other)
            continue;
        delta = other->posX - car->posX;
        if (delta < 0)
            delta = -delta;
        if (delta > 0xFA0000)
            continue;
        delta = other->posZ - car->posZ;
        if (delta < 0)
            delta = -delta;
        if (delta > 0xFA0000)
            continue;
        WorldToCarLocal(car, other->posX, other->posZ, localPos);
        if (localPos[1] > -16)
            continue;
        if (localPos[0] < -16)
            continue;
        if (localPos[0] > 16)
            continue;
        if (localPos[1] > -128)
            gUnk_0202CC2C = 1;
        if (localPos[1] < -64)
            continue;
        if (localPos[0] < 0)
            *side = 1;
        else
            *side = 2;
    } while (++carIdx, other++, carIdx != gNumCars[0]);
}

s32 ComputePitStallDistance(struct Car *car)
{
    s32 *stalls;
    s32 *stallZPtr;
    s32 stallIdx;
    s32 dx;
    s32 dz;
    s32 carX;
    s32 carZ;

    stalls = (s32 *)gPitStallPositions;
    stallIdx = gTrackId * 8 + car->pitStall;
    dx = stalls[stallIdx * 2];
#if PORTABLE
    stallZPtr = (s32 *)((u8 *)stalls + (stallIdx * 2 + 1) * 4);
#else
    stallZPtr = (s32 *)((stallIdx * 2 + 1) * 4 + (u32)stalls);
#endif
    dz = *stallZPtr;
    carX = ((s16 *)&car->posX)[1]; /* high half of posX */
    carZ = ((s16 *)&car->posZ)[1]; /* high half of posZ */
    dx = dx - carX;
    if (dx < 0)
        dx = -dx;
    carZ = dz - carZ;
    if (carZ < 0)
        carZ = -carZ;
    if (dx > carZ)
        carZ = dx;
    return carZ;
}

void UpdateAiDriver(struct Car *ent, u8 param)
{
    register u8 stv;
    u32 pad[10];
    struct LanePos target;
    s32 angle;
    u16 *pA0;
    register s32 result PIN(r8);
    register s32 zero PIN(r9);
    struct LanePos *targetp;
    u8 *ps;

    s32 diff;
    s32 angl;
    s32 diffxy;
    s32 limit;
    s32 d34;
    s32 d2;
    s32 dya;
    s32 t1;
    s32 t2;
    s32 t3;

    SetAiDriverGearTables(ent);
    FindCarAhead(ent);
    zero = 0;
    if (gAiCarAheadSide == 0 || gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 ||
        gGameMode == 17) {
        ent->aiInput = 1;
        gAiCarAheadSide = 0;
        pA0 = &ent->aiInput;
    } else {
        if (ent->pitState == 0 && (-ent->speed) >> 12 > 40)
            ent->aiInput = ent->aiInput & 0xFFFE;
        else
            ent->aiInput = 1;
        pA0 = &ent->aiInput;
        if (ent->pitState == 0) {
            if (gUnk_0202CC2C != 0)
                *pA0 = 2;
            if (gAiCarAheadSide != 0) {
                ent->lanePosition = (ent->lanePosition - 0x20) & 0x7FF;
                if (ent->lanePosition <= 0x100)
                    ent->lanePosition = 0x6FF;
                SetCarLane(ent, ent->lanePosition);
            }
        }
    }
    UpdateCarPredictedPos(ent);
    result = FindClosestLaneSegment(ent, param);
    if (result == -1)
        return;
    diff = WorldToLaneDistance(gClosestLanePointX, gClosestLanePointZ, ent->lanePoints, gClosestLaneSegment,
                               gClosestLaneSegmentIndex);
    diff = diff + 0x40;
    if (diff >= ent->laneLength)
        diff = diff - ent->laneLength;
    GetLanePositionAtDistance(diff, &target, ent->lanePoints, ent->laneSegments);
    ps = &ent->pitState;
    stv = 0;
    stv = *ps;
    targetp = &target;
    if (stv != 0) {
        if (stv == 1) {
            if (ComputePitStallDistance(ent) <= 99 || (gTrackId == 3 && ComputePitStallDistance(ent) <= 199))
                *ps = 2;
        }
        if (ent->pitState == 2) {
            if (ComputePitStallDistance(ent) <= 19 || gDamagePitsEnabled == 0 ||
                (ent == gCars && gPitMenuActive == 0 && gPitServiceEnabled == 0))
                ent->pitState = 3;
            target.x = gPitStallPositions[(gTrackId * 8 + ent->pitStall) * 2];
            targetp->z = gPitStallPositions[(gTrackId * 8 + ent->pitStall) * 2 + 1];
        }
        if (ent->pitState == 3) {
            if (gDamagePitsEnabled == 0)
                ent->pitState = 4;
            t1 = gPitStallPositions[(gTrackId * 8 + 6) * 2];
            t2 = gPitStallPositions[(gTrackId * 8 + 6) * 2 + 1];
            t3 = gPitStallPositions[(gTrackId * 8 + 7) * 2];
            angle = -(Atan2(t1 - t3, t2 - gPitStallPositions[(gTrackId * 8 + 7) * 2 + 1]) << 8) + 0x8400;
        }
    }
    limit = 4;
    if (gGameMode == 9 || gGameMode == 13 || gGameMode == 14 || gGameMode == 15 || gGameMode == 17)
        limit = -99;
    if (result > limit || ent->pitState != 0) {
        diffxy = (target.x << 16) - ent->posX;
        dya = (targetp->z << 16) - ent->posZ;
        angl = 0x8400 - (Atan2(diffxy >> 5, dya >> 5) << 8);
        if (ent->pitState != 0) {
            d34 = angl - ent->heading;
            if (d34 < 0)
                d34 = -d34;
            if (d34 > 0x4000) {
                ent->heading = angl;
                ent->steerHeading = angl;
            }
        }
        if (ent->pitState == 3)
            diffxy = angle - ent->steerHeading;
        else
            diffxy = angl - ent->steerHeading;
        diffxy = diffxy << 16;
        diffxy = diffxy >> 16;
        if (ent->pitState == 3) {
            d2 = angle - ent->heading;
            d2 = d2 << 16;
            d2 = d2 >> 16;
            if (ABS2(d2) <= 0x3FF || gTrackId == 3 || gTrackId == 1 || gTrackId == 9 ||
                (ABS2(d2) <= 0xFFF && (gTrackId == 4 || gTrackId == 2)))
                ent->pitState = 4;
        }
        if (ent->pitState == 0 && gAiCarAheadSide == 0)
            diffxy = diffxy / 8;
        if (gAiCarAheadSide != 0)
            diffxy = diffxy * 4;
        if (ent->speed > 0)
            ent->steerHeading = -angl;
        else
            ent->steerHeading = ent->steerHeading + diffxy;
        if (ABS2(diffxy) > 500 && (-ent->speed) >> 12 > 40)
            *pA0 = *pA0 & 0xFFFE;
        if (ABS2(diffxy) > 650 && (-ent->speed) >> 12 > 40)
            *pA0 = 2;
    }
    if (ent->pitState == 1 && (-ent->speed) >> 12 > 80)
        *pA0 = 2;
    {
        u8 st2 = ent->pitState;
        if (st2 == 2 && (-ent->speed) >> 12 > 40)
            *pA0 = st2;
    }
    if (ent->pitState == 3 && (-ent->speed) >> 12 > 10)
        *pA0 = 2;
    if (zero != 0) {
        zero = (s16)zero;
        ent->steerHeading = ent->steerHeading + zero;
    }
}

void InitCarSteering(s32 *steer, u32 heading)
{
    steer[1] = heading;
    steer[0] = heading;
}
