#include "global.h"

void *ModuleAllocTask(void);
void ModuleAddTask(u32);
void sub_08342FF0(void);

void sub_08342FAC(s32 *src)
{
    u32 p;

    p = (u32)ModuleAllocTask();
    if (p != 0)
    {
        *(u32 *)(p + 0x18) = 0;
        *(u32 *)(p + 0x1C) = 2;
        *(u32 *)(p + 0x00) = src[0];
        *(u32 *)(p + 0x04) = -6;
        *(u32 *)(p + 0x08) = src[2];
        *(u32 *)(p + 0x28) = src[3] >> 1;
        *(u32 *)(p + 0x30) = src[5] >> 1;
        *(u32 *)(p + 0x0C) = (u32)sub_08342FF0;
        ModuleAddTask(p);
    }
}
