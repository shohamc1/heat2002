#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08014A38(u8 a)
{
    const u8 *v; sub_08006734(gUnk_083FDE18[0]);
    GetString(0x4E);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x5F);
    DrawTextCenteredHighlight(v, 8, a == 0);
    v = GetString(0x5E);
    DrawTextCenteredHighlight(v, 0xA, a == 1);
}
