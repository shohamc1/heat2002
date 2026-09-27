#include "global.h"
#include "variables.h"


/* The high module's _call_via_r0 stub (0x08344B7C): _08344B7C(target) jumps
   to target with it in r0, the shape the module's own copy of the libgcc
   stub provides where the low program emits bl _call_via_r0. */
void _08344B7C(u32 arg0);
void sub_08339B04(void);

void sub_08339AD0(void)
{
    if (gUnk_020375D0 != 0)
        _08344B7C(gUnk_020375D0);
    sub_08339B04();
}
