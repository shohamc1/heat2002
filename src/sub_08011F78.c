#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08011F78(u8 a)
{
    const u8 *v; sub_08006734(gUnk_083FDE18[0]);
    GetString(0x5A);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x51);
    DrawTextCenteredHighlight(v, 9, a == 0);
    v = GetString(0x52);
    DrawTextCenteredHighlight(v, 0xB, a == 1);
}
