#include "global.h"

extern s32 gUnk_0202CADC;
extern s32 gUnk_0202A534;

u32 sub_08008B6C(s32 arg0)
{
    if (gUnk_0202CADC * 1000 + gUnk_0202A534 <= arg0)
        return 1;
    return 0;
}
