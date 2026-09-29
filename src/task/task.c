#include "global.h"
#include "variables.h"

/* The 0x44-byte task slot AllocTask hands out: 0x3C holds the slot's own
   index (FreeTask clears its flag), 0x0C the body RunTasks dispatches on,
   0x10/0x14 the doubly-linked list AddTask/RemoveTask splice. The words
   0x00-0x38 are per-task data (see the DraftStreak/SkidSmoke/DamageSmoke
   views in src/car/particles.c); timer at 0x18 counts callback invocations
   in every task body that touches it. */
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

extern struct Task gTasks;

extern u32 gUnk_0202A3E0;

void InitTasks(void)
{
    u32 i = 0;
    do {
        gUnk_02025ED0[i] = 0;
        i++;
    } while (i != 0x100);
    gUnk_02025FD0 = 0;
}

void *AllocTask(void)
{
    u32 i = 0;
    u32 flagsAddr = (u32)gUnk_02025ED0;
    u32 one = 1;
    struct Task *p = &gTasks;
    u32 off = 0;
    u32 q = (u32)&p[0].slotIndex;

    while (i != 0x100) {
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

void FreeTask(u32 p)
{ gUnk_02025ED0[((struct Task *)p)->slotIndex] = 0; }

void AddTask(u32 r0)
{
    u32 r2 = gUnk_02025FD0;
    ((struct Task *)r0)->next = (struct Task *)r2;
    ((struct Task *)r0)->prev = 0;
    ((struct Task *)r2)->prev = (struct Task *)r0;
    gUnk_02025FD0 = r0;
}

void RemoveTask(u32 p)
{
    u32 next;
    u32 prev;

    next = (u32)((struct Task *)p)->next;
    prev = (u32)((struct Task *)p)->prev;
    if (prev != 0) {
        ((struct Task *)prev)->next = (struct Task *)next;
    } else {
        gUnk_02025FD0 = next;
    }
    if (next != 0) {
        ((struct Task *)next)->prev = (struct Task *)prev;
    }
}

void RunTasks(void)
{
    struct Task *node;

    gUnk_0202A3E0 = 0;
    node = (*(struct Task **)&gUnk_02025FD0);
    if (node != NULL) {
        do {
            gUnk_0202A3E0 += 1;
            node->callback((u32)node);
            node = node->next;
        } while (node != NULL);
    }
}
