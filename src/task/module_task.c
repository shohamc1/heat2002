#include "global.h"
#include "variables.h"

/* The module twin of task.c's 0x44-byte task slot (0x40 of them here). */
struct Task
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 (*callback)(u32);
    /* 0x10 */ struct Task *prev;
    /* 0x14 */ struct Task *next;
    /* 0x18 */ s32 timer;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u8 unk34;
    /* 0x35 */ u8 pad35[0x3C - 0x35];
    /* 0x3C */ u32 slotIndex;
    /* 0x40 */ u8 pad40[4];
};

extern struct Task gModule_Tasks;
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
    struct Task *p = &gModule_Tasks;
    u32 off = 0;
    u32 q = (u32)&p[0].slotIndex;

    while (i != 0x40) {
        if (*(u8 *)(i + flagsAddr) == 0) {
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
{ gUnk_0203C340[((struct Task *)p)->slotIndex] = 0; }

void ModuleAddTask(u32 task)
{
    u32 r2 = gUnk_0203C380;
    ((struct Task *)task)->next = (struct Task *)r2;
    ((struct Task *)task)->prev = 0;
    ((struct Task *)r2)->prev = (struct Task *)task;
    gUnk_0203C380 = task;
}

void ModuleRemoveTask(u32 p)
{
    u32 next;
    u32 prev;

    next = (u32)((struct Task *)p)->next;
    prev = (u32)((struct Task *)p)->prev;
    if (prev != 0) {
        ((struct Task *)prev)->next = (struct Task *)next;
    } else {
        gUnk_0203C380 = next;
    }
    if (next != 0) {
        ((struct Task *)next)->prev = (struct Task *)prev;
    }
}

void ModuleRunTasks(void)
{
    u32 node;

    gUnk_0203D490 = 0;
    node = gUnk_0203C380;
    if (node != 0) {
        do {
            gUnk_0203D490 = gUnk_0203D490 + 1;
            _08344B80(node, (u32)((struct Task *)node)->callback);
            node = (u32)((struct Task *)node)->next;
        } while (node != 0);
    }
}
