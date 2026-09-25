#include "global.h"

extern const u8 gUnk_0200D0C4[];
extern const u8 gUnk_0200D0CC[];

u32 sub_0833EF0C(u32 r0, u32 r1, u32 r2);

void sub_08340E28(void)
{
    sub_0833EF0C((u32)gUnk_0200D0C4, 10, 14);
    sub_0833EF0C((u32)gUnk_0200D0CC, 10, 15);
}
