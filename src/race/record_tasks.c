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

extern u8 gRecordsTaskParams[];
void DelayTask(u32 task);

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
            task->callback = (u32)DelayTask;
            AddTask((u32)task);
        }
        row++;
    } while (row != 0xC);
}

void DelayTask(u32 task)
{
    if (--((struct Task *)task)->timer == 0) {
        RemoveTask(task);
        FreeTask(task);
    }
}
