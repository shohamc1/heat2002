#include "global.h"
#include "variables.h"

void RaceEndTask(void);

u32 AllocTask(void);
void AddTask(u32 a);

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
