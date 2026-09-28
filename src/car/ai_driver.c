#include "global.h"

struct Unk0800C28C {
    u32 posX;
    u32 unk04;
    u32 posZ;
    u32 velX;
    u32 unk10;
    u32 velZ;
    u32 unk18;
    u32 unk1C;
    s32 unk20;
    u32 unk24;
    u32 unk28;
    s32 speed;
};
#include "variables.h"
struct Unk0800C358 {
    u8 unk00[0x18];
    s32 unk18;
    s32 unk1C;
    u8 unk20[0xD4];
    u32 *lanePoints;
    u32 *laneSegments;
    u32 *unkFC;
    u16 *unk100;
};
/*
 * PARKED (wave 4): rebuild diverges from the ROM (first diff at ROM
 * 0x0800C430: ours pushes {r4,r5,r6,lr} vs ROM {r4-r7,lr}). Dead-agent
 * mid-edit state whose rebuild diverges while a stale .o once matched.
 * Needs re-derivation from the asm before extracting.
 */
#include "car.h"
void WorldToCarLocal(s32 *a, s32 b, s32 c, s32 *d);


void UpdateCarPredictedPos(struct Unk0800C28C *car)
{
    if (car->speed > (s32)0xFFFF0000)
    {
        car->unk18 = car->posX;
        car->unk1C = car->posZ;
    }
    else
    {
        car->unk18 = car->posX + car->velX * 8 + car->velX * 4 + car->velX * 2;
        car->unk1C = car->posZ + car->velZ * 8 + car->velZ * 4 + car->velX * 2;
    }
}


u32 ComputeLaneSegmentDistSq(s32 posX, s32 posZ, u16 *points, u8 *seg)
{
    u16 *endPt;
    s32 ax;
    s32 az;
    s32 dx;
    s32 dy;
    s32 proj;
    s32 closestX;
    s32 closestZ;

    ax = points[2 * seg[0]];
    az = points[(2 * seg[0]) + 1];
    endPt = (u16 *)(4 * seg[1] + (u32)points);
    proj = (posX - ax) * (*endPt - ax);
    closestX = endPt[1];
    dx = posZ - az;
    proj = proj + dx * (closestX - az);
    proj *= seg[2];
    if (proj < 0)
        proj = 0;
    if (proj > 0xFFFF)
        proj = 0xFFFF;
    dx = *endPt - ax;
    dy = endPt[1] - az;
    closestX = ax + ((dx * proj) >> 16);
    closestZ = az + ((dy * proj) >> 16);
    gClosestLanePointX[0] = closestX;
    gClosestLanePointZ[0] = closestZ;
    closestX = (posX - closestX) >> 2;
    closestZ = (posZ - closestZ) >> 2;
    proj = closestX * closestX + closestZ * closestZ;
    return proj;
}


u32 FindClosestLaneSegment(struct Unk0800C358 *car)
{
    u32 *segments;
    u32 *points;
    u32 bestDist;
    u8 *seg;
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
    gClosestLaneSegment[0] = (u32)seg;
    carX = car->unk18 >> 16;
    carZ = car->unk1C >> 16;
    cellX = car->unk18 >> 23;
    cellZ = car->unk1C >> 23;
    if (cellX < 0)
        cellX = 0;
    if (cellZ < 0)
        cellZ = 0;
    if (cellX > 47)
        cellX = 47;
    if (cellZ > 47)
        cellZ = 47;
    /* Offset first preserves the ROM register and address-load order. */
    cell = (u8 *)(car->unk100[cellZ * 48 + cellX] + (u32)car->unkFC);
    while (*cell != 0xFF) {
        segIdx = *cell;
        seg = (u8 *)segments + segIdx * 20;
        dist = ComputeLaneSegmentDistSq(carX, carZ, points, seg);
        if (dist <= bestDist) {
            bestDist = dist;
            gClosestLaneSegment[0] = (u32)seg;
            gClosestLaneSegmentIndex[0] = segIdx;
            bestX = gClosestLanePointX[0];
            bestZ = gClosestLanePointZ[0];
        }
        cell++;
    }
    gClosestLanePointX[0] = bestX;
    gClosestLanePointZ[0] = bestZ;
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

