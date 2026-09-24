#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xxx (high copy). The high module links its own libgcc copy, so the
   indirect call routes through _08344B84, its _call_via_r2, not the low
   copy's _call_via_r2 (same pattern as sub_0833ABE0 with _08344B80). */

extern MPlayFunc gUnk_02038DE0; /* 0x02038DE0, defined in symbols.ld */
void _08344B84(u32 arg0, u32 arg1, u32 arg2);

void sub_0833BB78(u32 a0, u32 a1)
{
    _08344B84(a0, a1, (u32)gUnk_02038DE0);
}
