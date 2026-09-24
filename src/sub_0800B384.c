#include "global.h"

extern u8 gUnk_0202CC10[];         /* 0x0202CC10 */
extern u8 gUnk_0806C96C[];         /* 0x0806C96C */

u32 GetString(u16 idx);
extern void sub_0800649C(u32 a, u32 b, u32 c);
void RemoveTask(u32 a);
void FreeTask(u32 a);

void sub_0800B384(u32 a)
{
    u8 unused[0x28];

    sub_0800649C(GetString(0x9A), 9, 5);
    sub_0800649C((u32)gUnk_0202CC10, 0xD, 5);
    if (--*(u32 *)(a + 0x18) == 0)
    {
        sub_0800649C((u32)gUnk_0806C96C, 9, 5);
        RemoveTask(a);
        FreeTask(a);
    }
}
