#include "global.h"

extern u8 gUnk_020020DC;
extern u8 gUnk_020253C4;
extern u8 gUnk_0202539C;

extern u8 gUnk_0806C6B0[];
extern u8 gUnk_0806C6BC[];
extern u8 gUnk_0806C6C8[];
extern u8 gUnk_0806C6D4[];
extern u8 gUnk_0806C6E0[];
extern u8 gUnk_0806C6E8[];

extern void sub_08006418(u32 a, u32 b, u32 c);
extern u32 sub_08016558(u32 a);

void sub_08004C44(u8 arg)
{
    u8 r4 = arg;

    if (gUnk_020020DC != 0) {
        switch (gUnk_020253C4) {
        case 0:
            sub_08006418((u32)gUnk_0806C6B0, 6, 1);
            break;
        case 1:
            sub_08006418((u32)gUnk_0806C6BC, 6, 1);
            break;
        case 2:
            sub_08006418((u32)gUnk_0806C6C8, 6, 1);
            break;
        case 3:
            sub_08006418((u32)gUnk_0806C6D4, 6, 1);
            break;
        }
    } else {
        sub_08006418((u32)gUnk_0806C6E0, 6, 1);
    }
    if (r4 == 1 || (gUnk_0202539C & 8)) {
        sub_08006418(sub_08016558(0x81), 8, 1);
    } else {
        sub_08006418((u32)gUnk_0806C6E8, 8, 1);
    }
    if (r4 == 0 || (gUnk_0202539C & 8)) {
        sub_08006418(sub_08016558(0x80), 0xA, 1);
    } else {
        sub_08006418((u32)gUnk_0806C6E8, 0xA, 1);
    }
}
