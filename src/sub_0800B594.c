#include "global.h"

extern u8 gRecordsTaskParams[];
void sub_0800B5D4(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B594(void)
{
    u32 i = 0;
    do {
        u32 *r = (u32 *)AllocTask();
        if (r != 0)
        {
            r[6] = 0x60;
            r[7] = i << 5;
            r[0] = gRecordsTaskParams[i];
            r[1] = 0x28;
            r[3] = (u32)sub_0800B5D4;
            AddTask((u32)r);
        }
        i++;
    } while (i != 0xC);
}
