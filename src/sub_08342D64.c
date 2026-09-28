#include "global.h"

extern u8 gUnk_020277F4[];

void *ModuleAllocTask(void);
void ModuleAddTask(u32 r0);
void sub_08342DA4(void);

void sub_08342D64(void)
{
    u32 i;

    i = 0;
    do {
        u32 *p = ModuleAllocTask();
        if (p != 0)
        {
            p[6] = 0x60;
            p[7] = i * 32;
            p[0] = gUnk_020277F4[i];
            p[1] = 0x28;
            p[3] = (u32)sub_08342DA4;
            ModuleAddTask((u32)p);
        }
        i++;
    } while (i != 12);
}
