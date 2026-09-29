#include "global.h"
#include "functions.h"

extern u8 gUnk_020277F4[];
void *ModuleAllocTask(void);
void ModuleAddTask(u32 r0);
void ModuleDelayTask(u32 task);

void ModuleAddTrackRecordTasks(void)
{
    u32 row;

    row = 0;
    do {
        u32 *task = ModuleAllocTask();
        if (task != 0) {
            task[6] = 0x60;
            task[7] = row * 32;
            task[0] = gUnk_020277F4[row];
            task[1] = 0x28;
            task[3] = (u32)ModuleDelayTask;
            ModuleAddTask((u32)task);
        }
        row++;
    } while (row != 12);
}

void ModuleDelayTask(u32 task)
{
    if (--*(u32 *)(task + 0x18) == 0) {
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}
