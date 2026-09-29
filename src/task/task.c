#include "global.h"
#include "variables.h"

extern u32 gUnk_02025FE0[];

struct Slot78E4
{
    u32 a[15];
    u32 b;
    u32 c;
};

struct Node0800796C
{
    u32 f0[3];
    u32 (*callback)(u32);
    u32 f10;
    struct Node0800796C *next;
};

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
    struct Slot78E4 *p = (struct Slot78E4 *)gUnk_02025FE0;
    u32 off = 0;
    u32 q = (u32)&p[0].b;

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
{ gUnk_02025ED0[*(u32 *)(p + 0x3C)] = 0; }

void AddTask(u32 r0)
{
    u32 r2 = gUnk_02025FD0;
    *(u32 *)(r0 + 0x14) = r2;
    *(u32 *)(r0 + 0x10) = 0;
    *(u32 *)(r2 + 0x10) = r0;
    gUnk_02025FD0 = r0;
}

void RemoveTask(u32 p)
{
    u32 next;
    u32 prev;

    next = *(u32 *)(p + 0x14);
    prev = *(u32 *)(p + 0x10);
    if (prev != 0) {
        *(u32 *)(prev + 0x14) = next;
    } else {
        gUnk_02025FD0 = next;
    }
    if (next != 0) {
        *(u32 *)(next + 0x10) = prev;
    }
}

void RunTasks(void)
{
    struct Node0800796C *node;

    gUnk_0202A3E0 = 0;
    node = (*(struct Node0800796C **)&gUnk_02025FD0);
    if (node != NULL) {
        do {
            gUnk_0202A3E0 += 1;
            node->callback((u32)node);
            node = node->next;
        } while (node != NULL);
    }
}
