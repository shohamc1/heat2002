#include "global.h"
#include "functions.h"
#include "data.h"



void sub_080139F0(void)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x30);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x11), 7, 1);
    DrawTextCenteredHighlight(GetString(0x11), 8, 1);
    DrawTextCenteredHighlight(GetString(0x11), 9, 1);
    DrawTextCenteredHighlight(GetString(0x11), 10, 1);
    DrawTextCenteredHighlight(GetString(0x11), 11, 1);
    DrawTextCenteredHighlight(GetString(0x11), 12, 1);
    DrawTextCenteredHighlight(GetString(0x11), 13, 1);
    DrawTextCenteredHighlight(GetString(0x11), 14, 1);
}
