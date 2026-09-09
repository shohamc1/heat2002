#include "global.h"

extern u8 gUnk_0806C854[];
extern u8 gUnk_0806C860[];
extern u8 gUnk_0806C878[];

void sub_0800649C(u32 r0, u32 r1, u32 r2);

void sub_08007EF8(void)
{
    u32 p;

    sub_0800649C((u32)gUnk_0806C854, 0x0B, 0x07);
    p = (u32)gUnk_0806C860;
    sub_0800649C(p, 0x06, 0x09);
    sub_0800649C(p, 0x06, 0x0A);
    p = (u32)gUnk_0806C878;
    sub_0800649C(p, 0x06, 0x0B);
    sub_0800649C(p, 0x0A, 0x0C);
}
