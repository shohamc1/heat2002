#include "global.h"
#include "functions.h"
#include "data.h"


// The retail body ignores both arguments; callers still pass them.
void sub_08012AF8(u8 unused1, u8 unused2)
{
    const u8 *v; sub_08006734(gUnk_083FDE18[0]);
    GetString(0xA9);
    ((void (*)(void))DrawBigText)();
    v = GetString(0xAA);
    DrawTextCenteredHighlight(v, 6, 1);
}
