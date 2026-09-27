#include "global.h"
#include "functions.h"

extern const u8 gUnk_0200D0C4[];
extern const u8 gUnk_0200D0CC[];


void sub_08340E28(void)
{
    sub_0833EF0C((u8 *)((u32)gUnk_0200D0C4), 10, 14);
    sub_0833EF0C((u8 *)((u32)gUnk_0200D0CC), 10, 15);
}
