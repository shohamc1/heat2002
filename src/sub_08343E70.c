#include "global.h"

extern s32 gUnk_0203DF44;

void sub_08343E70(s32 arg0, u8 arg1, u32 arg2, u8 arg3, u32 *arg4, u8 *arg5, u32 arg6, s32 arg7)
{
    if (arg7 < gUnk_0203DF44) {
        arg4[0] = arg0;
        arg4[1] = arg2;
        ((u8 *)arg4)[8] = arg1;
        ((u8 *)arg4)[9] = arg3;
        arg4[3] = arg6;
        *arg5 = 1;
        gUnk_0203DF44 = arg7;
    }
}
