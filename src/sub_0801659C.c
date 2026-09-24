#include "global.h"

extern u16 gUnk_0202F040[];

void sub_080170B8(u16 a, u16 *b);
void sub_0801719C(u16 a, u16 *b);

void WriteSaveBlocks(u16 a, u16 b)
{
    u16 *r6;
    u16 r4;
    u16 r5;

    r6 = &gUnk_0202F040[a / 2];
    for (r5 = b / 8, r4 = a / 8; r5 != 0; r5--) {
        sub_080170B8(r4, r6);
        sub_0801719C(r4, r6);
        r6 += 4;
        r4++;
    }
}
