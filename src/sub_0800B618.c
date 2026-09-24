#include "global.h"

void sub_0800B658(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B618(u8 a, u8 b)
{
    u32 r;

    r = AllocTask();
    if (r != 0) {
        *(u32 *)(r + 0x18) = 0;
        *(u8 *)(r + 0x34) = a;
        *(u32 *)(r + 0x20) = 2;
        *(u32 *)(r + 0x00) = 0;
        *(u32 *)(r + 0x04) = 0;
        *(u32 *)(r + 0x08) = 0x80000;
        *(u32 *)(r + 0x1C) = b;
        *(u32 *)(r + 0x0C) = (u32)sub_0800B658;
        AddTask(r);
    }
}
