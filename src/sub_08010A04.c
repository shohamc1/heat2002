#include "global.h"

extern const u8 gUnk_0829F2A0[];
extern const u8 gUnk_0829F294[];
extern const u8 gUnk_0829F288[];
extern const u8 gUnk_0829F27C[];
extern const u8 gUnk_0829F270[];
extern const u8 gUnk_0829F264[];
extern const u8 gUnk_0829F258[];
extern const u8 gUnk_0829F24C[];

void sub_080109C0(u8 *str, u32 attr, u32 pal);

void sub_08010A04(u32 a0, u32 a1, u32 a2)
{
    u8 v = a0;
    u8 w = v;

    if (v == 1)
        sub_080109C0(gUnk_0829F2A0, a1, a2);
    if (v == 2)
        sub_080109C0(gUnk_0829F294, a1, a2);
    if (v == 3)
        sub_080109C0(gUnk_0829F288, a1, a2);
    if (v == 4)
        sub_080109C0(gUnk_0829F27C, a1, a2);
    if (v == 5)
        sub_080109C0(gUnk_0829F270, a1, a2);
    if (v == 6)
        sub_080109C0(gUnk_0829F264, a1, a2);
    if (v == 7)
        sub_080109C0(gUnk_0829F258, a1, a2);
    if (w == 8)
        sub_080109C0(gUnk_0829F24C, a1, a2);
}
