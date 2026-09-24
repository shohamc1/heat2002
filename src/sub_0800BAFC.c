#include "global.h"

extern u8 gUnk_0200215C;           /* 0x0200215C */

u32 AllocTask(void);
void AddTask(u32 a);
void sub_0800BA38(void *e);

void sub_0800BAFC(s32 a, s32 b)
{
    u32 *r;

    if (gUnk_0200215C == 2 || gUnk_0200215C == 0xA)
        return;
    r = (u32 *)AllocTask();
    if (r != 0) {
        r[6] = 0xF0;
        r[0] = a;
        r[1] = 0;
        r[2] = b;
        r[3] = (u32)sub_0800BA38;
        AddTask((u32)r);
    }
}
