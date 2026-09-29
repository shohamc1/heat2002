#include "global.h"
#include "data.h"
#include "functions.h"
#include "car.h"

/* The task slot as DraftStreakTask sees it (0x44-byte struct Task). */
struct DraftStreak
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ s32 axialDist; /* 16.16 distance along the car's heading axis */
    /* 0x0C */ void (*callback)();
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 cornerIdx;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[0x10];
    /* 0x34 */ u8 carIdx;
};
/* The task slot as SkidSmokeTask sees it. */
struct SkidSmoke
{
    /* 0x00 */ s32 posX;
    /* 0x04 */ s32 rise;
    /* 0x08 */ s32 posZ;
    /* 0x0C */ void (*callback)();
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 cornerIdx;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ s32 velX;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ s32 velZ;
    /* 0x34 */ u8 carIdx;
};
/* The task slot as DamageSmokeTask sees it. */
struct DamageSmoke
{
    /* 0x00 */ s32 posX;
    /* 0x04 */ s32 rise;
    /* 0x08 */ s32 posZ;
    /* 0x0C */ void (*callback)();
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 riseRate;
    /* 0x20 */ u8 pad20[8];
    /* 0x28 */ s32 velX;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ s32 velZ;
};
struct ObjTileCacheEntry
{
    u8 pad00[0x10]; /* age, pending, unk05-07, gfx, vramDest */
    u32 tileIndex;  /* OAM attr2 base: tile number, OR'd with palette/priority at each use */
};

void DraftStreakTask(struct DraftStreak *);
extern const u8 *const gDraftStreakFrames[];
extern u8 gDraftStreakPalette[];
u32 WorldToScreen(s32 x, s32 y, s32 *out);
u32 *RequestObjTiles1Compressed(u32 a);
void SkidSmokeTask(struct SkidSmoke *);
extern const u8 *const gSkidSmokeFrames[]; /* 0x083FF60C */
extern u8 gSkidSmokePalette[];             /* 0x08330D18 */
void DamageSmokeTask(struct DamageSmoke *);
extern const u8 *const gDamageSmokeFrames[];
extern u8 gDamageSmokePalettes[];
u32 GetTrackTileType(s32 x, s32 y);

void DummyWallHitHook(void)
{}

void AddDraftStreakTask(u8 carIdx, u8 cornerIdx)
{
    struct DraftStreak *task;

    task = AllocTask();
    if (task != 0) {
        task->timer = 0;
        task->carIdx = carIdx;
        task->unk20 = 2;
        task->unk00 = 0;
        task->unk04 = 0;
        task->axialDist = 0x80000;
        task->cornerIdx = cornerIdx;
        task->callback = DraftStreakTask;
        AddTask(task);
    }
}

void DraftStreakTask(struct DraftStreak *e)
{
    struct Car *car;
    s32 pos[2];
    s32 cornerX;
    s32 cornerZ;
    s32 angle;
    s32 sin;
    s32 cos;
    s32 rel;
    s32 dx;
    s32 dy;
    u32 *sprite;
    u32 attr;
    u32 palBits;
    u32 attr2;
    s32 screenX;
    car = &gCars[e->carIdx];
    cornerX = car->nextCornerX[e->cornerIdx + 2];
    cornerZ = car->nextCornerZ[e->cornerIdx + 2];
    angle = car->heading >> 8;
    sin = gSinTable[angle];
    cos = gSinTable[angle + 0x40];
    rel = (dy = e->axialDist + 0xFFF60000);
    dx = (-(rel * sin)) >> 8;
    dy = (dy * cos) >> 8;
    cornerX = cornerX + dx;
    cornerZ = cornerZ + dy;
    if ((WorldToScreen(cornerX, cornerZ, pos) << 0x18) != 0) {
        screenX = pos[0];
        pos[0] = screenX - 4;
        pos[1] = pos[1] - 6;
        if (((((u32)(screenX + 0x1B)) <= 0x10E) && (pos[1] <= 0x9F)) && (pos[1] > (-0x20))) {
            sprite = RequestObjTiles1Compressed(gDraftStreakFrames[e->timer & 0xF]);
            if (sprite != 0) {
                attr = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 0x10);
                palBits = (RequestObjPalette((u32)gDraftStreakPalette) << 12) | 0x800;
                attr2 = sprite[4] | palBits;
                AddOamEntry(attr, attr2);
            }
        }
    }
    e->timer = e->timer + 1;
    e->axialDist = e->axialDist + 0x10000;
    if (e->timer == 0x10) {
        RemoveTask(e);
        FreeTask(e);
    }
}

