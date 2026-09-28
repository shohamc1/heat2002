#include "global.h"
#include "functions.h"
#include "variables.h"

struct Unk08342BA4
{
    u8 filler0[0x0C];
    u32 field0C;
    u8 filler10[0x18 - 0x10];
    u32 field18;
};
void ModuleLapTimeTask(u32 task);
void *ModuleAllocTask(void);
struct Unk08342C3C
{
    u8 pad00[0x18];
    s32 f18;
};
void ModuleLapSnapshotTask(struct Unk08342C3C *e);
void ModuleAddTask(u32 a);


void ModuleLapTimeTask(u32 task)
{
    u8 unused[0x28];

    ModuleDrawText(ModuleGetString(MODULE_MSG_LAP_TIME), 9, 5);
    ModuleDrawText(gUnk_0203DE30, 0xD, 5);
    if (--*(u32 *)(task + 0x18) == 0)
    {
        ModuleDrawText(gUnk_0200D118, 9, 5);
        ModuleRemoveTask(task);
        ModuleFreeTask(task);
    }
}


void ModuleDrawLapTime(u32 min, u32 sec, u32 ms)
{
    u8 *text;
    u32 nul;
    struct Unk08342BA4 *task;

    text = gUnk_0203DE30;
    nul = 0;
    text[2] = 0x2E;
    text[5] = 0x2E;
    text[0] = sub_08344BB8(min, 0x0A) + 0x30;
    text[1] = sub_08344C50(min, 0x0A) + 0x30;
    text[3] = sub_08344BB8(sec, 0x0A) + 0x30;
    text[4] = sub_08344C50(sec, 0x0A) + 0x30;
    text[6] = sub_08344BB8(ms, 0x64) + 0x30;
    text[7] = sub_08344BB8(sub_08344C50(ms, 0x64), 0x0A) + 0x30;
    text[8] = nul;
    task = ModuleAllocTask();
    if (task != 0)
    {
        task->field18 = 0x5A;
        task->field0C = (u32)ModuleLapTimeTask;
        ModuleAddTask(task);
    }
}


void ModuleLapSnapshotTask(struct Unk08342C3C *e)
{
    u8 buf[0x60];
    u8 *p0;
    u8 *p1;
    u8 *p3;
    u8 *p4;
    u8 *q6;
    u8 *q7;
    u8 *q8;
    u32 nul;
    s32 digit;
    s32 minutes;
    s32 seconds;
    s32 millis;

    p0 = buf;
    minutes = gUnk_0203DE28[0];
    digit = sub_08344C50(sub_08344BB8(minutes, 10), 10) + 0x30;
    nul = 0;
    p0[0] = digit;
    p1 = buf;
    p1[1] = sub_08344C50(minutes, 10) + 0x30;
    buf[2] = 0x3A;
    p3 = buf;
    seconds = gUnk_0203DE3C[0];
    p3[3] = sub_08344C50(sub_08344BB8(seconds, 10), 10) + 0x30;
    p4 = buf;
    p4[4] = sub_08344C50(seconds, 10) + 0x30;
    buf[5] = 0x3A;
    q6 = buf;
    millis = gUnk_0203DE20[0];
    q6[6] = sub_08344C50(sub_08344BB8(millis, 100), 10) + 0x30;
    q7 = buf;
    q7[7] = sub_08344C50(sub_08344BB8(millis, 10), 10) + 0x30;
    q8 = buf;
    q8[8] = sub_08344C50(millis, 10) + 0x30;
    buf[9] = nul;
    e->f18 = e->f18 - 2;
    if (e->f18 == 0)
    {
        ModuleRemoveTask((u32)e);
        ModuleFreeTask((u32)e);
    }
}


void ModuleSaveLapTime(void)
{
    u32 *task;

    task = (u32 *)ModuleAllocTask();
    if (task != 0) {
        task[6] = 0x40;
        task[3] = (u32)ModuleLapSnapshotTask;
        ModuleAddTask((u32)task);
        gUnk_0203DE28[0] = gModule_LapMin[0];
        gUnk_0203DE3C[0] = gModule_LapSec[0];
        gUnk_0203DE20[0] = gModule_LapMs[0];
    }
}

