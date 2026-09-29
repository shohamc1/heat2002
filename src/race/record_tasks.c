#include "global.h"
#include "functions.h"
#include "structs.h"

extern u8 gRecordsTaskParams[];
void DelayTask(struct Task *task);

void AddTrackRecordTasks(void)
{
    u32 row = 0;
    do {
        struct Task *task = AllocTask();
        if (task != 0) {
            task->timer = 0x60;
            task->unk1C = row << 5;
            task->unk00 = gRecordsTaskParams[row];
            task->unk04 = 0x28;
            task->callback = DelayTask;
            AddTask(task);
        }
        row++;
    } while (row != 0xC);
}

void DelayTask(struct Task *task)
{
    if (--task->timer == 0) {
        RemoveTask(task);
        FreeTask(task);
    }
}
