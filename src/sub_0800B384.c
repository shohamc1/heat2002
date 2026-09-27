#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"



void sub_0800B384(u32 a)
{
    u8 unused[0x28];

    sub_0800649C((u8 *)(GetString(0x9A)), 9, 5);
    sub_0800649C((u8 *)((u32)gUnk_0202CC10), 0xD, 5);
    if (--*(u32 *)(a + 0x18) == 0)
    {
        sub_0800649C((u8 *)((u32)gUnk_0806C96C), 9, 5);
        RemoveTask(a);
        FreeTask(a);
    }
}
