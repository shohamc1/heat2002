#include "global.h"

extern u8 gUnk_02025250;
extern u8 gUnk_0806C744[];
extern u8 gUnk_0806C758[];

u8 CarNeedsPit(void);
void DrawTextCentered(u32 a, u32 b, u32 c);

void sub_08005AA0(void)
{
    u32 p;

    if (CarNeedsPit() != 0 && (gUnk_02025250 & 8) != 0)
    {
        p = (u32)gUnk_0806C744;
        DrawTextCentered(p, 6, 1);
    }
    else
    {
        p = (u32)gUnk_0806C758;
        DrawTextCentered(p, 6, 1);
    }
    gUnk_02025250 = gUnk_02025250 + 1;
}
