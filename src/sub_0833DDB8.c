#include "global.h"

u32 sub_08344BB8(u32 a, u32 b);
s32 sub_08344C50(s32 a, s32 b);
void sub_0833E3C8(u16 *a, s32 b);

void sub_0833DDB8(u16 *a1, s32 a2, u32 a3, u32 a4)
{
    u32 arr[8];
    u32 *q;
    u32 i;

    if (a2 > 0x63) {
        a2 = 0x63;
        a3 = 0x3B;
        a4 = 0;
    }
    arr[2] = 0xA;
    arr[5] = 0xA;
    arr[0] = sub_08344BB8(a2, 0xA);
    arr[1] = sub_08344C50(a2, 0xA);
    arr[3] = sub_08344BB8(a3, 0xA);
    arr[4] = sub_08344C50(a3, 0xA);
    arr[7] = sub_08344BB8(sub_08344C50(a4, 0x64), 0xA);
    arr[6] = sub_08344BB8(a4, 0x64);
    i = 0;
    q = arr;
    do {
        sub_0833E3C8(a1 + 2, (u8)*q++);
        a1++;
        i++;
    } while (i != 8);
}
