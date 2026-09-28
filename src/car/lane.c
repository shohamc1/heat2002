#include "global.h"

struct UnkStruct0800BBFC {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    u16 e;
    s32 f;
    s32 g;
    s32 h;
};
#include "variables.h"
#include "data.h"
struct VtxBC4C {
    u16 x, y;
};
struct UnkStruct0800BD44_Entry {
    u8 f0;
    u8 f1;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 pad[0xC];
};
struct UnkStruct0800BD44_Ctl {
    u8 pad[0x4C];
    u8 lap;
    u8 waypoint;
    u8 subStep;
};
#include "functions.h"
struct OutBD98 {
    s32 x;
    s32 y;
};
extern const u8 *const gLaneCellLists[];
extern const u8 *const gLaneCellGrids[];
struct Car {
    s32 posX;
    s32 unk04;
    s32 posZ;
    u8 pad0C[0x18 - 0x0C];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 speed;
    u8 pad30[0x34 - 0x30];
    s16 heading;
    u8 pad36[0xF4 - 0x36];
    s32 lanePoints;
    s32 laneSegments;
    u8 padFC[0x154 - 0xFC];
    s32 laneLength;
};
void UpdateCarPredictedPos(struct Car *a);
s32 FindClosestLaneSegment(struct Car *a, s32 b);
s32 Atan2(s32 a, s32 b);


s32 WorldToLaneDistance(s32 posX, s32 posZ, u16 *points, struct UnkStruct0800BBFC *seg, s32 unused)
{
    s32 ax;
    s32 bx;
    s32 az;
    s32 bz;
    s32 dx;
    s32 dy;
    s32 distAlong;
    s32 axisScale;

    ax = points[2 * seg->a];
    bx = points[2 * seg->b];
    az = points[2 * seg->a + 1];
    bz = points[2 * seg->b + 1];
    dx = bx - ax;
    if (dx < 0)
        dx = -dx;
    dy = bz - az;
    if (dy < 0)
        dy = -dy;
    if (dx > dy) {
        distAlong = posX - ax;
        axisScale = seg->g;
    } else {
        distAlong = posZ - az;
        axisScale = seg->h;
    }
    dx = distAlong * axisScale;
    return seg->d + (s32)((dx * (seg->e - seg->d)) >> 16);
}


