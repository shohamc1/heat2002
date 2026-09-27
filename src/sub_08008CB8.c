#include "global.h"
#include "functions.h"

extern u8 gUnk_0806C8F0[];
extern u8 gUnk_0806C8F8[];


void sub_08008CB8(void)
{
    sub_0800649C((u8 *)((u32)gUnk_0806C8F0), 0x0A, 0x0E);
    sub_0800649C((u8 *)((u32)gUnk_0806C8F8), 0x0A, 0x0F);
}
