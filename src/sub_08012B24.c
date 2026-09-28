#include "global.h"
#include "functions.h"
#include "data.h"


void sub_08012B24(void)
{
    const u8 *v; sub_08006734(gUnk_083FDE18[0]);
    GetString(0xBD);
    ((void (*)(void))DrawBigText)();
    v = GetString(0xBE);
    DrawTextCenteredHighlight(v, 6, 1);
}
