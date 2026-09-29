#include "global.h"
#include "functions.h"

struct Task
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u8 pad08[4];
    /* 0x0C */ u32 callback;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
    /* 0x1C */ u32 unk1C;
};

extern u8 gUnk_020277F4[];
void ModuleDelayTask(u32 task);

void ModuleAddTrackRecordTasks(void)
{
    u32 row;

    row = 0;
    do {
        struct Task *task = ModuleAllocTask();
        if (task != 0) {
            task->timer = 0x60;
            task->unk1C = row * 32;
            task->unk00 = gUnk_020277F4[row];
            task->unk04 = 0x28;
            task->callback = (u32)ModuleDelayTask;
            ModuleAddTask((u32)task);
        }
        row++;
    } while (row != 12);
}

void ModuleDelayTask(u32 task)
{
    if (--((struct Task *)task)->timer == 0) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}
