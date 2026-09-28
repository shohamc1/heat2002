#include "global.h"
#include "functions.h"

extern u8 gText_BlankRow8[];
extern u8 gText_BlankRow12_2[];


void sub_08008CB8(void)
{
    sub_0800649C((u8 *)((u32)gText_BlankRow8), 0x0A, 0x0E);
    sub_0800649C((u8 *)((u32)gText_BlankRow12_2), 0x0A, 0x0F);
}
