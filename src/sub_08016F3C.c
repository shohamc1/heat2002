#include "global.h"
#include "gba/io_reg.h"

extern u16 *volatile gUnk_0200049C;
extern volatile u8 gUnk_02000494;
extern u16 gUnk_020004A0;

void sub_08016F3C(void)
{
    u16 *p = gUnk_0200049C;

    *p = 0;
    p++;
    gUnk_0200049C = p;
    *p = 0;
    p--;
    gUnk_0200049C = p;
    REG_IME = 0;
    REG_IE &= ~(8 << gUnk_02000494);
    REG_IME = gUnk_020004A0;
}
