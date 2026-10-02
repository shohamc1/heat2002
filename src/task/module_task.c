#include "global.h"
#include "functions.h"
#include "gba/defines.h"
#include "variables.h"

/* This file also owns the high module's task EWRAM run
   0x0203C340-0x0203D4A0, the module twin of src/task/task.c's run: the 64
   slot-used flags, the list head and the 64 0x44-byte task slots;
   gModule_TaskRunCount, the run's last identified variable, ends 0xC bytes
   before the run's end, where src/car/module_globals.c's grid run begins.
   ldscript.ld's .module_ewram_data_task places the section at 0x0203C340. */

MODULE_EWRAM_DATA u8 gModule_TaskSlotUsed[0x40] = {0};
MODULE_EWRAM_DATA struct Task *gModule_TaskListHead = 0;
static MODULE_EWRAM_DATA u8 task_gapC388[0xC] = {0};
MODULE_EWRAM_DATA struct Task gModule_Tasks[0x40] = {0};
MODULE_EWRAM_DATA u32 gModule_TaskRunCount = 0;
static MODULE_EWRAM_DATA u8 task_gapD494[0xC] = {0};

void ModuleInitTasks(void)
{
    u32 i;
    for (i = 0; i != 0x40; i++)
        gModule_TaskSlotUsed[i] = 0;
    gModule_TaskListHead = NULL;
}

void *ModuleAllocTask(void)
{
    u32 i = 0;
    u32 flagsAddr = (u32)gModule_TaskSlotUsed;
    u32 one = 1;
    struct Task *p = gModule_Tasks;
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

void ModuleFreeTask(void *task)
{
    struct Task *t = task;

    gModule_TaskSlotUsed[t->slotIndex] = 0;
}

void ModuleAddTask(void *task)
{
    struct Task *t = task;
    struct Task *head = gModule_TaskListHead;

    t->next = head;
    t->prev = NULL;
    head->prev = t;
    gModule_TaskListHead = t;
}

void ModuleRemoveTask(void *task)
{
    struct Task *t = task;
    struct Task *next;
    struct Task *prev;

    next = t->next;
    prev = t->prev;
    if (prev != NULL) {
        prev->next = next;
    } else {
        gModule_TaskListHead = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
}

void ModuleRunTasks(void)
{
    struct Task *node;

    gModule_TaskRunCount = 0;
    node = gModule_TaskListHead;
    if (node != NULL) {
        do {
            gModule_TaskRunCount = gModule_TaskRunCount + 1;
            node->callback(node);
            node = node->next;
        } while (node != NULL);
    }
}
