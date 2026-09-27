#include "global.h"

extern u32 gUnk_083FDE18[];

extern void sub_08006734(u32 a);
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2);

void sub_08013908(u8 a)
{
    u8 v;

    v = a;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x60);
    sub_080065A8();
    if (a == 0)
        DrawTextCenteredHighlight(GetString(0x63), 9, 1);
    if (a == 1)
        DrawTextCenteredHighlight(GetString(0x61), 9, 1);
    if (v == 2)
        DrawTextCenteredHighlight(GetString(0x62), 9, 1);
}
