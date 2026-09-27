#include "global.h"
#include "variables.h"

void sub_0800B0A0(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B2C4(void)
{
    u32 r;

    if (gGameMode[0] == 9)
        gGameMode[0] = 6;
    if (gGameMode[0] == 0x0D)
        gGameMode[0] = 0x0C;
    if (gGameMode[0] == 0x0E)
        gGameMode[0] = 2;
    if (gGameMode[0] == 0x0F)
        gGameMode[0] = 0x10;
    if (gGameMode[0] == 0x11)
        gGameMode[0] = 5;
    gRaceStarted = 1;
    r = AllocTask();
    if (r != 0) {
        *(u32 *)(r + 0x18) = 0;
        *(u32 *)(r + 0x0C) = (u32)sub_0800B0A0;
        AddTask(r);
        gRaceStartTaskPtr = r;
    }
}
