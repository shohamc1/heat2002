#include "global.h"

extern s32 gUnk_0203DCFC;
extern s32 gUnk_0203D500;

u32 sub_08340CDC(s32 arg0)
{
    if (gUnk_0203DCFC * 1000 + gUnk_0203D500 <= arg0)
        return 1;
    return 0;
}
