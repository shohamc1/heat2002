#include "global.h"
struct Unk0202A550 { u8 filler[400]; };
extern struct Unk0202A550 gUnk_0202A550[];
extern void sub_08007B34(struct Unk0202A550 *p, u8 i);
u32 sub_080140D8(void)
{
    u8 i = 0;
    do {
        sub_08007B34(&gUnk_0202A550[i], i);
        i++;
    } while (i != 0x18);
}
