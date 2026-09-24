#include "global.h"

void sub_0800AE94(void);
u32 AllocTask(void);
void AddTask(u32);

void sub_0800AF20(void)
{
    u32 r1 = AllocTask();

    if (r1 != 0) {
        *(u32 *)(r1 + 0x18) = 0xE1 << 2;
        *(u32 *)(r1 + 0x0C) = (u32)sub_0800AE94;
        AddTask(r1);
    }
}
