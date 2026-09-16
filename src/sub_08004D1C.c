#include "global.h"

extern u8 gUnk_0202539C;

extern u8 gUnk_0806C6FC[];
extern u8 gUnk_0806C6E8[];

extern void sub_08006418(u32 a, u32 b, u32 c);
extern u32 sub_08016558(u32 a);

void sub_08004D1C(u8 arg)
{
    u8 r4 = arg;

    if (r4 != 3) {
        sub_08006418(sub_08016558(0x66), 6, 1);
    } else {
        sub_08006418((u32)gUnk_0806C6FC, 6, 1);
    }
    if (r4 == 1 || (gUnk_0202539C & 8)) {
        sub_08006418(sub_08016558(0x68), 8, 1);
    } else {
        sub_08006418((u32)gUnk_0806C6E8, 8, 1);
    }
    if (r4 == 0 || (gUnk_0202539C & 8)) {
        sub_08006418(sub_08016558(0x67), 0xA, 1);
    } else {
        sub_08006418((u32)gUnk_0806C6E8, 0xA, 1);
    }
}
