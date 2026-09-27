#include "global.h"
#include "functions.h"

void CarNeedsPit(u32 arg);

s16 FixedInverse8(u16 r0)
{
    /* sub_08017230: this file's old prototype is s16 (u32, s16); the
       matched definition uses s32 throughout; call through the old one. */
    return ((s16 (*)(u32, s16))sub_08017230)(0x10000, r0);
}
