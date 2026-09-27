#include "global.h"
#include "variables.h"

void sub_0800B120(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B334(void)
{
    u32 r;

    gRaceStarted = 0;
    gRaceEndState = 0;
    if (gGameMode[0] == 3 || gGameMode[0] == 4) {
        r = AllocTask();
        if (r != 0) {
            *(u32 *)(r + 0x18) = 0;
            *(u32 *)(r + 0x0C) = (u32)sub_0800B120;
            AddTask(r);
            gRaceStartTaskPtr = r;
        }
    }
}
