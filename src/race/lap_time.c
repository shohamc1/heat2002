#include "global.h"
#include "gba/defines.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

void LapTimeTask(struct Task *task);

/* The file's four RAM variables (the two u32 timer-snapshot arrays,
   gLapTimeTextBuf -- sized to gUnk_0202CC20, its first 9 bytes the text
   DrawLapTime writes -- and gUnk_0202CC1C) moved to src/race/globals.c,
   the owner of the 0x0202CBE0-0x0202CCD0 EWRAM run they sit in; they are
   declared in variables.h. */

void LapTimeTask(struct Task *task)
{
    u8 unused[0x28];

    DrawTextAt(GetString(154), 9, 5);
    DrawTextAt(gLapTimeTextBuf, 13, 5);
    if (--task->timer == 0) {
        DrawTextAt(gText_BlankRowRaceMsg, 9, 5);
        RemoveTask(task);
        FreeTask(task);
    }
}

void DrawLapTime(s32 min, s32 sec, s32 ms)
{
    u8 *text = gLapTimeTextBuf;
    u32 nul = 0;
    struct Task *task;

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
        task->timer = 0x5A;
        task->callback = LapTimeTask;
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
    minutes = gUnk_0202CC08;
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
    millis = gUnk_0202CC00;
    q6[6] = sub_080172C8(sub_08017230(millis, 100), 10) + 0x30;
    q7 = buf;
    q7[7] = sub_080172C8(sub_08017230(millis, 10), 10) + 0x30;
    q8 = buf;
    q8[8] = sub_080172C8(millis, 10) + 0x30;
    buf[9] = nul;
    e->timer = e->timer - 2;
    if (e->timer == 0) {
        RemoveTask(e);
        FreeTask(e);
    }
}

void SaveLapTime(void)
{
    struct Task *task;

    task = AllocTask();
    if (task != 0) {
        task->timer = 0x40;
        task->callback = LapSnapshotTask;
        AddTask(task);
        gUnk_0202CC08 = gLapMin;
        gUnk_0202CC1C[0] = gLapSec;
        gUnk_0202CC00 = gLapMs;
    }
}
