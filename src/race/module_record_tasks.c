#include "global.h"
#include "functions.h"
#include "structs.h"

extern u8 gUnk_020277F4[];
void ModuleDelayTask(struct Task *task);

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
            task->callback = ModuleDelayTask;
            ModuleAddTask(task);
        }
        row++;
    } while (row != 12);
}

void ModuleDelayTask(struct Task *task)
{
    if (--task->timer == 0) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}
