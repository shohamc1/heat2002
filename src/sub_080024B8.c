#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xxx */

extern MPlayFunc gUnk_02001D90[]; /* 0x02001D90, defined in symbols.ld */

void sub_080024B8(u32 a0, u32 a1)
{
    gUnk_02001D90[0](a0, a1);
}
