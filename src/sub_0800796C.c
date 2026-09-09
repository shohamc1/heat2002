#include "global.h"

struct Node0800796C {
    u32 f0[3];
    u32 (*callback)(u32);
    u32 f10;
        struct Node0800796C *next;
};

extern u32 gUnk_0202A3E0;
extern struct Node0800796C *gUnk_02025FD0;

void sub_0800796C(void)
{
    struct Node0800796C *node;

    gUnk_0202A3E0 = 0;
    node = gUnk_02025FD0;
    if (node != NULL) {
        do {
            gUnk_0202A3E0 += 1;
            node->callback((u32)node);
            node = node->next;
        } while (node != NULL);
    }
}
