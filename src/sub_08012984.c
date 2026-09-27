#include "global.h"

extern u32 gUnk_083FDE18[];

extern void sub_08006734(u32 a);
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2);

void sub_08012984(u8 a)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0xA9);
    sub_080065A8();
    DrawTextCenteredHighlight(GetString(0xC5), 6, 1);
    DrawTextCenteredHighlight(GetString(a + 0xC5), 7, 1);
    if (a != 4)
        DrawTextCenteredHighlight(GetString(a + 0xAA), 0xA, 1);
    else
        DrawTextCenteredHighlight(GetString(0xB3), 0xA, 1);
}
