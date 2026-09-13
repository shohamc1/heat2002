#include "global.h"

extern u8 gUnk_02002090;
extern u8 gUnk_020020DC;
extern u8 gUnk_020020AC;
extern u8 gUnk_0202A550[];
extern volatile u8 gUnk_0200215C;

void sub_08009C4C(u32 arg0, u8 arg1);

void sub_08009F48(void)
{
    u8 n;
    u32 i;
    u8 *p;

    n = gUnk_02002090;
    if (gUnk_020020DC != 0)
        n = gUnk_020020AC;
    p = gUnk_0202A550;
    i = 0;
    while (i != n) {
        if (gUnk_0200215C != 2 || i == 0)
            sub_08009C4C(p, i);
        i++;
        p += 0xC8 * 2;
    }
}
