#include "global.h"
#include "functions.h"


void sub_0800592C(u32 x, u32 pal, u32 tiles, u32 a, u32 b)
{
    u32 arr[8];
    u32 *p;
    u32 i;

    arr[1] = 10;
    arr[4] = 10;
    arr[0] = tiles;
    arr[3] = sub_080172C8(a, 10);
    arr[2] = sub_08017230(a, 10);
    arr[6] = sub_08017230(sub_080172C8(b, 100), 10);
    arr[5] = sub_08017230(b, 100);
    arr[7] = 0;
    i = 0;
    pal &= 0xFF;
    p = arr;
    do {
        AddOamEntry(((x & 0x1FF) << 0x10) | pal, (*p++ + 0x3D4) | 0x3000);
        x += 4;
        i++;
    } while (i != 8);
}
