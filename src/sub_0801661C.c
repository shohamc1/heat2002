#include "global.h"

extern u32 gUnk_02000590[];

u32 sub_08016E38(u32 a);
u32 sub_08016EA0(u32 a, u32 b);

u32 sub_0801661C(void)
{
    sub_08016E38(4);
    return sub_08016EA0(3, gUnk_02000590);
}
