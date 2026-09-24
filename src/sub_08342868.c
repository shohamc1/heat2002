#include "global.h"

void sub_083427DC(void);
void *sub_0833FF44(void);
void sub_0833FF94(u32);

void sub_08342868(void)
{
    u32 r1 = (u32)sub_0833FF44();

    if (r1 != 0) {
        *(u32 *)(r1 + 0x18) = 0xE1 << 2;
        *(u32 *)(r1 + 0x0C) = (u32)sub_083427DC;
        sub_0833FF94(r1);
    }
}
