#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08012EE8(u32 unused, u8 v)
{
    const u8 *r; sub_08006734(gUnk_083FDE18[0]);
    GetString(0x1E);
    ((void (*)(void))DrawBigText)();
    r = GetString(v + 0x1F);
    DrawTextCenteredHighlight(r, 8, 1);
}
