#include "global.h"
#include "functions.h"

extern u8 gUnk_02025250;
extern u8 gUnk_0806C744[];
extern u8 gUnk_0806C758[];

u8 CarNeedsPit(void);

void sub_08005AA0(void)
{
    u32 p;

    if (CarNeedsPit() != 0 && (gUnk_02025250 & 8) != 0)
    {
        p = (u32)gUnk_0806C744;
        /* DrawTextCentered: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(u32, u32, u32))DrawTextCentered)(p, 6, 1);
    }
    else
    {
        p = (u32)gUnk_0806C758;
        ((void (*)(u32, u32, u32))DrawTextCentered)(p, 6, 1);
    }
    gUnk_02025250 = gUnk_02025250 + 1;
}
