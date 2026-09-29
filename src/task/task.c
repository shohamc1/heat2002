#include "global.h"
#include "variables.h"

extern u32 gTaskRunCount;

void InitTasks(void)
{
    u32 i = 0;
    do {
        gTaskSlotUsed[i] = 0;
        i++;
    } while (i != 0x100);
    gTaskListHead = 0;
}

void *AllocTask(void)
{
    u32 i = 0;
    u32 flagsAddr = (u32)gTaskSlotUsed;
    u32 one = 1;
    struct Task *p = gTasks;
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

void FreeTask(void *task)
{
    struct Task *t = task;

    gTaskSlotUsed[t->slotIndex] = 0;
}

void AddTask(void *task)
{
    struct Task *t = task;
    struct Task *head = gTaskListHead;

    t->next = head;
    t->prev = NULL;
    head->prev = t;
    gTaskListHead = t;
}

void RemoveTask(void *task)
{
    struct Task *t = task;
    struct Task *next;
    struct Task *prev;

    next = t->next;
    prev = t->prev;
    if (prev != NULL) {
        prev->next = next;
    } else {
        gTaskListHead = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
}

void RunTasks(void)
{
    struct Task *node;

    gTaskRunCount = 0;
    node = gTaskListHead;
    if (node != NULL) {
        do {
            gTaskRunCount += 1;
            node->callback(node);
            node = node->next;
        } while (node != NULL);
    }
}
