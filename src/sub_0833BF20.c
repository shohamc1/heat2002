#include "global.h"
#include "gba/io_reg.h"

void sub_0833BF20(void)
{
    REG_BG3CNT = 0x3D0B;
    REG_BG2CNT = 0x1E01;
    REG_BG1CNT = 0x1F02;
    REG_BG0CNT = 0x1C0C;
    REG_BLDALPHA = 0x808;
    REG_BLDCNT = 0x808 - 0xC8;
}
