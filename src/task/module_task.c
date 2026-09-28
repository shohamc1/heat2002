#include "global.h"
#include "variables.h"

extern u32 gUnk_0203C390[];
struct SlotFF44
{
    u32 a[15];
    u32 b;
    u32 c;
};
extern u32 gUnk_0203D490;
void _08344B80(u32 arg0, u32 arg1);


void ModuleInitTasks(void)
{
    u32 i;
    for (i = 0; i != 0x40; i++)
        gUnk_0203C340[i] = 0;
    gUnk_0203C380 = 0;
}


void *ModuleAllocTask(void)
{
    u32 i = 0;
    u32 flagsAddr = (u32)gUnk_0203C340;
    u32 one = 1;
    struct SlotFF44 *p = (struct SlotFF44 *)gUnk_0203C390;
    u32 off = 0;
    u32 q = (u32)&p[0].b;

    while (i != 0x40)
    {
        if (*(u8 *)(i + flagsAddr) == 0)
        {
            *(u8 *)(i + flagsAddr) = one;
            *(u32 *)(off + q) = i;
            return p;
        }
        p++;
        off += 0x44;
        i++;
    }
    return 0;
}


void ModuleFreeTask(u32 p)
{
    gUnk_0203C340[*(u32 *)(p + 0x3C)] = 0;
}


void ModuleAddTask(u32 task)
{
    u32 r2 = gUnk_0203C380;
    *(u32 *)(task + 0x14) = r2;
    *(u32 *)(task + 0x10) = 0;
    *(u32 *)(r2 + 0x10) = task;
    gUnk_0203C380 = task;
}


void ModuleRemoveTask(u32 p)
{
    u32 next;
    u32 prev;

    next = *(u32 *)(p + 0x14);
    prev = *(u32 *)(p + 0x10);
    if (prev != 0)
    {
        *(u32 *)(prev + 0x14) = next;
    }
    else
    {
        gUnk_0203C380 = next;
    }
    if (next != 0)
    {
        *(u32 *)(next + 0x10) = prev;
    }
}


void ModuleRunTasks(void)
{
    u32 node;

    gUnk_0203D490 = 0;
    node = gUnk_0203C380;
    if (node != 0)
    {
        do {
            gUnk_0203D490 = gUnk_0203D490 + 1;
            _08344B80(node, *(u32 *)(node + 0x0C));
            node = *(u32 *)(node + 0x14);
        } while (node != 0);
    }
}

