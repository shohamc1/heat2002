#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08012DEC(u8 a)
{
    const u8 *v; sub_08006734(gUnk_083FDE18[0]);
    GetString(8);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x66);
    DrawTextCenteredHighlight(v, 7, 1);
    v = GetString(0x67);
    DrawTextCenteredHighlight(v, 9, a == 0);
    v = GetString(0x68);
    DrawTextCenteredHighlight(v, 0xB, a == 1);
}
