#include "global.h"

struct Unk08342FF0;

void *ModuleAllocTask(void);
void ModuleAddTask(u32);
void ModuleDraftStreakTask(u32 task);
#include "functions.h"
#include "variables.h"
#include "car.h"
u32 ModuleWorldToScreen(s32 x, s32 y, s32 *out);
struct Tbl {
    u8 pad[0xC4];
    s32 nextCornerX[4];
    s32 nextCornerZ[4];
    u8 pad2[0x190 - 0xE4];
};
void ModuleSkidSmokeTask(u32 e);
void ModuleAddTask(u32 a);
void ModuleDamageSmokeTask(struct Unk08342FF0 *e);
extern u32 gUnk_0202B370[];
extern u8 gUnk_0201F370[];
u32 *ModuleRequestObjTiles16(u32 a);
u32 ModuleGetTrackTileType(s32 x, s32 y);
s32 ModuleRequestObjPalette(u32 a);
u32 ModuleAddOamEntry(u32 a, u32 b);
struct Unk08342FF0
{
    s32 f00;
    s32 f04;
    s32 f08;
    u8 pad0C[0x18 - 0x0C];
    s32 f18;
    s32 f1C;
    u8 pad20[0x28 - 0x20];
    s32 f28;
    u8 pad2C[0x30 - 0x2C];
    s32 f30;
};
struct Unk08342FF0Sprite
{
    u8 pad00[0x10];
    u32 f10;
};


void ModuleDummyWallHitHook(s32 cornerX, s32 cornerZ)
{
}


void ModuleAddDraftStreakTask(u8 carIdx, u8 cornerIdx)
{
    u32 task;

    task = (u32)ModuleAllocTask();
    if (task != 0)
    {
        *(u32 *)(task + 0x18) = 0;
        *(u8 *)(task + 0x34) = carIdx;
        *(u32 *)(task + 0x20) = 2;
        *(u32 *)(task + 0x00) = 0;
        *(u32 *)(task + 0x04) = 0;
        *(u32 *)(task + 0x08) = 0x80000;
        *(u32 *)(task + 0x1C) = cornerIdx;
        *(u32 *)(task + 0x0C) = (u32)ModuleDraftStreakTask;
        ModuleAddTask(task);
    }
}


void ModuleDraftStreakTask(u32 task)
{
    struct Tbl *car;
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

    car = (struct Tbl *)((u8 *)gModule_Cars + *(u8 *)(task + 0x34) * 0x190);
    cornerX = car->nextCornerX[*(s32 *)(task + 0x1C) + 2];
    cornerZ = car->nextCornerZ[*(s32 *)(task + 0x1C) + 2];
    idx = *(u16 *)((u8 *)car + 0x34) >> 8;
    sin = gModule_SinTable[idx];
    cos = gModule_SinTable[idx + 0x40];
    dy = *(s32 *)(task + 0x08) + 0xFFF60000;
    rel = dy;
    dx = -(rel * sin) >> 8;
    dy = (cos * rel) >> 8;
    if ((u8)ModuleWorldToScreen(cornerX + dx, cornerZ + dy, pos) != 0)
    {
        pos[0] -= 4;
        pos[1] -= 6;
    }
    counter = *(s32 *)(task + 0x18) + 1;
    idx = task + 0x18;
    *(s32 *)idx = counter;
    *(s32 *)(task + 0x08) += 0x10000;
    if (counter == 0x10)
    {
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
        *(u8 *)((u32)task + 0x34) = carIdx;
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

    if ((u8)ModuleWorldToScreen(*(s32 *)(e + 0x00), *(s32 *)(e + 0x08), pos) != 0)
    {
        pos[0] -= 4;
        riseY = pos[1] - 4;
        pos[1] = riseY + (*(s32 *)(e + 0x04) >> 2);
    }
    frame = *(s32 *)(e + 0x18) + 2;
    *(s32 *)(e + 0x18) = frame;
    *(s32 *)(e + 0x04) -= 1;
    *(s32 *)(e + 0x00) += *(s32 *)(e + 0x28) >> 1;
    *(s32 *)(e + 0x08) += *(s32 *)(e + 0x30) >> 1;
    if (frame == 0x10)
    {
        ModuleRemoveTask(e);
        ModuleFreeTask(e);
    }
}


void ModuleAddDamageSmokeTask(s32 *car)
{
    u32 task;

    task = (u32)ModuleAllocTask();
    if (task != 0)
    {
        *(u32 *)(task + 0x18) = 0;
        *(u32 *)(task + 0x1C) = 2;
        *(u32 *)(task + 0x00) = car[0];
        *(u32 *)(task + 0x04) = -6;
        *(u32 *)(task + 0x08) = car[2];
        *(u32 *)(task + 0x28) = car[3] >> 1;
        *(u32 *)(task + 0x30) = car[5] >> 1;
        *(u32 *)(task + 0x0C) = (u32)ModuleDamageSmokeTask;
        ModuleAddTask(task);
    }
}


void ModuleDamageSmokeTask(struct Unk08342FF0 *e)
{
    s32 out[2];
    struct Unk08342FF0Sprite *sprite;
    u32 attr;
    u32 palBits;
    u8 tileType;
    s32 screenX;
    s32 screenY;
    s32 frame;

    if (((u32)ModuleWorldToScreen(e->f00, e->f08, out) << 24) != 0)
    {
        screenX = out[0];
        out[0] = screenX - 8;
        screenY = out[1] - 8;
        out[1] = screenY + (e->f04 >> 1);
        if ((u32)(screenX + 0x17) <= 0x10E && out[1] <= 0x9F && out[1] > -0x10)
        {
            sprite = ModuleRequestObjTiles16(gUnk_0202B370[e->f18 & 0x1F]);
            if (sprite != 0)
            {
                tileType = ModuleGetTrackTileType(e->f00 >> 19, e->f08 >> 19);
                if (tileType & 1)
                {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)ModuleRequestObjPalette((u32)gUnk_0201F370) << 12) | 0x800;
                    ModuleAddOamEntry(attr, sprite->f10 | palBits);
                }
                else
                {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)ModuleRequestObjPalette((u32)gUnk_0201F370) << 12) | 0x400;
                    ModuleAddOamEntry(attr, sprite->f10 | palBits);
                }
            }
        }
    }
    frame = e->f18 + 1;
    e->f18 = frame;
    e->f04 = e->f04 - e->f1C;
    e->f00 = e->f00 + e->f28;
    e->f08 = e->f08 + e->f30;
    if (frame == 0x20)
    {
        ModuleRemoveTask((u32)e);
        ModuleFreeTask((u32)e);
    }
}

