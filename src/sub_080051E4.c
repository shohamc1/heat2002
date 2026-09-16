#include "global.h"

extern u8 gUnk_020253C4;

extern u8 gUnk_0806C714[];
extern u8 gUnk_0806C720[];
extern u8 gUnk_0806C72C[];
extern u8 gUnk_0806C738[];

extern void sub_08006418(u32 a, u32 b, u32 c);
extern u32 sub_08016558(u32 a);

void sub_080051E4(void)
{
    sub_08006418(sub_08016558(0x96), 8, 1);
    switch (gUnk_020253C4) {
    case 0:
        sub_08006418((u32)gUnk_0806C714, 9, 1);
        break;
    case 1:
        sub_08006418((u32)gUnk_0806C720, 9, 1);
        break;
    case 2:
        sub_08006418((u32)gUnk_0806C72C, 9, 1);
        break;
    case 3:
        sub_08006418((u32)gUnk_0806C738, 9, 1);
        break;
    }
}
