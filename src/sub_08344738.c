#include "global.h"

extern u32 gUnk_0201AA30[];
extern u32 gUnk_0201AA40[];
extern u32 gUnk_0201AA54[];

void sub_0833F018(u32 a);
void sub_0833F3C0(u32 a, u32 b, u32 c);

void sub_08344738(u8 a)
{
    u32 p;

    sub_0833F018((u32)gUnk_0201AA30);
    p = (u32)gUnk_0201AA40;
    sub_0833F3C0(p, 8, a == 0);
    p = (u32)gUnk_0201AA54;
    sub_0833F3C0(p, 0xA, a == 1);
}
