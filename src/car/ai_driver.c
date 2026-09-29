#include "global.h"
#include "variables.h"
#include "car.h"
#include "data.h"
#include "functions.h"

struct Unk0800C28C
{
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
struct Unk0800C358
{
    u8 unk00[0x18];
    s32 unk18;
    s32 unk1C;
    u8 unk20[0xD4];
    const u16 *lanePoints;
    const struct LaneSeg *laneSegments;
    u32 *unkFC;
    u16 *unk100;
};

void SetAiDriverGearTables(struct Car *car);
void FindCarAhead(struct Car *car);
u32 FindClosestLaneSegment(struct Unk0800C358 *car);
void UpdateCarPredictedPos(struct Unk0800C28C *car);
s32 Atan2(s32 a, s32 b);

void UpdateCarPredictedPos(struct Unk0800C28C *car)
{
    if (car->speed > (s32)0xFFFF0000) {
        car->unk18 = car->posX;
        car->unk1C = car->posZ;
    } else {
        car->unk18 = car->posX + car->velX * 8 + car->velX * 4 + car->velX * 2;
        car->unk1C = car->posZ + car->velZ * 8 + car->velZ * 4 + car->velX * 2;
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
    endPt = (const u16 *)(4 * seg->pointB + (u32)points);
    proj = (posX - ax) * (*endPt - ax);
    closestX = endPt[1];
    dx = posZ - az;
    proj = proj + dx * (closestX - az);
    proj *= seg->unk2;
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
    gClosestLaneSegment[0] = seg;
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
        seg = segments + segIdx;
        dist = ComputeLaneSegmentDistSq(carX, carZ, points, seg);
        if (dist <= bestDist) {
            bestDist = dist;
            gClosestLaneSegment[0] = seg;
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
    stallZPtr = (s32 *)((stallIdx * 2 + 1) * 4 + (u32)stalls);
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
    u32 buf[2];
    s32 angle;
    u16 *pA0;
    register s32 result asm("r8");
    register s32 zero asm("r9");
    u32 *bufp;
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
    if (gAiCarAheadSide == 0 || gGameMode[0] == 9 || gGameMode[0] == 0xD || gGameMode[0] == 0xE ||
        gGameMode[0] == 0xF || gGameMode[0] == 0x11) {
        ent->aiInput = 1;
        gAiCarAheadSide = 0;
        pA0 = &ent->aiInput;
    } else {
        if (ent->pitState == 0 && (-ent->speed) >> 12 > 0x28)
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
    ((void (*)(struct Car *))UpdateCarPredictedPos)(ent);
    result = ((s32 (*)(u32, u32))FindClosestLaneSegment)((u32)ent, param);
    if (result == -1)
        return;
    diff = WorldToLaneDistance((*(u32 *)&gClosestLanePointX), (*(u32 *)&gClosestLanePointZ), ent->lanePoints,
                               gClosestLaneSegment[0], (*(u32 *)&gClosestLaneSegmentIndex));
    diff = diff + 0x40;
    if (diff >= ent->laneLength)
        diff = diff - ent->laneLength;
    GetLanePositionAtDistance(diff, (struct OutBD98 *)buf, ent->lanePoints, ent->laneSegments);
    ps = &ent->pitState;
    stv = 0;
    stv = *ps;
    bufp = buf;
    if (stv != 0) {
        if (stv == 1) {
            if (ComputePitStallDistance(ent) <= 0x63 || (gTrackId == 3 && ComputePitStallDistance(ent) <= 0xC7))
                *ps = 2;
        }
        if (ent->pitState == 2) {
            if (ComputePitStallDistance(ent) <= 0x13 || gDamagePitsEnabled == 0 ||
                (ent == gCars && gPitMenuActive == 0 && gPitServiceEnabled == 0))
                ent->pitState = 3;
            buf[0] = gPitStallPositions[(gTrackId * 8 + ent->pitStall) * 2];
            bufp[1] = gPitStallPositions[(gTrackId * 8 + ent->pitStall) * 2 + 1];
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
    if (gGameMode[0] == 9 || gGameMode[0] == 0xD || gGameMode[0] == 0xE || gGameMode[0] == 0xF || gGameMode[0] == 0x11)
        limit = -99;
    if (result > limit || ent->pitState != 0) {
        diffxy = (buf[0] << 16) - ent->posX;
        dya = (bufp[1] << 16) - ent->posZ;
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
            if ((d2 < 0 ? -d2 : d2) <= 0x3FF || gTrackId == 3 || gTrackId == 1 || gTrackId == 9 ||
                ((d2 < 0 ? -d2 : d2) <= 0xFFF && (gTrackId == 4 || gTrackId == 2)))
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
        if ((diffxy < 0 ? -diffxy : diffxy) > 0x1F4 && (-ent->speed) >> 12 > 0x28)
            *pA0 = *pA0 & 0xFFFE;
        if ((diffxy < 0 ? -diffxy : diffxy) > 0x28A && (-ent->speed) >> 12 > 0x28)
            *pA0 = 2;
    }
    if (ent->pitState == 1 && (-ent->speed) >> 12 > 0x50)
        *pA0 = 2;
    {
        u8 st2 = ent->pitState;
        if (st2 == 2 && (-ent->speed) >> 12 > 0x28)
            *pA0 = st2;
    }
    if (ent->pitState == 3 && (-ent->speed) >> 12 > 0xA)
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
