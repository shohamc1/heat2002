#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08012758(void)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x8F);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x90), 8, 1);
}
