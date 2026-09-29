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
    /* 0x0C */ u32 callback;
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
    /* 0x0C */ u32 callback;
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
    /* 0x0C */ u32 callback;
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

void *ModuleAllocTask(void);
void ModuleAddTask(u32);
void ModuleDraftStreakTask(u32 task);
u8 ModuleWorldToScreen(s32 x, s32 y, s32 *out);
void ModuleSkidSmokeTask(u32 e);
void ModuleAddTask(u32 a);
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
    u32 task;

    task = (u32)ModuleAllocTask();
    if (task != 0) {
        ((struct DraftStreak *)task)->timer = 0;
        ((struct DraftStreak *)task)->carIdx = carIdx;
        ((struct DraftStreak *)task)->unk20 = 2;
        ((struct DraftStreak *)task)->unk00 = 0;
        ((struct DraftStreak *)task)->unk04 = 0;
        ((struct DraftStreak *)task)->axialDist = 0x80000;
        ((struct DraftStreak *)task)->cornerIdx = cornerIdx;
        ((struct DraftStreak *)task)->callback = (u32)ModuleDraftStreakTask;
        ModuleAddTask(task);
    }
}

void ModuleDraftStreakTask(u32 task)
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

    car = (struct Car *)((u8 *)gModule_Cars + ((struct DraftStreak *)task)->carIdx * 0x190);
    cornerX = car->nextCornerX[((struct DraftStreak *)task)->cornerIdx + 2];
    cornerZ = car->nextCornerZ[((struct DraftStreak *)task)->cornerIdx + 2];
    idx = car->heading >> 8;
    sin = gModule_SinTable[idx];
    cos = gModule_SinTable[idx + 0x40];
    dy = ((struct DraftStreak *)task)->axialDist + 0xFFF60000;
    rel = dy;
    dx = -(rel * sin) >> 8;
    dy = (cos * rel) >> 8;
    if (ModuleWorldToScreen(cornerX + dx, cornerZ + dy, pos) != 0) {
        pos[0] -= 4;
        pos[1] -= 6;
    }
    counter = ((struct DraftStreak *)task)->timer + 1;
    idx = task + 0x18;
    *(s32 *)idx = counter;
    ((struct DraftStreak *)task)->axialDist += 0x10000;
    if (counter == 0x10) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}

void ModuleAddSkidSmokeTask(u8 carIdx, u8 cornerIdx)
{
    u32 *task;
    u32 car;
    u32 cornerOff;
    u32 cornerPtr;
    u32 cornerX;
    u32 cornerZ;

    task = (u32 *)ModuleAllocTask();
    if (task != 0) {
        car = (u32)gModule_Cars + carIdx * 400;
        task[6] = 0;
        ((struct SkidSmoke *)task)->carIdx = carIdx;
        task[7] = cornerIdx;
        task[8] = 2;
        cornerOff = cornerIdx * 4;
        cornerPtr = car + 0xC4;
        cornerPtr += cornerOff;
        cornerX = *(u32 *)cornerPtr;
        task[0] = cornerX;
        task[1] = 0;
        cornerPtr = car + 0xD4;
        cornerPtr += cornerOff;
        cornerZ = *(u32 *)cornerPtr;
        task[2] = cornerZ;
        cornerPtr = car + 0xA4;
        cornerPtr += cornerOff;
        task[10] = cornerX - *(u32 *)cornerPtr;
        cornerPtr = car + 0xB4;
        cornerPtr += cornerOff;
        task[12] = cornerZ - *(u32 *)cornerPtr;
        task[3] = (u32)ModuleSkidSmokeTask;
        ModuleAddTask((u32)task);
    }
}

void ModuleSkidSmokeTask(u32 e)
{
    s32 pos[2];
    s32 frame;
    s32 riseY;

    if (ModuleWorldToScreen(((struct SkidSmoke *)e)->posX, ((struct SkidSmoke *)e)->posZ, pos) != 0) {
        pos[0] -= 4;
        riseY = pos[1] - 4;
        pos[1] = riseY + (((struct SkidSmoke *)e)->rise >> 2);
    }
    frame = ((struct SkidSmoke *)e)->timer + 2;
    ((struct SkidSmoke *)e)->timer = frame;
    ((struct SkidSmoke *)e)->rise -= 1;
    ((struct SkidSmoke *)e)->posX += ((struct SkidSmoke *)e)->velX >> 1;
    ((struct SkidSmoke *)e)->posZ += ((struct SkidSmoke *)e)->velZ >> 1;
    if (frame == 0x10) {
        ModuleRemoveTask(e);
        ModuleFreeTask(e);
    }
}

void ModuleAddDamageSmokeTask(s32 *car)
{
    u32 task;

    task = (u32)ModuleAllocTask();
    if (task != 0) {
        ((struct DamageSmoke *)task)->timer = 0;
        ((struct DamageSmoke *)task)->riseRate = 2;
        ((struct DamageSmoke *)task)->posX = car[0];
        ((struct DamageSmoke *)task)->rise = -6;
        ((struct DamageSmoke *)task)->posZ = car[2];
        ((struct DamageSmoke *)task)->velX = car[3] >> 1;
        ((struct DamageSmoke *)task)->velZ = car[5] >> 1;
        ((struct DamageSmoke *)task)->callback = (u32)ModuleDamageSmokeTask;
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
        ModuleRemoveTask((u32)e);
        ModuleFreeTask((u32)e);
    }
}
