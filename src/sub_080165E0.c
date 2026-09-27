#include "global.h"
#include "variables.h"


void sub_08017000(u16 a, u16 *b);

void ReadSaveBlocks(u16 a, u16 b)
{
    u16 *r6;
    u16 r4;
    u16 r5;

    r6 = &gUnk_0202F040[a / 2];
    for (r4 = b / 8, r5 = a / 8; r4 != 0; r4--) {
        sub_08017000(r5, r6);
        r6 += 4;
        r5++;
    }
}
