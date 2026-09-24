#include "global.h"

void sub_0800B8EC(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B8A8(s32 *a)
{
    u32 r;

    r = AllocTask();
    if (r != 0) {
        *(u32 *)(r + 0x18) = 0;
        *(u32 *)(r + 0x1C) = 2;
        *(u32 *)(r + 0x00) = a[0];
        *(u32 *)(r + 0x04) = -6;
        *(u32 *)(r + 0x08) = a[2];
        *(u32 *)(r + 0x28) = a[3] >> 1;
        *(u32 *)(r + 0x30) = a[5] >> 1;
        *(u32 *)(r + 0x0C) = (u32)sub_0800B8EC;
        AddTask(r);
    }
}
