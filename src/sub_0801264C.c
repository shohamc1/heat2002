#include "global.h"
#include "functions.h"
#include "data.h"


void sub_0801264C(u32 x)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x14);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x15), 8, x == 0);
    DrawTextCenteredHighlight(GetString(0x16), 0xA, x == 1);
    DrawTextCenteredHighlight(GetString(0x17), 0xC, x == 2);
    DrawTextCenteredHighlight(GetString(0x18), 0xE, x == 3);
}
