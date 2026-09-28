#include "global.h"

void sub_083427DC(void);
void *ModuleAllocTask(void);
void ModuleAddTask(u32);

void sub_08342868(void)
{
    u32 r1 = (u32)ModuleAllocTask();

    if (r1 != 0) {
        *(u32 *)(r1 + 0x18) = 0xE1 << 2;
        *(u32 *)(r1 + 0x0C) = (u32)sub_083427DC;
        ModuleAddTask(r1);
    }
}
