#include "global.h"

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


void ModuleDummyWallHitHook(void)
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

