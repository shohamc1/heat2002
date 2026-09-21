#include "global.h"
#include "gba/io_reg.h"

extern u16 gUnk_03007FF8;

void sub_083448B0(u16 a)
{
    REG_SIODATA8 = a;
    REG_IME = 0;
    gUnk_03007FF8 = gUnk_03007FF8 & 0xFF7F;
    REG_IME = 1;
    if ((*(u8 *)0x04000128 & 0x30) == 0)
        REG_SIOCNT |= 0x80;
}
