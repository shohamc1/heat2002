#include "global.h"
#include "variables.h"

void sub_0800B46C(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B540(void)
{
    u32 *r;

    r = (u32 *)AllocTask();
    if (r != 0) {
        r[6] = 0x40;
        r[3] = (u32)sub_0800B46C;
        AddTask((u32)r);
        gUnk_0202CC08[0] = gLapMin[0];
        gUnk_0202CC1C[0] = gLapSec[0];
        gUnk_0202CC00[0] = gLapMs[0];
    }
}
