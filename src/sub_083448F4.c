#include "global.h"
#include "gba/io_reg.h"

extern u16 gUnk_0203E160[];
extern u16 gUnk_03007FF8;

void sub_083448F4(void)
{
    if ((REG_SIOCNT & 0x40) == 0) {
        gUnk_0203E160[0] = REG_SIOMULTI0;
        gUnk_0203E160[4] = REG_SIOMULTI1;
        gUnk_0203E160[8] = REG_SIOMULTI2;
        gUnk_0203E160[12] = REG_SIOMULTI3;
    } else {
        gUnk_0203E160[0] = 0;
        gUnk_0203E160[4] = 0;
        gUnk_0203E160[8] = 0;
        gUnk_0203E160[12] = 0;
    }
    REG_IME = 0;
    gUnk_03007FF8 |= 0x80;
    REG_IME = 1;
}
