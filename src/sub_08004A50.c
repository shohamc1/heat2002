#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_08004A50(u8 *a, u32 b, u32 c, u8 d)
{
    if (d == 0 || (gUnk_02025370 & 8) != 0)
        DrawSpriteText(a, b, c);
}