void AddSkidSmokeTask(u8 carIdx, u8 cornerIdx)
{
    struct SkidSmoke *task;
    u32 cornerX, cornerZ;
    struct Car *car;

    task = AllocTask();
    if (task != 0) {
        car = &gCars[carIdx];
        task->timer = 0;
        task->carIdx = carIdx;
        task->cornerIdx = cornerIdx;
        task->unk20 = 2;
        cornerX = car->nextCornerX[cornerIdx];
        task->posX = cornerX;
        task->rise = 0;
        cornerZ = car->nextCornerZ[cornerIdx];
        task->posZ = cornerZ;
        task->velX = cornerX - car->cornerX[cornerIdx];
        task->velZ = cornerZ - car->cornerZ[cornerIdx];
        task->callback = SkidSmokeTask;
        AddTask(task);
    }
}

void SkidSmokeTask(struct SkidSmoke *e)
{
    s32 pos[2];
    u32 *sprite;
    u32 attr;
    u32 palBits;
    u32 attr2;
    s32 screenX;
    s32 riseY;

    if ((WorldToScreen(e->posX, e->posZ, pos) << 0x18) != 0) {
        screenX = pos[0];
        pos[0] = screenX - 4;
        riseY = pos[1] - 4;
        pos[1] = riseY + (e->rise >> 2);
        if ((u32)(screenX + 0x1B) <= 0x10E && pos[1] <= 0x9F && pos[1] > -0x20) {
            sprite = RequestObjTiles1Compressed(gSkidSmokeFrames[((e->timer + 8) & 7) + 8]);
            if (sprite != 0) {
                attr = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 0x10);
                palBits = (RequestObjPalette((u32)gSkidSmokePalette) << 12) | 0x800;
                attr2 = sprite[4] | palBits;
                AddOamEntry(attr, attr2);
            }
        }
    }
    e->timer = e->timer + 2;
    e->rise = e->rise - 1;
    e->posX = e->posX + (e->velX >> 1);
    e->posZ = e->posZ + (e->velZ >> 1);
    if (e->timer == 0x10) {
        RemoveTask(e);
        FreeTask(e);
    }
}

void AddDamageSmokeTask(s32 *car)
{
    struct DamageSmoke *task;

    task = AllocTask();
    if (task != 0) {
        task->timer = 0;
        task->riseRate = 2;
        task->posX = car[0];
        task->rise = -6;
        task->posZ = car[2];
        task->velX = car[3] >> 1;
        task->velZ = car[5] >> 1;
        task->callback = DamageSmokeTask;
        AddTask(task);
    }
}

void DamageSmokeTask(struct DamageSmoke *e)
{
    s32 out[2];
    struct ObjTileCacheEntry *sprite;
    u32 attr;
    u32 palBits;
    u8 tileType;
    s32 screenX;
    s32 screenY;
    s32 frame;

    if (((u32)WorldToScreen(e->posX, e->posZ, out) << 24) != 0) {
        screenX = out[0];
        out[0] = screenX - 8;
        screenY = out[1] - 8;
        out[1] = screenY + (e->rise >> 1);
        if ((u32)(screenX + 0x17) <= 0x10E && out[1] <= 0x9F && out[1] > -0x10) {
            sprite = RequestObjTiles16(gDamageSmokeFrames[e->timer & 0x1F]);
            if (sprite != 0) {
                tileType = GetTrackTileType(e->posX >> 19, e->posZ >> 19);
                if (tileType & 1) {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)RequestObjPalette((u32)gDamageSmokePalettes) << 12) | 0x800;
                    AddOamEntry(attr, sprite->tileIndex | palBits);
                } else {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)RequestObjPalette((u32)gDamageSmokePalettes) << 12) | 0x400;
                    AddOamEntry(attr, sprite->tileIndex | palBits);
                }
            }
        }
    }
    frame = e->timer + 1;
    e->timer = frame;
    e->rise = e->rise - e->riseRate;
    e->posX = e->posX + e->velX;
    e->posZ = e->posZ + e->velZ;
    if (frame == 0x20) {
        RemoveTask(e);
        FreeTask(e);
    }
}
