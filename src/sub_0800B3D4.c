#include "global.h"

extern u8 gUnk_0202CC10[];         /* 0x0202CC10 */
void sub_0800B384(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B3D4(s32 a, s32 b, s32 c)
{
    u8 *s = gUnk_0202CC10;
    u32 terminator = 0;
    u32 r;

    s[2] = 0x2E;
    s[5] = 0x2E;
    s[0] = a / 10 + 0x30;
    s[1] = a % 10 + 0x30;
    s[3] = b / 10 + 0x30;
    s[4] = b % 10 + 0x30;
    s[6] = c / 100 + 0x30;
    s[7] = c % 100 / 10 + 0x30;
    s[8] = terminator;
    r = AllocTask();
    if (r != 0) {
        *(u32 *)(r + 0x18) = 0x5A;
        *(u32 *)(r + 0x0C) = (u32)sub_0800B384;
        AddTask(r);
    }
}
