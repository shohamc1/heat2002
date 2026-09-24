#include "global.h"

extern u32 gUnk_083FDE18[];

void sub_08006734(u32 a);
u32 GetString(u16 idx);
void sub_080065A8(void);
void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);

void sub_08012EE8(u32 unused, u8 v)
{
    u32 r;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x1E);
    sub_080065A8();
    r = GetString(v + 0x1F);
    DrawTextCenteredHighlight(r, 8, 1);
}
