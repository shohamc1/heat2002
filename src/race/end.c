#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

struct EntityAF44 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ u32 unk18;
};

u32 AllocTask(void);
void AddTask(u32 a);

void RaceEndTask(struct EntityAF44 *e)
{
    if (gFadeActive == 0)
    {
        if (gIsLinkRace == 0)
        {
            if (gGameMode[0] == 0x0A || gGameMode[0] == 0x0B)
            {
                if (gChallengeScore != 0)
                    /* sub_0800649C: the ROM callers pass a fourth argument the matched definition drops; call
                       through a function pointer with the old prototype. */
                    ((void (*)(u8 *, u32, u32, u32))sub_0800649C)((u8 *)GetString(0x8E), 0x0A, 3, 1);
            }
            else
            {
                ((void (*)(u8 *, u32, u32, u32))sub_0800649C)((u8 *)GetString(0x97), 0x0A, 3, 1);
            }
        }
        e->unk18 = e->unk18 - 1;
        if (e->unk18 == 0)
        {
            RemoveTask((u32)e);
            FreeTask((u32)e);
            if (gGameMode[0] != 4)
            {
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
    if (*p == 0)
    {
        u32 *r = (u32 *)AllocTask();
        if (r != 0)
        {
            r[7] = gChallengeScore;
            r[6] = 0x64;
            r[3] = (u32)RaceEndTask;
            AddTask((u32)r);
        }
        *p = 1;
    }
}
