#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

/* The module task slot as the particle tasks see it (struct Task). */
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

void ModuleDraftStreakTask(struct DraftStreak *task);
u8 ModuleWorldToScreen(s32 x, s32 y, s32 *out);
void ModuleSkidSmokeTask(struct SkidSmoke *e);
void ModuleDamageSmokeTask(struct DamageSmoke *e);
extern u32 gUnk_0202B370[];
extern u8 gUnk_0201F370[];
u32 *ModuleRequestObjTiles16(u32 a);
u32 ModuleGetTrackTileType(s32 x, s32 y);
s32 ModuleRequestObjPalette(u32 a);
u32 ModuleAddOamEntry(u32 a, u32 b);

void ModuleDummyWallHitHook(s32 cornerX, s32 cornerZ)
{}

void ModuleAddDraftStreakTask(u8 carIdx, u8 cornerIdx)
{
    struct DraftStreak *task;

    task = ModuleAllocTask();
    if (task != 0) {
        task->timer = 0;
        task->carIdx = carIdx;
        task->unk20 = 2;
        task->unk00 = 0;
        task->unk04 = 0;
        task->axialDist = 0x80000;
        task->cornerIdx = cornerIdx;
        task->callback = ModuleDraftStreakTask;
        ModuleAddTask(task);
    }
}

void ModuleDraftStreakTask(struct DraftStreak *task)
{
    struct Car *car;
    s32 pos[2];
    s32 cornerX;
    s32 cornerZ;
    s32 idx;
    s32 sin;
    s32 cos;
    s32 rel;
    s32 dx;
    s32 dy;
    s32 counter;

    car = &gModule_Cars[task->carIdx];
    cornerX = car->nextCornerX[task->cornerIdx + 2];
    cornerZ = car->nextCornerZ[task->cornerIdx + 2];
    idx = car->heading >> 8;
    sin = gModule_SinTable[idx];
    cos = gModule_SinTable[idx + 0x40];
    dy = task->axialDist + 0xFFF60000;
    rel = dy;
    dx = -(rel * sin) >> 8;
    dy = (cos * rel) >> 8;
    if (ModuleWorldToScreen(cornerX + dx, cornerZ + dy, pos) != 0) {
        pos[0] -= 4;
        pos[1] -= 6;
    }
    counter = task->timer + 1;
    task->timer = counter;
    task->axialDist += 0x10000;
    if (counter == 0x10) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}

void ModuleAddSkidSmokeTask(u8 carIdx, u8 cornerIdx)
{
    struct SkidSmoke *task;
    struct Car *car;
    u32 cornerX;
    u32 cornerZ;

    task = ModuleAllocTask();
    if (task != 0) {
        car = &gModule_Cars[carIdx];
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
        task->callback = ModuleSkidSmokeTask;
        ModuleAddTask(task);
    }
}

void ModuleSkidSmokeTask(struct SkidSmoke *e)
{
    s32 pos[2];
    s32 frame;
    s32 riseY;

    if (ModuleWorldToScreen(e->posX, e->posZ, pos) != 0) {
        pos[0] -= 4;
        riseY = pos[1] - 4;
        pos[1] = riseY + (e->rise >> 2);
    }
    frame = e->timer + 2;
    e->timer = frame;
    e->rise -= 1;
    e->posX += e->velX >> 1;
    e->posZ += e->velZ >> 1;
    if (frame == 0x10) {
        ModuleRemoveTask(e);
        ModuleFreeTask(e);
    }
}

void ModuleAddDamageSmokeTask(s32 *car)
{
    struct DamageSmoke *task;

    task = ModuleAllocTask();
    if (task != 0) {
        task->timer = 0;
        task->riseRate = 2;
        task->posX = car[0];
        task->rise = -6;
        task->posZ = car[2];
        task->velX = car[3] >> 1;
        task->velZ = car[5] >> 1;
        task->callback = ModuleDamageSmokeTask;
        ModuleAddTask(task);
    }
}

void ModuleDamageSmokeTask(struct DamageSmoke *e)
{
    s32 out[2];
    struct ObjTileCacheEntry *sprite;
    u32 attr;
    u32 palBits;
    u8 tileType;
    s32 screenX;
    s32 screenY;
    s32 frame;

    if ((ModuleWorldToScreen(e->posX, e->posZ, out) << 24) != 0) {
        screenX = out[0];
        out[0] = screenX - 8;
        screenY = out[1] - 8;
        out[1] = screenY + (e->rise >> 1);
        if ((u32)(screenX + 0x17) <= 0x10E && out[1] <= 0x9F && out[1] > -0x10) {
            sprite = ModuleRequestObjTiles16(gUnk_0202B370[e->timer & 0x1F]);
            if (sprite != 0) {
                tileType = ModuleGetTrackTileType(e->posX >> 19, e->posZ >> 19);
                if (tileType & 1) {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)ModuleRequestObjPalette((u32)gUnk_0201F370) << 12) | 0x800;
                    ModuleAddOamEntry(attr, sprite->tileIndex | palBits);
                } else {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)ModuleRequestObjPalette((u32)gUnk_0201F370) << 12) | 0x400;
                    ModuleAddOamEntry(attr, sprite->tileIndex | palBits);
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
        ModuleRemoveTask(e);
        ModuleFreeTask(e);
    }
}
