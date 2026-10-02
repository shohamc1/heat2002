#include "global.h"
#include "functions.h"
#include "gba/defines.h"
#include "variables.h"

/* The file's RAM variables, defined in address order (ldscript.ld's
   .bss_task places the section at gTaskSlotUsed's address): the 256
   slot-used flags, the list head, and the 256 0x44-byte task slots
   (gTasks ends exactly at gTaskRunCount). The static gap array only
   positions gTasks at its original address. */
EWRAM_DATA u8 gTaskSlotUsed[0x100] = {0};
EWRAM_DATA struct Task *gTaskListHead = 0;
static EWRAM_DATA u8 task_gap5FD4[0xC] = {0};
EWRAM_DATA struct Task gTasks[0x100] = {0};
EWRAM_DATA u32 gTaskRunCount = 0;

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
#if PORTABLE
    u8 *flagsAddr = gTaskSlotUsed;
#else
    u32 flagsAddr = (u32)gTaskSlotUsed;
#endif
    u32 one = 1;
    struct Task *p = gTasks;
#if !PORTABLE
    /* The GBA walk keeps the slot address in integers: q is the address of
       slot 0's slotIndex word and off the 0x44 byte stride (sizeof(struct
       Task)). Hosted, off + q would scale by the u32 pointee, so the
       member access through p (which walks the same slots) replaces it. */
    u32 off = 0;
    u32 q = (u32)&p[0].slotIndex;
#endif

    while (i != 0x100) {
        if (*(u8 *)(i + flagsAddr) == 0) {
            *(u8 *)(i + flagsAddr) = one;
#if PORTABLE
            p->slotIndex = i;
#else
            *(u32 *)(off + q) = i;
#endif
            return p;
        }
        p++;
#if !PORTABLE
        off += 0x44;
#endif
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
#if PORTABLE
    /* Adding to an empty list: the original write through the NULL head
       lands at 0x18, inside the GBA's BIOS region, where the hardware
       drops writes - the retail ROM relies on that. Hosted it is a
       segfault, so guard it; the list was empty, nothing to fix up. */
    if (head != NULL)
        head->prev = t;
#else
    head->prev = t;
#endif
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
