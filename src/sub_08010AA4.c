#include "global.h"

extern u8 gUnk_0829F2AC[];
extern u8 *gUnk_083FDDD0[];
extern u8 gUnk_0202EF20[];
extern u8 *gUnk_083FDCF0[];
extern u8 *gUnk_083FDC88[];

extern void DrawText(u8 *p, u32 a1, u32 a2, u8 a3);
extern void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2);

void sub_08010AA4(u8 idx)
{
    u8 *p;

    p = gUnk_0829F2AC;
    DrawText(p, 0, 4, 0);
    DrawTextCenteredHighlight(gUnk_083FDDD0[idx], 4, 1);
    DrawText(p, 0, 0x11, 0);
    DrawText(p, 0, 0x12, 0);
    DrawText(p, 0, 0x13, 0);
    if (gUnk_0202EF20[idx] != 0)
        DrawText(gUnk_083FDCF0[idx], 0, 0x11, 1);
    else
        DrawText(gUnk_083FDC88[idx], 0, 0x11, 1);
}
