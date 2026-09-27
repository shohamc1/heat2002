#include "global.h"
#include "functions.h"

extern u8 gUnk_02025370;


void sub_08004A50(u8 *a, u32 b, u32 c, u8 d)
{
    if (d == 0 || (gUnk_02025370 & 8) != 0)
        DrawSpriteText(a, b, c);
}
