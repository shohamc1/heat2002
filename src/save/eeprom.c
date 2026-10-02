#include "global.h"
#include "functions.h"
#include "variables.h"

void sub_080170B8(u16 a, u16 *b);
void sub_0801719C(u16 a, u16 *b);
void sub_08017000(u16 a, u16 *b);
u32 sub_08016E38(u32 a);
u32 sub_08016EA0(u32 a, IntrFunc *b);

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

u32 InitEeprom(void)
{
    sub_08016E38(4);
    {
        IntrFunc *p = gIntrTable;

        return sub_08016EA0(3, p);
    }
}
