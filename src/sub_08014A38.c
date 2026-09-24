#include "global.h"

extern u32 gUnk_083FDE18[];

void sub_08006734(u32 a);
u32 GetString(u16 idx);
void sub_080065A8(void);
void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);

void sub_08014A38(u8 a)
{
    u32 v;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x4E);
    sub_080065A8();
    v = GetString(0x5F);
    DrawTextCenteredHighlight(v, 8, a == 0);
    v = GetString(0x5E);
    DrawTextCenteredHighlight(v, 0xA, a == 1);
}
