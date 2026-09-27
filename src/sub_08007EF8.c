#include "global.h"
#include "data.h"
#include "functions.h"

extern u8 gUnk_0806C854[];
extern u8 gUnk_0806C860[];


void sub_08007EF8(void)
{
    u32 p;

    sub_0800649C((u8 *)((u32)gUnk_0806C854), 0x0B, 0x07);
    p = (u32)gUnk_0806C860;
    sub_0800649C((u8 *)p, 0x06, 0x09);
    sub_0800649C((u8 *)p, 0x06, 0x0A);
    p = (u32)gUnk_0806C878;
    sub_0800649C((u8 *)p, 0x06, 0x0B);
    sub_0800649C((u8 *)p, 0x0A, 0x0C);
}
