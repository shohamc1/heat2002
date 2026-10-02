#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

void ModuleDraftStreakTask(struct DraftStreak *task);
void ModuleSkidSmokeTask(struct SkidSmoke *e);
void ModuleDamageSmokeTask(struct DamageSmoke *e);
extern u32 gModule_DamageSmokeFrames[];
extern const u8 gModule_SkidSmokePalette[];

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

void ModuleAddDamageSmokeTask(struct Car *car)
{
    struct DamageSmoke *task;

    task = ModuleAllocTask();
    if (task != 0) {
        task->timer = 0;
        task->riseRate = 2;
        task->posX = car->posX;
        task->rise = -6;
        task->posZ = car->posZ;
        task->velX = car->velX >> 1;
        task->velZ = car->velZ >> 1;
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
        if ((u32)(screenX + 0x17) <= 0x10E && out[1] <= 159 && out[1] > -0x10) {
            sprite = ModuleRequestObjTiles16(gModule_DamageSmokeFrames[e->timer & 0x1F]);
            if (sprite != 0) {
                tileType = ModuleGetTrackTileType(e->posX >> 19, e->posZ >> 19);
                if (tileType & 1) {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)ModuleRequestObjPalette(gModule_SkidSmokePalette) << 12) | 0x800;
                    ModuleAddOamEntry(attr, sprite->tileIndex | palBits);
                } else {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)ModuleRequestObjPalette(gModule_SkidSmokePalette) << 12) | 0x400;
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
