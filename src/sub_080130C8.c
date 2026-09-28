#include "global.h"
#include "functions.h"
#include "data.h"



void sub_080130C8(u8 a)
{
    const u8 *p; sub_08006734(gUnk_083FDE18[0]);
    p = GetString(0x0B);
    DrawBigText(p);
    p = GetString(0x05);
    DrawTextCenteredHighlight(p, 8, a == 0);
    p = GetString(0x08);
    DrawTextCenteredHighlight(p, 0x0B, a == 1);
}
