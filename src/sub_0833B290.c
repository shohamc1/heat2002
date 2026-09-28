#include "global.h"
#include "gba/m4a_internal.h"

/* CgbOscOff, high 0x0833 module copy: same code as CgbOscOff. */

void sub_0833B290(u8 chanNum)
{
    switch (chanNum)
    {
        case 1:
            REG_NR12 = 8;
            REG_NR14 = 0x80;
            break;
        case 2:
            REG_NR22 = 8;
            REG_NR24 = 0x80;
            break;
        case 3:
            REG_NR30 = 0;
            break;
        default:
            REG_NR42 = 8;
            REG_NR44 = 0x80;
            break;
    }
}
