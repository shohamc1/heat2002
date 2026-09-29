#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 callback;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
};

void LapTimeTask(u32 task);
u32 AllocTask(void);
void AddTask(u32 a);
void LapSnapshotTask(struct Task *);

void LapTimeTask(u32 task)
{
    u8 unused[0x28];

    DrawTextAt(GetString(0x9A), 9, 5);
    DrawTextAt(gLapTimeTextBuf, 0xD, 5);
    if (--((struct Task *)task)->timer == 0) {
        DrawTextAt(gText_BlankRowRaceMsg, 9, 5);
        RemoveTask(task);
        FreeTask(task);
    }
}

void DrawLapTime(s32 min, s32 sec, s32 ms)
{
    u8 *text = gLapTimeTextBuf;
    u32 nul = 0;
    u32 task;

    text[2] = 0x2E;
    text[5] = 0x2E;
    text[0] = min / 10 + 0x30;
    text[1] = min % 10 + 0x30;
    text[3] = sec / 10 + 0x30;
    text[4] = sec % 10 + 0x30;
    text[6] = ms / 100 + 0x30;
    text[7] = ms % 100 / 10 + 0x30;
    text[8] = nul;
    task = AllocTask();
    if (task != 0) {
        ((struct Task *)task)->timer = 0x5A;
        ((struct Task *)task)->callback = (u32)LapTimeTask;
        AddTask(task);
    }
}

void LapSnapshotTask(struct Task *e)
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
    minutes = gUnk_0202CC08[0];
    digit = sub_080172C8(sub_08017230(minutes, 10), 10) + 0x30;
    nul = 0;
    p0[0] = digit;
    p1 = buf;
    p1[1] = sub_080172C8(minutes, 10) + 0x30;
    buf[2] = 0x3A;
    p3 = buf;
    seconds = gUnk_0202CC1C[0];
    p3[3] = sub_080172C8(sub_08017230(seconds, 10), 10) + 0x30;
    p4 = buf;
    p4[4] = sub_080172C8(seconds, 10) + 0x30;
    buf[5] = 0x3A;
    q6 = buf;
    millis = gUnk_0202CC00[0];
    q6[6] = sub_080172C8(sub_08017230(millis, 100), 10) + 0x30;
    q7 = buf;
    q7[7] = sub_080172C8(sub_08017230(millis, 10), 10) + 0x30;
    q8 = buf;
    q8[8] = sub_080172C8(millis, 10) + 0x30;
    buf[9] = nul;
    e->timer = e->timer - 2;
    if (e->timer == 0) {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
}

void SaveLapTime(void)
{
    u32 *task;

    task = (u32 *)AllocTask();
    if (task != 0) {
        task[6] = 0x40;
        task[3] = (u32)LapSnapshotTask;
        AddTask((u32)task);
        gUnk_0202CC08[0] = gLapMin[0];
        gUnk_0202CC1C[0] = gLapSec[0];
        gUnk_0202CC00[0] = gLapMs[0];
    }
}