s32 FindWaypointCrossing(struct VtxBC4C *points, u8 *laneSeg)
{
    struct TrackSeg *trackSeg = gTrackSegTables[gTrackId];
    s32 t[6];
    s32 x1, y1, x2, y2;
    s32 reachedLast;
    s32 i;
    s32 segX1, segZ1, segX2, segZ2, cross, param;

    t[0] = points[laneSeg[0]].x;
    t[1] = points[laneSeg[0]].y;
    t[2] = points[laneSeg[1]].x;
    t[3] = points[laneSeg[1]].y;
    x1 = t[0];
    y1 = t[1];
    x2 = t[2];
    y2 = t[3];
    reachedLast = 0;
    i = 0;
    do {
        segX1 = trackSeg->f0;
        segZ1 = trackSeg->f4;
        segX2 = trackSeg->f8;
        segZ2 = trackSeg->fC;
        if (trackSeg->unk10 == 1)
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


void SetCarWaypointAtLaneDistance(s32 dist, u16 *points, struct UnkStruct0800BD44_Entry *segments, struct UnkStruct0800BD44_Ctl *car)
{
    struct UnkStruct0800BD44_Entry *seg;
    s32 waypoint;

    seg = segments;
    if (seg->f6 < dist) {
        do {
            seg = seg + 1;
        } while (seg->f6 < dist);
    }
loop:
    waypoint = FindWaypointCrossing((struct VtxBC4C *)points, (u8 *)seg);
    if (waypoint != -1)
        goto done;
    seg = seg + 1;
    if (seg->f1 == 0xFF) {
        car->lap = car->lap + 1;
        seg = segments;
    }
    goto loop;
done:
    car->waypoint = waypoint;
    car->subStep = 0xF;
}


void GetLanePositionAtDistance(s32 dist, struct OutBD98 *pos, u16 *lanePoints, void *segments)
{
    register struct OutBD98 *posOut asm("r8") = pos;
    register u16 *points asm("r6") = lanePoints;
    register u8 *seg asm("r4") = segments;
    s32 scale;
    s32 rangeStart;

    if (((u16 *)seg)[3] < dist) {
        do {
            seg += 0x14;
        } while (((u16 *)seg)[3] < dist);
    }
    rangeStart = ((u16 *)seg)[2];
    scale = sub_08017230((dist - rangeStart) << 16,
                         ((u16 *)seg)[3] - rangeStart);
    {
        register u16 *endPt asm("r2");
        register u16 *basePt asm("r1");
        s32 x0;
        s32 x1;
        s32 y1;
        s32 y0;
        s32 dx;
        s32 dy;
        register s32 outY asm("r0");

        x1 = seg[1];
        endPt = (u16 *)(x1 * 4 + (u32)points);
        basePt = (u16 *)(seg[0] * 4 + (u32)points);
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
        outY = points[seg[0] * 2 + 1] + dy;
        posOut->y = outY;
    }
}


void SetCarLane(void *car, s32 lanePosition)
{
    s32 row = lanePosition >> 8;

    *(u32 *)((u8 *)car + 0xF0) = lanePosition;
    *(u32 *)((u8 *)car + 0xF4) = (u32)gLanePointTables[row + gTrackId * 12];
    *(u32 *)((u8 *)car + 0xF8) = (u32)gLaneSegmentTables[row + gTrackId * 12];
    *(u32 *)((u8 *)car + 0xFC) = (u32)gLaneCellLists[row + gTrackId * 12];
    *(u32 *)&((u16 *)car)[0x80] = (u32)gLaneCellGrids[row + gTrackId * 12];
    *(u32 *)&((u16 *)car)[0xAA] = *(u16 *)gLaneLengthPtrs[row + gTrackId * 12];
}


void PlaceCarsAlongLane(struct Car **carOrder, s32 unused1, s32 unused2, s32 spacing, u8 singleLane)
{
    struct Car **carPtr;
    struct Car *car;
    s32 pos[2];
    s32 dist;
    s32 i, k;
    s32 deltaX;
    s32 deltaZ;

    car = *carOrder;
    for (i = 0; i != 0x18; i++) {
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
    car->unk18 = car->posX;
    car->unk1C = car->posZ;
    if (FindClosestLaneSegment(car, 0) == -1)
        return;
    dist = WorldToLaneDistance(*(s32 *)&gClosestLanePointX, *(s32 *)&gClosestLanePointZ, car->lanePoints,
                     (struct UnkStruct0800BBFC *)*(s32 *)&gClosestLaneSegment, *(s32 *)&gClosestLaneSegmentIndex);
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
            SetCarWaypointAtLaneDistance(dist, car->lanePoints, (struct UnkStruct0800BD44_Entry *)car->laneSegments, (struct UnkStruct0800BD44_Ctl *)car);
            GetLanePositionAtDistance(dist,(struct OutBD98 *)pos,(u16 *)(car->lanePoints),(void *)(car->laneSegments));
            car->posX = pos[0] << 16;
            car->posZ = pos[1] << 16;
            GetLanePositionAtDistance(sub_080172C8(dist + 0x32, car->laneLength), pos, car->lanePoints,
                         (void *)car->laneSegments);
            deltaX = (pos[0] << 16) - car->posX;
            deltaZ = (pos[1] << 16) - car->posZ;
            /* Stored straight to the s16 field, the minus is done in
               HImode, which gives the ROM's constant copy (adds r1, r2, #0). */
            car->heading = -0x7C00 - (Atan2(deltaX >> 5, deltaZ >> 5) << 8);
            if (gGameMode[0] == 0xF && i == 0 && gChallengeIndex == 3)
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
    for (k = 0; k != 0x32; k++) {
        carPtr = carOrder;
        for (i = 0; i != gNumCars[0]; i++) {
            car = *carPtr++;
            UpdateAiDriver((struct Unk0800C534 *)car, (u8)i);
        }
    }
}


void SetCarLaneByIndex(u32 car, u8 laneIdx)
{
    SetCarLane((void *)car, laneIdx << 8);
}

