#include "global.h"

void CarNeedsPit(u32 arg);
s16 sub_08017230(u32 freq, s16 arg2);
void DrawTextCentered(u8 *arg, u32 r1, u32 r2);

s16 FixedInverse8(u16 r0)
{
    return sub_08017230(0x10000, r0);
}
