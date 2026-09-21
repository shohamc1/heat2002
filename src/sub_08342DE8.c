#include "global.h"

void *sub_0833FF44(void);
void sub_0833FF94(u32);

void sub_08342DE8(u8 a, u8 b)
{
    u32 p;

    p = (u32)sub_0833FF44();
    if (p != 0)
    {
        *(u32 *)(p + 0x18) = 0;
        *(u8 *)(p + 0x34) = a;
        *(u32 *)(p + 0x20) = 2;
        *(u32 *)(p + 0x00) = 0;
        *(u32 *)(p + 0x04) = 0;
        *(u32 *)(p + 0x08) = 0x80000;
        *(u32 *)(p + 0x1C) = b;
        *(u32 *)(p + 0x0C) = (u32)0x0200A3A9;
        sub_0833FF94(p);
    }
}
