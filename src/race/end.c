#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ u32 callback;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 timer;
    /* 0x1C */ u32 unk1C;
};
extern u8 gText_DemoMode[];
extern u8 gText_BlankRow12_3[];
void DemoEndTask(u32 task);

void DemoEndTask(u32 task)
{
    if (((struct Task *)task)->timer & 0x10)
        DrawTextAt(gText_DemoMode, 0xB, 0xA);
    else
        DrawTextAt(gText_BlankRow12_3, 0xB, 0xA);
    --((struct Task *)task)->timer;
    ReadKeys();
    if ((gKeysHeld & 0x3FF) != 0 || ((struct Task *)task)->timer == 0) {
        BeginFadeToColor(0xA, 0);
        WaitForVBlank();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gRaceEndState = 2;
        RemoveTask(task);
        FreeTask(task);
    }
}

void AddDemoEndTask(void)
{
    u32 task = (u32)AllocTask();

    if (task != 0) {
        ((struct Task *)task)->timer = 0xE1 << 2;
        ((struct Task *)task)->callback = (u32)DemoEndTask;
        AddTask(task);
    }
}

void RaceEndTask(struct Task *e)
{
    if (gFadeActive == 0) {
        if (gIsLinkRace == 0) {
            if (gGameMode[0] == 0x0A || gGameMode[0] == 0x0B) {
                if (gChallengeScore != 0)
                    /* DrawTextAt: the ROM callers pass a fourth argument the matched definition drops; call
                       through a function pointer with the old prototype. */
                    ((void (*)(u8 *, u32, u32, u32))DrawTextAt)((u8 *)GetString(0x8E), 0x0A, 3, 1);
            } else {
                ((void (*)(u8 *, u32, u32, u32))DrawTextAt)((u8 *)GetString(0x97), 0x0A, 3, 1);
            }
        }
        e->timer = e->timer - 1;
        if (e->timer == 0) {
            RemoveTask((u32)e);
            FreeTask((u32)e);
            if (gGameMode[0] != 4) {
                BeginFadeToColor(0x0A, 0);
                WaitForVBlank();
                REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            }
            gRaceEndState = 2;
        }
    }
}

void EndRace(void)
{
    u8 *p = &gRaceEndState;
    if (*p == 0) {
        struct Task *task = AllocTask();
        if (task != 0) {
            task->unk1C = gChallengeScore;
            task->timer = 0x64;
            task->callback = (u32)RaceEndTask;
            AddTask((u32)task);
        }
        *p = 1;
    }
}
