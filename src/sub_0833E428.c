#include "global.h"
#include "functions.h"

void sub_0833D6A0(u32 a, u32 b);

void sub_0833E428(u32 x, u32 pal, u32 tiles, u32 a, u32 b)
{
    u32 arr[8];
    u32 *p;
    u32 i;

    arr[1] = 10;
    arr[4] = 10;
    arr[0] = tiles;
    arr[3] = sub_08344C50(a, 10);
    arr[2] = sub_08344BB8(a, 10);
    arr[6] = sub_08344BB8(sub_08344C50(b, 100), 10);
    arr[5] = sub_08344BB8(b, 100);
    arr[7] = 0;
    i = 0;
    pal &= 0xFF;
    p = arr;
    do {
        sub_0833D6A0(((x & 0x1FF) << 0x10) | pal, (*p++ + 0x3D4) | 0x3000);
        x += 4;
        i++;
    } while (i != 8);
}
