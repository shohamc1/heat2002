#include "global.h"

void *ModuleAllocTask(void);
void ModuleAddTask(u32);
void sub_08342E28(void);

void sub_08342DE8(u8 a, u8 b)
{
    u32 p;

    p = (u32)ModuleAllocTask();
    if (p != 0)
    {
        *(u32 *)(p + 0x18) = 0;
        *(u8 *)(p + 0x34) = a;
        *(u32 *)(p + 0x20) = 2;
        *(u32 *)(p + 0x00) = 0;
        *(u32 *)(p + 0x04) = 0;
        *(u32 *)(p + 0x08) = 0x80000;
        *(u32 *)(p + 0x1C) = b;
        *(u32 *)(p + 0x0C) = (u32)sub_08342E28;
        ModuleAddTask(p);
    }
}
