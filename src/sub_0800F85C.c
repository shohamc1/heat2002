#include "global.h"
#include "gba/io_reg.h"

extern u16 gUnk_0202EF40[];
extern u16 gUnk_03007FF8;

void sub_0800F85C(void)
{
    if ((REG_SIOCNT & 0x40) == 0) {
        gUnk_0202EF40[0] = REG_SIOMULTI0;
        gUnk_0202EF40[4] = REG_SIOMULTI1;
        gUnk_0202EF40[8] = REG_SIOMULTI2;
        gUnk_0202EF40[12] = REG_SIOMULTI3;
    } else {
        gUnk_0202EF40[0] = 0;
        gUnk_0202EF40[4] = 0;
        gUnk_0202EF40[8] = 0;
        gUnk_0202EF40[12] = 0;
    }
    REG_IME = 0;
    gUnk_03007FF8 |= 0x80;
    REG_IME = 1;
}
