#include "global.h"
#include "functions.h"

void CarNeedsPit(u32 arg);

s16 sub_08339A18(u16 r0)
{
    /* sub_08344BB8: this file's old prototype is s16 (u32, s16); the
   matched definition uses s32; call through the old one. */
return ((s16 (*)(u32, s16))sub_08344BB8)(0x10000, r0);
}
