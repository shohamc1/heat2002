#include "global.h"
#include "functions.h"

void sub_0833EDB8(void);

extern u8 gUnk_0203E1E0[];
extern u8 gUnk_0200CF90[];

void sub_0833EDF8(void)
{
    sub_0833EDB8();
    if (gUnk_0203E1E0[0] != 0)
        sub_0833EF0C((u8 *)gUnk_0200CF90, 0, 0x12);
}
