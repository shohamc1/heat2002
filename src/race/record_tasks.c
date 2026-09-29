#include "global.h"
#include "functions.h"

extern u8 gRecordsTaskParams[];
void DelayTask(u32 task);
u32 AllocTask(void);
void AddTask(u32 a);

void AddTrackRecordTasks(void)
{
    u32 row = 0;
    do {
        u32 *task = (u32 *)AllocTask();
        if (task != 0) {
            task[6] = 0x60;
            task[7] = row << 5;
            task[0] = gRecordsTaskParams[row];
            task[1] = 0x28;
            task[3] = (u32)DelayTask;
            AddTask((u32)task);
        }
        row++;
    } while (row != 0xC);
}

void DelayTask(u32 task)
{
    if (--*(u32 *)(task + 0x18) == 0) {
        RemoveTask(task);
        FreeTask(task);
    }
}
