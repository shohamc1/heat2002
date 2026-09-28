#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08012FB0(void)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x23);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x11), 7, 1);
    DrawTextCenteredHighlight(GetString(0x11), 8, 1);
    DrawTextCenteredHighlight(GetString(0x11), 9, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xA, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xB, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xC, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xD, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xE, 1);
}
