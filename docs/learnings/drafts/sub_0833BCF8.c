#include "global.h"

extern u8 gUnk_020390BC;
extern u32 gUnk_02039200[];
extern u8 gUnk_0203D520[];

void sub_0833BCF8(void)
{
    u8 i;
    u8 j;
    u32 swapped;
    u32 a;
    u32 b;
    u8 *np;
    u32 *arr;

    i = 0;
    np = &gUnk_020390BC;
    arr = gUnk_02039200;
    for (; i != *np; i++)
        arr[i] = (u32)gUnk_0203D520 + i * 0x190;

    do
    {
        j = 0;
        swapped = 0;
        for (; j != *np - 1; j++)
        {
            a = arr[j];
            b = arr[j + 1];
            if (*(u32 *)(a + 0x16C) > *(u32 *)(b + 0x16C))
            {
                arr[j] = b;
                arr[j + 1] = a;
                swapped = 1;
            }
        }
    } while (swapped != 0);
}
